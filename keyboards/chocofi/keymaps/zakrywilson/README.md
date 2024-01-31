# chocofi

## Default instructions

Make example for this keyboard (after setting up your build environment):

    make chocofi:default

Flashing example for this keyboard:

    make chocofi:default:flash

## Flashing with `qmk`

### Pro Micros

    qmk flash -kb chocofi -km zakrywilson -bl dfu

### RP2040s

    qmk compile -c -kb chocofi -km zakrywilson -e CONVERT_TO=bit_c_pro

    qmk flash -c -kb chocofi -km zakrywilson -e CONVERT_TO=bit_c_pro

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

