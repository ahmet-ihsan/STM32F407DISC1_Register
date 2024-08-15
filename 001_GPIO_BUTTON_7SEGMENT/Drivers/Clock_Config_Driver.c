#include "stm32f4xx.h"

void rcc_clock_config()
{
	// RCC clock control register reset deðerleri = 0x0000 XX83
	RCC->CR |= (1 << 16); // HSE açýldý
	while(!(RCC->CR & (1 << 17))); // HSE için bayraðýn kontrolü yapýlýr

	RCC->CR |= (1 << 19); // Clock System Security System aktif hale getirilir

	// PLL açýlmadan önce PLL konfigürasyonu yapýlýr.
	// PLL deðerlerinin bulunduðu RCC PLL configuration register reset deðerleri = 0x2400 3010
	RCC->PLLCFGR = 0x00000000; // PLL deðerleri sýfýrlanýr.
	RCC->PLLCFGR |= 1 << 22; // PLL için HSE seçildi
	RCC->PLLCFGR |= (1 << 2); // PLLM deðeri 4 yapýldý
	RCC->PLLCFGR |= (168 << 6); // PLLN deðeri 168 yapýldý
	// PLLP deðerinin 4 olmasý için PLLP0 ve PLLP1 deðerlerinin 0 olmasý gerekir
	RCC->PLLCFGR |= (1 << 26); // PLLQ deðeri 4 olarak ayarlandý.

	// PLL ayarlarý yapýldýktan sonra PLL aktif hale getirilir
	RCC->CR |= (1 << 24); // PLL aktif hale getirildi
	while(!(RCC->CR & (1 << 25))); // PLL aktifleþtirme bayraðý kontrol edilir

	// RCC clock configuration register reset deðeri = 0x0000 0000
	RCC->CFGR |= (1 << 1); // System clock switch ile PLL seçildi
	while(!(RCC->CFGR & (1 << 3))); // System clock switch PLL bayraðý kontrol edildi

	// AHB prescaler deðeri 1 olmasý durumunda deðerlerin 0 olmasý gerekir. Bu nedenle deðiþiklik yapmayacaðýz
	RCC->CFGR |= (5 << 10); // APB1 prescaler deðeri 4 olarak ayarlanýr
	RCC->CFGR |= (1 << 15); // APB2 prescaler deðeri 2 olarak ayarlanýr

	RCC->CIR |= (1 << 19); // HSE ready interrupt bayraðý temizlendi
	RCC->CIR |= (1 << 23); // Clock security system interrupt bayraðý temizlendi
}

