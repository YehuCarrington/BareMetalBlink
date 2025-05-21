#include <stdint.h>

// Memory-mapped registers

#define RCC_AHB2ENR    (*(volatile uint32_t*)0x4002104C) // Address found from Chapters 2 & 7 of the data sheet
#define GPIOA_MODER    (*(volatile uint32_t*)0x48000000) // Address found from Chapters 2 & 9 of the data sheet
#define GPIOA_ODR      (*(volatile uint32_t*)0x48000014) // Address found from Chapters 2 & 9 of the data sheet

void delay(volatile uint32_t t) {
    while (t--);
}

int main(void) {
    // Enable GPIOA clock (bit 0 in RCC_AHB2ENR)
    RCC_AHB2ENR |= (1 << 0);

    // Clear bits (The bits are cleared so we avoid unintentionally combining old data
    // This reads, go to the 10th position.
    // Shift the value 0b11, 10 places [0000110000000000], negate the value [1111001111111111]
    // This is our mask. It's known as an AND mask or a bit clear mask
    // And this value and the value inside of GPIOA_MODER [01001000000000000000000000000000]
    //													  [11111111111111111111001111111111]
    // The result is therefore 							  [01001000000000000000000000000000]
    // If those bits are already 0, the result is unchanged — which is what we want.
    GPIOA_MODER &= ~(3 << (5 * 2));
    GPIOA_MODER &= ~(3 << (1 * 2));

    // Set PA5 to general purpose output mode (01) as specified in the data sheet (chapter 9)
    // This reads, very much in the way it did before. in this case we want to set the specific bits in the field.
    // Shift the value 0b01, 10 places [0000010000000000]
    // This is our mask. Its's known as an OR mask or a bit set mask
    // OR this value with the values inside of GPIOA_MODER [01001000000000000000000000000000]
    //													   [00000000000000000000010000000000]
    // The result is therefore 							   [01001000000000000000010000000000]
    // We'ves set the bits in GPIOA_MODER to what we want.
    GPIOA_MODER |= (1 << (5 * 2)); // Set bit 10
    GPIOA_MODER |= (1 << (1 * 2));


	uint32_t counter1 = 0;
	uint32_t counter2 = 0;

    while (1) {

    	// Now that we've covered the basics of bit masking and register manipulation,
    	// we can move on to toggling the output pin.

    	// This line toggles PA5 using an XOR operation:
    	// Shift the value 0b1 left by 5 bits → 0b0000000000100000
    	// XOR this with the current value of GPIOA_ODR (initially 0x0000):
    	//    GPIOA_ODR:         [0b0000000000000000]
    	//    Toggle mask:       [0b0000000000100000]
    	//    Result (ODR):      [0b0000000000100000]  → PA5 is now set

    	// After a delay, we run the same XOR operation again:
    	//    GPIOA_ODR:         [0b0000000000100000]
    	//    Toggle mask:       [0b0000000000100000]
    	//    Result (ODR):      [0b0000000000000000]  → PA5 is now cleared



    	delay(1000);

    	counter1++;
    	counter2++;

    	if(counter1 >= 500){
    		GPIOA_ODR ^= (1 << 5); // Toggle PA5
    		counter1 = 0;
    	}

    	if(counter2 >= 1500){
    		GPIOA_ODR ^= (1 << 1); // Toggle PA1
    		counter2 = 0;
    	}

    }
}
