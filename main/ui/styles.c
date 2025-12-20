#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: test
//

void init_style_test_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_align(style, LV_TEXT_ALIGN_AUTO);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    {
        static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_row_dsc_array(style, dsc);
    }
    {
        static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_column_dsc_array(style, dsc);
    }
    lv_style_set_bg_color(style, lv_color_hex(0xffa1a1a1));
};

lv_style_t *get_style_test_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_test_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_test(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_test_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_test(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_test_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: bar
//

void init_style_bar_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff9aa084));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_bar_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_bar(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_bar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_bar(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_bar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: PARAMETER
//

void init_style_parameter_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(style, &lv_font_montserrat_42);
    lv_style_set_radius(style, 500);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_bg_opa(style, 100);
    lv_style_set_shadow_spread(style, 2);
    lv_style_set_shadow_color(style, lv_color_hex(0xff0b0b0b));
    lv_style_set_shadow_width(style, 50);
};

lv_style_t *get_style_parameter_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_parameter_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_parameter(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_parameter_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_parameter(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_parameter_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: PARAMETER_1
//

void init_style_parameter_1_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(style, &lv_font_montserrat_42);
    lv_style_set_radius(style, 500);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_bg_opa(style, 100);
    lv_style_set_shadow_spread(style, 2);
    lv_style_set_shadow_color(style, lv_color_hex(0xff0b0b0b));
    lv_style_set_shadow_width(style, 50);
};

lv_style_t *get_style_parameter_1_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_parameter_1_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_parameter_1(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_parameter_1_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_parameter_1(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_parameter_1_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Container
//

void init_style_container_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_container_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: barMain
//

void init_style_bar_main_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff00ffff));
    lv_style_set_bg_opa(style, 51);
    lv_style_set_base_dir(style, LV_BASE_DIR_LTR);
};

lv_style_t *get_style_bar_main_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_main_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_bar_main_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff00ffff));
    lv_style_set_bg_opa(style, 200);
    lv_style_set_radius(style, 0);
};

lv_style_t *get_style_bar_main_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_main_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_bar_main(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_bar_main_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_bar_main_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_bar_main(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_bar_main_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_bar_main_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
// Style: tagLabel
//

void add_style_tag_label(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_tag_label(lv_obj_t *obj) {
    (void)obj;
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_test,
        add_style_bar,
        add_style_parameter,
        add_style_parameter_1,
        add_style_container,
        add_style_bar_main,
        add_style_tag_label,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_test,
        remove_style_bar,
        remove_style_parameter,
        remove_style_parameter_1,
        remove_style_container,
        remove_style_bar_main,
        remove_style_tag_label,
    };
    remove_style_funcs[styleIndex](obj);
}

