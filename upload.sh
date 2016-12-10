#!/usr/bin/env bash

set -e

cd keyboard/atreus

make upload \
    KEYMAP=walrus_programmer_dvorak \
    USB=/dev/cu.usbmodem1411 \
    MOUSEKEY_ENABLE=yes
