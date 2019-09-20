#include <msp430g2452.h>
#define LED1_MASK 0x01
#define LED2_MASK 0x40

int dir = -1;
int max = 25000, min = 2000;
int led = 0x40;
int interval = 10000;
int press = 0;

void main(void)
{

    WDTCTL = WDTPW + WDTHOLD;       // Stop WDT
    CCTL0 = CCIE;                   // CCR0 interrupt enabled
    TACTL = TASSEL_2 + MC_1 + ID_3; // SMCLK/8, upmode
    CCR0 = 10000;                   // 12.5 Hz
    P1OUT &= 0x00;                  // Shut down everything
    P1DIR &= 0x00;
    P1DIR |= BIT0 + BIT6;  // P1.0 and P1.6 pins output the rest are input
    P1REN |= BIT3;         // Enable internal pull-up/down resistors
    P1OUT |= BIT3;         //Select pull-up mode for P1.3
    P1IE |= BIT3;          // P1.3 interrupt enabled
    P1IES |= BIT3;         // P1.3 Hi/lo edge
    P1IFG &= ~BIT3;        // P1.3 IFG cleared
    _BIS_SR(CPUOFF + GIE); // Enter LPM0 w/ interrupt
    while (1)              //Loop forever, we work with interrupts!
    {
    }
}

// Timer A0 interrupt service routine
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
{
    P1OUT ^= (LED1_MASK | LED2_MASK); // Toggle P1.0
    if (press)
        interval += 500 * dir;
    if (interval < min)
        interval = min;
    else if (interval > max)
        interval = max;
    CCR0 = interval;
}
// Port 1 interrupt service routine
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
    press = !press;
    if (!press)
        dir = -dir;
    P1IFG &= ~BIT3; // P1.3 IFG cleared
}