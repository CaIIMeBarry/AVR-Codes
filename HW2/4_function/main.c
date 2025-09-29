#include <mega32.h>
#include <delay.h>

void main(void)
{
    unsigned char a = 0;
    unsigned char b = 0;
    char step = 0;
    unsigned char c = 0;
    unsigned char d = 0;

    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRC = 0xFF;
    DDRD = 0xFF;

    while (1)
    {

        PORTA = a;
        delay_ms(50);
        a <<= 1;
        if (a == 0)
        {
            a = 0x01;
        }
    ////////////////////////////////////////////
        if (step < 8)
        {
            b = (b << 1) | 0x01;
        }
        else
        {
            b = (b << 1);
        }

        PORTB = b;
        delay_ms(50);
        step++;
        if (step == 16) step = 0;
    ////////////////////////////////////////////
        PORTC = c;
        c++;
        delay_ms(50);
    ///////////////////////////////////////////
        PORTD = d;
        d--;
        delay_ms(50);
    }
}


