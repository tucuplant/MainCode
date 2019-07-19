
#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal

void setup() {
  Serial.begin(9600);
  init_blink();
  init_timer();
  

  pinMode(9, OUTPUT);

}

void loop() {
  m_timer();
  m_blink(true,true);
}
