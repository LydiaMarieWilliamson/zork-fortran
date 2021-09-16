#include "F2C.h"

// parser.h:

// PARSER OUTPUT

extern struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;
#define prsvec_1 prsvec_

// PARSER STATE

extern struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;
#define orphs_1 orphs_
#define orp ((int *)&orphs_1)

extern struct {
   int lastit;
} last_;
#define last_1 last_

extern struct {
   int act, o1, o2, p1, p2;
} pv_;
#define pv_1 pv_
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

extern struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;
#define syntax_1 syntax_
#define syn ((int *)&syntax_1)

extern struct {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;
#define synflg_1 synflg_

extern struct {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;
#define objflg_1 objflg_

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

extern struct {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;
#define screen_1 screen_

// mindex.h:

// MESSAGE INDEX

extern struct {
   int mlnt, rtext[1820];
} rmsg_;
#define rmsg_1 rmsg_

// star.h: (Unlisted)
extern struct {
   int mbase, strbit;
} star_;
#define star_1 star_

// vers.h: (Unlisted)
extern struct {
   int vmaj, vmin, vedit;
} vers_;
#define vers_1 vers_

// time.h: (Unlisted)
extern struct {
   int pltime, shour, smin, ssec;
} time_;
#define time_1 time_

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

// debug.h:

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;
#define debug_1 debug_

// hyper.h: (Unlisted)
extern struct {
   int hfactr;
} hyper_;
#define hyper_1 hyper_

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

// rindex.h:

extern struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;
#define rindex_1 rindex_

// exits.h:

// EXITS

extern struct {
   int xlnt, travel[900];
} exits_;
#define exits_1 exits_

// curxt.h:

// CURRENT EXITS

extern struct {
   int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;
#define curxt_1 curxt_
#define xflag ((int *)&curxt_1 + 4)

// xpars.h:

extern struct {
   int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;
#define xpars_1 xpars_

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

extern struct {
   int astag;
} aflags_;
#define aflags_1 aflags_

extern struct {
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

// INIT-- DUNGEON INITIALIZATION SUBROUTINE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS
static Bool protct_(int);

Bool init_(int x) {
// Format strings
   static char fmt_0[] = "(\002 Suddenly a sinister, wraithlike figure appears before \002,\002you,\002/\002 seeming to float in the air.  In a low, sorrowful voice\002,\002 he says,\002/\002 \"Alas, the very nature of the world has changed, \002,\002and the dungeon\002/\002 cannot be found.  All must now pass away.\"\002,\002  Raising his oaken staff\002/\002 in farewell, he fades into the \002,\002spreading darkness.  In his place\002/\002 appears a tastefully \002,\002lettered sign reading:\002//23x,\002INITIALIZATION FAILURE\002//\002 The darkness becomes all encompassing, and your vision fails.\002)";

// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int xmax, r2max, dirmax, recno;
   extern void intime_(int *, int *, int *);
   extern void inirnd_(int);
   static int i__, j, k;
   extern void exit_(void);
   static int mmax, omax, rmax, vmax, amax, cmax, fmax, smax;

// MISCELLANEOUS VARIABLES

// INIT, PAGE 2

// FIRST CHECK FOR PROTECTION VIOLATION

   if (protct_(x)) {
      goto L10000;
   }
// 						!PROTECTION VIOLATION?
   BegExSF(6, /*10100*/"(\002 There appears before you a threatening figure clad \002,\002all over\002/\002 in heavy black armor.  His legs seem like the \002,\002massive trunk\002/\002 of the oak tree.  His broad shoulders and \002,\002helmeted head loom\002/\002 high over your own puny frame, and \002,\002you realize that his powerful\002/\002 arms could easily crush the \002,\002very life from your body.  There\002/\002 hangs from his belt a \002,\002veritable arsenal of deadly weapons:\002/\002 sword, mace, ball \002,\002and chain, dagger, lance, and trident.\002/\002 He speaks with a \002,\002commanding voice:\002//20x,\002\"You shall not pass.\"\002//\002 As \002,\002he grabs you by the neck all grows dim about you.\002)", 0);
   EndExSF();
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
   i__1 = OpenF(1, "dindx.dat", "OLD", "SEQUENTIAL", "FORMATTED", 0);
   if (i__1 != 0) {
      goto L1900;
   }

   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &i__, sizeof i__);
   DoFio(1, &j, sizeof j);
   DoFio(1, &k, sizeof k);
   EndInSF();
// 						!GET VERSION.
   if (i__ != vers_1.vmaj || j != vers_1.vmin) {
      goto L1925;
   }
// 	OPEN(UNIT=DBCH,file='/usr/share/games/dungeon/dtext.dat',
   i__1 = OpenF(chan_1.dbch, "dtext.dat", "OLD", "DIRECT", "UNFORMATTED", 76);
   if (i__1 != 0) {
      goto L1950;
   }
// D	PRINT 150
// D150	FORMAT(' RESTORING FROM "dindx.dat"')
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &state_1.mxscor, sizeof state_1.mxscor);
   DoFio(1, &star_1.strbit, sizeof star_1.strbit);
   DoFio(1, &state_1.egmxsc, sizeof state_1.egmxsc);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &rooms_1.rlnt, sizeof rooms_1.rlnt);
   DoFio(1, &rooms_1.rdesc2, sizeof rooms_1.rdesc2);
   DoFio(200, rooms_1.rdesc1, sizeof rooms_1.rdesc1[0]);
   DoFio(200, rooms_1.rexit, sizeof rooms_1.rexit[0]);
   DoFio(200, rooms_1.ractio, sizeof rooms_1.ractio[0]);
   DoFio(200, rooms_1.rval, sizeof rooms_1.rval[0]);
   DoFio(200, rooms_1.rflag, sizeof rooms_1.rflag[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &exits_1.xlnt, sizeof exits_1.xlnt);
   DoFio(900, exits_1.travel, sizeof exits_1.travel[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &objcts_1.olnt, sizeof objcts_1.olnt);
   DoFio(220, objcts_1.odesc1, sizeof objcts_1.odesc1[0]);
   DoFio(220, objcts_1.odesc2, sizeof objcts_1.odesc2[0]);
   DoFio(220, objcts_1.odesco, sizeof objcts_1.odesco[0]);
   DoFio(220, objcts_1.oactio, sizeof objcts_1.oactio[0]);
   DoFio(220, objcts_1.oflag1, sizeof objcts_1.oflag1[0]);
   DoFio(220, objcts_1.oflag2, sizeof objcts_1.oflag2[0]);
   DoFio(220, objcts_1.ofval, sizeof objcts_1.ofval[0]);
   DoFio(220, objcts_1.otval, sizeof objcts_1.otval[0]);
   DoFio(220, objcts_1.osize, sizeof objcts_1.osize[0]);
   DoFio(220, objcts_1.ocapac, sizeof objcts_1.ocapac[0]);
   DoFio(220, objcts_1.oroom, sizeof objcts_1.oroom[0]);
   DoFio(220, objcts_1.oadv, sizeof objcts_1.oadv[0]);
   DoFio(220, objcts_1.ocan, sizeof objcts_1.ocan[0]);
   DoFio(220, objcts_1.oread, sizeof objcts_1.oread[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &oroom2_1.r2lnt, sizeof oroom2_1.r2lnt);
   DoFio(20, oroom2_1.oroom2, sizeof oroom2_1.oroom2[0]);
   DoFio(20, oroom2_1.rroom2, sizeof oroom2_1.rroom2[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &cevent_1.clnt, sizeof cevent_1.clnt);
   DoFio(25, cevent_1.ctick, sizeof cevent_1.ctick[0]);
   DoFio(25, cevent_1.cactio, sizeof cevent_1.cactio[0]);
   EndInSF();
   BegInSF(1, /*135*/"(l4)", 0);
   DoFio(25, cevent_1.cflag, sizeof cevent_1.cflag[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &vill_1.vlnt, sizeof vill_1.vlnt);
   DoFio(4, vill_1.villns, sizeof vill_1.villns[0]);
   DoFio(4, vill_1.vprob, sizeof vill_1.vprob[0]);
   DoFio(4, vill_1.vopps, sizeof vill_1.vopps[0]);
   DoFio(4, vill_1.vbest, sizeof vill_1.vbest[0]);
   DoFio(4, vill_1.vmelee, sizeof vill_1.vmelee[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &advs_1.alnt, sizeof advs_1.alnt);
   DoFio(4, advs_1.aroom, sizeof advs_1.aroom[0]);
   DoFio(4, advs_1.ascore, sizeof advs_1.ascore[0]);
   DoFio(4, advs_1.avehic, sizeof advs_1.avehic[0]);
   DoFio(4, advs_1.aobj, sizeof advs_1.aobj[0]);
   DoFio(4, advs_1.aactio, sizeof advs_1.aactio[0]);
   DoFio(4, advs_1.astren, sizeof advs_1.astren[0]);
   DoFio(4, advs_1.aflag, sizeof advs_1.aflag[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &star_1.mbase, sizeof star_1.mbase);
   DoFio(1, &rmsg_1.mlnt, sizeof rmsg_1.mlnt);
   DoFio(1820, rmsg_1.rtext, sizeof rmsg_1.rtext[0]);
   EndInSF();

   CloseF(1);
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
   inirnd_(i__1);

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
   BegExSF(6, /*910*/"(\002 I can't open \002,\002dindx.dat\002,\002.\002)", 0);
   EndExSF();
   BegExSF(6, /*980*/fmt_0, 0);
   EndExSF();
   return ret_val;
L1925:
   BegExSF(6, /*920*/"(\002 \"dindx.dat\" is version \002,i1,\002.\002,i1,a1,\002.\002/\002 I require version \002,i1,\002.\002,i1,a1,\002.\002)", 0);
   DoFio(1, &i__, sizeof i__);
   DoFio(1, &j, sizeof j);
   DoFio(1, &k, sizeof k);
   DoFio(1, &vers_1.vmaj, sizeof vers_1.vmaj);
   DoFio(1, &vers_1.vmin, sizeof vers_1.vmin);
   DoFio(1, &vers_1.vedit, sizeof vers_1.vedit);
   EndExSF();
   BegExSF(6, /*980*/fmt_0, 0);
   EndExSF();
   return ret_val;
L1950:
   BegExSF(6, /*960*/"(\002 I can't open \002,\002dtext.dat\002,\002.\002)", 0);
   EndExSF();
   BegExSF(6, /*980*/fmt_0, 0);
   EndExSF();
   return ret_val;

}

// PROTCT-- CHECK FOR USER VIOLATION

// THIS ROUTINE SHOULD BE MODIFIED IF YOU WISH TO ADD SYSTEM
// DEPENDANT PROTECTION AGAINST ABUSE.

// AT THE MOMENT, PLAY IS PERMITTED UNDER ALL CIRCUMSTANCES.

static Bool protct_(int x) {
// System generated locals
   Bool ret_val;

   ret_val = true;
   return ret_val;
}
