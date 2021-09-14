#include "F2C.h"

/* Common Block Declarations */

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
   integer winner, here;
   logical telflg;
} play_;

#define play_1 play_

struct {
   integer moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

struct {
   integer rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   integer rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

struct {
   integer xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_

struct {
   integer xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;

#define xpars_1 xpars_

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
   integer garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

struct {
   integer clnt, ctick[25], cactio[25];
   logical cflag[25];
} cevent_;

#define cevent_1 cevent_

struct {
   integer cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

struct {
   integer cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

struct {
   logical trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   integer btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

/* Table of constant values */

static integer c__543 = 543;
static integer c__544 = 544;
static integer c__545 = 545;
static integer c__546 = 546;
static integer c__547 = 547;
static integer c__548 = 548;
static integer c__549 = 549;
static integer c__550 = 550;
static integer c__0 = 0;
static integer c__551 = 551;

/* BALLOP-	BALLOON FUNCTION */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* DECLARATIONS */

logical ballop_(integer * arg) {
/* System generated locals */
   logical ret_val;

/* Local variables */
#define flags ((logical *)&findex_1)
#define switch__ ((integer *)&findex_1 + 46)
   extern /* Subroutine */ int rspeak_(integer *), rspsub_(integer *, integer *), newsta_(integer *, integer *, integer *, integer *, integer *);
#define eqc ((integer *)&cevent_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
#define xflag ((integer *)&curxt_1 + 4)
#define rrand ((integer *)&rooms_1 + 602)
#define objvec ((integer *)&pv_1 + 1)
   extern logical findxt_(integer *, integer *);
#define prpvec ((integer *)&pv_1 + 3)
   extern logical qempty_(integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* ROOMS */

/* CURRENT EXITS */

/* OBJECTS */

/* CLOCK INTERRUPTS */

/* VERBS */

/* BALLOP, PAGE 2 */

/* FLAGS */

   ret_val = TRUE_;
/* 						!ASSUME WINS. */
   if (*arg != 2) {
      goto L200;
   }
/* 						!READOUT? */
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L10;
   }
/* 						!ONLY PROCESS LOOK. */
   if (findex_1.binff != 0) {
      goto L50;
   }
/* 						!INFLATED? */
   rspeak_(&c__543);
/* 						!NO. */
   goto L100;
L50:
   rspsub_(&c__544, &objcts_1.odesc2[findex_1.binff - 1]);
/* 						!YES. */
L100:
   if (findex_1.btief != 0) {
      rspeak_(&c__545);
   }
/* 						!HOOKED? */
   return ret_val;

L200:
   if (*arg != 1) {
      goto L500;
   }
/* 						!READIN? */
   if (prsvec_1.prsa != vindex_1.walkw) {
      goto L300;
   }
/* 						!WALK? */
   if (findxt_(&prsvec_1.prso, &play_1.here)) {
      goto L250;
   }
/* 						!VALID EXIT? */
   rspeak_(&c__546);
/* 						!NO, JOKE. */
   return ret_val;

L250:
   if (findex_1.btief == 0) {
      goto L275;
   }
/* 						!TIED UP? */
   rspeak_(&c__547);
/* 						!YES, JOKE. */
   return ret_val;

L275:
   if (curxt_1.xtype != xpars_1.xnorm) {
      goto L10;
   }
/* 						!NORMAL EXIT? */
   if ((rooms_1.rflag[curxt_1.xroom1 - 1] & rflag_1.rmung) == 0) {
      state_1.bloc = curxt_1.xroom1;
   }
L10:
   ret_val = FALSE_;
   return ret_val;

L300:
   if (prsvec_1.prsa != vindex_1.takew || prsvec_1.prso != findex_1.binff) {
      goto L350;
   }
   rspsub_(&c__548, &objcts_1.odesc2[findex_1.binff - 1]);
/* 						!RECEP CONT TOO HOT. */
   return ret_val;

L350:
   if (prsvec_1.prsa != vindex_1.putw || prsvec_1.prsi != oindex_1.recep || qempty_(&oindex_1.recep)) {
      goto L10;
   }
   rspeak_(&c__549);
   return ret_val;

L500:
   if (prsvec_1.prsa != vindex_1.unboaw || (rooms_1.rflag[play_1.here - 1] & rflag_1.rland) == 0) {
      goto L600;
   }
   if (findex_1.binff != 0) {
      cevent_1.ctick[cindex_1.cevbal - 1] = 3;
   }
/* 						!HE GOT OUT, START BALLOON. */
   goto L10;

L600:
   if (prsvec_1.prsa != vindex_1.burnw || objcts_1.ocan[prsvec_1.prso - 1] != oindex_1.recep) {
      goto L700;
   }
   rspsub_(&c__550, &objcts_1.odesc2[prsvec_1.prso - 1]);
/* 						!LIGHT FIRE IN RECEP. */
   cevent_1.ctick[cindex_1.cevbrn - 1] = objcts_1.osize[prsvec_1.prso - 1] * 20;
   objcts_1.oflag1[prsvec_1.prso - 1] |= oflags_1.onbt + oflags_1.flambt + oflags_1.litebt & ~(oflags_1.takebt + oflags_1.readbt);
   if (findex_1.binff != 0) {
      return ret_val;
   }
   if (!findex_1.blabf) {
      newsta_(&oindex_1.blabe, &c__0, &c__0, &oindex_1.ballo, &c__0);
   }
   findex_1.blabf = TRUE_;
   findex_1.binff = prsvec_1.prso;
   cevent_1.ctick[cindex_1.cevbal - 1] = 3;
   rspeak_(&c__551);
   return ret_val;

L700:
   if (prsvec_1.prsa == vindex_1.unboaw && findex_1.binff != 0 && (rooms_1.rflag[play_1.here - 1] & rflag_1.rland) != 0) {
      cevent_1.ctick[cindex_1.cevbal - 1] = 3;
   }
   goto L10;

} /* ballop_ */

#undef prpvec
#undef objvec
#undef rrand
#undef xflag
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqc
#undef switch__
#undef flags
