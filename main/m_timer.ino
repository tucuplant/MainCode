#include <DS3231.h>
DS3231 rtc(SDA, SCL);
const int timer_num_intervalos = 3;
int timer_intervalos[timer_num_intervalos][3];

bool timer_getOnTime(int num_t)
{
  if (num_t < timer_num_intervalos)
  { 
    int timer_hora = rtc.getTime().hour;
    if(timer_hora==0&&timer_intervalos[num_t][1]==24)
    timer_hora=24;

    Serial.print("---HOUR--->");
    Serial.println(timer_hora);

    if ((timer_hora >= timer_intervalos[num_t][0] && timer_hora <= timer_intervalos[num_t][1]))
      return true;
    else
     return false;
  }
}

int timer_getGate(int i){
  return timer_intervalos[i][2];
}

bool timer_gateIsOnTime(int g){
  
  Serial.print("Check gate ");
  Serial.println(g);
   for (unsigned i = 0; i < timer_num_intervalos; i++)
  {
 
  Serial.print(" with interval  ");
  Serial.println(i);

    if(timer_getOnTime(i)&&timer_intervalos[i][2]==g)
    return true,Serial.println("--its on time--");
    
  }

  Serial.println("--not in time--");
  return false;
}

void m_timer()
{
}

void init_timer()
{
  //timer_num_intervalos tiene que ser igual al numero de intervalos
  timer_intervalos[0][0] = 0,timer_intervalos[0][1] = 1,timer_intervalos[0][2] = 0 ;//luz
  timer_intervalos[1][0] = 0,timer_intervalos[0][1] = 0,timer_intervalos[1][2] = 1 ;//oxi
  timer_intervalos[2][0] = 7,timer_intervalos[0][1] = 12,timer_intervalos[2][2] = 1 ;//oxi

  rtc.begin();
}