# STM32F407DISC1_Register
Bütün projelerde clock ayarları yapılmadan önce 25000000 olan HSE_VALUE değeri 8000000 olarak değiştirildi.

## 001_GPIO_BUTTON_7SEGMENT
2 buton ile ortak katot 7 segment display kontrolü
##### Butonlar;
- Artış butonu =>PA0
- Azalma butonu =>PA1
##### 7 Segment Display pinleri;
- PE7 =>A
- PE8 =>B
- PE9 =>C
- PE10 =>D
- PE11 =>E
- PE12 =>F
- PE13 =>G
- PE14 => DP

## 002_EXTERNALINTERRUPT_BUTTON_7SEGMENT
3 harici kesme butonu ile ortak katot 7 segment display kontrolü
##### Butonlar;
- Sıfırlama kesme butonu =>PA0
- Artış kesme butonu =>PA1
- Azalma kesme butonu =>PA2
##### 7 Segment Display pinleri;
- PE7 =>A
- PE8 =>B
- PE9 =>C
- PE10 =>D
- PE11 =>E
- PE12 =>F
- PE13 =>G
- PE14 => DP
