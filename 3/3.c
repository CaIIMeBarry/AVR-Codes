#include <delay.h>
#include <mega32.h>
void main(void)
{
char y=0;
char d=0;
char s=0;
char h=0;
DDRB = 0xff;
DDRA = 0xff;
DDRC = 0xff;
DDRD = 0xff;


while (1)
    {
      PORTA = y;
      PORTB = d;
      PORTC = s;
      PORTD = h;
      delay_ms(2);
      y++;
      if (y>9)
      {
        y=0;
        d++;
        if (d>9)
        {
        s++;
        d=0;
        if(s>9)
            {
             h++;
             s=0;
             if(h>9)
             {
             h=0;
             }

            }

        }
      }


    }
}
