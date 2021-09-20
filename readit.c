#include <stdio.h>

struct frec {
   int indx;
   char c[74];
} rec;

int main(void) {
   FILE *fp = fopen("dtext.dat", "rb");
   int x = 0;
   char buf[75]; buf[74] = '\0';
   while (fread(&rec, sizeof rec, 1, fp) == 1) {
      x++;
      for (int i = 1; i < 75; i++) {
         int mask = (x&31) + i;
         buf[i - 1] = rec.c[i - 1] ^ mask;
      }
      for (char *cp = &buf[73]; *cp == ' '; cp--) *cp = '\0';
      printf("%d %s\n", rec.indx, buf);
   }
   return 0;
}
