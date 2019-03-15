# Task 5: FAT File System and "FortunaOS"

We are now at a stage where we can combine the code of the previous exercises with an adaptation of [ChanNsFAT File System](http://irtos.sourceforge.net/FAT32_ChaN/doc/00index_e.html) Implementation to build a small operating system for our LaFortuna. The skeleton code on the notes page combines:

* Peter Dannegger's code for the rotary encoder.
* Peter Dannegger's code for switch debouncing.
* Steve Gunn's display driver.
* The RIOS scheduler
* ChanNs FAT file system.

Only one 8-bit timer (Timer 0) is occupied and serves dual purpose: timer over-flows provide the ticks for the preemptive scheduler and the adjustable compare match output of the timer is used to control the brightness of the LED by pulse-width-modulation (PWM). Scanning the rotary encoder and scanning the switches are tasks handed to the scheduler.

The purpose of this excise is to become familiar with the implementa- tion of the FAT on a microcontroller, so you could use it for reading configuration files or to log some information. For this task you are required to do the following:

1. Download the archive with the skeleton code linked on the notes page.
2. Investigate `sample_main.c` to get an overview of what the code will do.
3. Run the code and make it write to the SD card. (If you cannot read the SD card with your computer to investigate whether the write succeeded, you need to trust the messages on the display at this stage.)
4. Write your own code to read the last 25 lines of a text file and write them to the display.
5. Trigger your code with one of the button events.
6. Test your implementation: Write additional positions to the file with functionality provided by the skeleton code, then trigger your code to show the most recent additions to the file.

Please note that some SD cards draw a lot of current when they are first connected (to charge internal capacitors), if your card is not recognized, try to reinsert it. If you experience problems with your card, please report your findings on the Wiki. (See also: https://secure.ecs.soton.ac.uk/student/wiki/w/COMP2215_1617_SDCardGlitch)

## Extra Work
Read the directory from the SD card. Display a file list (Feel free to limit the number of entries to something that fits on the display) and allow for the selection of the file to be made with the scroll wheel. Then display the tail of that fail as above