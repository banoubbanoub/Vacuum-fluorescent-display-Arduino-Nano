#include <Arduino.h>
byte shiftRegisterByte[4];
//****************************
// method to display number from grid 2 to grid 8 only
//********************************
byte* Digits(uint8_t number,uint8_t grid){
    switch (number)
    {
      case 0:
     shiftRegisterByte[0]=140;
     shiftRegisterByte[1]=200;
     shiftRegisterByte[2]=0;
      break;
     case 1:
     shiftRegisterByte[0]=4;
     shiftRegisterByte[1]=64;
     shiftRegisterByte[2]=0;
      break;
      case 2:
     shiftRegisterByte[0]=139;
     shiftRegisterByte[1]=72;
     shiftRegisterByte[2]=0;
      break;
      case 3:
     shiftRegisterByte[0]=139;
     shiftRegisterByte[1]=136;
     shiftRegisterByte[2]=0;
      break;
      case 4:
     shiftRegisterByte[0]=15;
     shiftRegisterByte[1]=128;
     shiftRegisterByte[2]=0;
      break;
      case 5:
     shiftRegisterByte[0]=135;
     shiftRegisterByte[1]=136;
     shiftRegisterByte[2]=0;
      break;
      case 6:
     shiftRegisterByte[0]=135;
     shiftRegisterByte[1]=200;
     shiftRegisterByte[2]=0;
      break;
      case 7:
     shiftRegisterByte[0]=136;
     shiftRegisterByte[1]=128;
     shiftRegisterByte[2]=0;
      break;
      case 8:
     shiftRegisterByte[0]=143;
     shiftRegisterByte[1]=200;
     shiftRegisterByte[2]=0;
      break;
      case 9:
     shiftRegisterByte[0]=143;
     shiftRegisterByte[1]=128;
     shiftRegisterByte[2]=0;
      break;
    }
   switch (grid)
    {
     case 1:
     shiftRegisterByte[3]=2;
      break;
      case 2:
      shiftRegisterByte[3]=4;
      break;
      case 3:
      shiftRegisterByte[3]=8;
      break;
      case 4:
      shiftRegisterByte[3]=16;
      break;
      case 5:
      shiftRegisterByte[3]=32;
      break;
      case 6:
      shiftRegisterByte[3]=64;
      break;
      case 7:
      shiftRegisterByte[3]=128;
      break;
      case 8:
      shiftRegisterByte[2]=1;
      break;
    }
    return shiftRegisterByte;
}
//*****************************************
//Method to display char from grid 2 to grid 8
//**************************************
byte* AlphaBet(char c,uint8_t grid){
  if(isspace(c)){
   shiftRegisterByte[0]=0;
   shiftRegisterByte[1]=0;
   shiftRegisterByte[2]=0;
   
  }
  switch(c){
    case 'a':
    shiftRegisterByte[0]=143;
    shiftRegisterByte[1]=192;
    shiftRegisterByte[2]=0;
    break;
    case 'b':
    shiftRegisterByte[0]=7;
    shiftRegisterByte[1]=200;
    shiftRegisterByte[2]=0;
    break;
    case 'c':
    shiftRegisterByte[0]=132;
    shiftRegisterByte[1]=72;
    shiftRegisterByte[2]=0;
    break;
    case 'd':
    shiftRegisterByte[0]=11;
    shiftRegisterByte[1]=200;
    shiftRegisterByte[2]=0;
    break;
    case 'e':
    shiftRegisterByte[0]=135;
    shiftRegisterByte[1]=72;
    shiftRegisterByte[2]=0;
    break;
    case 'f':
    shiftRegisterByte[0]=133;
    shiftRegisterByte[1]=64;
    shiftRegisterByte[2]=0;
    break;
    case 'g':
    shiftRegisterByte[0]=143;
    shiftRegisterByte[1]=136;
    shiftRegisterByte[2]=0;
    break;
    case 'h':
    shiftRegisterByte[0]=143;
    shiftRegisterByte[1]=192;
    shiftRegisterByte[2]=0;
    break;
    case 'i':
    shiftRegisterByte[0]=160;
    shiftRegisterByte[1]=8;
    shiftRegisterByte[2]=0;
    break;
    case 'l':
    shiftRegisterByte[0]=4;
    shiftRegisterByte[1]=72;
    shiftRegisterByte[2]=0;
    break;
    case 'o':
    shiftRegisterByte[0]=140;
    shiftRegisterByte[1]=200;
    shiftRegisterByte[2]=0;
    break;
    case 'u':
    shiftRegisterByte[0]=12;
    shiftRegisterByte[1]=200;
    shiftRegisterByte[2]=0;
    break;
    case 'x':
    shiftRegisterByte[0]=80;
    shiftRegisterByte[1]=48;
    shiftRegisterByte[2]=0;
    break;
    case 'm':
    shiftRegisterByte[0]=3;
    shiftRegisterByte[1]=192;
    shiftRegisterByte[2]=0;
    break;
  }
  switch (grid)
    {
     case 1:
     shiftRegisterByte[3]=2;
      break;
      case 2:
      shiftRegisterByte[3]=4;
      break;
      case 3:
      shiftRegisterByte[3]=8;
      break;
      case 4:
      shiftRegisterByte[3]=16;
      break;
      case 5:
      shiftRegisterByte[3]=32;
      break;
      case 6:
      shiftRegisterByte[3]=64;
      break;
      case 7:
      shiftRegisterByte[3]=128;
      break;
      case 8:
      shiftRegisterByte[2]=2;
      break;
    }
  return shiftRegisterByte;
}
//********************************
//Method to display Icons in grid number 1
byte* IconGrid_1(String str,uint8_t gridNumber=1){
  if(str=="DIM"){
    shiftRegisterByte[0]=128;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="WIFI"){
    shiftRegisterByte[0]=64;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="REP"){
    shiftRegisterByte[0]=32;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="DISC"){
    shiftRegisterByte[0]=16;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="RLL"){
    shiftRegisterByte[0]=8;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="TRACK"){
    shiftRegisterByte[0]=4;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="SHUF"){
    shiftRegisterByte[0]=2;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="PROG"){
    shiftRegisterByte[0]=1;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[2]=0;
  }
  if(str=="clk"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=128;
    shiftRegisterByte[2]=0;
  }
  if(str=="c"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=64;
    shiftRegisterByte[2]=0;
  }
  if(str=="-"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=32;
    shiftRegisterByte[2]=0;
  }
  if(str=="REC"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=16;
    shiftRegisterByte[2]=0;
  }
  if(str=="DBB"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=8;
    shiftRegisterByte[2]=0;
  }
  if (str=="1"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=4;
    shiftRegisterByte[2]=0;
  }
  if(str=="2"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=2;
    shiftRegisterByte[2]=0;
  }
  if(str=="3"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=1;
    shiftRegisterByte[2]=0;
  }
 shiftRegisterByte[3]=gridNumber;
 return shiftRegisterByte;
  
}
byte* IconGrid_10(String str,uint8_t gridNumber=2){
  if(str=="oo"){
    shiftRegisterByte[0] =128;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="z1"){
   shiftRegisterByte[0] =64;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="z2"){
    shiftRegisterByte[0] =32;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="z3"){
    shiftRegisterByte[0] =16;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="RM"){
    shiftRegisterByte[0] =8;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="PM"){
    shiftRegisterByte[0] =4;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="FM"){
    shiftRegisterByte[0] =2;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="MW"){
    shiftRegisterByte[0] =1;
    shiftRegisterByte[1]=0;
    shiftRegisterByte[3]=0;
  }
  if(str=="AM"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=128;
    shiftRegisterByte[3]=0;
  }
  if(str=="RDS"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=64;
    shiftRegisterByte[3]=0;
  }
  if(str=="NEWS"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=32;
    shiftRegisterByte[3]=0;
  }
  if(str=="OPTIMAL"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=16;
    shiftRegisterByte[3]=0;
  }
  if(str=="JAZZ"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=8;
    shiftRegisterByte[3]=0;
  }
  if(str=="ROCK"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=4;
    shiftRegisterByte[3]=0;
  }
  if(str=="TECHNO"){
    shiftRegisterByte[0]=0;
    shiftRegisterByte[1]=2;
    shiftRegisterByte[3]=0;
  }
 shiftRegisterByte[2]=gridNumber;
 return shiftRegisterByte;
}
byte* ShowDots_3row(uint8_t number,uint8_t gridNumber=4){
 
    shiftRegisterByte[0]=255;
    shiftRegisterByte[1]=255;
    shiftRegisterByte[2]=12;
    shiftRegisterByte[3]=0;
  return shiftRegisterByte;
}