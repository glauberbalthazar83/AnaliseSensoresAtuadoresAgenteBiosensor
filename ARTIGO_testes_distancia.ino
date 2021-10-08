#include <HCSR04.h>
#include <Adafruit_VL53L0X.h>

//VL53L1X
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

//HCSR04
UltraSonicDistanceSensor distanceSensorHCSR04(13, 12); 


//-------------------------------------------------------
void setup() {
  Serial.begin(9600); 
  while (! Serial) {
    delay(1);
  }
  
  //VL53L1X
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  Serial.println("HCSR04;VL53L1X");
}

//-------------------------------------------------------
void loop() {
  Serial.print(lerHCSR04());
  Serial.print(";");
  Serial.print(lerVL53L1X());
  Serial.println();
  delay(5000);
}


//-------------------------------------------------------
float lerHCSR04(){
  float vet[3];

  for(int i=0; i<3; i++){
    vet[i] = distanceSensorHCSR04.measureDistanceCm();
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);
}
//-------------------------------------------------------
float lerVL53L1X(){
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); 
  float vet[3];

  for(int i=0; i<3; i++){
    vet[i] = measure.RangeMilliMeter/10;//para cm
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);
}
