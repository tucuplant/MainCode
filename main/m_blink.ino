unsigned long blink_preTimeStep = 0, blink_curTimeStep = 0, blink_preTimeOn = 0, blink_curTimeOn = 0;
const long blink_stepInterval = 60, blink_onInterval = blink_stepInterval * 8;
int blink_i = 22, blink_y = blink_i + 1;
int blink_blur = 3; //MAX blur=4
bool blink_power = false;
/*------ */

void m_blink(bool w, bool r)
{

    blink_curTimeStep = millis();
    blink_curTimeOn = millis();

    if (blink_curTimeOn - blink_preTimeOn >= blink_onInterval)
    {
        if (!blink_power)
            blink_power = true, blink_i = 22;
        else
            blink_power = false;
        blink_preTimeOn = blink_curTimeOn;
    }

    if (blink_power && (blink_curTimeStep - blink_preTimeStep >= blink_stepInterval))
    {

        if (w)
            digitalWrite(blink_i, HIGH), digitalWrite(blink_i - blink_blur + 1, LOW);
        else
            digitalWrite(blink_i, LOW);

        if (r)
            digitalWrite(blink_y, HIGH), digitalWrite(blink_y - blink_blur + 1, LOW);
        else
            digitalWrite(blink_y, LOW);

        /**Si quitas el LOW, lo mantiene encendido, barra de carga */
        //digitalWrite(i, LOW);
        //digitalWrite(i, LOW);
        blink_i += 2;
        blink_y = blink_i + 1;

        if (blink_i > 37)
            blink_i = 22, blink_y = blink_i + 1;

        blink_preTimeStep = blink_curTimeStep;
    }
}

void init_blink()
{
    for (unsigned i = 22; i < 34; i++)
        pinMode(i, OUTPUT);
}
