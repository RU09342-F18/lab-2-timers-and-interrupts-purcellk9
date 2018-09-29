
#include <msp430.h>

volatile unsigned int t1 = 0;                // record timer at button press
volatile unsigned int t2 = 1000;             // record timer at button release
volatile unsigned int c1 = 0;                // record number at button press
volatile unsigned int c2 = 0;                // record number at button release
volatile unsigned int Ccount = 0;            // count every cycle of the timer
volatile unsigned int b = 0;                 // keeps track of up/down mode for the button

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                   // Stop watchdog timer
    BCSCTL3 = LFXT1S_2;                         // Makes ACKL use internal oscillator
    P1DIR &= ~BIT3;                             // P1.3 as input (Button)
    P1IE |=  BIT3;                              // P1.3 interrupt enabled
    P1IES |= BIT3;                              // button high/low edge determined
    P1IFG &= ~BIT3;                             // flag cleared
    P1OUT &= ~BIT0;                             // green LED off to start
    P1DIR |= (BIT0 + BIT6);                     // Set green and red LED output
    TA0CCTL0 = CCIE;                            // TA0CCR0 interrupt enabled
    TA0CCR0 = 5000;                             // set interrupt value of TA0CCR0
    TA0CTL = TASSEL_1 + MC_1;                   // enable ACLK

  __enable_interrupt();                         // Enable the interrupt
}

#pragma vector=PORT1_VECTOR                     // Interrupt when button is pressed and released
__interrupt void Port_1(void)
{
    P1IFG &= ~BIT3;                             // P1.3 IFG cleared
    if(!b)                                      // true when button is pressed
    {
        t1 = TA0R;                              // record timer at button press
        c1 = Ccount;                        // record cycle number at button press
    }
    else                                        // else when button is released
    {
        t2 = TA0R;                                   // record timer at button release
        c2 = Ccount;                                 // record cycle number at button release
        TA0CCR0 = ((2 + ((c2 - c1)*TA0CCR0)) - t1);  // set CCR0
    }
    P1IES ^= BIT3;                                   // Toggle High/low edge
    b ^= 1;                                          // Toggle x to keep track of button up/down
}

#pragma vector=TIMER0_A0_VECTOR                 // Interrupt when Timer hits TA0CCR0
__interrupt void Timer_A(void)
{
    P1OUT ^= BIT0;                              // P1.0 LED toggle
    Ccount++;                                   // Counts Number timer cycles since start
}
