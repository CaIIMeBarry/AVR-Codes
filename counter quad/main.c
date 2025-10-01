#include <mega32.h>
#include <delay.h>

void main(void)
{
    unsigned char i = 0;  // memory for up&down counter
    unsigned char johnson_state = 0; // initial state for john
    unsigned char johnson_step = 0; // first or second half of johnson??
    unsigned char ring_state = 0x01;// initial state for ring
    char counter_mode = 0;
    // 0=idle   1=upward   2=downward  3=john  4=ring
    DDRA = 0xFF;
    DDRD = 0x00;

    PORTA = i;

    while (1)
    {
        if (counter_mode == 0) // idle
        {
            if (PIND.1 == 0)
            {   // upwarddddd
                counter_mode = 1;
                while(PIND.1 == 0);
            }
            else if (PIND.2 == 0)
            {   // downwardddd
                i = 255;
                counter_mode = 2;
                while(PIND.2 == 0);
            }
            else if (PIND.4 == 0)
            {   // johnnnnn
                johnson_state = 0;
                johnson_step = 0;
                counter_mode = 3;
                while(PIND.4 == 0);
            }
            else if (PIND.3 == 0)
            {   // ringggg
                ring_state = 0x01;
                counter_mode = 4;
                while(PIND.3 == 0);
            }
        }
        else if (counter_mode == 1)  //upward
        {
            if (PIND.2 == 0)
            {
                counter_mode = 2; //downward
                while(PIND.2 == 0);
                continue;
            }
            else if (PIND.4 == 0) //john
            {
                johnson_state = 0;
                johnson_step = 0;
                counter_mode = 3;
                while(PIND.4 == 0);
                continue;
            }
            else if (PIND.3 == 0)  //ring
            {
                ring_state = 0x01;
                counter_mode = 4;
                while(PIND.3 == 0);
                continue;
            }

            PORTA = i;
            i++;
            delay_ms(200);
        }
        else if (counter_mode == 2)//downward
        {
            if (PIND.1 == 0) //upward
            {
                counter_mode = 1;
                while(PIND.1 == 0);
                continue;
            }
            else if (PIND.4 == 0)  //john
            {
                johnson_state = 0;
                johnson_step = 0;
                counter_mode = 3;
                while(PIND.4 == 0);
                continue;
            }
            else if (PIND.3 == 0)  // ring
            {
                ring_state = 0x01;
                counter_mode = 4;
                while(PIND.3 == 0);
                continue;
            }

            PORTA = i;
            i--;
            delay_ms(200);
        }
        else if (counter_mode == 3)//john
        {
            if (PIND.1 == 0)
            {
                counter_mode = 1;
                while(PIND.1 == 0);
                continue;
            }
            else if (PIND.2 == 0)
            {
                counter_mode = 2;
                while(PIND.2 == 0);
                continue;
            }
            else if (PIND.3 == 0)
            {
                ring_state = 0x01;
                counter_mode = 4;
                while(PIND.3 == 0);
                continue;
            }

            if (johnson_step < 8) {
                johnson_state = (johnson_state << 1) | 0x01;
            } else {
                johnson_state = (johnson_state << 1);
            }

            PORTA = johnson_state;
            delay_ms(200);

            johnson_step++;
            if (johnson_step == 16)
            {
                johnson_step = 0;
            }
        }
        else if (counter_mode == 4) //ring
        {
            if (PIND.1 == 0)
            {
                counter_mode = 1;
                while(PIND.1 == 0);
                continue;
            }
            else if (PIND.2 == 0)
            {
                counter_mode = 2;
                while(PIND.2 == 0);
                continue;
            }
            else if (PIND.4 == 0)
            {
                johnson_state = 0;
                johnson_step = 0;
                counter_mode = 3;
                while(PIND.4 == 0);
                continue;
            }

            PORTA = ring_state; //ring_state = 0x01
            delay_ms(200);

            ring_state <<= 1; //shift

            if (ring_state == 0)
            {
                ring_state = 0x01; // all over again
            }
        }
    }
}