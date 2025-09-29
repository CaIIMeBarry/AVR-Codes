#include <mega32.h>
#include <delay.h>
 unsigned char i=0;
void main() 
{ 
    
    DDRA = 0xFF;
    DDRD.2 = 0; 
    DDRD.3 =0;
    DDRB.0=0; 
    DDRD.7=1;
    while (1) 
    {  
       if(PIND.2==0)
    
       { 
         PORTA=i; 
         i++;
         PORTD.7=1;
         delay_ms(100);
       }
        if(PIND.3==0)
        {
        PORTA=i;
        i--; 
        delay_ms(100);
        PORTD.7=1;
        }
        if(PINB.0==0)
        {
        i=0;
        PORTA=0;
        PORTD.7=1;
        }
      }    
      }