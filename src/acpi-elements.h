#ifndef __ACPI_ELEMENTS_H
#define __ACPI_ELEMENTS_H

#include "types.h"

typedef int (*contained_acpi_elem)(char **data, int length,
                                   void *opaque);

int acpi_add_Device(char **data, int dlen, char *name,
                    contained_acpi_elem e, void *opaque);

int acpi_add_Name(char **data, int dlen, char *name,
                  contained_acpi_elem e, void *opaque);

int acpi_add_Method(char **data, int dlen, char *name, u8 flags,
                    contained_acpi_elem e, void *opaque);

/* Pass in a pointer to a u64 */
int acpi_add_Integer(char **data, int dlen, void *val);

/* Pass in a pointer to a string */
int acpi_add_EISAID(char **data, int dlen, void *val);

int acpi_add_BufferOp(char **data, int dlen,
                      contained_acpi_elem e, void *opaque);

/* Pass in a pointer to a u64 */
int acpi_add_Return(char **data, int dlen, void *);

/*
 * Note that str is void*, not char*, so it can be passed as a
 * contained element.
 */
int acpi_add_Unicode(char **data, int dlen, void *vstr);

int acpi_add_IO16(char **data, int dlen,
                  u16 minaddr, u16 maxaddr, u8 align, u8 range);

#define ACPI_RESOURCE_PRODUCER 0
#define ACPI_RESOURCE_CONSUMER 1
#define ACPI_INTERRUPT_MODE_LEVEL 0
#define ACPI_INTERRUPT_MODE_EDGE  1
#define ACPI_INTERRUPT_POLARITY_ACTIVE_HIGH 0
#define ACPI_INTERRUPT_POLARITY_ACTIVE_LOW  1
#define ACPI_INTERRUPT_EXCLUSIVE      0
#define ACPI_INTERRUPT_SHARED         1
#define ACPI_INTERRUPT_EXCLUSIVE_WAKE 2
#define ACPI_INTERRUPT_SHARED_WAKE    3

int acpi_add_Interrupt(char **data, int dlen, u32 irq,
                       int consumer, int mode, int polarity, int sharing);

int acpi_add_EndResource(char **data, int dlen);

#endif
