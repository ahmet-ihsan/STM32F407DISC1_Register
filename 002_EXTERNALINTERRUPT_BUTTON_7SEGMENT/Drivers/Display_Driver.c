#include "stm32f4xx.h"

void display_init(void)
{
	RCC->AHB1ENR |= (1 << 4); // AHB1 clock hattý E portu için aktifleþtirildi

	GPIOE->MODER |= (1 << 14);
	GPIOE->MODER &= ~(1 << 15); // E portu 7. pini output
	GPIOE->MODER |= (1 << 16);
	GPIOE->MODER &= ~(1 << 17); // E portu 8. pini output
	GPIOE->MODER |= (1 << 18);
	GPIOE->MODER &= ~(1 << 19); // E portu 9. pini output
	GPIOE->MODER |= (1 << 20);
	GPIOE->MODER &= ~(1 << 21); // E portu 10. pini output
	GPIOE->MODER |= (1 << 22);
	GPIOE->MODER &= ~(1 << 23); // E portu 11. pini output
	GPIOE->MODER |= (1 << 24);
	GPIOE->MODER &= ~(1 << 25); // E portu 12. pini output
	GPIOE->MODER |= (1 << 26);
	GPIOE->MODER &= ~(1 << 27); // E portu 13. pini output
	GPIOE->MODER |= (1 << 28);
	GPIOE->MODER &= ~(1 << 29); // E portu 14. pini output

	// GPIO output type register reset deðerleri push-pull olduðu için deðiþtirilmedi

	// GPIO output speed register ayarlarý yapýlýr
	GPIOE->OSPEEDR |= (3 << 14); // 7. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 16); // 8. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 18); // 9. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 20); // 10. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 22); // 11. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 24); // 12. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 26); // 13. pin very high speed seçildi
	GPIOE->OSPEEDR |= (3 << 28); // 14. pin very high speed seçildi

	// GPIO pull-up/pull-down registerlarý reset olarak no pull-up, pull-down olduðu için deðiþtirilmedi
}
void display(uint8_t led)
{
	// ortak katot 7 segment 0-F arasýnda deðerler alýr
	switch(led)
	{
	case 1:
	GPIOE->ODR &= ~(1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR &= ~(1 << 10);
	GPIOE->ODR &= ~(1 << 11);
	GPIOE->ODR &= ~(1 << 12);
	GPIOE->ODR &= ~(1 << 13);
	GPIOE->ODR |= (1 << 14); // 1 olduðu zaman 7 segment 1. þeklinde yanacak.
	break;
	case 2:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR &= ~(1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR &= ~(1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 2 olduðu zaman 7 segment 2. þeklinde yanacak.
	break;
	case 3:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR &= ~(1 << 11);
	GPIOE->ODR &= ~(1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 3 olduðu zaman 7 segment 3. þeklinde yanacak.
	break;
	case 4:
	GPIOE->ODR &= ~(1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR &= ~(1 << 10);
	GPIOE->ODR &= ~(1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 4 olduðu zaman 7 segment 4. þeklinde yanacak.
	break;
	case 5:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR &= ~(1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR &= ~(1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 5 olduðu zaman 7 segment 5. þeklinde yanacak.
	break;
	case 6:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR &= ~(1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 6 olduðu zaman 7 segment 6. þeklinde yanacak.
	break;
	case 7:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR &= ~(1 << 10);
	GPIOE->ODR &= ~(1 << 11);
	GPIOE->ODR &= ~(1 << 12);
	GPIOE->ODR &= ~(1 << 13);
	GPIOE->ODR |= (1 << 14); // 7 olduðu zaman 7 segment 7. þeklinde yanacak.
	break;
	case 8:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 8 olduðu zaman 7 segment 8. þeklinde yanacak.
	break;
	case 9:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR &= ~(1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 9 olduðu zaman 7 segment 9. þeklinde yanacak.
	break;
	case 10:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR &= ~(1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 10 olduðu zaman 7 segment A. þeklinde yanacak.
	break;
	case 11:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR &= ~(1 << 14); // 11 olduðu zaman 7 segment B þeklinde yanacak. (8 ile karýþmamasý için DP pini kapatýlýr)
	break;
	case 12:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR &= ~(1 << 8);
	GPIOE->ODR &= ~(1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR &= ~(1 << 13);
	GPIOE->ODR |= (1 << 14); // 12 olduðu zaman 7 segment C. þeklinde yanacak.
	break;
	case 13:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR &= ~(1 << 13);
	GPIOE->ODR &= ~(1 << 14); // 13 olduðu zaman 7 segment D þeklinde yanacak. (0 ile karýþtýrýlmamasý için DP pini kapatýlýr)
	break;
	case 14:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR &= ~(1 << 8);
	GPIOE->ODR &= ~(1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 14 olduðu zaman 7 segment E. þeklinde yanacak.
	break;
	case 15:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR &= ~(1 << 8);
	GPIOE->ODR &= ~(1 << 9);
	GPIOE->ODR &= ~(1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR |= (1 << 13);
	GPIOE->ODR |= (1 << 14); // 15 olduðu zaman 7 segment F. þeklinde yanacak.
	break;
	default:
	GPIOE->ODR |= (1 << 7);
	GPIOE->ODR |= (1 << 8);
	GPIOE->ODR |= (1 << 9);
	GPIOE->ODR |= (1 << 10);
	GPIOE->ODR |= (1 << 11);
	GPIOE->ODR |= (1 << 12);
	GPIOE->ODR &= ~(1 << 13);
	GPIOE->ODR |= (1 << 14); // default durumda 7 segment 0. þeklinde yanacak.
	break;
	}
}
