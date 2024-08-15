#include "stm32f4xx.h"

void display_init(void)
{
	RCC->AHB1ENR |= (1 << 4); // AHB1 clock hatt� E portu i�in aktifle�tirildi

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

	// GPIO output type register reset de�erleri push-pull oldu�u i�in de�i�tirilmedi

	// GPIO output speed register ayarlar� yap�l�r
	GPIOE->OSPEEDR |= (3 << 14); // 7. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 16); // 8. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 18); // 9. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 20); // 10. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 22); // 11. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 24); // 12. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 26); // 13. pin very high speed se�ildi
	GPIOE->OSPEEDR |= (3 << 28); // 14. pin very high speed se�ildi

	// GPIO pull-up/pull-down registerlar� reset olarak no pull-up, pull-down oldu�u i�in de�i�tirilmedi
}
void display(uint8_t led)
{
	// ortak katot 7 segment 0-F aras�nda de�erler al�r
	switch(led)
	{
	case 1:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (195 << 8);
	break;
	case 2:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (219 << 7);
	break;
	case 3:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (207 << 7);
	break;
	case 4:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (115 << 8);
	break;
	case 5:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (237 << 7);
	break;
	case 6:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (253 << 7);
	break;
	case 7:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (135 << 7);
	break;
	case 8:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (255 << 7);
	break;
	case 9:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (239 << 7);
	break;
	case 10:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (247 << 7);
	break;
	case 11:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (127 << 7);
	break;
	case 12:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (185 << 7);
	break;
	case 13:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (63 << 7);
	break;
	case 14:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (249 << 7);
	break;
	case 15:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (241 << 7);
	break;
	default:
	GPIOE->ODR &= ~(255 << 7);
	GPIOE->ODR |= (191 << 7);
	break;
	}
}
