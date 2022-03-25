#include <Servo.h>
 //Incluindo biblioteca do RTC
#include <virtuabotixRTC.h>
#define SERVO 11 // Porta Digital 9 PWM

//definindo os pinos 6,7,8
virtuabotixRTC myRTC(6, 7, 8);

Servo s; // Variável Servo
char pos = 0; // Posição Servo

void setup() {
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero

  //Inicializando o Shield RTC
  // seconds, minutes, hours, day of the week, day of the month, month, year
  // myRTC.setDS1302Time(00, 05, 16, 06, 25, 3, 2022); 
  //but remember to "comment/remove" this function once you're done
}

void loop() {

  controlarServo();

  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();

  // Start printing elements as individuals
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print(" ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);

  // Delay so the program doesn't print non-stop
  delay(1000);

}

//Função para controlar o motor

void controlarServo(void) {
  if (Serial.available() > 0) {
    // lê do buffer o dado recebido:
    pos = Serial.read();

    // responde com o dado recebido:

    if (pos == 'A' || pos == 'a') {
      s.write(0);
      Serial.println("Estou em 0º");
    } else if (pos == 'B' || pos == 'b') {
      s.write(45);
      Serial.println("Estou em 45º");
    } else if (pos == 'C' || pos == 'c') {
      s.write(90);
      Serial.println("Estou em 90º");
    } else if (pos == 'D' || pos == 'd') {
      s.write(135);
      Serial.println("Estou em 135º");
    } else if (pos == 'E' || pos == 'e') {
      s.write(180);
      Serial.println("Estou em 180º");
    }
  }

}
