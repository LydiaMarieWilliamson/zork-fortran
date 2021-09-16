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
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;

#define screen_1 screen_

extern struct {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;

#define puzzle_1 puzzle_

extern struct {
   int hfactr;
} hyper_;

#define hyper_1 hyper_

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
   int thfpos;
   Bool thfflg, thfact, swdact;
   int swdsta;
} hack_;

#define hack_1 hack_

extern struct {
   int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_

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

// NOBJS-	NEW OBJECTS PROCESSOR
// 	OBJECTS IN THIS MODULE CANNOT CALL RMINFO, JIGSUP,
// 	MAJOR VERBS, OR OTHER NON-RESIDENT SUBROUTINES

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS
static Bool mirpan_(int, Bool);

Bool nobjs_(int ri/*, int arg*/) {
// System generated locals
   int i__1, i__2;
   Bool ret_val;

// Local variables
   static Bool f;
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern void rspeak_(int);
   static int target;
   extern void rspsub_(int, int);
   extern void newsta_(int, int, int, int, int);
   static int i__;
   extern int mrhere_(int);
   static int j;
   extern void cpgoto_(int);
   extern void cpinfo_(int, int);
   extern void princr_(Bool, int);
   static int av, wl;
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
   extern void bug_(int, int);
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
   extern int rnd_(int);
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
   static int nxt, odi2, odo2;
#define pvec ((int *)&pv_1)
   extern Bool qhere_(int, int);
#define rrand ((int *)&rooms_1 + 602)
#define objvec ((int *)&pv_1 + 1)
   extern Bool opncls_(int, int, int);
#define prpvec ((int *)&pv_1 + 3)
   extern Bool moveto_(int, int);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// SCREEN OF LIGHT

// MISCELLANEOUS VARIABLES

// PUZZLE ROOM STATE

// ROOMS

// OBJECTS

// CLOCK INTERRUPTS

// VILLAINS AND DEMONS

// ADVENTURERS

// VERBS

// FUNCTIONS AND DATA

// FLAGS

// NOBJS, PAGE 2

   if (prsvec_1.prso != 0) {
      odo2 = objcts_1.odesc2[prsvec_1.prso - 1];
   }
   if (prsvec_1.prsi != 0) {
      odi2 = objcts_1.odesc2[prsvec_1.prsi - 1];
   }
   av = advs_1.avehic[play_1.winner - 1];
   ret_val = true;

   switch (ri - 31) {
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
   }
   bug_(6, ri);

// RETURN HERE TO DECLARE FALSE RESULT

L10:
   ret_val = false;
   return ret_val;

// O32--	BILLS

L1000:
   if (prsvec_1.prsa != vindex_1.eatw) {
      goto L1100;
   }
// 						!EAT?
   rspeak_(639);
// 						!JOKE.
   return ret_val;

L1100:
   if (prsvec_1.prsa == vindex_1.burnw) {
      rspeak_(640);
   }
// 						!BURN?  JOKE.
   goto L10;
// 						!LET IT BE HANDLED.
// NOBJS, PAGE 3

// O33--	SCREEN OF LIGHT

L2000:
   target = oindex_1.scol;
// 						!TARGET IS SCOL.
L2100:
   if (prsvec_1.prso != target) {
      goto L2400;
   }
// 						!PRSO EQ TARGET?
   if (prsvec_1.prsa != vindex_1.pushw && prsvec_1.prsa != vindex_1.movew && prsvec_1.prsa != vindex_1.takew && prsvec_1.prsa != vindex_1.rubw) {
      goto L2200;
   }
   rspeak_(673);
// 						!HAND PASSES THRU.
   return ret_val;

L2200:
   if (prsvec_1.prsa != vindex_1.killw && prsvec_1.prsa != vindex_1.attacw && prsvec_1.prsa != vindex_1.mungw) {
      goto L2400;
   }
   rspsub_(674, odi2);
// 						!PASSES THRU.
   return ret_val;

L2400:
   if (prsvec_1.prsa != vindex_1.throww || prsvec_1.prsi != target) {
      goto L10;
   }
   if (play_1.here == rindex_1.bkbox) {
      goto L2600;
   }
// 						!THRU SCOL?
   newsta_(prsvec_1.prso, 0, rindex_1.bkbox, 0, 0);
// 						!NO, THRU WALL.
   rspsub_(675, odo2);
// 						!ENDS UP IN BOX ROOM.
   cevent_1.ctick[cindex_1.cevscl - 1] = 0;
// 						!CANCEL ALARM.
   screen_1.scolrm = 0;
// 						!RESET SCOL ROOM.
   return ret_val;

L2600:
   if (screen_1.scolrm == 0) {
      goto L2900;
   }
// 						!TRIED TO GO THRU?
   newsta_(prsvec_1.prso, 0, screen_1.scolrm, 0, 0);
// 						!SUCCESS.
   rspsub_(676, odo2);
// 						!ENDS UP SOMEWHERE.
   cevent_1.ctick[cindex_1.cevscl - 1] = 0;
// 						!CANCEL ALARM.
   screen_1.scolrm = 0;
// 						!RESET SCOL ROOM.
   return ret_val;

L2900:
   rspeak_(213);
// 						!CANT DO IT.
   return ret_val;
// NOBJS, PAGE 4

// O34--	GNOME OF ZURICH

L3000:
   if (prsvec_1.prsa != vindex_1.givew && prsvec_1.prsa != vindex_1.throww) {
      goto L3200;
   }
   if (objcts_1.otval[prsvec_1.prso - 1] != 0) {
      goto L3100;
   }
// 						!THROW A TREASURE?
   newsta_(prsvec_1.prso, 641, 0, 0, 0);
// 						!NO, GO POP.
   return ret_val;

L3100:
   newsta_(prsvec_1.prso, 0, 0, 0, 0);
// 						!YES, BYE BYE TREASURE.
   rspsub_(642, odo2);
   newsta_(oindex_1.zgnom, 0, 0, 0, 0);
// 						!BYE BYE GNOME.
   cevent_1.ctick[cindex_1.cevzgo - 1] = 0;
// 						!CANCEL EXIT.
   f = moveto_(rindex_1.bkent, play_1.winner);
// 						!NOW IN BANK ENTRANCE.
   return ret_val;

L3200:
   if (prsvec_1.prsa != vindex_1.attacw && prsvec_1.prsa != vindex_1.killw && prsvec_1.prsa != vindex_1.mungw) {
      goto L3300;
   }
   newsta_(oindex_1.zgnom, 643, 0, 0, 0);
// 						!VANISH GNOME.
   cevent_1.ctick[cindex_1.cevzgo - 1] = 0;
// 						!CANCEL EXIT.
   return ret_val;

L3300:
   rspeak_(644);
// 						!GNOME IS IMPATIENT.
   return ret_val;

// O35--	EGG

L4000:
   if (prsvec_1.prsa != vindex_1.openw || prsvec_1.prso != oindex_1.egg) {
      goto L4500;
   }
   if (!((objcts_1.oflag2[oindex_1.egg - 1] & oflags_1.openbt) != 0)) {
      goto L4100;
   }
// 						!OPEN ALREADY?
   rspeak_(649);
// 						!YES.
   return ret_val;

L4100:
   if (prsvec_1.prsi != 0) {
      goto L4200;
   }
// 						!WITH SOMETHING?
   rspeak_(650);
// 						!NO, CANT.
   return ret_val;

L4200:
   if (prsvec_1.prsi != oindex_1.hands) {
      goto L4300;
   }
// 						!WITH HANDS?
   rspeak_(651);
// 						!NOT RECOMMENDED.
   return ret_val;

L4300:
   i__ = 652;
// 						!MUNG MESSAGE.
   if ((objcts_1.oflag1[prsvec_1.prsi - 1] & oflags_1.toolbt) != 0 || (objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.weapbt) != 0) {
      goto L4600;
   }
   i__ = 653;
// 						!NOVELTY 1.
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.fitebt) != 0) {
      i__ = 654;
   }
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.fitebt;
   rspsub_(i__, odi2);
   return ret_val;

L4500:
   if (prsvec_1.prsa != vindex_1.openw && prsvec_1.prsa != vindex_1.mungw) {
      goto L4800;
   }
   i__ = 655;
// 						!YOU BLEW IT.
L4600:
   newsta_(oindex_1.begg, i__, objcts_1.oroom[oindex_1.egg - 1], objcts_1.ocan[oindex_1.egg - 1], objcts_1.oadv[oindex_1.egg - 1]);
   newsta_(oindex_1.egg, 0, 0, 0, 0);
// 						!VANISH EGG.
   objcts_1.otval[oindex_1.begg - 1] = 2;
// 						!BAD EGG HAS VALUE.
   if (objcts_1.ocan[oindex_1.canar - 1] != oindex_1.egg) {
      goto L4700;
   }
// 						!WAS CANARY INSIDE?
   rspeak_(objcts_1.odesco[oindex_1.bcana - 1]);
// 						!YES, DESCRIBE RESULT.
   objcts_1.otval[oindex_1.bcana - 1] = 1;
   return ret_val;

L4700:
   newsta_(oindex_1.bcana, 0, 0, 0, 0);
// 						!NO, VANISH IT.
   return ret_val;

L4800:
   if (prsvec_1.prsa != vindex_1.dropw || play_1.here != rindex_1.mtree) {
      goto L10;
   }
   newsta_(oindex_1.begg, 658, rindex_1.fore3, 0, 0);
// 						!DROPPED EGG.
   newsta_(oindex_1.egg, 0, 0, 0, 0);
   objcts_1.otval[oindex_1.begg - 1] = 2;
   if (objcts_1.ocan[oindex_1.canar - 1] != oindex_1.egg) {
      goto L4700;
   }
   objcts_1.otval[oindex_1.bcana - 1] = 1;
// 						!BAD CANARY.
   return ret_val;
// NOBJS, PAGE 5

// O36--	CANARIES, GOOD AND BAD

L5000:
   if (prsvec_1.prsa != vindex_1.windw) {
      goto L10;
   }
// 						!WIND EM UP?
   if (prsvec_1.prso == oindex_1.canar) {
      goto L5100;
   }
// 						!RIGHT ONE?
   rspeak_(645);
// 						!NO, BAD NEWS.
   return ret_val;

L5100:
   if (!findex_1.singsf && (play_1.here == rindex_1.mtree || play_1.here >= rindex_1.fore1 && play_1.here < rindex_1.clear)) {
      goto L5200;
   }
   rspeak_(646);
// 						!NO, MEDIOCRE NEWS.
   return ret_val;

L5200:
   findex_1.singsf = true;
// 						!SANG SONG.
   i__ = play_1.here;
   if (i__ == rindex_1.mtree) {
      i__ = rindex_1.fore3;
   }
// 						!PLACE BAUBLE.
   newsta_(oindex_1.baubl, 647, i__, 0, 0);
   return ret_val;

// O37--	WHITE CLIFFS

L6000:
   if (prsvec_1.prsa != vindex_1.clmbw && prsvec_1.prsa != vindex_1.clmbuw && prsvec_1.prsa != vindex_1.clmbdw) {
      goto L10;
   }
   rspeak_(648);
// 						!OH YEAH?
   return ret_val;

// O38--	WALL

L7000:
   if ((i__1 = play_1.here - findex_1.mloc, abs(i__1)) != 1 || mrhere_(play_1.here) != 0 || prsvec_1.prsa != vindex_1.pushw) {
      goto L7100;
   }
   rspeak_(860);
// 						!PUSHED MIRROR WALL.
   return ret_val;

L7100:
   if ((rooms_1.rflag[play_1.here - 1] & rflag_1.rnwall) == 0) {
      goto L10;
   }
   rspeak_(662);
// 						!NO WALL.
   return ret_val;
// NOBJS, PAGE 6

// O39--	SONG BIRD GLOBAL

L8000:
   if (prsvec_1.prsa != vindex_1.findw) {
      goto L8100;
   }
// 						!FIND?
   rspeak_(666);
   return ret_val;

L8100:
   if (prsvec_1.prsa != vindex_1.examiw) {
      goto L10;
   }
// 						!EXAMINE?
   rspeak_(667);
   return ret_val;

// O40--	PUZZLE/SCOL WALLS

L9000:
   if (play_1.here != rindex_1.cpuzz) {
      goto L9500;
   }
// 						!PUZZLE WALLS?
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
// 						!PUSH?
   for (i__ = 1; i__ <= 8; i__ += 2) {
// 						!LOCATE WALL.
      if (prsvec_1.prso == puzzle_1.cpwl[i__ - 1]) {
         goto L9200;
      }
// L9100:
   }
   bug_(80, prsvec_1.prso);
// 						!WHAT?

L9200:
   j = puzzle_1.cpwl[i__];
// 						!GET DIRECTIONAL OFFSET.
   nxt = findex_1.cphere + j;
// 						!GET NEXT STATE.
   wl = puzzle_1.cpvec[nxt - 1];
// 						!GET C(NEXT STATE).
   switch (wl + 4) {
      case 1:
         goto L9300;
      case 2:
         goto L9300;
      case 3:
         goto L9300;
      case 4:
         goto L9250;
      case 5:
         goto L9350;
   }
// 						!PROCESS.

L9250:
   rspeak_(876);
// 						!CLEAR CORRIDOR.
   return ret_val;

L9300:
   if (puzzle_1.cpvec[nxt + j - 1] == 0) {
      goto L9400;
   }
// 						!MOVABLE, ROOM TO MOVE?
L9350:
   rspeak_(877);
// 						!IMMOVABLE, NO ROOM.
   return ret_val;

L9400:
   i__ = 878;
// 						!ASSUME FIRST PUSH.
   if (findex_1.cpushf) {
      i__ = 879;
   }
// 						!NOT?
   findex_1.cpushf = true;
   puzzle_1.cpvec[nxt + j - 1] = wl;
// 						!MOVE WALL.
   puzzle_1.cpvec[nxt - 1] = 0;
// 						!VACATE NEXT STATE.
   cpgoto_(nxt);
// 						!ONWARD.
   cpinfo_(i__, nxt);
// 						!DESCRIBE.
   princr_(true, play_1.here);
// 						!PRINT ROOMS CONTENTS.
   rooms_1.rflag[play_1.here - 1] |= rflag_1.rseen;
   return ret_val;

L9500:
   if (play_1.here != screen_1.scolac) {
      goto L9700;
   }
// 						!IN SCOL ACTIVE ROOM?
   for (i__ = 1; i__ <= 12; i__ += 3) {
      target = screen_1.scolwl[i__];
// 						!ASSUME TARGET.
      if (screen_1.scolwl[i__ - 1] == play_1.here) {
         goto L2100;
      }
// 						!TREAT IF FOUND.
// L9600:
   }

L9700:
   if (play_1.here != rindex_1.bkbox) {
      goto L10;
   }
// 						!IN BOX ROOM?
   target = oindex_1.wnort;
   goto L2100;
// NOBJS, PAGE 7

// O41--	SHORT POLE

L10000:
   if (prsvec_1.prsa != vindex_1.raisew) {
      goto L10100;
   }
// 						!LIFT?
   i__ = 749;
// 						!ASSUME UP.
   if (findex_1.poleuf == 2) {
      i__ = 750;
   }
// 						!ALREADY UP?
   rspeak_(i__);
   findex_1.poleuf = 2;
// 						!POLE IS RAISED.
   return ret_val;

L10100:
   if (prsvec_1.prsa != vindex_1.lowerw && prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
   if (findex_1.poleuf != 0) {
      goto L10200;
   }
// 						!ALREADY LOWERED?
   rspeak_(751);
// 						!CANT DO IT.
   return ret_val;

L10200:
   if (findex_1.mdir % 180 != 0) {
      goto L10300;
   }
// 						!MIRROR N-S?
   findex_1.poleuf = 0;
// 						!YES, LOWER INTO
   rspeak_(752);
// 						!CHANNEL.
   return ret_val;

L10300:
   if (findex_1.mdir != 270 || findex_1.mloc != rindex_1.mrb) {
      goto L10400;
   }
   findex_1.poleuf = 0;
// 						!LOWER INTO HOLE.
   rspeak_(753);
   return ret_val;

L10400:
   i__1 = findex_1.poleuf + 753;
   rspeak_(i__1);
// 						!POLEUF = 1 OR 2.
   findex_1.poleuf = 1;
// 						!NOW ON FLOOR.
   return ret_val;

// O42--	MIRROR SWITCH

L11000:
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
// 						!PUSH?
   if (findex_1.mrpshf) {
      goto L11300;
   }
// 						!ALREADY PUSHED?
   rspeak_(756);
// 						!BUTTON GOES IN.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!BLOCKED?
      if (qhere_(i__, rindex_1.mreye) && i__ != oindex_1.rbeam) {
         goto L11200;
      }
// L11100:
   }
   rspeak_(757);
// 						!NOTHING IN BEAM.
   return ret_val;

L11200:
   cevent_1.cflag[cindex_1.cevmrs - 1] = true;
// 						!MIRROR OPENS.
   cevent_1.ctick[cindex_1.cevmrs - 1] = 7;
   findex_1.mrpshf = true;
   findex_1.mropnf = true;
   return ret_val;

L11300:
   rspeak_(758);
// 						!MIRROR ALREADYOPEN.
   return ret_val;
// NOBJS, PAGE 8

// O43--	BEAM FUNCTION

L12000:
   if (prsvec_1.prsa != vindex_1.takew || prsvec_1.prso != oindex_1.rbeam) {
      goto L12100;
   }
   rspeak_(759);
// 						!TAKE BEAM, JOKE.
   return ret_val;

L12100:
   i__ = prsvec_1.prso;
// 						!ASSUME BLK WITH DIROBJ.
   if (prsvec_1.prsa == vindex_1.putw && prsvec_1.prsi == oindex_1.rbeam) {
      goto L12200;
   }
   if (prsvec_1.prsa != vindex_1.mungw || prsvec_1.prso != oindex_1.rbeam || prsvec_1.prsi == 0) {
      goto L10;
   }
   i__ = prsvec_1.prsi;
L12200:
   if (objcts_1.oadv[i__ - 1] != play_1.winner) {
      goto L12300;
   }
// 						!CARRYING?
   newsta_(i__, 0, play_1.here, 0, 0);
// 						!DROP OBJ.
   rspsub_(760, objcts_1.odesc2[i__ - 1]);
   return ret_val;

L12300:
   j = 761;
// 						!ASSUME NOT IN ROOM.
   if (qhere_(j, play_1.here)) {
      i__ = 762;
   }
// 						!IN ROOM?
   rspsub_(j, objcts_1.odesc2[i__ - 1]);
// 						!DESCRIBE.
   return ret_val;

// O44--	BRONZE DOOR

L13000:
   if (play_1.here == rindex_1.ncell || findex_1.lcell == 4 && (play_1.here == rindex_1.cell || play_1.here == rindex_1.scorr)) {
      goto L13100;
   }
   rspeak_(763);
// 						!DOOR NOT THERE.
   return ret_val;

L13100:
   if (!opncls_(oindex_1.odoor, 764, 765)) {
      goto L10;
   }
// 						!OPEN/CLOSE?
   if (play_1.here == rindex_1.ncell && (objcts_1.oflag2[oindex_1.odoor - 1] & oflags_1.openbt) != 0) {
      rspeak_(766);
   }
   return ret_val;

// O45--	QUIZ DOOR

L14000:
   if (prsvec_1.prsa != vindex_1.openw && prsvec_1.prsa != vindex_1.closew) {
      goto L14100;
   }
   rspeak_(767);
// 						!DOOR WONT MOVE.
   return ret_val;

L14100:
   if (prsvec_1.prsa != vindex_1.knockw) {
      goto L10;
   }
// 						!KNOCK?
   if (findex_1.inqstf) {
      goto L14200;
   }
// 						!TRIED IT ALREADY?
   findex_1.inqstf = true;
// 						!START INQUISITION.
   cevent_1.cflag[cindex_1.cevinq - 1] = true;
   cevent_1.ctick[cindex_1.cevinq - 1] = 2;
   findex_1.quesno = rnd_(8);
// 						!SELECT QUESTION.
   findex_1.nqatt = 0;
   findex_1.corrct = 0;
   rspeak_(768);
// 						!ANNOUNCE RULES.
   rspeak_(769);
   i__1 = findex_1.quesno + 770;
   rspeak_(i__1);
// 						!ASK QUESTION.
   return ret_val;

L14200:
   rspeak_(798);
// 						!NO REPLY.
   return ret_val;

// O46--	LOCKED DOOR

L15000:
   if (prsvec_1.prsa != vindex_1.openw) {
      goto L10;
   }
// 						!OPEN?
   rspeak_(778);
// 						!CANT.
   return ret_val;

// O47--	CELL DOOR

L16000:
   ret_val = opncls_(oindex_1.cdoor, 779, 780);
// 						!OPEN/CLOSE?
   return ret_val;
// NOBJS, PAGE 9

// O48--	DIALBUTTON

L17000:
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L10;
   }
// 						!PUSH?
   rspeak_(809);
// 						!CLICK.
   if ((objcts_1.oflag2[oindex_1.cdoor - 1] & oflags_1.openbt) != 0) {
      rspeak_(810);
   }
// 						!CLOSE CELL DOOR.

   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!RELOCATE OLD TO HYPER.
      if (objcts_1.oroom[i__ - 1] == rindex_1.cell && (objcts_1.oflag1[i__ - 1] & oflags_1.doorbt) == 0) {
         i__2 = findex_1.lcell * hyper_1.hfactr;
         newsta_(i__, 0, i__2, 0, 0);
      }
      if (objcts_1.oroom[i__ - 1] == findex_1.pnumb * hyper_1.hfactr) {
         newsta_(i__, 0, rindex_1.cell, 0, 0);
      }
// L17100:
   }

   objcts_1.oflag2[oindex_1.odoor - 1] &= ~oflags_1.openbt;
   objcts_1.oflag2[oindex_1.cdoor - 1] &= ~oflags_1.openbt;
   objcts_1.oflag1[oindex_1.odoor - 1] &= ~oflags_1.visibt;
   if (findex_1.pnumb == 4) {
      objcts_1.oflag1[oindex_1.odoor - 1] |= oflags_1.visibt;
   }

   if (advs_1.aroom[aindex_1.player - 1] != rindex_1.cell) {
      goto L17400;
   }
// 						!PLAYER IN CELL?
   if (findex_1.lcell != 4) {
      goto L17200;
   }
// 						!IN RIGHT CELL?
   objcts_1.oflag1[oindex_1.odoor - 1] |= oflags_1.visibt;
   f = moveto_(rindex_1.ncell, aindex_1.player);
// 						!YES, MOVETO NCELL.
   goto L17400;
L17200:
   f = moveto_(rindex_1.pcell, aindex_1.player);
// 						!NO, MOVETO PCELL.

L17400:
   findex_1.lcell = findex_1.pnumb;
   return ret_val;
// NOBJS, PAGE 10

// O49--	DIAL INDICATOR

L18000:
   if (prsvec_1.prsa != vindex_1.spinw) {
      goto L18100;
   }
// 						!SPIN?
   findex_1.pnumb = rnd_(8) + 1;
// 						!WHEE
// 						!
   i__1 = findex_1.pnumb + 712;
   rspsub_(797, i__1);
   return ret_val;

L18100:
   if (prsvec_1.prsa != vindex_1.movew && prsvec_1.prsa != vindex_1.putw && prsvec_1.prsa != vindex_1.trntow) {
      goto L10;
   }
   if (prsvec_1.prsi != 0) {
      goto L18200;
   }
// 						!TURN DIAL TO X?
   rspeak_(806);
// 						!MUST SPECIFY.
   return ret_val;

L18200:
   if (prsvec_1.prsi >= oindex_1.num1 && prsvec_1.prsi <= oindex_1.num8) {
      goto L18300;
   }
   rspeak_(807);
// 						!MUST BE DIGIT.
   return ret_val;

L18300:
   findex_1.pnumb = prsvec_1.prsi - oindex_1.num1 + 1;
// 						!SET UP NEW.
   i__1 = findex_1.pnumb + 712;
   rspsub_(808, i__1);
   return ret_val;

// O50--	GLOBAL MIRROR

L19000:
   ret_val = mirpan_(832, false);
   return ret_val;

// O51--	GLOBAL PANEL

L20000:
   if (play_1.here != rindex_1.fdoor) {
      goto L20100;
   }
// 						!AT FRONT DOOR?
   if (prsvec_1.prsa != vindex_1.openw && prsvec_1.prsa != vindex_1.closew) {
      goto L10;
   }
   rspeak_(843);
// 						!PANEL IN DOOR, NOGO.
   return ret_val;

L20100:
   ret_val = mirpan_(838, true);
   return ret_val;

// O52--	PUZZLE ROOM SLIT

L21000:
   if (prsvec_1.prsa != vindex_1.putw || prsvec_1.prsi != oindex_1.cslit) {
      goto L10;
   }
   if (prsvec_1.prso != oindex_1.gcard) {
      goto L21100;
   }
// 						!PUT CARD IN SLIT?
   newsta_(prsvec_1.prso, 863, 0, 0, 0);
// 						!KILL CARD.
   findex_1.cpoutf = true;
// 						!OPEN DOOR.
   objcts_1.oflag1[oindex_1.stldr - 1] &= ~oflags_1.visibt;
   return ret_val;

L21100:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.victbt) == 0 && (objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt) == 0) {
      goto L21200;
   }
   i__1 = rnd_(5) + 552;
   rspeak_(i__1);
// 						!JOKE FOR VILL, VICT.
   return ret_val;

L21200:
   newsta_(prsvec_1.prso, 0, 0, 0, 0);
// 						!KILL OBJECT.
   rspsub_(864, odo2);
// 						!DESCRIBE.
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

// MIRPAN--	PROCESSOR FOR GLOBAL MIRROR/PANEL

// DECLARATIONS

static Bool mirpan_(int st, Bool pnf) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int num;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
   static int mrbf;
#define pvec ((int *)&pv_1)
#define flags ((Bool *)&findex_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
#define switch__ ((int *)&findex_1 + 46)
   extern int mrhere_(int);
   extern void rspeak_(int);

// GAME STATE

// PARSER OUTPUT

// PARSER STATE

// VERBS

// MIRPAN, PAGE 2

// FLAGS

   ret_val = true;
   num = mrhere_(play_1.here);
// 						!GET MIRROR NUM.
   if (num != 0) {
      goto L100;
   }
// 						!ANY HERE?
   rspeak_(st);
// 						!NO, LOSE.
   return ret_val;

L100:
   mrbf = 0;
// 						!ASSUME MIRROR OK.
   if (num == 1 && !findex_1.mr1f || num == 2 && !findex_1.mr2f) {
      mrbf = 1;
   }
   if (prsvec_1.prsa != vindex_1.movew && prsvec_1.prsa != vindex_1.openw) {
      goto L200;
   }
   i__1 = st + 1;
   rspeak_(i__1);
// 						!CANT OPEN OR MOVE.
   return ret_val;

L200:
   if (pnf || prsvec_1.prsa != vindex_1.lookiw && prsvec_1.prsa != vindex_1.examiw && prsvec_1.prsa != vindex_1.lookw) {
      goto L300;
   }
   i__1 = mrbf + 844;
   rspeak_(i__1);
// 						!LOOK IN MIRROR.
   return ret_val;

L300:
   if (prsvec_1.prsa != vindex_1.mungw) {
      goto L400;
   }
// 						!BREAK?
   i__1 = st + 2 + mrbf;
   rspeak_(i__1);
// 						!DO IT.
   if (num == 1 && !(pnf)) {
      findex_1.mr1f = false;
   }
   if (num == 2 && !(pnf)) {
      findex_1.mr2f = false;
   }
   return ret_val;

L400:
   if (pnf || mrbf == 0) {
      goto L500;
   }
// 						!BROKEN MIRROR?
   rspeak_(846);
   return ret_val;

L500:
   if (prsvec_1.prsa != vindex_1.pushw) {
      goto L600;
   }
// 						!PUSH?
   i__1 = st + 3 + num;
   rspeak_(i__1);
   return ret_val;

L600:
   ret_val = false;
// 						!CANT HANDLE IT.
   return ret_val;

}

#undef switch__
#undef prpvec
#undef objvec
#undef flags
#undef pvec
#undef syn
#undef orp
