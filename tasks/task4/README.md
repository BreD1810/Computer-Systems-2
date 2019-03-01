# Task 4: EEPROM File System

If nonvolatile memory needs to be allocated dynamically it is often convenient to do so through a file abstraction. In this task you will develop a minimal file system that manages space in the EEPROM.

You are not provided with skeleton code - so plan before starting to code:

* your approach
* your data structures
* your application interface
  
For this task you are reuqired to design and implement a tiny file system that supports the following:

1. Several files named by integers
2. Provides a function to `open_for_write` a file, which creates it if it does not exist and sets its length to zero.
3. Provides a function to `open_for_append` a file, which creates it if it does not exist and otherwise preserves existing data in the file.
4. Provides a function to `open_for_read` that will fail if the file does not exist or is already open.
5. Provides a function to close a file that will make any changes to the file become persistent.
6. Provides a function to write a given number of bytes from a buffer to the file.
7. Provides a function to read a given number of bytes from a file. The function should return the number of bytes read, which may be less then requested in case the end of the file has been reached.
8. Provides a function to delete a file.
9. Your code should allow to define with constants:
    * the block size of your file system
    * the start address of the EEPROM memory available for the file system
    * the length of the memory available to the file system
    * the maximum number of files
10. Your code should handle errors sensibly. E.g., if there is no space left you can return an error, or you could use the existing file like a ring buffer and start overwriting from the beginning.

## 1 Implementation Hints
In addition to the functions above you probably need an `init_eepromfs` function that sets up your data structures. The main task of the file system is to break up the consecutive memory into blocks that can be allocated non-consecutively and to manage those blocks. That entails keeping track of free blocks and keeping track of the order of the blocks that belong to a file. Keep in mind that a file may not use all of the space in the blocks allocated to it, so you will need to keep track of the length of a file.

## 2 Extra Work
Embedded systems are often employed in harsh environments and a power failure can occure at any time. Insure that your file system cannot be corrupted in case the power fails during writing. If a write is terminated by brown out, it is acceptable that the data to be written is lost, however the file should be in the state it has been before the write operation started. this functionality is best integrated with a mechanism for wear levelling.