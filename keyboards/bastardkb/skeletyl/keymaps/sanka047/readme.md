## Building the firmware

| Shield Version  | default                                                         | via                                                         |
| --------------- | --------------------------------------------------------------- | ----------------------------------------------------------- |
| v1 (Elite-C)    | `qmk compile -kb bastardkb/skeletyl/v1/elitec -km default`      | `qmk compile -kb bastardkb/skeletyl/v1/elitec -km via`      |
| v2 (Elite-C)    | `qmk compile -kb bastardkb/skeletyl/v2/elitec -km default`      | `qmk compile -kb bastardkb/skeletyl/v2/elitec -km via`      |
| v2 (Splinky v2) | `qmk compile -kb bastardkb/skeletyl/v2/splinky_2 -km default`   | `qmk compile -kb bastardkb/skeletyl/v2/splinky_2 -km via`   |
| v2 (Splinky v3) | `qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km default`   | `qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km via`   |
| v2 (STeMCell)   | `qmk compile -kb bastardkb/skeletyl/v2/stemcell -km default`    | `qmk compile -kb bastardkb/skeletyl/v2/stemcell -km via`    |

Currently, the hardware for my build requires:
```zsh
qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km sanka047
# OR (if already set values in qmk config)
qmk compile
```

Then, flash the keyboard. For EEPROM handedness:
```zsh
qmk flash -kb bastardkb/skeletyl/v2/splinky_3 -km sanka047 -bl uf2-split-left
qmk flash -kb bastardkb/skeletyl/v2/splinky_3 -km sanka047 -bl uf2-split-right
# OR (if already set values in qmk config)
qmk flash -bl uf2-split-left
qmk flash -bl uf2-split-right
```
NOTE: The splinky requires the reset button to be tapped **TWICE** (not just once).
