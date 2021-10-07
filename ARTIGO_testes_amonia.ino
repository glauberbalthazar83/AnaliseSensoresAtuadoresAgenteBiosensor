#include <MQ135.h>

//MQ-135
MQ135 mq135 = MQ135(A0);

//CMJCU6814
const float max_volts = 5.0;
const float max_analog_steps = 1023.0;


void setup() {
  Serial.begin(9600);
  Serial.println("CJMCU6814;MICS5524;MQ135");
}

void loop() {
  delay(5000);
  Serial.print(lerCJMCU_6814());
  Serial.print(";");
  Serial.print(lerMICS_5524());
  Serial.print(";");
  Serial.print(lerMQ135());    

  Serial.println();  
}

//-------------------------------------------------------------
float lerCJMCU_6814(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    vet[i] = analogRead (A1*(max_volts / max_analog_steps)) ; 
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);  
}

//-------------------------------------------------------------
float lerMICS_5524(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    vet[i] = analogRead (A2) ; 
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);
}

//-------------------------------------------------------------
float lerMQ135(){
  float vet[3];

  for(int i=0; i<3; i++){
    vet[i] = mq135.getPPM();
    delay(250);    
  }
  
  return ((vet[0]+vet[1]+vet[2])/3);
}
