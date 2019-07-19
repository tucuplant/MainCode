#include <DS3231.h>
DS3231 rtc(SDA, SCL);
int timer_num_intervalos = 3;
bool onTime[timer_num_intervalos];
int timer_intervalos[timer_num_intervalos][2];

bool getOntime(int i)
{
  if (i < onTime.size())
  {
    int hora = rtc.getTime().hour;

    if ((hora > timer_num_intervalos[i][0] && hora < timer_num_intervalos[i][1]))
      onTime[i] = true;
    else
      onTime[i] = false;
  }

  return onTime[i];
}

void m_timer()
{
  //Serial.println(rtc.getTimeStr());
  //handleIntervalo(rtc.getTime().hour);
  /*if(onTime==true){
      //lcd.print("Encendido");
      if(digitalRead(9) == LOW)
      digitalWrite(9, HIGH);//LUZ ENCENDIDA
    }else if(onTime==false){
      //lcd.print("Apagado");
      if(digitalRead(9) == HIGH)
      digitalWrite(9, LOW);//LUZ ENCENDIDA
    }*/
}

void init_timer()
{
  for (unsigned i = 0; i < onTime; i++)
    onTime[i] = false;

  //timer_num_intervalos tiene que ser igual al numero de intervalos
  timer_intervalos[0] = {8, 21};  //luz
  timer_intervalos[1] = {7, 12};  //oxi
  timer_intervalos[2] = {18, 22}; //oxi

  rtc.begin();
}