#include <mega32.h>
#include <delay.h>


void main(void)
{

    unsigned char x = 0;

    // --- Port Initializations ---

    // PORTA, PORTB, PORTC are not used, leave as default inputs.
    DDRA = 0x00;
    PORTA = 0x00;
    DDRB = 0x00;
    PORTB = 0x00;
    DDRC = 0x00;
    PORTC = 0x00;
    DDRD = 0x00;
    PORTD = 0x00;

    // --- USART Initialization (Transmitter) ---
    // Baud Rate: 1200 bps (assuming 1MHz internal clock)
    // 8 data bits, 1 stop bit, no parity.
    UCSRA = 0x00;
    // Enable Transmitter
    UCSRB = (1<<TXEN);
    // Set frame format: 8data, 1stop bit
    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
    // Set baud rate
    UBRRH = 0x00;
    UBRRL = 0x33; // For 1200 baud @ 1MHz clock

    // Main program loop
    while (1)
    {
        if(PIND.2 == 0)
        {
            if(x < 15)
            {
                x++;
            }
            while(PIND.2 == 0);
        }

        if(PIND.3 == 0)
        {

            if(x > 0)
            {
                x--;
            }
            while(PIND.3 == 0);
        }

        if(PIND.4 == 0)
        {

            //Wait for Register to be empty
            while (!(UCSRA & (1<<UDRE)));

            //Put data & send
            UDR = x;
            while(PIND.4 == 0);
        }
    }
}
