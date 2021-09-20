// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

// RESIDENT SUBROUTINES FOR DUNGEON
// RSPEAK-- OUTPUT RANDOM MESSAGE ROUTINE
// CALLED BY--
// 	CALL RSPEAK(MSGNUM)
void rspeak(int n) {
   rspsb2(n, 0, 0);
}

// RSPSUB-- OUTPUT RANDOM MESSAGE WITH SUBSTITUTABLE ARGUMENT
// CALLED BY--
// 	CALL RSPSUB(MSGNUM,SUBNUM)
void rspsub(int n, int s1) {
   rspsb2(n, s1, 0);
}

// RSPSB2-- OUTPUT RANDOM MESSAGE WITH UP TO TWO SUBSTITUTABLE ARGUMENTS
// CALLED BY--
// 	CALL RSPSB2(MSGNUM,SUBNUM1,SUBNUM2)
void rspsb2(int n, int s1, int s2) {
// System generated locals
   int i__1;

// Local variables
   int i, j, x, y, z;
   char b1[74], b2[74], b3[74];
   int k1, k2, x1;
   short jrec, oldrec, newrec;

// CONVERT ALL ARGUMENTS FROM DICTIONARY NUMBERS (IF POSITIVE)
// TO ABSOLUTE RECORD NUMBERS.

   x = n;
// 						!SET UP WORK VARIABLES.
   y = s1;
   z = s2;
   if (x > 0) {
      x = rmsg_1.rtext[x - 1];
   }
// 						!IF >0, LOOK UP IN RTEXT.
   if (y > 0) {
      y = rmsg_1.rtext[y - 1];
   }
   if (z > 0) {
      z = rmsg_1.rtext[z - 1];
   }
   x = abs(x);
// 						!TAKE ABS VALUE.
   y = abs(y);
   z = abs(z);
   if (x == 0) {
      return;
   }
// 						!ANYTHING TO DO?
   play_1.telflg = true;
// 						!SAID SOMETHING.

   BegInDU(chan_1.dbch, 0, x);
   DoUio(1, &oldrec, sizeof oldrec);
   DoUio(1, b1, sizeof b1);
   EndInDU();

L100:
   for (i = 1; i <= 74; ++i) {
      x1 = (x & 31) + i;
      b1[i - 1] = (char)(b1[i - 1] ^ x1);
// L150:
   }

L200:
   if (y == 0) {
      goto L400;
   }
// 						!ANY SUBSTITUTABLE?
   for (i = 1; i <= 74; ++i) {
// 						!YES, LOOK FOR #.
      if (b1[i - 1] == '#') {
         goto L1000;
      }
// L300:
   }

L400:
   for (i = 74; i >= 1; --i) {
// 						!BACKSCAN FOR BLANKS.
      if (b1[i - 1] != ' ') {
         goto L600;
      }
// L500:
   }

L600:
   BegExSF(chan_1.outch, /*650*/"(1x,74a1)", 0);
   i__1 = i;
   for (j = 1; j <= i__1; ++j) {
      DoFio(1, b1 + (j - 1), sizeof b1[0]);
   }
   EndExSF();
   ++x;
// 						!ON TO NEXT RECORD.
   BegInDU(chan_1.dbch, 0, x);
   DoUio(1, &newrec, sizeof newrec);
   DoUio(1, b1, sizeof b1);
   EndInDU();
   if (oldrec == newrec) {
      goto L100;
   }
// 						!CONTINUATION?
   return;
// 						!NO, EXIT.

// SUBSTITUTION WITH SUBSTITUTABLE AVAILABLE.
// I IS INDEX OF # IN B1.
// Y IS NUMBER OF RECORD TO SUBSTITUTE.

// PROCEDURE:
//   1) COPY REST OF B1 TO B2
//   2) READ SUBSTITUTABLE OVER B1
//   3) RESTORE TAIL OF ORIGINAL B1

// THE IMPLICIT ASSUMPTION HERE IS THAT THE SUBSTITUTABLE STRING
// IS VERY SHORT (i.e. MUCH LESS THAN ONE RECORD).

L1000:
   k2 = 1;
// 						!TO
   for (k1 = i + 1; k1 <= 74; ++k1) {
// 						!COPY REST OF B1.
      b2[k2 - 1] = b1[k1 - 1];
      ++k2;
// L1100:
   }

//   READ SUBSTITUTE STRING INTO B3, AND DECRYPT IT:

   BegInDU(chan_1.dbch, 0, y);
   DoUio(1, &jrec, sizeof jrec);
   DoUio(1, b3, sizeof b3);
   EndInDU();
   for (k1 = 1; k1 <= 74; ++k1) {
      x1 = (y & 31) + k1;
      b3[k1 - 1] = (char)(b3[k1 - 1] ^ x1);
// L1150:
   }

//   FILL REMAINDER OF B1 WITH CHARACTERS FROM B3:

   k2 = 1;
   for (k1 = i; k1 <= 74; ++k1) {
      b1[k1 - 1] = b3[k2 - 1];
      ++k2;
// L1180:
   }

//   FIND END OF SUBSTITUTE STRING IN B1:

   for (j = 74; j >= 1; --j) {
// 						!ELIM TRAILING BLANKS.
      if (b1[j - 1] != ' ') {
         goto L1300;
      }
// L1200:
   }

//   PUT TAIL END OF B1 (NOW IN B2) BACK INTO B1 AFTER SUBSTITUTE STRING:

L1300:
   k1 = 1;
// 						!FROM
   for (k2 = j + 1; k2 <= 74; ++k2) {
// 						!COPY REST OF B1 BACK.
      b1[k2 - 1] = b2[k1 - 1];
      ++k1;
// L1400:
   }

   y = z;
// 						!SET UP FOR NEXT
   z = 0;
// 						!SUBSTITUTION AND
   goto L200;
// 						!RECHECK LINE.
}

// OBJACT-- APPLY OBJECTS FROM PARSE VECTOR
Bool objact(/*int x*/) {
// System generated locals
   Bool ret_val;

// Local variables

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prsi == 0) {
      goto L100;
   }
// 						!IND OBJECT?
   if (oappli(objcts_1.oactio[prsvec_1.prsi - 1], 0)) {
      return ret_val;
   }
// 						!YES, LET IT HANDLE.

L100:
   if (prsvec_1.prso == 0) {
      goto L200;
   }
// 						!DIR OBJECT?
   if (oappli(objcts_1.oactio[prsvec_1.prso - 1], 0)) {
      return ret_val;
   }
// 						!YES, LET IT HANDLE.

L200:
   ret_val = false;
// 						!LOSES.
   return ret_val;
}

// BUG-- REPORT FATAL SYSTEM ERROR
// CALLED BY--
// 	CALL BUG(NO,PAR)
void bug(int a, int b) {
// Local variables

   BegExSF(6, /*100*/"(\002 PROGRAM ERROR \002,i2,\002, PARAMETER=\002,i6)", 0);
   DoFio(1, &a, sizeof a);
   DoFio(1, &b, sizeof b);
   EndExSF();
   if (debug_1.dbgflg != 0) {
      return;
   }
   exit_();
}

// NEWSTA-- SET NEW STATUS FOR OBJECT
// CALLED BY--
// 	CALL NEWSTA(OBJECT,STRING,NEWROOM,NEWCON,NEWADV)
void newsta(int o, int r, int rm, int cn, int ad) {
// Local variables

   rspeak(r);
   objcts_1.oroom[o - 1] = rm;
   objcts_1.ocan[o - 1] = cn;
   objcts_1.oadv[o - 1] = ad;
}

// QHERE-- TEST FOR OBJECT IN ROOM
Bool qhere(int obj, int rm) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   int i;

   ret_val = true;
   if (objcts_1.oroom[obj - 1] == rm) {
      return ret_val;
   }
// 						!IN ROOM?
   i__1 = oroom2_1.r2lnt;
   for (i = 1; i <= i__1; ++i) {
// 						!NO, SCH ROOM2.
      if (oroom2_1.oroom2[i - 1] == obj && oroom2_1.rroom2[i - 1] == rm) {
         return ret_val;
      }
// L100:
   }
   ret_val = false;
// 						!NOT PRESENT.
   return ret_val;
}

// QEMPTY-- TEST FOR OBJECT EMPTY
Bool qempty(int obj) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   int i;

   ret_val = false;
// 						!ASSUME LOSE.
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
      if (objcts_1.ocan[i - 1] == obj) {
         return ret_val;
      }
// 						!INSIDE TARGET?
// L100:
   }
   ret_val = true;
   return ret_val;
}

// JIGSUP- YOU ARE DEAD
void jigsup(int desc) {
// Initialized data
   static const int rlist[9] = { 8, 6, 36, 35, 34, 4, 34, 6, 5 };

// System generated locals
   int i__1;

// Local variables
   int nonofl;
   Bool f;
   int i, j;

// JIGSUP, PAGE 2

   rspeak(desc);
// 						!DESCRIBE SAD STATE.
   prsvec_1.prscon = 1;
// 						!STOP PARSER.
   if (debug_1.dbgflg != 0) {
      return;
   }
// 						!IF DBG, EXIT.
   advs_1.avehic[play_1.winner - 1] = 0;
// 						!GET RID OF VEHICLE.
   if (play_1.winner == aindex_1.player) {
      goto L100;
   }
// 						!HIMSELF?
   rspsub(432, objcts_1.odesc2[advs_1.aobj[play_1.winner - 1] - 1]);
// 						!NO, SAY WHO DIED.
   newsta(advs_1.aobj[play_1.winner - 1], 0, 0, 0, 0);
// 						!SEND TO HYPER SPACE.
   return;

L100:
   if (findex_1.endgmf) {
      goto L900;
   }
// 						!NO RECOVERY IN END GAME.
   if (state_1.deaths >= 2) {
      goto L1000;
   }
// 						!DEAD TWICE? KICK HIM OFF.
   if (!yesno(10, 9, 8)) {
      goto L1100;
   }
// 						!CONTINUE?

   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!TURN OFF FIGHTING.
      if (qhere(j, play_1.here)) {
         objcts_1.oflag2[j - 1] &= ~FiteO;
      }
// L50:
   }

   ++state_1.deaths;
   scrupd(-10);
// 						!CHARGE TEN POINTS.
   f = moveto(rindex_1.fore1, play_1.winner);
// 						!REPOSITION HIM.
   findex_1.egyptf = true;
// 						!RESTORE COFFIN.
   if (objcts_1.oadv[oindex_1.coffi - 1] == play_1.winner) {
      newsta(oindex_1.coffi, 0, rindex_1.egypt, 0, 0);
   }
   objcts_1.oflag2[oindex_1.door - 1] &= ~TChO;
   objcts_1.oflag1[oindex_1.robot - 1] = (objcts_1.oflag1[oindex_1.robot - 1] | VisiO) & ~NDscO;
   if (objcts_1.oroom[oindex_1.lamp - 1] != 0 || objcts_1.oadv[oindex_1.lamp - 1] == play_1.winner) {
      newsta(oindex_1.lamp, 0, rindex_1.lroom, 0, 0);
   }

// NOW REDISTRIBUTE HIS VALUABLES AND OTHER BELONGINGS.

// THE LAMP HAS BEEN PLACED IN THE LIVING ROOM.
// THE FIRST 8 NON-VALUABLES ARE PLACED IN LOCATIONS AROUND THE HOUSE.
// HIS VALUABLES ARE PLACED AT THE END OF THE MAZE.
// REMAINING NON-VALUABLES ARE PLACED AT THE END OF THE MAZE.

   i = 1;
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!LOOP THRU OBJECTS.
      if (objcts_1.oadv[j - 1] != play_1.winner || objcts_1.otval[j - 1] != 0) {
         goto L200;
      }
      ++i;
      if (i > 9) {
         goto L400;
      }
// 						!MOVE TO RANDOM LOCATIONS.
      newsta(j, 0, rlist[i - 1], 0, 0);
   L200:
      ;
   }

L400:
   i = rooms_1.rlnt + 1;
// 						!NOW MOVE VALUABLES.
   nonofl = AirR + WaterR + SacrdR + EndR;
// 						!DONT MOVE HERE.
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
      if (objcts_1.oadv[j - 1] != play_1.winner || objcts_1.otval[j - 1] == 0) {
         goto L300;
      }
   L250:
      --i;
// 						!FIND NEXT ROOM.
      if ((rooms_1.rflag[i - 1] & nonofl) != 0) {
         goto L250;
      }
      newsta(j, 0, i, 0, 0);
// 						!YES, MOVE.
   L300:
      ;
   }

   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!NOW GET RID OF REMAINDER.
      if (objcts_1.oadv[j - 1] != play_1.winner) {
         goto L500;
      }
   L450:
      --i;
// 						!FIND NEXT ROOM.
      if ((rooms_1.rflag[i - 1] & nonofl) != 0) {
         goto L450;
      }
      newsta(j, 0, i, 0, 0);
   L500:
      ;
   }
   return;

// CAN'T OR WON'T CONTINUE, CLEAN UP AND EXIT.

L900:
   rspeak(625);
// 						!IN ENDGAME, LOSE.
   goto L1100;

L1000:
   rspeak(7);
// 						!INVOLUNTARY EXIT.
L1100:
   score(false);
// 						!TELL SCORE.
   CloseF(chan_1.dbch);
   exit_();
}

// OACTOR-	GET ACTOR ASSOCIATED WITH OBJECT
int oactor(int obj) {
// System generated locals
   int ret_val, i__1;

// Local variables
   int i;

   i__1 = advs_1.alnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP THRU ACTORS.
      ret_val = i;
// 						!ASSUME FOUND.
      if (advs_1.aobj[i - 1] == obj) {
         return ret_val;
      }
// 						!FOUND IT?
// L100:
   }
   bug(40, obj);
// 						!NO, DIE.
   return ret_val;
}

// PROB-		COMPUTE PROBABILITY
Bool prob(int g, int b) {
// System generated locals
   Bool ret_val;

// Local variables
   int i;

   i = g;
// 						!ASSUME GOOD LUCK.
   if (findex_1.badlkf) {
      i = b;
   }
// 						!IF BAD, TOO BAD.
   ret_val = rnd(100) < i;
// 						!COMPUTE.
   return ret_val;
}

// RMDESC-- PRINT ROOM DESCRIPTION
// RMDESC PRINTS A DESCRIPTION OF THE CURRENT ROOM.
// IT IS ALSO THE PROCESSOR FOR VERBS 'LOOK' AND 'EXAMINE'.
Bool rmdesc(int full) {
// System generated locals
   Bool ret_val, L__1;

// Local variables
   int i, ra;

// FULL=	0/1/2/3=	SHORT/OBJ/ROOM/FULL

// RMDESC, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prso < xsrch_1.xmin) {
      goto L50;
   }
// 						!IF DIRECTION,
   screen_1.fromdr = prsvec_1.prso;
// 						!SAVE AND
   prsvec_1.prso = 0;
// 						!CLEAR.
L50:
   if (play_1.here == advs_1.aroom[aindex_1.player - 1]) {
      goto L100;
   }
// 						!PLAYER JUST MOVE?
   rspeak(2);
// 						!NO, JUST SAY DONE.
   prsvec_1.prsa = vindex_1.walkiw;
// 						!SET UP WALK IN ACTION.
   return ret_val;

L100:
   if (lit(play_1.here)) {
      goto L300;
   }
// 						!LIT?
   rspeak(430);
// 						!WARN OF GRUE.
   ret_val = false;
   return ret_val;

L300:
   ra = rooms_1.ractio[play_1.here - 1];
// 						!GET ROOM ACTION.
   if (full == 1) {
      goto L600;
   }
// 						!OBJ ONLY?
   i = rooms_1.rdesc2 - play_1.here;
// 						!ASSUME SHORT DESC.
   if (full == 0 && (findex_1.superf || (rooms_1.rflag[play_1.here - 1] & SeenR) != 0 && (findex_1.brieff || prob(80, 80)))) {
      goto L400;
   }
   i = rooms_1.rdesc1[play_1.here - 1];
// 						!USE LONG.
   if (i != 0 || ra == 0) {
      goto L400;
   }
// 						!IF GOT DESC, SKIP.
   prsvec_1.prsa = vindex_1.lookw;
// 						!PRETEND LOOK AROUND.
   if (!rappli(ra)) {
      goto L100;
   }
// 						!ROOM HANDLES, NEW DESC?
   prsvec_1.prsa = vindex_1.foow;
// 						!NOP PARSER.
   goto L500;

L400:
   rspeak(i);
// 						!OUTPUT DESCRIPTION.
L500:
   if (advs_1.avehic[play_1.winner - 1] != 0) {
      rspsub(431, objcts_1.odesc2[advs_1.avehic[play_1.winner - 1] - 1]);
   }

L600:
   if (full != 2) {
      L__1 = full != 0;
      princr(L__1, play_1.here);
   }
   rooms_1.rflag[play_1.here - 1] |= SeenR;
   if (full != 0 || ra == 0) {
      return ret_val;
   }
// 						!ANYTHING MORE?
   prsvec_1.prsa = vindex_1.walkiw;
// 						!GIVE HIM A SURPISE.
   if (!rappli(ra)) {
      goto L100;
   }
// 						!ROOM HANDLES, NEW DESC?
   prsvec_1.prsa = vindex_1.foow;
   return ret_val;
}

// RAPPLI-	ROUTING ROUTINE FOR ROOM APPLICABLES
Bool rappli(int ri) {
// Initialized data
   const int newrms = 38;

// System generated locals
   Bool ret_val;

   ret_val = true;
// 						!ASSUME WINS.
   if (ri == 0) {
      return ret_val;
   }
// 						!IF ZERO, WIN.
   if (ri < newrms) {
      ret_val = rappl1(ri);
   }
// 						!IF OLD, PROCESSOR 1.
   if (ri >= newrms) {
      ret_val = rappl2(ri);
   }
// 						!IF NEW, PROCESSOR 2.
   return ret_val;
}
