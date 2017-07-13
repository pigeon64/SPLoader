/*
** File: loader/i386-pc/timer/timer.c
**
** Author: Brennan Ringey
**
*/

#include <SPLoader/timer/timer.h>
#include <SPLoader/err.h>

#include <SPLoader/i386-pc/idt/isr.h>
#include <SPLoader/i386-pc/pit.h>
#include <SPLoader/i386/io.h>
#include <SPLoader/i386/x86arch.h>

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CLOCK_FREQ 1000


static void __timer_isr(int vector, int code);

static bool _timer_enabled;
static unsigned _tickTotal;
static unsigned _ticks;
static TimerCallback _callback;

int timer_init(void) {
    _timer_enabled = false;
    _tickTotal = 0;
    _ticks = 0;
    _callback = NULL;

    // disable PIT timer 0 by setting it to one-shot mode
    __outb(PIT_CONTROL_PORT, PIT_0_SELECT | PIT_MODE_1);


    isr_install(INT_VEC_TIMER, __timer_isr, NULL);
    return E_SUCCESS;
}


int timer_start(TimerCallback callback) {
    if (callback == NULL) {
        return E_ARGNULL;
    }

    _timer_enabled = true;
    _ticks = 0;
    _tickTotal = 0;
    _callback = callback;

    // start PIT timer 0
    uint32_t divisor = PIT_FREQUENCY / CLOCK_FREQ;
    __outb(PIT_CONTROL_PORT, PIT_0_LOAD | PIT_0_SQUARE);
    __outb(PIT_0_PORT, divisor & 0xFF);
    __outb(PIT_0_PORT, (divisor >> 8) & 0xFF);

    return E_SUCCESS;
}

int timer_stop(void) {
    _timer_enabled = false;

    // stop PIT timer 0 by setting it to one-shot mode
    __outb(PIT_CONTROL_PORT, PIT_0_SELECT | PIT_MODE_1);

    return E_SUCCESS;
}


void __timer_isr(int vector, int code) {
    (void)vector; (void)code;

    if (_timer_enabled) {
        ++_tickTotal;
        if (++_ticks == CLOCK_FREQ) {
            _callback(_tickTotal);
            _ticks = 0;
        }
    }

    __outb(PIC_MASTER_CMD_PORT, PIC_EOI);
}