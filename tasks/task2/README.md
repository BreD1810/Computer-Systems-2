# Task 2 - Display Driver

For this task you are required to do the following:
1. Download the archive with the skeleton code linked on the notes page.
2. Use the provided makefile to compile the code.
3. Run the executable built from the skeleton code. You will notice that `display.string()` ignores newline control codes included in its arguement.
4. Modify `display.char()` found in ./lcd/lcd.c such that:
   * a newline control character starts a new line, and
   * at the end of the display a newline control character also clears the screen.
5. Modify `lcd.usage-sample.c` so that it demonstrates the above functionality.

## Extra Work
Instead of clearing the screen when it is full, scroll all text on the display up to free up a line at the bottom of the display. You can find hints on how to do this flicker-free in the pong game code that is available on the notes page's 'Preview Material' section.