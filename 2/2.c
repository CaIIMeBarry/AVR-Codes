#include <mega32.h>
#include <delay.h>

void main(void)
{
    unsigned char i;
    unsigned char persistence_loop;
    unsigned char digits[4];
    unsigned char segment_map[10] = {~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07, ~0x7F, ~0x6F};

    DDRA = 0xFF;
    DDRB = 0xFF;

    while (1)
    {
        for (i = 0; i <= 99; i++)
        {
            unsigned char up_counter = i;
            unsigned char down_counter = 99 - i;
            digits[0] = down_counter / 10;
            digits[1] = down_counter % 10;
            digits[2] = up_counter / 10;
            digits[3] = up_counter % 10;

            for (persistence_loop = 0; persistence_loop < 5; persistence_loop++)
            {
                // Multiplexing logic (with wire swap fix)
                PORTB = ~0x01;
                PORTA = segment_map[digits[2]];
                delay_ms(5);

                PORTB = ~0x02;
                PORTA = segment_map[digits[1]];
                delay_ms(5);

                PORTB = ~0x04;
                PORTA = segment_map[digits[0]];
                delay_ms(5);

                PORTB = ~0x08;
                PORTA = segment_map[digits[3]];
                delay_ms(5);
            }
        }
    }
}