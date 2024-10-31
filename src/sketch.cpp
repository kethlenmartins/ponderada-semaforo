#include <Ultrasonic.h>

const int echoPin = 3; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 2; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)
 
Ultrasonic ultrasonic(trigPin, echoPin); //INICIALIZANDO OS PINOS DO ARDUINO
 
int distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  hcsr04(); //Atualiza a distância

  if (distancia < 15) {
    digitalWrite(8, HIGH); 
    Serial.println("1");
  } else {
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(8,HIGH);
    delay(6000);
    digitalWrite(8,LOW);
  }
  
  hcsr04();
  if (distancia < 15) {
    digitalWrite(8, HIGH); 
    Serial.println("2");
  } else {  
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(9,HIGH);
    delay(2000);
    digitalWrite(9,LOW);
  }

  hcsr04();
  if (distancia < 15) {
    digitalWrite(8, HIGH);
    Serial.println("3");
  } else {
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(10,HIGH);
    delay(4000);
    digitalWrite(10,LOW);
  }

  hcsr04();
  if (distancia < 15) {
    digitalWrite(8, HIGH);
    Serial.println("4");
  } else {
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(9,HIGH);
    delay(2000);
    digitalWrite(9,LOW);
  }
}

void hcsr04() {
  digitalWrite(trigPin, LOW); // Pulso baixo no pino 6
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Pulso alto no pino 6
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Pulso baixo novamente
  
  // Lê a distância e armazena na variável global 'distancia'
  distancia = ultrasonic.Ranging(CM);
  result = String(distancia); // Converte a distância para string e armazena em 'result'
  delay(500); // Intervalo de 500 ms
}
