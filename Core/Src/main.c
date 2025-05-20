#include "stm32g4xx.h"
#include <stdint.h>

#define MASK(x) ((unsigned char) (1<<(x)))

volatile uint32_t x;
volatile uint8_t sensor_data[SIZE];

int main(void) {

	for(x=0; x<SIZE; x++)
		sensor_data[x] = (uint8_t)x;

	while(1);
	return 0;
}
