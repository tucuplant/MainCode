unsigned long preTimeStep = 0, curTimeStep = 0, preTimeOn = 0, curTimeOn = 0;
const long stepInterval = 60, onInterval = stepInterval * 8;
int i = 22, y = i + 1;
int blur = 3; //MAX blur=4
bool power = false;
/*------ */
void m_blink(bool w, bool r)
{

    curTimeStep = millis();
    curTimeOn = millis();

    if (curTimeOn - preTimeOn >= onInterval)
    {
        if (!power)
            power = true, i = 22;
        else
            power = false;
        preTimeOn = curTimeOn;
    }

    if (power && (curTimeStep - preTimeStep >= stepInterval))
    {

        if (w)
            Serial.print("W : "), Serial.println(i), digitalWrite(i, HIGH), digitalWrite(i - blur+1, LOW);
        else
            digitalWrite(i, LOW);

        if (r)
            Serial.print("R : "), Serial.println(y), digitalWrite(y, HIGH), digitalWrite(y - blur+1, LOW);
        else
            digitalWrite(y, LOW);

        /**Si quitas el LOW, lo mantiene encendido, barra de carga */
        //digitalWrite(i, LOW);
        //digitalWrite(i, LOW);
        i += 2;
        y = i + 1;

        if (i > 37)
            i = 22, y = i + 1;

        preTimeStep = curTimeStep;
    }

    /* for (int i = 22; i <= 37; i += 2)
    {
        if (w)
            digitalWrite(i, HIGH);

        int y = i + 1;
        if (r)
            digitalWrite(y, HIGH);

        if (curTime - preTime >= 20)
        {
            digitalWrite(i, LOW);
            digitalWrite(y, LOW);
            preTime = curTime;
        }
        //delay(10);
    }*/
}

void init_blink()
{
    pinMode(Led23, OUTPUT);
    pinMode(Led24, OUTPUT);
    pinMode(Led25, OUTPUT);
    pinMode(Led26, OUTPUT);
    pinMode(Led27, OUTPUT);
    pinMode(Led28, OUTPUT);
    pinMode(Led29, OUTPUT);
    pinMode(Led30, OUTPUT);
    pinMode(Led31, OUTPUT);
    pinMode(Led32, OUTPUT);
    pinMode(Led33, OUTPUT);
    pinMode(Led34, OUTPUT);
}
