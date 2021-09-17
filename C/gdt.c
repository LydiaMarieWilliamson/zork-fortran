#include "F2C.h"
#include "parse.h"

// gamestat.h:

// GAME STATE

extern struct {
   int winner, here;
   Bool telflg;
} play_;
#define play_1 play_

// state.h:
extern struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;
#define state_1 state_

// screen.h:

// SCREEN OF LIGHT

extern struct screen_1_ {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;
#define screen_1 screen_

// puzzle.h:

// PUZZLE ROOM STATE

extern struct puzzle_1_ {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;
#define puzzle_1 puzzle_

// star.h: (Unlisted)
extern struct {
   int mbase, strbit;
} star_;
#define star_1 star_

// io.h:

// I/O VARIABLES

extern struct {
   int inlnt;
   char inbuf[78];
} input_;
#define input_1 input_

extern struct {
   int inpch, outch, dbch;
} chan_;
#define chan_1 chan_

// mindex.h:

// MESSAGE INDEX

extern struct {
   int mlnt, rtext[1820];
} rmsg_;
#define rmsg_1 rmsg_

// debug.h:

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;
#define debug_1 debug_

// rooms.h:

// ROOMS

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;
#define rooms_1 rooms_
#define eqr ((int *)&rooms_1 + 2)
#define rrand ((int *)&rooms_1 + 602)

// rindex.h:

extern struct rindex_1_ {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;
#define rindex_1 rindex_

// exits.h:

// EXITS

extern struct {
   int xlnt, travel[900];
} exits_;
#define exits_1 exits_

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

// flags.h:

// FLAGS

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;
#define findex_1 findex_
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// GDT- GAME DEBUGGING TOOL

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

void gdt_(void) {
// Initialized data

   static int cmdmax = 38;
   static char dbgcmd[2 * 38] = "DR" "DO" "DA" "DC" "DX" "DH" "DL" "DV" "DF" "DS" "AF" "HE" "NR" "NT" "NC" "ND" "RR" "RT" "RC" "RD" "TK" "EX" "AR" "AO" "AA" "AC" "AX" "AV" "D2" "DN" "AN" "DM" "DT" "AH" "DP" "PD" "DZ" "AZ";
   static char ldbgcmd[2 * 38] = "dr" "do" "da" "dc" "dx" "dh" "dl" "dv" "df" "ds" "af" "he" "nr" "nt" "nc" "nd" "rr" "rt" "rc" "rd" "tk" "ex" "ar" "ao" "aa" "ac" "ax" "av" "d2" "dn" "an" "dm" "dt" "ah" "dp" "pd" "dz" "az";
   static int argtyp[38] = {
      2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      3, 3, 3, 3, 1, 3, 2, 2, 1, 2, 1, 0, 0, 0, 0, 1
   };

// Format strings
   static char fmt_0[] = "(\002   RANGE   CONTENTS\002)";
   static char fmt_1[] = "(\002 Old=\002,l2,6x,\002New= \002,$)";
   static char fmt_2[] = "(\002 Old= \002,i6,6x,\002New= \002,$)";

// System generated locals
   int i__1, i__2;

// Local variables
   extern void newsta_(int, int, int, int, int);
   extern void rspeak_(int);
   static int i__, j, k, l, l1;
   static char cmd[2];
   static int fmax, smax;

// MISCELLANEOUS VARIABLES

// FUNCTIONS AND DATA

// GDT, PAGE 2

// FIRST, VALIDATE THAT THE CALLER IS AN IMPLEMENTER.

   fmax = 46;
// 						!SET ARRAY LIMITS.
   smax = 22;

   if (debug_1.gdtflg != 0) {
      goto L2000;
   }
// 						!IF OK, SKIP.
   BegExSF(chan_1.outch, /*100*/"(\002 You are not an authorized user.\002)", 0);
   EndExSF();
// 						!NOT AN IMPLEMENTER.
   return;
// 						!BOOT HIM OFF

// GDT, PAGE 2A

// HERE TO GET NEXT COMMAND

L2000:
   BegExSF(chan_1.outch, /*200*/"(\002 GDT>\002,$)", 0);
   EndExSF();
// 						!OUTPUT PROMPT.
   BegInSF(chan_1.inpch, /*210*/"(a2)", 0);
   DoFio(1, cmd, sizeof cmd);
   EndInSF();
// 						!GET COMMAND.
   if (CompS(cmd, "  ", sizeof cmd) == 0) {
      goto L2000;
   }
// 						!IGNORE BLANKS.
   i__1 = cmdmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOK IT UP.
      if (CompS(cmd, dbgcmd + (i__ - 1 << 1), sizeof cmd) == 0) {
         goto L2300;
      }
// 						!FOUND?
// 	  check for lower case command, as well
      if (CompS(cmd, ldbgcmd + (i__ - 1 << 1), sizeof cmd) == 0) {
         goto L2300;
      }
// L2100:
   }
L2200:
   BegExSF(chan_1.outch, /*220*/"(\002 ?\002)", 0);
   EndExSF();
// 						!NO, LOSE.
   goto L2000;

//L230:
//L240:
//L225:
//L235:
//L245:

L2300:
   switch (argtyp[i__ - 1] + 1) {
      case 1:
         goto L2400;
      case 2:
         goto L2500;
      case 3:
         goto L2600;
      case 4:
         goto L2700;
   }
// 						!BRANCH ON ARG TYPE.
   goto L2200;
// 						!ILLEGAL TYPE.

L2700:
   BegExSF(chan_1.outch, /*245*/"(\002 Idx,Ary:  \002,$)", 0);
   EndExSF();
// 						!TYPE 3, REQUEST ARRAY COORDS.
   BegInSF(chan_1.inpch, /*230*/"(2i6)", 0);
   DoFio(1, &j, sizeof j);
   DoFio(1, &k, sizeof k);
   EndInSF();
   goto L2400;

L2600:
   BegExSF(chan_1.outch, /*225*/"(\002 Limits:   \002,$)", 0);
   EndExSF();
// 						!TYPE 2, READ BOUNDS.
   BegInSF(chan_1.inpch, /*230*/"(2i6)", 0);
   DoFio(1, &j, sizeof j);
   DoFio(1, &k, sizeof k);
   EndInSF();
   if (k == 0) {
      k = j;
   }
   goto L2400;

L2500:
   BegExSF(chan_1.outch, /*235*/"(\002 Entry:    \002,$)", 0);
   EndExSF();
// 						!TYPE 1, READ ENTRY NO.
   BegInSF(chan_1.inpch, /*240*/"(i6)", 0);
   DoFio(1, &j, sizeof j);
   EndInSF();
L2400:
   switch (i__) {
      case 1:
         goto L10000;
      case 2:
         goto L11000;
      case 3:
         goto L12000;
      case 4:
         goto L13000;
      case 5:
         goto L14000;
      case 6:
         goto L15000;
      case 7:
         goto L16000;
      case 8:
         goto L17000;
      case 9:
         goto L18000;
      case 10:
         goto L19000;
      case 11:
         goto L20000;
      case 12:
         goto L21000;
      case 13:
         goto L22000;
      case 14:
         goto L23000;
      case 15:
         goto L24000;
      case 16:
         goto L25000;
      case 17:
         goto L26000;
      case 18:
         goto L27000;
      case 19:
         goto L28000;
      case 20:
         goto L29000;
      case 21:
         goto L30000;
      case 22:
         goto L31000;
      case 23:
         goto L32000;
      case 24:
         goto L33000;
      case 25:
         goto L34000;
      case 26:
         goto L35000;
      case 27:
         goto L36000;
      case 28:
         goto L37000;
      case 29:
         goto L38000;
      case 30:
         goto L39000;
      case 31:
         goto L40000;
      case 32:
         goto L41000;
      case 33:
         goto L42000;
      case 34:
         goto L43000;
      case 35:
         goto L44000;
      case 36:
         goto L45000;
      case 37:
         goto L46000;
      case 38:
         goto L47000;
   }
   goto L2200;
// 						!WHAT???
// GDT, PAGE 3

// DR-- DISPLAY ROOMS

L10000:
   if (!(j > 0 && j <= rooms_1.rlnt && (k > 0 && k <= rooms_1.rlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   BegExSF(chan_1.outch, /*300*/"(\002 RM#  DESC1  EXITS ACTION  VALUE  FLAGS\002)", 0);
   EndExSF();
// 						!COL HDRS.
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*310*/"(1x,i3,4(1x,i6),1x,i6)", 0);
      DoFio(1, &i__, sizeof i__);
      for (l = 1; l <= 5; ++l) {
         DoFio(1, &eqr[i__ + l * 200 - 201], sizeof eqr[0]);
      }
      EndExSF();
// L10100:
   }
   goto L2000;

// DO-- DISPLAY OBJECTS

L11000:
   if (!(j > 0 && j <= objcts_1.olnt && (k > 0 && k <= objcts_1.olnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   BegExSF(chan_1.outch, /*320*/"(\002 OB# DESC1 DESC2 DESCO ACT FLAGS1 FLAGS2 FVL TVL  SIZE CAPAC ROOM ADV CON  READ\002)", 0);
   EndExSF();
// 						!COL HDRS
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*330*/"(1x,i3,3i6,i4,2i7,2i4,2i6,1x,3i4,i6)", 0);
      DoFio(1, &i__, sizeof i__);
      for (l = 1; l <= 14; ++l) {
         DoFio(1, &eqo[i__ + l * 220 - 221], sizeof eqo[0]);
      }
      EndExSF();
// L11100:
   }
   goto L2000;

// DA-- DISPLAY ADVENTURERS

L12000:
   if (!(j > 0 && j <= advs_1.alnt && (k > 0 && k <= advs_1.alnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   BegExSF(chan_1.outch, /*340*/"(\002 AD#   ROOM  SCORE  VEHIC OBJECT ACTION  STREN  FLAGS\002)", 0);
   EndExSF();
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*350*/"(1x,i3,6(1x,i6),1x,i6)", 0);
      DoFio(1, &i__, sizeof i__);
      for (l = 1; l <= 7; ++l) {
         DoFio(1, &eqa[i__ + (l << 2) - 5], sizeof eqa[0]);
      }
      EndExSF();
// L12100:
   }
   goto L2000;

// DC-- DISPLAY CLOCK EVENTS

L13000:
   if (!(j > 0 && j <= cevent_1.clnt && (k > 0 && k <= cevent_1.clnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   BegExSF(chan_1.outch, /*360*/"(\002 CL#   TICK ACTION  FLAG\002)", 0);
   EndExSF();
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*370*/"(1x,i3,1x,i6,1x,i6,5x,l1)", 0);
      DoFio(1, &i__, sizeof i__);
      for (l = 1; l <= 2; ++l) {
         DoFio(1, &eqc[i__ + l * 25 - 26], sizeof eqc[0]);
      }
      DoFio(1, &cevent_1.cflag[i__ - 1], sizeof cevent_1.cflag[0]);
      EndExSF();
// L13100:
   }
   goto L2000;

// DX-- DISPLAY EXITS

L14000:
   if (!(j > 0 && j <= exits_1.xlnt && (k > 0 && k <= exits_1.xlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   BegExSF(chan_1.outch, /*380*/fmt_0, 0);
   EndExSF();
// 						!COL HDRS.
   i__1 = k;
   for (i__ = j; i__ <= i__1; i__ += 10) {
// 						!TEN PER LINE.
// Computing MIN
      i__2 = i__ + 9;
      l = min(i__2, k);
// 						!COMPUTE END OF LINE.
      BegExSF(chan_1.outch, /*390*/"(1x,i3,\002-\002,i3,3x,10i7)", 0);
      DoFio(1, &i__, sizeof i__);
      DoFio(1, &l, sizeof l);
      i__2 = l;
      for (l1 = i__; l1 <= i__2; ++l1) {
         DoFio(1, &exits_1.travel[l1 - 1], sizeof exits_1.travel[0]);
      }
      EndExSF();
// L14100:
   }
   goto L2000;

// DH-- DISPLAY HACKS

L15000:
   BegExSF(chan_1.outch, /*400*/"(\002 THFPOS=\002,i6,\002, THFFLG=\002,l2,\002,THFACT=\002,l2/\002 SWDACT=\002,l2,\002, SWDSTA=\002,i2)", 0);
   DoFio(1, &hack_1.thfpos, sizeof hack_1.thfpos);
   DoFio(1, &hack_1.thfflg, sizeof hack_1.thfflg);
   DoFio(1, &hack_1.thfact, sizeof hack_1.thfact);
   DoFio(1, &hack_1.swdact, sizeof hack_1.swdact);
   DoFio(1, &hack_1.swdsta, sizeof hack_1.swdsta);
   EndExSF();
   goto L2000;

// DL-- DISPLAY LENGTHS

L16000:
   BegExSF(chan_1.outch, /*410*/"(\002 R=\002,i6,\002, X=\002,i6,\002, O=\002,i6,\002, C=\002,i6/\002 V=\002,i6,\002, A=\002,i6,\002, M=\002,i6,\002, R2=\002,i5/\002 MBASE=\002,i6,\002, STRBIT=\002,i6)", 0);
   DoFio(1, &rooms_1.rlnt, sizeof rooms_1.rlnt);
   DoFio(1, &exits_1.xlnt, sizeof exits_1.xlnt);
   DoFio(1, &objcts_1.olnt, sizeof objcts_1.olnt);
   DoFio(1, &cevent_1.clnt, sizeof cevent_1.clnt);
   DoFio(1, &vill_1.vlnt, sizeof vill_1.vlnt);
   DoFio(1, &advs_1.alnt, sizeof advs_1.alnt);
   DoFio(1, &rmsg_1.mlnt, sizeof rmsg_1.mlnt);
   DoFio(1, &oroom2_1.r2lnt, sizeof oroom2_1.r2lnt);
   DoFio(1, &star_1.mbase, sizeof star_1.mbase);
   DoFio(1, &star_1.strbit, sizeof star_1.strbit);
   EndExSF();
   goto L2000;

// DV-- DISPLAY VILLAINS

L17000:
   if (!(j > 0 && j <= vill_1.vlnt && (k > 0 && k <= vill_1.vlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   BegExSF(chan_1.outch, /*420*/"(\002 VL# OBJECT   PROB   OPPS   BEST  MELEE\002)", 0);
   EndExSF();
// 						!COL HDRS
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*430*/"(1x,i3,5(1x,i6))", 0);
      DoFio(1, &i__, sizeof i__);
      for (l = 1; l <= 5; ++l) {
         DoFio(1, &eqv[i__ + (l << 2) - 5], sizeof eqv[0]);
      }
      EndExSF();
// L17100:
   }
   goto L2000;

// DF-- DISPLAY FLAGS

L18000:
   if (!(j > 0 && j <= fmax && (k > 0 && k <= fmax) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*440*/"(\002 Flag #\002,i2,\002 = \002,l1)", 0);
      DoFio(1, &i__, sizeof i__);
      DoFio(1, &flags[i__ - 1], sizeof flags[0]);
      EndExSF();
// L18100:
   }
   goto L2000;

// DS-- DISPLAY STATE

L19000:
{
   BegExSF(chan_1.outch, /*450*/"(\002 Parse vector=\002,3(1x,i6),1x,l6,1x,i6)", 0);
   DoFio(1, &prsvec_1.prsa, sizeof prsvec_1.prsa);
   DoFio(1, &prsvec_1.prso, sizeof prsvec_1.prso);
   DoFio(1, &prsvec_1.prsi, sizeof prsvec_1.prsi);
   DoFio(1, &prsvec_1.prswon, sizeof prsvec_1.prswon);
   DoFio(1, &prsvec_1.prscon, sizeof prsvec_1.prscon);
   EndExSF();
   BegExSF(chan_1.outch, /*460*/"(\002 Play vector= \002,2(1x,i6),1x,l6)", 0);
   DoFio(1, &play_1.winner, sizeof play_1.winner);
   DoFio(1, &play_1.here, sizeof play_1.here);
   DoFio(1, &play_1.telflg, sizeof play_1.telflg);
   EndExSF();
   BegExSF(chan_1.outch, /*470*/"(\002 State vector=\002,9(1x,i6)/14x,2(1x,i6))", 0);
   DoFio(1, &state_1.moves, sizeof state_1.moves);
   DoFio(1, &state_1.deaths, sizeof state_1.deaths);
   DoFio(1, &state_1.rwscor, sizeof state_1.rwscor);
   DoFio(1, &state_1.mxscor, sizeof state_1.mxscor);
   DoFio(1, &state_1.mxload, sizeof state_1.mxload);
   DoFio(1, &state_1.ltshft, sizeof state_1.ltshft);
   DoFio(1, &state_1.bloc, sizeof state_1.bloc);
   DoFio(1, &state_1.mungrm, sizeof state_1.mungrm);
   DoFio(1, &state_1.hs, sizeof state_1.hs);
   DoFio(1, &state_1.egscor, sizeof state_1.egscor);
   DoFio(1, &state_1.egmxsc, sizeof state_1.egmxsc);
   EndExSF();
   BegExSF(chan_1.outch, /*475*/"(\002 Scol vector= \002,1x,i6,2(1x,i6))", 0);
   DoFio(1, &screen_1.fromdr, sizeof screen_1.fromdr);
   DoFio(1, &screen_1.scolrm, sizeof screen_1.scolrm);
   DoFio(1, &screen_1.scolac, sizeof screen_1.scolac);
   EndExSF();
}
   goto L2000;

// GDT, PAGE 4

// AF-- ALTER FLAGS

L20000:
   if (!(j > 0 && j <= fmax)) {
      goto L2200;
   }
// 						!ENTRY NO VALID?
{
   BegExSF(chan_1.outch, /*480*/fmt_1, 0);
   DoFio(1, &flags[j - 1], sizeof flags[0]);
   EndExSF();
}
// 						!TYPE OLD, GET NEW.
{
   BegInSF(chan_1.inpch, /*490*/"(l1)", 0);
   DoFio(1, &flags[j - 1], sizeof flags[0]);
   EndInSF();
} 
   goto L2000;

// 21000-- HELP

L21000:
{
   BegExSF(chan_1.outch, /*900*/"(\002 Valid commands are:\002/\002 AA- Alter ADVS\002/\002 AC- Alter CEVENT\002/\002 AF- Alter FINDEX\002/\002 AH- Alter HERE\002/\002 AN- Alter switches\002/\002 AO- Alter OBJCTS\002/\002 AR- Alter ROOMS\002/\002 AV- Alter VILLS\002/\002 AX- Alter EXITS\002/\002 AZ- Alter PUZZLE\002/\002 DA- Display ADVS\002/\002 DC- Display CEVENT\002/\002 DF- Display FINDEX\002/\002 DH- Display HACKS\002/\002 DL- Display lengths\002/\002 DM- Display RTEXT\002/\002 DN- Display switches\002/\002 DO- Display OBJCTS\002/\002 DP- Display parser\002/\002 DR- Display ROOMS\002/\002 DS- Display state\002/\002 DT- Display text\002/\002 DV- Display VILLS\002/\002 DX- Display EXITS\002/\002 DZ- Display PUZZLE\002/\002 D2- Display ROOM2\002/\002 EX- Exit\002/\002 HE- Type this message\002/\002 NC- No cyclops\002/\002 ND- No deaths\002/\002 NR- No robber\002/\002 NT- No troll\002/\002 PD- Program detail\002/\002 RC- Restore cyclops\002/\002 RD- Restore deaths\002/\002 RR- Restore robber\002/\002 RT- Restore troll\002/\002 TK- Take.\002)", 0);
   EndExSF();
}
   goto L2000;

// NR-- NO ROBBER

L22000:
   hack_1.thfflg = false;
// 						!DISABLE ROBBER.
   hack_1.thfact = false;
   newsta_(oindex_1.thief, 0, 0, 0, 0);
// 						!VANISH THIEF.
{
   BegExSF(chan_1.outch, /*500*/"(\002 No robber.\002)", 0);
   EndExSF();
}
   goto L2000;

// NT-- NO TROLL

L23000:
   findex_1.trollf = true;
   newsta_(oindex_1.troll, 0, 0, 0, 0);
{
   BegExSF(chan_1.outch, /*510*/"(\002 No troll.\002)", 0);
   EndExSF();
}
   goto L2000;

// NC-- NO CYCLOPS

L24000:
   findex_1.cyclof = true;
   newsta_(oindex_1.cyclo, 0, 0, 0, 0);
{
   BegExSF(chan_1.outch, /*520*/"(\002 No cyclops.\002)", 0);
   EndExSF();
}
   goto L2000;

// ND-- IMMORTALITY MODE

L25000:
   debug_1.dbgflg = 1;
{
   BegExSF(chan_1.outch, /*530*/"(\002 No deaths.\002)", 0);
   EndExSF();
}
   goto L2000;

// RR-- RESTORE ROBBER

L26000:
   hack_1.thfact = true;
{
   BegExSF(chan_1.outch, /*540*/"(\002 Restored robber.\002)", 0);
   EndExSF();
}
   goto L2000;

// RT-- RESTORE TROLL

L27000:
   findex_1.trollf = false;
   newsta_(oindex_1.troll, 0, rindex_1.mtrol, 0, 0);
{
   BegExSF(chan_1.outch, /*550*/"(\002 Restored troll.\002)", 0);
   EndExSF();
}
   goto L2000;

// RC-- RESTORE CYCLOPS

L28000:
   findex_1.cyclof = false;
   findex_1.magicf = false;
   newsta_(oindex_1.cyclo, 0, rindex_1.mcycl, 0, 0);
{
   BegExSF(chan_1.outch, /*560*/"(\002 Restored cyclops.\002)", 0);
   EndExSF();
}
   goto L2000;

// RD-- MORTAL MODE

L29000:
   debug_1.dbgflg = 0;
{
   BegExSF(chan_1.outch, /*570*/"(\002 Restored deaths.\002)", 0);
   EndExSF();
}
   goto L2000;

// GDT, PAGE 5

// TK-- TAKE

L30000:
   if (!(j > 0 && j <= objcts_1.olnt)) {
      goto L2200;
   }
// 						!VALID OBJECT?
   newsta_(j, 0, 0, 0, play_1.winner);
// 						!YES, TAKE OBJECT.
{
   BegExSF(chan_1.outch, /*580*/"(\002 Taken.\002)", 0);
   EndExSF();
}
// 						!TELL.
   goto L2000;

// EX-- GOODBYE

L31000:
   prsvec_1.prscon = 1;
   return;

// AR--	ALTER ROOM ENTRY

L32000:
   if (!(j > 0 && j <= rooms_1.rlnt && (k > 0 && k <= 5))) {
      goto L2200;
   }
// 						!INDICES VALID?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &eqr[j + k * 200 - 201], sizeof eqr[0]);
   EndExSF();
}
// 						!TYPE OLD, GET NEW.
{
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &eqr[j + k * 200 - 201], sizeof eqr[0]);
   EndInSF();
}
   goto L2000;

// AO-- ALTER OBJECT ENTRY

L33000:
   if (!(j > 0 && j <= objcts_1.olnt && (k > 0 && k <= 14))) {
      goto L2200;
   }
// 						!INDICES VALID?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &eqo[j + k * 220 - 221], sizeof eqo[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &eqo[j + k * 220 - 221], sizeof eqo[0]);
   EndInSF();
}
   goto L2000;

// AA-- ALTER ADVS ENTRY

L34000:
   if (!(j > 0 && j <= advs_1.alnt && (k > 0 && k <= 7))) {
      goto L2200;
   }
// 						!INDICES VALID?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &eqa[j + (k << 2) - 5], sizeof eqa[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &eqa[j + (k << 2) - 5], sizeof eqa[0]);
   EndInSF();
}
   goto L2000;

// AC-- ALTER CLOCK EVENTS

L35000:
   if (!(j > 0 && j <= cevent_1.clnt && (k > 0 && k <= 3))) {
      goto L2200;
   }
// 						!INDICES VALID?
   if (k == 3) {
      goto L35500;
   }
// 						!FLAGS ENTRY?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &eqc[j + k * 25 - 26], sizeof eqc[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &eqc[j + k * 25 - 26], sizeof eqc[0]);
   EndInSF();
}
   goto L2000;

L35500:
{
   BegExSF(chan_1.outch, /*480*/fmt_1, 0);
   DoFio(1, &cevent_1.cflag[j - 1], sizeof cevent_1.cflag[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*490*/"(l1)", 0);
   DoFio(1, &cevent_1.cflag[j - 1], sizeof cevent_1.cflag[0]);
   EndInSF();
}
   goto L2000;
// GDT, PAGE 6

// AX-- ALTER EXITS

L36000:
   if (!(j > 0 && j <= exits_1.xlnt)) {
      goto L2200;
   }
// 						!ENTRY NO VALID?
{
   BegExSF(chan_1.outch, /*610*/fmt_2, 0);
   DoFio(1, &exits_1.travel[j - 1], sizeof exits_1.travel[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*620*/"(i6)", 0);
   DoFio(1, &exits_1.travel[j - 1], sizeof exits_1.travel[0]);
   EndInSF();
}
   goto L2000;

// AV-- ALTER VILLAINS

L37000:
   if (!(j > 0 && j <= vill_1.vlnt && (k > 0 && k <= 5))) {
      goto L2200;
   }
// 						!INDICES VALID?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &eqv[j + (k << 2) - 5], sizeof eqv[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &eqv[j + (k << 2) - 5], sizeof eqv[0]);
   EndInSF();
}
   goto L2000;

// D2-- DISPLAY ROOM2 LIST

L38000:
   if (!(j > 0 && j <= oroom2_1.r2lnt && (k > 0 && k <= oroom2_1.r2lnt) && j <= k)) {
      goto L2200;
   }
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*630*/"(\002 #\002,i2,\002   Room=\002,i6,\002   Obj=\002,i6)", 0);
      DoFio(1, &i__, sizeof i__);
      DoFio(1, &oroom2_1.rroom2[i__ - 1], sizeof oroom2_1.rroom2[0]);
      DoFio(1, &oroom2_1.oroom2[i__ - 1], sizeof oroom2_1.oroom2[0]);
      EndExSF();
// L38100:
   }
   goto L2000;

// DN-- DISPLAY SWITCHES

L39000:
   if (!(j > 0 && j <= smax && (k > 0 && k <= smax) && j <= k)) {
      goto L2200;
   }
// 						!VALID?
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      BegExSF(chan_1.outch, /*640*/"(\002 Switch #\002,i2,\002 = \002,i6)", 0);
      DoFio(1, &i__, sizeof i__);
      DoFio(1, &switch__[i__ - 1], sizeof switch__[0]);
      EndExSF();
// L39100:
   }
   goto L2000;

// AN-- ALTER SWITCHES

L40000:
   if (!(j > 0 && j <= smax)) {
      goto L2200;
   }
// 						!VALID ENTRY?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &switch__[j - 1], sizeof switch__[0]);
   EndExSF();
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &switch__[j - 1], sizeof switch__[0]);
   EndInSF();
}
   goto L2000;

// DM-- DISPLAY MESSAGES

L41000:
   if (!(j > 0 && j <= rmsg_1.mlnt && (k > 0 && k <= rmsg_1.mlnt) && j <= k)) {
      goto L2200;
   }
// 						!VALID LIMITS?
{
   BegExSF(chan_1.outch, /*380*/fmt_0, 0);
   EndExSF();
}
   i__1 = k;
   for (i__ = j; i__ <= i__1; i__ += 10) {
// Computing MIN
      i__2 = i__ + 9;
      l = min(i__2, k);
      BegExSF(chan_1.outch, /*650*/"(1x,i3,\002-\002,i3,3x,10(1x,i6))", 0);
      DoFio(1, &i__, sizeof i__);
      DoFio(1, &l, sizeof l);
      i__2 = l;
      for (l1 = i__; l1 <= i__2; ++l1) {
         DoFio(1, &rmsg_1.rtext[l1 - 1], sizeof rmsg_1.rtext[0]);
      }
      EndExSF();
// L41100:
   }
   goto L2000;

// DT-- DISPLAY TEXT

L42000:
   rspeak_(j);
   goto L2000;

// AH--	ALTER HERE

L43000:
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &play_1.here, sizeof play_1.here);
   EndExSF();
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &play_1.here, sizeof play_1.here);
   EndInSF();
}
   eqa[0] = play_1.here;
   goto L2000;

// DP--	DISPLAY PARSER STATE

L44000:
{
   BegExSF(chan_1.outch, /*660*/"(\002 ORPHS= \002,i7,i7,4i7/\002 PV=    \002,i7,4i7/\002 SYN=   \002,6i7/15x,5i7)", 0);
   DoFio(5, orp, sizeof orp[0]);
   DoFio(1, &last_1.lastit, sizeof last_1.lastit);
   DoFio(5, pvec, sizeof pvec[0]);
   DoFio(11, syn, sizeof syn[0]);
   EndExSF();
}
   goto L2000;

// PD--	PROGRAM DETAIL DEBUG

L45000:
{
   BegExSF(chan_1.outch, /*610*/fmt_2, 0);
   DoFio(1, &debug_1.prsflg, sizeof debug_1.prsflg);
   EndExSF();
}
// 						!TYPE OLD, GET NEW.
{
   BegInSF(chan_1.inpch, /*620*/"(i6)", 0);
   DoFio(1, &debug_1.prsflg, sizeof debug_1.prsflg);
   EndInSF();
}
   goto L2000;

// DZ--	DISPLAY PUZZLE ROOM

L46000:
   for (i__ = 1; i__ <= 64; i__ += 8) {
// 						!DISPLAY PUZZLE
      BegExSF(chan_1.outch, /*670*/"(2x,8i3)", 0);
      i__1 = i__ + 7;
      for (j = i__; j <= i__1; ++j) {
         DoFio(1, &puzzle_1.cpvec[j - 1], sizeof puzzle_1.cpvec[0]);
      }
      EndExSF();
// L46100:
   }
   goto L2000;

// AZ--	ALTER PUZZLE ROOM

L47000:
   if (!(j > 0 && j <= 64)) {
      goto L2200;
   }
// 						!VALID ENTRY?
{
   BegExSF(chan_1.outch, /*590*/fmt_2, 0);
   DoFio(1, &puzzle_1.cpvec[j - 1], sizeof puzzle_1.cpvec[0]);
   EndExSF();
}
// 						!OUTPUT OLD,
{
   BegInSF(chan_1.inpch, /*600*/"(i6)", 0);
   DoFio(1, &puzzle_1.cpvec[j - 1], sizeof puzzle_1.cpvec[0]);
   EndInSF();
}
   goto L2000;

}
