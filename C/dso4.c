#include "F2C.h"

// Common Block Declarations

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
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

struct {
   int astag;
} aflags_;

#define aflags_1 aflags_

struct {
   int player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;

#define prsvec_1 prsvec_

struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

struct {
   int lastit;
} last_;

#define last_1 last_

struct {
   int act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

struct {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

struct {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

struct {
   int thfpos;
   Bool thfflg, thfact, swdact;
   int swdsta;
} hack_;

#define hack_1 hack_

struct {
   int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_

struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// Table of constant values

static int c__0 = 0;
static Bool c_true = true;
static int c__90 = 90;
static int c__100 = 100;
static int c__75 = 75;
static int c__85 = 85;
static int c__50 = 50;
static int c__30 = 30;
static int c__25 = 25;
static int c__10 = 10;

// ROBADV-- STEAL WINNER'S VALUABLES

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

int robadv_(int * adv, int * nr, int * nc, int * na) {
// System generated locals
   int ret_val, i__1;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)
   extern Void newsta_(int *, int *, int *, int *, int *);

// OBJECTS

   ret_val = 0;
// 						!COUNT OBJECTS
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (objcts_1.oadv[i__ - 1] != *adv || objcts_1.otval[i__ - 1] <= 0 || (objcts_1.oflag2[i__ - 1] & oflags_1.scrdbt) != 0) {
         goto L100;
      }
      newsta_(&i__, &c__0, nr, nc, na);
// 						!STEAL OBJECT
      ++ret_val;
   L100:
      ;
   }
   return ret_val;
}

#undef eqo

// ROBRM-- STEAL ROOM VALUABLES

// DECLARATIONS

int robrm_(int * rm, int * pr, int * nr, int * nc, int * na) {
// System generated locals
   int ret_val, i__1, i__2;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)
   extern Bool prob_(int *, int *), qhere_(int *, int *);
   extern Void newsta_(int *, int *, int *, int *, int *);
   extern int robadv_(int *, int *, int *, int *), oactor_(int *);

// OBJECTS

   ret_val = 0;
// 						!COUNT OBJECTS
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP ON OBJECTS.
      if (!qhere_(&i__, rm)) {
         goto L100;
      }
      if (objcts_1.otval[i__ - 1] <= 0 || (objcts_1.oflag2[i__ - 1] & oflags_1.scrdbt) != 0 || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt) == 0 || !prob_(pr, pr)) {
         goto L50;
      }
      newsta_(&i__, &c__0, nr, nc, na);
      ++ret_val;
      objcts_1.oflag2[i__ - 1] |= oflags_1.tchbt;
      goto L100;
   L50:
      if ((objcts_1.oflag2[i__ - 1] & oflags_1.actrbt) != 0) {
         i__2 = oactor_(&i__);
         ret_val += robadv_(&i__2, nr, nc, na);
      }
   L100:
      ;
   }
   return ret_val;
}

#undef eqo

// WINNIN-- SEE IF VILLAIN IS WINNING

// DECLARATIONS

Bool winnin_(int * vl, int * hr) {
// System generated locals
   Bool ret_val;

// Local variables
   static int ps, vs;
#define eqo ((int *)&objcts_1 + 1)
   extern Bool prob_(int *, int *);
   extern int fights_(int *, Bool *);

// OBJECTS

   vs = objcts_1.ocapac[*vl - 1];
// 						!VILLAIN STRENGTH
   ps = vs - fights_(hr, &c_true);
// 						!HIS MARGIN OVER HERO
   ret_val = prob_(&c__90, &c__100);
   if (ps > 3) {
      return ret_val;
   }
// 						!+3... 90% WINNING
   ret_val = prob_(&c__75, &c__85);
   if (ps > 0) {
      return ret_val;
   }
// 						!>0... 75% WINNING
   ret_val = prob_(&c__50, &c__30);
   if (ps == 0) {
      return ret_val;
   }
// 						!=0... 50% WINNING
   ret_val = prob_(&c__25, &c__25);
   if (vs > 1) {
      return ret_val;
   }
// 						!ANY VILLAIN STRENGTH.
   ret_val = prob_(&c__10, &c__0);
   return ret_val;
}

#undef eqo

// FIGHTS-- COMPUTE FIGHT STRENGTH

// DECLARATIONS

int fights_(int * h__, Bool * flg) {
// Initialized data

   static int smin = 2;
   static int smax = 7;

// System generated locals
   int ret_val;

// Local variables
#define eqa ((int *)&advs_1 + 1)

// GAME STATE

// FUNCTIONS AND DATA

// ADVENTURERS

   ret_val = smin + ((smax - smin) * advs_1.ascore[(20 + (0 + (*h__ - 1 << 2)) - 20) / 4] + state_1.mxscor / 2) / state_1.mxscor;
   if (*flg) {
      ret_val += advs_1.astren[*h__ - 1];
   }
   return ret_val;
}

#undef eqa

// VILSTR-	COMPUTE VILLAIN STRENGTH

// DECLARATIONS

int vilstr_(int * v) {
// System generated locals
   int ret_val, i__1, i__2, i__3;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// PARSER OUTPUT

// PARSER STATE

// OBJECTS

// VILLAINS AND DEMONS

// VILSTR, PAGE 2

// FLAGS

   ret_val = objcts_1.ocapac[*v - 1];
   if (ret_val <= 0) {
      return ret_val;
   }
   if (*v != oindex_1.thief || !findex_1.thfenf) {
      goto L100;
   }
   findex_1.thfenf = false;
// 						!THIEF UNENGROSSED.
   ret_val = min(ret_val, 2);
// 						!NO BETTER THAN 2.

L100:
   i__1 = vill_1.vlnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!SEE IF  BEST WEAPON.
      if (vill_1.villns[i__ - 1] == *v && prsvec_1.prsi == vill_1.vbest[i__ - 1]) {
// Computing MAX
         i__2 = 1, i__3 = ret_val - 1;
         ret_val = max(i__2, i__3);
      }
// L200:
   }
   return ret_val;
}

#undef switch__
#undef flags
#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqo
