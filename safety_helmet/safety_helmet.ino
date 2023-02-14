#define pResistor A0
#define gasSensor A2
#define temperatureSensor A5
#define buzzer 7
#define hLight 8
#define redLed 9

float dTemp = 35.0;
int dGas = 400;
int bValue= 20;

int gasValue;
int lightValue;
float tempValue;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(hLight,OUTPUT);
  pinMode(redLed, OUTPUT);
  delay(10000);
}

float temperatureValue(){
  return ((analogRead(A2)*(5.0/1024.0))*100)-20;
}

void display(int gas,int light,float temp){
  Serial.print(" Gas: ");
  
  Serial.print(gas);
  Serial.print(" Light: ");
  Serial.print(light);
  Serial.print(" Temp: ");
  Serial.println(temp);
}

void loop()
{
  gasValue   = analogRead(gasSensor);
  lightValue = analogRead(pResistor);
  tempValue  = temperatureValue();
  
  display(gasValue, lightValue, tempValue);

  //GAS Sensor

  if (gasValue >= dGas+100 && gasValue < dGas+200){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(150);
    tone(buzzer, 350);
    digitalWrite(redLed,LOW);
    delay(150);
  }
  else if (gasValue >= dGas+200 && gasValue < dGas+300){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(100);
    tone(buzzer, 350);
    digitalWrite(redLed,LOW);
    delay(100);
  }
  else if (gasValue >= dGas+300 && gasValue < dGas+400){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(75);
    tone(buzzer, 350);
    digitalWrite(redLed,LOW);
    delay(75);
  }
  else if (gasValue >= dGas+400 && gasValue < dGas+500){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(50);
    tone(buzzer, 350);
    digitalWrite(redLed,LOW);
    delay(50);
  }
  else if (gasValue >= dGas+500 && gasValue < dGas+600){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(25);
    tone(buzzer, 350);
    digitalWrite(redLed,LOW);
    delay(25);
  }
  else if (gasValue >= dGas+600){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
  }
  else if(gasValue <= 400){
    noTone(buzzer);
    digitalWrite(redLed, LOW);
  }

  //Temperature Sensor

  if (tempValue >= dTemp+15.0 && tempValue<16.0 ){
    tone(buzzer, 800);
    digitalWrite(redLed, HIGH);
    delay(150);
    tone(buzzer, 100);
    digitalWrite(redLed, LOW);
    delay(150);
  }
  else if (tempValue >= dTemp+16.0 && tempValue<17.0){
    tone(buzzer, 800);
    digitalWrite(redLed, HIGH);
    delay(125);
    tone(buzzer, 100);
    digitalWrite(redLed, LOW);
    delay(125);
  }
  else if (tempValue >= dTemp+17.0 && tempValue<18.0){
    tone(buzzer, 800);
    digitalWrite(redLed, HIGH);
    delay(100);
    tone(buzzer, 100);
    digitalWrite(redLed, LOW);
    delay(100);
  }
  else if (tempValue >= dTemp+18.0 && tempValue<19.0){
    tone(buzzer, 800);
    digitalWrite(redLed, HIGH);
    delay(75);
    tone(buzzer, 100);
    digitalWrite(redLed, LOW);
    delay(75);
  }
  else if (tempValue >= dTemp+19.0){
    tone(buzzer, 800);
    digitalWrite(redLed, HIGH);
  }
  else if (tempValue < dTemp){
    noTone(buzzer);
    digitalWrite(redLed,LOW);
  }

  //LDR

  if (lightValue > bValue){
    digitalWrite(hLight, LOW);
  }
  else{
    digitalWrite(hLight, HIGH);
  }

  delay(100);
}
