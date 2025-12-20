#define _(String) gettext(String)
#include "freertos/semphr.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "lvgl.h"
#include "esp_timer.h"
#include "demos/lv_demos.h"
#include "ui/ui.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_lcd_touch_gt911.h"
extern "C"
{
#include "sunton_esp32_8048s050c.h"
    // #include "lvgl_helpers.h"
}
#define TAG "main"
#define LV_TICK_PERIOD_MS 1

/**
 * @file sunton_esp32_8048s050c.c
 * @author Sven Fabricius (sven.fabricius@livediesel.de)
 * @brief
 * @version 0.1
 * @date 2024-09-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "esp_timer.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_lcd_touch_gt911.h"
#include "driver/i2c_master.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "sunton_esp32_8048s050c.h"
#include "freertos/FreeRTOS.h"

SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter)
{
    (void)pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    // lv_init();
    lv_draw_init();
    ui_init();
    uint32_t task_delay_ms = CONFIG_LVGL_TASK_MAX_DELAY_MS;
    while (1)
    {
        task_delay_ms = lv_timer_handler();
        if (task_delay_ms > CONFIG_LVGL_TASK_MAX_DELAY_MS)
        {
            task_delay_ms = CONFIG_LVGL_TASK_MAX_DELAY_MS;
        }
        else if (task_delay_ms < CONFIG_LVGL_TASK_MIN_DELAY_MS)
        {
            task_delay_ms = CONFIG_LVGL_TASK_MIN_DELAY_MS;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms + 10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
        {
            // lv_task_handler();
            ui_tick();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    vTaskDelete(NULL);
    ESP_LOGI(TAG, "guiTask deleted");
}

extern "C" void app_main(void)
{
    // lv_init();
    // ui_init();
    sunton_esp32s3_backlight_init();

    sunton_esp32s3_lcd_init();

    i2c_master_bus_handle_t i2c_master = sunton_esp32s3_i2c_master();
    sunton_esp32s3_touch_init(i2c_master);

    // run_display_demo(disp, 0);
    // ui_init();
    xTaskCreatePinnedToCore(guiTask, "gui", 4096 * 16, NULL, tskIDLE_PRIORITY + 1, NULL, 1);
    // xTaskCreate(lvgl_port_task, "lvgl_port_task", (CONFIG_LVGL_TASK_STACK_SIZE * 1024), NULL, CONFIG_LVGL_TASK_PRIORITY, &lvgl_port_task_handle);
}
