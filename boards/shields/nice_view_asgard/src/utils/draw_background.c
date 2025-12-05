#include "../../include/utils/draw_background.h"

#include <lvgl.h>
#include "../../include/images/logo_0.h"
#include "../../include/images/logo_1.h"
#include "../../include/images/logo_2.h"
#include "../../include/images/logo_3.h"
#include "../../include/images/logo_4.h"
#include "../../include/images/logo_5.h"
#include "../../include/images/logo_6.h"
#include "../../include/images/logo_7.h"
#include "../../include/images/logo_8.h"
#include "../../include/images/logo_9.h"
#include "../../include/images/logo_10.h"
#include "../../include/images/logo_11.h"
#include "../../include/images/logo_12.h"
#include "../../include/images/logo_13.h"
#include "../../include/images/logo_14.h"
#include "../../include/images/logo_15.h"
#include "../../include/images/logo_16.h"
#include "../../include/images/logo_17.h"
#include "../../include/images/logo_18.h"
#include "../../include/images/logo_19.h"
#include "../../include/images/logo_20.h"
#include "../../include/images/logo_21.h"
#include "../../include/images/logo_22.h"
#include "../../include/images/logo_23.h"
#include "../../include/images/logo_24.h"
#include "../../include/images/logo_25.h"
#include "../../include/images/logo_26.h"
#include "../../include/images/logo_27.h"
#include "../../include/images/logo_28.h"
#include "../../include/images/logo_29.h"
#include "../../include/images/logo_30.h"
#include "../../include/images/logo_31.h"
#include "../../include/images/logo_32.h"
#include "../../include/images/logo_33.h"
#include "../../include/images/logo_34.h"
#include "../../include/images/logo_35.h"
#include "../../include/images/logo_36.h"
#include "../../include/images/logo_37.h"
#include "../../include/images/logo_38.h"
#include "../../include/images/logo_39.h"
#include "../../include/images/logo_40.h"
#include "../../include/images/logo_41.h"
#include "../../include/images/logo_42.h"
#include "../../include/images/logo_43.h"
#include "../../include/images/logo_44.h"
#include "../../include/images/logo_45.h"
#include "../../include/images/logo_46.h"
#include "../../include/images/logo_47.h"
#include "../../include/images/logo_48.h"
#include "../../include/images/logo_49.h"

void draw_background(lv_obj_t* canvas, unsigned index) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    switch (index % 50) {
        case 0: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_0, &img_dsc);
            break;
        }
        case 1: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_1, &img_dsc);
            break;
        }
        case 2: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_2, &img_dsc);
            break;
        }
        case 3: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_3, &img_dsc);
            break;
        }
        case 4: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_4, &img_dsc);
            break;
        }
        case 5: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_5, &img_dsc);
            break;
        }
        case 6: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_6, &img_dsc);
            break;
        }
        case 7: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_7, &img_dsc);
            break;
        }
        case 8: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_8, &img_dsc);
            break;
        }
        case 9: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_9, &img_dsc);
            break;
        }
        case 10: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_10, &img_dsc);
            break;
        }
        case 11: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_11, &img_dsc);
            break;
        }
        case 12: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_12, &img_dsc);
            break;
        }
        case 13: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_13, &img_dsc);
            break;
        }
        case 14: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_14, &img_dsc);
            break;
        }
        case 15: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_15, &img_dsc);
            break;
        }
        case 16: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_16, &img_dsc);
            break;
        }
        case 17: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_17, &img_dsc);
            break;
        }
        case 18: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_18, &img_dsc);
            break;
        }
        case 19: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_19, &img_dsc);
            break;
        }
        case 20: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_20, &img_dsc);
            break;
        }
        case 21: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_21, &img_dsc);
            break;
        }
        case 22: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_22, &img_dsc);
            break;
        }
        case 23: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_23, &img_dsc);
            break;
        }
        case 24: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_24, &img_dsc);
            break;
        }
        case 25: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_25, &img_dsc);
            break;
        }
        case 26: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_26, &img_dsc);
            break;
        }
        case 27: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_27, &img_dsc);
            break;
        }
        case 28: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_28, &img_dsc);
            break;
        }
        case 29: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_29, &img_dsc);
            break;
        }
        case 30: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_30, &img_dsc);
            break;
        }
        case 31: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_31, &img_dsc);
            break;
        }
        case 32: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_32, &img_dsc);
            break;
        }
        case 33: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_33, &img_dsc);
            break;
        }
        case 34: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_34, &img_dsc);
            break;
        }
        case 35: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_35, &img_dsc);
            break;
        }
        case 36: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_36, &img_dsc);
            break;
        }
        case 37: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_37, &img_dsc);
            break;
        }
        case 38: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_38, &img_dsc);
            break;
        }
        case 39: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_39, &img_dsc);
            break;
        }
        case 40: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_40, &img_dsc);
            break;
        }
        case 41: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_41, &img_dsc);
            break;
        }
        case 42: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_42, &img_dsc);
            break;
        }
        case 43: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_43, &img_dsc);
            break;
        }
        case 44: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_44, &img_dsc);
            break;
        }
        case 45: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_45, &img_dsc);
            break;
        }
        case 46: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_46, &img_dsc);
            break;
        }
        case 47: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_47, &img_dsc);
            break;
        }
        case 48: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_48, &img_dsc);
            break;
        }
        case 49: {
            lv_canvas_draw_img(canvas, 0, 0, &logo_49, &img_dsc);
            break;
        }
    }
}
