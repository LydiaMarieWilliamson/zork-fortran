/*  -- translated by f2c (version 20190311).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
   integer winner, here;
   logical telflg;
} play_;

#define play_1 play_

struct {
   integer rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   integer rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

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
   integer visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt,
      schbt;
} oflags_;

#define oflags_1 oflags_

struct {
   integer garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw,
      cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage,
      spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs,
      sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

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

struct {
   logical trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf,
      frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   integer btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

/* Table of constant values */

static integer c__502 = 502;
static integer c__578 = 578;
static integer c__573 = 573;

/* PRINCR- PRINT CONTENTS OF ROOM */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* DECLARATIONS */

/* Subroutine */ int princr_(logical * full, integer * rm) {
/* System generated locals */
   integer i__1, i__2;

/* Local variables */
   static integer i__, j, k;
#define eqa ((integer *)&advs_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
   extern logical qhere_(integer *, integer *);
#define rrand ((integer *)&rooms_1 + 602)
   extern logical qempty_(integer *);
#define flags ((logical *)&findex_1)
#define switch__ ((integer *)&findex_1 + 46)
   extern /* Subroutine */ int rspeak_(integer *), rspsub_(integer *,
      integer *), invent_(integer *);
   extern integer oactor_(integer *);
   extern /* Subroutine */ int princo_(integer *, integer *);

/* GAME STATE */

/* ROOMS */

/* OBJECTS */

/* ADVENTURERS */

/* PRINCR, PAGE 2 */

/* FLAGS */

   j = 329;
/* 						!ASSUME SUPERBRIEF FORMAT. */
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!LOOP ON OBJECTS */
      if (!qhere_(&i__, rm) || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt + oflags_1.ndscbt) != oflags_1.visibt || i__ == advs_1.avehic[play_1.winner - 1]) {
         goto L500;
      }
      if (!(*full) && (findex_1.superf || findex_1.brieff && (rooms_1.rflag[play_1.here - 1] & rflag_1.rseen) != 0)) {
         goto L200;
      }

   /* DO LONG DESCRIPTION OF OBJECT. */

      k = objcts_1.odesco[i__ - 1];
/* 						!GET UNTOUCHED. */
      if (k == 0 || (objcts_1.oflag2[i__ - 1] & oflags_1.tchbt) != 0) {
         k = objcts_1.odesc1[i__ - 1];
      }
      rspeak_(&k);
/* 						!DESCRIBE. */
      goto L500;
/* DO SHORT DESCRIPTION OF OBJECT. */

    L200:
      rspsub_(&j, &objcts_1.odesc2[i__ - 1]);
/* 						!YOU CAN SEE IT. */
      j = 502;

    L500:
      ;
   }

/* NOW LOOP TO PRINT CONTENTS OF OBJECTS IN ROOM. */

   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!LOOP ON OBJECTS. */
      if (!qhere_(&i__, rm) || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt + oflags_1.ndscbt) != oflags_1.visibt) {
         goto L1000;
      }
      if ((objcts_1.oflag2[i__ - 1] & oflags_1.actrbt) != 0) {
         i__2 = oactor_(&i__);
         invent_(&i__2);
      }
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[i__ - 1] & oflags_1.openbt) == 0 || qempty_(&i__)) {
         goto L1000;
      }

   /* OBJECT IS NOT EMPTY AND IS OPEN OR TRANSPARENT. */

      j = 573;
      if (i__ != oindex_1.tcase) {
         goto L600;
      }
/* 						!TROPHY CASE? */
      j = 574;
      if ((findex_1.brieff || findex_1.superf) && !(*full)) {
         goto L1000;
      }
    L600:
      princo_(&i__, &j);
/* 						!PRINT CONTENTS. */

    L1000:
      ;
   }
   return 0;

} /* princr_ */

#undef switch__
#undef flags
#undef rrand
#undef eqr
#undef eqo
#undef eqa

/* INVENT- PRINT CONTENTS OF ADVENTURER */

/* DECLARATIONS */

/* Subroutine */ int invent_(integer * adv) {
/* System generated locals */
   integer i__1;

/* Local variables */
   static integer i__, j;
#define eqa ((integer *)&advs_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
   extern /* Subroutine */ int rspeak_(integer *), princo_(integer *,
      integer *);
   extern logical qempty_(integer *);
   extern /* Subroutine */ int rspsub_(integer *, integer *);

/* GAME STATE */

/* OBJECTS */

/* INVENT, PAGE 2 */

/* ADVENTURERS */

   i__ = 575;
/* 						!FIRST LINE. */
   if (*adv != aindex_1.player) {
      i__ = 576;
   }
/* 						!IF NOT ME. */
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
/* 						!LOOP */
      if (objcts_1.oadv[j - 1] != *adv || (objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0) {
         goto L10;
      }
      rspsub_(&i__, &objcts_1.odesc2[advs_1.aobj[*adv - 1] - 1]);
      i__ = 0;
      rspsub_(&c__502, &objcts_1.odesc2[j - 1]);
    L10:
      ;
   }

   if (i__ == 0) {
      goto L25;
   }
/* 						!ANY OBJECTS? */
   if (*adv == aindex_1.player) {
      rspeak_(&c__578);
   }
/* 						!NO, TELL HIM. */
   return 0;

 L25:
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
/* 						!LOOP. */
      if (objcts_1.oadv[j - 1] != *adv || (objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[j - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[j - 1] & oflags_1.openbt) == 0) {
         goto L100;
      }
      if (!qempty_(&j)) {
         princo_(&j, &c__573);
      }
/* 						!IF NOT EMPTY, LIST. */
    L100:
      ;
   }
   return 0;

} /* invent_ */

#undef eqo
#undef eqa

/* PRINCO-	PRINT CONTENTS OF OBJECT */

/* DECLARATIONS */

/* Subroutine */ int princo_(integer * obj, integer * desc) {
/* System generated locals */
   integer i__1;

/* Local variables */
   static integer i__;
#define eqo ((integer *)&objcts_1 + 1)
   extern /* Subroutine */ int rspsub_(integer *, integer *);

/* OBJECTS */

   rspsub_(desc, &objcts_1.odesc2[*obj - 1]);
/* 						!PRINT HEADER. */
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!LOOP THRU. */
      if (objcts_1.ocan[i__ - 1] == *obj) {
         rspsub_(&c__502, &objcts_1.odesc2[i__ - 1]);
      }
/* L100: */
   }
   return 0;

} /* princo_ */

#undef eqo
