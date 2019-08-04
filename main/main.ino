
#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal


void setup() {
  Serial.begin(9600);
  init_blink();
  init_timer();
  init_trigger();
  //init_dimmer();
 
}

void loop() {
  //m_timer();
  m_blink(true,true);
  m_trigger();
  //m_dimmer();
}
