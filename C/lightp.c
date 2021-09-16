#include "F2C.h"

// Common Block Declarations

extern struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;

#define prsvec_1 prsvec_

extern struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

extern struct {
   int lastit;
} last_;

#define last_1 last_

extern struct {
   int act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

extern struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

extern struct {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

extern struct {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

extern struct {
   int winner, here;
   Bool telflg;
} play_;

#define play_1 play_

extern struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

extern struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

extern struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

extern struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;

#define cevent_1 cevent_

extern struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

extern struct {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// LIGHTP-	LIGHT PROCESSOR

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool lightp_(int obj) {
// System generated locals
   Bool ret_val;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   static int flobts;
   extern void rspeak_(int);
   extern void newsta_(int, int, int, int, int);
   static int i__;
#define eqc ((int *)&cevent_1 + 1)
   extern void bug_(int, int);
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// OBJECTS

// CLOCK INTERRUPTS

// VERBS

// FUNCTIONS AND DATA

// FLAGS

// LIGHTP, PAGE 2

   ret_val = true;
// 						!ASSUME WINS
   flobts = oflags_1.flambt + oflags_1.litebt + oflags_1.onbt;
   if (obj != oindex_1.candl) {
      goto L20000;
   }
// 						!CANDLE?
   if (findex_1.orcand != 0) {
      goto L19100;
   }
// 						!FIRST REF?
   findex_1.orcand = 1;
// 						!YES, CANDLES ARE
   cevent_1.ctick[cindex_1.cevcnd - 1] = 50;
// 						!BURNING WHEN SEEN.

L19100:
   if (prsvec_1.prsi == oindex_1.candl) {
      goto L10;
   }
// 						!IGNORE IND REFS.
   if (prsvec_1.prsa != vindex_1.trnofw) {
      goto L19200;
   }
// 						!TURN OFF?
   i__ = 513;
// 						!ASSUME OFF.
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      i__ = 514;
   }
// 						!IF ON, DIFFERENT.
   cevent_1.cflag[cindex_1.cevcnd - 1] = false;
// 						!DISABLE COUNTDOWN.
   objcts_1.oflag1[oindex_1.candl - 1] &= ~oflags_1.onbt;
   rspeak_(i__);
   return ret_val;

L19200:
   if (prsvec_1.prsa != vindex_1.burnw && prsvec_1.prsa != vindex_1.trnonw) {
      goto L10;
   }
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.litebt) != 0) {
      goto L19300;
   }
   rspeak_(515);
// 						!CANDLES TOO SHORT.
   return ret_val;

L19300:
   if (prsvec_1.prsi != 0) {
      goto L19400;
   }
// 						!ANY FLAME?
   rspeak_(516);
// 						!NO, LOSE.
   prsvec_1.prswon = false;
   return ret_val;

L19400:
   if (prsvec_1.prsi != oindex_1.match || !((objcts_1.oflag1[oindex_1.match - 1] & oflags_1.onbt) != 0)) {
      goto L19500;
   }
   i__ = 517;
// 						!ASSUME OFF.
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      i__ = 518;
   }
// 						!IF ON, JOKE.
   objcts_1.oflag1[oindex_1.candl - 1] |= oflags_1.onbt;
   cevent_1.cflag[cindex_1.cevcnd - 1] = true;
// 						!RESUME COUNTDOWN.
   rspeak_(i__);
   return ret_val;

L19500:
   if (prsvec_1.prsi != oindex_1.torch || !((objcts_1.oflag1[oindex_1.torch - 1] & oflags_1.onbt) != 0)) {
      goto L19600;
   }
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      goto L19700;
   }
// 						!ALREADY ON?
   newsta_(oindex_1.candl, 521, 0, 0, 0);
// 						!NO, VAPORIZE.
   return ret_val;

L19600:
   rspeak_(519);
// 						!CANT LIGHT WITH THAT.
   return ret_val;

L19700:
   rspeak_(520);
// 						!ALREADY ON.
   return ret_val;

L20000:
   if (obj != oindex_1.match) {
      bug_(6, obj);
   }
   if (prsvec_1.prsa != vindex_1.trnonw || prsvec_1.prso != oindex_1.match) {
      goto L20500;
   }
   if (findex_1.ormtch != 0) {
      goto L20100;
   }
// 						!ANY MATCHES LEFT?
   rspeak_(183);
// 						!NO, LOSE.
   return ret_val;

L20100:
   --findex_1.ormtch;
// 						!DECREMENT NO MATCHES.
   objcts_1.oflag1[oindex_1.match - 1] |= flobts;
   cevent_1.ctick[cindex_1.cevmat - 1] = 2;
// 						!COUNTDOWN.
   rspeak_(184);
   return ret_val;

L20500:
   if (prsvec_1.prsa != vindex_1.trnofw || (objcts_1.oflag1[oindex_1.match - 1] & oflags_1.onbt) == 0) {
      goto L10;
   }
   objcts_1.oflag1[oindex_1.match - 1] &= ~flobts;
   cevent_1.ctick[cindex_1.cevmat - 1] = 0;
   rspeak_(185);
   return ret_val;

// HERE FOR FALSE RETURN

L10:
   ret_val = false;
   return ret_val;
}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqc
#undef switch__
#undef flags
