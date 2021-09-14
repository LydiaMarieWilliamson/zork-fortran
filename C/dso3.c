#include "F2C.h"

// Common Block Declarations

struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   int xlnt, travel[900];
} exits_;

#define exits_1 exits_

struct {
   int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_

struct {
   int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;

#define xpars_1 xpars_

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
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

// Table of constant values

static int c__10 = 10;
static int c__1 = 1;
static int c__6 = 6;

// FINDXT- FIND EXIT FROM ROOM

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool findxt_(int * dir, int * rm) {
// System generated locals
   Bool ret_val;

// Local variables
   static int i__, xi;
   extern Void bug_(int *, int *);
#define eqr ((int *)&rooms_1 + 2)
#define xflag ((int *)&curxt_1 + 4)
#define rrand ((int *)&rooms_1 + 602)

// ROOMS

// EXITS

// CURRENT EXITS

   ret_val = true;
// 						!ASSUME WINS.
   xi = rooms_1.rexit[*rm - 1];
// 						!FIND FIRST ENTRY.
   if (xi == 0) {
      goto L1000;
   }
// 						!NO EXITS?

L100:
   i__ = exits_1.travel[xi - 1];
// 						!GET ENTRY.
   curxt_1.xroom1 = i__ & xpars_1.xrmask;
   curxt_1.xtype = ((i__ & 32767) / xpars_1.xfshft & xpars_1.xfmask) + 1;
   switch (curxt_1.xtype) {
      case 1:
         goto L110;
      case 2:
         goto L120;
      case 3:
         goto L130;
      case 4:
         goto L130;
   }
// 						!BRANCH ON ENTRY.
   bug_(&c__10, &curxt_1.xtype);

L130:
   curxt_1.xobj = exits_1.travel[xi + 1] & xpars_1.xrmask;
   curxt_1.xactio = exits_1.travel[xi + 1] / xpars_1.xashft;
L120:
   curxt_1.xstrng = exits_1.travel[xi];
// 						!DOOR/CEXIT/NEXIT - STRING.
L110:
   xi += xpars_1.xelnt[curxt_1.xtype - 1];
// 						!ADVANCE TO NEXT ENTRY.
   if ((i__ & xpars_1.xdmask) == *dir) {
      return ret_val;
   }
   if ((i__ & xpars_1.xlflag) == 0) {
      goto L100;
   }
L1000:
   ret_val = false;
// 						!YES, LOSE.
   return ret_val;
}

#undef rrand
#undef xflag
#undef eqr

// FWIM- FIND WHAT I MEAN

// DECLARATIONS

int fwim_(int * f1, int * f2, int * rm, int * con, int * adv, Bool * nocare) {
// System generated locals
   int ret_val, i__1, i__2;

// Local variables
   static int i__, j;
#define eqo ((int *)&objcts_1 + 1)

// OBJECTS

   ret_val = 0;
// 						!ASSUME NOTHING.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP
      if ((*rm == 0 || objcts_1.oroom[i__ - 1] != *rm) && (*adv == 0 || objcts_1.oadv[i__ - 1] != *adv) && (*con == 0 || objcts_1.ocan[i__ - 1] != *con)) {
         goto L1000;
      }

   // OBJECT IS ON LIST... IS IT A MATCH?

      if ((objcts_1.oflag1[i__ - 1] & oflags_1.visibt) == 0) {
         goto L1000;
      }
// 	  IF(IAND(not(NOCARE),(IAND(OFLAG1(I),TAKEBT).EQ.0)) .OR.
      if (!(*nocare) && (objcts_1.oflag1[i__ - 1] & oflags_1.takebt) == 0 || (objcts_1.oflag1[i__ - 1] & *f1) == 0 && (objcts_1.oflag2[i__ - 1] & *f2) == 0) {
         goto L500;
      }
      if (ret_val == 0) {
         goto L400;
      }
// 						!ALREADY GOT SOMETHING?
      ret_val = -ret_val;
// 						!YES, AMBIGUOUS.
      return ret_val;

   L400:
      ret_val = i__;
// 						!NOTE MATCH.

// DOES OBJECT CONTAIN A MATCH?

   L500:
      if ((objcts_1.oflag2[i__ - 1] & oflags_1.openbt) == 0) {
         goto L1000;
      }
      i__2 = objcts_1.olnt;
      for (j = 1; j <= i__2; ++j) {
// 						!NO, SEARCH CONTENTS.
         if (objcts_1.ocan[j - 1] != i__ || (objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[j - 1] & *f1) == 0 && (objcts_1.oflag2[j - 1] & *f2) == 0) {
            goto L700;
         }
         if (ret_val == 0) {
            goto L600;
         }
         ret_val = -ret_val;
         return ret_val;

      L600:
         ret_val = j;
      L700:
         ;
      }
   L1000:
      ;
   }
   return ret_val;
}

#undef eqo

// YESNO- OBTAIN YES/NO ANSWER

// CALLED BY-

// 	YES-IS-TRUE=YESNO(QUESTION,YES-STRING,NO-STRING)

Bool yesno_(int * q, int * y, int * n) {
// Format strings
   static char fmt_110[] = "(a1)";

// System generated locals
   Bool ret_val;

// Builtin functions
   int s_rsfe(cilist *), do_fio(int *, char *, ftnlen), e_rsfe(void);

// Local variables
   static char ans[1];
   extern Void rspeak_(int *);

// Fortran I/O blocks
   static cilist io___9 = { 0, 0, 0, fmt_110, 0 };

L100:
   rspeak_(q);
// 						!ASK
   io___9.ciunit = chan_1.inpch;
   s_rsfe(&io___9);
   do_fio(&c__1, ans, (ftnlen) 1);
   e_rsfe();
// 						!GET ANSWER
   if (*(unsigned char *)ans == 'Y' || *(unsigned char *)ans == 'y') {
      goto L200;
   }
   if (*(unsigned char *)ans == 'N' || *(unsigned char *)ans == 'n') {
      goto L300;
   }
   rspeak_(&c__6);
// 						!SCOLD.
   goto L100;

L200:
   ret_val = true;
// 						!YES,
   rspeak_(y);
// 						!OUT WITH IT.
   return ret_val;

L300:
   ret_val = false;
// 						!NO,
   rspeak_(n);
// 						!LIKEWISE.
   return ret_val;

}
