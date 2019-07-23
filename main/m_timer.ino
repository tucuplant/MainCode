#include <DS3231.h>
DS3231 rtc(SDA, SCL);
const int timer_num_intervalos = 3;
int timer_intervalos[timer_num_intervalos][3];

bool timer_getOnTime(int num_t)
{
  if (num_t < timer_num_intervalos)
  {
    int timer_hora = rtc.getTime().hour;
    if (timer_hora == 0 && timer_intervalos[num_t][1] == 24)
      timer_hora = 24;

    /*Serial.print("Check if ");
    Serial.print(timer_hora);
    Serial.print(" is bewtween ");
    Serial.print(timer_intervalos[num_t][0]);
    Serial.print(" and ");
    Serial.println(timer_intervalos[num_t][1]); */

    if ((timer_hora >= timer_intervalos[num_t][0] && timer_hora <= timer_intervalos[num_t][1]))
      return true;

    else
      return false;
  }
}

int timer_getGate(int i)
{
  return timer_intervalos[i][2];
}

bool timer_gateIsOnTime(int g)
{

  Serial.print("Check gate ");
  Serial.println(g);
  for (unsigned i = 0; i < timer_num_intervalos; i++)
  {

    Serial.print(" with interval  ");
    Serial.println(i);

    if (timer_getOnTime(i) && timer_intervalos[i][2] == g)
    {
      Serial.println("--its on time--");
      return true;
    }
  }
  Serial.println("--not in time--");
  return false;
}

void m_timer()
{
}

void init_timer()
{
  /*
  timer_num_intervalos tiene que ser igual al numero de intervalos
    -Cuando añadas un intervalo nuevo, asegurate de incrementar timer_num_intervalos y aqui abajo 
    Por ejemplo el siguiente seria timer_intervalos[3][x]... y timer_num_intervalos seria 4.
    -Las 12pm en el menor son las 0 y en el mayor son las 24.
  */
  timer_intervalos[0][0] = 19, timer_intervalos[0][1] = 19, timer_intervalos[0][2] = 0; //luz
  timer_intervalos[1][0] = 16, timer_intervalos[1][1] = 16, timer_intervalos[1][2] = 1; //oxi
  //Esto seria tol puto dia
  timer_intervalos[2][0] = 20, timer_intervalos[2][1] = 20, timer_intervalos[2][2] = 1; //oxi

  rtc.begin();
}