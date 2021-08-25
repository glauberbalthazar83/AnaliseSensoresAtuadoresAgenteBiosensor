#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <DHT.h>
#include <Thermistor.h> 
#include <cactus_io_HTU21D.h>

//BME-280
#define SEALEVELPRESSURE_HPA (1013.25) 
Adafruit_BME280 bme; 
float temperatura, umidade;

//DHT11
#define DHTPIN_11 2 
#define DHTTYPE_11 DHT11
DHT dht11(DHTPIN_11, DHTTYPE_11);

//DHT22
#define DHTPIN_22 3
#define DHTTYPE_22 DHT22
DHT dht22(DHTPIN_22, DHTTYPE_22);

//P10
Thermistor thermistorP10(0); 

//HTU21d
HTU21D htu;

//------------------------------------------------------------- 
void setup() {
  Serial.begin(9600);
  delay(100);

  //BME-280
  bme.begin(0x76);

  //DHT11
  dht11.begin();

  //DHT22
  dht22.begin();

  //HTU21d
  htu.begin();

 Serial.println("BME_Temp;BME_Umid;DHT11_Temp;DHT11_Umid;DHT22_Temp;DHT22_Umid;P10_temp;HTU21d_temp;HTU21d_umid;");
}

//------------------------------------------------------------- 
void loop() {
  Serial.print(leituraTemperaturaBME280());
  Serial.print(";");
  Serial.print(leituraUmidadeBME280());
  Serial.print(";");
  Serial.print(leituraTemperaturaDHT11());
  Serial.print(";");
  Serial.print(leituraUmidadeDHT11());
  Serial.print(";");
  Serial.print(leituraTemperaturaDHT22());
  Serial.print(";");
  Serial.print(leituraUmidadeDHT22());  
  Serial.print(";");
  Serial.print(leituraTemperaturaP10());    
  Serial.print(";");
  Serial.print(leituraTemperaturaHTU21d());  
  Serial.print(";");
  Serial.print(leituraUmidadeHTU21d());   
  Serial.println();
  delay(5000);
}
//-------------------------------------------------------------
float leituraTemperaturaBME280(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = bme.readTemperature();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);  
}
//-------------------------------------------------------------
float leituraUmidadeBME280(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = bme.readHumidity();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraTemperaturaDHT11(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = dht11.readTemperature();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraUmidadeDHT11(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = dht11.readHumidity();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraTemperaturaDHT22(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = dht22.readTemperature();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraUmidadeDHT22(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = dht22.readHumidity();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraTemperaturaP10(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = thermistorP10.getTemp();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraTemperaturaHTU21d(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    htu.readSensor();
    float temp = htu.getTemperature_C();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
//-------------------------------------------------------------
float leituraUmidadeHTU21d(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    htu.readSensor();
    float temp = htu.getHumidity();  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);    
}
