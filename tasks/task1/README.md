# Task 1 - Rotary Encoder

This task will introduce you to GPIO and interrupts. You we will use the incremental rotary encoder wheel to change the blink frequency of the LED. Reading a rotary encoder correctly and reliably is not trivial.  The skeleton code therefore contains the excellent solution provided by Peter Dannegger. You can focus on setting up the timer interrupt.

For this task you are required to do the following:

1. Download the skeleton code
2. Consult the circuit schematics for the LaFortuna Board and figure out on which pins the A and B phase of the rotary encoder are connected.
3. Enable these pins as inputs with pull-ups in the initialization code.
4. Set up timer 0 for 1 ms timer interrupts:  it is partly set up already, you need to set the interval and enable the interrupt for COMPA.
5. Globally enable interrupts after the initialization and before the main loop (see the avr-libc commands for this).
6. To find out what the macros (as a convention in C they are always written with capitals) in the skeleton code mean, look for them with the search function of your PDF reader in the datasheet of the AT90USB1286 available on the notes page

## Extra Work
Animate the change in blinking speed with dynamics, to give the impression of momentum.  E.g., if the dial was moved fast, then increase the steps with which changes are made (acceleration). Experiment with different levels of friction and momentum. More fancy physics simulations are possible: there could be endpoints with some bounce, the feeling of throwing something in a viscose medium, stretching, etc.  You can also enhance the animation by changing the duty cycle (on time vs.  off time) of the LED in addition to its frequency.  This can be done at low frequency (visible duty cycle) and at high frequency (brightness change).