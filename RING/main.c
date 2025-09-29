#include <mega32.h>
#include <delay.h>
signed char i=9;
void main(void)
{
 DDRA=0xff;
 DDRC=0xfc; //0b11111100
while (1)
    {
      PORTA=i;
      delay_ms(400); 
      i--;
      if(i==-1) i=9;
    }
}
