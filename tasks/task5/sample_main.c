/* COMP2215 Task 5---SKELETON */

#include "os.h"

#define MAX_LINE_BUFF 50

int blink(int);
int update_dial(int);
int collect_delta(int);
int check_switches(int);
void appendFileWithPosition();
void printEndLines(uint8_t);


FIL File;                   /* FAT File */

int position = 0;



void main(void) {
    os_init();

    os_add_task( blink,            30, 1);
    os_add_task( collect_delta,   500, 1);
    os_add_task( check_switches,  100, 1);

    sei();
    for(;;){}

}


int collect_delta(int state) {
	position += os_enc_delta();
	return state;
}


int check_switches(int state) {

	if (get_switch_press(_BV(SWN))) {
		// display_string("North\n"); /* ORIGINAL CODE */
		printEndLines(25);
	}

	if (get_switch_press(_BV(SWE))) {
			display_string("East\n");
	}

	if (get_switch_press(_BV(SWS))) {
			display_string("South\n");
	}

	if (get_switch_press(_BV(SWW))) {
			display_string("West\n");
	}

	if (get_switch_long(_BV(SWC))) {
		appendFileWithPosition();
	}

	if (get_switch_short(_BV(SWC))) {
		display_string("[S] Centre\n");
	}

	if (get_switch_rpt(_BV(SWN))) {
		display_string("[R] North\n");
	}

	if (get_switch_rpt(_BV(SWE))) {
		display_string("[R] East\n");
	}

	if (get_switch_rpt(_BV(SWS))) {
		display_string("[R] South\n");
	}

	if (get_switch_rpt(_BV(SWW))) {
		display_string("[R] West\n");
	}

	if (get_switch_rpt(SWN)) {
		// display_string("[R] North\n"); /* ORIGINAL CODE */
	}


	if (get_switch_long(_BV(OS_CD))) {
		display_string("Detected SD card.\n");
	}

	return state;
}




int blink(int state) {
	static int light = 0;
	uint8_t level;

	if (light < -120) {
		state = 1;
	} else if (light > 254) {
		state = -20;
	}


	/* Compensate somewhat for nonlinear LED
           output and eye sensitivity:
        */
	if (state > 0) {
		if (light > 40) {
			state = 2;
		}
		if (light > 100) {
			state = 5;
		}
	} else {
		if (light < 180) {
			state = -10;
		}
		if (light < 30) {
			state = -5;
		}
	}
	light += state;

	if (light < 0) {
		level = 0;
	} else if (light > 255) {
		level = 255;
	} else {
		level = light;
	}

	os_led_brightness(level);
	return state;
}

void appendFileWithPosition()
{
		f_mount(&FatFs, "", 0);
		if (f_open(&File, "myfile.txt", FA_WRITE | FA_OPEN_ALWAYS) == FR_OK) {
			f_lseek(&File, f_size(&File));
			f_printf(&File, "Encoder position is: %d \r\n", position);
			f_close(&File);
			display_string("Wrote position\n");
		} else {
			display_string("Can't write file! \n");
		}
}

void printEndLines(uint8_t n)
{
	char line[n][MAX_LINE_BUFF]; //2d array to store 25 lines - to be used as a ring buffer.
	f_mount(&FatFs, "", 0);
		if (f_open(&File, "myfile.txt", FA_READ) == FR_OK) { //Open the file in read mode
			
			for (uint8_t i = 0; i < n; i++)
			{
				line[i][0] = '\0'; //Write the null character to each position to stop errors displaying string.
			}

			uint8_t i = 0;
			while (f_gets(line[i], MAX_LINE_BUFF, &File)) //Read until no more lines
			{
				i++;
				i %= n; //Get the remainder, aka reset to first position if reached the end.
			}
			
			//Display all of the files in the ring buffer array
			for (uint8_t j = 0; j < n; j++)
			{
				display_string(line[i++]);
				i %= n;
			}

			f_close(&File);
		} else {
			display_string("Can't write file! \n");
		}
}