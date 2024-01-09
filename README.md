# Vacuum-fluorescent-display-Arduino-Nano
I did salvage this VFD from an old cassette to be used in the Arduino Nano project, Arduino Nano to control the sound processors through I2C and to LV2300 PLL radio tuner, and to control SN75518 shift register to drive the FVD

this VFD has 12 grids and 14 Segments

I did use just one SN 75518 shift register to control segments and grids

the same pins used for the 14 segments it used for icons
The SN65518 and SN75518 are monolithic

BIDFET† integrated circuits are designed to drive a

dot matrix or segmented vacuum fluorescent

display.
First, I created DisplayData.h to contain all the data for the 14 segments and icons and grids data, in the display that has been used in this project.

Second Display. h to display numbers and char and icons
I did build a library called shift Register bus to shift out 32-bit for SN75518 shift register to control the VFD in this project
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
