#include <GP2Y1010AU0F.h>
#include <DSM501.h>

//GP2Y1010AU0F
int measurePin = A0;
int ledPin     = 13;
GP2Y1010AU0F dustSensor(ledPin, measurePin);
float dustDensity = 0;

//DSM501A
#define DSM501_PM10 3
#define DSM501_PM25 4
DSM501 dsm501(DSM501_PM10, DSM501_PM25);

//-------------------------------------------------------
void setup() {
  Serial.begin(9600);
  Serial.println("GP2Y1010AU0F;DSM501A");

  //GP2Y1010AU0F
  dustSensor.begin();

  //DSM501A
  dsm501.begin(MIN_WIN_SPAN);  
}
//-------------------------------------------------------
void loop() {
  Serial.print(lerGP2Y1010AU0F());
  Serial.print(";");
  Serial.print(lerDSM501A());
  Serial.println();
  delay(5000);
}

//-------------------------------------------------------
float lerGP2Y1010AU0F(){
  float vet[3];

  for(int i=0; i<3; i++){
    vet[i] = dustSensor.read();
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);  
}

//-------------------------------------------------------
float lerDSM501A(){
  float vet[3];

  for(int i=0; i<3; i++){
    dsm501.update();
    vet[i] = dsm501.getPM25();
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);
}
