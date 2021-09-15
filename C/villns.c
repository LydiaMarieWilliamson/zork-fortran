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
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

extern struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

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
   int thfpos;
   Bool thfflg, thfact, swdact;
   int swdsta;
} hack_;

#define hack_1 hack_

extern struct {
   int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_

// Table of constant values

static int c__0 = 0;
static int c__437 = 437;
static int c__33 = 33;
static int c__66 = 66;
static int c__438 = 438;
static int c__439 = 439;
static int c__442 = 442;
static int c__443 = 443;
static int c__366 = 366;
static int c__187 = 187;
static int c__188 = 188;
static int c__189 = 189;
static int c__190 = 190;
static int c__191 = 191;
static int c__2 = 2;
static int c__498 = 498;
static int c__499 = 499;
static int c__20 = 20;
static int c__75 = 75;
static int c__626 = 626;
static int c__505 = 505;
static int c__506 = 506;
static int c__10 = 10;
static int c__507 = 507;
static int c__510 = 510;
static int c__511 = 511;
static int c__512 = 512;
static int c__627 = 627;

// TROLLP-	TROLL FUNCTION

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool trollp_(int * arg) {
// System generated locals
   Bool ret_val;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool prob_(int *, int *), qhere_(int *, int *);
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void newsta_(int *, int *, int *, int *, int *), rspeak_(int *), rspsub_(int *, int *);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// OBJECTS

// VERBS

// TROLLP, PAGE 2

// FLAGS

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prsa != vindex_1.fightw) {
      goto L1100;
   }
// 						!FIGHT?
   if (objcts_1.ocan[oindex_1.axe - 1] == oindex_1.troll) {
      goto L10;
   }
// 						!GOT AXE?  NOTHING.
   i__ = 433;
// 						!ASSUME CANT GET.
   if (!qhere_(&oindex_1.axe, &play_1.here)) {
      goto L1050;
   }
// 						!HERE?
   i__ = 434;
// 						!YES, RECOVER.
   newsta_(&oindex_1.axe, &c__0, &c__0, &oindex_1.troll, &c__0);
L1050:
   if (qhere_(&oindex_1.troll, &play_1.here)) {
      rspeak_(&i__);
   }
// 						!IF PLAYER HERE.
   return ret_val;

L1100:
   if (prsvec_1.prsa != vindex_1.deadxw) {
      goto L1200;
   }
// 						!DEAD?
   findex_1.trollf = true;
// 						!PERMIT EXITS.
   return ret_val;

L1200:
   if (prsvec_1.prsa != vindex_1.outxw) {
      goto L1300;
   }
// 						!OUT?
   findex_1.trollf = true;
// 						!PERMIT EXITS.
   objcts_1.oflag1[oindex_1.axe - 1] &= ~oflags_1.visibt;
   objcts_1.odesc1[oindex_1.troll - 1] = 435;
// 						!TROLL OUT.
   return ret_val;

L1300:
   if (prsvec_1.prsa != vindex_1.inxw) {
      goto L1400;
   }
// 						!WAKE UP?
   findex_1.trollf = false;
// 						!FORBID EXITS.
   objcts_1.oflag1[oindex_1.axe - 1] |= oflags_1.visibt;
   objcts_1.odesc1[oindex_1.troll - 1] = 436;
// 						!TROLL IN.
   if (qhere_(&oindex_1.troll, &play_1.here)) {
      rspeak_(&c__437);
   }
   return ret_val;

L1400:
   if (prsvec_1.prsa != vindex_1.frstqw) {
      goto L1500;
   }
// 						!FIRST ENCOUNTER?
   ret_val = prob_(&c__33, &c__66);
// 						!33% TRUE UNLESS BADLK.
   return ret_val;

L1500:
   if (prsvec_1.prsa != vindex_1.movew && prsvec_1.prsa != vindex_1.takew && prsvec_1.prsa != vindex_1.mungw && prsvec_1.prsa != vindex_1.throww && prsvec_1.prsa != vindex_1.givew) {
      goto L2000;
   }
   if (objcts_1.ocapac[oindex_1.troll - 1] >= 0) {
      goto L1550;
   }
// 						!TROLL OUT?
   objcts_1.ocapac[oindex_1.troll - 1] = -objcts_1.ocapac[oindex_1.troll - 1];
// 						!YES, WAKE HIM.
   objcts_1.oflag1[oindex_1.axe - 1] |= oflags_1.visibt;
   findex_1.trollf = false;
   objcts_1.odesc1[oindex_1.troll - 1] = 436;
   rspeak_(&c__437);

L1550:
   if (prsvec_1.prsa != vindex_1.takew && prsvec_1.prsa != vindex_1.movew) {
      goto L1600;
   }
   rspeak_(&c__438);
// 						!JOKE.
   return ret_val;

L1600:
   if (prsvec_1.prsa != vindex_1.mungw) {
      goto L1700;
   }
// 						!MUNG?
   rspeak_(&c__439);
// 						!JOKE.
   return ret_val;

L1700:
   if (prsvec_1.prso == 0) {
      goto L10;
   }
// 						!NO OBJECT?
   i__ = 440;
// 						!ASSUME THROW.
   if (prsvec_1.prsa == vindex_1.givew) {
      i__ = 441;
   }
// 						!GIVE?
   rspsub_(&i__, &objcts_1.odesc2[prsvec_1.prso - 1]);
// 						!TROLL TAKES.
   if (prsvec_1.prso == oindex_1.knife) {
      goto L1900;
   }
// 						!OBJ KNIFE?
   newsta_(&prsvec_1.prso, &c__442, &c__0, &c__0, &c__0);
// 						!NO, EATS IT.
   return ret_val;

L1900:
   rspeak_(&c__443);
// 						!KNIFE, THROWS IT BACK
   objcts_1.oflag2[oindex_1.troll - 1] |= oflags_1.fitebt;
   return ret_val;

L2000:
   if (!findex_1.trollf || prsvec_1.prsa != vindex_1.hellow) {
      goto L10;
   }
   rspeak_(&c__366);
// 						!TROLL OUT.
   return ret_val;

L10:
   ret_val = false;
// 						!COULDNT HANDLE IT.
   return ret_val;
}

#undef switch__
#undef flags
#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo

// CYCLOP-	CYCLOPS FUNCTION

// DECLARATIONS

Bool cyclop_(int * arg) {
// System generated locals
   int i__1, i__2;
   Bool ret_val;

// Local variables
   static int i__;
   extern int rnd_(int *);
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void rspeak_(int *), jigsup_(int *), newsta_(int *, int *, int *, int *, int *);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// OBJECTS

// VERBS

// CYCLOP, PAGE 2

// FLAGS

   ret_val = true;
// 						!ASSUME WINS.
   if (!findex_1.cyclof) {
      goto L100;
   }
// 						!ASLEEP?
   if (prsvec_1.prsa != vindex_1.alarmw && prsvec_1.prsa != vindex_1.mungw && prsvec_1.prsa != vindex_1.hellow && prsvec_1.prsa != vindex_1.burnw && prsvec_1.prsa != vindex_1.killw && prsvec_1.prsa != vindex_1.attacw) {
      goto L10;
   }
   findex_1.cyclof = false;
// 						!WAKE CYCLOPS.
   rspeak_(&c__187);
// 						!DESCRIBE.
   findex_1.rvcyc = abs(findex_1.rvcyc);
   objcts_1.oflag2[oindex_1.cyclo - 1] = (objcts_1.oflag2[oindex_1.cyclo - 1] | oflags_1.fitebt) & ~oflags_1.slepbt;
   return ret_val;

L100:
   if (prsvec_1.prsa == vindex_1.fightw || prsvec_1.prsa == vindex_1.frstqw) {
      goto L10;
   }
   if (abs(findex_1.rvcyc) <= 5) {
      goto L200;
   }
// 						!ANNOYED TOO MUCH?
   findex_1.rvcyc = 0;
// 						!RESTART COUNT.
   jigsup_(&c__188);
// 						!YES, EATS PLAYER.
   return ret_val;

L200:
   if (prsvec_1.prsa != vindex_1.givew) {
      goto L500;
   }
// 						!GIVE?
   if (prsvec_1.prso != oindex_1.food || findex_1.rvcyc < 0) {
      goto L300;
   }
// 						!FOOD WHEN HUNGRY?
   newsta_(&oindex_1.food, &c__189, &c__0, &c__0, &c__0);
// 						!EATS PEPPERS.
// Computing MIN
   i__1 = -1, i__2 = -findex_1.rvcyc;
   findex_1.rvcyc = min(i__1, i__2);
// 						!GETS THIRSTY.
   return ret_val;

L300:
   if (prsvec_1.prso != oindex_1.water) {
      goto L400;
   }
// 						!DRINK WHEN THIRSTY?
   if (findex_1.rvcyc >= 0) {
      goto L350;
   }
   newsta_(&prsvec_1.prso, &c__190, &c__0, &c__0, &c__0);
// 						!DRINKS AND
   findex_1.cyclof = true;
// 						!FALLS ASLEEP.
   objcts_1.oflag2[oindex_1.cyclo - 1] = (objcts_1.oflag2[oindex_1.cyclo - 1] | oflags_1.slepbt) & ~oflags_1.fitebt;
   return ret_val;

L350:
   rspeak_(&c__191);
// 						!NOT THIRSTY.
L10:
   ret_val = false;
// 						!FAILS.
   return ret_val;

L400:
   i__ = 192;
// 						!ASSUME INEDIBLE.
   if (prsvec_1.prso == oindex_1.garli) {
      i__ = 193;
   }
// 						!GARLIC IS JOKE.
L450:
   rspeak_(&i__);
// 						!DISDAIN IT.
   if (findex_1.rvcyc < 0) {
      --findex_1.rvcyc;
   }
   if (findex_1.rvcyc >= 0) {
      ++findex_1.rvcyc;
   }
   if (!findex_1.cyclof) {
      i__1 = abs(findex_1.rvcyc) + 193;
      rspeak_(&i__1);
   }
   return ret_val;

L500:
   i__ = 0;
// 						!ASSUME NOT HANDLED.
   if (prsvec_1.prsa == vindex_1.hellow) {
      goto L450;
   }
// 						!HELLO IS NO GO.
   if (prsvec_1.prsa == vindex_1.throww || prsvec_1.prsa == vindex_1.mungw) {
      i__ = rnd_(&c__2) + 200;
   }
   if (prsvec_1.prsa == vindex_1.takew) {
      i__ = 202;
   }
   if (prsvec_1.prsa == vindex_1.tiew) {
      i__ = 203;
   }
   if (i__ <= 0) {
      goto L10;
   } else {
      goto L450;
   }
// 						!SEE IF HANDLED.

}

#undef switch__
#undef flags
#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo

// THIEFP-	THIEF FUNCTION

// DECLARATIONS

Bool thiefp_(int * arg) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void newsta_(int *, int *, int *, int *, int *), rspeak_(int *), rspsub_(int *, int *);
   static int i__, j;
#define eqc ((int *)&cevent_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool prob_(int *, int *), qhere_(int *, int *);
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// ROOMS

// GAME STATE

// OBJECTS

// CLOCK INTERRUPTS

// VILLAINS AND DEMONS

// VERBS

// THIEFP, PAGE 2

// FLAGS

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prsa != vindex_1.fightw) {
      goto L100;
   }
// 						!FIGHT?
   if (objcts_1.ocan[oindex_1.still - 1] == oindex_1.thief) {
      goto L10;
   }
// 						!GOT STILLETTO?  F.
   if (qhere_(&oindex_1.still, &hack_1.thfpos)) {
      goto L50;
   }
// 						!CAN HE RECOVER IT?
   newsta_(&oindex_1.thief, &c__0, &c__0, &c__0, &c__0);
// 						!NO, VANISH.
   if (qhere_(&oindex_1.thief, &play_1.here)) {
      rspeak_(&c__498);
   }
// 						!IF HERO, TELL.
   return ret_val;

L50:
   newsta_(&oindex_1.still, &c__0, &c__0, &oindex_1.thief, &c__0);
// 						!YES, RECOVER.
   if (qhere_(&oindex_1.thief, &play_1.here)) {
      rspeak_(&c__499);
   }
// 						!IF HERO, TELL.
   return ret_val;

L100:
   if (prsvec_1.prsa != vindex_1.deadxw) {
      goto L200;
   }
// 						!DEAD?
   hack_1.thfact = false;
// 						!DISABLE DEMON.
   objcts_1.oflag1[oindex_1.chali - 1] |= oflags_1.takebt;
   j = 0;
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CARRYING ANYTHING?
// L125:
      if (objcts_1.oadv[i__ - 1] == -oindex_1.thief) {
         j = 500;
      }
   }
   rspeak_(&j);
// 						!TELL IF BOOTY REAPPEARS.

   j = 501;
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP.
      if (i__ == oindex_1.chali || i__ == oindex_1.thief || play_1.here != rindex_1.treas || !qhere_(&i__, &play_1.here)) {
         goto L135;
      }
      objcts_1.oflag1[i__ - 1] |= oflags_1.visibt;
      rspsub_(&j, &objcts_1.odesc2[i__ - 1]);
// 						!DESCRIBE.
      j = 502;
      goto L150;

   L135:
      if (objcts_1.oadv[i__ - 1] == -oindex_1.thief) {
         newsta_(&i__, &c__0, &play_1.here, &c__0, &c__0);
      }
   L150:
      ;
   }
   return ret_val;

L200:
   if (prsvec_1.prsa != vindex_1.frstqw) {
      goto L250;
   }
// 						!FIRST ENCOUNTER?
   ret_val = prob_(&c__20, &c__75);
   return ret_val;

L250:
   if (prsvec_1.prsa != vindex_1.hellow || objcts_1.odesc1[oindex_1.thief - 1] != 504) {
      goto L300;
   }
   rspeak_(&c__626);
   return ret_val;

L300:
   if (prsvec_1.prsa != vindex_1.outxw) {
      goto L400;
   }
// 						!OUT?
   hack_1.thfact = false;
// 						!DISABLE DEMON.
   objcts_1.odesc1[oindex_1.thief - 1] = 504;
// 						!CHANGE DESCRIPTION.
   objcts_1.oflag1[oindex_1.still - 1] &= ~oflags_1.visibt;
   objcts_1.oflag1[oindex_1.chali - 1] |= oflags_1.takebt;
   return ret_val;

L400:
   if (prsvec_1.prsa != vindex_1.inxw) {
      goto L500;
   }
// 						!IN?
   if (qhere_(&oindex_1.thief, &play_1.here)) {
      rspeak_(&c__505);
   }
// 						!CAN HERO SEE?
   hack_1.thfact = true;
// 						!ENABLE DEMON.
   objcts_1.odesc1[oindex_1.thief - 1] = 503;
// 						!CHANGE DESCRIPTION.
   objcts_1.oflag1[oindex_1.still - 1] |= oflags_1.visibt;
   if (play_1.here == rindex_1.treas && qhere_(&oindex_1.chali, &play_1.here)) {
      objcts_1.oflag1[oindex_1.chali - 1] &= ~oflags_1.takebt;
   }
   return ret_val;

L500:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L600;
   }
// 						!TAKE?
   rspeak_(&c__506);
// 						!JOKE.
   return ret_val;

L600:
   if (prsvec_1.prsa != vindex_1.throww || prsvec_1.prso != oindex_1.knife || (objcts_1.oflag2[oindex_1.thief - 1] & oflags_1.fitebt) != 0) {
      goto L700;
   }
   if (prob_(&c__10, &c__10)) {
      goto L650;
   }
// 						!THREW KNIFE, 10%?
   rspeak_(&c__507);
// 						!NO, JUST MAKES
   objcts_1.oflag2[oindex_1.thief - 1] |= oflags_1.fitebt;
   return ret_val;

L650:
   j = 508;
// 						!THIEF DROPS STUFF.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (objcts_1.oadv[i__ - 1] != -oindex_1.thief) {
         goto L675;
      }
// 						!THIEF CARRYING?
      j = 509;
      newsta_(&i__, &c__0, &play_1.here, &c__0, &c__0);
   L675:
      ;
   }
   newsta_(&oindex_1.thief, &j, &c__0, &c__0, &c__0);
// 						!THIEF VANISHES.
   return ret_val;

L700:
   if (prsvec_1.prsa != vindex_1.throww && prsvec_1.prsa != vindex_1.givew || prsvec_1.prso == 0 || prsvec_1.prso == oindex_1.thief) {
      goto L10;
   }
   if (objcts_1.ocapac[oindex_1.thief - 1] >= 0) {
      goto L750;
   }
// 						!WAKE HIM UP.
   objcts_1.ocapac[oindex_1.thief - 1] = -objcts_1.ocapac[oindex_1.thief - 1];
   hack_1.thfact = true;
   objcts_1.oflag1[oindex_1.still - 1] |= oflags_1.visibt;
   objcts_1.odesc1[oindex_1.thief - 1] = 503;
   rspeak_(&c__510);

L750:
   if (prsvec_1.prso != oindex_1.brick || objcts_1.ocan[oindex_1.fuse - 1] != oindex_1.brick || cevent_1.ctick[cindex_1.cevfus - 1] == 0) {
      goto L800;
   }
   rspeak_(&c__511);
// 						!THIEF REFUSES BOMB.
   return ret_val;

L800:
   i__1 = -oindex_1.thief;
   newsta_(&prsvec_1.prso, &c__0, &c__0, &c__0, &i__1);
// 						!THIEF TAKES GIFT.
   if (objcts_1.otval[prsvec_1.prso - 1] > 0) {
      goto L900;
   }
// 						!A TREASURE?
   rspsub_(&c__512, &objcts_1.odesc2[prsvec_1.prso - 1]);
   return ret_val;

L900:
   rspsub_(&c__627, &objcts_1.odesc2[prsvec_1.prso - 1]);
// 						!THIEF ENGROSSED.
   findex_1.thfenf = true;
   return ret_val;

L10:
   ret_val = false;
   return ret_val;
}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqo
#undef eqc
#undef switch__
#undef flags