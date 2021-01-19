#pragma once
#ifndef COMBO_COUNT
#define COMBO_COUNT 4
#endif
enum combos {
    TK__LS_CB,
    KAPSLOCK,
    SFT_CB,
    CTL_CB,
};

const uint16_t PROGMEM tk_ls[] = {KC_O, KC_COMM, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM kapslock[] = {KC_COMM, KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM sftcb[] = {KC_O, KC_COMM, KC_S, COMBO_END};
const uint16_t PROGMEM ctlcb[] = {KC_O, KC_COMM, KC_N, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    [TK__LS_CB] = COMBO_ACTION(tk_ls),
    [KAPSLOCK] = COMBO_ACTION(kapslock),
    [SFT_CB] = COMBO_ACTION(sftcb),
    [CTL_CB] = COMBO_ACTION(ctlcb),
};

static bool kpa_active = false;

void capOn(void) {
    if (kpa_active) {
        return;
    }
    kpa_active = true;
    tap_code(KC_CAPS);
}

void capOff(void) {
    if (!kpa_active) {
        return;
    }
    kpa_active = false;
    tap_code(KC_CAPS);
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) {
        return;
    }
    switch(combo_index) {
    case TK__LS_CB:
        capOff();
        break;
    case KAPSLOCK:
        capOn();
        break;
    case SFT_CB:
        capOff();
        set_oneshot_mods(MOD_BIT(KC_LSFT));
        break;
    case CTL_CB:
        capOff();
        set_oneshot_mods(MOD_BIT(KC_LCTL));
        break;
    }
}
