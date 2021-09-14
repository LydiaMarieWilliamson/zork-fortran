#include "F2C.h"

// Common Block Declarations

struct {
   int hfactr;
} hyper_;

#define hyper_1 hyper_

struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

struct {
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

struct {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;

#define puzzle_1 puzzle_

// Table of constant values

static int c__0 = 0;
static int c__8 = 8;
static int c__870 = 870;
static int c__871 = 871;
static int c__874 = 874;
static int c__875 = 875;

// ENCRYP--	ENCRYPT PASSWORD

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Void encryp_(char *inw, char *outw, ftnlen inw_len, ftnlen outw_len) {
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
   return 0;

}

// CPGOTO--	MOVE TO NEXT STATE IN PUZZLE ROOM

// DECLARATIONS

Void cpgoto_(int * st) {
// System generated locals
   int i__1, i__2;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
#define rrand ((int *)&rooms_1 + 602)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void newsta_(int *, int *, int *, int *, int *);

// ROOMS

// OBJECTS

// CPGOTO, PAGE 2

// FLAGS

   rooms_1.rflag[rindex_1.cpuzz - 1] &= ~rflag_1.rseen;
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!RELOCATE OBJECTS.
      if (objcts_1.oroom[i__ - 1] == rindex_1.cpuzz && (objcts_1.oflag2[i__ - 1] & oflags_1.actrbt + oflags_1.villbt) == 0) {
         i__2 = findex_1.cphere * hyper_1.hfactr;
         newsta_(&i__, &c__0, &i__2, &c__0, &c__0);
      }
      if (objcts_1.oroom[i__ - 1] == *st * hyper_1.hfactr) {
         newsta_(&i__, &c__0, &rindex_1.cpuzz, &c__0, &c__0);
      }
// L100:
   }
   findex_1.cphere = *st;
   return 0;

}

#undef switch__
#undef flags
#undef rrand
#undef eqr
#undef eqo

// CPINFO--	DESCRIBE PUZZLE ROOM

// DECLARATIONS

Void cpinfo_(int * rmk, int * st) {
// Initialized data

   static int dgmoft[8] = { -9, -8, -7, -1, 1, 7, 8, 9 };
   static char pict[1 * 5] = "S" "S" "S" " " "M";
   static char qmk[1] = "?";

// Format strings
   static char fmt_10[] = "(\002       |\002,a2,1x,a2,1x,a2,\002|\002/,\002" " West  |\002,a2,\002 .. \002,a2,\002|  East\002,/\002       |" "\002,a2,1x,a2,1x,a2,\002|\002)";

// Local variables
   static int i__, j, k, l;
   static char dgm[1 * 8];
#define flags ((Bool *)&findex_1)
   extern Void rspeak_(int *);
#define switch__ ((int *)&findex_1 + 46)

// Fortran I/O blocks
   static cilist io___25 = { 0, 0, 0, fmt_10, 0 };

// PUZZLE ROOM

// FUNCTIONS AND LOCAL DATA

// FLAGS

// CPINFO, PAGE 2

   rspeak_(rmk);
   for (i__ = 1; i__ <= 8; ++i__) {
      j = dgmoft[i__ - 1];
      *(unsigned char *)&dgm[i__ - 1] = *(unsigned char *)&pict[puzzle_1.cpvec[*st + j - 1] + 3];
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
      if (puzzle_1.cpvec[*st + k - 1] != 0 && puzzle_1.cpvec[*st + l - 1] != 0) {
         *(unsigned char *)&dgm[i__ - 1] = *(unsigned char *)&qmk[0];
      }
   L100:
      ;
   }
   io___25.ciunit = chan_1.outch;
   s_wsfe(&io___25);
   do_fio(&c__8, dgm, (ftnlen) 1);
   e_wsfe();

   if (*st == 10) {
      rspeak_(&c__870);
   }
// 						!AT HOLE?
   if (*st == 37) {
      rspeak_(&c__871);
   }
// 						!AT NICHE?
   i__ = 872;
// 						!DOOR OPEN?
   if (findex_1.cpoutf) {
      i__ = 873;
   }
   if (*st == 52) {
      rspeak_(&i__);
   }
// 						!AT DOOR?
   if (puzzle_1.cpvec[*st] == -2) {
      rspeak_(&c__874);
   }
// 						!EAST LADDER?
   if (puzzle_1.cpvec[*st - 2] == -3) {
      rspeak_(&c__875);
   }
// 						!WEST LADDER?
   return 0;

}

#undef switch__
#undef flags
