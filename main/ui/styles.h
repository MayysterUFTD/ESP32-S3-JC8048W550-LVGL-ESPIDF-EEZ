#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <..\managed_components\lvgl__lvgl\lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: test
lv_style_t *get_style_test_MAIN_DEFAULT();
void add_style_test(lv_obj_t *obj);
void remove_style_test(lv_obj_t *obj);

// Style: bar
lv_style_t *get_style_bar_MAIN_DEFAULT();
void add_style_bar(lv_obj_t *obj);
void remove_style_bar(lv_obj_t *obj);

// Style: PARAMETER
lv_style_t *get_style_parameter_MAIN_DEFAULT();
void add_style_parameter(lv_obj_t *obj);
void remove_style_parameter(lv_obj_t *obj);

// Style: PARAMETER_1
lv_style_t *get_style_parameter_1_MAIN_DEFAULT();
void add_style_parameter_1(lv_obj_t *obj);
void remove_style_parameter_1(lv_obj_t *obj);

// Style: Container
lv_style_t *get_style_container_MAIN_DEFAULT();
void add_style_container(lv_obj_t *obj);
void remove_style_container(lv_obj_t *obj);

// Style: barMain
lv_style_t *get_style_bar_main_MAIN_DEFAULT();
lv_style_t *get_style_bar_main_INDICATOR_DEFAULT();
void add_style_bar_main(lv_obj_t *obj);
void remove_style_bar_main(lv_obj_t *obj);

// Style: tagLabel
void add_style_tag_label(lv_obj_t *obj);
void remove_style_tag_label(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/