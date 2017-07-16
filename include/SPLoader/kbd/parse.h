
#ifndef _SPLOADER_KBD_PARSE_H
#define _SPLOADER_KBD_PARSE_H

#define KBD_PARSE_ERROR      2
#define KBD_PARSE_INCOMPLETE 1
#define KBD_PARSE_COMPLETE   0

#ifndef __ASM__

#include <SPLoader/kbd/ScancodePacket.h>
#include <SPLoader/kbd/KeyEvent.h>

int kbd_parse_set1(ScancodePacket *packet, KeyEvent *evt);

// int kbd_parse_set3(ScancodePacket *packet, KeyEvent *evt);

// int kbd_parse_set2(ScancodePacket *packet, KeyEvent *evt);

#endif  // __ASM__

#endif