/*
** File: include/loader/err.h
**
** Author: bringey
**
** Contains macros for error codes used throughout the loader source.
**
*/

#ifndef _LOADER_ERR_H
#define _LOADER_ERR_H


//
// Success, no error
//
#define E_SUCCESS 0

//
// Generic error
//
#define E_FAILURE 1

//
// A passed argument was null
//
#define E_ARGNULL 2

//
// A passed argument is out of bounds
//
#define E_ARGBOUNDS 3

//
// An assertion check has failed
//
#define E_ASSERT 4


//
// Unable to allocate memory, no memory available
//
#define E_NOMEM 5

//
// Disk Errors (100-200)
//

// generic read error
#define E_DISK_READ 100

// ============================================================================
// EX_HEADER
// ============================================================================

#define E_HEADER_INVALID 1

#define E_HEADER_INTEGRITY 2

#define E_HEADER_LOADER_INTEGRITY 3

// ============================================================================
// EX_DISK_LABEL
// ============================================================================

#define E_DISK_LABEL_UNKNOWN                1
#define E_DISK_LABEL_UNSUPPORTED            2


//
// MBR exception codes (100-199)
//

// MBR contains an invalid signature (signature != 0xAA55)
#define E_MBR_SIGNATURE                     100
// MBR partitions overlap
#define E_MBR_PARTITION_OVERLAP             101

// GPT Exception codes (200-299)

// unsupported version
#define E_GPT_VERSION                       200
// incorrect crc32 checksum for header
#define E_GPT_HEADER_INTEGRITY              201
// incorrect crc32 checksum for partition table
#define E_GPT_PARTITION_INTEGRITY           202
// invalid header
#define E_GPT_HEADER_INVALID                203
// partition entry invalid
#define E_GPT_PARTITION_INVALID             204
// overlapping partitions
#define E_GPT_PARTITION_OVERLAP             205

#endif 