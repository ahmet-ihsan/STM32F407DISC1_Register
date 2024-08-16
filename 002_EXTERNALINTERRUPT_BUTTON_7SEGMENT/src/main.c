#include "stm32f4xx.h"
#include "Clock_Config_Driver.h"
#include "Display_Driver.h"
#include "Exti_Driver.h"

extern volatile uint8_t count;


int main(void)
{
	// Sistem clock ayarlarý açýlýþta 168MHz'dir. Önce RCC_DeInit() ile 16MHz. yapýlýp sonra tekrar ayarlandý
	RCC_DeInit();
	SystemCoreClockUpdate();

	rcc_clock_config(); // Kendi kodlarýmýzla sistem clock ayarlarý 168MHz. olarak ayarlandý
	SystemCoreClockUpdate();

	display_init();
	exti_init();


  while (1)
  {
	  display(count);
  }
}
