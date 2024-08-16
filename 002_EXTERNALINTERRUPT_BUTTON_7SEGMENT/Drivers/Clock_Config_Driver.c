#include "stm32f4xx.h"

void rcc_clock_config()
{
	// RCC clock control register reset de�erleri = 0x0000 XX83
	RCC->CR |= (1 << 16); // HSE a��ld�
	while(!(RCC->CR & (1 << 17))); // HSE i�in bayra��n kontrol� yap�l�r

	RCC->CR |= (1 << 19); // Clock System Security System aktif hale getirilir

	// PLL a��lmadan �nce PLL konfig�rasyonu yap�l�r.
	// PLL de�erlerinin bulundu�u RCC PLL configuration register reset de�erleri = 0x2400 3010
	RCC->PLLCFGR = 0x00000000; // PLL de�erleri s�f�rlan�r.
	RCC->PLLCFGR |= 1 << 22; // PLL i�in HSE se�ildi
	RCC->PLLCFGR |= (1 << 2); // PLLM de�eri 4 yap�ld�
	RCC->PLLCFGR |= (168 << 6); // PLLN de�eri 168 yap�ld�
	// PLLP de�erinin 4 olmas� i�in PLLP0 ve PLLP1 de�erlerinin 0 olmas� gerekir
	RCC->PLLCFGR |= (1 << 26); // PLLQ de�eri 4 olarak ayarland�.

	// PLL ayarlar� yap�ld�ktan sonra PLL aktif hale getirilir
	RCC->CR |= (1 << 24); // PLL aktif hale getirildi
	while(!(RCC->CR & (1 << 25))); // PLL aktifle�tirme bayra�� kontrol edilir

	// RCC clock configuration register reset de�eri = 0x0000 0000
	RCC->CFGR |= (1 << 1); // System clock switch ile PLL se�ildi
	while(!(RCC->CFGR & (1 << 3))); // System clock switch PLL bayra�� kontrol edildi

	// AHB prescaler de�eri 1 olmas� durumunda de�erlerin 0 olmas� gerekir. Bu nedenle de�i�iklik yapmayaca��z
	RCC->CFGR |= (5 << 10); // APB1 prescaler de�eri 4 olarak ayarlan�r
	RCC->CFGR |= (1 << 15); // APB2 prescaler de�eri 2 olarak ayarlan�r

	RCC->CIR |= (1 << 19); // HSE ready interrupt bayra�� temizlendi
	RCC->CIR |= (1 << 23); // Clock security system interrupt bayra�� temizlendi
}

