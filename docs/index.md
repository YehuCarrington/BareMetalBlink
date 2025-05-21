# BareMetalBlink Documentation

Welcome to the documentation for the **BareMetalBlink** project, a minimal embedded C setup targeting STM32G4xx microcontrollers.

This documentation includes information on system clock setup, GPIO configuration, memory mapping, and relevant peripheral registers.

## Table of Contents

- [Clock Configuration](clock_config.md)  
  Overview of the STM32G4xx clock sources and how to configure them after reset.

- [GPIO Setup](gpio_setup.md)  
  Steps for enabling and configuring GPIO peripherals via RCC and GPIO registers.

- [AHB2ENR Register Reference](img/HB2ENR_Doc.png)  
  Snapshot of the RCC AHB2 peripheral clock enable register used for enabling GPIOs.

---

Refer to the source files in `/Src` and `/Drivers` for implementation details and CMSIS support.
