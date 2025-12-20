#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <..\managed_components\lvgl__lvgl\lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *control;
    lv_obj_t *settings;
    lv_obj_t *obj0;
    lv_obj_t *obj0__obj0;
    lv_obj_t *obj0__obj1;
    lv_obj_t *obj0__obj2;
    lv_obj_t *obj0__obj3;
    lv_obj_t *obj0__obj4;
    lv_obj_t *obj0__obj5;
    lv_obj_t *obj0__obj6;
    lv_obj_t *obj0__main_place;
    lv_obj_t *obj1;
    lv_obj_t *obj1__obj0;
    lv_obj_t *obj1__obj1;
    lv_obj_t *obj1__obj2;
    lv_obj_t *obj1__obj3;
    lv_obj_t *obj1__obj4;
    lv_obj_t *obj1__obj5;
    lv_obj_t *obj1__obj6;
    lv_obj_t *obj1__main_place;
    lv_obj_t *obj2;
    lv_obj_t *obj2__obj0;
    lv_obj_t *obj2__obj1;
    lv_obj_t *obj2__obj2;
    lv_obj_t *obj2__obj3;
    lv_obj_t *obj2__obj4;
    lv_obj_t *obj2__obj5;
    lv_obj_t *obj2__obj6;
    lv_obj_t *obj2__main_place;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_CONTROL = 2,
    SCREEN_ID_SETTINGS = 3,
};

void create_screen_main();
void tick_screen_main();

void create_screen_control();
void tick_screen_control();

void create_screen_settings();
void tick_screen_settings();

void create_user_widget_main_bg(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_main_bg(void *flowState, int startWidgetIndex);

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/