// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

// Move player to new room
Bool moveto(int nr, int who) {
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
   lhr = (rooms.rflag[play.here - 1] & LandR) != 0;
   lnr = (rooms.rflag[nr - 1] & LandR) != 0;
   j = advs.avehic[who - 1];
// 						!HIS VEHICLE

   if (j != 0) {
      goto L100;
   }
// 						!IN VEHICLE?
   if (lnr) {
      goto L500;
   }
// 						!NO, GOING TO LAND?
   rspeak(427);
// 						!CAN'T GO WITHOUT VEHICLE.
   return ret_val;

L100:
   bits = 0;
// 						!ASSUME NOWHERE.
   if (j == RBoatOX) {
      bits = WaterR;
   }
// 						!IN BOAT?
   if (j == BalloOX) {
      bits = AirR;
   }
// 						!IN BALLOON?
   if (j == BuckeOX) {
      bits = BuckR;
   }
// 						!IN BUCKET?
   nlv = (rooms.rflag[nr - 1] & bits) == 0;
   if (!lnr && nlv || lnr && lhr && nlv && bits != LandR) {
      goto L800;
   }

L500:
   ret_val = true;
// 						!MOVE SHOULD SUCCEED.
   if ((rooms.rflag[nr - 1] & MungR) == 0) {
      goto L600;
   }
   rspeak(rrand[nr - 1]);
// 						!YES, TELL HOW.
   return ret_val;

L600:
   if (who != PlayerAX) {
      newsta(advs.aobj[who - 1], 0, nr, 0, 0);
   }
   if (j != 0) {
      newsta(j, 0, nr, 0, 0);
   }
   play.here = nr;
   advs.aroom[who - 1] = play.here;
   scrupd(rooms.rval[nr - 1]);
// 						!SCORE ROOM
   rooms.rval[nr - 1] = 0;
   return ret_val;

L800:
   rspsub(428, objcts.odesc2[j - 1]);
// 						!WRONG VEHICLE.
   return ret_val;
}

// Print out current score
void score(Bool flg) {
// Initialized data
   static const int rank[10] = { 20, 19, 18, 16, 12, 8, 4, 2, 1, 0 };
   static const int erank[5] = { 20, 15, 10, 5, 0 };

// System generated locals
   int i__1;

// Local variables
   int i, as;

// SCORE, PAGE 2

   as = advs.ascore[(play.winner - 1 << 2) / 4];

   if (findex.endgmf) {
      goto L60;
   }
// 						!ENDGAME?
// if (flg) //F
//    write(outch, " Your score would be%$"); //F
// else //F
//    write(outch, " Your score is%$"); //F
   if (flg)
      BegExSF(outch, "(\2 Your score would be\2,$)");
   else
      BegExSF(outch, "(\2 Your score is\2,$)");
   EndExSF();
// if (state.moves != 1) //F
//    write(outch, "%I4 [total of%I4 points], in%I5 moves."); //F
// else //F
//    write(outch, "%I4 [total of%I4 points], in%I5 move."); //F
   if (state.moves != 1)
      BegExSF(outch, "(i4,\2 [total of\2,i4,\2 points], in\2,i5,\2 moves.\2)");
   else
      BegExSF(outch, "(i4,\2 [total of\2,i4,\2 points], in\2,i5,\2 move.\2)");
   DoFio(1, &as, sizeof as), DoFio(1, &state.mxscor, sizeof state.mxscor), DoFio(1, &state.moves, sizeof state.moves);
   EndExSF();

   for (i = 1; i <= 10; ++i) {
      if (as * 20 / state.mxscor >= rank[i - 1]) {
         goto L50;
      }
// L10:
   }
L50:
   i__1 = i + 484;
   rspeak(i__1);
   return;

L60:
// if (flg) //F
//    write(outch, " Your score in the endgame would be%$"); //F
// else //F
//    write(outch, " Your score in the endgame is%$"); //F
   if (flg)
      BegExSF(outch, "(\2 Your score in the endgame would be\2,$)"), EndExSF();
   else
      BegExSF(outch, "(\2 Your score in the endgame is\2,$)"), EndExSF();
// write(outch, "%I4 [total of%I4 points], in%I5 moves.", //F
//    state.egscor, state.egmxsc, state.moves //F
// ); //F
   BegExSF(outch, "(i4,\2 [total of\2,i4,\2 points], in\2,i5,\2 moves.\2)");
   DoFio(1, &state.egscor, sizeof state.egscor), DoFio(1, &state.egmxsc, sizeof state.egmxsc);
   DoFio(1, &state.moves, sizeof state.moves);
   EndExSF();
   for (i = 1; i <= 5; ++i) {
      if (state.egscor * 20 / state.egmxsc >= erank[i - 1]) {
         goto L80;
      }
// L70:
   }
L80:
   i__1 = i + 786;
   rspeak(i__1);
}

// Update winner's score
void scrupd(int n) {
   if (findex.endgmf) {
      goto L100;
   }
// 						!ENDGAME?
   advs.ascore[play.winner - 1] += n;
// 						!UPDATE SCORE
   state.rwscor += n;
// 						!UPDATE RAW SCORE
   if (advs.ascore[play.winner - 1] < state.mxscor - state.deaths * 10) {
      return;
   }
   cevent.cflag[EghCX - 1] = true;
// 						!TURN ON END GAME
   cevent.ctick[EghCX - 1] = 15;
   return;

L100:
   state.egscor += n;
// 						!UPDATE EG SCORE.
}
