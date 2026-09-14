# embed_beetroot_hw_2_8_stm1

STM32CubeMX/CMake firmware project for the STM32F411CEU6 (Blackpill-style board).

The LED on PC13 blinks while the pushbutton (PA5) is pressed.

## Hardware

- MCU: STM32F411CEU6 (UFQFPN48)
- PC13 — `LED`, push-pull output (internal LED)
- PA5 — `BTN`, input with pull-up

## Prerequisites

- STM32CubeIDE or STM32CubeCLT (tested with STM32CubeCLT 1.22.0)

```sh
$ cmake --version
cmake version 4.3.1

$ ninja --version
1.13.2

$ STM32_Programmer_CLI --version
STM32CubeProgrammer version: 2.23.0

$ arm-none-eabi-gcc --version
arm-none-eabi-gcc (GNU Tools for STM32 14.3.rel1.20251027-0700) 14.3.1 20250623
```

## Build

```sh
cmake --preset Debug
cmake --build --preset Debug
```

Substitute `Release` for `Debug` above for a release build.

## Flash

Connect the board using an ST-Link, then run:

```sh
STM32_Programmer_CLI -c port=SWD -d build/Debug/embed_beetroot_hw_2_8_stm1.elf -v -s
```
