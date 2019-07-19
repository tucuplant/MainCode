#include <DS3231.h>
DS3231 rtc(SDA, SCL);
bool ontime;
int compiled_time[3];

void handleIntervalo(int hora){
   if((hora<22 && hora>7)){
    ontime=true;
    }else {
    ontime=false;
  }
}

void m_timer(){
    //Serial.println(rtc.getTimeStr());
    handleIntervalo(rtc.getTime().hour);  
    if(ontime==true){
      //lcd.print("Encendido");
      if(digitalRead(9) == LOW)
      digitalWrite(9, HIGH);//LUZ ENCENDIDA
    }else if(ontime==false){
      //lcd.print("Apagado");
      if(digitalRead(9) == HIGH)
      digitalWrite(9, LOW);//LUZ ENCENDIDA
    }
}

void init_timer(){
  rtc.begin();
}