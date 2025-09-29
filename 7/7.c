#include <delay.h>
#include <mega32.h>

void main(void)
{
char a=0;
signed char b=9;
DDRA = 0xff;
DDRB = 0xff;
while (1)
    {
     PORTA = a;
     PORTB = b;
     delay_ms(400);
     a++;
     b--;
     if (a>9)
     {
        a=0;
     }
     if(b<0)
     {
        b=9;
     }
    }
}
