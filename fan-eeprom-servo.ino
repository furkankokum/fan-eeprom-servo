#include <EEPROM.h>
int birSensor = A0;
int ikiSensor = A1;
int fan = 3;
int crrDisDeger = 0;
int crrIcDeger = 0;
int crrDeger = 0;
int icAdres = 0;
int disAdres = 513;
int icCrrDeger=0;
int disCrrDeger=0;
int terminal = 13;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(3,OUTPUT);
  pinMode(terminal,OUTPUT);
  digitalWrite(3,LOW);
  Serial.begin(9600);
}
void loop() {
    float icDeger = analogRead(A0);
    float disDeger = analogRead(A1);
    float icC = ((icDeger/1023.0)*5000.0)/10.0;
    float disC = ((disDeger/1023.0)*5000.0)/10.0;
if(icC != disC){
  EEPROM.write(icAdres,icC);
  icAdres = icAdres+1;
  if(icAdres == 513){
    icAdres = 0;
    }
  }
if(icC != disC){
  EEPROM.write(disAdres,disC);
  disAdres = disAdres+1;
  if(disAdres == 1025){
    disAdres = 513;
    }
  }
delay(60000);
int i;
int j;
j = 15;
if(i>=0 && i<513 && j>=15 && j<527){
    for(i = 0;i<=j;i++){
        crrIcDeger = crrIcDeger + EEPROM.read(i);
    }
    i++;
    j++;
  }
else {
  i = 0;
  j = 15;
  }
j = 528;
if(i>=513 && i<1024 && j>=528 && j<1024){
    for(i= 513;i<=j;i++){
        crrDisDeger = crrDisDeger + EEPROM.read(i);
    }
    i++;
    j++;
  }
else {
  i = 513;
  j = 528;
  }
float crrDeger = ((crrIcDeger)/15 - (crrDisDeger)/15);

if ((crrDeger) > 15){
      analogWrite(fan,85);
      delay(500);
    }
  if ((crrDeger) > 30){
      analogWrite(fan,190);
      delay(500);
    }
  if ((crrDeger) > 45){
      analogWrite(fan,255);
      delay(500);
    }
  else{
      analogWrite(fan,LOW);
    }
Serial.println(EEPROM.read(0));
Serial.println(EEPROM.read(1));
Serial.println(EEPROM.read(2));
Serial.println(EEPROM.read(3));
Serial.println(EEPROM.read(4));
Serial.println(EEPROM.read(513));
Serial.println(EEPROM.read(514));
Serial.println(EEPROM.read(515));
Serial.println(EEPROM.read(516));
Serial.println(EEPROM.read(517));
}
