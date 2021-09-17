#include "F2C.h"

// hyper.h: (Unlisted)
extern struct hyper_1_ {
   int hfactr;
} hyper_;
#define hyper_1 hyper_

// rooms.h:

// ROOMS

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;
#define rooms_1 rooms_
#define eqr ((int *)&rooms_1 + 2)
#define rrand ((int *)&rooms_1 + 602)

// rflag.h:

extern struct rflag_1_ {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;
#define rflag_1 rflag_

// rindex.h:

extern struct rindex_1_ {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;
#define rindex_1 rindex_

// objects.h:

// OBJECTS

extern struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;
#define objcts_1 objcts_
#define eqo ((int *)&objcts_1 + 1)

extern struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;
#define oroom2_1 oroom2_

// oflags.h:

extern struct oflags_1_ {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;
#define oflags_1 oflags_

// flags.h:

// FLAGS

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;
#define findex_1 findex_
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// io.h: (Unlisted)
extern struct {
   int inpch, outch, dbch;
} chan_;
#define chan_1 chan_

// puzzle.h:

// PUZZLE ROOM STATE

extern struct puzzle_1_ {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;
#define puzzle_1 puzzle_

// ENCRYP--	ENCRYPT PASSWORD

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

void encryp_(const char *inw, char *outw/*, size_t inw_unit, size_t outw_unit*/) {
// Initialized data

   static char keyw[1 * 6] = "E" "C" "O" "R" "M" "S";

   static int i__, j, uinw[6], usum;
   static char ukeyw[1 * 6];
   static int uinws, ukeyws;

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
   for (i__ = 1; i__ <= 6; ++i__) {
// 						!UNBIAS, COMPUTE SUMS.
      *(unsigned char *)&ukeyw[i__ - 1] = (char)(*(unsigned char *)&keyw[i__ - 1] - 64);
      if (*(unsigned char *)&inw[j] <= '@') {
         j = 1;
      }
// 	  UINW(I)=char(ichar(INW(J))-64)
      uinw[i__ - 1] = *(unsigned char *)&inw[j] - 64;
      ukeyws += *(unsigned char *)&ukeyw[i__ - 1];
      uinws += uinw[i__ - 1];
      ++j;
// L100:
   }

   usum = uinws % 8 + (ukeyws % 8 << 3);
// 						!COMPUTE MASK.
   for (i__ = 1; i__ <= 6; ++i__) {
      j = (uinw[i__ - 1] ^ *(unsigned char *)&ukeyw[i__ - 1] ^ usum) & 31;
      usum = (usum + 1) % 32;
      if (j > 26) {
         j %= 26;
      }
      *(unsigned char *)&outw[i__] = (char)(max(1, j) + 64);
// L200:
   }
}

// CPGOTO--	MOVE TO NEXT STATE IN PUZZLE ROOM

// DECLARATIONS

void cpgoto_(int st) {
// System generated locals
   int i__1, i__2;

// Local variables
   static int i__;
   extern void newsta_(int, int, int, int, int);

// CPGOTO, PAGE 2

   rooms_1.rflag[rindex_1.cpuzz - 1] &= ~rflag_1.rseen;
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!RELOCATE OBJECTS.
      if (objcts_1.oroom[i__ - 1] == rindex_1.cpuzz && (objcts_1.oflag2[i__ - 1] & oflags_1.actrbt + oflags_1.villbt) == 0) {
         i__2 = findex_1.cphere * hyper_1.hfactr;
         newsta_(i__, 0, i__2, 0, 0);
      }
      if (objcts_1.oroom[i__ - 1] == st * hyper_1.hfactr) {
         newsta_(i__, 0, rindex_1.cpuzz, 0, 0);
      }
// L100:
   }
   findex_1.cphere = st;
}

// CPINFO--	DESCRIBE PUZZLE ROOM

// DECLARATIONS

void cpinfo_(int rmk, int st) {
// Initialized data

   static int dgmoft[8] = { -9, -8, -7, -1, 1, 7, 8, 9 };
   static char pict[1 * 5] = "S" "S" "S" " " "M";
   static char qmk[1] = "?";

// Local variables
   static int i__, j, k, l;
   static char dgm[1 * 8];
   extern void rspeak_(int);

// PUZZLE ROOM

// FUNCTIONS AND LOCAL DATA

// CPINFO, PAGE 2

   rspeak_(rmk);
   for (i__ = 1; i__ <= 8; ++i__) {
      j = dgmoft[i__ - 1];
      *(unsigned char *)&dgm[i__ - 1] = *(unsigned char *)&pict[puzzle_1.cpvec[st + j - 1] + 3];
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
         *(unsigned char *)&dgm[i__ - 1] = *(unsigned char *)&qmk[0];
      }
   L100:
      ;
   }
   BegExSF(chan_1.outch, /*10*/"(\002       |\002,a2,1x,a2,1x,a2,\002|\002/,\002 West  |\002,a2,\002 .. \002,a2,\002|  East\002,/\002       |\002,a2,1x,a2,1x,a2,\002|\002)", 0);
   DoFio(8, dgm, sizeof dgm[0]);
   EndExSF();

   if (st == 10) {
      rspeak_(870);
   }
// 						!AT HOLE?
   if (st == 37) {
      rspeak_(871);
   }
// 						!AT NICHE?
   i__ = 872;
// 						!DOOR OPEN?
   if (findex_1.cpoutf) {
      i__ = 873;
   }
   if (st == 52) {
      rspeak_(i__);
   }
// 						!AT DOOR?
   if (puzzle_1.cpvec[st] == -2) {
      rspeak_(874);
   }
// 						!EAST LADDER?
   if (puzzle_1.cpvec[st - 2] == -3) {
      rspeak_(875);
   }
// 						!WEST LADDER?
}
