#include "F2C.h"
#include "parser.h"

// gamestat.h:

// GAME STATE

extern struct {
   int winner, here;
   Bool telflg;
} play_;
#define play_1 play_

// rooms.h:

// ROOMS

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;
#define rooms_1 rooms_
#define eqr ((int *)&rooms_1 + 2)
#define rrand ((int *)&rooms_1 + 602)

// rflag.h:

extern struct rflag_1_ {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;
#define rflag_1 rflag_

// rindex.h:

extern struct rindex_1_ {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;
#define rindex_1 rindex_

// xsrch.h:

extern struct xsrch_1_ {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;
#define xsrch_1 xsrch_

// objects.h:

// OBJECTS

extern struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;
#define objcts_1 objcts_
#define eqo ((int *)&objcts_1 + 1)

extern struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;
#define oroom2_1 oroom2_

// oflags.h:

extern struct oflags_1_ {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;
#define oflags_1 oflags_

// oindex.h:

extern struct oindex_1_ {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;
#define oindex_1 oindex_

// clock.h:

// CLOCK INTERRUPTS

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;
#define cevent_1 cevent_
#define eqc ((int *)&cevent_1 + 1)

extern struct cindex_1_ {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;
#define cindex_1 cindex_

// advers.h:

// ADVENTURERS

extern struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;
#define advs_1 advs_
#define eqa ((int *)&advs_1 + 1)

extern struct aflags_1_ {
   int astag;
} aflags_;
#define aflags_1 aflags_

extern struct aindex_1_ {
   int player, arobot, amastr;
} aindex_;
#define aindex_1 aindex_

// verbs.h:

// VERBS

extern struct vindex_1_ {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;
#define vindex_1 vindex_

// flags.h:

// FLAGS

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;
#define findex_1 findex_
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// debug.h:

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;
#define debug_1 debug_

// villians.h:

// VILLAINS AND DEMONS

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
#define eqv ((int *)&vill_1 + 1)

// AAPPLI- APPLICABLES FOR ADVENTURERS

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool aappli_(int ri) {
// System generated locals
   Bool ret_val;

// Local variables
   static Bool f;
   extern void newsta_(int, int, int, int, int);
   extern void rspeak_(int);
   static int i__;
   extern void bug_(int, int);
   extern Bool moveto_(int, int);

// AAPPLI, PAGE 2

   if (ri == 0) {
      goto L10;
   }
// 						!IF ZERO, NO APP.
   ret_val = true;
// 						!ASSUME WINS.
   switch (ri) {
      case 1:
         goto L1000;
      case 2:
         goto L2000;
   }
// 						!BRANCH ON ADV.
   bug_(11, ri);

// COMMON FALSE RETURN.

L10:
   ret_val = false;
   return ret_val;

// A1--	ROBOT.  PROCESS MOST COMMANDS GIVEN TO ROBOT.

L1000:
   if (prsvec_1.prsa != vindex_1.raisew || prsvec_1.prso != oindex_1.rcage) {
      goto L1200;
   }
   cevent_1.cflag[cindex_1.cevsph - 1] = false;
// 						!ROBOT RAISED CAGE.
   play_1.winner = aindex_1.player;
// 						!RESET FOR PLAYER.
   f = moveto_(rindex_1.cager, play_1.winner);
// 						!MOVE TO NEW ROOM.
   newsta_(oindex_1.cage, 567, rindex_1.cager, 0, 0);
// 						!INSTALL CAGE IN ROOM.
   newsta_(oindex_1.robot, 0, rindex_1.cager, 0, 0);
// 						!INSTALL ROBOT IN ROOM.
   advs_1.aroom[aindex_1.arobot - 1] = rindex_1.cager;
// 						!ALSO MOVE ROBOT/ADV.
   findex_1.cagesf = true;
// 						!CAGE SOLVED.
   objcts_1.oflag1[oindex_1.robot - 1] &= ~oflags_1.ndscbt;
   objcts_1.oflag1[oindex_1.spher - 1] |= oflags_1.takebt;
   return ret_val;

L1200:
   if (prsvec_1.prsa != vindex_1.drinkw && prsvec_1.prsa != vindex_1.eatw) {
      goto L1300;
   }
   rspeak_(568);
// 						!EAT OR DRINK, JOKE.
   return ret_val;

L1300:
   if (prsvec_1.prsa != vindex_1.readw) {
      goto L1400;
   }
// 						!READ,
   rspeak_(569);
// 						!JOKE.
   return ret_val;

L1400:
   if (prsvec_1.prsa == vindex_1.walkw || prsvec_1.prsa == vindex_1.takew || prsvec_1.prsa == vindex_1.dropw || prsvec_1.prsa == vindex_1.putw || prsvec_1.prsa == vindex_1.pushw || prsvec_1.prsa == vindex_1.throww || prsvec_1.prsa == vindex_1.turnw || prsvec_1.prsa == vindex_1.leapw) {
      goto L10;
   }
   rspeak_(570);
// 						!JOKE.
   return ret_val;
// AAPPLI, PAGE 3

// A2--	MASTER.  PROCESS MOST COMMANDS GIVEN TO MASTER.

L2000:
   if ((objcts_1.oflag2[oindex_1.qdoor - 1] & oflags_1.openbt) != 0) {
      goto L2100;
   }
   rspeak_(783);
// 						!NO MASTER YET.
   return ret_val;

L2100:
   if (prsvec_1.prsa != vindex_1.walkw) {
      goto L2200;
   }
// 						!WALK?
   i__ = 784;
// 						!ASSUME WONT.
   if (play_1.here == rindex_1.scorr && (prsvec_1.prso == xsrch_1.xnorth || prsvec_1.prso == xsrch_1.xenter) || play_1.here == rindex_1.ncorr && (prsvec_1.prso == xsrch_1.xsouth || prsvec_1.prso == xsrch_1.xenter)) {
      i__ = 785;
   }
   rspeak_(i__);
   return ret_val;

L2200:
   if (prsvec_1.prsa == vindex_1.takew || prsvec_1.prsa == vindex_1.dropw || prsvec_1.prsa == vindex_1.putw || prsvec_1.prsa == vindex_1.throww || prsvec_1.prsa == vindex_1.pushw || prsvec_1.prsa == vindex_1.turnw || prsvec_1.prsa == vindex_1.spinw || prsvec_1.prsa == vindex_1.trntow || prsvec_1.prsa == vindex_1.follow || prsvec_1.prsa == vindex_1.stayw || prsvec_1.prsa == vindex_1.openw || prsvec_1.prsa == vindex_1.closew || prsvec_1.prsa == vindex_1.killw) {
      goto L10;
   }
   rspeak_(786);
// 						!MASTER CANT DO IT.
   return ret_val;

}

// THIEFD-	INTERMOVE THIEF DEMON

// DECLARATIONS

void thiefd_(void) {
// System generated locals
   int i__1, i__2;

// Local variables
   static int i__, j, nr;
   extern Bool lit_(int);
   static Bool once;
   extern Bool prob_(int, int);
   extern Bool qhere_(int, int);
   extern Bool winnin_(int, int);
   static int rhere;
   extern void newsta_(int, int, int, int, int);
   extern int robadv_(int, int, int, int);
   extern int robrm_(int, int, int, int, int);
   extern void rspeak_(int);
   extern void rspsub_(int, int);

// FUNCTIONS AND DATA

// THIEFD, PAGE 2

// D	DFLAG=IAND(PRSFLG, 32768).NE.0
// 						!SET UP DETAIL FLAG.
   once = false;
// 						!INIT FLAG.
L1025:
   rhere = objcts_1.oroom[oindex_1.thief - 1];
// 						!VISIBLE POS.
   if (rhere != 0) {
      hack_1.thfpos = rhere;
   }

   if (hack_1.thfpos == play_1.here) {
      goto L1100;
   }
// 						!THIEF IN WIN RM?
   if (hack_1.thfpos != rindex_1.treas) {
      goto L1400;
   }
// 						!THIEF NOT IN TREAS?

// THIEF IS IN TREASURE ROOM, AND WINNER IS NOT.

// D	IF(DFLAG) PRINT 10
// D10	FORMAT(' THIEFD-- IN TREASURE ROOM')
   if (rhere == 0) {
      goto L1050;
   }
// 						!VISIBLE?
   newsta_(oindex_1.thief, 0, 0, 0, 0);
// 						!YES, VANISH.
   rhere = 0;
   if (qhere_(oindex_1.still, rindex_1.treas) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
L1050:
   i__1 = -oindex_1.thief;
   i__ = robadv_(i__1, hack_1.thfpos, 0, 0);
// 						!DROP VALUABLES.
   if (qhere_(oindex_1.egg, hack_1.thfpos)) {
      objcts_1.oflag2[oindex_1.egg - 1] |= oflags_1.openbt;
   }
   goto L1700;

// THIEF AND WINNER IN SAME ROOM.

L1100:
   if (hack_1.thfpos == rindex_1.treas) {
      goto L1700;
   }
// 						!IF TREAS ROOM, NOTHING.
   if ((rooms_1.rflag[hack_1.thfpos - 1] & rflag_1.rlight) != 0) {
      goto L1400;
   }
// D	IF(DFLAG) PRINT 20
// D20	FORMAT(' THIEFD-- IN ADV ROOM')
   if (hack_1.thfflg) {
      goto L1300;
   }
// 						!THIEF ANNOUNCED?
   if (rhere != 0 || prob_(70, 70)) {
      goto L1150;
   }
// 						!IF INVIS AND 30%.
   if (objcts_1.ocan[oindex_1.still - 1] != oindex_1.thief) {
      goto L1700;
   }
// 						!ABORT IF NO STILLETTO.
   newsta_(oindex_1.thief, 583, hack_1.thfpos, 0, 0);
// 						!INSERT THIEF INTO ROOM.
   hack_1.thfflg = true;
// 						!THIEF IS ANNOUNCED.
   return;

L1150:
   if (rhere == 0 || (objcts_1.oflag2[oindex_1.thief - 1] & oflags_1.fitebt) == 0) {
      goto L1200;
   }
   if (winnin_(oindex_1.thief, play_1.winner)) {
      goto L1175;
   }
// 						!WINNING?
   newsta_(oindex_1.thief, 584, 0, 0, 0);
// 						!NO, VANISH THIEF.
   objcts_1.oflag2[oindex_1.thief - 1] &= ~oflags_1.fitebt;
   if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   return;

L1175:
   if (prob_(90, 90)) {
      goto L1700;
   }
// 						!90% CHANCE TO STAY.

L1200:
   if (rhere == 0 || prob_(70, 70)) {
      goto L1250;
   }
// 						!IF VISIBLE AND 30%
   newsta_(oindex_1.thief, 585, 0, 0, 0);
// 						!VANISH THIEF.
   if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   return;

L1300:
   if (rhere == 0) {
      goto L1700;
   }
// 						!ANNOUNCED.  VISIBLE?
L1250:
   if (prob_(70, 70)) {
      return;
   }
// 						!70% CHANCE TO DO NOTHING.
   hack_1.thfflg = true;
   i__1 = -oindex_1.thief;
   i__2 = -oindex_1.thief;
   nr = robrm_(hack_1.thfpos, 100, 0, 0, i__1) + robadv_(play_1.winner, 0, 0, i__2);
   i__ = 586;
// 						!ROBBED EM.
   if (rhere != 0) {
      i__ = 588;
   }
// 						!WAS HE VISIBLE?
   if (nr != 0) {
      ++i__;
   }
// 						!DID HE GET ANYTHING?
   newsta_(oindex_1.thief, i__, 0, 0, 0);
// 						!VANISH THIEF.
   if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   if (nr != 0 && !lit_(hack_1.thfpos)) {
      rspeak_(406);
   }
   rhere = 0;
   goto L1700;
// 						!ONWARD.

// NOT IN ADVENTURERS ROOM.

L1400:
   newsta_(oindex_1.thief, 0, 0, 0, 0);
// 						!VANISH.
   rhere = 0;
// D	IF(DFLAG) PRINT 30,THFPOS
// D30	FORMAT(' THIEFD-- IN ROOM ',I4)
   if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   if ((rooms_1.rflag[hack_1.thfpos - 1] & rflag_1.rseen) == 0) {
      goto L1700;
   }
   i__1 = -oindex_1.thief;
   i__ = robrm_(hack_1.thfpos, 75, 0, 0, i__1);
// 						!ROB ROOM 75%.
   if (hack_1.thfpos < rindex_1.maze1 || hack_1.thfpos > rindex_1.maz15 || play_1.here < rindex_1.maze1 || play_1.here > rindex_1.maz15) {
      goto L1500;
   }
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!BOTH IN MAZE.
      if (!qhere_(i__, hack_1.thfpos) || prob_(60, 60) || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt + oflags_1.takebt) != oflags_1.visibt + oflags_1.takebt) {
         goto L1450;
      }
      rspsub_(590, objcts_1.odesc2[i__ - 1]);
// 						!TAKE OBJECT.
      if (prob_(40, 20)) {
         goto L1700;
      }
      i__2 = -oindex_1.thief;
      newsta_(i__, 0, 0, 0, i__2);
// 						!MOST OF THE TIME.
      objcts_1.oflag2[i__ - 1] |= oflags_1.tchbt;
      goto L1700;
   L1450:
      ;
   }
   goto L1700;

L1500:
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!NOT IN MAZE.
      if (!qhere_(i__, hack_1.thfpos) || objcts_1.otval[i__ - 1] != 0 || prob_(80, 60) || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt + oflags_1.takebt) != oflags_1.visibt + oflags_1.takebt) {
         goto L1550;
      }
      i__2 = -oindex_1.thief;
      newsta_(i__, 0, 0, 0, i__2);
      objcts_1.oflag2[i__ - 1] |= oflags_1.tchbt;
      goto L1700;
   L1550:
      ;
   }

// NOW MOVE TO NEW ROOM.

L1700:
   if (objcts_1.oadv[oindex_1.rope - 1] == -oindex_1.thief) {
      findex_1.domef = false;
   }
   if (once) {
      goto L1800;
   }
   once = !once;
L1750:
   --hack_1.thfpos;
// 						!NEXT ROOM.
   if (hack_1.thfpos <= 0) {
      hack_1.thfpos = rooms_1.rlnt;
   }
   if ((rooms_1.rflag[hack_1.thfpos - 1] & rflag_1.rland + rflag_1.rsacrd + rflag_1.rend) != rflag_1.rland) {
      goto L1750;
   }
   hack_1.thfflg = false;
// 						!NOT ANNOUNCED.
   goto L1025;
// 						!ONCE MORE.

// ALL DONE.

L1800:
   if (hack_1.thfpos == rindex_1.treas) {
      return;
   }
// 						!IN TREASURE ROOM?
   j = 591;
// 						!NO, DROP STUFF.
   if (hack_1.thfpos != play_1.here) {
      j = 0;
   }
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (objcts_1.oadv[i__ - 1] != -oindex_1.thief || prob_(70, 70) || objcts_1.otval[i__ - 1] > 0) {
         goto L1850;
      }
      newsta_(i__, j, hack_1.thfpos, 0, 0);
      j = 0;
   L1850:
      ;
   }
}
