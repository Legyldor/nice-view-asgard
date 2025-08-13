#include "../../include/central/render.h"

#include <ctype.h>
#include <lvgl.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/sys/util.h>
#include "../../include/colors.h"
#include "../../include/central/initialize_listeners.h"
#include "../../include/fonts/press_start_2p_8.h"
#include "../../include/fonts/press_start_2p_16.h"
#include "../../include/fonts/press_start_2p_24.h"
#include "../../include/main.h"
#include "../../include/utils/draw_battery.h"
#include "../../include/utils/draw_bluetooth_searching.h"
#include "../../include/utils/draw_bluetooth_logo_outlined.h"
#include "../../include/utils/draw_bluetooth_logo.h"
#include "../../include/utils/draw_usb_logo.h"

void render_battery() {
    lv_canvas_fill_bg(battery_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    draw_battery(battery_canvas, 0, 0, states.battery);
}

static void render_bluetooth_logo() {
    if (states.connectivity.active_profile_bonded) {
        if (states.connectivity.active_profile_connected) {
            draw_bluetooth_logo(connectivity_canvas, 16, 0);
        } else {
            draw_bluetooth_logo_outlined(connectivity_canvas, 16, 0);
        }
    } else {
        draw_bluetooth_searching(connectivity_canvas, 16, 0);
    }
}

static void render_bluetooth_profile_index() {
    lv_draw_label_dsc_t label_dsc;
    lv_draw_label_dsc_init(&label_dsc);
    label_dsc.color = FOREGROUND_COLOR;
    label_dsc.font = &press_start_2p_16;
    label_dsc.align = LV_TEXT_ALIGN_RIGHT;

    // Magic number
    static const unsigned padding_x_offset = 2;
    static const unsigned padding_x = padding_x_offset;

    // Magic number
    static const unsigned padding_y_offset = 1;
    // `ceil` is used to tend towards the bottom of the screen.
    const unsigned padding_y = ceil((CONNECTIVITY_CANVAS_HEIGHT - press_start_2p_16.line_height) / 2) + padding_y_offset;
    static const unsigned width = CONNECTIVITY_CANVAS_WIDTH - 12 - 2;
    static const char bluetooth_profile_label[5][2] = {"1", "2", "3", "4", "5"};
    const char* label = bluetooth_profile_label[states.connectivity.active_profile_index];
   
    lv_canvas_draw_text(connectivity_canvas, padding_x, padding_y, width, &label_dsc, label);
}

static void render_bluetooth_connectivity() {
    render_bluetooth_logo();
    render_bluetooth_profile_index();
}

static void render_usb_connectivity() {
    draw_usb_logo(connectivity_canvas, 10, 4);
}

void render_connectivity() {
    lv_canvas_fill_bg(connectivity_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    switch (states.connectivity.selected_endpoint.transport) {
        case ZMK_TRANSPORT_BLE: {
            render_bluetooth_connectivity();
            break;
        }
        case ZMK_TRANSPORT_USB: {
            render_usb_connectivity();
            break;
        }
    }
}

void render_main() {
    lv_draw_rect_dsc_t background_dsc;
    lv_draw_rect_dsc_init(&background_dsc);
    background_dsc.bg_color = BACKGROUND_COLOR;
    
    lv_canvas_draw_rect(
        layer_canvas,
        0,
        0,
        LAYER_CANVAS_WIDTH,
        LAYER_CANVAS_HEIGHT,
        &background_dsc
    );

    // Capitalize the layer name if given or use the layer number otherwise.
    char* text = NULL;
    if (states.layer.name == NULL) {
        text = malloc(10 * sizeof(char));
        sprintf(text, "LAYER %i", states.layer.index);
    }
    else {
        text = malloc((strlen(states.layer.name) + 1) * sizeof(char));
        for (unsigned i = 0; states.layer.name[i] != '\0'; i++) {
#if IS_ENABLED(NICE_VIEW_ELEMENTAL_CAPITALIZATION)
            text[i] = toupper(states.layer.name[i]);
#else
            text[i] = states.layer.name[i];
#endif
        }
        text[strlen(states.layer.name)] = '\0';
    }

    lv_draw_label_dsc_t layer_name_dsc;
    lv_draw_label_dsc_init(&layer_name_dsc);
    layer_name_dsc.color = FOREGROUND_COLOR;
    layer_name_dsc.font = &press_start_2p_24;
    layer_name_dsc.align = LV_TEXT_ALIGN_CENTER;

    lv_canvas_draw_text(
        layer_canvas,
        0,
        0,
        LAYER_CANVAS_WIDTH,
        &layer_name_dsc,
        text
    );

    free(text);
    text = NULL;
}

void render_modifiers() {
    lv_draw_rect_dsc_t background_dsc;
    lv_draw_rect_dsc_init(&background_dsc);
    background_dsc.bg_color = BACKGROUND_COLOR;
    
    lv_canvas_draw_rect(
        modifiers_canvas,
        0,
        0,
        MODIFIERS_CANVAS_WIDTH,
        MODIFIERS_CANVAS_HEIGHT,
        &background_dsc
    );

    lv_draw_rect_dsc_t active_modifier_background_dsc;
    lv_draw_rect_dsc_init(&active_modifier_background_dsc);
    active_modifier_background_dsc.bg_color = FOREGROUND_COLOR;

    lv_draw_label_dsc_t active_modifier_text_dsc;
    lv_draw_label_dsc_init(&active_modifier_text_dsc);
    active_modifier_text_dsc.color = BACKGROUND_COLOR;
    active_modifier_text_dsc.font = &press_start_2p_8;
    active_modifier_text_dsc.align = LV_TEXT_ALIGN_LEFT;

    lv_draw_label_dsc_t inactive_modifier_text_dsc;
    lv_draw_label_dsc_init(&inactive_modifier_text_dsc);
    inactive_modifier_text_dsc.color = FOREGROUND_COLOR;
    inactive_modifier_text_dsc.font = &press_start_2p_8;
    inactive_modifier_text_dsc.align = LV_TEXT_ALIGN_LEFT;

    if (states.modifiers.is_gui_active) {
        lv_canvas_draw_rect(
            modifiers_canvas,
            // 0 * (MODIFIER_WIDTH + MODIFIER_PADDING_X),
            0,
            0,
            MODIFIER_WIDTH,
            MODIFIERS_CANVAS_HEIGHT,
            &active_modifier_background_dsc
        );
    }

    lv_canvas_draw_text(
        modifiers_canvas,
        MODIFIER_PADDING_X,
        MODIFIER_PADDING_Y,
        MODIFIER_WIDTH,
        states.modifiers.is_gui_active ? &active_modifier_text_dsc : &inactive_modifier_text_dsc,
        "W"
    );

    if (states.modifiers.is_alt_active) {
        lv_canvas_draw_rect(
            modifiers_canvas,
            1 * (MODIFIER_WIDTH + MODIFIERS_GAP),
            0,
            MODIFIER_WIDTH,
            MODIFIERS_CANVAS_HEIGHT,
            &active_modifier_background_dsc
        );
    }

    lv_canvas_draw_text(
        modifiers_canvas,
        1 * (MODIFIER_WIDTH + MODIFIERS_GAP) + MODIFIER_PADDING_X,
        MODIFIER_PADDING_Y,
        MODIFIER_WIDTH,
        states.modifiers.is_alt_active ? &active_modifier_text_dsc : &inactive_modifier_text_dsc,
        "A"
    );

    if (states.modifiers.is_ctrl_active) {
        lv_canvas_draw_rect(
            modifiers_canvas,
            2 * (MODIFIER_WIDTH + MODIFIERS_GAP),
            0,
            MODIFIER_WIDTH,
            MODIFIERS_CANVAS_HEIGHT,
            &active_modifier_background_dsc
        );
    }

    lv_canvas_draw_text(
        modifiers_canvas,
        2 * (MODIFIER_WIDTH + MODIFIERS_GAP) + MODIFIER_PADDING_X,
        MODIFIER_PADDING_Y,
        MODIFIER_WIDTH,
        states.modifiers.is_ctrl_active ? &active_modifier_text_dsc : &inactive_modifier_text_dsc,
        "C"
    );

    if (states.modifiers.is_shift_active) {
        lv_canvas_draw_rect(
            modifiers_canvas,
            3 * (MODIFIER_WIDTH + MODIFIERS_GAP),
            0,
            MODIFIER_WIDTH,
            MODIFIERS_CANVAS_HEIGHT,
            &active_modifier_background_dsc
        );
    }

    lv_canvas_draw_text(
        modifiers_canvas,
        3 * (MODIFIER_WIDTH + MODIFIERS_GAP) + MODIFIER_PADDING_X,
        MODIFIER_PADDING_Y,
        MODIFIER_WIDTH,
        states.modifiers.is_shift_active ? &active_modifier_text_dsc : &inactive_modifier_text_dsc,
        "S"
    );
}