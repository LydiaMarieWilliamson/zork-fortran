#include <stdio.h>

struct frec {
   char ix[2], buf[74];
} rec;

int main(void) {
   FILE *fp = fopen("dtext.dat", "rb");
   int x = 0;
   size_t n = sizeof rec.buf;
   char buf[n + 1]; buf[n] = '\0';
   while (fread(&rec, sizeof rec, 1, fp) == 1) {
      x++;
      for (int i = 0; i < n; i++) buf[i] = rec.buf[i] ^ ((x&31) + i + 1);
      for (char *cp = &buf[n - 1]; *cp == ' '; cp--) *cp = '\0';
      unsigned indx = (unsigned)(rec.ix[0]&0xff) | (unsigned)(rec.ix[1]&0xff) << 8;
      printf("%4d %4u: %s\n", x, indx, buf);
   }
   return 0;
}
