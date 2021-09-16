#include "F2C.h"

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

extern struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;
#define rflag_1 rflag_

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

// oindex.h:

extern struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;
#define oindex_1 oindex_

// advers.h:

// ADVENTURERS

extern struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;
#define advs_1 advs_
#define eqa ((int *)&advs_1 + 1)

extern struct {
   int astag;
} aflags_;
#define aflags_1 aflags_

extern struct {
   int player, arobot, amastr;
} aindex_;
#define aindex_1 aindex_

// state.h:
extern struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;
#define state_1 state_

// io.h: (Unlisted)

extern struct {
   int inpch, outch, dbch;
} chan_;
#define chan_1 chan_

// flags.h:

// FLAGS

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;
#define findex_1 findex_
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// clock.h:

// CLOCK INTERRUPTS

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;
#define cevent_1 cevent_
#define eqc ((int *)&cevent_1 + 1)

extern struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;
#define cindex_1 cindex_

// MOVETO- MOVE PLAYER TO NEW ROOM

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool moveto_(int nr, int who) {
// System generated locals
   Bool ret_val;

// Local variables
   static int j;
   static Bool lhr;
   static Bool lnr, nlv;
   static int bits;
   extern void rspeak_(int);
   extern void scrupd_(int);
   extern void newsta_(int, int, int, int, int);
   extern void rspsub_(int, int);

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

   static int rank[10] = { 20, 19, 18, 16, 12, 8, 4, 2, 1, 0 };
   static int erank[5] = { 20, 15, 10, 5, 0 };

// System generated locals
   int i__1;

// Local variables
   static int i__, as;
   extern void rspeak_(int);

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

   for (i__ = 1; i__ <= 10; ++i__) {
      if (as * 20 / state_1.mxscor >= rank[i__ - 1]) {
         goto L50;
      }
// L10:
   }
L50:
   i__1 = i__ + 484;
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
   for (i__ = 1; i__ <= 5; ++i__) {
      if (state_1.egscor * 20 / state_1.egmxsc >= erank[i__ - 1]) {
         goto L80;
      }
// L70:
   }
L80:
   i__1 = i__ + 786;
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
