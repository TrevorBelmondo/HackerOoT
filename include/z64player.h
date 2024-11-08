#ifndef Z64PLAYER_H
#define Z64PLAYER_H

#include "z64actor.h"
#include "alignment.h"
#include "face_change.h"

struct Player;

typedef enum PlayerSword {
    /* 0 */ PLAYER_SWORD_NONE,
    /* 1 */ PLAYER_SWORD_KOKIRI,
    /* 2 */ PLAYER_SWORD_MASTER,
    /* 3 */ PLAYER_SWORD_BIGGORON,
    /* 4 */ PLAYER_SWORD_MAX
} PlayerSword;

typedef enum PlayerShield {
    /* 0x00 */ PLAYER_SHIELD_NONE,
    /* 0x01 */ PLAYER_SHIELD_DEKU,
    /* 0x02 */ PLAYER_SHIELD_HYLIAN,
    /* 0x03 */ PLAYER_SHIELD_MIRROR,
    /* 0x04 */ PLAYER_SHIELD_MAX
} PlayerShield;

typedef enum PlayerTunic {
    /* 0x00 */ PLAYER_TUNIC_KOKIRI,
    /* 0x01 */ PLAYER_TUNIC_GORON,
    /* 0x02 */ PLAYER_TUNIC_ZORA,
    /* 0x03 */ PLAYER_TUNIC_MAX
} PlayerTunic;

typedef enum PlayerBoots {
    /* 0x00 */ PLAYER_BOOTS_KOKIRI,
    /* 0x01 */ PLAYER_BOOTS_IRON,
    /* 0x02 */ PLAYER_BOOTS_HOVER,
    /* Values below are only relevant when setting regs in Player_SetBootData */
    /* 0x03 */ PLAYER_BOOTS_INDOOR,
    /* 0x04 */ PLAYER_BOOTS_IRON_UNDERWATER,
    /* 0x05 */ PLAYER_BOOTS_KOKIRI_CHILD,
    /* 0x06 */ PLAYER_BOOTS_MAX
} PlayerBoots;

typedef enum PlayerStrength {
    /* 0x00 */ PLAYER_STR_NONE,
    /* 0x01 */ PLAYER_STR_BRACELET,
    /* 0x02 */ PLAYER_STR_SILVER_G,
    /* 0x03 */ PLAYER_STR_GOLD_G,
    /* 0x04 */ PLAYER_STR_MAX
} PlayerStrength;

typedef enum PlayerMask {
    /* 0x00 */ PLAYER_MASK_NONE,
    /* 0x01 */ PLAYER_MASK_KEATON,
    /* 0x02 */ PLAYER_MASK_SKULL,
    /* 0x03 */ PLAYER_MASK_SPOOKY,
    /* 0x04 */ PLAYER_MASK_BUNNY,
    /* 0x05 */ PLAYER_MASK_GORON,
    /* 0x06 */ PLAYER_MASK_ZORA,
    /* 0x07 */ PLAYER_MASK_GERUDO,
    /* 0x08 */ PLAYER_MASK_TRUTH,
    /* 0x09 */ PLAYER_MASK_MAX
} PlayerMask;

typedef enum PlayerEnvHazard {
    /* 0x0 */ PLAYER_ENV_HAZARD_NONE,
    /* 0x1 */ PLAYER_ENV_HAZARD_HOTROOM,
    /* 0x2 */ PLAYER_ENV_HAZARD_UNDERWATER_FLOOR,
    /* 0x3 */ PLAYER_ENV_HAZARD_SWIMMING,
    /* 0x4 */ PLAYER_ENV_HAZARD_UNDERWATER_FREE
} PlayerEnvHazard;

typedef enum PlayerIdleType {
    /* -0x1 */ PLAYER_IDLE_CRIT_HEALTH = -1,
    /*  0x0 */ PLAYER_IDLE_DEFAULT,
    /*  0x1 */ PLAYER_IDLE_FIDGET
} PlayerIdleType;

typedef enum PlayerItemAction {
    /* 0x00 */ PLAYER_IA_NONE,
    /* 0x01 */ PLAYER_IA_SWORD_CS, // Hold sword without shield in hand. The sword is not usable.
    /* 0x02 */ PLAYER_IA_FISHING_POLE,
    /* 0x03 */ PLAYER_IA_SWORD_MASTER,
    /* 0x04 */ PLAYER_IA_SWORD_KOKIRI,
    /* 0x05 */ PLAYER_IA_SWORD_BIGGORON,
    /* 0x06 */ PLAYER_IA_DEKU_STICK,
    /* 0x07 */ PLAYER_IA_HAMMER,
    /* 0x08 */ PLAYER_IA_BOW,
    /* 0x09 */ PLAYER_IA_BOW_FIRE,
    /* 0x0A */ PLAYER_IA_BOW_ICE,
    /* 0x0B */ PLAYER_IA_BOW_LIGHT,
    /* 0x0C */ PLAYER_IA_BOW_0C,
    /* 0x0D */ PLAYER_IA_BOW_0D,
    /* 0x0E */ PLAYER_IA_BOW_0E,
    /* 0x0F */ PLAYER_IA_SLINGSHOT,
    /* 0x10 */ PLAYER_IA_HOOKSHOT,
    /* 0x11 */ PLAYER_IA_LONGSHOT,
    /* 0x12 */ PLAYER_IA_BOMB,
    /* 0x13 */ PLAYER_IA_BOMBCHU,
    /* 0x14 */ PLAYER_IA_BOOMERANG,
    /* 0x15 */ PLAYER_IA_MAGIC_SPELL_15,
    /* 0x16 */ PLAYER_IA_MAGIC_SPELL_16,
    /* 0x17 */ PLAYER_IA_MAGIC_SPELL_17,
    /* 0x18 */ PLAYER_IA_FARORES_WIND,
    /* 0x19 */ PLAYER_IA_NAYRUS_LOVE,
    /* 0x1A */ PLAYER_IA_DINS_FIRE,
    /* 0x1B */ PLAYER_IA_DEKU_NUT,
    /* 0x1C */ PLAYER_IA_OCARINA_FAIRY,
    /* 0x1D */ PLAYER_IA_OCARINA_OF_TIME,
    /* 0x1E */ PLAYER_IA_BOTTLE,
    /* 0x1F */ PLAYER_IA_BOTTLE_FISH,
    /* 0x20 */ PLAYER_IA_BOTTLE_FIRE,
    /* 0x21 */ PLAYER_IA_BOTTLE_BUG,
    /* 0x22 */ PLAYER_IA_BOTTLE_POE,
    /* 0x23 */ PLAYER_IA_BOTTLE_BIG_POE,
    /* 0x24 */ PLAYER_IA_BOTTLE_RUTOS_LETTER,
    /* 0x25 */ PLAYER_IA_BOTTLE_POTION_RED,
    /* 0x26 */ PLAYER_IA_BOTTLE_POTION_BLUE,
    /* 0x27 */ PLAYER_IA_BOTTLE_POTION_GREEN,
    /* 0x28 */ PLAYER_IA_BOTTLE_MILK_FULL,
    /* 0x29 */ PLAYER_IA_BOTTLE_MILK_HALF,
    /* 0x2A */ PLAYER_IA_BOTTLE_FAIRY,
    /* 0x2B */ PLAYER_IA_ZELDAS_LETTER,
    /* 0x2C */ PLAYER_IA_WEIRD_EGG,
    /* 0x2D */ PLAYER_IA_CHICKEN,
    /* 0x2E */ PLAYER_IA_MAGIC_BEAN,
    /* 0x2F */ PLAYER_IA_POCKET_EGG,
    /* 0x30 */ PLAYER_IA_POCKET_CUCCO,
    /* 0x31 */ PLAYER_IA_COJIRO,
    /* 0x32 */ PLAYER_IA_ODD_MUSHROOM,
    /* 0x33 */ PLAYER_IA_ODD_POTION,
    /* 0x34 */ PLAYER_IA_POACHERS_SAW,
    /* 0x35 */ PLAYER_IA_BROKEN_GORONS_SWORD,
    /* 0x36 */ PLAYER_IA_PRESCRIPTION,
    /* 0x37 */ PLAYER_IA_FROG,
    /* 0x38 */ PLAYER_IA_EYEDROPS,
    /* 0x39 */ PLAYER_IA_CLAIM_CHECK,
    /* 0x3A */ PLAYER_IA_MASK_KEATON,
    /* 0x3B */ PLAYER_IA_MASK_SKULL,
    /* 0x3C */ PLAYER_IA_MASK_SPOOKY,
    /* 0x3D */ PLAYER_IA_MASK_BUNNY_HOOD,
    /* 0x3E */ PLAYER_IA_MASK_GORON,
    /* 0x3F */ PLAYER_IA_MASK_ZORA,
    /* 0x40 */ PLAYER_IA_MASK_GERUDO,
    /* 0x41 */ PLAYER_IA_MASK_TRUTH,
    /* 0x42 */ PLAYER_IA_LENS_OF_TRUTH,
    /* 0x43 */ PLAYER_IA_MAX
} PlayerItemAction;

typedef enum PlayerLimb {
    /* 0x00 */ PLAYER_LIMB_NONE,
    /* 0x01 */ PLAYER_LIMB_ROOT,
    /* 0x02 */ PLAYER_LIMB_WAIST,
    /* 0x03 */ PLAYER_LIMB_LOWER,
    /* 0x04 */ PLAYER_LIMB_R_THIGH,
    /* 0x05 */ PLAYER_LIMB_R_SHIN,
    /* 0x06 */ PLAYER_LIMB_R_FOOT,
    /* 0x07 */ PLAYER_LIMB_L_THIGH,
    /* 0x08 */ PLAYER_LIMB_L_SHIN,
    /* 0x09 */ PLAYER_LIMB_L_FOOT,
    /* 0x0A */ PLAYER_LIMB_UPPER,
    /* 0x0B */ PLAYER_LIMB_HEAD,
    /* 0x0C */ PLAYER_LIMB_HAT,
    /* 0x0D */ PLAYER_LIMB_COLLAR,
    /* 0x0E */ PLAYER_LIMB_L_SHOULDER,
    /* 0x0F */ PLAYER_LIMB_L_FOREARM,
    /* 0x10 */ PLAYER_LIMB_L_HAND,
    /* 0x11 */ PLAYER_LIMB_R_SHOULDER,
    /* 0x12 */ PLAYER_LIMB_R_FOREARM,
    /* 0x13 */ PLAYER_LIMB_R_HAND,
    /* 0x14 */ PLAYER_LIMB_SHEATH,
    /* 0x15 */ PLAYER_LIMB_TORSO,
    /* 0x16 */ PLAYER_LIMB_MAX
} PlayerLimb;

typedef enum PlayerBodyPart {
    /* 0x00 */ PLAYER_BODYPART_WAIST,      // PLAYER_LIMB_WAIST
    /* 0x01 */ PLAYER_BODYPART_R_THIGH,    // PLAYER_LIMB_R_THIGH
    /* 0x02 */ PLAYER_BODYPART_R_SHIN,     // PLAYER_LIMB_R_SHIN
    /* 0x03 */ PLAYER_BODYPART_R_FOOT,     // PLAYER_LIMB_R_FOOT
    /* 0x04 */ PLAYER_BODYPART_L_THIGH,    // PLAYER_LIMB_L_THIGH
    /* 0x05 */ PLAYER_BODYPART_L_SHIN,     // PLAYER_LIMB_L_SHIN
    /* 0x06 */ PLAYER_BODYPART_L_FOOT,     // PLAYER_LIMB_L_FOOT
    /* 0x07 */ PLAYER_BODYPART_HEAD,       // PLAYER_LIMB_HEAD
    /* 0x08 */ PLAYER_BODYPART_HAT,        // PLAYER_LIMB_HAT
    /* 0x09 */ PLAYER_BODYPART_COLLAR,     // PLAYER_LIMB_COLLAR
    /* 0x0A */ PLAYER_BODYPART_L_SHOULDER, // PLAYER_LIMB_L_SHOULDER
    /* 0x0B */ PLAYER_BODYPART_L_FOREARM,  // PLAYER_LIMB_L_FOREARM
    /* 0x0C */ PLAYER_BODYPART_L_HAND,     // PLAYER_LIMB_L_HAND
    /* 0x0D */ PLAYER_BODYPART_R_SHOULDER, // PLAYER_LIMB_R_SHOULDER
    /* 0x0E */ PLAYER_BODYPART_R_FOREARM,  // PLAYER_LIMB_R_FOREARM
    /* 0x0F */ PLAYER_BODYPART_R_HAND,     // PLAYER_LIMB_R_HAND
    /* 0x10 */ PLAYER_BODYPART_SHEATH,     // PLAYER_LIMB_SHEATH
    /* 0x11 */ PLAYER_BODYPART_TORSO,      // PLAYER_LIMB_TORSO
    /* 0x12 */ PLAYER_BODYPART_MAX
} PlayerBodyPart;

typedef enum PlayerMeleeWeaponAnimation {
    /*  0 */ PLAYER_MWA_FORWARD_SLASH_1H,
    /*  1 */ PLAYER_MWA_FORWARD_SLASH_2H,
    /*  2 */ PLAYER_MWA_FORWARD_COMBO_1H,
    /*  3 */ PLAYER_MWA_FORWARD_COMBO_2H,
    /*  4 */ PLAYER_MWA_RIGHT_SLASH_1H,
    /*  5 */ PLAYER_MWA_RIGHT_SLASH_2H,
    /*  6 */ PLAYER_MWA_RIGHT_COMBO_1H,
    /*  7 */ PLAYER_MWA_RIGHT_COMBO_2H,
    /*  8 */ PLAYER_MWA_LEFT_SLASH_1H,
    /*  9 */ PLAYER_MWA_LEFT_SLASH_2H,
    /* 10 */ PLAYER_MWA_LEFT_COMBO_1H,
    /* 11 */ PLAYER_MWA_LEFT_COMBO_2H,
    /* 12 */ PLAYER_MWA_STAB_1H,
    /* 13 */ PLAYER_MWA_STAB_2H,
    /* 14 */ PLAYER_MWA_STAB_COMBO_1H,
    /* 15 */ PLAYER_MWA_STAB_COMBO_2H,
    /* 16 */ PLAYER_MWA_FLIPSLASH_START,
    /* 17 */ PLAYER_MWA_JUMPSLASH_START,
    /* 18 */ PLAYER_MWA_FLIPSLASH_FINISH,
    /* 19 */ PLAYER_MWA_JUMPSLASH_FINISH,
    /* 20 */ PLAYER_MWA_BACKSLASH_RIGHT,
    /* 21 */ PLAYER_MWA_BACKSLASH_LEFT,
    /* 22 */ PLAYER_MWA_HAMMER_FORWARD,
    /* 23 */ PLAYER_MWA_HAMMER_SIDE,
    /* 24 */ PLAYER_MWA_SPIN_ATTACK_1H,
    /* 25 */ PLAYER_MWA_SPIN_ATTACK_2H,
    /* 26 */ PLAYER_MWA_BIG_SPIN_1H,
    /* 27 */ PLAYER_MWA_BIG_SPIN_2H,
    /* 28 */ PLAYER_MWA_MAX
} PlayerMeleeWeaponAnimation;

typedef enum PlayerDoorType {
    /* -1 */ PLAYER_DOORTYPE_AJAR = -1,
    /*  0 */ PLAYER_DOORTYPE_NONE,
    /*  1 */ PLAYER_DOORTYPE_HANDLE,
    /*  2 */ PLAYER_DOORTYPE_SLIDING,
    /*  3 */ PLAYER_DOORTYPE_FAKE
} PlayerDoorType;

typedef enum PlayerFacePart {
    /* 0 */ PLAYER_FACEPART_EYES,
    /* 1 */ PLAYER_FACEPART_MOUTH,
    /* 2 */ PLAYER_FACEPART_MAX
} PlayerFacePart;

typedef enum PlayerEyes {
    /* 0 */ PLAYER_EYES_OPEN,
    /* 1 */ PLAYER_EYES_HALF,
    /* 2 */ PLAYER_EYES_CLOSED,
    /* 3 */ PLAYER_EYES_LEFT,
    /* 4 */ PLAYER_EYES_RIGHT,
    /* 5 */ PLAYER_EYES_WIDE,
    /* 6 */ PLAYER_EYES_DOWN,
    /* 7 */ PLAYER_EYES_WINCING,
    /* 8 */ PLAYER_EYES_MAX
} PlayerEyes;

typedef enum PlayerMouth {
    /* 0 */ PLAYER_MOUTH_CLOSED,
    /* 1 */ PLAYER_MOUTH_HALF,
    /* 2 */ PLAYER_MOUTH_OPEN,
    /* 3 */ PLAYER_MOUTH_SMILE,
    /* 4 */ PLAYER_MOUTH_MAX
} PlayerMouth;

typedef enum PlayerFace {
    /*  0 */ PLAYER_FACE_NEUTRAL,                   // eyes open and mouth closed
    /*  1 */ PLAYER_FACE_NEUTRAL_BLINKING_HALF,     // eyes half open and mouth closed
    /*  2 */ PLAYER_FACE_NEUTRAL_BLINKING_CLOSED,   // eyes and mouth closed
    /*  3 */ PLAYER_FACE_NEUTRAL_2,                 // same as `PLAYER_FACE_NEUTRAL`
    /*  4 */ PLAYER_FACE_NEUTRAL_BLINKING_HALF_2,   // same as `PLAYER_FACE_NEUTRAL_BLINKING_HALF`
    /*  5 */ PLAYER_FACE_NEUTRAL_BLINKING_CLOSED_2, // same as `PLAYER_FACE_NEUTRAL_BLINKING_CLOSED`
    /*  6 */ PLAYER_FACE_LOOK_RIGHT,                // eyes looking right and mouth closed
    /*  7 */ PLAYER_FACE_SURPRISED,                 // wide eyes and grimacing mouth
    /*  8 */ PLAYER_FACE_HURT,                      // eyes wincing in pain and mouth open
    /*  9 */ PLAYER_FACE_GASP,                      // eyes and mouth open
    /* 10 */ PLAYER_FACE_LOOK_LEFT,                 // eyes looking left and mouth closed
    /* 11 */ PLAYER_FACE_LOOK_RIGHT_2,              // duplicate of `PLAYER_FACE_LOOK_RIGHT`
    /* 12 */ PLAYER_FACE_EYES_CLOSED_MOUTH_OPEN,    // eyes closed and mouth open
    /* 13 */ PLAYER_FACE_OPENING,                   // eyes and mouth both halfway open
    /* 14 */ PLAYER_FACE_EYES_AND_MOUTH_OPEN,       // eyes and mouth open
    /* 15 */ PLAYER_FACE_NEUTRAL_3,                 // same as `PLAYER_FACE_NEUTRAL` and `PLAYER_FACE_NEUTRAL_2`
    /* 16 */ PLAYER_FACE_MAX
} PlayerFace;

typedef enum PlayerModelGroup {
    /* 0x00 */ PLAYER_MODELGROUP_0, // unused (except for a bug in `Player_OverrideLimbDrawPause`)
    /* 0x01 */ PLAYER_MODELGROUP_CHILD_HYLIAN_SHIELD,  //hold sword only. used for holding sword only as child link with hylian shield equipped
    /* 0x02 */ PLAYER_MODELGROUP_SWORD_AND_SHIELD, // hold sword and shield or just sword if no shield is equipped
    /* 0x03 */ PLAYER_MODELGROUP_DEFAULT, // non-specific models, for items that don't have particular link models
    /* 0x04 */ PLAYER_MODELGROUP_4, // unused, same as PLAYER_MODELGROUP_DEFAULT
    /* 0x05 */ PLAYER_MODELGROUP_BGS, // biggoron sword
    /* 0x06 */ PLAYER_MODELGROUP_BOW_SLINGSHOT, // bow/slingshot
    /* 0x07 */ PLAYER_MODELGROUP_EXPLOSIVES, // bombs, bombchus, same as PLAYER_MODELGROUP_DEFAULT
    /* 0x08 */ PLAYER_MODELGROUP_BOOMERANG,
    /* 0x09 */ PLAYER_MODELGROUP_HOOKSHOT,
    /* 0x0A */ PLAYER_MODELGROUP_10, // stick/fishing pole (which are drawn separately)
    /* 0x0B */ PLAYER_MODELGROUP_HAMMER,
    /* 0x0C */ PLAYER_MODELGROUP_OCARINA, // ocarina
    /* 0x0D */ PLAYER_MODELGROUP_OOT, // ocarina of time
    /* 0x0E */ PLAYER_MODELGROUP_BOTTLE, // bottles (drawn separately)
    /* 0x0F */ PLAYER_MODELGROUP_SWORD, // hold sword and no shield, even if one is equipped
    /* 0x10 */ PLAYER_MODELGROUP_MAX
} PlayerModelGroup;

typedef enum PlayerModelGroupEntry {
    /* 0x00 */ PLAYER_MODELGROUPENTRY_ANIM,
    /* 0x01 */ PLAYER_MODELGROUPENTRY_LEFT_HAND,
    /* 0x02 */ PLAYER_MODELGROUPENTRY_RIGHT_HAND,
    /* 0x03 */ PLAYER_MODELGROUPENTRY_SHEATH,
    /* 0x04 */ PLAYER_MODELGROUPENTRY_WAIST,
    /* 0x05 */ PLAYER_MODELGROUPENTRY_MAX
} PlayerModelGroupEntry;

typedef enum PlayerModelType {
    // left hand
    /* 0x00 */ PLAYER_MODELTYPE_LH_OPEN, // empty open hand
    /* 0x01 */ PLAYER_MODELTYPE_LH_CLOSED, // empty closed hand
    /* 0x02 */ PLAYER_MODELTYPE_LH_SWORD, // holding kokiri/master sword
    /* 0x03 */ PLAYER_MODELTYPE_LH_SWORD_2, // unused, same as PLAYER_MODELTYPE_LH_SWORD
    /* 0x04 */ PLAYER_MODELTYPE_LH_BGS, // holding bgs/broken giant knife (child: master sword)
    /* 0x05 */ PLAYER_MODELTYPE_LH_HAMMER, // holding hammer (child: empty hand)
    /* 0x06 */ PLAYER_MODELTYPE_LH_BOOMERANG, // holding boomerang (adult: empty hand)
    /* 0x07 */ PLAYER_MODELTYPE_LH_BOTTLE, // holding bottle (bottle drawn separately)
    // right hand
    /* 0x08 */ PLAYER_MODELTYPE_RH_OPEN, // empty open hand
    /* 0x09 */ PLAYER_MODELTYPE_RH_CLOSED, // empty closed hand
    /* 0x0A */ PLAYER_MODELTYPE_RH_SHIELD, // holding a shield (including no shield)
    /* 0x0B */ PLAYER_MODELTYPE_RH_BOW_SLINGSHOT, // holding bow/slingshot
    /* 0x0C */ PLAYER_MODELTYPE_RH_BOW_SLINGSHOT_2, // unused, same as PLAYER_MODELTYPE_RH_BOW_SLINGSHOT
    /* 0x0D */ PLAYER_MODELTYPE_RH_OCARINA, // holding ocarina (child: fairy ocarina, adult: OoT)
    /* 0x0E */ PLAYER_MODELTYPE_RH_OOT, // holding OoT
    /* 0x0F */ PLAYER_MODELTYPE_RH_HOOKSHOT, // holding hookshot (child: empty hand)
    // sheath
    /* 0x10 */ PLAYER_MODELTYPE_SHEATH_16, // sheathed kokiri/master sword?
    /* 0x11 */ PLAYER_MODELTYPE_SHEATH_17, // empty sheath?
    /* 0x12 */ PLAYER_MODELTYPE_SHEATH_18, // sword sheathed and shield on back?
    /* 0x13 */ PLAYER_MODELTYPE_SHEATH_19, // empty sheath and shield on back?
    // waist
    /* 0x14 */ PLAYER_MODELTYPE_WAIST,
    /* 0x15 */ PLAYER_MODELTYPE_MAX,
    /* 0xFF */ PLAYER_MODELTYPE_RH_FF = 0xFF // disable shield collider, cutscene-specific
} PlayerModelType;

typedef enum PlayerAnimType {
    /* 0x00 */ PLAYER_ANIMTYPE_0,
    /* 0x01 */ PLAYER_ANIMTYPE_1,
    /* 0x02 */ PLAYER_ANIMTYPE_2,
    /* 0x03 */ PLAYER_ANIMTYPE_3,
    /* 0x04 */ PLAYER_ANIMTYPE_4,
    /* 0x05 */ PLAYER_ANIMTYPE_5,
    /* 0x06 */ PLAYER_ANIMTYPE_MAX
} PlayerAnimType;

/**
 * Temporary names, derived from original animation names in `D_80853914`
 */
typedef enum PlayerAnimGroup {
    /* 0x00 */ PLAYER_ANIMGROUP_wait,
    /* 0x01 */ PLAYER_ANIMGROUP_walk,
    /* 0x02 */ PLAYER_ANIMGROUP_run,
    /* 0x03 */ PLAYER_ANIMGROUP_damage_run,
    /* 0x04 */ PLAYER_ANIMGROUP_heavy_run,
    /* 0x05 */ PLAYER_ANIMGROUP_waitL,
    /* 0x06 */ PLAYER_ANIMGROUP_waitR,
    /* 0x07 */ PLAYER_ANIMGROUP_wait2waitR,
    /* 0x08 */ PLAYER_ANIMGROUP_normal2fighter,
    /* 0x09 */ PLAYER_ANIMGROUP_doorA_free,
    /* 0x0A */ PLAYER_ANIMGROUP_doorA,
    /* 0x0B */ PLAYER_ANIMGROUP_doorB_free,
    /* 0x0C */ PLAYER_ANIMGROUP_doorB,
    /* 0x0D */ PLAYER_ANIMGROUP_carryB,
    /* 0x0E */ PLAYER_ANIMGROUP_landing,
    /* 0x0F */ PLAYER_ANIMGROUP_short_landing,
    /* 0x10 */ PLAYER_ANIMGROUP_landing_roll,
    /* 0x11 */ PLAYER_ANIMGROUP_hip_down,
    /* 0x12 */ PLAYER_ANIMGROUP_walk_endL,
    /* 0x13 */ PLAYER_ANIMGROUP_walk_endR,
    /* 0x14 */ PLAYER_ANIMGROUP_defense,
    /* 0x15 */ PLAYER_ANIMGROUP_defense_wait,
    /* 0x16 */ PLAYER_ANIMGROUP_defense_end,
    /* 0x17 */ PLAYER_ANIMGROUP_side_walk,
    /* 0x18 */ PLAYER_ANIMGROUP_side_walkL,
    /* 0x19 */ PLAYER_ANIMGROUP_side_walkR,
    /* 0x1A */ PLAYER_ANIMGROUP_45_turn,
    /* 0x1B */ PLAYER_ANIMGROUP_waitL2wait,
    /* 0x1C */ PLAYER_ANIMGROUP_waitR2wait,
    /* 0x1D */ PLAYER_ANIMGROUP_throw,
    /* 0x1E */ PLAYER_ANIMGROUP_put,
    /* 0x1F */ PLAYER_ANIMGROUP_back_walk,
    /* 0x20 */ PLAYER_ANIMGROUP_check,
    /* 0x21 */ PLAYER_ANIMGROUP_check_wait,
    /* 0x22 */ PLAYER_ANIMGROUP_check_end,
    /* 0x23 */ PLAYER_ANIMGROUP_pull_start,
    /* 0x24 */ PLAYER_ANIMGROUP_pulling,
    /* 0x25 */ PLAYER_ANIMGROUP_pull_end,
    /* 0x26 */ PLAYER_ANIMGROUP_fall_up,
    /* 0x27 */ PLAYER_ANIMGROUP_jump_climb_hold,
    /* 0x28 */ PLAYER_ANIMGROUP_jump_climb_wait,
    /* 0x29 */ PLAYER_ANIMGROUP_jump_climb_up,
    /* 0x2A */ PLAYER_ANIMGROUP_down_slope_slip_end,
    /* 0x2B */ PLAYER_ANIMGROUP_up_slope_slip_end,
    /* 0x2C */ PLAYER_ANIMGROUP_nwait,
    /* 0x2D */ PLAYER_ANIMGROUP_MAX
} PlayerAnimGroup;

#define LIMB_BUF_COUNT(limbCount) ((ALIGN16((limbCount) * sizeof(Vec3s)) + sizeof(Vec3s) - 1) / sizeof(Vec3s))
#define PLAYER_LIMB_BUF_COUNT LIMB_BUF_COUNT(PLAYER_LIMB_MAX)

typedef enum PlayerCsAction {
    /* 0x00 */ PLAYER_CSACTION_NONE,
    /* 0x01 */ PLAYER_CSMODE_IDLE,
    /* 0x02 */ PLAYER_CSMODE_TURN_AROUND_SURPRISED_SHORT,
    /* 0x03 */ PLAYER_CSACTION_3,
    /* 0x04 */ PLAYER_CSACTION_4,
    /* 0x05 */ PLAYER_CSMODE_SURPRISED,
    /* 0x06 */ PLAYER_CSACTION_6,
    /* 0x07 */ PLAYER_CSMODE_END,
    /* 0x08 */ PLAYER_CSMODE_WAIT,
    /* 0x09 */ PLAYER_CSMODE_TURN_AROUND_SURPRISED_LONG,
    /* 0x0A */ PLAYER_CSMODE_ENTER_WARP,
    /* 0x0B */ PLAYER_CSMODE_RAISED_BY_WARP,
    /* 0x0C */ PLAYER_CSMODE_FIGHT_STANCE,
    /* 0x0D */ PLAYER_CSMODE_START_GET_SPIRITUAL_STONE,
    /* 0x0E */ PLAYER_CSMODE_GET_SPIRITUAL_STONE,
    /* 0x0F */ PLAYER_CSMODE_END_GET_SPIRITUAL_STONE,
    /* 0x10 */ PLAYER_CSMODE_GET_UP_FROM_DEKU_TREE_STORY,
    /* 0x11 */ PLAYER_CSMODE_SIT_LISTENING_TO_DEKU_TREE_STORY,
    /* 0x12 */ PLAYER_CSMODE_SWORD_INTO_PEDESTAL,
    /* 0x13 */ PLAYER_CSMODE_REACT_TO_QUAKE,
    /* 0x14 */ PLAYER_CSMODE_END_REACT_TO_QUAKE,
    /* 0x15 */ PLAYER_CSACTION_21,
    /* 0x16 */ PLAYER_CSMODE_WARP_TO_SAGES,
    /* 0x17 */ PLAYER_CSMODE_LOOK_AT_SELF,
    /* 0x18 */ PLAYER_CSMODE_KNOCKED_TO_GROUND,
    /* 0x19 */ PLAYER_CSMODE_GET_UP_FROM_GROUND,
    /* 0x1A */ PLAYER_CSMODE_START_PLAY_OCARINA,
    /* 0x1B */ PLAYER_CSMODE_END_PLAY_OCARINA,
    /* 0x1C */ PLAYER_CSMODE_GET_ITEM,
    /* 0x1D */ PLAYER_CSMODE_IDLE_2,
    /* 0x1E */ PLAYER_CSMODE_DRAW_AND_BRANDISH_SWORD,
    /* 0x1F */ PLAYER_CSMODE_CLOSE_EYES,
    /* 0x20 */ PLAYER_CSMODE_OPEN_EYES,
    /* 0x21 */ PLAYER_CSMODE_SURPRIED_STUMBLE_BACK_AND_FALL,
    /* 0x22 */ PLAYER_CSMODE_SURFACE_FROM_DIVE,
    /* 0x23 */ PLAYER_CSMODE_GET_ITEM_IN_WATER,
    /* 0x24 */ PLAYER_CSMODE_GENTLE_KNOCKBACK_INTO_SIT,
    /* 0x25 */ PLAYER_CSMODE_GRABBED_AND_CARRIED_BY_NECK,
    /* 0x26 */ PLAYER_CSMODE_SLEEPING_RESTLESS,
    /* 0x27 */ PLAYER_CSMODE_SLEEPING,
    /* 0x28 */ PLAYER_CSMODE_AWAKEN,
    /* 0x29 */ PLAYER_CSMODE_GET_OFF_BED,
    /* 0x2A */ PLAYER_CSMODE_BLOWN_BACKWARD,
    /* 0x2B */ PLAYER_CSMODE_STAND_UP_AND_WATCH,
    /* 0x2C */ PLAYER_CSMODE_IDLE_3,
    /* 0x2D */ PLAYER_CSMODE_STOP,
    /* 0x2E */ PLAYER_CSMODE_STOP_2,
    /* 0x2F */ PLAYER_CSMODE_LOOK_THROUGH_PEEPHOLE,
    /* 0x30 */ PLAYER_CSMODE_STEP_BACK_CAUTIOUSLY,
    /* 0x31 */ PLAYER_CSMODE_IDLE_4,
    /* 0x32 */ PLAYER_CSMODE_DRAW_SWORD_CHILD,
    /* 0x33 */ PLAYER_CSMODE_JUMP_TO_ZELDAS_CRYSTAL,
    /* 0x34 */ PLAYER_CSMODE_DESPERATE_LOOKING_AT_ZELDAS_CRYSTAL,
    /* 0x35 */ PLAYER_CSMODE_LOOK_UP_AT_ZELDAS_CRYSTAL_VANISHING,
    /* 0x36 */ PLAYER_CSMODE_TURN_AROUND_SLOWLY,
    /* 0x37 */ PLAYER_CSMODE_END_SHIELD_EYES_WITH_HAND,
    /* 0x38 */ PLAYER_CSMODE_SHIELD_EYES_WITH_HAND,
    /* 0x39 */ PLAYER_CSMODE_LOOK_AROUND_SURPRISED,
    /* 0x3A */ PLAYER_CSMODE_INSPECT_GROUND_CAREFULLY,
    /* 0x3B */ PLAYER_CSMODE_STARTLED_BY_GORONS_FALLING,
    /* 0x3C */ PLAYER_CSMODE_FALL_TO_KNEE,
    /* 0x3D */ PLAYER_CSMODE_FLAT_ON_BACK,
    /* 0x3E */ PLAYER_CSMODE_RAISE_FROM_FLAT_ON_BACK,
    /* 0x3F */ PLAYER_CSMODE_START_SPIN_ATTACK,
    /* 0x40 */ PLAYER_CSMODE_ZELDA_CLOUDS_CUTSCENE_IDLE,
    /* 0x41 */ PLAYER_CSMODE_ZELDA_CLOUDS_CUTSCENE_START_PASS_OCARINA,
    /* 0x42 */ PLAYER_CSMODE_ZELDA_CLOUDS_CUTSCENE_END_PASS_OCARINA,
    /* 0x43 */ PLAYER_CSMODE_START_LOOK_AROUND_AFTER_SWORD_WARP,
    /* 0x44 */ PLAYER_CSMODE_END_LOOK_AROUND_AFTER_SWORD_WARP,
    /* 0x45 */ PLAYER_CSMODE_LOOK_AROUND_AND_AT_SELF_QUICKLY,
    /* 0x46 */ PLAYER_CSMODE_START_LEARN_OCARINA_SONG_ADULT,
    /* 0x47 */ PLAYER_CSMODE_END_LEARN_OCARINA_SONG_ADULT,
    /* 0x48 */ PLAYER_CSMODE_START_LEARN_OCARINA_SONG_CHILD,
    /* 0x49 */ PLAYER_CSMODE_END_LEARN_OCARINA_SONG_CHILD,
    /* 0x4A */ PLAYER_CSMODE_RESIST_DARK_MAGIC,
    /* 0x4B */ PLAYER_CSMODE_TRIFORCE_HAND_RESONATES,
    /* 0x4C */ PLAYER_CSMODE_STARE_DOWN_STARTLED,
    /* 0x4D */ PLAYER_CSMODE_LOOK_UP_STARTLED,
    /* 0x4E */ PLAYER_CSMODE_LOOK_TO_CHARACTER_AT_SIDE_SMILING,
    /* 0x4F */ PLAYER_CSMODE_LOOK_TO_CHARACTER_ABOVE_SMILING,
    /* 0x50 */ PLAYER_CSMODE_SURPRISED_DEFENSE,
    /* 0x51 */ PLAYER_CSMODE_START_HALF_TURN_SURPRISED,
    /* 0x52 */ PLAYER_CSMODE_END_HALF_TURN_SURPRISED,
    /* 0x53 */ PLAYER_CSMODE_START_LOOK_UP_DEFENSE,
    /* 0x54 */ PLAYER_CSMODE_LOOK_UP_DEFENSE_IDLE,
    /* 0x55 */ PLAYER_CSMODE_END_LOOK_UP_DEFENSE,
    /* 0x56 */ PLAYER_CSMODE_START_SWORD_KNOCKED_FROM_HAND,
    /* 0x57 */ PLAYER_CSMODE_SWORD_KNOCKED_FROM_HAND_IDLE,
    /* 0x58 */ PLAYER_CSMODE_END_SWORD_KNOCKED_FROM_HAND,
    /* 0x59 */ PLAYER_CSMODE_SPIN_ATTACK_IDLE,
    /* 0x5A */ PLAYER_CSMODE_INSPECT_WEAPON,
    /* 0x5B */ PLAYER_CSACTION_91,
    /* 0x5C */ PLAYER_CSMODE_KNOCKED_TO_GROUND_WITH_DAMAGE_EFFECT,
    /* 0x5D */ PLAYER_CSMODE_REACT_TO_HEAT,
    /* 0x5E */ PLAYER_CSMODE_GET_SWORD_BACK,
    /* 0x5F */ PLAYER_CSMODE_CAUGHT_BY_GUARD,
    /* 0x60 */ PLAYER_CSMODE_GET_SWORD_BACK_2,
    /* 0x61 */ PLAYER_CSMODE_START_GANON_KILL_COMBO,
    /* 0x62 */ PLAYER_CSMODE_END_GANON_KILL_COMBO,
    /* 0x63 */ PLAYER_CSMODE_WATCH_ZELDA_STUN_GANON,
    /* 0x64 */ PLAYER_CSMODE_START_LOOK_AT_SWORD_GLOW,
    /* 0x65 */ PLAYER_CSMODE_LOOK_AT_SWORD_GLOW_IDLE,
    /* 0x66 */ PLAYER_CSMODE_END_LOOK_AT_SWORD_GLOW,
    /* 0x67 */ PLAYER_CSACTION_MAX
} PlayerCsAction;

typedef enum PlayerCueId {
    /* 0x00 */ PLAYER_CUEID_NONE,
    /* 0x01 */ PLAYER_CUEID_1,
    /* 0x02 */ PLAYER_CUEID_2,
    /* 0x03 */ PLAYER_CUEID_3,
    /* 0x04 */ PLAYER_CUEID_4,
    /* 0x05 */ PLAYER_CUEID_5,
    /* 0x06 */ PLAYER_CUEID_6,
    /* 0x07 */ PLAYER_CUEID_7,
    /* 0x08 */ PLAYER_CUEID_8,
    /* 0x09 */ PLAYER_CUEID_9,
    /* 0x0A */ PLAYER_CUEID_10,
    /* 0x0B */ PLAYER_CUEID_11,
    /* 0x0C */ PLAYER_CUEID_12,
    /* 0x0D */ PLAYER_CUEID_13,
    /* 0x0E */ PLAYER_CUEID_14,
    /* 0x0F */ PLAYER_CUEID_15,
    /* 0x10 */ PLAYER_CUEID_16,
    /* 0x11 */ PLAYER_CUEID_17,
    /* 0x12 */ PLAYER_CUEID_18,
    /* 0x13 */ PLAYER_CUEID_19,
    /* 0x14 */ PLAYER_CUEID_20,
    /* 0x15 */ PLAYER_CUEID_21,
    /* 0x16 */ PLAYER_CUEID_22,
    /* 0x17 */ PLAYER_CUEID_23,
    /* 0x18 */ PLAYER_CUEID_24,
    /* 0x19 */ PLAYER_CUEID_25,
    /* 0x1A */ PLAYER_CUEID_26,
    /* 0x1B */ PLAYER_CUEID_27,
    /* 0x1C */ PLAYER_CUEID_28,
    /* 0x1D */ PLAYER_CUEID_29,
    /* 0x1E */ PLAYER_CUEID_30,
    /* 0x1F */ PLAYER_CUEID_31,
    /* 0x20 */ PLAYER_CUEID_32,
    /* 0x21 */ PLAYER_CUEID_33,
    /* 0x22 */ PLAYER_CUEID_34,
    /* 0x23 */ PLAYER_CUEID_35,
    /* 0x24 */ PLAYER_CUEID_36,
    /* 0x25 */ PLAYER_CUEID_37,
    /* 0x26 */ PLAYER_CUEID_38,
    /* 0x27 */ PLAYER_CUEID_39,
    /* 0x28 */ PLAYER_CUEID_40,
    /* 0x29 */ PLAYER_CUEID_41,
    /* 0x2A */ PLAYER_CUEID_42,
    /* 0x2B */ PLAYER_CUEID_43,
    /* 0x2C */ PLAYER_CUEID_44,
    /* 0x2D */ PLAYER_CUEID_45,
    /* 0x2E */ PLAYER_CUEID_46,
    /* 0x2F */ PLAYER_CUEID_47,
    /* 0x30 */ PLAYER_CUEID_48,
    /* 0x31 */ PLAYER_CUEID_49,
    /* 0x32 */ PLAYER_CUEID_50,
    /* 0x33 */ PLAYER_CUEID_51,
    /* 0x34 */ PLAYER_CUEID_52,
    /* 0x35 */ PLAYER_CUEID_53,
    /* 0x36 */ PLAYER_CUEID_54,
    /* 0x37 */ PLAYER_CUEID_55,
    /* 0x38 */ PLAYER_CUEID_56,
    /* 0x39 */ PLAYER_CUEID_57,
    /* 0x3A */ PLAYER_CUEID_58,
    /* 0x3B */ PLAYER_CUEID_59,
    /* 0x3C */ PLAYER_CUEID_60,
    /* 0x3D */ PLAYER_CUEID_61,
    /* 0x3E */ PLAYER_CUEID_62,
    /* 0x3F */ PLAYER_CUEID_63,
    /* 0x40 */ PLAYER_CUEID_64,
    /* 0x41 */ PLAYER_CUEID_65,
    /* 0x42 */ PLAYER_CUEID_66,
    /* 0x43 */ PLAYER_CUEID_67,
    /* 0x44 */ PLAYER_CUEID_68,
    /* 0x45 */ PLAYER_CUEID_69,
    /* 0x46 */ PLAYER_CUEID_70,
    /* 0x47 */ PLAYER_CUEID_71,
    /* 0x48 */ PLAYER_CUEID_72,
    /* 0x49 */ PLAYER_CUEID_73,
    /* 0x4A */ PLAYER_CUEID_74,
    /* 0x4B */ PLAYER_CUEID_75,
    /* 0x4C */ PLAYER_CUEID_76,
    /* 0x4D */ PLAYER_CUEID_77,
    /* 0x4E */ PLAYER_CUEID_MAX
} PlayerCueId;

typedef enum PlayerLedgeClimbType {
    /* 0 */ PLAYER_LEDGE_CLIMB_NONE,
    /* 1 */ PLAYER_LEDGE_CLIMB_1,
    /* 2 */ PLAYER_LEDGE_CLIMB_2,
    /* 3 */ PLAYER_LEDGE_CLIMB_3,
    /* 4 */ PLAYER_LEDGE_CLIMB_4
} PlayerLedgeClimbType;

typedef enum PlayerStickDirection {
    /* -1 */ PLAYER_STICK_DIR_NONE = -1,
    /*  0 */ PLAYER_STICK_DIR_FORWARD,
    /*  1 */ PLAYER_STICK_DIR_LEFT,
    /*  2 */ PLAYER_STICK_DIR_BACKWARD,
    /*  3 */ PLAYER_STICK_DIR_RIGHT
} PlayerStickDirection;

typedef enum {
    /* 0 */ PLAYER_KNOCKBACK_NONE, // No knockback
    /* 1 */ PLAYER_KNOCKBACK_SMALL, // A small hop, remains standing up
    /* 2 */ PLAYER_KNOCKBACK_LARGE, // Sent flying in the air and lands laying down on the floor
    /* 3 */ PLAYER_KNOCKBACK_LARGE_SHOCK // Same as`PLAYER_KNOCKBACK_LARGE` with a shock effect
} PlayerKnockbackType;

typedef enum {
    /* 0 */ PLAYER_HIT_RESPONSE_NONE,
    /* 1 */ PLAYER_HIT_RESPONSE_KNOCKBACK_LARGE,
    /* 2 */ PLAYER_HIT_RESPONSE_KNOCKBACK_SMALL,
    /* 3 */ PLAYER_HIT_RESPONSE_ICE_TRAP,
    /* 4 */ PLAYER_HIT_RESPONSE_ELECTRIC_SHOCK
} PlayerDamageResponseType;

typedef struct PlayerAgeProperties {
    /* 0x00 */ f32 ceilingCheckHeight;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 translationScale;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 waterSurface;
    /* 0x2C */ f32 diveWaterSurface;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 wallCheckRadius;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ Vec3s unk_44;
    /* 0x4A */ Vec3s unk_4A[4];
    /* 0x62 */ Vec3s unk_62[4];
    /* 0x7A */ Vec3s unk_7A[2];
    /* 0x86 */ Vec3s unk_86[2];
    /* 0x92 */ u16 ageVoiceSfxOffset;
    /* 0x94 */ u16 ageMoveSfxOffset;
    /* 0x98 */ LinkAnimationHeader* chestOpenAnim;
    /* 0x9C */ LinkAnimationHeader* timeTravelStartAnim;
    /* 0xA0 */ LinkAnimationHeader* timeTravelEndAnim;
    /* 0xA4 */ LinkAnimationHeader* startClimb1Anim;
    /* 0xA8 */ LinkAnimationHeader* startClimb2Anim;
    /* 0xAC */ LinkAnimationHeader* verticalClimbAnim[4];
    /* 0xBC */ LinkAnimationHeader* horizontalClimbAnim[2];
    /* 0xC4 */ LinkAnimationHeader* endClimb1Anim[2];
    /* 0xCC */ LinkAnimationHeader* endClimb2Anim[2];
} PlayerAgeProperties; // size = 0xD4

typedef struct WeaponInfo {
    /* 0x00 */ s32 active;
    /* 0x04 */ Vec3f tip;
    /* 0x10 */ Vec3f base;
} WeaponInfo; // size = 0x1C

#define LEDGE_DIST_MAX 399.96002f

#define PLAYER_STATE1_EXITING_SCENE  (1 << 0)
#define PLAYER_STATE1_SWINGING_BOTTLE (1 << 1) // Bottle is swung; Bottle is active and can catch things
#define PLAYER_STATE1_END_HOOKSHOT_MOVE  (1 << 2)
#define PLAYER_STATE1_AIMING_FPS_ITEM  (1 << 3)
#define PLAYER_STATE1_HOSTILE_LOCK_ON (1 << 4) // Currently locked onto a hostile actor. Triggers a "battle" variant of many actions.
#define PLAYER_STATE1_INPUT_DISABLED  (1 << 5)
#define PLAYER_STATE1_TALKING (1 << 6) // Currently talking to an actor. This includes item exchanges.
#define PLAYER_STATE1_DEAD (1 << 7) // Player has died. Note that this gets set when the death cutscene has started, after landing from the air.
#define PLAYER_STATE1_START_CHANGING_HELD_ITEM (1 << 8) // Item change process has begun
#define PLAYER_STATE1_READY_TO_SHOOT (1 << 9)
#define PLAYER_STATE1_GETTING_ITEM  (1 << 10)
#define PLAYER_STATE1_CARRYING_ACTOR (1 << 11) // Currently carrying an actor
#define PLAYER_STATE1_CHARGING_SPIN_ATTACK (1 << 12) // Currently charing a spin attack (by holding down the B button)
#define PLAYER_STATE1_HANGING_FROM_LEDGE_SLIP  (1 << 13)
#define PLAYER_STATE1_CLIMBING_ONTO_LEDGE  (1 << 14)
#define PLAYER_STATE1_UNUSED_Z_TARGETING_FLAG  (1 << 15) // Either lock-on or parallel is active. This flag is never checked for and is practically unused.
#define PLAYER_STATE1_FRIENDLY_ACTOR_FOCUS (1 << 16) // Currently focusing on a friendly actor. Includes friendly lock-on, talking, and more. Usually does not include hostile actor lock-on, see `PLAYER_STATE1_HOSTILE_LOCK_ON`.
#define PLAYER_STATE1_PARALLEL (1 << 17) // "Parallel" mode, Z-Target without an actor lock-on
#define PLAYER_STATE1_JUMPING  (1 << 18)
#define PLAYER_STATE1_FREEFALLING  (1 << 19)
#define PLAYER_STATE1_IN_FIRST_PERSON_MODE  (1 << 20)
#define PLAYER_STATE1_CLIMBING  (1 << 21)
#define PLAYER_STATE1_22 (1 << 22)
#define PLAYER_STATE1_RIDING_HORSE  (1 << 23)
#define PLAYER_STATE1_AIMING_BOOMERANG  (1 << 24) // Currently using the boomerang. This includes all phases (aiming, throwing, and catching).
#define PLAYER_STATE1_AWAITING_THROWN_BOOMERANG  (1 << 25) // Boomerang has been thrown and is flying in the air
#define PLAYER_STATE1_TAKING_DAMAGE  (1 << 26)
#define PLAYER_STATE1_SWIMMING  (1 << 27)
#define PLAYER_STATE1_SKIP_OTHER_ACTORS_UPDATE  (1 << 28)
#define PLAYER_STATE1_IN_CUTSCENE  (1 << 29)
#define PLAYER_STATE1_LOCK_ON_FORCED_TO_RELEASE (1 << 30) // Lock-on was released automatically, for example by leaving the lock-on leash range
#define PLAYER_STATE1_FALLING_INTO_GROTTO_OR_VOID  (1 << 31)

#define PLAYER_STATE2_CAN_GRAB_PUSH_PULL_WALL  (1 << 0)
#define PLAYER_STATE2_CAN_ACCEPT_TALK_OFFER (1 << 1) // Can accept a talk offer. "Speak" or "Check" is shown on the A button.
#define PLAYER_STATE2_CAN_CLIMB_PUSH_PULL_WALL (1 << 2)
#define PLAYER_STATE2_MAKING_REACTABLE_NOISE (1 << 3)
#define PLAYER_STATE2_MOVING_PUSH_PULL_WALL  (1 << 4)
#define PLAYER_STATE2_DISABLE_MOVE_ROTATION_WHILE_Z_TARGETING (1 << 5)
#define PLAYER_STATE2_ALWAYS_DISABLE_MOVE_ROTATION  (1 << 6)
#define PLAYER_STATE2_RESTRAINED_BY_ENEMY  (1 << 7)
#define PLAYER_STATE2_ENABLE_PUSH_PULL_CAM  (1 << 8)
#define PLAYER_STATE2_FORCE_SAND_FLOOR_SOUND (1 << 9) // Forces sand footstep sounds regardless of current floor type
#define PLAYER_STATE2_DIVING  (1 << 10)
#define PLAYER_STATE2_ENABLE_DIVE_CAMERA_AND_TIMER  (1 << 11)
#define PLAYER_STATE2_IDLE_WHILE_CLIMBING  (1 << 12)
#define PLAYER_STATE2_LOCK_ON_WITH_SWITCH (1 << 13) // Actor lock-on is active, specifically with Switch Targeting. Hold Targeting checks the state of the Z button instead of this flag.
#define PLAYER_STATE2_FROZEN_IN_ICE  (1 << 14)
#define PLAYER_STATE2_PAUSE_MOST_UPDATING  (1 << 15)
#define PLAYER_STATE2_DO_ACTION_ENTER (1 << 16) // Sets the "Enter On A" DoAction
#define PLAYER_STATE2_RELEASING_SPIN_ATTACK  (1 << 17)
#define PLAYER_STATE2_CRAWLING (1 << 18) // Crawling through a crawlspace
#define PLAYER_STATE2_BACKFLIPPING_OR_SIDEHOPPING  (1 << 19)
#define PLAYER_STATE2_NAVI_ACTIVE (1 << 20) // Navi is visible and active. Could be hovering idle near Link or hovering over other actors.
#define PLAYER_STATE2_NAVI_REQUESTING_TALK  (1 << 21)
#define PLAYER_STATE2_CAN_DISMOUNT_HORSE  (1 << 22)
#define PLAYER_STATE2_NEAR_OCARINA_ACTOR  (1 << 23)
#define PLAYER_STATE2_ATTEMPT_PLAY_OCARINA_FOR_ACTOR  (1 << 24)
#define PLAYER_STATE2_PLAYING_OCARINA_FOR_ACTOR  (1 << 25)
#define PLAYER_STATE2_ENABLE_REFLECTION  (1 << 26)
#define PLAYER_STATE2_PLAYING_OCARINA_GENERAL  (1 << 27)
#define PLAYER_STATE2_IDLE_FIDGET (1 << 28) // Playing a fidget idle animation (under typical circumstances, see `Player_ChooseNextIdleAnim` for more info)
#define PLAYER_STATE2_DISABLE_DRAW  (1 << 29)
#define PLAYER_STATE2_ENABLE_FORWARD_SLIDE_FROM_ATTACK  (1 << 30)
#define PLAYER_STATE2_FORCE_VOID_OUT  (1 << 31)

#define PLAYER_STATE3_IGNORE_CEILING_FLOOR_AND_WATER  (1 << 0)
#define PLAYER_STATE3_MIDAIR  (1 << 1)
#define PLAYER_STATE3_PAUSE_ACTION_FUNC  (1 << 2)
#define PLAYER_STATE3_ENDING_MELEE_ATTACK  (1 << 3)
#define PLAYER_STATE3_CHECKING_FLOOR_AND_WATER_COLLISION  (1 << 4)
#define PLAYER_STATE3_FORCE_PULL_OCARINA  (1 << 5)
#define PLAYER_STATE3_RESTORE_NAYRUS_LOVE (1 << 6) // Set by ocarina effects actors when destroyed to signal Nayru's Love may be restored (see `ACTOROVL_ALLOC_ABSOLUTE`)
#define PLAYER_STATE3_FLYING_WITH_HOOKSHOT (1 << 7) // Flying in the air with the hookshot as it pulls Player toward its destination

#define PLAYER_ALLOC_GI_MIN 0x2880 // title card maximum file size

typedef void (*PlayerActionFunc)(struct Player*, struct PlayState*);
typedef s32 (*UpperActionFunc)(struct Player*, struct PlayState*);
typedef void (*AfterPutAwayFunc)(struct PlayState*, struct Player*);

#define UNK6AE_ROT_FOCUS_X (1 << 0)
#define UNK6AE_ROT_FOCUS_Y (1 << 1)
#define UNK6AE_ROT_FOCUS_Z (1 << 2)
#define UNK6AE_ROT_HEAD_X (1 << 3)
#define UNK6AE_ROT_HEAD_Y (1 << 4)
#define UNK6AE_ROT_HEAD_Z (1 << 5)
#define UNK6AE_ROT_UPPER_X (1 << 6)
#define UNK6AE_ROT_UPPER_Y (1 << 7)
#define UNK6AE_ROT_UPPER_Z (1 << 8)

typedef struct Player {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ s8 currentTunic; // current tunic from `PlayerTunic`
    /* 0x014D */ s8 currentSwordItemId;
    /* 0x014E */ s8 currentShield; // current shield from `PlayerShield`
    /* 0x014F */ s8 currentBoots; // current boots from `PlayerBoots`
    /* 0x0150 */ s8 heldItemButton; // Button index for the item currently used
    /* 0x0151 */ s8 heldItemAction; // Item action for the item currently used
    /* 0x0152 */ u8 heldItemId; // Item id for the item currently used
    /* 0x0153 */ s8 prevBoots; // previous boots from `PlayerBoots`
    /* 0x0154 */ s8 itemAction; // the difference between this and heldItemAction is unclear
    /* 0x0155 */ char unk_155[0x003];
    /* 0x0158 */ u8 modelGroup;
    /* 0x0159 */ u8 nextModelGroup;
    /* 0x015A */ s8 itemChangeType;
    /* 0x015B */ u8 modelAnimType;
    /* 0x015C */ u8 leftHandType;
    /* 0x015D */ u8 rightHandType;
    /* 0x015E */ u8 sheathType;
    /* 0x015F */ u8 currentMask; // current mask equipped from `PlayerMask`
    /* 0x0160 */ Gfx** rightHandDLists;
    /* 0x0164 */ Gfx** leftHandDLists;
    /* 0x0168 */ Gfx** sheathDLists;
    /* 0x016C */ Gfx** waistDLists;
    /* 0x0170 */ u8 giObjectLoading;
    /* 0x0174 */ DmaRequest giObjectDmaRequest;
    /* 0x0194 */ OSMesgQueue giObjectLoadQueue;
    /* 0x01AC */ OSMesg giObjectLoadMsg;
    /* 0x01B0 */ void* giObjectSegment; // also used for title card textures
    /* 0x01B4 */ SkelAnime skelAnime;
    /* 0x01F8 */ Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0288 */ Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0318 */ Vec3s blendTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x03A8 */ FaceChange faceChange;
    /* 0x03AC */ Actor* heldActor;
    /* 0x03B0 */ Vec3f leftHandPos;
    /* 0x03BC */ Vec3s leftHandRot;
    /* 0x03C4 */ Actor* pushPullActor;
    /* 0x03C8 */ Vec3f hookshotHeldPos;
    /* 0x03D4 */ char unk_3D4[0x058];
    /* 0x042C */ s8 doorType;
    /* 0x042D */ s8 doorDirection;
    /* 0x042E */ s16 doorTimer;
    /* 0x0430 */ Actor* doorActor;
    /* 0x0434 */ s8 getItemId;
    /* 0x0436 */ u16 getItemDirection;
    /* 0x0438 */ Actor* interactRangeActor;
    /* 0x043C */ s8 mountSide;
    /* 0x043D */ char unk_43D[0x003];
    /* 0x0440 */ Actor* rideActor;
    /* 0x0444 */ u8 csAction;
    /* 0x0445 */ u8 prevCsAction;
    /* 0x0446 */ u8 cueId;
    /* 0x0447 */ u8 unk_447;
    /* 0x0448 */ Actor* csActor; // Actor involved in a `csAction`. Typically the actor that invoked the cutscene.
    /* 0x044C */ char unk_44C[0x004];
    /* 0x0450 */ Vec3f csStartPos;
    /* 0x045C */ Vec3f csEndPos;
    /* 0x0468 */ char unk_468[0x002];
    /* 0x046A */ union {
        s16 haltActorsDuringCsAction; // If true, halt actors belonging to certain categories during a `csAction`
        s16 slidingDoorBgCamIndex; // `BgCamIndex` used during a sliding door cutscene
    } cv; // "Cutscene Variable": context dependent variable that has different meanings depending on what function is called
    /* 0x046C */ s16 subCamId;
    /* 0x046E */ char unk_46E[0x02A];
    /* 0x0498 */ ColliderCylinder cylinder;
    /* 0x04E4 */ ColliderQuad meleeWeaponQuads[2];
    /* 0x05E4 */ ColliderQuad shieldQuad;
    /* 0x0664 */ Actor* focusActor; // Actor that Player and the camera are looking at; Used for lock-on, talking, and more
    /* 0x0668 */ char unk_668[0x004];
    /* 0x066C */ s32 zTargetActiveTimer; // Non-zero values indicate Z-Targeting should update; Values under 5 indicate lock-on is releasing
    /* 0x0670 */ s32 meleeWeaponEffectIndex;
    /* 0x0674 */ PlayerActionFunc actionFunc;
    /* 0x0678 */ PlayerAgeProperties* ageProperties;
    /* 0x067C */ u32 stateFlags1;
    /* 0x0680 */ u32 stateFlags2;
    /* 0x0684 */ Actor* autoLockOnActor; // Actor that is locked onto automatically without player input; see `Player_SetAutoLockOnActor`
    /* 0x0688 */ Actor* boomerangActor;
    /* 0x068C */ Actor* naviActor;
    /* 0x0690 */ s16 naviTextId;
    /* 0x0692 */ u8 stateFlags3;
    /* 0x0693 */ s8 exchangeItemId;
    /* 0x0694 */ Actor* talkActor; // Actor offering to talk, or currently talking to, depending on context
    /* 0x0698 */ f32 talkActorDistance; // xz distance away from `talkActor`
    /* 0x069C */ char unk_69C[0x004];
    /* 0x06A0 */ f32 stoneOfAgonyRumbleTimer;
    /* 0x06A4 */ f32 closestSecretDistSq;
    /* 0x06A8 */ Actor* ocarinaActor;
    /* 0x06AC */ s8 idleType;
    /* 0x06AD */ u8 attentionMode;
    /* 0x06AE */ u16 unk_6AE_rotFlags; // See `UNK6AE_ROT_` macros. If its flag isn't set, a rot steps to 0.
    /* 0x06B0 */ s16 upperLimbYawSecondary;
    /* 0x06B2 */ char unk_6B4[0x004];
    /* 0x06B6 */ Vec3s headLimbRot;
    /* 0x06BC */ Vec3s upperLimbRot;
    /* 0x06C2 */ s16 shapePitchOffset;
    /* 0x06C4 */ f32 shapeOffsetY;
    /* 0x06C8 */ SkelAnime upperSkelAnime;
    /* 0x070C */ Vec3s upperJointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x079C */ Vec3s upperMorphTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x082C */ UpperActionFunc upperActionFunc;
    /* 0x0830 */ f32 upperAnimInterpWeight;
    /* 0x0834 */ s16 fpsItemTimer;
    /* 0x0836 */ s8 fpsItemShootState;
    /* 0x0837 */ u8 putAwayCooldownTimer;
    /* 0x0838 */ f32 speedXZ; // Controls horizontal speed, used for `actor.speed`. Current or target value depending on context.
    /* 0x083C */ s16 yaw; // General yaw value, used both for world and shape rotation. Current or target value depending on context.
    /* 0x083E */ s16 parallelYaw; // yaw in "parallel" mode, Z-Target without an actor lock-on
    /* 0x0840 */ u16 underwaterTimer;
    /* 0x0842 */ s8 meleeWeaponAnimation;
    /* 0x0843 */ s8 meleeWeaponState;
    /* 0x0844 */ s8 comboTimer;
    /* 0x0845 */ u8 slashCounter;
    /* 0x0846 */ u8 controlStickDataIndex; // cycles between 0 - 3. Used to index `controlStickSpinAngles` and `controlStickDirections`
    /* 0x0847 */ s8 controlStickSpinAngles[4]; // Stores a modified version of the control stick angle for the last 4 frames. Used for checking spins.
    /* 0x084B */ s8 controlStickDirections[4]; // Stores the control stick direction (relative to shape yaw) for the last 4 frames. See `PlayerStickDirection`.

    /* 0x084F */ union {
        s8 actionVar1;
        s8 facingUpSlope; // Player_SlipOnSlope: facing uphill when sliding on a slope
        s8 bottleCatchType; // Player_SwingBottle: entry type for `sBottleCatchInfo`, corresponds to actor caught in a bottle
    } av1; // "Action Variable 1": context dependent variable that has different meanings depending on what action is currently running

    /* 0x0850 */ union {
        s16 actionVar2;
        s16 fallDamageStunTimer; // Player_StandingStill: Prevents any movement and shakes model up and down quickly to indicate fall damage stun
        s16 bonked; // Player_Rolling: set to true after bonking into a wall or an actor
        s16 startedTextbox; // Player_SwingBottle: set to true when the textbox is started
        s16 inWater; // Player_SwingBottle: true if a bottle is swung in water. Used to determine which bottle swing animation to use.
    } av2; // "Action Variable 2": context dependent variable that has different meanings depending on what action is currently running

    /* 0x0854 */ f32 unk_854;
    /* 0x0858 */ f32 unk_858;
    /* 0x085C */ f32 unk_85C; // stick length among other things
    /* 0x0860 */ s16 unk_860; // stick flame timer among other things
    /* 0x0862 */ s8 unk_862; // get item draw ID + 1
    /* 0x0864 */ f32 unk_864;
    /* 0x0868 */ f32 unk_868;
    /* 0x086C */ f32 unk_86C;
    /* 0x0870 */ f32 unk_870;
    /* 0x0874 */ f32 unk_874;
    /* 0x0878 */ f32 unk_878;
    /* 0x087C */ s16 unk_87C;
    /* 0x087E */ s16 turnRate; // Amount angle is changed every frame when turning in place
    /* 0x0880 */ f32 unk_880;
    /* 0x0884 */ f32 yDistToLedge; // y distance to ground above an interact wall. LEDGE_DIST_MAX if no ground is found
    /* 0x0888 */ f32 distToInteractWall; // xyz distance to the interact wall
    /* 0x088C */ u8 ledgeClimbType;
    /* 0x088D */ u8 ledgeClimbDelayTimer;
    /* 0x088E */ u8 textboxBtnCooldownTimer; // Prevents usage of A/B/C-up when counting down
    /* 0x088F */ u8 damageFlickerAnimCounter; // Used to flicker Link after taking damage
    /* 0x0890 */ u8 unk_890;
    /* 0x0891 */ u8 bodyShockTimer;
    /* 0x0892 */ u8 unk_892;
    /* 0x0893 */ u8 hoverBootsTimer;
    /* 0x0894 */ s16 fallStartHeight; // last truncated Y position before falling
    /* 0x0896 */ s16 fallDistance; // truncated Y distance the player has fallen so far (positive is down)
    /* 0x0898 */ s16 floorPitch; // angle of the floor slope in the direction of current world yaw (positive for ascending slope)
    /* 0x089A */ s16 floorPitchAlt; // the calculation for this value is bugged and doesn't represent anything meaningful
    /* 0x089C */ s16 unk_89C;
    /* 0x089E */ u16 floorSfxOffset;
    /* 0x08A0 */ u8 knockbackDamage;
    /* 0x08A1 */ u8 knockbackType;
    /* 0x08A2 */ s16 knockbackRot;
    /* 0x08A4 */ f32 knockbackSpeed;
    /* 0x08A8 */ f32 knockbackYVelocity;
    /* 0x08AC */ f32 pushedSpeed; // Pushing player, examples include water currents, floor conveyors, climbing sloped surfaces
    /* 0x08B0 */ s16 pushedYaw; // Yaw direction of player being pushed
    /* 0x08B4 */ WeaponInfo meleeWeaponInfo[3];
    /* 0x0908 */ Vec3f bodyPartsPos[PLAYER_BODYPART_MAX];
    /* 0x09E0 */ MtxF mf_9E0;
    /* 0x0A20 */ MtxF shieldMf;
    /* 0x0A60 */ u8 bodyIsBurning;
    /* 0x0A61 */ u8 bodyFlameTimers[PLAYER_BODYPART_MAX]; // one flame per body part
    /* 0x0A73 */ u8 unk_A73;
    /* 0x0A74 */ AfterPutAwayFunc afterPutAwayFunc; // See `Player_SetupWaitForPutAway` and `Player_Action_WaitForPutAway`
    /* 0x0A78 */ s8 invincibilityTimer; // prevents damage when nonzero. Positive values are intangibility, negative are invulnerability
    /* 0x0A79 */ u8 floorTypeTimer; // counts up every frame the current floor type is the same as the last frame
    /* 0x0A7A */ u8 floorProperty;
    /* 0x0A7B */ u8 prevFloorType;
    /* 0x0A7C */ f32 prevControlStickMagnitude;
    /* 0x0A80 */ s16 prevControlStickAngle;
    /* 0x0A82 */ u16 prevFloorSfxOffset;
    /* 0x0A84 */ s16 unk_A84;
    /* 0x0A86 */ s8 unk_A86;
    /* 0x0A87 */ u8 unk_A87;
    /* 0x0A88 */ Vec3f unk_A88; // previous body part 0 position
} Player; // size = 0xA94

// z_player_lib.c
void Player_SetBootData(struct PlayState* play, Player* this);
int Player_InBlockingCsMode(struct PlayState* play, Player* this);
int Player_InCsMode(struct PlayState* play);
s32 Player_CheckHostileLockOn(Player* this);
int Player_IsChildWithHylianShield(Player* this);
s32 Player_ActionToModelGroup(Player* this, s32 itemAction);
void Player_SetModelsForHoldingShield(Player* this);
void Player_SetModels(Player* this, s32 modelGroup);
void Player_SetModelGroup(Player* this, s32 modelGroup);
void func_8008EC70(Player* this);
void Player_SetEquipmentData(struct PlayState* play, Player* this);
void Player_UpdateBottleHeld(struct PlayState* play, Player* this, s32 item, s32 itemAction);
void Player_ReleaseLockOn(Player* this);
void Player_ClearZTargeting(Player* this);
void Player_SetAutoLockOnActor(struct PlayState* play, Actor* actor);
s32 func_8008EF44(struct PlayState* play, s32 ammo);
int Player_IsBurningStickInRange(struct PlayState* play, Vec3f* pos, f32 xzRange, f32 yRange);
s32 Player_GetStrength(void);
u8 Player_GetMask(struct PlayState* play);
Player* Player_UnsetMask(struct PlayState* play);
s32 Player_HasMirrorShieldEquipped(struct PlayState* play);
int Player_HasMirrorShieldSetToDraw(struct PlayState* play);
s32 Player_ActionToMagicSpell(Player* this, s32 itemAction);
int Player_HoldsHookshot(Player* this);
int func_8008F128(Player* this);
s32 Player_ActionToMeleeWeapon(s32 itemAction);
s32 Player_GetMeleeWeaponHeld(Player* this);
s32 Player_HoldsTwoHandedWeapon(Player* this);
int Player_HoldsBrokenKnife(Player* this);
s32 Player_ActionToBottle(Player* this, s32 itemAction);
s32 Player_GetBottleHeld(Player* this);
s32 Player_ActionToExplosive(Player* this, s32 itemAction);
s32 Player_GetExplosiveHeld(Player* this);
s32 func_8008F2BC(Player* this, s32 itemAction);
s32 Player_GetEnvironmentalHazard(struct PlayState* play);
void Player_DrawImpl(struct PlayState* play, void** skeleton, Vec3s* jointTable, s32 dListCount, s32 lod, s32 tunic,
                     s32 boots, s32 face, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw,
                     void* data);
s32 Player_OverrideLimbDrawGameplayCommon(struct PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                          void* thisx);
s32 Player_OverrideLimbDrawGameplayDefault(struct PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                           void* thisx);
s32 Player_OverrideLimbDrawGameplayFirstPerson(struct PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos,
                                               Vec3s* rot, void* thisx);
s32 Player_OverrideLimbDrawGameplayCrawling(struct PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                            void* thisx);
u8 func_80090480(struct PlayState* play, ColliderQuad* collider, WeaponInfo* weaponInfo, Vec3f* newTip, Vec3f* newBase);
void Player_DrawGetItem(struct PlayState* play, Player* this);
void Player_PostLimbDrawGameplay(struct PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx);
u32 Player_InitPauseDrawData(struct PlayState* play, u8* segment, SkelAnime* skelAnime);
void Player_DrawPause(struct PlayState* play, u8* segment, SkelAnime* skelAnime, Vec3f* pos, Vec3s* rot, f32 scale,
                      s32 sword, s32 tunic, s32 shield, s32 boots);

// z_player_lib.c
extern FlexSkeletonHeader* gPlayerSkelHeaders[2];
extern u8 gPlayerModelTypes[PLAYER_MODELGROUP_MAX][PLAYER_MODELGROUPENTRY_MAX];
extern Gfx* gPlayerLeftHandBgsDLs[];
extern Gfx* gPlayerLeftHandOpenDLs[];
extern Gfx* gPlayerLeftHandClosedDLs[];
extern Gfx* gPlayerLeftHandBoomerangDLs[];
extern Gfx gCullBackDList[];
extern Gfx gCullFrontDList[];

// object_table.c
extern s16 gLinkObjectIds[2];

#endif
