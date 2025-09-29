#include <delay.h>
#include <mega32.h>
void main(void)
{
char y=0;
char d=0;

DDRB = 0xff;
DDRA = 0xff;


while (1)
    {
      PORTA = y;
      PORTB = d;
      delay_ms(50);
      y++;
      if (y>9)
      {
        y=0;
        d++;
        if (d>9)
        {
        d=0;
        }
      }


    }
}
