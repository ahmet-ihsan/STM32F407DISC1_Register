#include "stm32f4xx.h"

volatile uint8_t count = 0;

void exti_init()
{
	RCC->AHB1ENR |= (1 << 0); // Butonlarý kullanmak için AHB1 clock hattý A protu için aktifleþtirildi
	// APB2 clock hattý harici kesme için aktif hale getirildi.
	// harici kesme için system configuration clock biti set edilir
	RCC->APB2ENR |= (1 << 14);

	// SYSCFG external interrupt configuration registerlarý ayarlanýr.
	// reset deðerleri 0x00000000 olmasýna raðmen yine ayarlanýr
	SYSCFG->EXTICR[0] = 0x00000000; // EXTI0 harici kesme hattý A portu için ayarlandý
	SYSCFG->EXTICR[1] = 0x00000000; // EXTI1 harici kesme hattý A portu için ayarlandý
	SYSCFG->EXTICR[2] = 0x00000000; // EXTI2 harici kesme hattý A portu için ayarlandý

	NVIC_EnableIRQ(EXTI0_IRQn); // EXTI0 harici kesme hattý NVIC biriminde aktif edildi
	NVIC_EnableIRQ(EXTI1_IRQn); // EXTI1 harici kesme hattý NVIC biriminde aktif edildi
	NVIC_EnableIRQ(EXTI2_IRQn); // EXTI2 harici kesme hattý NVIC biriminde aktif edildi

	NVIC_SetPriority(EXTI0_IRQn, 0); // NVIC biriminde aktif hale getirilen kesmenin önceliði belirlenir
	NVIC_SetPriority(EXTI1_IRQn, 1); // NVIC biriminde aktif hale getirilen kesmenin önceliði belirlenir
	NVIC_SetPriority(EXTI2_IRQn, 2); // NVIC biriminde aktif hale getirilen kesmenin önceliði belirlenir
	// 0 en öncelikli kesmedir

	// EXTI interrupt mask register reset deðerleri 0x00000000
	EXTI->IMR |= (1 << 0); // EXTI0 hattý interrupt olarak ayarlandý
	EXTI->IMR |= (1 << 1); // EXTI1 hattý interrupt olarak ayarlandý
	EXTI->IMR |= (1 << 2); // EXTI2 hattý interrupt olarak ayarlandý

	EXTI->RTSR |= (1 << 0); // EXTI0 harici interrupt yükselen kenar olarak ayarlandý
	EXTI->RTSR |= (1 << 1); // EXTI1 harici interrupt yükselen kenar olarak ayarlandý
	EXTI->RTSR |= (1 << 2); // EXTI2 harici interrupt yükselen kenar olarak ayarlandý
}

// Harici kesme fonksiyonlarý startup_stm32f40xx.s dosyasý içerisinde bulunmaktadýr
void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & (1 << 0)) // EXTI0 tetiklemesi kontrol edildi
	{
		count = 0; // EXTI0 basýlmasý durumunda counter temizlendi
		EXTI->PR |= (1 << 0); // EXTI0 için kalkan kesme bayraðý temizlendi
	}
}

void EXTI1_IRQHandler(void)
{
	if(EXTI->PR & (1 << 1)) // EXTI1 tetiklemesi kontrol edildi
	{
		if(15 == count)
			count = 0; // count deðeri 15 olursa tekrar sýfýrlanýr
		else
			count++; // count deðeri artýrýlýr
		EXTI->PR |= (1 << 1); // EXTI1 için kalkan kesme bayraðý indirilir
	}
}

void EXTI2_IRQHandler(void)
{
	if(EXTI->PR & (1 << 2)) // EXTI2 tetiklemesi kontrol edildi
	{
		if(0 == count)
			count = 15; // count deðeri 0 olursa 15 yapýlýr
		else
			count--; // count deðeri azaltýlýr
		EXTI->PR |= (1 << 2); // EXTI2 için kalkan kesme bayraðý indirilir
	}
}
