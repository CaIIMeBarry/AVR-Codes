#include <delay.h>
#include <mega32.h>

void main(void) {
    int count = 0;
    char d,y,s,h;
    DDRB = 0xFF;
    DDRA = 0xFF;
    while (1) {

        h =  count / 1000;
        s = (count%1000)/100;
        d = (count%100)/10;
        y =  count%10;

        PORTA = (d << 4) | y;
        PORTB = (h << 4) | s;

        delay_ms(1);

        count++;
        if (count > 9999) {
            count = 0;
        }
    }
}