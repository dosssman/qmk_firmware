#include QMK_KEYBOARD_H


typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

user_config_t user_config;

#define LAYER_0 0 // Base layer 0 for general usage
#define LAYER_1 1 // Base layer 1 for general usage
#define LAYER_2 2 // Base layer 2 for general usage
#define LAYER_3 3 // PAT || RTS focused base layer 0
#define LAYER_4 4 // PAT || RTS focused layer 1
#define LAYER_5 5 // PAT || RTS focused layer 2

#define LAYERS_EFFECT_SPEEDS ((uint8_t[]){ 64, 148, 255})

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Set default layer, if enabled
  if (user_config.rgb_layer_change) {
    rgblight_enable();
    rgblight_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGB_MATRIX_BREATHING);
    rgb_matrix_set_speed_noeeprom(LAYERS_EFFECT_SPEEDS[0]);
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    const uint32_t curr_layer = get_highest_layer(state);

    switch (curr_layer) {
    case LAYER_0 ... LAYER_2:
      if (user_config.rgb_layer_change) {
        rgblight_sethsv_noeeprom(HSV_CYAN);
        // rgb_matrix_set_speed_noeeprom(LAYERS_EFFECT_SPEEDS[curr_layer % 3]);
      };
      break;
    case LAYER_3 ... LAYER_5:
      if (user_config.rgb_layer_change) {
        rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
        // rgb_matrix_set_speed_noeeprom(LAYERS_EFFECT_SPEEDS[curr_layer % 3]);
      }
      break;
    default: //  for any other layers, or the default layer
      if (user_config.rgb_layer_change) {
        rgblight_sethsv_noeeprom(HSV_CYAN);
        rgblight_mode_noeeprom(RGB_MATRIX_BREATHING);
        // rgb_matrix_set_speed_noeeprom(LAYERS_EFFECT_SPEEDS[0]); // Maintain same effect speed across layer groups
      }
      break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT: // For any of the RGB codes (see quantum_keycodes.h, L400 for reference)
        if (record->event.pressed) { //This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
            if (user_config.rgb_layer_change) {        // only if this is enabled
                user_config.rgb_layer_change = false;  // disable it, and
                eeconfig_update_user(user_config.raw); // write the setings to EEPROM
            }
        }
        return true; break;
    default:
      return true; // Process all other keycodes normally
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.rgb_layer_change = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv(HSV_CYAN);  // Set it to CYAN by default
  rgblight_mode(RGB_MATRIX_BREATHING); // set to solid by default
  rgb_matrix_set_speed(LAYERS_EFFECT_SPEEDS[0]);
}
