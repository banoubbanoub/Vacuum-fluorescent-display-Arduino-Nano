#include<Arduino.h>
#include<SanyoCCB.h>
//LC7213IN1, byte 0
#define IN10_P0 0
#define IN10_P1 1
#define IN10_P2 2
#define IN10_P3 3
#define IN10_P4 4
#define IN10_P5 5
#define IN10_P6 6
#define IN10_P7 7
//LC7213IN1, byte 1
#define IN10_P8 0
#define IN10_P9 1
#define IN10_P10 2
#define IN10_P11 3
#define IN10_P12 4
#define IN10_P13 5
#define IN10_P14 6
#define IN10_P15 7
// LC72131 IN1, byte 2
#define IN10_R3     7
#define IN10_R2     6
#define IN10_R1     5
#define IN10_R0     4
#define IN10_DNC    3
#define IN10_CTE    2
#define IN10_DVS    1
#define IN10_SNS    0
// LC72131 IN2, byte 0
#define IN20_TEST2  7
#define IN20_TEST1  6
#define IN20_TEST0  5
#define IN20_IFS    4
#define IN20_DLC    3
#define IN20_SDC1    2
#define IN20_GT1    1
#define IN20_GT0    0

// LC72131 IN2, byte 1
#define IN21_DZ1    7
#define IN21_DZ0    6
#define IN21_UL1    5
#define IN21_UL0    4
#define IN21_DOC2   3
#define IN21_DOC1   2
#define IN21_DOC0   1
#define IN21_SDC0    0

// LC72131 IN2, byte 2
#define IN22_STSW   7
#define IN22_BDSW  6
#define IN22_BO2    5
#define IN22_IFSW   4
#define IN22_BO1    3
#define IN22_IOC2   2
#define IN22_IOC1   1
#define IN22_IO1    0

// LC72131 DO0, byte 0
#define DO0_IN2     7
#define DO0_IN1     6
#define DO0_UL      4

// For function LV2300SetMode
#define LV2300_MONO    1
#define LV2300_STEREO  2
#define LV2300_MUTE    3
#define LV2300_UNMUTE  4
#define LV2300_BAND_FM 5
#define LV2300_BAND_AM 6

// Acceptable IF frequency deviation window (for the PLL) when searching for radio stations
// You may need to tweek these values to have a reliable "scan" mode
#define FM_TUNED_WINDOW 180
#define AM_TUNED_WINDOW 20



SanyoCCB LV2300PLLccb(A2, A3, A0, A1); // Pins: DO CL DI CE

byte pll_in1[3];
byte pll_in2[3];

// Initial frequencies
uint16_t FMFrequency = 2128;   // MHz * 10
uint16_t AMFrequency = 53;    // KHZ / 10

uint8_t band = LV2300_BAND_FM;
uint8_t tuned = 0;


/************************************************\
 *              LV2300Init()                   *
 * Initialize the PLL settings vectors with     *
 * parameters common to booth AM and FM modes   *
\************************************************/ 
void LV2300Init() {
  memset(pll_in1, 0, 3);
  memset(pll_in2, 0, 3);
  bitSet(pll_in2[0], IN20_IFS);   // IF counter in normal mode
  bitSet(pll_in2[1], IN21_UL0);   // Phase error detection width = 0us
  bitClear(pll_in2[2], IN22_IFSW);   // Mute off / normal tuner mode
}

/************************************************\
 *              LV2300SetMode()                 *
 * Some predefined setups for the YST93x module *
\************************************************/
void LV2300SetMode(uint8_t mode) {
  switch(mode) {
    case LV2300_STEREO:
     bitSet(pll_in2[2], IN22_STSW);
      break;

    case LV2300_MONO:
     bitClear(pll_in2[2], IN22_STSW);
      break;

    case LV2300_MUTE:
    bitSet(pll_in2[2], IN22_IFSW);
      break;

    case LV2300_UNMUTE:
     bitClear(pll_in2[2], IN22_IFSW);
      break;

    case LV2300_BAND_FM:
      band = LV2300_BAND_FM;
      /*
       bitWrite(pll_in1[0], IN10_R0,  1); // Reference frequency = 50kHz
      bitWrite(pll_in1[0], IN10_R3,  0); //
      bitWrite(pll_in1[0], IN10_DVS, 1); // Programmable Divider divisor = 2
      bitWrite(pll_in2[0], IN20_GT0, 1); // IF counter mesurement period = 32ms
      bitWrite(pll_in2[0], IN20_GT1, 1); //
      bitWrite(pll_in2[1], IN21_DZ0, 1); // Dead zone = DZB
      bitWrite(pll_in2[1], IN21_DZ1, 0); //
      bitWrite(pll_in2[2], IN22_BDSW, 1); // FM mode
      */
      bitWrite(pll_in1[0], IN10_SNS , 0); // 
      bitWrite(pll_in1[0], IN10_DVS, 1); // 
     // bitWrite(pll_in1[0], IN10_CTE , 1); // 
      bitWrite(pll_in1[0], IN10_DNC, 0); // 
      bitWrite(pll_in1[0], IN10_R0,  0); // 
      bitWrite(pll_in1[0], IN10_R1,  0); // 
      bitWrite(pll_in1[0], IN10_R2,  0); //
      bitWrite(pll_in1[0], IN10_R3,  0); //
     
        bitWrite(pll_in2[2], IN22_IO1, 0);
        bitWrite(pll_in2[2], IN22_IOC1,1 );
        bitWrite(pll_in2[2], IN22_IOC2, 0);
       bitWrite(pll_in2[2], IN22_BO1, 0); // 
        //bitWrite(pll_in2[2], IN22_IFSW, 0); // 
       bitWrite(pll_in2[2], IN22_BO2, 0); // 
        bitWrite(pll_in2[2], IN22_BDSW, 1); // 
        //bitWrite(pll_in2[2], IN22_STSW, 0); 
        //
        bitWrite(pll_in2[1], IN21_SDC0 , 0); //
        bitWrite(pll_in2[1], IN21_DOC0 , 0); // 
        bitWrite(pll_in2[1], IN21_DOC1 , 0);
        bitWrite(pll_in2[1], IN21_DOC2, 0); 
      //  bitWrite(pll_in2[1], IN21_UL0 , 1);
       bitWrite(pll_in2[1], IN21_UL1 , 0);
       bitWrite(pll_in2[1], IN21_DZ0  , 1);///////
       bitWrite(pll_in2[1], IN21_DZ1 , 0);
        //
        bitWrite(pll_in2[0],  IN20_GT0   , 1);
        bitWrite(pll_in2[0],  IN20_GT1   , 1);//////////
        bitWrite(pll_in2[0],  IN20_SDC1   , 0);
         bitWrite(pll_in2[0],  IN20_DLC   , 0);
      // bitWrite(pll_in2[0],   IN20_IFS   , 1);
        bitWrite(pll_in2[0],  IN20_TEST0  , 0);
        bitWrite(pll_in2[0],  IN20_TEST1  , 0);
       bitWrite(pll_in2[0],  IN20_TEST2  , 0);
      break;
    
    case LV2300_BAND_AM:

       
      break;
  }
   LV2300PLLccb.write(B10000010, pll_in1, 3 );
   LV2300PLLccb.write(B10010010, pll_in2, 3); 
}

/************************************************************\
 *                                            *
 * Set the tuner frequency and return 1 if it is tuned      *
 * or 0 otherwise.                                          *
 *                                                          *
 * The frequency divisors was chosen in a way the frequency *
 * representation can be directly sent to the PLL and is    *
 * easy to represent:                                       *
 * - FM mode (divisor = 100): frequency (MHz) * 10          *
 * - AM mode (divisor = 10):  frequency (kHZ) / 10          *
\************************************************************/
uint8_t LV2300Tune(uint16_t frequency) {
  uint16_t fpd = 0;
  uint8_t i = 0;
 // uint8_t r[3];
  unsigned long IFCounter = 0;
  
  switch(band) {
    case LV2300_BAND_FM:
      // FM: fpd = (frequency + FI) / (50 * 2)
      fpd = (frequency + 107);
      break;
      
    case LV2300_BAND_AM:
      // AM: fpd = ((frequency + FI) / 10) << 4
      fpd = (frequency + 45) << 4;
      break;
      
    default: return 1;
  }

  LV2300SetMode(LV2300_MUTE);   // LV2300 only injects FI signal into the PLL when in MUTE mode

  // Reset the IF counter and program the Frequency Programmable Divider (fpd)
  bitClear(pll_in1[0], IN10_CTE);
  pll_in1[1] = byte(fpd >> 8);
  pll_in1[2] = byte(fpd & 0x00ff);
  LV2300PLLccb.write(B10000010, pll_in1, 3);

  // Start the IF counter
  bitSet(pll_in1[0], IN10_CTE);
LV2300PLLccb.write(B10000010, pll_in1, 3);
  
   //Wait for PLL to be locked (DO0_UL == 1)
//while(i < 20) {
   //delay(50);
   //Radioccb.read(0xa2, r, 3);  // Discard the 1st result: it is latched from the last count (as said on the datasheet)
  //Radioccb.read(0xa2, r, 3);  // The 20 rightmost bits from r[0..2] are the IF counter result
  // i = (bitRead(r[0], DO0_UL)) ? 100 : i + 1;
 //}
  
  LV2300SetMode(LV2300_UNMUTE);   // Mute off / normal tuner mode
   
  if(i == 100) {
    // PLL is locked.  If the IF deviation is within the defined (window) interval,
    // the radio is likely to be tuned.
    // Note: this "tuned" detection method is not recommended on the LC72131 datasheet as 
    // it can give false positive results.  A better approach would be to get the "tuned"
    // flag from a RDS decoder with signal quality detection (e.g.: PT2579 or Philips SAA6588)
    // connected to the YST93x tuner module "RDS Output" pin. SAA6588 is more powerful/popular, 
    // but PT2579 looks a lot easier to use as it is not programmable and has a dedicated
    // signal quality output pin.
  // IFCounter = (r[0] & 0x0f);
    //IFCounter = (IFCounter << 16) | (unsigned long)(r[1] << 8) | (r[2]);
    //Serial.println(IFCounter);
    switch(band) {
     case LV2300_BAND_FM:
         //Expected value: IF (10.7MHz) * Mesurement period (32ms, as set via GT[1..0]) = 342400
       //if((IFCounter > 342400) && ((IFCounter - 342400) < FM_TUNED_WINDOW)) return 1;
       //if((IFCounter < 342400) && ((342400 - IFCounter) < FM_TUNED_WINDOW)) return 1;
        break;
      case LV2300_BAND_AM:
        // Expected value: IF (450kHz) * Mesurement period (8ms, as set via GT[1..0]) = 3600
        // Note: scan mode in AM is really poor.  I have done my best in tweaking it, but it barely works
        if((IFCounter > 3600) && ((IFCounter - 3600) < AM_TUNED_WINDOW)) return 1;
        if((IFCounter < 3600) && ((3600 - IFCounter) < AM_TUNED_WINDOW)) return 1;
        break;
        
    }
 }
  
  return 0; 
}
uint8_t YST93xIsStereo() {
  uint8_t r[3];
  
  LV2300PLLccb.read(0xa2, r, 3);
  return(bitRead(r[0], DO0_IN2) ? 0 : 1);
}
