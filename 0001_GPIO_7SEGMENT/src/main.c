#include "stm32f4xx.h"
#include "Clock_Config_Driver.h"
#include "Button_Driver.h"
#include "Display_Driver.h"


uint8_t count = 0;

int main(void)
{
	// Sistem clock ayarlarý açýlýþta 168MHz'dir. Önce RCC_DeInit() ile 16MHz. yapýlýp sonra tekrar ayarlandý
	RCC_DeInit();
	SystemCoreClockUpdate();

	rcc_clock_config(); // Kendi kodlarýmýzla sistem clock ayarlarý 168MHz. olarak ayarlandý
	SystemCoreClockUpdate();

	button_init(); // Buton GPIO ayarlarý yapýldý
	display_init(); // 7 segment display kontrolü için GPIO ayarlarý yapýldý

  while (1)
  {
	  if(1 == button_up()) // Deðerleri artýran buton kontrol edildi
	  {
		  while(1 == button_up()); // Butondan elimizin çekilmesi bekleniyor
		  for(int i = 16800000; i < 0; i--); // Buton arkýný önlemek için beklenir
		  if(15 == count) // Sayacýn 15'ten fazla olmasý durumunda sayaç 0 deðerine döner
			  count = 0;
		  else
			  count++;
	  }
	  if(1 == button_down()) // Deðerleri azaltan buton kontrol edildi
	  {
		  while(1 == button_down()); // Butondan elimizin çekilmesi bekleniyor
		  for(int i = 16800000; i < 0; i--); // Buton arkýný önlemek için beklenir
		  if (0 == count) // Sayacýn 0'dan az olmasý durumunda sayaç 15(F) deðerine döner
			  count = 15;
		  else
			  count--;
	  }

	  display(count);

  }
}
