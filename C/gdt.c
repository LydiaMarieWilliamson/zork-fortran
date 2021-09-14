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
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;

#define puzzle_1 puzzle_

struct {
   int mbase, strbit;
} star_;

#define star_1 star_

struct {
   int inlnt;
   char inbuf[78];
} input_;

#define input_1 input_

struct {
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

struct {
   int mlnt, rtext[1820];
} rmsg_;

#define rmsg_1 rmsg_

struct {
   int dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

struct {
   int xlnt, travel[900];
} exits_;

#define exits_1 exits_

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
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// Table of constant values

static int c__1 = 1;
static int c__0 = 0;
static int c__5 = 5;
static int c__14 = 14;
static int c__7 = 7;
static int c__3 = 3;
static int c__11 = 11;
static int c__64 = 64;

// GDT- GAME DEBUGGING TOOL

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Void gdt_(void) {
// Initialized data

   static int cmdmax = 38;
   static char dbgcmd[2 * 38] = "DR" "DO" "DA" "DC" "DX" "DH" "DL" "DV" "DF" "DS" "AF" "HE" "NR" "NT" "NC" "ND" "RR" "RT" "RC" "RD" "TK" "EX" "AR" "AO" "AA" "AC" "AX" "AV" "D2" "DN" "AN" "DM" "DT" "AH" "DP" "PD" "DZ" "AZ";
   static char ldbgcmd[2 * 38] = "dr" "do" "da" "dc" "dx" "dh" "dl" "dv" "df" "ds" "af" "he" "nr" "nt" "nc" "nd" "rr" "rt" "rc" "rd" "tk" "ex" "ar" "ao" "aa" "ac" "ax" "av" "d2" "dn" "an" "dm" "dt" "ah" "dp" "pd" "dz" "az";
   static int argtyp[38] = {
      2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      3, 3, 3, 3, 1, 3, 2, 2, 1, 2, 1, 0, 0, 0, 0, 1
   };

// Format strings
   static char fmt_100[] = "(\002 You are not an authorized user.\002)";
   static char fmt_200[] = "(\002 GDT>\002,$)";
   static char fmt_210[] = "(a2)";
   static char fmt_220[] = "(\002 ?\002)";
   static char fmt_230[] = "(2i6)";
   static char fmt_240[] = "(i6)";
   static char fmt_225[] = "(\002 Limits:   \002,$)";
   static char fmt_235[] = "(\002 Entry:    \002,$)";
   static char fmt_245[] = "(\002 Idx,Ary:  \002,$)";
   static char fmt_300[] = "(\002 RM#  DESC1  EXITS ACTION  VALUE  FLAGS" "\002)";
   static char fmt_310[] = "(1x,i3,4(1x,i6),1x,i6)";
   static char fmt_320[] = "(\002 OB# DESC1 DESC2 DESCO ACT FLAGS1 FLAGS2 F" "VL TVL  SIZE CAPAC ROOM ADV CON  READ\002)";
   static char fmt_330[] = "(1x,i3,3i6,i4,2i7,2i4,2i6,1x,3i4,i6)";
   static char fmt_340[] = "(\002 AD#   ROOM  SCORE  VEHIC OBJECT ACTION  S" "TREN  FLAGS\002)";
   static char fmt_350[] = "(1x,i3,6(1x,i6),1x,i6)";
   static char fmt_360[] = "(\002 CL#   TICK ACTION  FLAG\002)";
   static char fmt_370[] = "(1x,i3,1x,i6,1x,i6,5x,l1)";
   static char fmt_380[] = "(\002   RANGE   CONTENTS\002)";
   static char fmt_390[] = "(1x,i3,\002-\002,i3,3x,10i7)";
   static char fmt_400[] = "(\002 THFPOS=\002,i6,\002, THFFLG=\002,l2,\002," "THFACT=\002,l2/\002 SWDACT=\002,l2,\002, SWDSTA=\002,i2)";
   static char fmt_410[] = "(\002 R=\002,i6,\002, X=\002,i6,\002, O=\002," "i6,\002, C=\002,i6/\002 V=\002,i6,\002, A=\002,i6,\002, M=\002,i" "6,\002, R2=\002,i5/\002 MBASE=\002,i6,\002, STRBIT=\002,i6)";
   static char fmt_420[] = "(\002 VL# OBJECT   PROB   OPPS   BEST  MELEE" "\002)";
   static char fmt_430[] = "(1x,i3,5(1x,i6))";
   static char fmt_440[] = "(\002 Flag #\002,i2,\002 = \002,l1)";
   static char fmt_450[] = "(\002 Parse vector=\002,3(1x,i6),1x,l6,1x,i6)";
   static char fmt_460[] = "(\002 Play vector= \002,2(1x,i6),1x,l6)";
   static char fmt_470[] = "(\002 State vector=\002,9(1x,i6)/14x,2(1x,i6))";
   static char fmt_475[] = "(\002 Scol vector= \002,1x,i6,2(1x,i6))";
   static char fmt_480[] = "(\002 Old=\002,l2,6x,\002New= \002,$)";
   static char fmt_490[] = "(l1)";
   static char fmt_900[] =
      "(\002 Valid commands are:\002/\002 AA- Alter AD" "VS\002/\002 AC- Alter CEVENT\002/\002 AF- Alter FINDEX\002/\002 " "AH- Alter HERE\002/\002 AN- Alter switches\002/\002 AO- Alter OB" "JCTS\002/\002 AR- Alter ROOMS\002/\002 AV- Alter VILLS\002/\002 "
      "AX- Alter EXITS\002/\002 AZ- Alter PUZZLE\002/\002 DA- Display A" "DVS\002/\002 DC- Display CEVENT\002/\002 DF- Display FINDEX\002" "/\002 DH- Display HACKS\002/\002 DL- Display lengths\002/\002 DM"
      "- Display RTEXT\002/\002 DN- Display switches\002/\002 DO- Displ" "ay OBJCTS\002/\002 DP- Display parser\002/\002 DR- Display ROOM" "S\002/\002 DS- Display state\002/\002 DT- Display text\002/\002 "
      "DV- Display VILLS\002/\002 DX- Display EXITS\002/\002 DZ- Displa" "y PUZZLE\002/\002 D2- Display ROOM2\002/\002 EX- Exit\002/\002 H" "E- Type this message\002/\002 NC- No cyclops\002/\002 ND- No dea"
      "ths\002/\002 NR- No robber\002/\002 NT- No troll\002/\002 PD- Pr" "ogram detail\002/\002 RC- Restore cyclops\002/\002 RD- Restore d" "eaths\002/\002 RR- Restore robber\002/\002 RT- Restore troll\002/" "\002 TK- Take.\002)";
   static char fmt_500[] = "(\002 No robber.\002)";
   static char fmt_510[] = "(\002 No troll.\002)";
   static char fmt_520[] = "(\002 No cyclops.\002)";
   static char fmt_530[] = "(\002 No deaths.\002)";
   static char fmt_540[] = "(\002 Restored robber.\002)";
   static char fmt_550[] = "(\002 Restored troll.\002)";
   static char fmt_560[] = "(\002 Restored cyclops.\002)";
   static char fmt_570[] = "(\002 Restored deaths.\002)";
   static char fmt_580[] = "(\002 Taken.\002)";
   static char fmt_590[] = "(\002 Old= \002,i6,6x,\002New= \002,$)";
   static char fmt_600[] = "(i6)";
   static char fmt_610[] = "(\002 Old= \002,i6,6x,\002New= \002,$)";
   static char fmt_620[] = "(i6)";
   static char fmt_630[] = "(\002 #\002,i2,\002   Room=\002,i6,\002   Obj" "=\002,i6)";
   static char fmt_640[] = "(\002 Switch #\002,i2,\002 = \002,i6)";
   static char fmt_650[] = "(1x,i3,\002-\002,i3,3x,10(1x,i6))";
   static char fmt_660[] = "(\002 ORPHS= \002,i7,i7,4i7/\002 PV=    \002,i7" ",4i7/\002 SYN=   \002,6i7/15x,5i7)";
   static char fmt_670[] = "(2x,8i3)";

// System generated locals
   int i__1, i__2;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void newsta_(int *, int *, int *, int *, int *), rspeak_(int *);
   static int i__, j, k, l, l1;
   static char cmd[2];
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   static int fmax, smax;
#define rrand ((int *)&rooms_1 + 602)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// Fortran I/O blocks
   static cilist io___20 = { 0, 0, 0, fmt_100, 0 };
   static cilist io___21 = { 0, 0, 0, fmt_200, 0 };
   static cilist io___22 = { 0, 0, 0, fmt_210, 0 };
   static cilist io___25 = { 0, 0, 0, fmt_220, 0 };
   static cilist io___26 = { 0, 0, 0, fmt_245, 0 };
   static cilist io___27 = { 0, 0, 0, fmt_230, 0 };
   static cilist io___30 = { 0, 0, 0, fmt_225, 0 };
   static cilist io___31 = { 0, 0, 0, fmt_230, 0 };
   static cilist io___32 = { 0, 0, 0, fmt_235, 0 };
   static cilist io___33 = { 0, 0, 0, fmt_240, 0 };
   static cilist io___34 = { 0, 0, 0, fmt_300, 0 };
   static cilist io___35 = { 0, 0, 0, fmt_310, 0 };
   static cilist io___37 = { 0, 0, 0, fmt_320, 0 };
   static cilist io___38 = { 0, 0, 0, fmt_330, 0 };
   static cilist io___39 = { 0, 0, 0, fmt_340, 0 };
   static cilist io___40 = { 0, 0, 0, fmt_350, 0 };
   static cilist io___41 = { 0, 0, 0, fmt_360, 0 };
   static cilist io___42 = { 0, 0, 0, fmt_370, 0 };
   static cilist io___43 = { 0, 0, 0, fmt_380, 0 };
   static cilist io___44 = { 0, 0, 0, fmt_390, 0 };
   static cilist io___46 = { 0, 0, 0, fmt_400, 0 };
   static cilist io___47 = { 0, 0, 0, fmt_410, 0 };
   static cilist io___48 = { 0, 0, 0, fmt_420, 0 };
   static cilist io___49 = { 0, 0, 0, fmt_430, 0 };
   static cilist io___50 = { 0, 0, 0, fmt_440, 0 };
   static cilist io___51 = { 0, 0, 0, fmt_450, 0 };
   static cilist io___52 = { 0, 0, 0, fmt_460, 0 };
   static cilist io___53 = { 0, 0, 0, fmt_470, 0 };
   static cilist io___54 = { 0, 0, 0, fmt_475, 0 };
   static cilist io___55 = { 0, 0, 0, fmt_480, 0 };
   static cilist io___56 = { 0, 0, 0, fmt_490, 0 };
   static cilist io___57 = { 0, 0, 0, fmt_900, 0 };
   static cilist io___58 = { 0, 0, 0, fmt_500, 0 };
   static cilist io___59 = { 0, 0, 0, fmt_510, 0 };
   static cilist io___60 = { 0, 0, 0, fmt_520, 0 };
   static cilist io___61 = { 0, 0, 0, fmt_530, 0 };
   static cilist io___62 = { 0, 0, 0, fmt_540, 0 };
   static cilist io___63 = { 0, 0, 0, fmt_550, 0 };
   static cilist io___64 = { 0, 0, 0, fmt_560, 0 };
   static cilist io___65 = { 0, 0, 0, fmt_570, 0 };
   static cilist io___66 = { 0, 0, 0, fmt_580, 0 };
   static cilist io___67 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___68 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___69 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___70 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___71 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___72 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___73 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___74 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___75 = { 0, 0, 0, fmt_480, 0 };
   static cilist io___76 = { 0, 0, 0, fmt_490, 0 };
   static cilist io___77 = { 0, 0, 0, fmt_610, 0 };
   static cilist io___78 = { 0, 0, 0, fmt_620, 0 };
   static cilist io___79 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___80 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___81 = { 0, 0, 0, fmt_630, 0 };
   static cilist io___82 = { 0, 0, 0, fmt_640, 0 };
   static cilist io___83 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___84 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___85 = { 0, 0, 0, fmt_380, 0 };
   static cilist io___86 = { 0, 0, 0, fmt_650, 0 };
   static cilist io___87 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___88 = { 0, 0, 0, fmt_600, 0 };
   static cilist io___89 = { 0, 0, 0, fmt_660, 0 };
   static cilist io___90 = { 0, 0, 0, fmt_610, 0 };
   static cilist io___91 = { 0, 0, 0, fmt_620, 0 };
   static cilist io___92 = { 0, 0, 0, fmt_670, 0 };
   static cilist io___93 = { 0, 0, 0, fmt_590, 0 };
   static cilist io___94 = { 0, 0, 0, fmt_600, 0 };

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// SCREEN OF LIGHT

// MISCELLANEOUS VARIABLES

// PUZZLE ROOM STATE

// I/O VARIABLES

// MESSAGE INDEX

// ROOMS

// EXITS

// OBJECTS

// CLOCK INTERRUPTS

// VILLAINS AND DEMONS

// ADVENTURERS

// FUNCTIONS AND DATA

// FLAGS

// GDT, PAGE 2

// FIRST, VALIDATE THAT THE CALLER IS AN IMPLEMENTER.

   fmax = 46;
// 						!SET ARRAY LIMITS.
   smax = 22;

   if (debug_1.gdtflg != 0) {
      goto L2000;
   }
// 						!IF OK, SKIP.
   io___20.ciunit = chan_1.outch;
   s_wsfe(&io___20);
   e_wsfe();
// 						!NOT AN IMPLEMENTER.
   return 0;
// 						!BOOT HIM OFF

// GDT, PAGE 2A

// HERE TO GET NEXT COMMAND

L2000:
   io___21.ciunit = chan_1.outch;
   s_wsfe(&io___21);
   e_wsfe();
// 						!OUTPUT PROMPT.
   io___22.ciunit = chan_1.inpch;
   s_rsfe(&io___22);
   do_fio(&c__1, cmd, (ftnlen) 2);
   e_rsfe();
// 						!GET COMMAND.
   if (s_cmp(cmd, "  ", (ftnlen) 2, (ftnlen) 2) == 0) {
      goto L2000;
   }
// 						!IGNORE BLANKS.
   i__1 = cmdmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOK IT UP.
      if (s_cmp(cmd, dbgcmd + (i__ - 1 << 1), (ftnlen) 2, (ftnlen) 2) == 0) {
         goto L2300;
      }
// 						!FOUND?
// 	  check for lower case command, as well
      if (s_cmp(cmd, ldbgcmd + (i__ - 1 << 1), (ftnlen) 2, (ftnlen) 2) == 0) {
         goto L2300;
      }
// L2100:
   }
L2200:
   io___25.ciunit = chan_1.outch;
   s_wsfe(&io___25);
   e_wsfe();
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
   io___26.ciunit = chan_1.outch;
   s_wsfe(&io___26);
   e_wsfe();
// 						!TYPE 3, REQUEST ARRAY COORDS.
   io___27.ciunit = chan_1.inpch;
   s_rsfe(&io___27);
   do_fio(&c__1, (char *)&j, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&k, (ftnlen) sizeof(int));
   e_rsfe();
   goto L2400;

L2600:
   io___30.ciunit = chan_1.outch;
   s_wsfe(&io___30);
   e_wsfe();
// 						!TYPE 2, READ BOUNDS.
   io___31.ciunit = chan_1.inpch;
   s_rsfe(&io___31);
   do_fio(&c__1, (char *)&j, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&k, (ftnlen) sizeof(int));
   e_rsfe();
   if (k == 0) {
      k = j;
   }
   goto L2400;

L2500:
   io___32.ciunit = chan_1.outch;
   s_wsfe(&io___32);
   e_wsfe();
// 						!TYPE 1, READ ENTRY NO.
   io___33.ciunit = chan_1.inpch;
   s_rsfe(&io___33);
   do_fio(&c__1, (char *)&j, (ftnlen) sizeof(int));
   e_rsfe();
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
   io___34.ciunit = chan_1.outch;
   s_wsfe(&io___34);
   e_wsfe();
// 						!COL HDRS.
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      io___35.ciunit = chan_1.outch;
      s_wsfe(&io___35);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      for (l = 1; l <= 5; ++l) {
         do_fio(&c__1, (char *)&eqr[i__ + l * 200 - 201], (ftnlen) sizeof(int));
      }
      e_wsfe();
// L10100:
   }
   goto L2000;

// DO-- DISPLAY OBJECTS

L11000:
   if (!(j > 0 && j <= objcts_1.olnt && (k > 0 && k <= objcts_1.olnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   io___37.ciunit = chan_1.outch;
   s_wsfe(&io___37);
   e_wsfe();
// 						!COL HDRS
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      io___38.ciunit = chan_1.outch;
      s_wsfe(&io___38);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      for (l = 1; l <= 14; ++l) {
         do_fio(&c__1, (char *)&eqo[i__ + l * 220 - 221], (ftnlen) sizeof(int));
      }
      e_wsfe();
// L11100:
   }
   goto L2000;

// DA-- DISPLAY ADVENTURERS

L12000:
   if (!(j > 0 && j <= advs_1.alnt && (k > 0 && k <= advs_1.alnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   io___39.ciunit = chan_1.outch;
   s_wsfe(&io___39);
   e_wsfe();
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      io___40.ciunit = chan_1.outch;
      s_wsfe(&io___40);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      for (l = 1; l <= 7; ++l) {
         do_fio(&c__1, (char *)&eqa[i__ + (l << 2) - 5], (ftnlen) sizeof(int));
      }
      e_wsfe();
// L12100:
   }
   goto L2000;

// DC-- DISPLAY CLOCK EVENTS

L13000:
   if (!(j > 0 && j <= cevent_1.clnt && (k > 0 && k <= cevent_1.clnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   io___41.ciunit = chan_1.outch;
   s_wsfe(&io___41);
   e_wsfe();
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      io___42.ciunit = chan_1.outch;
      s_wsfe(&io___42);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      for (l = 1; l <= 2; ++l) {
         do_fio(&c__1, (char *)&eqc[i__ + l * 25 - 26], (ftnlen) sizeof(int));
      }
      do_fio(&c__1, (char *)&cevent_1.cflag[i__ - 1], (ftnlen) sizeof(Bool));
      e_wsfe();
// L13100:
   }
   goto L2000;

// DX-- DISPLAY EXITS

L14000:
   if (!(j > 0 && j <= exits_1.xlnt && (k > 0 && k <= exits_1.xlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   io___43.ciunit = chan_1.outch;
   s_wsfe(&io___43);
   e_wsfe();
// 						!COL HDRS.
   i__1 = k;
   for (i__ = j; i__ <= i__1; i__ += 10) {
// 						!TEN PER LINE.
// Computing MIN
      i__2 = i__ + 9;
      l = min(i__2, k);
// 						!COMPUTE END OF LINE.
      io___44.ciunit = chan_1.outch;
      s_wsfe(&io___44);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&l, (ftnlen) sizeof(int));
      i__2 = l;
      for (l1 = i__; l1 <= i__2; ++l1) {
         do_fio(&c__1, (char *)&exits_1.travel[l1 - 1], (ftnlen) sizeof(int));
      }
      e_wsfe();
// L14100:
   }
   goto L2000;

// DH-- DISPLAY HACKS

L15000:
   io___46.ciunit = chan_1.outch;
   s_wsfe(&io___46);
   do_fio(&c__1, (char *)&hack_1.thfpos, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&hack_1.thfflg, (ftnlen) sizeof(Bool));
   do_fio(&c__1, (char *)&hack_1.thfact, (ftnlen) sizeof(Bool));
   do_fio(&c__1, (char *)&hack_1.swdact, (ftnlen) sizeof(Bool));
   do_fio(&c__1, (char *)&hack_1.swdsta, (ftnlen) sizeof(int));
   e_wsfe();
   goto L2000;

// DL-- DISPLAY LENGTHS

L16000:
   io___47.ciunit = chan_1.outch;
   s_wsfe(&io___47);
   do_fio(&c__1, (char *)&rooms_1.rlnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&exits_1.xlnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&objcts_1.olnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&cevent_1.clnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&vill_1.vlnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&advs_1.alnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&rmsg_1.mlnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&oroom2_1.r2lnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&star_1.mbase, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&star_1.strbit, (ftnlen) sizeof(int));
   e_wsfe();
   goto L2000;

// DV-- DISPLAY VILLAINS

L17000:
   if (!(j > 0 && j <= vill_1.vlnt && (k > 0 && k <= vill_1.vlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   io___48.ciunit = chan_1.outch;
   s_wsfe(&io___48);
   e_wsfe();
// 						!COL HDRS
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      io___49.ciunit = chan_1.outch;
      s_wsfe(&io___49);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      for (l = 1; l <= 5; ++l) {
         do_fio(&c__1, (char *)&eqv[i__ + (l << 2) - 5], (ftnlen) sizeof(int));
      }
      e_wsfe();
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
      io___50.ciunit = chan_1.outch;
      s_wsfe(&io___50);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&flags[i__ - 1], (ftnlen) sizeof(Bool));
      e_wsfe();
// L18100:
   }
   goto L2000;

// DS-- DISPLAY STATE

L19000:
   io___51.ciunit = chan_1.outch;
   s_wsfe(&io___51);
   do_fio(&c__1, (char *)&prsvec_1.prsa, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&prsvec_1.prso, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&prsvec_1.prsi, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&prsvec_1.prswon, (ftnlen) sizeof(Bool));
   do_fio(&c__1, (char *)&prsvec_1.prscon, (ftnlen) sizeof(int));
   e_wsfe();
   io___52.ciunit = chan_1.outch;
   s_wsfe(&io___52);
   do_fio(&c__1, (char *)&play_1.winner, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&play_1.here, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&play_1.telflg, (ftnlen) sizeof(Bool));
   e_wsfe();
   io___53.ciunit = chan_1.outch;
   s_wsfe(&io___53);
   do_fio(&c__1, (char *)&state_1.moves, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.deaths, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.rwscor, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.mxscor, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.mxload, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.ltshft, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.bloc, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.mungrm, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.hs, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.egscor, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.egmxsc, (ftnlen) sizeof(int));
   e_wsfe();
   io___54.ciunit = chan_1.outch;
   s_wsfe(&io___54);
   do_fio(&c__1, (char *)&screen_1.fromdr, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&screen_1.scolrm, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&screen_1.scolac, (ftnlen) sizeof(int));
   e_wsfe();
   goto L2000;

// GDT, PAGE 4

// AF-- ALTER FLAGS

L20000:
   if (!(j > 0 && j <= fmax)) {
      goto L2200;
   }
// 						!ENTRY NO VALID?
   io___55.ciunit = chan_1.outch;
   s_wsfe(&io___55);
   do_fio(&c__1, (char *)&flags[j - 1], (ftnlen) sizeof(Bool));
   e_wsfe();
// 						!TYPE OLD, GET NEW.
   io___56.ciunit = chan_1.inpch;
   s_rsfe(&io___56);
   do_fio(&c__1, (char *)&flags[j - 1], (ftnlen) sizeof(Bool));
   e_rsfe();
   goto L2000;

// 21000-- HELP

L21000:
   io___57.ciunit = chan_1.outch;
   s_wsfe(&io___57);
   e_wsfe();
   goto L2000;

// NR-- NO ROBBER

L22000:
   hack_1.thfflg = false;
// 						!DISABLE ROBBER.
   hack_1.thfact = false;
   newsta_(&oindex_1.thief, &c__0, &c__0, &c__0, &c__0);
// 						!VANISH THIEF.
   io___58.ciunit = chan_1.outch;
   s_wsfe(&io___58);
   e_wsfe();
   goto L2000;

// NT-- NO TROLL

L23000:
   findex_1.trollf = true;
   newsta_(&oindex_1.troll, &c__0, &c__0, &c__0, &c__0);
   io___59.ciunit = chan_1.outch;
   s_wsfe(&io___59);
   e_wsfe();
   goto L2000;

// NC-- NO CYCLOPS

L24000:
   findex_1.cyclof = true;
   newsta_(&oindex_1.cyclo, &c__0, &c__0, &c__0, &c__0);
   io___60.ciunit = chan_1.outch;
   s_wsfe(&io___60);
   e_wsfe();
   goto L2000;

// ND-- IMMORTALITY MODE

L25000:
   debug_1.dbgflg = 1;
   io___61.ciunit = chan_1.outch;
   s_wsfe(&io___61);
   e_wsfe();
   goto L2000;

// RR-- RESTORE ROBBER

L26000:
   hack_1.thfact = true;
   io___62.ciunit = chan_1.outch;
   s_wsfe(&io___62);
   e_wsfe();
   goto L2000;

// RT-- RESTORE TROLL

L27000:
   findex_1.trollf = false;
   newsta_(&oindex_1.troll, &c__0, &rindex_1.mtrol, &c__0, &c__0);
   io___63.ciunit = chan_1.outch;
   s_wsfe(&io___63);
   e_wsfe();
   goto L2000;

// RC-- RESTORE CYCLOPS

L28000:
   findex_1.cyclof = false;
   findex_1.magicf = false;
   newsta_(&oindex_1.cyclo, &c__0, &rindex_1.mcycl, &c__0, &c__0);
   io___64.ciunit = chan_1.outch;
   s_wsfe(&io___64);
   e_wsfe();
   goto L2000;

// RD-- MORTAL MODE

L29000:
   debug_1.dbgflg = 0;
   io___65.ciunit = chan_1.outch;
   s_wsfe(&io___65);
   e_wsfe();
   goto L2000;

// GDT, PAGE 5

// TK-- TAKE

L30000:
   if (!(j > 0 && j <= objcts_1.olnt)) {
      goto L2200;
   }
// 						!VALID OBJECT?
   newsta_(&j, &c__0, &c__0, &c__0, &play_1.winner);
// 						!YES, TAKE OBJECT.
   io___66.ciunit = chan_1.outch;
   s_wsfe(&io___66);
   e_wsfe();
// 						!TELL.
   goto L2000;

// EX-- GOODBYE

L31000:
   prsvec_1.prscon = 1;
   return 0;

// AR--	ALTER ROOM ENTRY

L32000:
   if (!(j > 0 && j <= rooms_1.rlnt && (k > 0 && k <= c__5))) {
      goto L2200;
   }
// 						!INDICES VALID?
   io___67.ciunit = chan_1.outch;
   s_wsfe(&io___67);
   do_fio(&c__1, (char *)&eqr[j + k * 200 - 201], (ftnlen) sizeof(int));
   e_wsfe();
// 						!TYPE OLD, GET NEW.
   io___68.ciunit = chan_1.inpch;
   s_rsfe(&io___68);
   do_fio(&c__1, (char *)&eqr[j + k * 200 - 201], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// AO-- ALTER OBJECT ENTRY

L33000:
   if (!(j > 0 && j <= objcts_1.olnt && (k > 0 && k <= c__14))) {
      goto L2200;
   }
// 						!INDICES VALID?
   io___69.ciunit = chan_1.outch;
   s_wsfe(&io___69);
   do_fio(&c__1, (char *)&eqo[j + k * 220 - 221], (ftnlen) sizeof(int));
   e_wsfe();
   io___70.ciunit = chan_1.inpch;
   s_rsfe(&io___70);
   do_fio(&c__1, (char *)&eqo[j + k * 220 - 221], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// AA-- ALTER ADVS ENTRY

L34000:
   if (!(j > 0 && j <= advs_1.alnt && (k > 0 && k <= c__7))) {
      goto L2200;
   }
// 						!INDICES VALID?
   io___71.ciunit = chan_1.outch;
   s_wsfe(&io___71);
   do_fio(&c__1, (char *)&eqa[j + (k << 2) - 5], (ftnlen) sizeof(int));
   e_wsfe();
   io___72.ciunit = chan_1.inpch;
   s_rsfe(&io___72);
   do_fio(&c__1, (char *)&eqa[j + (k << 2) - 5], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// AC-- ALTER CLOCK EVENTS

L35000:
   if (!(j > 0 && j <= cevent_1.clnt && (k > 0 && k <= c__3))) {
      goto L2200;
   }
// 						!INDICES VALID?
   if (k == 3) {
      goto L35500;
   }
// 						!FLAGS ENTRY?
   io___73.ciunit = chan_1.outch;
   s_wsfe(&io___73);
   do_fio(&c__1, (char *)&eqc[j + k * 25 - 26], (ftnlen) sizeof(int));
   e_wsfe();
   io___74.ciunit = chan_1.inpch;
   s_rsfe(&io___74);
   do_fio(&c__1, (char *)&eqc[j + k * 25 - 26], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

L35500:
   io___75.ciunit = chan_1.outch;
   s_wsfe(&io___75);
   do_fio(&c__1, (char *)&cevent_1.cflag[j - 1], (ftnlen) sizeof(Bool));
   e_wsfe();
   io___76.ciunit = chan_1.inpch;
   s_rsfe(&io___76);
   do_fio(&c__1, (char *)&cevent_1.cflag[j - 1], (ftnlen) sizeof(Bool));
   e_rsfe();
   goto L2000;
// GDT, PAGE 6

// AX-- ALTER EXITS

L36000:
   if (!(j > 0 && j <= exits_1.xlnt)) {
      goto L2200;
   }
// 						!ENTRY NO VALID?
   io___77.ciunit = chan_1.outch;
   s_wsfe(&io___77);
   do_fio(&c__1, (char *)&exits_1.travel[j - 1], (ftnlen) sizeof(int));
   e_wsfe();
   io___78.ciunit = chan_1.inpch;
   s_rsfe(&io___78);
   do_fio(&c__1, (char *)&exits_1.travel[j - 1], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// AV-- ALTER VILLAINS

L37000:
   if (!(j > 0 && j <= vill_1.vlnt && (k > 0 && k <= c__5))) {
      goto L2200;
   }
// 						!INDICES VALID?
   io___79.ciunit = chan_1.outch;
   s_wsfe(&io___79);
   do_fio(&c__1, (char *)&eqv[j + (k << 2) - 5], (ftnlen) sizeof(int));
   e_wsfe();
   io___80.ciunit = chan_1.inpch;
   s_rsfe(&io___80);
   do_fio(&c__1, (char *)&eqv[j + (k << 2) - 5], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// D2-- DISPLAY ROOM2 LIST

L38000:
   if (!(j > 0 && j <= oroom2_1.r2lnt && (k > 0 && k <= oroom2_1.r2lnt) && j <= k)) {
      goto L2200;
   }
   i__1 = k;
   for (i__ = j; i__ <= i__1; ++i__) {
      io___81.ciunit = chan_1.outch;
      s_wsfe(&io___81);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&oroom2_1.rroom2[i__ - 1], (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&oroom2_1.oroom2[i__ - 1], (ftnlen) sizeof(int));
      e_wsfe();
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
      io___82.ciunit = chan_1.outch;
      s_wsfe(&io___82);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&switch__[i__ - 1], (ftnlen) sizeof(int));
      e_wsfe();
// L39100:
   }
   goto L2000;

// AN-- ALTER SWITCHES

L40000:
   if (!(j > 0 && j <= smax)) {
      goto L2200;
   }
// 						!VALID ENTRY?
   io___83.ciunit = chan_1.outch;
   s_wsfe(&io___83);
   do_fio(&c__1, (char *)&switch__[j - 1], (ftnlen) sizeof(int));
   e_wsfe();
   io___84.ciunit = chan_1.inpch;
   s_rsfe(&io___84);
   do_fio(&c__1, (char *)&switch__[j - 1], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// DM-- DISPLAY MESSAGES

L41000:
   if (!(j > 0 && j <= rmsg_1.mlnt && (k > 0 && k <= rmsg_1.mlnt) && j <= k)) {
      goto L2200;
   }
// 						!VALID LIMITS?
   io___85.ciunit = chan_1.outch;
   s_wsfe(&io___85);
   e_wsfe();
   i__1 = k;
   for (i__ = j; i__ <= i__1; i__ += 10) {
// Computing MIN
      i__2 = i__ + 9;
      l = min(i__2, k);
      io___86.ciunit = chan_1.outch;
      s_wsfe(&io___86);
      do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
      do_fio(&c__1, (char *)&l, (ftnlen) sizeof(int));
      i__2 = l;
      for (l1 = i__; l1 <= i__2; ++l1) {
         do_fio(&c__1, (char *)&rmsg_1.rtext[l1 - 1], (ftnlen) sizeof(int));
      }
      e_wsfe();
// L41100:
   }
   goto L2000;

// DT-- DISPLAY TEXT

L42000:
   rspeak_(&j);
   goto L2000;

// AH--	ALTER HERE

L43000:
   io___87.ciunit = chan_1.outch;
   s_wsfe(&io___87);
   do_fio(&c__1, (char *)&play_1.here, (ftnlen) sizeof(int));
   e_wsfe();
   io___88.ciunit = chan_1.inpch;
   s_rsfe(&io___88);
   do_fio(&c__1, (char *)&play_1.here, (ftnlen) sizeof(int));
   e_rsfe();
   eqa[0] = play_1.here;
   goto L2000;

// DP--	DISPLAY PARSER STATE

L44000:
   io___89.ciunit = chan_1.outch;
   s_wsfe(&io___89);
   do_fio(&c__5, (char *)&orp[0], (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&last_1.lastit, (ftnlen) sizeof(int));
   do_fio(&c__5, (char *)&pvec[0], (ftnlen) sizeof(int));
   do_fio(&c__11, (char *)&syn[0], (ftnlen) sizeof(int));
   e_wsfe();
   goto L2000;

// PD--	PROGRAM DETAIL DEBUG

L45000:
   io___90.ciunit = chan_1.outch;
   s_wsfe(&io___90);
   do_fio(&c__1, (char *)&debug_1.prsflg, (ftnlen) sizeof(int));
   e_wsfe();
// 						!TYPE OLD, GET NEW.
   io___91.ciunit = chan_1.inpch;
   s_rsfe(&io___91);
   do_fio(&c__1, (char *)&debug_1.prsflg, (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

// DZ--	DISPLAY PUZZLE ROOM

L46000:
   for (i__ = 1; i__ <= 64; i__ += 8) {
// 						!DISPLAY PUZZLE
      io___92.ciunit = chan_1.outch;
      s_wsfe(&io___92);
      i__1 = i__ + 7;
      for (j = i__; j <= i__1; ++j) {
         do_fio(&c__1, (char *)&puzzle_1.cpvec[j - 1], (ftnlen) sizeof(int));
      }
      e_wsfe();
// L46100:
   }
   goto L2000;

// AZ--	ALTER PUZZLE ROOM

L47000:
   if (!(j > 0 && j <= c__64)) {
      goto L2200;
   }
// 						!VALID ENTRY?
   io___93.ciunit = chan_1.outch;
   s_wsfe(&io___93);
   do_fio(&c__1, (char *)&puzzle_1.cpvec[j - 1], (ftnlen) sizeof(int));
   e_wsfe();
// 						!OUTPUT OLD,
   io___94.ciunit = chan_1.inpch;
   s_rsfe(&io___94);
   do_fio(&c__1, (char *)&puzzle_1.cpvec[j - 1], (ftnlen) sizeof(int));
   e_rsfe();
   goto L2000;

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
