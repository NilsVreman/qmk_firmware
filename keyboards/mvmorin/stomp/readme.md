# Stomp

[Stomp](https://github.com/mvmorin/stomp), a ProMicro compatible split keyboard.

* Hardware Supported: RP2040 Pro Micro footprint controllers (e.g. SparkFun Pro Micro RP2040, Elite-Pi)

Build example, after installing [qmk cli](https://docs.qmk.fm/cli)

    qmk compile -kb mvmorin/stomp -km default

Flashing example for this keyboard:

    qmk flash -kb mvmorin/stomp -km default

## Bootloader

This board uses an RP2040 Pro Micro footprint controller (UF2 bootloader). Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset**: Double-tap the RESET button, or hold the BOOTSEL button while plugging in the keyboard. The board mounts as a `RPI-RP2` USB drive; copy the `.uf2` firmware onto it to flash
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
