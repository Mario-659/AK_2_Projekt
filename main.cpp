#include <iostream>

using namespace std;

unsigned char bcd_add(unsigned char x, unsigned char y) {
   asm(R"(
            movb %0, %%al    # x -> AL
            movb %1, %%bl    # y -> BL
            add %%bl, %%al   # x + y -> AL
            daa              # Decimal Adjust AL after Addition
            movb %%al, %0    # al -> x
      )" 
      : "+r"(x)
      : "r"(y)
      : "%al", "%bl"
   );

   return x;
}

int main() {
   unsigned char x = 0x54;  // Liczba 54 zakodowana w BCD
   unsigned char y = 0x23;  // Liczba 23 zakodowana w BCD

   unsigned char result = bcd_add(x, y); // Wynik dodawania

   
   //Wyswietlenie wyniku zakodowanego w BCD
   cout << "Result: " << hex << (int)result << endl;

   return 0;
}
