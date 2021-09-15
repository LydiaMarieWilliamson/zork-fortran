#include "F2C.h"

// Common Block Declarations

extern struct {
   int winner, here;
   Bool telflg;
} play_;

#define play_1 play_

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

extern struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

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
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

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
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

extern struct {
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;

#define cevent_1 cevent_

extern struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

// Table of constant values

static int c__427 = 427;
static int c__0 = 0;
static int c__428 = 428;
static int c__1 = 1;

// MOVETO- MOVE PLAYER TO NEW ROOM

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool moveto_(int * nr, int * who) {
// System generated locals
   Bool ret_val;

// Local variables
   static int j;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
   static Bool lhr;
#define eqr ((int *)&rooms_1 + 2)
   static Bool lnr, nlv;
   static int bits;
#define rrand ((int *)&rooms_1 + 602)
   extern Void rspeak_(int *), scrupd_(int *), newsta_(int *, int *, int *, int *, int *), rspsub_(int *, int *);

// GAME STATE

// ROOMS

// OBJECTS

// MOVETO, PAGE 2

// ADVENTURERS

   ret_val = false;
// 						!ASSUME FAILS.
   lhr = (rooms_1.rflag[play_1.here - 1] & rflag_1.rland) != 0;
   lnr = (rooms_1.rflag[*nr - 1] & rflag_1.rland) != 0;
   j = advs_1.avehic[*who - 1];
// 						!HIS VEHICLE

   if (j != 0) {
      goto L100;
   }
// 						!IN VEHICLE?
   if (lnr) {
      goto L500;
   }
// 						!NO, GOING TO LAND?
   rspeak_(&c__427);
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
   nlv = (rooms_1.rflag[*nr - 1] & bits) == 0;
   if (!lnr && nlv || lnr && lhr && nlv && bits != rflag_1.rland) {
      goto L800;
   }

L500:
   ret_val = true;
// 						!MOVE SHOULD SUCCEED.
   if ((rooms_1.rflag[*nr - 1] & rflag_1.rmung) == 0) {
      goto L600;
   }
   rspeak_(&rrand[*nr - 1]);
// 						!YES, TELL HOW.
   return ret_val;

L600:
   if (*who != aindex_1.player) {
      newsta_(&advs_1.aobj[*who - 1], &c__0, nr, &c__0, &c__0);
   }
   if (j != 0) {
      newsta_(&j, &c__0, nr, &c__0, &c__0);
   }
   play_1.here = *nr;
   advs_1.aroom[*who - 1] = play_1.here;
   scrupd_(&rooms_1.rval[*nr - 1]);
// 						!SCORE ROOM
   rooms_1.rval[*nr - 1] = 0;
   return ret_val;

L800:
   rspsub_(&c__428, &objcts_1.odesc2[j - 1]);
// 						!WRONG VEHICLE.
   return ret_val;
}

#undef rrand
#undef eqr
#undef eqo
#undef eqa

// SCORE-- PRINT OUT CURRENT SCORE

// DECLARATIONS

Void score_(Bool * flg) {
// Initialized data

   static int rank[10] = { 20, 19, 18, 16, 12, 8, 4, 2, 1, 0 };
   static int erank[5] = { 20, 15, 10, 5, 0 };

// Format strings
   static char fmt_100[] = "(\002 Your score would be\002,$)";
   static char fmt_110[] = "(\002 Your score is\002,$)";
   static char fmt_120[] = "(i4,\002 [total of\002,i4,\002 points], in\002," "i5,\002 moves.\002)";
   static char fmt_130[] = "(i4,\002 [total of\002,i4,\002 points], in\002," "i5,\002 move.\002)";
   static char fmt_140[] = "(\002 Your score in the endgame would be\002,$)";
   static char fmt_150[] = "(\002 Your score in the endgame is\002,$)";

// System generated locals
   int i__1;

// Local variables
   static int i__, as;
#define eqa ((int *)&advs_1 + 1)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void rspeak_(int *);

// Fortran I/O blocks
   static cilist io___16 = { 0, 0, 0, fmt_100, 0 };
   static cilist io___17 = { 0, 0, 0, fmt_110, 0 };
   static cilist io___18 = { 0, 0, 0, fmt_120, 0 };
   static cilist io___19 = { 0, 0, 0, fmt_130, 0 };
   static cilist io___21 = { 0, 0, 0, fmt_140, 0 };
   static cilist io___22 = { 0, 0, 0, fmt_150, 0 };
   static cilist io___23 = { 0, 0, 0, fmt_120, 0 };

// GAME STATE

// ADVENTURERS

// FUNCTIONS AND DATA

// FLAGS

// SCORE, PAGE 2

   as = advs_1.ascore[(20 + (0 + (play_1.winner - 1 << 2)) - 20) / 4];

   if (findex_1.endgmf) {
      goto L60;
   }
// 						!ENDGAME?
   if (*flg) {
      io___16.ciunit = chan_1.outch;
      s_wsfe(&io___16);
      e_wsfe();
   }
   if (!(*flg)) {
      io___17.ciunit = chan_1.outch;
      s_wsfe(&io___17);
      e_wsfe();
   }
   if (state_1.moves != 1) {
      io___18.ciunit = chan_1.outch;
      s_wsfe(&io___18);
      do_fio(&c__1, (char *)&as, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&state_1.mxscor, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&state_1.moves, (ftnlen) sizeof(int));
      e_wsfe();
   }
   if (state_1.moves == 1) {
      io___19.ciunit = chan_1.outch;
      s_wsfe(&io___19);
      do_fio(&c__1, (char *)&as, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&state_1.mxscor, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&state_1.moves, (ftnlen) sizeof(int));
      e_wsfe();
   }

   for (i__ = 1; i__ <= 10; ++i__) {
      if (as * 20 / state_1.mxscor >= rank[i__ - 1]) {
         goto L50;
      }
// L10:
   }
L50:
   i__1 = i__ + 484;
   rspeak_(&i__1);
   return 0;

L60:
   if (*flg) {
      io___21.ciunit = chan_1.outch;
      s_wsfe(&io___21);
      e_wsfe();
   }
   if (!(*flg)) {
      io___22.ciunit = chan_1.outch;
      s_wsfe(&io___22);
      e_wsfe();
   }
   io___23.ciunit = chan_1.outch;
   s_wsfe(&io___23);
   do_fio(&c__1, (char *)&state_1.egscor, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.egmxsc, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.moves, (ftnlen) sizeof(int));
   e_wsfe();
   for (i__ = 1; i__ <= 5; ++i__) {
      if (state_1.egscor * 20 / state_1.egmxsc >= erank[i__ - 1]) {
         goto L80;
      }
// L70:
   }
L80:
   i__1 = i__ + 786;
   rspeak_(&i__1);
   return 0;

}

#undef switch__
#undef flags
#undef eqa

// SCRUPD- UPDATE WINNER'S SCORE

// DECLARATIONS

Void scrupd_(int * n) {
// Local variables
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// GAME STATE

// CLOCK INTERRUPTS

// ADVENTURERS

// FLAGS

   if (findex_1.endgmf) {
      goto L100;
   }
// 						!ENDGAME?
   advs_1.ascore[play_1.winner - 1] += *n;
// 						!UPDATE SCORE
   state_1.rwscor += *n;
// 						!UPDATE RAW SCORE
   if (advs_1.ascore[play_1.winner - 1] < state_1.mxscor - state_1.deaths * 10) {
      return 0;
   }
   cevent_1.cflag[cindex_1.cevegh - 1] = true;
// 						!TURN ON END GAME
   cevent_1.ctick[cindex_1.cevegh - 1] = 15;
   return 0;

L100:
   state_1.egscor += *n;
// 						!UPDATE EG SCORE.
   return 0;
}

#undef switch__
#undef flags
#undef eqc
#undef eqa
