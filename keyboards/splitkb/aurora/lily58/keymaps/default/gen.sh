#!/bin/bash

set -eu

qmk json2c keymap_json > keymap.c
cat init_stuff_c >> keymap.c
#qmk flash -e CONVERT_TO=liatris -kb splitkb/aurora/lily58/rev1 -km default
