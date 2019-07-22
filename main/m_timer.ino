#include <DS3231.h>
DS3231 rtc(SDA, SCL);
const int timer_num_intervalos = 3;
bool timer_onTime[timer_num_intervalos];
int timer_intervalos[timer_num_intervalos][3];

bool timer_getOnTime(int num_t)
{
  if (num_t < (sizeof(timer_onTime)/sizeof(timer_onTime[0])))
  {
    
    int timer_hora = rtc.getTime().hour;
    if ((timer_hora > timer_intervalos[num_t][0] && timer_hora < timer_intervalos[num_t][1]))
      timer_onTime[num_t] = true;
    else
      timer_onTime[num_t] = false;
  }

  return timer_onTime[num_t];
}

int timer_getGate(int i){
  return timer_intervalos[i][2];
}
int timer_getTimerOfGate(int i){
  return timer_intervalos[i][2];
}

bool timer_gateIsOnTime(int g){
 
   for (unsigned i = 0; i < timer_num_intervalos; i++)
  {
 
    if(timer_getOnTime(i)&&timer_intervalos[i][2]==g)
    return true;
    
  }
  return false;
}

void m_timer()
{
}

void init_timer()
{
  for (unsigned i = 0; i < (sizeof(timer_onTime)/sizeof(timer_onTime[0])); i++)
    timer_onTime[i] = false;

  //timer_num_intervalos tiene que ser igual al numero de intervalos
  timer_intervalos[0][0] = 1,timer_intervalos[0][1] = 21,timer_intervalos[0][2] = 0 ;//luz
  timer_intervalos[1][0] = 7,timer_intervalos[0][1] = 12,timer_intervalos[1][2] = 1 ;//oxi
  timer_intervalos[2][0] = 18,timer_intervalos[0][1] = 22,timer_intervalos[2][2] = 1 ;//oxi

  rtc.begin();
}