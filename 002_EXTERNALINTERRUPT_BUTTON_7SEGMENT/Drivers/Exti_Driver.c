#include "stm32f4xx.h"

volatile uint8_t count = 0;

void exti_init()
{
	RCC->AHB1ENR |= (1 << 0); // Butonlar� kullanmak i�in AHB1 clock hatt� A protu i�in aktifle�tirildi
	// APB2 clock hatt� harici kesme i�in aktif hale getirildi.
	// harici kesme i�in system configuration clock biti set edilir
	RCC->APB2ENR |= (1 << 14);

	// SYSCFG external interrupt configuration registerlar� ayarlan�r.
	// reset de�erleri 0x00000000 olmas�na ra�men yine ayarlan�r
	SYSCFG->EXTICR[0] = 0x00000000; // EXTI0 harici kesme hatt� A portu i�in ayarland�
	SYSCFG->EXTICR[1] = 0x00000000; // EXTI1 harici kesme hatt� A portu i�in ayarland�
	SYSCFG->EXTICR[2] = 0x00000000; // EXTI2 harici kesme hatt� A portu i�in ayarland�

	NVIC_EnableIRQ(EXTI0_IRQn); // EXTI0 harici kesme hatt� NVIC biriminde aktif edildi
	NVIC_EnableIRQ(EXTI1_IRQn); // EXTI1 harici kesme hatt� NVIC biriminde aktif edildi
	NVIC_EnableIRQ(EXTI2_IRQn); // EXTI2 harici kesme hatt� NVIC biriminde aktif edildi

	NVIC_SetPriority(EXTI0_IRQn, 0); // NVIC biriminde aktif hale getirilen kesmenin �nceli�i belirlenir
	NVIC_SetPriority(EXTI1_IRQn, 1); // NVIC biriminde aktif hale getirilen kesmenin �nceli�i belirlenir
	NVIC_SetPriority(EXTI2_IRQn, 2); // NVIC biriminde aktif hale getirilen kesmenin �nceli�i belirlenir
	// 0 en �ncelikli kesmedir

	// EXTI interrupt mask register reset de�erleri 0x00000000
	EXTI->IMR |= (1 << 0); // EXTI0 hatt� interrupt olarak ayarland�
	EXTI->IMR |= (1 << 1); // EXTI1 hatt� interrupt olarak ayarland�
	EXTI->IMR |= (1 << 2); // EXTI2 hatt� interrupt olarak ayarland�

	EXTI->RTSR |= (1 << 0); // EXTI0 harici interrupt y�kselen kenar olarak ayarland�
	EXTI->RTSR |= (1 << 1); // EXTI1 harici interrupt y�kselen kenar olarak ayarland�
	EXTI->RTSR |= (1 << 2); // EXTI2 harici interrupt y�kselen kenar olarak ayarland�
}

// Harici kesme fonksiyonlar� startup_stm32f40xx.s dosyas� i�erisinde bulunmaktad�r
void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & (1 << 0)) // EXTI0 tetiklemesi kontrol edildi
	{
		count = 0; // EXTI0 bas�lmas� durumunda counter temizlendi
		EXTI->PR |= (1 << 0); // EXTI0 i�in kalkan kesme bayra�� temizlendi
	}
}

void EXTI1_IRQHandler(void)
{
	if(EXTI->PR & (1 << 1)) // EXTI1 tetiklemesi kontrol edildi
	{
		if(15 == count)
			count = 0; // count de�eri 15 olursa tekrar s�f�rlan�r
		else
			count++; // count de�eri art�r�l�r
		EXTI->PR |= (1 << 1); // EXTI1 i�in kalkan kesme bayra�� indirilir
	}
}

void EXTI2_IRQHandler(void)
{
	if(EXTI->PR & (1 << 2)) // EXTI2 tetiklemesi kontrol edildi
	{
		if(0 == count)
			count = 15; // count de�eri 0 olursa 15 yap�l�r
		else
			count--; // count de�eri azalt�l�r
		EXTI->PR |= (1 << 2); // EXTI2 i�in kalkan kesme bayra�� indirilir
	}
}
