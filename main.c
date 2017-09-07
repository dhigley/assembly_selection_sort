//
//  main.c
//  assembly_IAS
//
//  Created by Daniel Higley on 11/5/16.
//  Copyright © 2016 Daniel Higley. All rights reserved.
//

#include <stdio.h>

int main(void) {
  int i, j, sum, start, end;
  i = 0; j = 2; sum = 0; start = 300; end = 5000;

  __asm{
        mov ecx,  sum     // ecx = 0
        mov eax,  start   // eax = start
        mov i,    eax     // i = start
   top: cmp eax,  end     // TOP OF OUTER LOOP
        jg        xout    // jump if start > end

        mov ebx,  2       // ebx = 2
        mov j,    ebx     // j = 2

  top2: cmp ebx,  eax     // TOP OF INNER LOOP
        jg        inci    // jump if j >= i

//    if (i % j == 0)
        mov edx,  0       // prepare for division
        div eax,  ebx     // edx = eax % ebx
        cmp edx,  0       // if (i % j == 0)
        je        test
        jmp       incj

//    if ( j == i && i > sum )
  test: mov eax,  i
        mov ebx,  j
        cmp eax,  ebx     // if (i != j)
        jne       inci
        cmp eax,  sum     // if (i <= sum)
        jle       inci

        add ecx,  eax     // sum += 1
        mov sum,  ecx

  }

  printf("i = %d\n", i);

  __asm{
        mov ecx,  sum

  incj: mov ebx,  j       // increment j and jump to the top of the inner loop
        add ebx,  1       // j++
        mov j,    ebx     // save value to j
        mov eax,  i       // eax changes after printf, set eax back to value save in i
        jmp       top2

  inci: mov eax,  i       // increment i and jump to the top of the outer loop
        add eax,  1       // i++
        mov i,    eax     // javae value to i
        jmp       top

  xout: nop
  }

  return 0;
}
