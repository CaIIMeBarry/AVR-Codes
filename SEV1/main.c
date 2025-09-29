#include <mega32.h>
#include <delay.h>
unsigned char bts[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char i,y,d;

void main(void)
{
 DDRA=0xff;
 DDRB=0xff;
 PORTB=0xff;
while (1)
    {
     //-------Digit 1 ---------
      PORTA=bts[1];
      PORTB.1=0;
      delay_ms(15);
      PORTB.1=1;
     //-------Digit 2 ---------
      PORTA=bts[2];
      PORTB.2=0;
      delay_ms(15);
      PORTB.2=1;
     //-------Digit 3 ---------
      PORTA=bts[3];
      PORTB.3=0;
      delay_ms(15);
      PORTB.3=1;
     //-------Digit 4 ---------
      PORTA=bts[4];
      PORTB.4=0;
      delay_ms(15);
      PORTB.4=1;


    }
}
