#include <Arduino.h>
#include <ShiftRegisterBus.h>
#include <DisplayData.h>
#define clks 13
#define dta 11
#define strobe 8
#define latch 9
ShiftRegisterBus shiftRegisterbus(dta,clks,latch,strobe);
//*********************************
void ClearDisplay(){
   digitalWrite(strobe,HIGH);
   digitalWrite(latch,HIGH);
   digitalWrite(strobe,LOW);
   digitalWrite(latch,LOW);
}
//*************************************
//
void Display(int number,uint8_t gridNumber){
    uint8_t a[2]={(number/10) %10,number %10};
    uint8_t b[3]={(number/100)%10,(number/10)%10,number %10};
    uint8_t c[4]={(number/1000)%10,(number/100)%10,(number/10)%10,number%10};
    uint8_t d[5]={(number/10000)%10,(number/1000)%10,(number/100)%10,(number/10)%10,number%10};
    String num = String(number);
    uint8_t z= number;
    uint8_t gridnum=0;
   
    for(uint8_t x=0;x < num.length();x++){
     // if(num.length()==1){z =number;}
      if(num.length()==2){z=a[x];}
      if(num.length()==3){z=b[x];}
      if(num.length()==4){z=c[x];}
      if(num.length()==5){z=d[x];}
   ClearDisplay();
      Digits(z,gridNumber+gridnum);
      shiftRegisterbus.write(shiftRegisterByte,4); 
      gridnum++;
      if(gridnum>=8)gridnum=0;
    }
    
}
void Display(String str,uint8_t gridNumber){
  uint8_t gridNum=0;
  for(uint8_t x=0;x< str.length();x++){
    char c = str.charAt(x);
    ClearDisplay();
    AlphaBet(c,gridNumber + gridNum);
    shiftRegisterbus.write(shiftRegisterByte,4);
    gridNum++;
    if(gridNum >= 8)gridNum=0;
  }
}
void DisplayIcon_G_1(String str){
    ClearDisplay();
   IconGrid_1(str);
   shiftRegisterbus.write(shiftRegisterByte,4);
}
void DisplayIcon_G_10(String str){
    ClearDisplay();
  IconGrid_10(str);
  shiftRegisterbus.write(shiftRegisterByte,4);
}
void DisplayDots(uint8_t number){
  ClearDisplay();
  ShowDots_3row(number);
  shiftRegisterbus.write(shiftRegisterByte,4);
}