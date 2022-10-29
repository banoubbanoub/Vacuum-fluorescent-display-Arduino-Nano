# Vacuum-fluorescent-display-Arduino-Nano
I did salvage this VFD from an old cassette to be used in Arduino Nano project, Arduino Nano to control the sound processors throw I2C and to control LV2300 PLL radio tuner and to control SN75518 shift register to drive the FVD

this VFD it has 12 grid and 14 Segments

I did use just one SN 75518 shift register to control segments and grids

the same pins used for the 14 segments it used for icons
The SN65518 and SN75518 are monolithic

BIDFET† integrated circuits designed to drive a

dot matrix or segmented vacuum fluorescent

display.
First i did create DisplayData.h to contain all the data for the 14 segments and icons and grids data, in the display that been used in this project.

Second Display.h to display numbers and char and icons
I did build a library called shift Register bus to shift out 32 bit for SN75518 shift register to control the VFD in this project
