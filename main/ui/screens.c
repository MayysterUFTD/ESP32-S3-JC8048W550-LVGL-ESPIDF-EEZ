#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main()
{
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 280, 126);
            lv_obj_set_size(obj, 240, 229);
            lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);
            lv_scale_set_range(obj, 0, 200);
            lv_scale_set_total_tick_count(obj, 51);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, true);
            lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffff0000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xfff61212), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffeaeaea), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 272, 115);
            lv_obj_set_size(obj, 257, 250);
            lv_arc_set_value(obj, 25);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff00ffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe0cdcd), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            lv_obj_set_pos(obj, 69, 40);
            lv_obj_set_size(obj, 268, 248);
            lv_arc_set_value(obj, 25);
        }
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            lv_obj_set_pos(obj, 627, 46);
            lv_obj_set_size(obj, 80, 80);
            lv_spinner_set_anim_params(obj, 1000, 60);
        }
        {
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            lv_obj_set_pos(obj, 542, 213);
            lv_obj_set_size(obj, 213, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Option 1\nOption 2\nOption 3");
            lv_dropdown_set_selected(obj, 0);
        }
    }

    tick_screen_main();
}

void delete_screen_main()
{
    lv_obj_delete(objects.main);
    objects.main = 0;
    objects.obj0 = 0;
    objects.obj1 = 0;
    deletePageFlowState(0);
}

void tick_screen_main()
{
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

static const char *screen_names[] = {"Main"};
static const char *object_names[] = {"main", "obj0", "obj1"};

typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_main,
};
void create_screen(int screen_index)
{
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId)
{
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_main,
};
void delete_screen(int screen_index)
{
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId)
{
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index)
{
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId)
{
    tick_screen_funcs[screenId - 1]();
}

void create_screens()
{
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));

    eez_flow_set_create_screen_func(create_screen);
    eez_flow_set_delete_screen_func(delete_screen);

    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    create_screen_main();
}
