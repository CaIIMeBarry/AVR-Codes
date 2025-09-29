#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <alcd.h>

void main(void)
{

    unsigned char received_value;
    char lcd_buffer[16];
    int i;
    DDRB = (1<<DDB7);
    PORTB = 0x00;
    DDRC = 0x00;
    DDRD = 0x00;

    // --- USART Initialization (Receiver) ---
    // Baud Rate: 1200 bps (assuming 1MHz internal clock)
    // 8 data bits, 1 stop bit, no parity.
    UCSRA = 0x00;
    // Enable Receiver
    UCSRB = (1<<RXEN);
    // Set frame format: 8data, 1stop bit
    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
    // Set baud rate
    UBRRH = 0x00;
    UBRRL = 0x33; // For 1200 baud @ 1MHz clock

    lcd_init(16);
    lcd_clear();
    lcd_puts("Waiting...");
    while (1)
    {
        //Wait for data
        while (!(UCSRA & (1<<RXC)));

        //Get received data from buffer
        received_value = UDR;
        sprintf(lcd_buffer, "Count: %d", received_value);
        lcd_clear();
        lcd_puts(lcd_buffer);
        for (i = 0; i < received_value; i++)
        {
            PORTB.7 = 1;
            delay_ms(100);
            PORTB.7 = 0;
            delay_ms(150);
        }
    }
}
