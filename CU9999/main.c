#include <mega32.h>
#include <delay.h>
unsigned char d=0,y=0;
int i,t;
void main(void)
{
 DDRA=0xff;
 DDRB=0xff; 

while (1)
    {
     for(i=0;i<100;i++)
     {
      d=i/10;
      y=i%10;
      PORTA=(d<<4)|y;
      delay_ms(100);
     } 
    
    }
}
