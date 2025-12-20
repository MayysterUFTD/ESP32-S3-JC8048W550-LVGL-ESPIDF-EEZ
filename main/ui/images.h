#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <..\managed_components\lvgl__lvgl\lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_menu_off;
extern const lv_img_dsc_t img_background;
extern const lv_img_dsc_t img_uftd;
extern const lv_img_dsc_t img_settings;
extern const lv_img_dsc_t img_home_3_48;
extern const lv_img_dsc_t img_power_48;
extern const lv_img_dsc_t img_menu_on;
extern const lv_img_dsc_t img_pp;
extern const lv_img_dsc_t img__cfbvcvb;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[9];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/