# Button Interrupt
This was done on two different boards, the MSP430G2553 and the MSP430F5529. This part of the lab the task was to switch the led that is on when the a button was pressed.  This was done by using interrupts, when the button was pressed the interrupt activates and switches to the LED that was previously not on and turns the one that was on off. Then the flag is cleared and waits until the button/interrupt coccurs again.

# Inputs/ Outputs
MSP430G2553

Inputs:

P1.3 Buttton

Outputs:

P1.0 (LED)

MSP430F5529

Inputs:

P1DIR |= BIT0;                            // Set P1.0 to output (red LED)

P2REN |= BIT1;                            // Set pull up resistor on 2.1
 

Outputs:

P1.0 (LED)
