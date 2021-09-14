#include "F2C.h"

// Common Block Declarations

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
   int winner, here;
   Bool telflg;
} play_;

#define play_1 play_

struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

struct {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;

#define screen_1 screen_

struct {
   int batdrp[9];
} bats_;

#define bats_1 bats_

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
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;

#define cevent_1 cevent_

struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

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
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// Table of constant values

static int c__1 = 1;
static int c__11 = 11;
static int c__14 = 14;
static int c__0 = 0;
static int c__21 = 21;
static int c__22 = 22;
static int c__23 = 23;
static int c__27 = 27;
static int c__30 = 30;
static int c__33 = 33;
static int c__38 = 38;
static int c__39 = 39;
static int c__42 = 42;
static int c__43 = 43;
static int c__50 = 50;
static int c__47 = 47;
static int c__294 = 294;
static int c__44 = 44;
static int c__295 = 295;
static int c__45 = 45;
static int c__48 = 48;
static int c__49 = 49;
static int c__9 = 9;
static int c__51 = 51;
static int c__52 = 52;
static int c__53 = 53;
static int c__54 = 54;
static int c__55 = 55;
static int c__56 = 56;
static int c__57 = 57;
static int c__58 = 58;
static int c__59 = 59;
static int c__60 = 60;
static int c__62 = 62;
static int c__61 = 61;
static int c__63 = 63;
static int c__64 = 64;
static int c__65 = 65;
static int c__66 = 66;
static int c__69 = 69;
static int c__70 = 70;
static int c__660 = 660;
static int c__502 = 502;
static int c__606 = 606;
static int c__82 = 82;
static int c__84 = 84;
static int c__85 = 85;
static int c__2 = 2;
static int c__90 = 90;
static int c__96 = 96;
static int c__100 = 100;
static int c__104 = 104;
static int c__107 = 107;
static int c__108 = 108;

// RAPPL1- SPECIAL PURPOSE ROOM ROUTINES, PART 1

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool rappl1_(int * ri) {
// System generated locals
   int i__1, i__2;
   Bool ret_val;

// Local variables
   static Bool f;
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   static int i__;
   extern Void rspsub_(int *, int *), rspeak_(int *);
   static int j;
   extern Void scrupd_(int *), jigsup_(int *), newsta_(int *, int *, int *, int *, int *);
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
   extern Void bug_(int *, int *);
   extern int rnd_(int *);
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
   extern Bool lit_(int *);
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool prob_(int *, int *);
   static int chbt;
   extern Bool qhere_(int *, int *);
#define rrand ((int *)&rooms_1 + 602)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
   extern Bool moveto_(int *, int *);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// SCREEN OF LIGHT

// MISCELLANEOUS VARIABLES

// ROOMS

// OBJECTS

// CLOCK INTERRUPTS

// VILLAINS AND DEMONS

// ADVENTURERS

// VERBS

// FUNCTIONS AND DATA

// FLAGS

// RAPPL1, PAGE 2

   ret_val = true;
// 						!USUALLY IGNORED.
   if (*ri == 0) {
      return ret_val;
   }
// 						!RETURN IF NAUGHT.

// 						!SET TO FALSE FOR

// 						!NEW DESC NEEDED.
   switch (*ri) {
      case 1:
         goto L1000;
      case 2:
         goto L2000;
      case 3:
         goto L3000;
      case 4:
         goto L4000;
      case 5:
         goto L5000;
      case 6:
         goto L6000;
      case 7:
         goto L7000;
      case 8:
         goto L8000;
      case 9:
         goto L9000;
      case 10:
         goto L10000;
      case 11:
         goto L11000;
      case 12:
         goto L12000;
      case 13:
         goto L13000;
      case 14:
         goto L14000;
      case 15:
         goto L15000;
      case 16:
         goto L16000;
      case 17:
         goto L17000;
      case 18:
         goto L18000;
      case 19:
         goto L19000;
      case 20:
         goto L20000;
      case 21:
         goto L21000;
      case 22:
         goto L22000;
      case 23:
         goto L23000;
      case 24:
         goto L24000;
      case 25:
         goto L25000;
      case 26:
         goto L26000;
      case 27:
         goto L27000;
      case 28:
         goto L28000;
      case 29:
         goto L29000;
      case 30:
         goto L30000;
      case 31:
         goto L31000;
      case 32:
         goto L32000;
      case 33:
         goto L33000;
      case 34:
         goto L34000;
      case 35:
         goto L35000;
      case 36:
         goto L36000;
      case 37:
         goto L37000;
   }
   bug_(&c__1, ri);

// R1--	EAST OF HOUSE.  DESCRIPTION DEPENDS ON STATE OF WINDOW

L1000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 13;
// 						!ASSUME CLOSED.
   if ((objcts_1.oflag2[oindex_1.windo - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
// 						!IF OPEN, AJAR.
   rspsub_(&c__11, &i__);
// 						!DESCRIBE.
   return ret_val;

// R2--	KITCHEN.  SAME VIEW FROM INSIDE.

L2000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 13;
// 						!ASSUME CLOSED.
   if ((objcts_1.oflag2[oindex_1.windo - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
// 						!IF OPEN, AJAR.
   rspsub_(&c__14, &i__);
// 						!DESCRIBE.
   return ret_val;

// R3--	LIVING ROOM.  DESCRIPTION DEPENDS ON MAGICF (STATE OF
// 	DOOR TO CYCLOPS ROOM), RUG (MOVED OR NOT), DOOR (OPEN OR CLOSED)

L3000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L3500;
   }
// 						!LOOK?
   i__ = 15;
// 						!ASSUME NO HOLE.
   if (findex_1.magicf) {
      i__ = 16;
   }
// 						!IF MAGICF, CYCLOPS HOLE.
   rspeak_(&i__);
// 						!DESCRIBE.
   i__ = findex_1.orrug + 17;
// 						!ASSUME INITIAL STATE.
   if ((objcts_1.oflag2[oindex_1.door - 1] & oflags_1.openbt) != 0) {
      i__ += 2;
   }
// 						!DOOR OPEN?
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// 	NOT A LOOK WORD.  REEVALUATE TROPHY CASE.

L3500:
   if (prsvec_1.prsa != vindex_1.takew && (prsvec_1.prsa != vindex_1.putw || prsvec_1.prsi != oindex_1.tcase)) {
      return ret_val;
   }
   advs_1.ascore[play_1.winner - 1] = state_1.rwscor;
// 						!SCORE TROPHY CASE.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!RETAIN RAW SCORE AS WELL.
      j = i__;
// 						!FIND OUT IF IN CASE.
   L3550:
      j = objcts_1.ocan[j - 1];
// 						!TRACE OWNERSHIP.
      if (j == 0) {
         goto L3600;
      }
      if (j != oindex_1.tcase) {
         goto L3550;
      }
// 						!DO ALL LEVELS.
      advs_1.ascore[play_1.winner - 1] += objcts_1.otval[i__ - 1];
   L3600:
      ;
   }
   scrupd_(&c__0);
// 						!SEE IF ENDGAME TRIG.
   return ret_val;
// RAPPL1, PAGE 3

// R4--	CELLAR.  SHUT DOOR AND BAR IT IF HE JUST WALKED IN.

L4000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L4500;
   }
// 						!LOOK?
   rspeak_(&c__21);
// 						!DESCRIBE CELLAR.
   return ret_val;

L4500:
   if (prsvec_1.prsa != vindex_1.walkiw) {
      return ret_val;
   }
// 						!WALKIN?
   if ((objcts_1.oflag2[oindex_1.door - 1] & oflags_1.openbt + oflags_1.tchbt) != oflags_1.openbt) {
      return ret_val;
   }
   objcts_1.oflag2[oindex_1.door - 1] = objcts_1.oflag2[oindex_1.door - 1] & chbt & ~oflags_1.openbt;
   rspeak_(&c__22);
// 						!SLAM AND BOLT DOOR.
   return ret_val;

// R5--	MAZE11.  DESCRIBE STATE OF GRATING.

L5000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__23);
// 						!DESCRIBE.
   i__ = 24;
// 						!ASSUME LOCKED.
   if (findex_1.grunlf) {
      i__ = 26;
   }
// 						!UNLOCKED?
   if ((objcts_1.oflag2[oindex_1.grate - 1] & oflags_1.openbt) != 0) {
      i__ = 25;
   }
// 						!OPEN?
   rspeak_(&i__);
// 						!DESCRIBE GRATE.
   return ret_val;

// R6--	CLEARING.  DESCRIBE CLEARING, MOVE LEAVES.

L6000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L6500;
   }
// 						!LOOK?
   rspeak_(&c__27);
// 						!DESCRIBE.
   if (findex_1.rvclr == 0) {
      return ret_val;
   }
// 						!LEAVES MOVED?
   i__ = 28;
// 						!YES, ASSUME GRATE CLOSED.
   if ((objcts_1.oflag2[oindex_1.grate - 1] & oflags_1.openbt) != 0) {
      i__ = 29;
   }
// 						!OPEN?
   rspeak_(&i__);
// 						!DESCRIBE GRATE.
   return ret_val;

L6500:
   if (findex_1.rvclr != 0 || qhere_(&oindex_1.leave, &rindex_1.clear) && (prsvec_1.prsa != vindex_1.movew || prsvec_1.prso != oindex_1.leave)) {
      return ret_val;
   }
   rspeak_(&c__30);
// 						!MOVE LEAVES, REVEAL GRATE.
   findex_1.rvclr = 1;
// 						!INDICATE LEAVES MOVED.
   return ret_val;
// RAPPL1, PAGE 4

// R7--	RESERVOIR SOUTH.  DESCRIPTION DEPENDS ON LOW TIDE FLAG.

L7000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 31;
// 						!ASSUME FULL.
   if (findex_1.lwtidf) {
      i__ = 32;
   }
// 						!IF LOW TIDE, EMPTY.
   rspeak_(&i__);
// 						!DESCRIBE.
   rspeak_(&c__33);
// 						!DESCRIBE EXITS.
   return ret_val;

// R8--	RESERVOIR.  STATE DEPENDS ON LOW TIDE FLAG.

L8000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 34;
// 						!ASSUME FULL.
   if (findex_1.lwtidf) {
      i__ = 35;
   }
// 						!IF LOW TIDE, EMTPY.
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// R9--	RESERVOIR NORTH.  ALSO DEPENDS ON LOW TIDE FLAG.

L9000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 36;
// 						!YOU GET THE IDEA.
   if (findex_1.lwtidf) {
      i__ = 37;
   }
   rspeak_(&i__);
   rspeak_(&c__38);
   return ret_val;

// R10--	GLACIER ROOM.  STATE DEPENDS ON MELTED, VANISHED FLAGS.

L10000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__39);
// 						!BASIC DESCRIPTION.
   i__ = 0;
// 						!ASSUME NO CHANGES.
   if (findex_1.glacmf) {
      i__ = 40;
   }
// 						!PARTIAL MELT?
   if (findex_1.glacrf) {
      i__ = 41;
   }
// 						!COMPLETE MELT?
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// R11--	FOREST ROOM

L11000:
   if (prsvec_1.prsa == vindex_1.walkiw) {
      cevent_1.cflag[cindex_1.cevfor - 1] = true;
   }
// 						!IF WALK IN, BIRDIE.
   return ret_val;

// R12--	MIRROR ROOM.  STATE DEPENDS ON MIRROR INTACT.

L12000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__42);
// 						!DESCRIBE.
   if (findex_1.mirrmf) {
      rspeak_(&c__43);
   }
// 						!IF BROKEN, NASTY REMARK.
   return ret_val;
// RAPPL1, PAGE 5

// R13--	CAVE2 ROOM.  BLOW OUT CANDLES WITH 50% PROBABILITY.

L13000:
   if (prsvec_1.prsa != vindex_1.walkiw) {
      return ret_val;
   }
// 						!WALKIN?
   if (prob_(&c__50, &c__50) || objcts_1.oadv[oindex_1.candl - 1] != play_1.winner || !((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0)) {
      return ret_val;
   }
   objcts_1.oflag1[oindex_1.candl - 1] &= ~oflags_1.onbt;
   rspeak_(&c__47);
// 						!TELL OF WINDS.
   cevent_1.cflag[cindex_1.cevcnd - 1] = false;
// 						!HALT CANDLE COUNTDOWN.
   return ret_val;

// R14--	BOOM ROOM.  BLOW HIM UP IF CARRYING FLAMING OBJECT.

L14000:
   j = objcts_1.odesc2[oindex_1.candl - 1];
// 						!ASSUME CANDLE.
   if (objcts_1.oadv[oindex_1.candl - 1] == play_1.winner && (objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      goto L14100;
   }
   j = objcts_1.odesc2[oindex_1.torch - 1];
// 						!ASSUME TORCH.
   if (objcts_1.oadv[oindex_1.torch - 1] == play_1.winner && (objcts_1.oflag1[oindex_1.torch - 1] & oflags_1.onbt) != 0) {
      goto L14100;
   }
   j = objcts_1.odesc2[oindex_1.match - 1];
   if (objcts_1.oadv[oindex_1.match - 1] == play_1.winner && (objcts_1.oflag1[oindex_1.match - 1] & oflags_1.onbt) != 0) {
      goto L14100;
   }
   return ret_val;
// 						!SAFE

L14100:
   if (prsvec_1.prsa != vindex_1.trnonw) {
      goto L14200;
   }
// 						!TURN ON?
   rspsub_(&c__294, &j);
// 						!BOOM
// 						!
   jigsup_(&c__44);
   return ret_val;

L14200:
   if (prsvec_1.prsa != vindex_1.walkiw) {
      return ret_val;
   }
// 						!WALKIN?
   rspsub_(&c__295, &j);
// 						!BOOM
// 						!
   jigsup_(&c__44);
   return ret_val;

// R15--	NO-OBJS.  SEE IF EMPTY HANDED, SCORE LIGHT SHAFT.

L15000:
   findex_1.empthf = true;
// 						!ASSUME TRUE.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!SEE IF CARRYING.
      if (objcts_1.oadv[i__ - 1] == play_1.winner) {
         findex_1.empthf = false;
      }
// L15100:
   }

   if (play_1.here != rindex_1.bshaf || !lit_(&play_1.here)) {
      return ret_val;
   }
   scrupd_(&state_1.ltshft);
// 						!SCORE LIGHT SHAFT.
   state_1.ltshft = 0;
// 						!NEVER AGAIN.
   return ret_val;
// RAPPL1, PAGE 6

// R16--	MACHINE ROOM.  DESCRIBE MACHINE.

L16000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 46;
// 						!ASSUME LID CLOSED.
   if ((objcts_1.oflag2[oindex_1.machi - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
// 						!IF OPEN, OPEN.
   rspsub_(&c__45, &i__);
// 						!DESCRIBE.
   return ret_val;

// R17--	BAT ROOM.  UNLESS CARRYING GARLIC, FLY AWAY WITH ME...

L17000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L17500;
   }
// 						!LOOK?
   rspeak_(&c__48);
// 						!DESCRIBE ROOM.
   if (objcts_1.oadv[oindex_1.garli - 1] == play_1.winner) {
      rspeak_(&c__49);
   }
// 						!BAT HOLDS NOSE.
   return ret_val;

L17500:
   if (prsvec_1.prsa != vindex_1.walkiw || objcts_1.oadv[oindex_1.garli - 1] == play_1.winner) {
      return ret_val;
   }
   rspeak_(&c__50);
// 						!TIME TO FLY, JACK.
   f = moveto_(&bats_1.batdrp[rnd_(&c__9)], &play_1.winner);
// 						!SELECT RANDOM DEST.
   ret_val = false;
// 						!INDICATE NEW DESC NEEDED.
   return ret_val;

// R18--	DOME ROOM.  STATE DEPENDS ON WHETHER ROPE TIED TO RAILING.

L18000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L18500;
   }
// 						!LOOK?
   rspeak_(&c__51);
// 						!DESCRIBE.
   if (findex_1.domef) {
      rspeak_(&c__52);
   }
// 						!IF ROPE, DESCRIBE.
   return ret_val;

L18500:
   if (prsvec_1.prsa == vindex_1.leapw) {
      jigsup_(&c__53);
   }
// 						!DID HE JUMP???
   return ret_val;

// R19--	TORCH ROOM.  ALSO DEPENDS ON WHETHER ROPE TIED TO RAILING.

L19000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__54);
// 						!DESCRIBE.
   if (findex_1.domef) {
      rspeak_(&c__55);
   }
// 						!IF ROPE, DESCRIBE.
   return ret_val;

// R20--	CAROUSEL ROOM.  SPIN HIM OR KILL HIM.

L20000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L20500;
   }
// 						!LOOK?
   rspeak_(&c__56);
// 						!DESCRIBE.
   if (!findex_1.caroff) {
      rspeak_(&c__57);
   }
// 						!IF NOT FLIPPED, SPIN.
   return ret_val;

L20500:
   if (prsvec_1.prsa == vindex_1.walkiw && findex_1.carozf) {
      jigsup_(&c__58);
   }
// 						!WALKED IN.
   return ret_val;
// RAPPL1, PAGE 7

// R21--	LLD ROOM.  HANDLE EXORCISE, DESCRIPTIONS.

L21000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L21500;
   }
// 						!LOOK?
   rspeak_(&c__59);
// 						!DESCRIBE.
   if (!findex_1.lldf) {
      rspeak_(&c__60);
   }
// 						!IF NOT VANISHED, GHOSTS.
   return ret_val;

L21500:
   if (prsvec_1.prsa != vindex_1.exorcw) {
      return ret_val;
   }
// 						!EXORCISE?
   if (objcts_1.oadv[oindex_1.bell - 1] == play_1.winner && objcts_1.oadv[oindex_1.book - 1] == play_1.winner && objcts_1.oadv[oindex_1.candl - 1] == play_1.winner && (objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      goto L21600;
   }
   rspeak_(&c__62);
// 						!NOT EQUIPPED.
   return ret_val;

L21600:
   if (qhere_(&oindex_1.ghost, &play_1.here)) {
      goto L21700;
   }
// 						!GHOST HERE?
   jigsup_(&c__61);
// 						!NOPE, EXORCISE YOU.
   return ret_val;

L21700:
   newsta_(&oindex_1.ghost, &c__63, &c__0, &c__0, &c__0);
// 						!VANISH GHOST.
   findex_1.lldf = true;
// 						!OPEN GATE.
   return ret_val;

// R22--	LLD2-ROOM.  IS HIS HEAD ON A POLE?

L22000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__64);
// 						!DESCRIBE.
   if (findex_1.onpolf) {
      rspeak_(&c__65);
   }
// 						!ON POLE?
   return ret_val;

// R23--	DAM ROOM.  DESCRIBE RESERVOIR, PANEL.

L23000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__66);
// 						!DESCRIBE.
   i__ = 67;
   if (findex_1.lwtidf) {
      i__ = 68;
   }
   rspeak_(&i__);
// 						!DESCRIBE RESERVOIR.
   rspeak_(&c__69);
// 						!DESCRIBE PANEL.
   if (findex_1.gatef) {
      rspeak_(&c__70);
   }
// 						!BUBBLE IS GLOWING.
   return ret_val;

// R24--	TREE ROOM

L24000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__660);
// 						!DESCRIBE.
   i__ = 661;
// 						!SET FLAG FOR BELOW.
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!DESCRIBE OBJ IN FORE3.
      if (!qhere_(&j, &rindex_1.fore3) || j == oindex_1.ftree) {
         goto L24200;
      }
      rspeak_(&i__);
// 						!SET STAGE,
      i__ = 0;
      rspsub_(&c__502, &objcts_1.odesc2[j - 1]);
// 						!DESCRIBE.
   L24200:
      ;
   }
   return ret_val;
// RAPPL1, PAGE 8

// R25--	CYCLOPS-ROOM.  DEPENDS ON CYCLOPS STATE, ASLEEP FLAG, MAGIC FLAG.

L25000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__606);
// 						!DESCRIBE.
   i__ = 607;
// 						!ASSUME BASIC STATE.
   if (findex_1.rvcyc > 0) {
      i__ = 608;
   }
// 						!>0?  HUNGRY.
   if (findex_1.rvcyc < 0) {
      i__ = 609;
   }
// 						!<0?  THIRSTY.
   if (findex_1.cyclof) {
      i__ = 610;
   }
// 						!ASLEEP?
   if (findex_1.magicf) {
      i__ = 611;
   }
// 						!GONE?
   rspeak_(&i__);
// 						!DESCRIBE.
   if (!findex_1.cyclof && findex_1.rvcyc != 0) {
      i__1 = abs(findex_1.rvcyc) + 193;
      rspeak_(&i__1);
   }
   return ret_val;

// R26--	BANK BOX ROOM.

L26000:
   if (prsvec_1.prsa != vindex_1.walkiw) {
      return ret_val;
   }
// 						!SURPRISE HIM.
   for (i__ = 1; i__ <= 8; i__ += 2) {
// 						!SCOLRM DEPENDS ON
      if (screen_1.fromdr == screen_1.scoldr[i__ - 1]) {
         screen_1.scolrm = screen_1.scoldr[i__];
      }
// L26100:
   }
// 						!ENTRY DIRECTION.
   return ret_val;

// R27--	TREASURE ROOM.

L27000:
   if (prsvec_1.prsa != vindex_1.walkiw || !hack_1.thfact) {
      return ret_val;
   }
   if (objcts_1.oroom[oindex_1.thief - 1] != play_1.here) {
      newsta_(&oindex_1.thief, &c__82, &play_1.here, &c__0, &c__0);
   }
   hack_1.thfpos = play_1.here;
// 						!RESET SEARCH PATTERN.
   objcts_1.oflag2[oindex_1.thief - 1] |= oflags_1.fitebt;
   if (objcts_1.oroom[oindex_1.chali - 1] == play_1.here) {
      objcts_1.oflag1[oindex_1.chali - 1] &= ~oflags_1.takebt;
   }

//     VANISH EVERYTHING IN ROOM

   j = 0;
// 						!ASSUME NOTHING TO VANISH.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (i__ == oindex_1.chali || i__ == oindex_1.thief || !qhere_(&i__, &play_1.here)) {
         goto L27200;
      }
      j = 83;
// 						!FLAG BYEBYE.
      objcts_1.oflag1[i__ - 1] &= ~oflags_1.visibt;
   L27200:
      ;
   }
   rspeak_(&j);
// 						!DESCRIBE.
   return ret_val;

// R28--	CLIFF FUNCTION.  SEE IF CARRYING INFLATED BOAT.

L28000:
   findex_1.deflaf = objcts_1.oadv[oindex_1.rboat - 1] != play_1.winner;
// 						!TRUE IF NOT CARRYING.
   return ret_val;
// RAPPL1, PAGE 9

// R29--	RIVR4 ROOM.  PLAY WITH BUOY.

L29000:
   if (!findex_1.buoyf || objcts_1.oadv[oindex_1.buoy - 1] != play_1.winner) {
      return ret_val;
   }
   rspeak_(&c__84);
// 						!GIVE HINT,
   findex_1.buoyf = false;
// 						!THEN DISABLE.
   return ret_val;

// R30--	OVERFALLS.  DOOM.

L30000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      jigsup_(&c__85);
   }
// 						!OVER YOU GO.
   return ret_val;

// R31--	BEACH ROOM.  DIG A HOLE.

L31000:
   if (prsvec_1.prsa != vindex_1.digw || prsvec_1.prso != oindex_1.shove) {
      return ret_val;
   }
   ++findex_1.rvsnd;
// 						!INCREMENT DIG STATE.
   switch (findex_1.rvsnd) {
      case 1:
         goto L31100;
      case 2:
         goto L31100;
      case 3:
         goto L31100;
      case 4:
         goto L31400;
      case 5:
         goto L31500;
   }
// 						!PROCESS STATE.
   bug_(&c__2, &findex_1.rvsnd);

L31100:
   i__1 = findex_1.rvsnd + 85;
   rspeak_(&i__1);
// 						!1-3... DISCOURAGE HIM.
   return ret_val;

L31400:
   i__ = 89;
// 						!ASSUME DISCOVERY.
   if ((objcts_1.oflag1[oindex_1.statu - 1] & oflags_1.visibt) != 0) {
      i__ = 88;
   }
   rspeak_(&i__);
   objcts_1.oflag1[oindex_1.statu - 1] |= oflags_1.visibt;
   return ret_val;

L31500:
   findex_1.rvsnd = 0;
// 						!5... SAND COLLAPSES
   jigsup_(&c__90);
// 						!AND SO DOES HE.
   return ret_val;

// R32--	TCAVE ROOM.  DIG A HOLE IN GUANO.

L32000:
   if (prsvec_1.prsa != vindex_1.digw || prsvec_1.prso != oindex_1.shove) {
      return ret_val;
   }
   i__ = 91;
// 						!ASSUME NO GUANO.
   if (!qhere_(&oindex_1.guano, &play_1.here)) {
      goto L32100;
   }
// 						!IS IT HERE?
// Computing MIN
   i__1 = 4, i__2 = findex_1.rvgua + 1;
   findex_1.rvgua = min(i__1, i__2);
// 						!YES, SET NEW STATE.
   i__ = findex_1.rvgua + 91;
// 						!GET NASTY REMARK.
L32100:
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// R33--	FALLS ROOM

L33000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__96);
// 						!DESCRIBE.
   i__ = 97;
// 						!ASSUME NO RAINBOW.
   if (findex_1.rainbf) {
      i__ = 98;
   }
// 						!GOT ONE?
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;
// RAPPL1, PAGE 10

// R34--	LEDGE FUNCTION.  LEDGE CAN COLLAPSE.

L34000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__100);
// 						!DESCRIBE.
   i__ = 102;
// 						!ASSUME SAFE ROOM OK.
   if ((rooms_1.rflag[rindex_1.msafe - 1] & rflag_1.rmung) != 0) {
      i__ = 101;
   }
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// R35--	SAFE ROOM.  STATE DEPENDS ON WHETHER SAFE BLOWN.

L35000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__104);
// 						!DESCRIBE.
   i__ = 105;
// 						!ASSUME OK.
   if (findex_1.safef) {
      i__ = 106;
   }
// 						!BLOWN?
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// R36--	MAGNET ROOM.  DESCRIBE, CHECK FOR SPINDIZZY DOOM.

L36000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      goto L36500;
   }
// 						!LOOK?
   rspeak_(&c__107);
// 						!DESCRIBE.
   return ret_val;

L36500:
   if (prsvec_1.prsa != vindex_1.walkiw || !findex_1.caroff) {
      return ret_val;
   }
// 						!WALKIN ON FLIPPED?
   if (findex_1.carozf) {
      goto L36600;
   }
// 						!ZOOM?
   rspeak_(&c__108);
// 						!NO, SPIN HIS COMPASS.
   return ret_val;

L36600:
   i__ = 58;
// 						!SPIN HIS INSIDES.
   if (play_1.winner != aindex_1.player) {
      i__ = 99;
   }
// 						!SPIN ROBOT.
   jigsup_(&i__);
// 						!DEAD.
   return ret_val;

// R37--	CAGE ROOM.  IF SOLVED CAGE, MOVE TO OTHER CAGE ROOM.

L37000:
   if (findex_1.cagesf) {
      f = moveto_(&rindex_1.cager, &play_1.winner);
   }
// 						!IF SOLVED, MOVE.
   return ret_val;

}

#undef prpvec
#undef objvec
#undef rrand
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqr
#undef eqo
#undef eqc
#undef eqa
#undef switch__
#undef flags
