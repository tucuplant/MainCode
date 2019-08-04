
int trigger_gates[]={8,9};


void m_trigger()
{
    for (unsigned i = 0; i < (sizeof(trigger_gates)/sizeof(trigger_gates[0])); i++)
    {

        if (timer_gateIsOnTime(i))
        {
            //lcd.print("Encendido");
            if (digitalRead(trigger_gates[i]) == LOW)
                digitalWrite(trigger_gates[i], LOW);
                digitalWrite(trigger_gates[i], HIGH);
        }
        else
        {
            //lcd.print("Apagado");
            if (digitalRead(trigger_gates[i]) == HIGH)
                digitalWrite(trigger_gates[i], HIGH);
                digitalWrite(trigger_gates[i], LOW);
        }
    }
}

void init_trigger()
{
    for (unsigned i = 0; i < (sizeof(trigger_gates)/sizeof(trigger_gates[0])); i++)
        pinMode(trigger_gates[i], OUTPUT); //luz
}