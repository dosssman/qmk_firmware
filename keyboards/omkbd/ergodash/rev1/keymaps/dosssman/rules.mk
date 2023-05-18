# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
# BOOTLOADER = caterina
BOOTLOADER = atmel-dfu

BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes 
AUDIO_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

SPLIT_KEYBOARD = yes