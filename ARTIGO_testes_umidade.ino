//Sensores
int GBK = A1;
int FUNDUINO = A2;
int MH = A3;
int HW390 = A4;

void setup()
{
  pinMode(A1, OUTPUT);
  pinMode(GBK, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(FUNDUINO, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(MH, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(HW390, INPUT);
  Serial.begin (9600);

  Serial.println("SensorGBK;SensorFUNDUINO;SensorMH;SensorHW390");
}
void loop()
{
  Serial.print(sensorValue1());
  Serial.print(";");
  Serial.print(sensorValue2());
  Serial.print(";");
  Serial.print(sensorValue3());
  Serial.print(";");
  Serial.print(sensorValue4());

  Serial.println();
 
  delay(5000);
}
//-------------------------------------------------------------
float sensorValue1(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = analogRead(GBK);  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);  
}
//-------------------------------------------------------------
float sensorValue2(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = analogRead(FUNDUINO);  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);  
}
//-------------------------------------------------------------
float sensorValue3(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = analogRead(MH);  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);  
}
//-------------------------------------------------------------
float sensorValue4(){
  float vet[3];
  
  for(int i=0; i<3; i++){
    float temp = analogRead(HW390);  
    vet[i] = temp;
    delay(250);
  }

  return ((vet[0]+vet[1]+vet[2])/3);  
}
