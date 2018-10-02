# TIMER A Blink
This was done on two different MSP430G2553 and the MSP432PR401R, this part of the lab the task was to have 2 LEDs toggling on and off at different speeds. This was done by using two timers and two CCR's (capture control registers), setting each CCR to a different speed (clock cylce). Where the CCR0 was calcuted by (32768/(Hz*3))-1

# Inputs/ Outputs
MSP430G2553:

Inputs:

int Hertz(int Hz)                         // Function that converts Hz to a CCR0 value

Outputs:

P1DIR |= BIT0;                       // Set green LED output

P1DIR |= BIT6;                       // Set red LED output

MSP432PR401R:

Inputs:

int Hertz(int Hz)                         // Function that converts Hz to a CCR0 value

OutPuts:

P1DIR |= BIT0;                              // Set red LED output

P2DIR |= BIT1;                              // Set green LED output
