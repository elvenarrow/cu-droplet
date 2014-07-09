#ifndef power_h
#define power_h

#include <avr/io.h>
#include <avr/interrupt.h>
#include "RGB_LED.h"
#include "scheduler.h"
#include "delay_x.h"


#define FULL_BIT_DURATION 208 //duration of a bit at 300 baud, us.(increase delay by 6%)
#define HALF_BIT_DURATION 104 //half duration of a bit at 300 baud, us.
#define PROG_BUFFER_SIZE 64
#define PROG_BUFFER_CHECK_FREQ 10

volatile uint8_t prog_num_chars;
volatile char* prog_in_buffer;

void power_init(); //just calls cap_monitor and leg_monitor init
void cap_monitor_init();
void leg_monitor_init();
void programming_mode_init();
void print_prog_buffer();

uint8_t cap_status();			// Returns 0 if cap is within normal range ( 2.8V -- 5V ),
								//         1 if cap voltage is dangerously high ( > 5V )
								//         -1 if cap voltage is dangerously low ( < 2.8V )

int8_t leg_status(uint8_t leg);
int8_t leg1_status();			// Returns 0 if leg is floating,
int8_t leg2_status();			//         1 if leg is on power
int8_t leg3_status();			//         -1 if leg is on ground


int8_t legs_powered();

uint8_t light_if_unpowered(uint8_t r, uint8_t g, uint8_t b);

#endif
