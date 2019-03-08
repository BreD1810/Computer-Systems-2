#ifndef _EEPROMFS_
#define _EEPROMFS_

#include <avr/eeprom.h>
#include <stdint.h>

#define BLOCK_SIZE 64
#define MAX_FILES 
#define EEPROM_LENGTH 
#define EEPROM_START 
#define TOTALBLOCKS = EEPROM_LENGTH/BLOCK_SIZE

/*For each file, record the start, the length of the file,
  and the current position within the file.*/
typedef struct entry
{
    uint8_t startBlock;
    uint16_t fileLength;
    uint16_t currentPosition;
} directoryEntry;

typedef struct fs_meta
{
    directoryEntry dir[MAX_FILES]; /
} metaData;

void init_eepromfs();
void open_for_write(uint8_t fileName);
void open_for_append(uint8_t fileName);
void open_for_read(uint8_t fileName);
void close(uint8_t fileName);
void write(uint8_t fileName, uint8_t* buffer, uint16_t noOfBytes);
uint16_t read(uint8_t fileName, uint8_t* buffer, uint16_t noOfBytes);
void delete_file(uint8_t fileName);

#endif //_EEPROMFS_