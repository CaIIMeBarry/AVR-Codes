#include <mega32.h>
#include <delay.h>
unsigned char bts[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char h,s,d,y,k;
void main(void)
{
 DDRA=0xff;
 DDRC=0x3c;//0b00111100
 PORTC=0x00;
while (1)
    {
     y++;
     if(y==10)
     {
      y=0;
      d++;
      if(d==10)
      {
       d=0;
       s++;
       if(s==10)
       {
        s=0;
        h++;
        if(h==10) h=0;
        }}}
       for(k=0;k<50;k++)
       {
       //-------Digit 1 -------------
       PORTA=bts[h];
       PORTC.2=1;
       delay_ms(5);
       PORTC.2=0;
       //-------Digit 2 -------------
       PORTA=bts[s];
       PORTC.3=1;
       delay_ms(5);
       PORTC.3=0;
       //-------Digit 3 -------------
       PORTA=bts[d];
       PORTC.4=1;
       delay_ms(5);
       PORTC.4=0;
       //-------Digit 4 -------------
       PORTA=bts[y];
       PORTC.5=1;
       delay_ms(5);
       PORTC.5=0;
       } 
    }
}
