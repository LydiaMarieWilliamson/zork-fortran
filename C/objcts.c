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
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

extern struct {
   int batdrp[9];
} bats_;

#define bats_1 bats_

extern struct {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;

#define puzzle_1 puzzle_

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

extern struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

extern struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

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
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

extern struct {
   int astag;
} aflags_;

#define aflags_1 aflags_

extern struct {
   int player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

extern struct {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// Table of constant values

static int c__6 = 6;
static int c__123 = 123;
static int c__124 = 124;
static int c__561 = 561;
static int c__525 = 525;
static int c__615 = 615;
static int c__297 = 297;
static int c__0 = 0;
static int c__612 = 612;
static int c__613 = 613;
static int c__614 = 614;
static int c__133 = 133;
static int c__296 = 296;
static int c__132 = 132;
static int c__158 = 158;
static int c__159 = 159;
static int c__2 = 2;
static int c__344 = 344;
static int c__160 = 160;
static int c__161 = 161;
static int c__169 = 169;
static int c__170 = 170;
static int c__171 = 171;
static int c__298 = 298;
static int c__172 = 172;
static int c__180 = 180;
static int c__181 = 181;
static int c__182 = 182;
static int c__208 = 208;
static int c__209 = 209;
static int c__228 = 228;
static int c__229 = 229;
static int c__50 = 50;
static int c__9 = 9;
static int c__244 = 244;
static int c__247 = 247;
static int c__633 = 633;
static int c__260 = 260;
static int c__100 = 100;
static int c__261 = 261;
static int c__263 = 263;
static int c__148 = 148;
static int c__264 = 264;
static int c__265 = 265;
static int c__269 = 269;
static int c__270 = 270;
static int c__272 = 272;
static int c__290 = 290;
static int c__291 = 291;
static int c__273 = 273;
static int c__280 = 280;
static int c__282 = 282;
static int c__283 = 283;
static int c__284 = 284;
static int c__150 = 150;
static int c__286 = 286;
static int c__287 = 287;
static int c__733 = 733;
static int c__685 = 685;
static int c__734 = 734;
static int c__730 = 730;
static int c__735 = 735;
static int c__736 = 736;
static int c__737 = 737;
static int c__738 = 738;
static int c__742 = 742;
static int c__743 = 743;
static int c__741 = 741;
static int c__744 = 744;
static int c__745 = 745;
static int c__746 = 746;
static int c__747 = 747;
static int c__748 = 748;
static int c__419 = 419;
static int c__865 = 865;
static int c__866 = 866;
static int c__867 = 867;
static int c__3 = 3;

// OAPPLI- OBJECT SPECIAL ACTION ROUTINES

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool oappli_(int ri, int arg) {
// Initialized data

   static int mxsmp = 99;

// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static Bool f;
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   static int flobts, i__;
   extern void rspeak_(int);
   extern void rspsub_(int, int);
   extern void newsta_(int, int, int, int, int);
   extern void jigsup_(int);
   extern int robadv_(int, int, int, int);
   extern int robrm_(int, int, int, int, int);
   static int j,/* x,*/ av, io, ir, iz;
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
   extern void bug_(int, int);
   extern int rnd_(int);
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
   extern Bool lit_(int);
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
   static int odi2, odo2;
#define pvec ((int *)&pv_1)
   static int nloc;
   extern Bool qhere_(int, int);
#define rrand ((int *)&rooms_1 + 602)
   extern Bool nobjs_(int/*, int*/);
   extern Bool sobjs_(int, int);
   extern Bool clockd_(/*int*/);
#define objvec ((int *)&pv_1 + 1)
   extern Bool ballop_(int);
   extern Bool rmdesc_(int);
   extern Bool thiefp_(/*int*/);
   extern Bool lightp_(int);
   extern Bool cyclop_(/*int*/);
   extern Bool opncls_(int, int, int);
#define prpvec ((int *)&pv_1 + 3)
   extern Bool moveto_(int, int);
   extern Bool trollp_(/*int*/);
   extern Bool qempty_(int);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// PUZZLE ROOM

// ROOMS

// OBJECTS

// CLOCK INTERRUPTS

// ADVENTURERS

// VERBS

// FUNCTIONS AND DATA

// FLAGS

// OAPPLI, PAGE 2

   if (ri == 0) {
      goto L10;
   }
// 						!ZERO IS FALSE APP.
   if (ri <= mxsmp) {
      goto L100;
   }
// 						!SIMPLE OBJECT?
   if (prsvec_1.prso > 220) {
      goto L5;
   }
   if (prsvec_1.prso != 0) {
      odo2 = objcts_1.odesc2[prsvec_1.prso - 1];
   }
L5:
   if (prsvec_1.prsi != 0) {
      odi2 = objcts_1.odesc2[prsvec_1.prsi - 1];
   }
   av = advs_1.avehic[play_1.winner - 1];
   flobts = oflags_1.flambt + oflags_1.litebt + oflags_1.onbt;
   ret_val = true;

   switch (ri - mxsmp) {
      case 1:
         goto L2000;
      case 2:
         goto L5000;
      case 3:
         goto L10000;
      case 4:
         goto L11000;
      case 5:
         goto L12000;
      case 6:
         goto L15000;
      case 7:
         goto L18000;
      case 8:
         goto L19000;
      case 9:
         goto L20000;
      case 10:
         goto L22000;
      case 11:
         goto L25000;
      case 12:
         goto L26000;
      case 13:
         goto L32000;
      case 14:
         goto L35000;
      case 15:
         goto L39000;
      case 16:
         goto L40000;
      case 17:
         goto L45000;
      case 18:
         goto L47000;
      case 19:
         goto L48000;
      case 20:
         goto L49000;
      case 21:
         goto L50000;
      case 22:
         goto L51000;
      case 23:
         goto L52000;
      case 24:
         goto L54000;
      case 25:
         goto L55000;
      case 26:
         goto L56000;
      case 27:
         goto L57000;
      case 28:
         goto L58000;
      case 29:
         goto L59000;
      case 30:
         goto L60000;
      case 31:
         goto L61000;
      case 32:
         goto L62000;
   }
   bug_(c__6, ri);

// RETURN HERE TO DECLARE FALSE RESULT

L10:
   ret_val = false;
   return ret_val;

// SIMPLE OBJECTS, PROCESSED EXTERNALLY.

L100:
   if (ri < 32) {
      ret_val = sobjs_(ri, arg);
   }
   if (ri >= 32) {
      ret_val = nobjs_(ri/*, arg*/);
   }
   return ret_val;
// OAPPLI, PAGE 3

// O100--	MACHINE FUNCTION

L2000:
   if (play_1.here != rindex_1.mmach) {
      goto L10;
   }
// 						!NOT HERE? F
   ret_val = opncls_(oindex_1.machi, c__123, c__124);
// 						!HANDLE OPN/CLS.
   return ret_val;

// O101--	WATER FUNCTION

L5000:
   if (prsvec_1.prsa != vindex_1.fillw) {
      goto L5050;
   }
// 						!FILL X WITH Y IS
   prsvec_1.prsa = vindex_1.putw;
// 						!MADE INTO
   i__ = prsvec_1.prsi;
   prsvec_1.prsi = prsvec_1.prso;
   prsvec_1.prso = i__;
// 						!PUT Y IN X.
   i__ = odi2;
   odi2 = odo2;
   odo2 = i__;
L5050:
   if (prsvec_1.prso == oindex_1.water || prsvec_1.prso == oindex_1.gwate) {
      goto L5100;
   }
   rspeak_(c__561);
// 						!WATER IS IND OBJ,
   return ret_val;
// 						!PUNT.

L5100:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L5400;
   }
// 						!TAKE WATER?
   if (objcts_1.oadv[oindex_1.bottl - 1] == play_1.winner && objcts_1.ocan[prsvec_1.prso - 1] != oindex_1.bottl) {
      goto L5500;
   }
   if (objcts_1.ocan[prsvec_1.prso - 1] == 0) {
      goto L5200;
   }
// 						!INSIDE ANYTHING?
   if ((objcts_1.oflag2[objcts_1.ocan[prsvec_1.prso - 1] - 1] & oflags_1.openbt) != 0) {
      goto L5200;
   }
// 						!YES, OPEN?
   rspsub_(c__525, objcts_1.odesc2[objcts_1.ocan[prsvec_1.prso - 1] - 1]);
// 						!INSIDE, CLOSED, PUNT.
   return ret_val;

L5200:
   rspeak_(c__615);
// 						!NOT INSIDE OR OPEN,
   return ret_val;
// 						!SLIPS THRU FINGERS.

L5400:
   if (prsvec_1.prsa != vindex_1.putw) {
      goto L5700;
   }
// 						!PUT WATER IN X?
   if (av != 0 && prsvec_1.prsi == av) {
      goto L5800;
   }
// 						!IN VEH?
   if (prsvec_1.prsi == oindex_1.bottl) {
      goto L5500;
   }
// 						!IN BOTTLE?
   rspsub_(c__297, odi2);
// 						!WONT GO ELSEWHERE.
   newsta_(prsvec_1.prso, c__0, c__0, c__0, c__0);
// 						!VANISH WATER.
   return ret_val;

L5500:
   if ((objcts_1.oflag2[oindex_1.bottl - 1] & oflags_1.openbt) != 0) {
      goto L5550;
   }
// 						!BOTTLE OPEN?
   rspeak_(c__612);
// 						!NO, LOSE.
   return ret_val;

L5550:
   if (qempty_(oindex_1.bottl)) {
      goto L5600;
   }
// 						!OPEN, EMPTY?
   rspeak_(c__613);
// 						!NO, ALREADY FULL.
   return ret_val;

L5600:
   newsta_(oindex_1.water, c__614, c__0, oindex_1.bottl, c__0);
// 						!TAKE WATER TO BOTTLE.
   return ret_val;

L5700:
   if (prsvec_1.prsa != vindex_1.dropw && prsvec_1.prsa != vindex_1.pourw && prsvec_1.prsa != vindex_1.givew) {
      goto L5900;
   }
   if (av != 0) {
      goto L5800;
   }
// 						!INTO VEHICLE?
   newsta_(prsvec_1.prso, c__133, c__0, c__0, c__0);
// 						!NO, VANISHES.
   return ret_val;

L5800:
   newsta_(oindex_1.water, c__0, c__0, av, c__0);
// 						!WATER INTO VEHICLE.
   rspsub_(c__296, objcts_1.odesc2[av - 1]);
// 						!DESCRIBE.
   return ret_val;

L5900:
   if (prsvec_1.prsa != vindex_1.throww) {
      goto L10;
   }
// 						!LAST CHANCE, THROW?
   newsta_(prsvec_1.prso, c__132, c__0, c__0, c__0);
// 						!VANISHES.
   return ret_val;
// OAPPLI, PAGE 4

// O102--	LEAF PILE

L10000:
   if (prsvec_1.prsa != vindex_1.burnw) {
      goto L10500;
   }
// 						!BURN?
   if (objcts_1.oroom[prsvec_1.prso - 1] == 0) {
      goto L10100;
   }
// 						!WAS HE CARRYING?
   newsta_(prsvec_1.prso, c__158, c__0, c__0, c__0);
// 						!NO, BURN IT.
   return ret_val;

L10100:
   newsta_(prsvec_1.prso, c__0, play_1.here, c__0, c__0);
// 						!DROP LEAVES.
   jigsup_(c__159);
// 						!BURN HIM.
   return ret_val;

L10500:
   if (prsvec_1.prsa != vindex_1.movew) {
      goto L10600;
   }
// 						!MOVE?
   rspeak_(c__2);
// 						!DONE.
   return ret_val;

L10600:
   if (prsvec_1.prsa != vindex_1.lookuw || findex_1.rvclr != 0) {
      goto L10;
   }
   rspeak_(c__344);
// 						!LOOK UNDER?
   return ret_val;

// O103--	TROLL, DONE EXTERNALLY.

L11000:
   ret_val = trollp_(/*arg*/);
// 						!TROLL PROCESSOR.
   return ret_val;

// O104--	RUSTY KNIFE.

L12000:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L12100;
   }
// 						!TAKE?
   if (objcts_1.oadv[oindex_1.sword - 1] == play_1.winner) {
      rspeak_(c__160);
   }
// 						!PULSE SWORD.
   goto L10;

L12100:
   if ((prsvec_1.prsa != vindex_1.attacw && prsvec_1.prsa != vindex_1.killw || prsvec_1.prsi != oindex_1.rknif) && (prsvec_1.prsa != vindex_1.swingw && prsvec_1.prsa != vindex_1.throww || prsvec_1.prso != oindex_1.rknif)) {
      goto L10;
   }
   newsta_(oindex_1.rknif, c__0, c__0, c__0, c__0);
// 						!KILL KNIFE.
   jigsup_(c__161);
// 						!KILL HIM.
   return ret_val;
// OAPPLI, PAGE 5

// O105--	GLACIER

L15000:
   if (prsvec_1.prsa != vindex_1.throww) {
      goto L15500;
   }
// 						!THROW?
   if (prsvec_1.prso != oindex_1.torch) {
      goto L15400;
   }
// 						!TORCH?
   newsta_(oindex_1.ice, c__169, c__0, c__0, c__0);
// 						!MELT ICE.
   objcts_1.odesc1[oindex_1.torch - 1] = 174;
// 						!MUNG TORCH.
   objcts_1.odesc2[oindex_1.torch - 1] = 173;
   objcts_1.oflag1[oindex_1.torch - 1] &= ~flobts;
   newsta_(oindex_1.torch, c__0, rindex_1.strea, c__0, c__0);
// 						!MOVE TORCH.
   findex_1.glacrf = true;
// 						!GLACIER GONE.
   if (!lit_(play_1.here)) {
      rspeak_(c__170);
   }
// 						!IN DARK?
   return ret_val;

L15400:
   rspeak_(c__171);
// 						!JOKE IF NOT TORCH.
   return ret_val;

L15500:
   if (prsvec_1.prsa != vindex_1.meltw || prsvec_1.prso != oindex_1.ice) {
      goto L10;
   }
   if ((objcts_1.oflag1[prsvec_1.prsi - 1] & flobts) == flobts) {
      goto L15600;
   }
   rspsub_(c__298, odi2);
// 						!CANT MELT WITH THAT.
   return ret_val;

L15600:
   findex_1.glacmf = true;
// 						!PARTIAL MELT.
   if (prsvec_1.prsi != oindex_1.torch) {
      goto L15700;
   }
// 						!MELT WITH TORCH?
   objcts_1.odesc1[oindex_1.torch - 1] = 174;
// 						!MUNG TORCH.
   objcts_1.odesc2[oindex_1.torch - 1] = 173;
   objcts_1.oflag1[oindex_1.torch - 1] &= ~flobts;
L15700:
   jigsup_(c__172);
// 						!DROWN.
   return ret_val;

// O106--	BLACK BOOK

L18000:
   if (prsvec_1.prsa != vindex_1.openw) {
      goto L18100;
   }
// 						!OPEN?
   rspeak_(c__180);
// 						!JOKE.
   return ret_val;

L18100:
   if (prsvec_1.prsa != vindex_1.closew) {
      goto L18200;
   }
// 						!CLOSE?
   rspeak_(c__181);
   return ret_val;

L18200:
   if (prsvec_1.prsa != vindex_1.burnw) {
      goto L10;
   }
// 						!BURN?
   newsta_(prsvec_1.prso, c__0, c__0, c__0, c__0);
// 						!FATAL JOKE.
   jigsup_(c__182);
   return ret_val;
// OAPPLI, PAGE 6

// O107--	CANDLES, PROCESSED EXTERNALLY

L19000:
   ret_val = lightp_(oindex_1.candl);
   return ret_val;

// O108--	MATCHES, PROCESSED EXTERNALLY

L20000:
   ret_val = lightp_(oindex_1.match);
   return ret_val;

// O109--	CYCLOPS, PROCESSED EXTERNALLY.

L22000:
   ret_val = cyclop_(/*arg*/);
// 						!CYCLOPS
   return ret_val;

// O110--	THIEF, PROCESSED EXTERNALLY

L25000:
   ret_val = thiefp_(/*arg*/);
   return ret_val;

// O111--	WINDOW

L26000:
   ret_val = opncls_(oindex_1.windo, c__208, c__209);
// 						!OPEN/CLS WINDOW.
   return ret_val;

// O112--	PILE OF BODIES

L32000:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L32500;
   }
// 						!TAKE?
   rspeak_(c__228);
// 						!CANT.
   return ret_val;

L32500:
   if (prsvec_1.prsa != vindex_1.burnw && prsvec_1.prsa != vindex_1.mungw) {
      goto L10;
   }
   if (findex_1.onpolf) {
      return ret_val;
   }
// 						!BURN OR MUNG?
   findex_1.onpolf = true;
// 						!SET HEAD ON POLE.
   newsta_(oindex_1.hpole, c__0, rindex_1.lld2, c__0, c__0);
   jigsup_(c__229);
// 						!BEHEADED.
   return ret_val;

// O113--	VAMPIRE BAT

L35000:
   rspeak_(c__50);
// 						!TIME TO FLY, JACK.
   f = moveto_(bats_1.batdrp[rnd_(c__9)], play_1.winner);
// 						!SELECT RANDOM DEST.
   f = rmdesc_(c__0);
   return ret_val;
// OAPPLI, PAGE 7

// O114--	STICK

L39000:
   if (prsvec_1.prsa != vindex_1.wavew) {
      goto L10;
   }
// 						!WAVE?
   if (play_1.here == rindex_1.mrain) {
      goto L39500;
   }
// 						!ON RAINBOW?
   if (play_1.here == rindex_1.pog || play_1.here == rindex_1.falls) {
      goto L39200;
   }
   rspeak_(c__244);
// 						!NOTHING HAPPENS.
   return ret_val;

L39200:
   objcts_1.oflag1[oindex_1.pot - 1] |= oflags_1.visibt;
   findex_1.rainbf = !findex_1.rainbf;
// 						!COMPLEMENT RAINBOW.
   i__ = 245;
// 						!ASSUME OFF.
   if (findex_1.rainbf) {
      i__ = 246;
   }
// 						!IF ON, SOLID.
   rspeak_(i__);
// 						!DESCRIBE.
   return ret_val;

L39500:
   findex_1.rainbf = false;
// 						!ON RAINBOW,
   jigsup_(c__247);
// 						!TAKE A FALL.
   return ret_val;

// O115--	BALLOON, HANDLED EXTERNALLY

L40000:
   ret_val = ballop_(arg);
   return ret_val;

// O116--	HEADS

L45000:
   if (prsvec_1.prsa != vindex_1.hellow) {
      goto L45100;
   }
// 						!HELLO HEADS?
   rspeak_(c__633);
// 						!TRULY BIZARRE.
   return ret_val;

L45100:
   if (prsvec_1.prsa == vindex_1.readw) {
      goto L10;
   }
// 						!READ IS OK.
   newsta_(oindex_1.lcase, c__260, rindex_1.lroom, c__0, c__0);
// 						!MAKE LARGE CASE.
   i__ = robadv_(play_1.winner, c__0, oindex_1.lcase, c__0) + robrm_(play_1.here, c__100, c__0, oindex_1.lcase, c__0);
   jigsup_(c__261);
// 						!KILL HIM.
   return ret_val;
// OAPPLI, PAGE 8

// O117--	SPHERE

L47000:
   if (findex_1.cagesf || prsvec_1.prsa != vindex_1.takew) {
      goto L10;
   }
// 						!TAKE?
   if (play_1.winner != aindex_1.player) {
      goto L47500;
   }
// 						!ROBOT TAKE?
   rspeak_(c__263);
// 						!NO, DROP CAGE.
   if (objcts_1.oroom[oindex_1.robot - 1] != play_1.here) {
      goto L47200;
   }
// 						!ROBOT HERE?
   f = moveto_(rindex_1.caged, play_1.winner);
// 						!YES, MOVE INTO CAGE.
   newsta_(oindex_1.robot, c__0, rindex_1.caged, c__0, c__0);
// 						!MOVE ROBOT.
   advs_1.aroom[aindex_1.arobot - 1] = rindex_1.caged;
   objcts_1.oflag1[oindex_1.robot - 1] |= oflags_1.ndscbt;
   cevent_1.ctick[cindex_1.cevsph - 1] = 10;
// 						!GET OUT IN 10 OR ELSE.
   return ret_val;

L47200:
   newsta_(oindex_1.spher, c__0, c__0, c__0, c__0);
// 						!YOURE DEAD.
   rooms_1.rflag[rindex_1.cager - 1] |= rflag_1.rmung;
   rrand[rindex_1.cager - 1] = 147;
   jigsup_(c__148);
// 						!MUNG PLAYER.
   return ret_val;

L47500:
   newsta_(oindex_1.spher, c__0, c__0, c__0, c__0);
// 						!ROBOT TRIED,
   newsta_(oindex_1.robot, c__264, c__0, c__0, c__0);
// 						!KILL HIM.
   newsta_(oindex_1.cage, c__0, play_1.here, c__0, c__0);
// 						!INSERT MANGLED CAGE.
   return ret_val;

// O118--	GEOMETRICAL BUTTONS

L48000:
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
// 						!PUSH?
   i__ = prsvec_1.prso - oindex_1.sqbut + 1;
// 						!GET BUTTON INDEX.
   if (i__ <= 0 || i__ >= 4) {
      goto L10;
   }
// 						!A BUTTON?
   if (play_1.winner != aindex_1.player) {
      switch (i__) {
         case 1:
            goto L48100;
         case 2:
            goto L48200;
         case 3:
            goto L48300;
      }
   }
   jigsup_(c__265);
// 						!YOU PUSHED, YOU DIE.
   return ret_val;

L48100:
   i__ = 267;
   if (findex_1.carozf) {
      i__ = 266;
   }
// 						!SPEED UP?
   findex_1.carozf = true;
   rspeak_(i__);
   return ret_val;

L48200:
   i__ = 266;
// 						!ASSUME NO CHANGE.
   if (findex_1.carozf) {
      i__ = 268;
   }
   findex_1.carozf = false;
   rspeak_(i__);
   return ret_val;

L48300:
   findex_1.caroff = !findex_1.caroff;
// 						!FLIP CAROUSEL.
   if (!qhere_(oindex_1.irbox, rindex_1.carou)) {
      return ret_val;
   }
// 						!IRON BOX IN CAROUSEL?
   rspeak_(c__269);
// 						!YES, THUMP.
   objcts_1.oflag1[oindex_1.irbox - 1] ^= oflags_1.visibt;
   if (findex_1.caroff) {
      rooms_1.rflag[rindex_1.carou - 1] &= ~rflag_1.rseen;
   }
   return ret_val;

// O119--	FLASK FUNCTION

L49000:
   if (prsvec_1.prsa == vindex_1.openw) {
      goto L49100;
   }
// 						!OPEN?
   if (prsvec_1.prsa != vindex_1.mungw && prsvec_1.prsa != vindex_1.throww) {
      goto L10;
   }
   newsta_(oindex_1.flask, c__270, c__0, c__0, c__0);
// 						!KILL FLASK.
L49100:
   rooms_1.rflag[play_1.here - 1] |= rflag_1.rmung;
   rrand[play_1.here - 1] = 271;
   jigsup_(c__272);
// 						!POISONED.
   return ret_val;

// O120--	BUCKET FUNCTION

L50000:
   if (arg != 2) {
      goto L10;
   }
// 						!READOUT?
   if (objcts_1.ocan[oindex_1.water - 1] != oindex_1.bucke || findex_1.bucktf) {
      goto L50500;
   }
   findex_1.bucktf = true;
// 						!BUCKET AT TOP.
   cevent_1.ctick[cindex_1.cevbuc - 1] = 100;
// 						!START COUNTDOWN.
   newsta_(oindex_1.bucke, c__290, rindex_1.twell, c__0, c__0);
// 						!REPOSITION BUCKET.
   goto L50900;
// 						!FINISH UP.

L50500:
   if (objcts_1.ocan[oindex_1.water - 1] == oindex_1.bucke || !findex_1.bucktf) {
      goto L10;
   }
   findex_1.bucktf = false;
   newsta_(oindex_1.bucke, c__291, rindex_1.bwell, c__0, c__0);
// 						!BUCKET AT BOTTOM.
L50900:
   if (av != oindex_1.bucke) {
      return ret_val;
   }
// 						!IN BUCKET?
   f = moveto_(objcts_1.oroom[oindex_1.bucke - 1], play_1.winner);
// 						!MOVE ADVENTURER.
   f = rmdesc_(c__0);
// 						!DESCRIBE ROOM.
   return ret_val;
// OAPPLI, PAGE 9

// O121--	EATME CAKE

L51000:
   if (prsvec_1.prsa != vindex_1.eatw || prsvec_1.prso != oindex_1.ecake || play_1.here != rindex_1.alice) {
      goto L10;
   }
   newsta_(oindex_1.ecake, c__273, c__0, c__0, c__0);
// 						!VANISH CAKE.
   objcts_1.oflag1[oindex_1.robot - 1] &= ~oflags_1.visibt;
   ret_val = moveto_(rindex_1.alism, play_1.winner);
// 						!MOVE TO ALICE SMALL.
   iz = 64;
   ir = rindex_1.alism;
   io = rindex_1.alice;
   goto L52405;

// O122--	ICINGS

L52000:
   if (prsvec_1.prsa != vindex_1.readw) {
      goto L52200;
   }
// 						!READ?
   i__ = 274;
// 						!CANT READ.
   if (prsvec_1.prsi != 0) {
      i__ = 275;
   }
// 						!THROUGH SOMETHING?
   if (prsvec_1.prsi == oindex_1.bottl) {
      i__ = 276;
   }
// 						!THROUGH BOTTLE?
   if (prsvec_1.prsi == oindex_1.flask) {
      i__ = prsvec_1.prso - oindex_1.orice + 277;
   }
// 						!THROUGH FLASK?
   rspeak_(i__);
// 						!READ FLASK.
   return ret_val;

L52200:
   if (prsvec_1.prsa != vindex_1.throww || prsvec_1.prso != oindex_1.rdice || prsvec_1.prsi != oindex_1.pool) {
      goto L52300;
   }
   newsta_(oindex_1.pool, c__280, c__0, c__0, c__0);
// 						!VANISH POOL.
   objcts_1.oflag1[oindex_1.saffr - 1] |= oflags_1.visibt;
   return ret_val;

L52300:
   if (play_1.here != rindex_1.alice && play_1.here != rindex_1.alism && play_1.here != rindex_1.alitr) {
      goto L10;
   }
   if (prsvec_1.prsa != vindex_1.eatw && prsvec_1.prsa != vindex_1.throww || prsvec_1.prso != oindex_1.orice) {
      goto L52400;
   }
   newsta_(oindex_1.orice, c__0, c__0, c__0, c__0);
// 						!VANISH ORANGE ICE.
   rooms_1.rflag[play_1.here - 1] |= rflag_1.rmung;
   rrand[play_1.here - 1] = 281;
   jigsup_(c__282);
// 						!VANISH ADVENTURER.
   return ret_val;

L52400:
   if (prsvec_1.prsa != vindex_1.eatw || prsvec_1.prso != oindex_1.blice) {
      goto L10;
   }
   newsta_(oindex_1.blice, c__283, c__0, c__0, c__0);
// 						!VANISH BLUE ICE.
   if (play_1.here != rindex_1.alism) {
      goto L52500;
   }
// 						!IN REDUCED ROOM?
   objcts_1.oflag1[oindex_1.robot - 1] |= oflags_1.visibt;
   io = play_1.here;
   ret_val = moveto_(rindex_1.alice, play_1.winner);
   iz = 0;
   ir = rindex_1.alice;

//  Do a size change, common loop used also by code at 51000

L52405:
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!ENLARGE WORLD.
      if (objcts_1.oroom[i__ - 1] != io || objcts_1.osize[i__ - 1] == 10000) {
         goto L52450;
      }
      objcts_1.oroom[i__ - 1] = ir;
      objcts_1.osize[i__ - 1] *= iz;
   L52450:
      ;
   }
   return ret_val;

L52500:
   jigsup_(c__284);
// 						!ENLARGED IN WRONG ROOM.
   return ret_val;

// O123--	BRICK

L54000:
   if (prsvec_1.prsa != vindex_1.burnw) {
      goto L10;
   }
// 						!BURN?
   jigsup_(c__150);
// 						!BOOM
// 						!
   return ret_val;

// O124--	MYSELF

L55000:
   if (prsvec_1.prsa != vindex_1.givew) {
      goto L55100;
   }
// 						!GIVE?
   newsta_(prsvec_1.prso, c__2, c__0, c__0, aindex_1.player);
// 						!DONE.
   return ret_val;

L55100:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L55200;
   }
// 						!TAKE?
   rspeak_(c__286);
// 						!JOKE.
   return ret_val;

L55200:
   if (prsvec_1.prsa != vindex_1.killw && prsvec_1.prsa != vindex_1.mungw) {
      goto L10;
   }
   jigsup_(c__287);
// 						!KILL, NO JOKE.
   return ret_val;
// OAPPLI, PAGE 10

// O125--	PANELS INSIDE MIRROR

L56000:
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
// 						!PUSH?
   if (findex_1.poleuf != 0) {
      goto L56100;
   }
// 						!SHORT POLE UP?
   i__ = 731;
// 						!NO, WONT BUDGE.
   if (findex_1.mdir % 180 == 0) {
      i__ = 732;
   }
// 						!DIFF MSG IF N-S.
   rspeak_(i__);
// 						!TELL WONT MOVE.
   return ret_val;

L56100:
   if (findex_1.mloc != rindex_1.mrg) {
      goto L56200;
   }
// 						!IN GDN ROOM?
   rspeak_(c__733);
// 						!YOU LOSE.
   jigsup_(c__685);
   return ret_val;

L56200:
   i__ = 831;
// 						!ROTATE L OR R.
   if (prsvec_1.prso == oindex_1.rdwal || prsvec_1.prso == oindex_1.ylwal) {
      i__ = 830;
   }
   rspeak_(i__);
// 						!TELL DIRECTION.
   findex_1.mdir = (findex_1.mdir + 45 + (i__ - 830) * 270) % 360;
// 						!CALCULATE NEW DIR.
   i__1 = findex_1.mdir / 45 + 695;
   rspsub_(c__734, i__1);
// 						!TELL NEW DIR.
   if (findex_1.wdopnf) {
      rspeak_(c__730);
   }
// 						!IF PANEL OPEN, CLOSE.
   findex_1.wdopnf = false;
   return ret_val;
// 						!DONE.

// O126--	ENDS INSIDE MIRROR

L57000:
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
// 						!PUSH?
   if (findex_1.mdir % 180 == 0) {
      goto L57100;
   }
// 						!MIRROR N-S?
   rspeak_(c__735);
// 						!NO, WONT BUDGE.
   return ret_val;

L57100:
   if (prsvec_1.prso != oindex_1.pindr) {
      goto L57300;
   }
// 						!PUSH PINE WALL?
   if (findex_1.mloc == rindex_1.mrc && findex_1.mdir == 180 || findex_1.mloc == rindex_1.mrd && findex_1.mdir == 0 || findex_1.mloc == rindex_1.mrg) {
      goto L57200;
   }
   rspeak_(c__736);
// 						!NO, OPENS.
   findex_1.wdopnf = true;
// 						!INDICATE OPEN.
   cevent_1.cflag[cindex_1.cevpin - 1] = true;
// 						!TIME OPENING.
   cevent_1.ctick[cindex_1.cevpin - 1] = 5;
   return ret_val;

L57200:
   rspeak_(c__737);
// 						!GDN SEES YOU, DIE.
   jigsup_(c__685);
   return ret_val;

L57300:
   nloc = findex_1.mloc - 1;
// 						!NEW LOC IF SOUTH.
   if (findex_1.mdir == 0) {
      nloc = findex_1.mloc + 1;
   }
// 						!NEW LOC IF NORTH.
   if (nloc >= rindex_1.mra && nloc <= rindex_1.mrd) {
      goto L57400;
   }
   rspeak_(c__738);
// 						!HAVE REACHED END.
   return ret_val;

L57400:
   i__ = 699;
// 						!ASSUME SOUTH.
   if (findex_1.mdir == 0) {
      i__ = 695;
   }
// 						!NORTH.
   j = 739;
// 						!ASSUME SMOOTH.
   if (findex_1.poleuf != 0) {
      j = 740;
   }
// 						!POLE UP, WOBBLES.
   rspsub_(j, i__);
// 						!DESCRIBE.
   findex_1.mloc = nloc;
   if (findex_1.mloc != rindex_1.mrg) {
      return ret_val;
   }
// 						!NOW IN GDN ROOM?

   if (findex_1.poleuf != 0) {
      goto L57500;
   }
// 						!POLE UP, GDN SEES.
   if (findex_1.mropnf || findex_1.wdopnf) {
      goto L57600;
   }
// 						!DOOR OPEN, GDN SEES.
   if (findex_1.mr1f && findex_1.mr2f) {
      return ret_val;
   }
// 						!MIRRORS INTACT, OK.
   rspeak_(c__742);
// 						!MIRRORS BROKEN, DIE.
   jigsup_(c__743);
   return ret_val;

L57500:
   rspeak_(c__741);
// 						!POLE UP, DIE.
   jigsup_(c__743);
   return ret_val;

L57600:
   rspeak_(c__744);
// 						!DOOR OPEN, DIE.
   jigsup_(c__743);
   return ret_val;
// OAPPLI, PAGE 11

// O127--	GLOBAL GUARDIANS

L58000:
   if (prsvec_1.prsa != vindex_1.attacw && prsvec_1.prsa != vindex_1.killw && prsvec_1.prsa != vindex_1.mungw) {
      goto L58100;
   }
   jigsup_(c__745);
// 						!LOSE.
   return ret_val;

L58100:
   if (prsvec_1.prsa != vindex_1.hellow) {
      goto L10;
   }
// 						!HELLO?
   rspeak_(c__746);
// 						!NO REPLY.
   return ret_val;

// O128--	GLOBAL MASTER

L59000:
   if (prsvec_1.prsa != vindex_1.attacw && prsvec_1.prsa != vindex_1.killw && prsvec_1.prsa != vindex_1.mungw) {
      goto L59100;
   }
   jigsup_(c__747);
// 						!BAD IDEA.
   return ret_val;

L59100:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L10;
   }
// 						!TAKE?
   rspeak_(c__748);
// 						!JOKE.
   return ret_val;

// O129--	NUMERAL FIVE (FOR JOKE)

L60000:
   if (prsvec_1.prsa != vindex_1.takew) {
      goto L10;
   }
// 						!TAKE FIVE?
   rspeak_(c__419);
// 						!TIME PASSES.
   for (i__ = 1; i__ <= 3; ++i__) {
// 						!WAIT A WHILE.
      if (clockd_(/*x*/)) {
         return ret_val;
      }
// L60100:
   }
   return ret_val;

// O130--	CRYPT FUNCTION

L61000:
   if (!findex_1.endgmf) {
      goto L45000;
   }
// 						!IF NOT EG, DIE.
   if (prsvec_1.prsa != vindex_1.openw) {
      goto L61100;
   }
// 						!OPEN?
   i__ = 793;
   if ((objcts_1.oflag2[oindex_1.tomb - 1] & oflags_1.openbt) != 0) {
      i__ = 794;
   }
   rspeak_(i__);
   objcts_1.oflag2[oindex_1.tomb - 1] |= oflags_1.openbt;
   return ret_val;

L61100:
   if (prsvec_1.prsa != vindex_1.closew) {
      goto L45000;
   }
// 						!CLOSE?
   i__ = 795;
   if ((objcts_1.oflag2[oindex_1.tomb - 1] & oflags_1.openbt) != 0) {
      i__ = 796;
   }
   rspeak_(i__);
   objcts_1.oflag2[oindex_1.tomb - 1] &= ~oflags_1.openbt;
   if (play_1.here == rindex_1.crypt) {
      cevent_1.ctick[cindex_1.cevste - 1] = 3;
   }
// 						!IF IN CRYPT, START EG.
   return ret_val;
// OAPPLI, PAGE 12

// O131--	GLOBAL LADDER

L62000:
   if (puzzle_1.cpvec[findex_1.cphere] == -2 || puzzle_1.cpvec[findex_1.cphere - 2] == -3) {
      goto L62100;
   }
   rspeak_(c__865);
// 						!NO, LOSE.
   return ret_val;

L62100:
   if (prsvec_1.prsa == vindex_1.clmbw || prsvec_1.prsa == vindex_1.clmbuw) {
      goto L62200;
   }
   rspeak_(c__866);
// 						!CLIMB IT?
   return ret_val;

L62200:
   if (findex_1.cphere == 10 && puzzle_1.cpvec[findex_1.cphere] == -2) {
      goto L62300;
   }
   rspeak_(c__867);
// 						!NO, HIT YOUR HEAD.
   return ret_val;

L62300:
   f = moveto_(rindex_1.cpant, play_1.winner);
// 						!TO ANTEROOM.
   f = rmdesc_(c__3);
// 						!DESCRIBE.
   return ret_val;

}

#undef prpvec
#undef objvec
#undef rrand
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqc
#undef eqa
#undef switch__
#undef flags
