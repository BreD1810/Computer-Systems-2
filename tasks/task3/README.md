# Task 3 - Preemptive Scheduler

For this task you are required to do the following:

Download the archive with the skeleton code linked on the notes page.

1. Investigate the skeleton code to see the task set in the provided code.
2. Use the included Makefile or adapt your own makefile or script to build the skeleton code.
3. Run the code and observe the nesting of task executing when T1 preempts a lower priority task.
4. Modify the code such that the LED lights up whenever the CPU is idling.
5. Run the modified code and observe the idling pattern.
6. Change the code so that the task periods are harmonic (you can shorten, but not lengthen the periods).
7. Run the code with the harmonic task set: has the idling pattern changed?
8. Play with some different task sets to observe how the CPU load depends on task number, task period, and task duration.

## Extra Work
Instead of lighting up the LED when the process is idling, send it to sleep. Take a look at the avr-libc's support for power management and sleep modes to see how this can be accomplished.