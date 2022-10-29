#include<Arduino.h>
#include<Wire.h>
void InputSelector(uint8_t number){
byte inputselectorData[] = {0x00,0x01,0x02,0x03};//A,B,C,D  
  Wire.beginTransmission(0x40);//Slave address
  Wire.write(0x04);//input selector address 
  switch (number)
  {
  case 1:
    Wire.write(inputselectorData[0]);
    break;
    case 2:
    Wire.write(inputselectorData[1]);
    break;
    case 3:
    Wire.write(inputselectorData[2]);
    break;
    case 4:
    Wire.write(inputselectorData[3]);
    break;
  }
  Wire.endTransmission();
}
void VolumeGain_1ch(byte data){
  Wire.beginTransmission(0x40);//Slave address
  Wire.write(0x21);
  Wire.write(data);
  Wire.endTransmission();
}
void VolumeGain_2h(byte data){
  Wire.beginTransmission(0x40);//Slave address
  Wire.write(0x22);
  Wire.write(data);
  Wire.endTransmission();
}
void BassGain(){

}
void TrebleGain(){

}
void Gain(){

}
void SystemReset(){

}