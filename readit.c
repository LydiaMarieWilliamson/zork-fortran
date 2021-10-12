#include <stdio.h>
#include <stdbool.h>

#define BalloOX 98

unsigned IOErrs = 0U;

// Read an integer from a line in the index file
int GetWord(FILE *InF) {
   int A = 0, n = fscanf(InF, "%6d\n", &A);
   if (n < 1) IOErrs++;
   return A;
}

// Read a number of integers from separate lines in the index file
void GetWords(int Lim, int *WordP, FILE *InF) {
   while (Lim-- > 0) *WordP++ = GetWord(InF);
}

// Read a number of boolean values from separate lines in the index file
void GetFlags(int Lim, bool *FlagP, FILE *InF) {
   while (Lim-- > 0) {
      char Ch = '\0'; int n = fscanf(InF, " %c\n", &Ch);
      if (n < 1 || (Ch != 'T' && Ch != 'F')) IOErrs++;
      *FlagP++ = Ch == 'T';
   }
}

void PutMsg(int X) {
   if (X < 0) printf("#%04d", -X);
   else if (X > 0) printf("?%04d", +X);
   else printf("-----");
}

// Dungeon initialization subroutine
int main(void) {
   const char *MyIndexFile = "dindx.dat";
// Now, restore from the existing index file.
   FILE *IndexF = fopen(MyIndexFile, "r"); if (IndexF == NULL) { printf("I can't open %s.\n", MyIndexFile); return 1; }
// /edit/:
   int Maj = GetWord(IndexF), Min = GetWord(IndexF), Edit = GetWord(IndexF);
   printf("/edit/: %1d.%1d.%1d\n", Maj, Min, Edit);
// /state/: (bloc will be set later, and strbit is from /star/
   int mxscor = GetWord(IndexF), strbit = GetWord(IndexF), egmxsc = GetWord(IndexF), bloc = 0;
   printf("/state/: Max Score = %d, Eg Score = %d\n", mxscor, egmxsc);
// /rooms/: (eqr)
   printf("\n");
   printf("Room Table\n");
   printf("──────────\n");
   const int rmax = 200;
   int rlnt = GetWord(IndexF);
   int rdesc1[200], rdesc2[200], rexit[200], ractio[200], rval[200], rflag[200];
   GetWords(rlnt, rdesc1, IndexF), GetWords(rlnt, rdesc2, IndexF), GetWords(rlnt, rexit, IndexF), GetWords(rlnt, ractio, IndexF), GetWords(rlnt, rval, IndexF), GetWords(rlnt, rflag, IndexF);
   printf("%d of %d rooms { desc1, desc2, exit, actio, val, flag; }\n", rlnt, rmax);
   for (int r = 0; r < rlnt; r++) printf("{ "), PutMsg(rdesc1[r]), printf(", "), PutMsg(rdesc2[r]), printf(", %3d, %2d, %2d, 0x%04x },\n", rexit[r], ractio[r], rval[r], rflag[r]);
// /exits/:
   printf("\n");
   printf("Exit Table\n");
   printf("──────────\n");
   const int xmax = 900;
   int xlnt = GetWord(IndexF);
   int travel[900];
   GetWords(xlnt, travel, IndexF);
   printf("/exits/: %d of %d exits { travel; }\n", xlnt, xmax);
   for (int x = 0; x < xlnt; x++) printf("%3u<<8|%3u,\n", ((unsigned)travel[x]&0xffff)>>8, (unsigned)travel[x]&0xff);
// /objcts/: (eqo)
   printf("\n");
   printf("Object Table\n");
   printf("────────────\n");
   const int omax = 220;
   int olnt = GetWord(IndexF);
   int odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
   GetWords(olnt, odesc1, IndexF), GetWords(olnt, odesc2, IndexF), GetWords(olnt, odesco, IndexF), GetWords(olnt, oactio, IndexF), GetWords(olnt, oflag1, IndexF), GetWords(olnt, oflag2, IndexF), GetWords(olnt, ofval, IndexF), GetWords(olnt, otval, IndexF), GetWords(olnt, osize, IndexF), GetWords(olnt, ocapac, IndexF), GetWords(olnt, oroom, IndexF), GetWords(olnt, oadv, IndexF), GetWords(olnt, ocan, IndexF), GetWords(olnt, oread, IndexF);
   printf("/objcts/: %d of %d objects { desc1, desc2, desco, actio, flag1, flag2, fval, tval, size, capac, room, adv, can, read; }\n", olnt, omax);
   for (int o = 0; o < olnt; o++)
      printf("{ "), PutMsg(odesc1[o]), printf(", "), PutMsg(odesc2[o]), printf(", "), PutMsg(odesco[o]), printf(", %3d, 0x%04x, 0x%04x, %2d, %2d, %5d, %5d, %5d, %d, %3d, ", oactio[o], (unsigned)oflag1[o]&0xffff, (unsigned)oflag2[o]&0xffff, ofval[o], otval[o], osize[o], ocapac[o], oroom[o], oadv[o], ocan[o]), PutMsg(oread[o]), printf(" },\n");
   bloc = oroom[BalloOX - 1];
   printf("/state/ bloc: %3d = oroom[%d]\n", bloc, BalloOX);
// /oroom2/:
   printf("\n");
   printf("Room 2 Table\n");
   printf("────────────\n");
   const int r2max = 20;
   int r2lnt = GetWord(IndexF);
   int oroom2[20], rroom2[20];
   GetWords(r2lnt, oroom2, IndexF), GetWords(r2lnt, rroom2, IndexF);
   printf("/oroom2/: %d of %d room2 slots { o, r; }\n", r2lnt, r2max);
   for (int r2 = 0; r2 < r2lnt; r2++) printf("{ %3d, %3d },\n", oroom2[r2], rroom2[r2]);
// /cevent/:
   printf("\n");
   printf("Clock Table\n");
   printf("───────────\n");
   const int cmax = 25;
   int clnt = GetWord(IndexF);
   int ctick[25], cactio[25]; bool cflag[25];
   GetWords(clnt, ctick, IndexF), GetWords(clnt, cactio, IndexF), GetFlags(clnt, cflag, IndexF);
   printf("/cevent/: %d of %d clock events { tick, actio, flag; }\n", clnt, cmax);
   for (int c = 0; c < clnt; c++) printf("{ %3d, %2d, %5s },\n", ctick[c], cactio[c], cflag[c]? "true": "false");
// /vill/:
   printf("\n");
   printf("Villain Table\n");
   printf("─────────────\n");
   const int vmax = 4;
   int vlnt = GetWord(IndexF);
   int villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
   GetWords(vlnt, villns, IndexF), GetWords(vlnt, vprob, IndexF), GetWords(vlnt, vopps, IndexF), GetWords(vlnt, vbest, IndexF), GetWords(vlnt, vmelee, IndexF);
   printf("/vill/: %d of %d villains { villns, prob, opps, best, melee; }\n", vlnt, vmax);
   for (int v = 0; v < vlnt; v++) printf("{ %2d, %d, %d, %2d, %d },\n", villns[v], vprob[v], vopps[v], vbest[v], vmelee[v]);
// /advs/:
   printf("\n");
   printf("Adventurer Table\n");
   printf("────────────────\n");
   const int amax = 4;
   int alnt = GetWord(IndexF);
   int aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
   GetWords(alnt, aroom, IndexF), GetWords(alnt, ascore, IndexF), GetWords(alnt, avehic, IndexF), GetWords(alnt, aobj, IndexF), GetWords(alnt, aactio, IndexF), GetWords(alnt, astren, IndexF), GetWords(alnt, aflag, IndexF);
   printf("/advs/: %d of %d adventurers { room, score, vehic, obj, actio, stren, flag; }\n", alnt, amax);
   for (int a = 0; a < alnt; a++) printf("{ %3d, %d, %d, %3d, %d, %d, 0x%02x },\n", aroom[a], ascore[a], avehic[a], aobj[a], aactio[a], astren[a], (unsigned)aflag[a]);
// /star/: strbit was set, up above.
   int mbase = GetWord(IndexF);
   printf("/star/: Star Mask = %d, Melee Start = %d\n", strbit, mbase);
// /rmsg/:
   printf("\n");
   printf("Message Table\n");
   printf("─────────────\n");
   const int mmax = 1820;
   int mlnt = GetWord(IndexF);
   int rtext[1820];
   GetWords(mlnt, rtext, IndexF);
   printf("/rmsg/: %d of %d messages { text; }\n", mlnt, mmax);
   for (int m = 0; m < mlnt; m++) PutMsg(rtext[m]), printf(",\n");
// Initialization done.
   fclose(IndexF);
   if (IOErrs > 0) { printf("I can't read %s: %1d error(s) found.", MyIndexFile, IOErrs); return 1; }
   printf("Message Table:\n");
   struct frec {
      char ix[2], buf[74];
   } rec;
   FILE *StoryF = fopen("dtext.dat", "rb");
   int x = 0;
   size_t n = sizeof rec.buf;
   char buf[n + 1]; buf[n] = '\0';
   unsigned exindx = 0U;
   while (fread(&rec, sizeof rec, 1, StoryF) == 1) {
      x++;
      for (int i = 0; i < n; i++) buf[i] = rec.buf[i] ^ ((x&31) + i + 1);
      for (char *cp = &buf[n - 1]; *cp == ' '; cp--) *cp = '\0';
      unsigned indx = (unsigned)(rec.ix[0]&0xff) | (unsigned)(rec.ix[1]&0xff) << 8;
      if (indx != exindx) printf("#%04d", x), exindx = indx; else printf("     ");
      printf(":%s\n", buf);
   }
   return 0;
}
