# Stomp

[Stomp](https://github.com/mvmorin/stomp), a ProMicro compatible split keyboard.

- Hardware Supported: RP2040 Pro Micro footprint controllers (e.g. SparkFun Pro Micro RP2040, Elite-Pi)

Build example, after installing [qmk cli](https://docs.qmk.fm/cli)

    qmk compile -kb mvmorin/stomp -km default

Flashing example for this keyboard:

    qmk flash -kb mvmorin/stomp -km default

## Bootloader

This board uses an RP2040 Pro Micro footprint controller (UF2 bootloader). Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
- **Physical reset**: Double-tap the RESET button, or hold the BOOTSEL button while plugging in the keyboard. The board mounts as a `RPI-RP2` USB drive; copy the `.uf2` firmware onto it to flash
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## How to:

From the root of the QMK repository, build the keymap:

```bash
qmk compile -kb mvmorin/stomp -km nils
```

This should produce a UF2 file:

```text
.build/mvmorin_stomp_nils.uf2
```

To flash the controller, put the RP2040 into bootloader mode:

1. Unplug the keyboard.
2. Hold the `BOOT` button.
3. Plug the keyboard back in while still holding `BOOT`.
4. Release `BOOT`.

The board should appear as a small removable device labelled `RPI-RP2`.

Check which device it is:

```bash
lsblk -o NAME,SIZE,FSTYPE,LABEL,MOUNTPOINTS,MODEL
```

Example:

```text
sdb           128M                            RP2
└─sdb1        128M vfat   RPI-RP2
```

Verify the filesystem if needed:

```bash
lsblk -f /dev/sdb
```

Mount it:

```bash
sudo mkdir -p /mnt/rpi-rp2
sudo mount /dev/sdb1 /mnt/rpi-rp2
```

Copy the firmware:

```bash
sudo cp .build/mvmorin_stomp_nils.uf2 /mnt/rpi-rp2/
sync
```

After the copy finishes, the keyboard should reboot into the new firmware.

Always confirm the device name with `lsblk` before mounting or copying. In the example above it is `/dev/sdb1`, but it may be different on another machine.
