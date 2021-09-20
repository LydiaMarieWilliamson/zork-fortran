// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

// Applicables for adventurers
Bool aappli(int ri) {
// System generated locals
   Bool ret_val;

// Local variables
   Bool f;
   int i;

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
   bug(11, ri);

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
   f = moveto(rindex_1.cager, play_1.winner);
// 						!MOVE TO NEW ROOM.
   newsta(oindex_1.cage, 567, rindex_1.cager, 0, 0);
// 						!INSTALL CAGE IN ROOM.
   newsta(oindex_1.robot, 0, rindex_1.cager, 0, 0);
// 						!INSTALL ROBOT IN ROOM.
   advs_1.aroom[aindex_1.arobot - 1] = rindex_1.cager;
// 						!ALSO MOVE ROBOT/ADV.
   findex_1.cagesf = true;
// 						!CAGE SOLVED.
   objcts_1.oflag1[oindex_1.robot - 1] &= ~NDscO;
   objcts_1.oflag1[oindex_1.spher - 1] |= TakeO;
   return ret_val;

L1200:
   if (prsvec_1.prsa != vindex_1.drinkw && prsvec_1.prsa != vindex_1.eatw) {
      goto L1300;
   }
   rspeak(568);
// 						!EAT OR DRINK, JOKE.
   return ret_val;

L1300:
   if (prsvec_1.prsa != vindex_1.readw) {
      goto L1400;
   }
// 						!READ,
   rspeak(569);
// 						!JOKE.
   return ret_val;

L1400:
   if (prsvec_1.prsa == vindex_1.walkw || prsvec_1.prsa == vindex_1.takew || prsvec_1.prsa == vindex_1.dropw || prsvec_1.prsa == vindex_1.putw || prsvec_1.prsa == vindex_1.pushw || prsvec_1.prsa == vindex_1.throww || prsvec_1.prsa == vindex_1.turnw || prsvec_1.prsa == vindex_1.leapw) {
      goto L10;
   }
   rspeak(570);
// 						!JOKE.
   return ret_val;
// AAPPLI, PAGE 3

// A2--	MASTER.  PROCESS MOST COMMANDS GIVEN TO MASTER.

L2000:
   if ((objcts_1.oflag2[oindex_1.qdoor - 1] & OpenO) != 0) {
      goto L2100;
   }
   rspeak(783);
// 						!NO MASTER YET.
   return ret_val;

L2100:
   if (prsvec_1.prsa != vindex_1.walkw) {
      goto L2200;
   }
// 						!WALK?
   i = 784;
// 						!ASSUME WONT.
   if (play_1.here == rindex_1.scorr && (prsvec_1.prso == xsrch_1.xnorth || prsvec_1.prso == xsrch_1.xenter) || play_1.here == rindex_1.ncorr && (prsvec_1.prso == xsrch_1.xsouth || prsvec_1.prso == xsrch_1.xenter)) {
      i = 785;
   }
   rspeak(i);
   return ret_val;

L2200:
   if (prsvec_1.prsa == vindex_1.takew || prsvec_1.prsa == vindex_1.dropw || prsvec_1.prsa == vindex_1.putw || prsvec_1.prsa == vindex_1.throww || prsvec_1.prsa == vindex_1.pushw || prsvec_1.prsa == vindex_1.turnw || prsvec_1.prsa == vindex_1.spinw || prsvec_1.prsa == vindex_1.trntow || prsvec_1.prsa == vindex_1.follow || prsvec_1.prsa == vindex_1.stayw || prsvec_1.prsa == vindex_1.openw || prsvec_1.prsa == vindex_1.closew || prsvec_1.prsa == vindex_1.killw) {
      goto L10;
   }
   rspeak(786);
// 						!MASTER CANT DO IT.
   return ret_val;
}

// Intermove thief demon
void thiefd(void) {
// System generated locals
   int i__1, i__2;

// Local variables
   int i, j, nr;
   Bool once;
   int rhere;

// THIEFD, PAGE 2

#ifdef ALLOW_GDT
   dflag = (debug_1.prsflg & 32768) != 0;
#endif
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

#ifdef ALLOW_GDT
   if (dflag) print(" THIEFD-- IN TREASURE ROOM");
#endif
   if (rhere == 0) {
      goto L1050;
   }
// 						!VISIBLE?
   newsta(oindex_1.thief, 0, 0, 0, 0);
// 						!YES, VANISH.
   rhere = 0;
   if (qhere(oindex_1.still, rindex_1.treas) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
L1050:
   i__1 = -oindex_1.thief;
   i = robadv(i__1, hack_1.thfpos, 0, 0);
// 						!DROP VALUABLES.
   if (qhere(oindex_1.egg, hack_1.thfpos)) {
      objcts_1.oflag2[oindex_1.egg - 1] |= OpenO;
   }
   goto L1700;

// THIEF AND WINNER IN SAME ROOM.

L1100:
   if (hack_1.thfpos == rindex_1.treas) {
      goto L1700;
   }
// 						!IF TREAS ROOM, NOTHING.
   if ((rooms_1.rflag[hack_1.thfpos - 1] & LightR) != 0) {
      goto L1400;
   }
#ifdef ALLOW_GDT
   if (dflag) print(" THIEFD-- IN ADV ROOM");
#endif
   if (hack_1.thfflg) {
      goto L1300;
   }
// 						!THIEF ANNOUNCED?
   if (rhere != 0 || prob(70, 70)) {
      goto L1150;
   }
// 						!IF INVIS AND 30%.
   if (objcts_1.ocan[oindex_1.still - 1] != oindex_1.thief) {
      goto L1700;
   }
// 						!ABORT IF NO STILLETTO.
   newsta(oindex_1.thief, 583, hack_1.thfpos, 0, 0);
// 						!INSERT THIEF INTO ROOM.
   hack_1.thfflg = true;
// 						!THIEF IS ANNOUNCED.
   return;

L1150:
   if (rhere == 0 || (objcts_1.oflag2[oindex_1.thief - 1] & FiteO) == 0) {
      goto L1200;
   }
   if (winnin(oindex_1.thief, play_1.winner)) {
      goto L1175;
   }
// 						!WINNING?
   newsta(oindex_1.thief, 584, 0, 0, 0);
// 						!NO, VANISH THIEF.
   objcts_1.oflag2[oindex_1.thief - 1] &= ~FiteO;
   if (qhere(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   return;

L1175:
   if (prob(90, 90)) {
      goto L1700;
   }
// 						!90% CHANCE TO STAY.

L1200:
   if (rhere == 0 || prob(70, 70)) {
      goto L1250;
   }
// 						!IF VISIBLE AND 30%
   newsta(oindex_1.thief, 585, 0, 0, 0);
// 						!VANISH THIEF.
   if (qhere(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   return;

L1300:
   if (rhere == 0) {
      goto L1700;
   }
// 						!ANNOUNCED.  VISIBLE?
L1250:
   if (prob(70, 70)) {
      return;
   }
// 						!70% CHANCE TO DO NOTHING.
   hack_1.thfflg = true;
   i__1 = -oindex_1.thief;
   i__2 = -oindex_1.thief;
   nr = robrm(hack_1.thfpos, 100, 0, 0, i__1) + robadv(play_1.winner, 0, 0, i__2);
   i = 586;
// 						!ROBBED EM.
   if (rhere != 0) {
      i = 588;
   }
// 						!WAS HE VISIBLE?
   if (nr != 0) {
      ++i;
   }
// 						!DID HE GET ANYTHING?
   newsta(oindex_1.thief, i, 0, 0, 0);
// 						!VANISH THIEF.
   if (qhere(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   if (nr != 0 && !lit(hack_1.thfpos)) {
      rspeak(406);
   }
   rhere = 0;
   goto L1700;
// 						!ONWARD.

// NOT IN ADVENTURERS ROOM.

L1400:
   newsta(oindex_1.thief, 0, 0, 0, 0);
// 						!VANISH.
   rhere = 0;
#ifdef ALLOW_GDT
   if (dflag) print(" THIEFD-- IN ROOM %I4", hack_1.thfpos);
#endif
   if (qhere(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief) {
      newsta(oindex_1.still, 0, 0, oindex_1.thief, 0);
   }
   if ((rooms_1.rflag[hack_1.thfpos - 1] & SeenR) == 0) {
      goto L1700;
   }
   i__1 = -oindex_1.thief;
   i = robrm(hack_1.thfpos, 75, 0, 0, i__1);
// 						!ROB ROOM 75%.
   if (hack_1.thfpos < rindex_1.maze1 || hack_1.thfpos > rindex_1.maz15 || play_1.here < rindex_1.maze1 || play_1.here > rindex_1.maz15) {
      goto L1500;
   }
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!BOTH IN MAZE.
      if (!qhere(i, hack_1.thfpos) || prob(60, 60) || (objcts_1.oflag1[i - 1] & VisiO + TakeO) != VisiO + TakeO) {
         goto L1450;
      }
      rspsub(590, objcts_1.odesc2[i - 1]);
// 						!TAKE OBJECT.
      if (prob(40, 20)) {
         goto L1700;
      }
      i__2 = -oindex_1.thief;
      newsta(i, 0, 0, 0, i__2);
// 						!MOST OF THE TIME.
      objcts_1.oflag2[i - 1] |= TChO;
      goto L1700;
   L1450:
      ;
   }
   goto L1700;

L1500:
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!NOT IN MAZE.
      if (!qhere(i, hack_1.thfpos) || objcts_1.otval[i - 1] != 0 || prob(80, 60) || (objcts_1.oflag1[i - 1] & VisiO + TakeO) != VisiO + TakeO) {
         goto L1550;
      }
      i__2 = -oindex_1.thief;
      newsta(i, 0, 0, 0, i__2);
      objcts_1.oflag2[i - 1] |= TChO;
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
   if ((rooms_1.rflag[hack_1.thfpos - 1] & LandR + SacrdR + EndR) != LandR) {
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
   for (i = 1; i <= i__1; ++i) {
      if (objcts_1.oadv[i - 1] != -oindex_1.thief || prob(70, 70) || objcts_1.otval[i - 1] > 0) {
         goto L1850;
      }
      newsta(i, j, hack_1.thfpos, 0, 0);
      j = 0;
   L1850:
      ;
   }
}
