#include <mega32.h>
#include <delay.h>

void main(void)
{
    unsigned char minutes, seconds;
    unsigned char persistence_loop;
    unsigned char digits[4];

    //  Bit 7 (0x80) is the Decimal Point
    unsigned char segment_map[10] = {
        ~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07, ~0x7F, ~0x6F};

    DDRA = 0xFF;
    DDRB = 0xFF;

    while (1)
    {
        // Outer loop for minutes (0-59)
        for (minutes = 0; minutes < 60; minutes++)
        {
            // Inner loop for seconds (0-59)
            for (seconds = 0; seconds < 60; seconds++)
            {
                // Extract digits for display
                digits[0] = minutes / 10;
                digits[1] = minutes % 10;
                digits[2] = seconds / 10;
                digits[3] = seconds % 10;
                for (persistence_loop = 0; persistence_loop < 5; persistence_loop++)
                {
                    // Multiplexing logic (with wire swap fix)
                    PORTB = ~0x01;
                    PORTA = segment_map[digits[2]]; // Tens of seconds
                    delay_ms(5);

                    // Display hundreds digit (tens of minutes) WITH decimal point
                    PORTB = ~0x02;
                    PORTA = segment_map[digits[1]] & ~0x80; // Turn ON DP by clearing bit 7
                    delay_ms(5);

                    PORTB = ~0x04;
                    PORTA = segment_map[digits[0]]; // Thousands digit (minutes)
                    delay_ms(5);

                    PORTB = ~0x08;
                    PORTA = segment_map[digits[3]]; // Units of seconds
                    delay_ms(5);
                }
            }
        }
    }
}