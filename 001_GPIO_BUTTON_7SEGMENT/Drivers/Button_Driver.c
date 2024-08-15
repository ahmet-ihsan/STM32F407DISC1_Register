#include "stm32f4xx.h"

void button_init()
{
	RCC->AHB1ENR |= (1 << 0); // AHB1 clock hattý A portu için aktifleþtirildi

	// GPIOA mode registerlarý reset durumunda input olduðu için deðiþiklik yapýlmadý

	// GPIO pull-up/pull-down registerlarý ayarlanýr
	GPIOA->PUPDR |= (1 << 1); // A portu 0. pini pull-down olarak ayarlandý
	GPIOA->PUPDR |= (1 << 3); // A portu 1. pini pull-down olarak ayarlandý
}
uint8_t button_up(void)
{
	if(GPIOA->IDR & (1 << 0)) // A portunun 0. pini kontrol edilir
		return 1;
	else
		return 0;
}
uint8_t button_down(void)
{
	if(GPIOA->IDR & (1 << 1)) // A portunun 1. pini kontrol edilir
		return 1;
	else
		return 0;
}
