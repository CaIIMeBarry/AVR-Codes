#include <mega32.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

char percent_str[4]; // String for "XXX%", needs 5 chars for "100%" + null
char bar_str[16];    // String for progress bar, needs 17 chars for 16 blocks + null

void main(void)
{
    int percent = 0;
    int i = 0;
    lcd_init(16);
    lcd_clear();

    while (1)
    {
        for (percent = 0; percent <= 100; percent++)
        {

            int bars;
            sprintf(percent_str, "%3d%%", percent);
            lcd_gotoxy(6, 0);
            lcd_puts(percent_str);
            ///////////////////////////
            bars = (percent * 16) / 100;

            for (i = 0; i < 16; i++)
            {
                bar_str[i] = (i < bars) ? 255 : ' ';
            }
            //bar_str[16] = '\0';
            lcd_gotoxy(0, 1);
            lcd_puts(bar_str);
            delay_ms(100);
        }
    }
}