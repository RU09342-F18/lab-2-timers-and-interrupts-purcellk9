# Button Based Delay
This was done on two different boards, the MSP430G2553 and the MSP430FR2311.This part of the lab the task was to have an LED blink at a rate corresponding to how long a button was pressed. For example, holding the button for 5 seconds will casuse the LED blinks once every 5 seconds.

This was done by initially having the LED blink at a specified rate then would change on the interrupt, button press. When the button was pressed the interrupt begins and a timer begins to count the amount of time it is held down for, then once the button is released the timer turns off and the time is stored, timer is reset, set back to up mode from contniuous mode of counting the time, the interrupt flags are reset as well. At this time the LED blinks at the rate corresponding to the length of time the button was pressed for

# Inputs and Outputs
MSP430G2553:
Inputs: 
volatile unsigned int t1 = 0;                // record timer at button press
volatile unsigned int t2 = 1000;             // record timer at button release
volatile unsigned int c1 = 0;                // record number at button press
volatile unsigned int c2 = 0;                // record number at button release
volatile unsigned int Ccount = 0;            // count every cycle of the timer
volatile unsigned int b = 0;                 // keeps track of up/down mode for the button
P1.3 Button
Outputs:
P1.0 LED

MSP430FR2311:
Inputs:
P1DIR &= ~BIT1;                         // configure P1.1 as input (Button)
volatile unsigned int i;                // volatile to prevent optimization
int a = 1;                              // blink speed state: 0 - off, 1 - slow, 2 - medium, 3 - fast
int b = 0;                              // counter to set blink interval - waits to reach x
int c = 8;                              // blink interval - the higher the slower the blink
int d;
Outputs:
P1DIR |= 0x01;                          // Set P1.0 to output direction (LED)
