#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "I2S.h"
#include "sinus.h"





void setup()
{
    WiFi.forceSleepBegin();
    delay(1);
    system_update_cpu_freq(160);
    i2s_begin();
    i2s_set_rate(44100);
    
}

uint8_t phase = 0;

void loop()
{
    writeDAC(0x8000 + sinus[phase]);
    phase++;
}


uint32_t acc;
uint16_t err;

void writeDAC(uint16_t value)
{
    for (uint8_t i = 0; i < 32; i++)
    {
        acc = acc << 1;
        if (value >= err)
        {
            acc |= 1;
            err += 0xFFFF - value;
        }
        else
        {
            err -= value;
        }
    }
    i2s_write_sample(acc);
}
