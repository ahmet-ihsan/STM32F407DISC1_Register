#include "stm32f4xx.h"
#include "Clock_Config_Driver.h"
#include "Display_Driver.h"
#include "Exti_Driver.h"

extern volatile uint8_t count;


int main(void)
{
	// Sistem clock ayarlar� a��l��ta 168MHz'dir. �nce RCC_DeInit() ile 16MHz. yap�l�p sonra tekrar ayarland�
	RCC_DeInit();
	SystemCoreClockUpdate();

	rcc_clock_config(); // Kendi kodlar�m�zla sistem clock ayarlar� 168MHz. olarak ayarland�
	SystemCoreClockUpdate();

	display_init();
	exti_init();


  while (1)
  {
	  display(count);
  }
}
