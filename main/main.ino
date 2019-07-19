
//#include <DS3231.h>
#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal

/**VARIABLES */
//CLOCK
//LCD
LiquidCrystal lcd(1, 2, 37,39, 41, 43); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
/**VARIABLES */


int Led23= 22;
int Led24= 23;
int Led25= 24;
int Led26= 25;
int Led27= 26;
int Led28= 27;
int Led29= 28;
int Led30= 29;
int Led31= 30;
int Led32= 31;
int Led33= 32;
int Led34= 33;


void setup() {
  Serial.begin(9600);
  init_timer();
  //Serial.println("Inicio de sketch - valores del depósto");
  //pinMode(sensorDepPin, INPUT);
  //pinMode(sensorTankPin, INPUT);
  pinMode(9, OUTPUT);
  pinMode(Led23, OUTPUT);
  pinMode(Led24, OUTPUT);
  pinMode(Led25, OUTPUT);
  pinMode(Led26, OUTPUT);
  pinMode(Led27, OUTPUT);
  pinMode(Led28, OUTPUT);
  pinMode(Led29, OUTPUT);
  pinMode(Led30, OUTPUT);
  pinMode(Led31, OUTPUT);
  pinMode(Led32, OUTPUT);
  pinMode(Led33, OUTPUT);
  pinMode(Led34, OUTPUT);



}

void loop() {
  m_timer();
  
  for (int i = 22; i <= 37; i+=2) {
    digitalWrite(i, HIGH);
    int y=i+1;
    digitalWrite(y, HIGH);
    delay(20);
    digitalWrite(i, LOW);    
    digitalWrite(y, LOW);
    delay(10);

  }    

   delay(300);
}
