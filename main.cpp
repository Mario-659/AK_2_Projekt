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

unsigned char bcd_sub(unsigned char x, unsigned char y) {
   asm(R"(
            movb %0, %%al      # x -> AL
            movb %1, %%bl      # y -> BL
            sub %%bl, %%al     # x - y -> AL
            das                # Decimal Adjust AL after Subtraction
            movb %%al, %0      # al -> x
      )" 
      : "+r"(x)
      : "r"(y)
      : "%al", "%bl"
   );

   return x;
}

int main() {
   unsigned char x = 0x21;  // Liczba 54 zakodowana w BCD
   unsigned char y = 0x23;  // Liczba 23 zakodowana w BCD

   unsigned char result = bcd_add(x, y); // Wynik dodawania

   
   //Wyswietlenie wyniku zakodowanego w BCD
   cout << "Result of addition: " << hex << (int)result << endl;
   
   result = bcd_sub(x, y); // Wynik odejmowania
   cout << "Result of substraction: " << hex << (int)result << endl;

   return 0;
}
