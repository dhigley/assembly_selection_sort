/*
 * The c programming version of assignment 4
 */
#include <stdio.h>

int main(void) {
  int i, j  = 0;
  int sum   = 0;
  int start = 10;
  int end   = 100;

  for (i = start; i <= end; i++) {
    /* printf("%s\n", "start another loop"); */
    for ( j = 2 ; j < i; j++ ) {
      if ( i%j == 0 ) {
        /* printf("%s\n", "broken"); */
        break;
      }
    }
    /* printf("%s", "check"); */
    if ( j == i && i > sum ) {
      printf("%d\n", i);
      sum += i;
      /* i = sum; */
    }
  }

  printf("sum = %d", sum);
  return 0;
}
