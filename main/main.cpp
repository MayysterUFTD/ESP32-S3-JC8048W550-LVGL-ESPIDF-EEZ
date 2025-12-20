#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "lvgl.h"
#include "esp_lvgl_port.h"
#include "ui/ui.h"
#include "eez-framework/src/eez-framework.h"

extern "C"
{
#include "sunton_esp32_8048s050c.h"
}

#define TAG "main"

extern "C" void app_main(void)
{
    // Initialize backlight
    sunton_esp32s3_backlight_init();

    // Initialize LCD and LVGL (esp_lvgl_port handles LVGL task internally)
    lv_display_t *disp = sunton_esp32s3_lcd_init();
    if (disp == NULL)
    {
        ESP_LOGE(TAG, "Failed to initialize display");
        return;
    }

    // Initialize I2C and touch
    i2c_master_bus_handle_t i2c_master = sunton_esp32s3_i2c_master();
    sunton_esp32s3_touch_init(i2c_master);

    // Initialize UI - must lock LVGL before calling LVGL functions from app_main
    if (lvgl_port_lock(0))
    {
        ui_init();
        lvgl_port_unlock();
    }

    ESP_LOGI(TAG, "Application started");

    // Main loop - just call ui_tick periodically
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(100));

        if (lvgl_port_lock(10))
        {
            ui_tick();
            lvgl_port_unlock();
        }
    }
}
