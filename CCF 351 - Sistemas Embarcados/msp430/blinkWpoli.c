#include <msp430g2452.h>
#define LED1_MASK 0x01
#define LED2_MASK 0x40
#define BUTTON BIT3 // Port 1.3
#define SEC 50000

int main(void)
{
    volatile int i = 0;
    int interval = 7;
    int dir = -1;
    int max = 15, min = 1;
    int press = 0;

    /* stop watchdog timer */
    WDTCTL = WDTPW | WDTHOLD;

    /* set P1 direction */
    P1DIR = LED1_MASK | LED2_MASK | ~BUTTON;

    // Button setup
    P1REN |= BUTTON; // resistor enabled

    for (;;)
    {

        if (!(P1IN & BUTTON) && !press)
        {
            dir = -dir;
            press = 1;
        }
        if (!(P1IN & BUTTON))
        {
            interval = interval + dir;
            if (interval > max)
            {
                interval = max;
            }
            else if (interval < min)
            {
                interval = min;
            }
        }
        else
        {
            press = 0;
        }

        // Enable RED LED
        /* toggle leds */
        P1OUT ^= (LED1_MASK | LED2_MASK);
        /* delay */
        for (i = 0; i < interval; i++)
        {
            __delay_cycles(SEC);
        }
    }
}
