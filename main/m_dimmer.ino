int pinmosfet = 7;
int photocellPin = 0;     
int photocellReading;


void level_light(){
    photocellReading = analogRead(photocellPin);
    
    Serial.print("Analog reading = ");
    Serial.print(photocellReading);
}

void m_dimmer(){
    level_light();

}



void init_dimmer(){
  pinMode(pinmosfet, OUTPUT);
  digitalWrite(pinmosfet, LOW);
}