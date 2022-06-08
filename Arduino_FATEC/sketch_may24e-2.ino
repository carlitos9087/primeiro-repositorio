#include <Ultrasonic.h>
#include <Servo.h>

#define SERVO 6 // Porta Digital 6 PWM

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
Servo s; // Variável Servo
int pos; // Posição Servo

long tempo;
 
void setup ()
{
  Serial.begin(9600);
  s.attach(SERVO);
  s.write(0); // Inicia motor posição zero
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
 
void loop()
{
  for(int i=15;i<=165;i = i + 10){  
  s.write(i);
    Distancia();
  }

  for(int i=165;i>15;i = i - 10){  
  s.write(i);
  Distancia();
  
  }
}

void Distancia(){ 
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor
  Serial.println("Distancia em cm: ");
  Serial.println(cmMsec); 
  
    while(cmMsec < 50)
    {
      if (cmMsec < 60 && cmMsec > 0.9)
      {
        long microsec = ultrasonic.timing();
        cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
        digitalWrite(8, 1);
        digitalWrite(9, 1);
        delay(cmMsec*2.0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
        delay(cmMsec*2.0);
        microsec = ultrasonic.timing();
        cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
      }
    }
  delay(500);
}
