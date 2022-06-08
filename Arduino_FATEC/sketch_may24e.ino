#include <Ultrasonic.h>

#include <Servo.h>

#define SERVO 6 // Porta Digital 6 PWM

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

int tempo;

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
Servo s; // Variável Servo
int pos; // Posição Servo
 
void setup ()
{
 
  pinMode(8, OUTPUT);
  s.attach(SERVO);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  s.write(0); // Inicia motor posição zero
}
 
void loop()
{
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  Distancia(cmMsec);
  delay(500);
  for(pos = 0; pos < 60; pos++)
  {
    s.write(pos);
    delay(10);
  }
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  Distancia(cmMsec);
  delay(500);
  for(pos = 60; pos < 90; pos++)
  {
    s.write(pos);
    delay(10);
  }
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(500);
  for(pos = 90; pos >= 60; pos--)
  {
    s.write(pos);
    delay(10);
  }
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  Distancia(cmMsec);
  delay(500);
   for(pos = 60; pos >= 0; pos--)
  {
    s.write(pos);
    delay(10);
  }
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  Distancia(cmMsec);
  delay(500);
  }

void Distancia(float distancia)
{
  if(distancia > 1000)
  { 
    tempo = 1000;
    Buzina(tempo);
  }
  else if(distancia < 1000 && distancia > 500)
  {
    tempo = 500;
    Buzina(tempo);
  }
  else if(distancia < 500 && distancia > 100)
  {
    tempo = 100;
    Buzina(tempo);
  }
  else if(distancia < 100 && distancia > 50)
  {
    tempo = 60;
    Buzina(tempo);
  }
  else if(distancia < 50 && distancia > 20)
  {
      tempo = 30;
      Buzina(tempo);
  } 
  else if(distancia < 20)
  {
      tempo = 10;
      Buzina(tempo);
  } 
  else
  {
    tempo = 0;
  }
}


void Buzina(int tempo){
    for(int x=0;x<=3;x++){
    digitalWrite(8, 1);
    delay(tempo);
    digitalWrite(8, 0);
    delay(tempo);
    
    }
    
  }
