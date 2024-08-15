#include "stm32f4xx.h"
#include "Clock_Config_Driver.h"
#include "Button_Driver.h"
#include "Display_Driver.h"


uint8_t count = 0;

int main(void)
{
	// Sistem clock ayarlar� a��l��ta 168MHz'dir. �nce RCC_DeInit() ile 16MHz. yap�l�p sonra tekrar ayarland�
	RCC_DeInit();
	SystemCoreClockUpdate();

	rcc_clock_config(); // Kendi kodlar�m�zla sistem clock ayarlar� 168MHz. olarak ayarland�
	SystemCoreClockUpdate();

	button_init(); // Buton GPIO ayarlar� yap�ld�
	display_init(); // 7 segment display kontrol� i�in GPIO ayarlar� yap�ld�

  while (1)
  {
	  if(1 == button_up()) // De�erleri art�ran buton kontrol edildi
	  {
		  while(1 == button_up()); // Butondan elimizin �ekilmesi bekleniyor
		  for(int i = 16800000; i < 0; i--); // Buton ark�n� �nlemek i�in beklenir
		  if(15 == count) // Sayac�n 15'ten fazla olmas� durumunda saya� 0 de�erine d�ner
			  count = 0;
		  else
			  count++;
	  }
	  if(1 == button_down()) // De�erleri azaltan buton kontrol edildi
	  {
		  while(1 == button_down()); // Butondan elimizin �ekilmesi bekleniyor
		  for(int i = 16800000; i < 0; i--); // Buton ark�n� �nlemek i�in beklenir
		  if (0 == count) // Sayac�n 0'dan az olmas� durumunda saya� 15(F) de�erine d�ner
			  count = 15;
		  else
			  count--;
	  }

	  display(count);

  }
}
