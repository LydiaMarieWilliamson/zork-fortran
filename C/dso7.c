// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

// ENCRYP--	ENCRYPT PASSWORD
void encryp(const char *inw, char *outw/*, size_t inw_unit, size_t outw_unit*/) {
// Initialized data
   static const char keyw[1 * 6] = "E" "C" "O" "R" "M" "S";

   int i, j, uinw[6], usum;
   char ukeyw[1 * 6];
   int uinws, ukeyws;

// Parameter adjustments
   --outw;
   --inw;

// Function Body

   uinws = 0;
// 						!UNBIASED INW SUM.
   ukeyws = 0;
// 						!UNBIASED KEYW SUM.
   j = 1;
// 						!POINTER IN KEYWORD.
   for (i = 1; i <= 6; ++i) {
// 						!UNBIAS, COMPUTE SUMS.
      ukeyw[i - 1] = (char)(keyw[i - 1] - 64);
      if (inw[j] <= '@') {
         j = 1;
      }
// 	  UINW(I)=char(ichar(INW(J))-64)
      uinw[i - 1] = inw[j] - 64;
      ukeyws += ukeyw[i - 1];
      uinws += uinw[i - 1];
      ++j;
// L100:
   }

   usum = uinws % 8 + (ukeyws % 8 << 3);
// 						!COMPUTE MASK.
   for (i = 1; i <= 6; ++i) {
      j = (uinw[i - 1] ^ ukeyw[i - 1] ^ usum) & 31;
      usum = (usum + 1) % 32;
      if (j > 26) {
         j %= 26;
      }
      outw[i] = (char)(max(1, j) + 64);
// L200:
   }
}

// CPGOTO--	MOVE TO NEXT STATE IN PUZZLE ROOM
void cpgoto(int st) {
// System generated locals
   int i__1, i__2;

// Local variables
   int i;

// CPGOTO, PAGE 2

   rooms_1.rflag[rindex_1.cpuzz - 1] &= ~SeenR;
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!RELOCATE OBJECTS.
      if (objcts_1.oroom[i - 1] == rindex_1.cpuzz && (objcts_1.oflag2[i - 1] & ActrO + VillO) == 0) {
         i__2 = findex_1.cphere * hyper_1.hfactr;
         newsta(i, 0, i__2, 0, 0);
      }
      if (objcts_1.oroom[i - 1] == st * hyper_1.hfactr) {
         newsta(i, 0, rindex_1.cpuzz, 0, 0);
      }
// L100:
   }
   findex_1.cphere = st;
}

// CPINFO--	DESCRIBE PUZZLE ROOM
void cpinfo(int rmk, int st) {
// Initialized data
   static const int dgmoft[8] = { -9, -8, -7, -1, 1, 7, 8, 9 };
   static const char pict[1 * 5] = "S" "S" "S" " " "M";
   static const char qmk[1] = "?";

// Local variables
   int i, j, k, l;
   char dgm[1 * 8];

// PUZZLE ROOM

// FUNCTIONS AND LOCAL DATA

// CPINFO, PAGE 2

   rspeak(rmk);
   for (i = 1; i <= 8; ++i) {
      j = dgmoft[i - 1];
      dgm[i - 1] = pict[puzzle_1.cpvec[st + j - 1] + 3];
// 						!GET PICTURE ELEMENT.
      if (abs(j) == 1 || abs(j) == 8) {
         goto L100;
      }
      k = 8;
      if (j < 0) {
         k = -8;
      }
// 						!GET ORTHO DIR.
      l = j - k;
      if (puzzle_1.cpvec[st + k - 1] != 0 && puzzle_1.cpvec[st + l - 1] != 0) {
         dgm[i - 1] = qmk[0];
      }
   L100:
      ;
   }
   BegExSF(chan_1.outch, /*10*/"(\002       |\002,a2,1x,a2,1x,a2,\002|\002/,\002 West  |\002,a2,\002 .. \002,a2,\002|  East\002,/\002       |\002,a2,1x,a2,1x,a2,\002|\002)", 0);
   DoFio(8, dgm, sizeof dgm[0]);
   EndExSF();

   if (st == 10) {
      rspeak(870);
   }
// 						!AT HOLE?
   if (st == 37) {
      rspeak(871);
   }
// 						!AT NICHE?
   i = 872;
// 						!DOOR OPEN?
   if (findex_1.cpoutf) {
      i = 873;
   }
   if (st == 52) {
      rspeak(i);
   }
// 						!AT DOOR?
   if (puzzle_1.cpvec[st] == -2) {
      rspeak(874);
   }
// 						!EAST LADDER?
   if (puzzle_1.cpvec[st - 2] == -3) {
      rspeak(875);
   }
// 						!WEST LADDER?
}
