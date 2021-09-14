#include "F2C.h"

/* Common Block Declarations */

struct {
   integer pltime, shour, smin, ssec;
} time_;

#define time_1 time_

struct {
   integer prsa, prsi, prso;
   logical prswon;
   integer prscon;
} prsvec_;

#define prsvec_1 prsvec_

struct {
   integer oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

struct {
   integer lastit;
} last_;

#define last_1 last_

struct {
   integer act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

struct {
   integer vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

struct {
   integer sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

struct {
   integer vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

struct {
   integer olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   integer r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct {
   integer visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

struct {
   integer cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

struct {
   integer rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   integer rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

struct {
   integer alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

struct {
   integer astag;
} aflags_;

#define aflags_1 aflags_

struct {
   integer player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

/* Table of constant values */

static integer c__3 = 3;

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* GTTIME-- GET TOTAL TIME PLAYED */

/* DECLARATIONS */

/* Subroutine */ int gttime_(integer * t) {
   static integer h__, m, s;
   extern /* Subroutine */ int intime_(integer *, integer *, integer *);

   intime_(&h__, &m, &s);
   *t = h__ * 60 + m - (time_1.shour * 60 + time_1.smin);
   if (*t < 0) {
      *t += 1440;
   }
   *t += time_1.pltime;
   return 0;
} /* gttime_ */

/* OPNCLS-- PROCESS OPEN/CLOSE FOR DOORS */

/* DECLARATIONS */

logical opncls_(integer * obj, integer * so, integer * sc) {
/* System generated locals */
   integer i__1;
   logical ret_val;

/* Local variables */
   extern integer rnd_(integer *);
#define eqo ((integer *)&objcts_1 + 1)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
   extern /* Subroutine */ int rspeak_(integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* OBJECTS */

/* FUNCTIONS AND DATA */

/* VERBS */

   ret_val = TRUE_;
/* 						!ASSUME WINS. */
   if (prsvec_1.prsa == vindex_1.closew) {
      goto L100;
   }
/* 						!CLOSE? */
   if (prsvec_1.prsa == vindex_1.openw) {
      goto L50;
   }
/* 						!OPEN? */
   ret_val = FALSE_;
/* 						!LOSE */
   return ret_val;

L50:
   if ((objcts_1.oflag2[*obj - 1] & oflags_1.openbt) != 0) {
      goto L200;
   }
/* 						!OPEN... IS IT? */
   rspeak_(so);
   objcts_1.oflag2[*obj - 1] |= oflags_1.openbt;
   return ret_val;

L100:
   if (!((objcts_1.oflag2[*obj - 1] & oflags_1.openbt) != 0)) {
      goto L200;
   }
/* 						!CLOSE... IS IT? */
   rspeak_(sc);
   objcts_1.oflag2[*obj - 1] &= ~oflags_1.openbt;
   return ret_val;

L200:
   i__1 = rnd_(&c__3) + 125;
   rspeak_(&i__1);
/* 						!DUMMY. */
   return ret_val;
} /* opncls_ */

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo

/* LIT-- IS ROOM LIT? */

/* DECLARATIONS */

logical lit_(integer * rm) {
/* System generated locals */
   integer i__1, i__2;
   logical ret_val;

/* Local variables */
   static integer i__, j, oa;
#define eqa ((integer *)&advs_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
   extern logical qhere_(integer *, integer *);
#define rrand ((integer *)&rooms_1 + 602)

/* ROOMS */

/* OBJECTS */

/* ADVENTURERS */

   ret_val = TRUE_;
/* 						!ASSUME WINS */
   if ((rooms_1.rflag[*rm - 1] & rflag_1.rlight) != 0) {
      return ret_val;
   }

   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!LOOK FOR LIT OBJ */
      if (qhere_(&i__, rm)) {
         goto L100;
      }
/* 						!IN ROOM? */
      oa = objcts_1.oadv[i__ - 1];
/* 						!NO */
      if (oa <= 0) {
         goto L1000;
      }
/* 						!ON ADV? */
      if (advs_1.aroom[oa - 1] != *rm) {
         goto L1000;
      }
/* 						!ADV IN ROOM? */

/* OBJ IN ROOM OR ON ADV IN ROOM */

   L100:
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.onbt) != 0) {
         return ret_val;
      }
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[i__ - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[i__ - 1] & oflags_1.openbt) == 0) {
         goto L1000;
      }

   /* OBJ IS VISIBLE AND OPEN OR TRANSPARENT */

      i__2 = objcts_1.olnt;
      for (j = 1; j <= i__2; ++j) {
         if (objcts_1.ocan[j - 1] == i__ && (objcts_1.oflag1[j - 1] & oflags_1.onbt) != 0) {
            return ret_val;
         }
   /* L500: */
      }
   L1000:
      ;
   }
   ret_val = FALSE_;
   return ret_val;
} /* lit_ */

#undef rrand
#undef eqr
#undef eqo
#undef eqa

/* WEIGHT- RETURNS SUM OF WEIGHT OF QUALIFYING OBJECTS */

/* DECLARATIONS */

integer weight_(integer * rm, integer * cn, integer * ad) {
/* System generated locals */
   integer ret_val, i__1;

/* Local variables */
   static integer i__, j;
#define eqo ((integer *)&objcts_1 + 1)
   extern logical qhere_(integer *, integer *);

/* OBJECTS */

   ret_val = 0;
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!OMIT BIG FIXED ITEMS. */
      if (objcts_1.osize[i__ - 1] >= 10000) {
         goto L100;
      }
/* 						!IF FIXED, FORGET IT. */
      if (qhere_(&i__, rm) && *rm != 0 || objcts_1.oadv[i__ - 1] == *ad && *ad != 0) {
         goto L50;
      }
      j = i__;
/* 						!SEE IF CONTAINED. */
   L25:
      j = objcts_1.ocan[j - 1];
/* 						!GET NEXT LEVEL UP. */
      if (j == 0) {
         goto L100;
      }
/* 						!END OF LIST? */
      if (j != *cn) {
         goto L25;
      }
   L50:
      ret_val += objcts_1.osize[i__ - 1];
   L100:
      ;
   }
   return ret_val;
} /* weight_ */

#undef eqo
