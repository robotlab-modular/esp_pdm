#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "I2S.h"

void setup()
{
    // WiFi.forceSleepBegin();
    // delay(1);
    system_update_cpu_freq(160);
    i2s_begin();
    i2s_set_rate(44100);
}

void loop()
{
}

void writeDAC(uint16_t value)
{
    uint32_t acc;
    uint16_t err;

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
    bool flag = i2s_write_sample(acc);
}
