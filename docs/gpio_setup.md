#Introduction

The STM32G4 Series of MCU, much like most other MCUs I believe allow for access to the GPIO ports. To this end, I think that the most important thing I've learned is how to read the datasheet/reference manual.
I've worked with different microcontrollers before so it's not the first time I'd read a datasheet or a reference manual but it was interesting for me to see how the data was laid out on STM.

The first things first, I want to do this on bare metal, hence the name so for my first act, I looked at the GPIO section of the Reference Manual.
I knew that I wanted to blink an LED on PA5 (portA pin 5), it wasn't until I had done that, that I decided to also include PA1.
On the nucleoboard that I have PA 5 is connected to an onboard LED so connecting to it should have been no problem.
You can see below the relevant registers I'd found while scouring the reference manual.

In my code, I take an approach on explaining where I got my information from, it was very much a trial and error approach.
The important thing to not is that Chapter 9 is not the only chapter I had a look at. It turned out that the memory map was an equally important section.
I got stumped by the Address offset. Once I crossed that bridge, I had to take a look at bit masking, which is the main way that I interacted with the registers.
