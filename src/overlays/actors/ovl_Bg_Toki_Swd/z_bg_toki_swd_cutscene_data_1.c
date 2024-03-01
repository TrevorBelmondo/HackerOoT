#include "z_bg_toki_swd.h"
#include "z64cutscene_commands.h"

// clang-format off
CutsceneData D_808BB2F0[] = {
    CS_BEGIN_CUTSCENE(9, 425),
    CS_PLAYER_CUE_LIST(1),
        CS_PLAYER_CUE(PLAYER_CUEID_12, 0, 256, 0x0000, 0x0000, 0x0000, 0, 54, 52, 0, 54, 52, CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f), CS_FLOAT(0x0, 0.0f)),
    CS_LIGHT_SETTING_LIST(1),
        CS_LIGHT_SETTING(0x0001, 110, 111, 0x0000, 0x00000000, 0x00000000, 0xFFFFFFE3, 0xFFFFFFC5, 0x00000000, 0xFFFFFFE3, 0xFFFFFFC5),
    CS_MISC_LIST(1),
        CS_MISC(CS_MISC_SET_CSFLAG_1, 110, 111, 0x0000, 0x00000000, 0x00000000, 0x0000002E, 0xFFFFFFE6, 0x00000000, 0x0000002E, 0xFFFFFFE6, 0x00000000, 0x00000000, 0x00000000),
    CS_DESTINATION(CS_DEST_TEMPLE_OF_TIME_FROM_MASTER_SWORD, 230, 231),
    CS_TRANSITION(CS_TRANS_GRAY_FILL_IN, 210, 230),
    CS_CAM_EYE_SPLINE(0, 241),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x018C),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x019D),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x01AE),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x02A8),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x007A),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x0064),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x0074),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -42, 72, -39, 0x005F),
    CS_CAM_EYE_SPLINE(80, 406),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 95, -19, 0x2F73),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 95, -19, 0x6B2F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 95, -19, 0x6169),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 95, -19, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 95, -19, 0x0005),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 129, -34, 0x7961),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -1, 173, -19, 0x742F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -17, 217, -20, 0x2E64),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -24, 328, -12, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -27, 509, -2, 0x2F73),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -41, 813, 10, 0x6B2F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -60, 1285, 38, 0x6D61),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -58, 1910, 91, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -53, 2526, 133, 0x0005),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), -33, 3445, 193, 0x7961),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 0, 3960, 225, 0x742F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 7, 4317, 245, 0x6565),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 7, 4316, 245, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 7, 4316, 245, 0x2F73),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 0, CS_FLOAT(0x42700000, 60.0f), 7, 4316, 245, 0x6B2F),
    CS_CAM_AT_SPLINE(0, 270),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x2F73),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x6B2F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x6169),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x0005),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x7961),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x742F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x2E64),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 30, CS_FLOAT(0x42700000, 60.0f), -20, 85, -9, 0x0000),
    CS_CAM_AT_SPLINE(80, 425),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 5, CS_FLOAT(0x42700000, 60.0f), -1, 112, 7, 0x2F73),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 5, CS_FLOAT(0x42700000, 60.0f), -1, 112, 7, 0x6B2F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 5, CS_FLOAT(0x42700000, 60.0f), -1, 112, 7, 0x6169),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 5, CS_FLOAT(0x42700000, 60.0f), -1, 112, 7, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 15, CS_FLOAT(0x42700000, 60.0f), -1, 112, 7, 0x0005),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x7961),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 25, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x742F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 25, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x2E64),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x2F73),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x6B2F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x6D61),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x0005),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x7961),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x742F),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x6565),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x0000),
        CS_CAM_POINT(CS_CAM_CONTINUE, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x2F73),
        CS_CAM_POINT(CS_CAM_STOP, 0x00, 20, CS_FLOAT(0x42700000, 60.0f), -1, 117, 7, 0x6B2F),
    CS_END(),
};
// clang-format on
