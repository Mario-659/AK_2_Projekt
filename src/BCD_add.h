#ifndef BCD_ADD_H
#define BCD_ADD_H

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

#endif