#include "F2C.h"
#include "common.h"
#include "extern.h"

// MOVETO- MOVE PLAYER TO NEW ROOM

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool moveto_(int nr, int who) {
// System generated locals
   Bool ret_val;

// Local variables
   int j;
   Bool lhr;
   Bool lnr, nlv;
   int bits;

// MOVETO, PAGE 2

   ret_val = false;
// 						!ASSUME FAILS.
   lhr = (rooms_1.rflag[play_1.here - 1] & rflag_1.rland) != 0;
   lnr = (rooms_1.rflag[nr - 1] & rflag_1.rland) != 0;
   j = advs_1.avehic[who - 1];
// 						!HIS VEHICLE

   if (j != 0) {
      goto L100;
   }
// 						!IN VEHICLE?
   if (lnr) {
      goto L500;
   }
// 						!NO, GOING TO LAND?
   rspeak_(427);
// 						!CAN'T GO WITHOUT VEHICLE.
   return ret_val;

L100:
   bits = 0;
// 						!ASSUME NOWHERE.
   if (j == oindex_1.rboat) {
      bits = rflag_1.rwater;
   }
// 						!IN BOAT?
   if (j == oindex_1.ballo) {
      bits = rflag_1.rair;
   }
// 						!IN BALLOON?
   if (j == oindex_1.bucke) {
      bits = rflag_1.rbuck;
   }
// 						!IN BUCKET?
   nlv = (rooms_1.rflag[nr - 1] & bits) == 0;
   if (!lnr && nlv || lnr && lhr && nlv && bits != rflag_1.rland) {
      goto L800;
   }

L500:
   ret_val = true;
// 						!MOVE SHOULD SUCCEED.
   if ((rooms_1.rflag[nr - 1] & rflag_1.rmung) == 0) {
      goto L600;
   }
   rspeak_(rrand[nr - 1]);
// 						!YES, TELL HOW.
   return ret_val;

L600:
   if (who != aindex_1.player) {
      newsta_(advs_1.aobj[who - 1], 0, nr, 0, 0);
   }
   if (j != 0) {
      newsta_(j, 0, nr, 0, 0);
   }
   play_1.here = nr;
   advs_1.aroom[who - 1] = play_1.here;
   scrupd_(rooms_1.rval[nr - 1]);
// 						!SCORE ROOM
   rooms_1.rval[nr - 1] = 0;
   return ret_val;

L800:
   rspsub_(428, objcts_1.odesc2[j - 1]);
// 						!WRONG VEHICLE.
   return ret_val;
}

// SCORE-- PRINT OUT CURRENT SCORE

// DECLARATIONS

void score_(Bool flg) {
// Initialized data

   static const int rank[10] = { 20, 19, 18, 16, 12, 8, 4, 2, 1, 0 };
   static const int erank[5] = { 20, 15, 10, 5, 0 };

// System generated locals
   int i__1;

// Local variables
   int i, as;

// FUNCTIONS AND DATA

// SCORE, PAGE 2

   as = advs_1.ascore[(20 + (0 + (play_1.winner - 1 << 2)) - 20) / 4];

   if (findex_1.endgmf) {
      goto L60;
   }
// 						!ENDGAME?
   if (flg) {
      BegExSF(chan_1.outch, /*100*/"(\002 Your score would be\002,$)", 0);
      EndExSF();
   }
   if (!(flg)) {
      BegExSF(chan_1.outch, /*110*/"(\002 Your score is\002,$)", 0);
      EndExSF();
   }
   if (state_1.moves != 1) {
      BegExSF(chan_1.outch, /*120*/"(i4,\002 [total of\002,i4,\002 points], in\002,i5,\002 moves.\002)", 0);
      DoFio(1, &as, sizeof as);
      DoFio(1, &state_1.mxscor, sizeof state_1.mxscor);
      DoFio(1, &state_1.moves, sizeof state_1.moves);
      EndExSF();
   }
   if (state_1.moves == 1) {
      BegExSF(chan_1.outch, /*130*/"(i4,\002 [total of\002,i4,\002 points], in\002,i5,\002 move.\002)", 0);
      DoFio(1, &as, sizeof as);
      DoFio(1, &state_1.mxscor, sizeof state_1.mxscor);
      DoFio(1, &state_1.moves, sizeof state_1.moves);
      EndExSF();
   }

   for (i = 1; i <= 10; ++i) {
      if (as * 20 / state_1.mxscor >= rank[i - 1]) {
         goto L50;
      }
// L10:
   }
L50:
   i__1 = i + 484;
   rspeak_(i__1);
   return;

L60:
   if (flg) {
      BegExSF(chan_1.outch, /*140*/"(\002 Your score in the endgame would be\002,$)", 0);
      EndExSF();
   }
   if (!(flg)) {
      BegExSF(chan_1.outch, /*150*/"(\002 Your score in the endgame is\002,$)", 0);
      EndExSF();
   }
   BegExSF(chan_1.outch, /*120*/"(i4,\002 [total of\002,i4,\002 points], in\002,i5,\002 moves.\002)", 0);
   DoFio(1, &state_1.egscor, sizeof state_1.egscor);
   DoFio(1, &state_1.egmxsc, sizeof state_1.egmxsc);
   DoFio(1, &state_1.moves, sizeof state_1.moves);
   EndExSF();
   for (i = 1; i <= 5; ++i) {
      if (state_1.egscor * 20 / state_1.egmxsc >= erank[i - 1]) {
         goto L80;
      }
// L70:
   }
L80:
   i__1 = i + 786;
   rspeak_(i__1);
}

// SCRUPD- UPDATE WINNER'S SCORE

// DECLARATIONS

void scrupd_(int n) {
// Local variables

   if (findex_1.endgmf) {
      goto L100;
   }
// 						!ENDGAME?
   advs_1.ascore[play_1.winner - 1] += n;
// 						!UPDATE SCORE
   state_1.rwscor += n;
// 						!UPDATE RAW SCORE
   if (advs_1.ascore[play_1.winner - 1] < state_1.mxscor - state_1.deaths * 10) {
      return;
   }
   cevent_1.cflag[cindex_1.cevegh - 1] = true;
// 						!TURN ON END GAME
   cevent_1.ctick[cindex_1.cevegh - 1] = 15;
   return;

L100:
   state_1.egscor += n;
// 						!UPDATE EG SCORE.
}
