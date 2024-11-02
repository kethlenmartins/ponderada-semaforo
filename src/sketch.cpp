#include <Ultrasonic.h>

const int echoPin = 3; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 2; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)
 
Ultrasonic ultrasonic(trigPin, echoPin); //INICIALIZANDO OS PINOS DO ARDUINO
 
int distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING

void setup() {
  pinMode(8, OUTPUT); // led vermelho
  pinMode(9, OUTPUT); // led amarelo
  pinMode(10, OUTPUT); // led verde
  pinMode(echoPin, INPUT); // echo do sensor ultrassônico
  pinMode(trigPin, OUTPUT)// trigger do sensor ultrassõnico 
  Serial.begin(9600); 
}

void loop() {
  hcsr04(); //Atualiza a distância chamando a função que a calcula
  if (distancia < 15) { 
    digitalWrite(8, HIGH); // liga a luz vermelha
    Serial.println("1");
  } else {
    digitalWrite(8,LOW); // apaga a luz vermelha
    delay(500);
    digitalWrite(8,HIGH); // liga a luz vermelha
    delay(6000);
    digitalWrite(8,LOW); // apaga a luz vermelha
  }
  
  hcsr04();
  if (distancia < 15) {
    digitalWrite(8, HIGH); // liga a luz vermelha
    Serial.println("2");
  } else {  
    digitalWrite(8,LOW); // apaga a luz vermelha
    delay(500);
    digitalWrite(9,HIGH); // liga a luz amarela
    delay(2000);
    digitalWrite(9,LOW); // apaga a luz amarela
  }

  hcsr04();
  if (distancia < 15) {
    digitalWrite(8, HIGH); // liga a luz vermelha
    Serial.println("3");
  } else {
    digitalWrite(8,LOW); // apaga a luz vermelha
    delay(500);
    digitalWrite(10,HIGH); // liga a luz verde
    delay(4000);
    digitalWrite(10,LOW); // apaga a luz verde
  }

  hcsr04();
  if (distancia < 15) {
    digitalWrite(8, HIGH); // liga a luz vermelha
    Serial.println("4");
  } else {
    digitalWrite(8,LOW); // apaga a luz vermelha
    delay(500);
    digitalWrite(9,HIGH); // liga a luz amarela
    delay(2000);
    digitalWrite(9,LOW); // apaga a luz amarela
  }
}

// função padrão do próprio sensor
void hcsr04() {
  digitalWrite(trigPin, LOW); // Pulso baixo no pino 2
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Pulso alto no pino 2
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Pulso baixo novamente
  
  // Lê a distância e armazena na variável global 'distancia'
  distancia = ultrasonic.Ranging(CM);
  result = String(distancia); // Converte a distância para string e armazena em 'result'
  delay(500); // Intervalo de 500 ms
}
