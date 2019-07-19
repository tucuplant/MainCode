
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
  init_blink();
  init_timer();
  

  pinMode(9, OUTPUT);

}

void loop() {
  m_timer();
  m_blink(true,true);
  
   

   //delay(100);
}
