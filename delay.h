//
// delay.h  By AHD  1400.09.02
//

#include <chrono>
#include <thread>

#ifndef _delay_h_
#define _delay_h_

void delay_ms(unsigned int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));

}

void delay_us(unsigned int microseconds)
{
	std::this_thread::sleep_for(std::chrono::microseconds(microseconds));

}

#endif
