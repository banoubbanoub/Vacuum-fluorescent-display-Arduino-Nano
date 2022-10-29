#include <Arduino.h>
#include <Wire.h>
#include <LV2300PLL.h>
#include <IRremote.h>
#include <Display.h>
#include<SoundProcessors.h>
int RECV_PIN = 2;  // IR Receiver pin
IRrecv irrecv(RECV_PIN);
decode_results results;
#define clk 3
#define dt 4
#define sw 5
#define slaveAddress 0x40
#define powerSwitch 6
#define optoCubler 7
int cuk=0;
int pvk=0;
byte vol=176; 
int v=10;
int count =1;    
String str_1;
uint8_t tr=0; 
uint8_t tr_1=0; 
void UpdateDisplay(){
 Display(str_1,1);
 if(str_1 =="fm"){Display(tr_1,3);DisplayIcon_G_10("FM");}
 if(str_1=="aux"){Display(tr,4);}
 Display(v,6);
 DisplayIcon_G_1("clk");
 DisplayDots(1);
} 
void Audiovolume(byte data){
 VolumeGain_1ch(data);
 VolumeGain_2h(data);
}


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  irrecv.enableIRIn();
  shiftRegisterbus.init();
  pinMode(clk,INPUT);
  pinMode(dt,INPUT);
  pinMode(powerSwitch,INPUT);
  pinMode(optoCubler,OUTPUT);
  LV2300PLLccb.init();
  LV2300Init();
  band = LV2300_BAND_FM;
  LV2300SetMode(LV2300_BAND_FM);
  LV2300SetMode(LV2300_STEREO);
  tuned = LV2300Tune(FMFrequency);
  pvk = digitalRead(clk);
  str_1 ="aux";
  tr =1;
  InputSelector(4);
  Audiovolume(vol); 
}

void loop() {

if(digitalRead(powerSwitch)== HIGH){
  digitalWrite(optoCubler,HIGH);
 }

  cuk = digitalRead(clk);
   if(cuk != pvk){
    if(cuk != digitalRead(dt)){
      FMFrequency--;
     tr_1=(FMFrequency/10)/2;
     LV2300Tune(FMFrequency);
     if(FMFrequency < 880)  FMFrequency = 880;
     ///if(vol <=127){vol =127;}
    }
    else{
      FMFrequency++;
      tr_1=(FMFrequency/10)/2;
      LV2300Tune(FMFrequency);
     //if(vol >= 215){vol =215;}
    
    }
   }
 pvk = cuk;
 if(irrecv.decode(&results)){
   switch(results.value){
    case 3772799143://Local radio Audio output
    InputSelector(2);
    str_1 ="fm";
    count =2;
    break;
    case 3772803223:// AUX IN
    InputSelector(4);
    str_1 ="aux";
    count =1;
    tr =1;
    break;
    case 3772795063:
      FMFrequency++;
    tr_1=(FMFrequency/10)/2;
      LV2300Tune(FMFrequency);
     break;
     case 3772778743:
     FMFrequency--;
    tr_1=(FMFrequency/10)/2;
     LV2300Tune(FMFrequency);
     if(FMFrequency < 880)  FMFrequency = 880;
    break;
    case 3772833823:
    if(vol <= 127)vol = 127;
    if(v<=0)v=0;
     v++;
    vol --;
    Audiovolume(vol); 
    break;
    case 3772829743:
    if(vol >= 215)vol = 215;
    if(v>999)v=999;
    vol++;
    v--;
    Audiovolume(vol);
    break;
    case 3772837903: // volume mute
    vol = 215;
    Audiovolume(vol);
    break;
   }

 }
 irrecv.resume();
 UpdateDisplay();
}