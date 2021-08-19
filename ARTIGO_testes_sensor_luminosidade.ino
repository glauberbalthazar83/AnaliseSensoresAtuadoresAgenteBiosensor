#include <Wire.h>
#include <BH1750.h>
#include <LightDependentResistor.h>

//TEMT6000
int const AREF = 5.0;//tensao referencia 5v
int const pinoLuminosidadeTEMT6000 = A0;

//BH1750
BH1750 lightMeter;

//P13-LDR
#define OTHER_RESISTOR 10000 //ohms
#define USED_PIN A1
#define USED_PHOTOCELL LightDependentResistor::GL5528
LightDependentResistor photocell(USED_PIN, OTHER_RESISTOR, USED_PHOTOCELL);

//-------------------------------------------------------------
void setup() {  
  //inicializacao basica
  Serial.println("Iniciando...");
  Serial.begin(9600);

  //TEMT6000
  pinMode(pinoLuminosidadeTEMT6000,  INPUT);   

  //BH1750
  Wire.begin();
  lightMeter.begin();  

  //delay
  delay(5000);
}

//-------------------------------------------------------------
void loop() {
  float luminosidadeTEMT6000 = leituraLuminosidadeTEMT6000();
  float luminosidadeBH1750 = leituraLuminosidadeBH1750();
  float luminosidadeP13LDR = leituraLuminosidadeP13LDR();
  
  Serial.print("TEMT6000: ");
  Serial.print(luminosidadeTEMT6000);
  Serial.print(" - ");
  Serial.print("BH1750: ");
  Serial.print(luminosidadeBH1750);
  Serial.print(" - ");
  Serial.print("P13LDR: ");
  Serial.print(luminosidadeP13LDR);
      
  Serial.println("");
  delay(5000);
}

//-------------------------------------------------------------
float leituraLuminosidadeP13LDR(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float lux = photocell.getCurrentLux();  
    vet[i] = lux;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);
}

//-------------------------------------------------------------
float leituraLuminosidadeBH1750(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    uint16_t lux = lightMeter.readLightLevel();
    vet[i] = lux;
    delay(250);
  }
  return ((vet[0]+vet[1]+vet[2])/3);
}

//-------------------------------------------------------------
float leituraLuminosidadeTEMT6000(){
  float vet[3];
  
  for(int i=0; i<3; i++){
      float sensor_value = analogRead(pinoLuminosidadeTEMT6000); 
      float volts = sensor_value * AREF / 1024.0;    
      float amps = volts / 10000.0;             
      float microamps = amps * 1000000.0;       
      float lux = microamps * 2.0;
      vet[i] = lux;
      delay(250);
  }  
  
  return ((vet[0]+vet[1]+vet[2])/3);
}
