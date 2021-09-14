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
   int mlnt, rtext[1820];
} rmsg_;

#define rmsg_1 rmsg_

struct {
   int mbase, strbit;
} star_;

#define star_1 star_

struct {
   int vmaj, vmin, vedit;
} vers_;

#define vers_1 vers_

struct {
   int pltime, shour, smin, ssec;
} time_;

#define time_1 time_

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
   int dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

struct {
   int hfactr;
} hyper_;

#define hyper_1 hyper_

struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

struct {
   int xlnt, travel[900];
} exits_;

#define exits_1 exits_

struct {
   int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_

struct {
   int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;

#define xpars_1 xpars_

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
static int c__200 = 200;
static int c__900 = 900;
static int c__220 = 220;
static int c__20 = 20;
static int c__25 = 25;
static int c__4 = 4;
static int c__1820 = 1820;

// INIT-- DUNGEON INITIALIZATION SUBROUTINE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool init_(int * x) {
// Format strings
   static char fmt_10100[] =
      "(\002 There appears before you a threatening " "figure clad \002,\002all over\002/\002 in heavy black armor.  Hi" "s legs seem like the \002,\002massive trunk\002/\002 of the oak " "tree.  His broad shoulders and \002,\002helmeted head loom\002"
      "/\002 high over your own puny frame, and \002,\002you realize th" "at his powerful\002/\002 arms could easily crush the \002,\002ve" "ry life from your body.  There\002/\002 hangs from his belt a"
      " \002,\002veritable arsenal of deadly weapons:\002/\002 sword, m" "ace, ball \002,\002and chain, dagger, lance, and trident.\002" "/\002 He speaks with a \002,\002commanding voice:\002//20x,"
      "\002\"You shall not pass.\"\002//\002 As \002,\002he grabs you b" "y the neck all grows dim about you.\002)";
   static char fmt_130[] = "(i6)";
   static char fmt_135[] = "(l4)";
   static char fmt_910[] = "(\002 I can't open \002,\002dindx.dat\002,\002" ".\002)";
   static char fmt_980[] =
      "(\002 Suddenly a sinister, wraithlike figure ap" "pears before \002,\002you,\002/\002 seeming to float in the air." "  In a low, sorrowful voice\002,\002 he says,\002/\002 \"Alas, t"
      "he very nature of the world has changed, \002,\002and the dungeon" "\002/\002 cannot be found.  All must now pass away.\"\002,\002  " "Raising his oaken staff\002/\002 in farewell, he fades into the"
      " \002,\002spreading darkness.  In his place\002/\002 appears a t" "astefully \002,\002lettered sign reading:\002//23x,\002INITIALIZ" "ATION FAILURE\002//\002 The darkness becomes all encompassing, a" "nd your vision fails.\002)";
   static char fmt_920[] = "(\002 \"dindx.dat\" is version \002,i1,\002." "\002,i1,a1,\002.\002/\002 I require version \002,i1,\002.\002,i1" ",a1,\002.\002)";
   static char fmt_960[] = "(\002 I can't open \002,\002dtext.dat\002,\002" ".\002)";

// System generated locals
   int i__1;
   Bool ret_val;
   olist o__1;
   cllist cl__1;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   static int xmax, r2max, dirmax, recno;
   extern Void intime_(int *, int *, int *), inirnd_(int *);
   static int i__, j, k;
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Void exit_(void);
   static int mmax, omax, rmax, vmax, amax, cmax, fmax, smax;
#define rrand ((int *)&rooms_1 + 602)
#define xflag ((int *)&curxt_1 + 4)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
   extern Bool protct_(int *);

// Fortran I/O blocks
   static cilist io___15 = { 0, 6, 0, fmt_10100, 0 };
   static cilist io___29 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___32 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___33 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___34 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___35 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___36 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___37 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___38 = { 0, 1, 0, fmt_135, 0 };
   static cilist io___39 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___40 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___41 = { 0, 1, 0, fmt_130, 0 };
   static cilist io___42 = { 0, 6, 0, fmt_910, 0 };
   static cilist io___43 = { 0, 6, 0, fmt_980, 0 };
   static cilist io___44 = { 0, 6, 0, fmt_920, 0 };
   static cilist io___45 = { 0, 6, 0, fmt_980, 0 };
   static cilist io___46 = { 0, 6, 0, fmt_960, 0 };
   static cilist io___47 = { 0, 6, 0, fmt_980, 0 };

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// SCREEN OF LIGHT

// MISCELLANEOUS VARIABLES

// MESSAGE INDEX

// I/O VARIABLES

// ROOMS

// EXITS

// CURRENT EXITS

// OBJECTS

// CLOCK INTERRUPTS

// VILLAINS AND DEMONS

// ADVENTURERS

// INIT, PAGE 2

// FIRST CHECK FOR PROTECTION VIOLATION

// FLAGS

   if (protct_(x)) {
      goto L10000;
   }
// 						!PROTECTION VIOLATION?
   s_wsfe(&io___15);
   e_wsfe();
   exit_();

// NOW START INITIALIZATION PROPER

L10000:
   ret_val = false;
// 						!ASSUME INIT FAILS.
   mmax = 1820;
// 						!SET UP ARRAY LIMITS.
   omax = 220;
   rmax = 200;
   vmax = 4;
   amax = 4;
   cmax = 25;
   fmax = 46;
   smax = 22;
   xmax = 900;
   r2max = 20;
   dirmax = 15;

   rmsg_1.mlnt = 0;
// 						!INIT ARRAY COUNTERS.
   objcts_1.olnt = 0;
   rooms_1.rlnt = 0;
   vill_1.vlnt = 0;
   advs_1.alnt = 0;
   cevent_1.clnt = 0;
   exits_1.xlnt = 1;
   oroom2_1.r2lnt = 0;

   state_1.ltshft = 10;
// 						!SET UP STATE VARIABLES.
   state_1.mxscor = state_1.ltshft;
   state_1.egscor = 0;
   state_1.egmxsc = 0;
   state_1.mxload = 100;
   state_1.rwscor = 0;
   state_1.deaths = 0;
   state_1.moves = 0;
   time_1.pltime = 0;
   state_1.mungrm = 0;
   state_1.hs = 0;
   prsvec_1.prsa = 0;
// 						!CLEAR PARSE VECTOR.
   prsvec_1.prsi = 0;
   prsvec_1.prso = 0;
   prsvec_1.prscon = 1;
   orphs_1.oflag = 0;
// 						!CLEAR ORPHANS.
   orphs_1.oact = 0;
   orphs_1.oslot = 0;
   orphs_1.oprep = 0;
   orphs_1.oname = 0;
   hack_1.thfflg = false;
// 						!THIEF NOT INTRODUCED BUT
   hack_1.thfact = true;
// 						!IS ACTIVE.
   hack_1.swdact = false;
// 						!SWORD IS INACTIVE.
   hack_1.swdsta = 0;
// 						!SWORD IS OFF.

   recno = 1;
// 						!INIT DB FILE POINTER.
   star_1.mbase = 0;
// 						!INIT MELEE BASE.
//   LOGICAL UNIT NRS: 5=STDIN, 6=STDOUT
   chan_1.inpch = 5;
// 						!TTY INPUT
   chan_1.outch = 6;
   chan_1.dbch = 2;
// 						!DATA BASE.
// INIT, PAGE 3

// INIT ALL ARRAYS.

   i__1 = cmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR CLOCK EVENTS
      cevent_1.cflag[i__ - 1] = false;
      cevent_1.ctick[i__ - 1] = 0;
      cevent_1.cactio[i__ - 1] = 0;
// L5:
   }

   i__1 = fmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR FLAGS.
      flags[i__ - 1] = false;
// L10:
   }
   findex_1.buoyf = true;
// 						!SOME START AS TRUE.
   findex_1.egyptf = true;
   findex_1.cagetf = true;
   findex_1.mr1f = true;
   findex_1.mr2f = true;
   findex_1.follwf = true;
   i__1 = smax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR SWITCHES.
      switch__[i__ - 1] = 0;
// L12:
   }
   findex_1.ormtch = 4;
// 						!NUMBER OF MATCHES.
   findex_1.lcell = 1;
   findex_1.pnumb = 1;
   findex_1.mdir = 270;
   findex_1.mloc = rindex_1.mrb;
   findex_1.cphere = 10;

   i__1 = r2max;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR ROOM 2 ARRAY.
      oroom2_1.rroom2[i__ - 1] = 0;
      oroom2_1.oroom2[i__ - 1] = 0;
// L15:
   }

   i__1 = xmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR TRAVEL ARRAY.
      exits_1.travel[i__ - 1] = 0;
// L20:
   }

   i__1 = vmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR VILLAINS ARRAYS.
      vill_1.vopps[i__ - 1] = 0;
      vill_1.vprob[i__ - 1] = 0;
      vill_1.villns[i__ - 1] = 0;
      vill_1.vbest[i__ - 1] = 0;
      vill_1.vmelee[i__ - 1] = 0;
// L30:
   }

   i__1 = omax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR OBJECT ARRAYS.
      objcts_1.odesc1[i__ - 1] = 0;
      objcts_1.odesc2[i__ - 1] = 0;
      objcts_1.odesco[i__ - 1] = 0;
      objcts_1.oread[i__ - 1] = 0;
      objcts_1.oactio[i__ - 1] = 0;
      objcts_1.oflag1[i__ - 1] = 0;
      objcts_1.oflag2[i__ - 1] = 0;
      objcts_1.ofval[i__ - 1] = 0;
      objcts_1.otval[i__ - 1] = 0;
      objcts_1.osize[i__ - 1] = 0;
      objcts_1.ocapac[i__ - 1] = 0;
      objcts_1.ocan[i__ - 1] = 0;
      objcts_1.oadv[i__ - 1] = 0;
      objcts_1.oroom[i__ - 1] = 0;
// L40:
   }

   rooms_1.rdesc2 = 0;
// 						!CLEAR DESC BASE PTR.
   i__1 = rmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR ROOM ARRAYS.
      rooms_1.rdesc1[i__ - 1] = 0;
      rooms_1.ractio[i__ - 1] = 0;
      rooms_1.rflag[i__ - 1] = 0;
      rooms_1.rval[i__ - 1] = 0;
      rooms_1.rexit[i__ - 1] = 0;
// L50:
   }

   i__1 = mmax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR MESSAGE DIRECTORY.
      rmsg_1.rtext[i__ - 1] = 0;
// L60:
   }

   i__1 = amax;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!CLEAR ADVENTURER'S ARRAYS.
      advs_1.aroom[i__ - 1] = 0;
      advs_1.ascore[i__ - 1] = 0;
      advs_1.avehic[i__ - 1] = 0;
      advs_1.aobj[i__ - 1] = 0;
      advs_1.aactio[i__ - 1] = 0;
      advs_1.astren[i__ - 1] = 0;
      advs_1.aflag[i__ - 1] = 0;
// L70:
   }

   debug_1.dbgflg = 0;
   debug_1.prsflg = 0;

// allow setting gdtflg true if user id matches wizard id
// this way, the wizard doesn't have to recompile to use gdt

// 	Changed by TAA so that always in wizard ID
// D	gdtflg=1

   screen_1.fromdr = 0;
// 						!INIT SCOL GOODIES.
   screen_1.scolrm = 0;
   screen_1.scolac = 0;
// INIT, PAGE 4

// NOW RESTORE FROM EXISTING INDEX FILE.

// 	OPEN(UNIT=1,file='/usr/share/games/dungeon/dindx.dat',
   o__1.oerr = 1;
   o__1.ounit = 1;
   o__1.ofnmlen = 9;
   o__1.ofnm = "dindx.dat";
   o__1.orl = 0;
   o__1.osta = "OLD";
   o__1.oacc = "SEQUENTIAL";
   o__1.ofm = "FORMATTED";
   o__1.oblnk = 0;
   i__1 = f_open(&o__1);
   if (i__1 != 0) {
      goto L1900;
   }
   s_rsfe(&io___29);
   do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&j, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&k, (ftnlen) sizeof(int));
   e_rsfe();
// 						!GET VERSION.
   if (i__ != vers_1.vmaj || j != vers_1.vmin) {
      goto L1925;
   }
// 	OPEN(UNIT=DBCH,file='/usr/share/games/dungeon/dtext.dat',
   o__1.oerr = 1;
   o__1.ounit = chan_1.dbch;
   o__1.ofnmlen = 9;
   o__1.ofnm = "dtext.dat";
   o__1.orl = 76;
   o__1.osta = "OLD";
   o__1.oacc = "DIRECT";
   o__1.ofm = "UNFORMATTED";
   o__1.oblnk = 0;
   i__1 = f_open(&o__1);
   if (i__1 != 0) {
      goto L1950;
   }
// D	PRINT 150
// D150	FORMAT(' RESTORING FROM "dindx.dat"')
   s_rsfe(&io___32);
   do_fio(&c__1, (char *)&state_1.mxscor, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&star_1.strbit, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&state_1.egmxsc, (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___33);
   do_fio(&c__1, (char *)&rooms_1.rlnt, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&rooms_1.rdesc2, (ftnlen) sizeof(int));
   do_fio(&c__200, (char *)&rooms_1.rdesc1[0], (ftnlen) sizeof(int));
   do_fio(&c__200, (char *)&rooms_1.rexit[0], (ftnlen) sizeof(int));
   do_fio(&c__200, (char *)&rooms_1.ractio[0], (ftnlen) sizeof(int));
   do_fio(&c__200, (char *)&rooms_1.rval[0], (ftnlen) sizeof(int));
   do_fio(&c__200, (char *)&rooms_1.rflag[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___34);
   do_fio(&c__1, (char *)&exits_1.xlnt, (ftnlen) sizeof(int));
   do_fio(&c__900, (char *)&exits_1.travel[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___35);
   do_fio(&c__1, (char *)&objcts_1.olnt, (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.odesc1[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.odesc2[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.odesco[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.oactio[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.oflag1[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.oflag2[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.ofval[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.otval[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.osize[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.ocapac[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.oroom[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.oadv[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.ocan[0], (ftnlen) sizeof(int));
   do_fio(&c__220, (char *)&objcts_1.oread[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___36);
   do_fio(&c__1, (char *)&oroom2_1.r2lnt, (ftnlen) sizeof(int));
   do_fio(&c__20, (char *)&oroom2_1.oroom2[0], (ftnlen) sizeof(int));
   do_fio(&c__20, (char *)&oroom2_1.rroom2[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___37);
   do_fio(&c__1, (char *)&cevent_1.clnt, (ftnlen) sizeof(int));
   do_fio(&c__25, (char *)&cevent_1.ctick[0], (ftnlen) sizeof(int));
   do_fio(&c__25, (char *)&cevent_1.cactio[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___38);
   do_fio(&c__25, (char *)&cevent_1.cflag[0], (ftnlen) sizeof(Bool));
   e_rsfe();
   s_rsfe(&io___39);
   do_fio(&c__1, (char *)&vill_1.vlnt, (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&vill_1.villns[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&vill_1.vprob[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&vill_1.vopps[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&vill_1.vbest[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&vill_1.vmelee[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___40);
   do_fio(&c__1, (char *)&advs_1.alnt, (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.aroom[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.ascore[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.avehic[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.aobj[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.aactio[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.astren[0], (ftnlen) sizeof(int));
   do_fio(&c__4, (char *)&advs_1.aflag[0], (ftnlen) sizeof(int));
   e_rsfe();
   s_rsfe(&io___41);
   do_fio(&c__1, (char *)&star_1.mbase, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&rmsg_1.mlnt, (ftnlen) sizeof(int));
   do_fio(&c__1820, (char *)&rmsg_1.rtext[0], (ftnlen) sizeof(int));
   e_rsfe();

   cl__1.cerr = 0;
   cl__1.cunit = 1;
   cl__1.csta = 0;
   f_clos(&cl__1);
   goto L1025;
// 						!INIT DONE.

// 130	FORMAT(I8)
// INIT, PAGE 5

// THE INTERNAL DATA BASE IS NOW ESTABLISHED.
// SET UP TO PLAY THE GAME.

L1025:
   intime_(&time_1.shour, &time_1.smin, &time_1.ssec);
// 						!GET TIME AND DATE.
// 	CALL IDATE(I,J,K)
// 	CALL IDATE(DATARRY(1))
// 	CALL INIRND(or(DATARRY(1),or(DATARRY(2),DATARRY(3))),
//     &	or(SHOUR,or(SMIN,SSEC)))
// 	NEW WAY TO INITIALIZE /+TAA+/
   i__1 = time_1.shour * 3600 + time_1.smin * 60 + time_1.ssec;
   inirnd_(&i__1);

   play_1.winner = aindex_1.player;
   last_1.lastit = advs_1.aobj[aindex_1.player - 1];
   play_1.here = advs_1.aroom[play_1.winner - 1];
   hack_1.thfpos = objcts_1.oroom[oindex_1.thief - 1];
   state_1.bloc = objcts_1.oroom[oindex_1.ballo - 1];
   ret_val = true;

// D	PRINT 1050,RLNT,RMAX,XLNT,XMAX,OLNT,OMAX,MLNT,MMAX,
// D    &  VLNT,VMAX,ALNT,AMAX,CLNT,CMAX,R2LNT,R2MAX
// D1050	FORMAT(' USED:'/1X,I5,' OF',I5,' ROOMS'/
// D    &  1X,I5,' OF',I5,' EXITS'/
// D    &  1X,I5,' OF',I5,' OBJECTS'/
// D    &  1X,I5,' OF',I5,' MESSAGES'/
// D    &  1X,I5,' OF',I5,' VILLAINS'/
// D    &  1X,I5,' OF',I5,' ADVENTURERS'/
// D    &  1X,I5,' OF',I5,' CLOCK EVENTS'/
// D    &  1X,I5,' OF',I5,' ROOM2 SLOTS')
// D	PRINT 1150,MXSCOR,EGMXSC,RECNO,RDESC2,MBASE,STRBIT
// D1150	FORMAT(' MAX SCORE=',I5/' EG SCORE=',I5/
// D    &  ' MAX RECNO=',I5/' RDESC2 BASE=',I5/
// D    &  ' MELEE START=',I5/' STAR MASK=',I7)
// D	PAUSE 1

   return ret_val;
// INIT, PAGE 6

// ERRORS-- INIT FAILS.

L1900:
   s_wsfe(&io___42);
   e_wsfe();
   s_wsfe(&io___43);
   e_wsfe();
   return ret_val;
L1925:
   s_wsfe(&io___44);
   do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&j, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&k, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&vers_1.vmaj, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&vers_1.vmin, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&vers_1.vedit, (ftnlen) sizeof(int));
   e_wsfe();
   s_wsfe(&io___45);
   e_wsfe();
   return ret_val;
L1950:
   s_wsfe(&io___46);
   e_wsfe();
   s_wsfe(&io___47);
   e_wsfe();
   return ret_val;

}

#undef prpvec
#undef objvec
#undef xflag
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

// PROTCT-- CHECK FOR USER VIOLATION

// THIS ROUTINE SHOULD BE MODIFIED IF YOU WISH TO ADD SYSTEM
// DEPENDANT PROTECTION AGAINST ABUSE.

// AT THE MOMENT, PLAY IS PERMITTED UNDER ALL CIRCUMSTANCES.

Bool protct_(int * x) {
// System generated locals
   Bool ret_val;

   ret_val = true;
   return ret_val;
}
