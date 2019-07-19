#include <DS3231.h>
DS3231 rtc(SDA, SCL);
const int timer_num_intervalos = 3;
bool timer_onTime[timer_num_intervalos];
int timer_intervalos[timer_num_intervalos][2];

bool getOntime(int i)
{
  if (i < sizeof(timer_onTime))
  {
    int timer_hora = rtc.getTime().hour;

    if ((timer_hora > timer_intervalos[i][0] && timer_hora < timer_intervalos[i][1]))
      timer_onTime[i] = true;
    else
      timer_onTime[i] = false;
  }

  return timer_onTime[i];
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
  for (unsigned i = 0; i < sizeof(timer_onTime); i++)
    timer_onTime[i] = false;

  //timer_num_intervalos tiene que ser igual al numero de intervalos
  timer_intervalos[0][0] = 8,timer_intervalos[0][1] = 21,  //luz
  timer_intervalos[1][0] = 7,timer_intervalos[0][1] = 12,  //oxi
  timer_intervalos[1][0] = 18,timer_intervalos[0][1] = 22, //oxi

  rtc.begin();
}