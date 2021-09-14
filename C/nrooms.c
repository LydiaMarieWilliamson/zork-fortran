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
   int inlnt;
   char inbuf[78];
} input_;

#define input_1 input_

struct {
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

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
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

struct {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;

#define xsrch_1 xsrch_

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
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// Table of constant values

static int c__70 = 70;
static int c__0 = 0;
static int c__682 = 682;
static int c__681 = 681;
static int c__685 = 685;
static int c__683 = 683;
static int c__684 = 684;
static int c__686 = 686;
static int c__687 = 687;
static int c__688 = 688;
static int c__694 = 694;
static int c__705 = 705;
static int c__706 = 706;
static int c__707 = 707;
static int c__708 = 708;
static int c__709 = 709;
static int c__710 = 710;
static int c__711 = 711;
static int c__712 = 712;
static int c__723 = 723;
static int c__724 = 724;
static int c__725 = 725;
static int c__726 = 726;
static Bool c_false = false;
static int c__792 = 792;
static int c__868 = 868;
static int c__869 = 869;
static int c__880 = 880;
static int c__847 = 847;
static int c__848 = 848;
static int c__851 = 851;
static int c__825 = 825;

// RAPPL2- SPECIAL PURPOSE ROOM ROUTINES, PART 2

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool rappl2_(int * ri) {
// Initialized data

   static int newrms = 38;

// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void lookto_(int *, int *, int *, int *, int *), jigsup_(int *), ewtell_(int *, int *), rspeak_(int *);
   static int i__;
   extern Void rspsub_(int *, int *);
   static int j;
   extern Void rspsb2_(int *, int *, int *), score_(Bool *), cpinfo_(int *, int *);
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
   extern Void bug_(int *, int *);
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Void exit_(void);
   extern Bool qhere_(int *, int *);
#define rrand ((int *)&rooms_1 + 602)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// I/O VARIABLES

// ROOMS

// OBJECTS

// CLOCK INTERRUPTS

// ADVENTURERS

// VERBS

// FUNCTIONS AND DATA

// FLAGS

// RAPPL2, PAGE 2

   ret_val = true;
   switch (*ri - newrms + 1) {
      case 1:
         goto L38000;
      case 2:
         goto L39000;
      case 3:
         goto L40000;
      case 4:
         goto L41000;
      case 5:
         goto L42000;
      case 6:
         goto L43000;
      case 7:
         goto L44000;
      case 8:
         goto L45000;
      case 9:
         goto L46000;
      case 10:
         goto L47000;
      case 11:
         goto L48000;
      case 12:
         goto L49000;
      case 13:
         goto L50000;
      case 14:
         goto L51000;
      case 15:
         goto L52000;
      case 16:
         goto L53000;
      case 17:
         goto L54000;
      case 18:
         goto L55000;
      case 19:
         goto L56000;
      case 20:
         goto L57000;
      case 21:
         goto L58000;
      case 22:
         goto L59000;
      case 23:
         goto L60000;
   }
   bug_(&c__70, ri);
   return ret_val;

// R38--	MIRROR D ROOM

L38000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      lookto_(&rindex_1.fdoor, &rindex_1.mrg, &c__0, &c__682, &c__681);
   }
   return ret_val;

// R39--	MIRROR G ROOM

L39000:
   if (prsvec_1.prsa == vindex_1.walkiw) {
      jigsup_(&c__685);
   }
   return ret_val;

// R40--	MIRROR C ROOM

L40000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      lookto_(&rindex_1.mrg, &rindex_1.mrb, &c__683, &c__0, &c__681);
   }
   return ret_val;

// R41--	MIRROR B ROOM

L41000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      lookto_(&rindex_1.mrc, &rindex_1.mra, &c__0, &c__0, &c__681);
   }
   return ret_val;

// R42--	MIRROR A ROOM

L42000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      lookto_(&rindex_1.mrb, &c__0, &c__0, &c__684, &c__681);
   }
   return ret_val;
// RAPPL2, PAGE 3

// R43--	MIRROR C EAST/WEST

L43000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      ewtell_(&play_1.here, &c__683);
   }
   return ret_val;

// R44--	MIRROR B EAST/WEST

L44000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      ewtell_(&play_1.here, &c__686);
   }
   return ret_val;

// R45--	MIRROR A EAST/WEST

L45000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      ewtell_(&play_1.here, &c__687);
   }
   return ret_val;

// R46--	INSIDE MIRROR

L46000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__688);
// 						!DESCRIBE

// NOW DESCRIBE POLE STATE.

// CASES 1,2--	MDIR=270 & MLOC=MRB, POLE IS UP OR IN HOLE
// CASES 3,4--	MDIR=0 V MDIR=180, POLE IS UP OR IN CHANNEL
// CASE 5--	POLE IS UP

   i__ = 689;
// 						!ASSUME CASE 5.
   if (findex_1.mdir == 270 && findex_1.mloc == rindex_1.mrb) {
      i__ = min(findex_1.poleuf, 1) + 690;
   }
   if (findex_1.mdir % 180 == 0) {
      i__ = min(findex_1.poleuf, 1) + 692;
   }
   rspeak_(&i__);
// 						!DESCRIBE POLE.
   i__1 = findex_1.mdir / 45 + 695;
   rspsub_(&c__694, &i__1);
// 						!DESCRIBE ARROW.
   return ret_val;
// RAPPL2, PAGE 4

// R47--	MIRROR EYE ROOM

L47000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 704;
// 						!ASSUME BEAM STOP.
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
      if (qhere_(&j, &play_1.here) && j != oindex_1.rbeam) {
         goto L47200;
      }
// L47100:
   }
   i__ = 703;
L47200:
   rspsub_(&i__, &objcts_1.odesc2[j - 1]);
// 						!DESCRIBE BEAM.
   lookto_(&rindex_1.mra, &c__0, &c__0, &c__0, &c__0);
// 						!LOOK NORTH.
   return ret_val;

// R48--	INSIDE CRYPT

L48000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 46;
// 						!CRYPT IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.tomb - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
   rspsub_(&c__705, &i__);
   return ret_val;

// R49--	SOUTH CORRIDOR

L49000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   rspeak_(&c__706);
// 						!DESCRIBE.
   i__ = 46;
// 						!ODOOR IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.odoor - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
   if (findex_1.lcell == 4) {
      rspsub_(&c__707, &i__);
   }
// 						!DESCRIBE ODOOR IF THERE.
   return ret_val;

// R50--	BEHIND DOOR

L50000:
   if (prsvec_1.prsa != vindex_1.walkiw) {
      goto L50100;
   }
// 						!WALK IN?
   cevent_1.cflag[cindex_1.cevfol - 1] = true;
// 						!MASTER FOLLOWS.
   cevent_1.ctick[cindex_1.cevfol - 1] = -1;
   return ret_val;

L50100:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 46;
// 						!QDOOR IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.qdoor - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
   rspsub_(&c__708, &i__);
   return ret_val;
// RAPPL2, PAGE 5

// R51--	FRONT DOOR

L51000:
   if (prsvec_1.prsa == vindex_1.walkiw) {
      cevent_1.ctick[cindex_1.cevfol - 1] = 0;
   }
// 						!IF EXITS, KILL FOLLOW.
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   lookto_(&c__0, &rindex_1.mrd, &c__709, &c__0, &c__0);
// 						!DESCRIBE SOUTH.
   i__ = 46;
// 						!PANEL IS OPEN/CLOSED.
   if (findex_1.inqstf) {
      i__ = 12;
   }
// 						!OPEN IF INQ STARTED.
   j = 46;
// 						!QDOOR IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.qdoor - 1] & oflags_1.openbt) != 0) {
      j = 12;
   }
   rspsb2_(&c__710, &i__, &j);
   return ret_val;

// R52--	NORTH CORRIDOR

L52000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 46;
   if ((objcts_1.oflag2[oindex_1.cdoor - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
// 						!CDOOR IS OPEN/CLOSED.
   rspsub_(&c__711, &i__);
   return ret_val;

// R53--	PARAPET

L53000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      i__1 = findex_1.pnumb + 712;
      rspsub_(&c__712, &i__1);
   }
   return ret_val;

// R54--	CELL

L54000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 721;
// 						!CDOOR IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.cdoor - 1] & oflags_1.openbt) != 0) {
      i__ = 722;
   }
   rspeak_(&i__);
   i__ = 46;
// 						!ODOOR IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.odoor - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
   if (findex_1.lcell == 4) {
      rspsub_(&c__723, &i__);
   }
// 						!DESCRIBE.
   return ret_val;

// R55--	PRISON CELL

L55000:
   if (prsvec_1.prsa == vindex_1.lookw) {
      rspeak_(&c__724);
   }
// 						!LOOK?
   return ret_val;

// R56--	NIRVANA CELL

L56000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 46;
// 						!ODOOR IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.odoor - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
   rspsub_(&c__725, &i__);
   return ret_val;
// RAPPL2, PAGE 6

// R57--	NIRVANA AND END OF GAME

L57000:
   if (prsvec_1.prsa != vindex_1.walkiw) {
      return ret_val;
   }
// 						!WALKIN?
   rspeak_(&c__726);
   score_(&c_false);
// moved to exit routine	CLOSE(DBCH)
   exit_();

// R58--	TOMB ROOM

L58000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 46;
// 						!TOMB IS OPEN/CLOSED.
   if ((objcts_1.oflag2[oindex_1.tomb - 1] & oflags_1.openbt) != 0) {
      i__ = 12;
   }
   rspsub_(&c__792, &i__);
   return ret_val;

// R59--	PUZZLE SIDE ROOM

L59000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   i__ = 861;
// 						!ASSUME DOOR CLOSED.
   if (findex_1.cpoutf) {
      i__ = 862;
   }
// 						!OPEN?
   rspeak_(&i__);
// 						!DESCRIBE.
   return ret_val;

// R60--	PUZZLE ROOM

L60000:
   if (prsvec_1.prsa != vindex_1.lookw) {
      return ret_val;
   }
// 						!LOOK?
   if (findex_1.cpushf) {
      goto L60100;
   }
// 						!STARTED PUZZLE?
   rspeak_(&c__868);
// 						!NO, DESCRIBE.
   if ((objcts_1.oflag2[oindex_1.warni - 1] & oflags_1.tchbt) != 0) {
      rspeak_(&c__869);
   }
   return ret_val;

L60100:
   cpinfo_(&c__880, &findex_1.cphere);
// 						!DESCRIBE ROOM.
   return ret_val;

}

#undef prpvec
#undef objvec
#undef rrand
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqc
#undef eqa
#undef switch__
#undef flags

// LOOKTO--	DESCRIBE VIEW IN MIRROR HALLWAY

// DECLARATIONS

Void lookto_(int * nrm, int * srm, int * nt, int * st, int * ht) {
// System generated locals
   int i__1;

// Local variables
   static int i__, m1, dir, mrbf;
#define flags ((Bool *)&findex_1)
   extern Void rspsb2_(int *, int *, int *);
   extern int mrhere_(int *);
   extern Void rspeak_(int *);
#define switch__ ((int *)&findex_1 + 46)
   extern Void rspsub_(int *, int *);

// GAME STATE

// LOOKTO, PAGE 2

// FLAGS

   rspeak_(ht);
// 						!DESCRIBE HALL.
   rspeak_(nt);
// 						!DESCRIBE NORTH VIEW.
   rspeak_(st);
// 						!DESCRIBE SOUTH VIEW.
   dir = 0;
// 						!ASSUME NO DIRECTION.
   if ((i__1 = findex_1.mloc - play_1.here, abs(i__1)) != 1) {
      goto L200;
   }
// 						!MIRROR TO N OR S?
   if (findex_1.mloc == *nrm) {
      dir = 695;
   }
   if (findex_1.mloc == *srm) {
      dir = 699;
   }
// 						!DIR=N/S.
   if (findex_1.mdir % 180 != 0) {
      goto L100;
   }
// 						!MIRROR N-S?
   rspsub_(&c__847, &dir);
// 						!YES, HE SEES PANEL
   rspsb2_(&c__848, &dir, &dir);
// 						!AND NARROW ROOMS.
   goto L200;

L100:
   m1 = mrhere_(&play_1.here);
// 						!WHICH MIRROR?
   mrbf = 0;
// 						!ASSUME INTACT.
   if (m1 == 1 && !findex_1.mr1f || m1 == 2 && !findex_1.mr2f) {
      mrbf = 1;
   }
   i__1 = mrbf + 849;
   rspsub_(&i__1, &dir);
// 						!DESCRIBE.
   if (m1 == 1 && findex_1.mropnf) {
      i__1 = mrbf + 823;
      rspeak_(&i__1);
   }
   if (mrbf != 0) {
      rspeak_(&c__851);
   }

L200:
   i__ = 0;
// 						!ASSUME NO MORE TO DO.
   if (*nt == 0 && (dir == 0 || dir == 699)) {
      i__ = 852;
   }
   if (*st == 0 && (dir == 0 || dir == 695)) {
      i__ = 853;
   }
   if (*nt + *st + dir == 0) {
      i__ = 854;
   }
   if (*ht != 0) {
      rspeak_(&i__);
   }
// 						!DESCRIBE HALLS.
   return 0;

}

#undef switch__
#undef flags

// EWTELL--	DESCRIBE E/W NARROW ROOMS

// DECLARATIONS

Void ewtell_(int * rm, int * st) {
// System generated locals
   int i__1;

// Local variables
   static int i__;
   static Bool m1;
#define flags ((Bool *)&findex_1)
   extern Void rspeak_(int *);
#define switch__ ((int *)&findex_1 + 46)

// ROOMS

// EWTELL, PAGE 2

// NOTE THAT WE ARE EAST OR WEST OF MIRROR, AND
// MIRROR MUST BE N-S.

// FLAGS

   m1 = findex_1.mdir + (*rm - rindex_1.mrae) % 2 * 180 == 180;
   i__ = (*rm - rindex_1.mrae) % 2 + 819;
// 						!GET BASIC E/W STRING.
   if (m1 && !findex_1.mr1f || !m1 && !findex_1.mr2f) {
      i__ += 2;
   }
   rspeak_(&i__);
   if (m1 && findex_1.mropnf) {
      i__1 = (i__ - 819) / 2 + 823;
      rspeak_(&i__1);
   }
   rspeak_(&c__825);
   rspeak_(st);
   return 0;

}

#undef switch__
#undef flags
