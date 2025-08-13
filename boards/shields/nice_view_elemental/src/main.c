#include "../include/main.h"

#include <lvgl.h>
#include <math.h>
#include <zephyr/sys/util_macro.h>
#include "../include/initialize_listeners.h"
#include "../include/colors.h"

lv_obj_t* battery_canvas;
lv_color_t battery_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        BATTERY_CANVAS_WIDTH,
        BATTERY_CANVAS_HEIGHT
    )
];

lv_obj_t* connectivity_canvas;
lv_color_t connectivity_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        CONNECTIVITY_CANVAS_WIDTH,
        CONNECTIVITY_CANVAS_HEIGHT
    )
];

lv_obj_t* layer_canvas;
lv_color_t layer_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        LAYER_CANVAS_WIDTH,
        LAYER_CANVAS_HEIGHT
    )
];

lv_obj_t* modifiers_canvas;
lv_color_t modifiers_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        MODIFIERS_CANVAS_WIDTH,
        MODIFIERS_CANVAS_HEIGHT
    )
];

#if (defined(CONFIG_ZMK_SPLIT) && !defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
lv_obj_t* image_canvas;
lv_color_t image_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        IMAGE_CANVAS_WIDTH,
        IMAGE_CANVAS_HEIGHT
    )
];
#endif

// ZMK calls this function directly in `app/src/display/main.c` of its source
// code.
lv_obj_t* zmk_display_status_screen() {
    // Setup the base screen.
    lv_obj_t* screen = lv_obj_create(NULL);
    lv_obj_set_size(screen, SCREEN_WIDTH, SCREEN_HEIGHT);

#if (defined(CONFIG_ZMK_SPLIT) && defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
    // Create the main canvas to be used in the `render_main` function.
    layer_canvas = lv_canvas_create(screen);
    lv_obj_align(
        layer_canvas,
        LV_ALIGN_TOP_LEFT,
        PADDING,
        // `ceil` is used to tend towards the bottom of the screen.
        PADDING + ceil((SCREEN_HEIGHT - LAYER_CANVAS_HEIGHT - STATUS_HEIGHT) / 2)
    );
    lv_canvas_set_buffer(
        layer_canvas,
        layer_canvas_buffer,
        LAYER_CANVAS_WIDTH,
        LAYER_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );

    modifiers_canvas = lv_canvas_create(screen);
    lv_obj_align(
        modifiers_canvas,
        LV_ALIGN_BOTTOM_MID,
        0,
        -4
    );
    lv_canvas_set_buffer(
        modifiers_canvas,
        modifiers_canvas_buffer,
        MODIFIERS_CANVAS_WIDTH,
        MODIFIERS_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );
#endif

    // Create the battery canvas to be used in the `render_battery` function.
    battery_canvas = lv_canvas_create(screen);
    lv_obj_align(
        battery_canvas,
#if (defined(CONFIG_ZMK_SPLIT) && !defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
        LV_ALIGN_TOP_RIGHT,
        -PADDING,
        PADDING + 3
#else
        LV_ALIGN_BOTTOM_LEFT,
        PADDING,
        -PADDING - 3
#endif
    );
    lv_canvas_set_buffer(
        battery_canvas,
        battery_canvas_buffer,
        BATTERY_CANVAS_WIDTH,
        BATTERY_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );
    
    // Create the info canvas to be used in the `render_connectivity` function.
    connectivity_canvas = lv_canvas_create(screen);
    lv_obj_align(
        connectivity_canvas,
#if (defined(CONFIG_ZMK_SPLIT) && !defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
        LV_ALIGN_TOP_LEFT,
        PADDING,
        PADDING
#else
        LV_ALIGN_BOTTOM_RIGHT,
        -PADDING,
        -PADDING
#endif
    );
    lv_canvas_set_buffer(
        connectivity_canvas,
        connectivity_canvas_buffer,
        CONNECTIVITY_CANVAS_WIDTH,
        CONNECTIVITY_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );
    
#if (defined(CONFIG_ZMK_SPLIT) && !defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
    // Create the info canvas to be used in the `render_image` function.
    image_canvas = lv_animimg_create(screen);
    lv_obj_align(
        image_canvas,
        LV_ALIGN_CENTER,
        0,
        0
    );
#endif
    
    // Depending on which half the build is for, the implementation will differ.
    initialize_listeners();

    return screen;
}
