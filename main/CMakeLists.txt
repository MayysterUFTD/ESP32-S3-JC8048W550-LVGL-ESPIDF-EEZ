# idf_component_register(SRCS main.c)

file(GLOB_RECURSE SOURCES_C *.c
                            ./ui/*.c
                            ./ui/**/*.c
                            ./eez-framework/**/*.cpp
                            ./eez-framework/**/*.c
                            )
file(GLOB_RECURSE SOURCES_CPP *.cpp)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DEEZ_PLATFORM_ESP32 -DEEZ_FOR_LVGL -DLV_LVGL_H_INCLUDE_SIMPLE")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEEZ_PLATFORM_ESP32 -DEEZ_FOR_LVGL -DLV_LVGL_H_INCLUDE_SIMPLE")


idf_component_register(
    SRCS ${SOURCES_C} ${SOURCES_CPP}
    INCLUDE_DIRS    "."
    ./ui
    #./ui/images
    ./ui/fonts
    ./eez-framework/src
    ./eez-framework/src/eez/libs/agg 
    ./eez-framework/src/eez/platform/simulator 
    REQUIRES        lvgl esp_lcd_touch_gt911 esp_timer esp_lcd esp_driver_ledc esp_driver_gpio
    )

# Add LVGL include path for EEZ framework compatibility
target_include_directories(${COMPONENT_LIB} PUBLIC
    "${COMPONENT_DIR}/../managed_components/lvgl__lvgl"
    "${COMPONENT_DIR}/../managed_components/lvgl__lvgl/src"
)
