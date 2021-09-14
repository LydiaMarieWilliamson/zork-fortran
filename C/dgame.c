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

// Table of constant values

static int c__1 = 1;
static int c__3 = 3;
static Bool c_true = true;
static int c__0 = 0;
static int c__571 = 571;
static Bool c_false = false;
static int c__602 = 602;
static int c__341 = 341;
static int c__2 = 2;

// GAME- MAIN COMMAND LOOP FOR DUNGEON

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Void game_(void) {
// Initialized data

   static char secho[1 * 4] = "E" "C" "H" "O";

// Format strings
   static char fmt_1410[] = "(1x,78a1)";

// System generated locals
   int i__1;

// Builtin functions
   int s_wsfe(cilist *), do_fio(int *, char *, ftnlen), e_wsfe(void);

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern Void rspeak_(int *), rdline_(char *, int *, int *, ftnlen), xendmv_(Bool *), valuac_(int *);
   extern int oactor_(int *);
   static Bool f;
   static int i__, j;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
   extern Bool lit_(int *);
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define rrand ((int *)&rooms_1 + 602)
   extern Bool parse_(char *, int *, Bool *, ftnlen), aappli_(int *);
#define objvec ((int *)&pv_1 + 1)
   extern Bool rmdesc_(int *), xvehic_(int *), rappli_(int *), vappli_(int *), findxt_(int *, int *);
#define prpvec ((int *)&pv_1 + 3)

// Fortran I/O blocks
   static cilist io___15 = { 0, 0, 0, fmt_1410, 0 };

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// I/O VARIABLES

// ROOMS

// OBJECTS

// ADVENTURERS

// VERBS

// FUNCTIONS AND DATA

// FLAGS

// D	DATA GDTSTR/'G','D','T'/
// GAME, PAGE 2

// START UP, DESCRIBE CURRENT LOCATION.

   rspeak_(&c__1);
// 						!WELCOME ABOARD.
   f = rmdesc_(&c__3);
// 						!START GAME.

// NOW LOOP, READING AND EXECUTING COMMANDS.

L100:
   play_1.winner = aindex_1.player;
// 						!PLAYER MOVING.
   play_1.telflg = false;
// 						!ASSUME NOTHING TOLD.
   if (prsvec_1.prscon <= 1) {
      rdline_(input_1.inbuf, &input_1.inlnt, &c__1, (ftnlen) 1);
   }

// D   DO 150 I=1,3
//                                             !CALL ON GDT?
// D     IF(INBUF(I+PRSCON-1).NE.GDTSTR(I)) GO TO 200
// D150        CONTINUE
// D   CALL GDT
//                                             !YES, INVOKE.
// D   GO TO 100
//                                             !ONWARD.

//L200:
   ++state_1.moves;
   prsvec_1.prswon = parse_(input_1.inbuf, &input_1.inlnt, &c_true, (ftnlen)1);
   if (!prsvec_1.prswon) {
      goto L400;
   }
// 						!PARSE LOSES?
   if (xvehic_(&c__1)) {
      goto L400;
   }
// 						!VEHICLE HANDLE?

   if (prsvec_1.prsa == vindex_1.tellw) {
      goto L2000;
   }
// 						!TELL?
L300:
   if (prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every) {
      goto L900;
   }
   if (!vappli_(&prsvec_1.prsa)) {
      goto L400;
   }
// 						!VERB OK?
L350:
   if (!findex_1.echof && play_1.here == rindex_1.echor) {
      goto L1000;
   }
   f = rappli_(&rooms_1.ractio[play_1.here - 1]);

L400:
   xendmv_(&play_1.telflg);
// 						!DO END OF MOVE.
   if (!lit_(&play_1.here)) {
      prsvec_1.prscon = 1;
   }
   goto L100;

L900:
   valuac_(&oindex_1.valua);
   goto L350;
// GAME, PAGE 3

// SPECIAL CASE-- ECHO ROOM.
// IF INPUT IS NOT 'ECHO' OR A DIRECTION, JUST ECHO.

L1000:
   rdline_(input_1.inbuf, &input_1.inlnt, &c__0, (ftnlen) 1);
   ++state_1.moves;
// 						!CHARGE FOR MOVES.
   for (i__ = 1; i__ <= 4; ++i__) {
// 						!INPUT = ECHO?
      if (*(unsigned char *)&input_1.inbuf[i__ - 1] != *(unsigned char *)&secho[i__ - 1]) {
         goto L1300;
      }
// L1100:
   }

//   Note: the following DO loop was changed from DO 1200 I=5,78
//     The change was necessary because the RDLINE function was changed,
//      and no longer provides a 78 character buffer padded with blanks.

   i__1 = input_1.inlnt;
   for (i__ = 5; i__ <= i__1; ++i__) {
      if (*(unsigned char *)&input_1.inbuf[i__ - 1] != ' ') {
         goto L1300;
      }
// L1200:
   }

   rspeak_(&c__571);
// 						!KILL THE ECHO.
   findex_1.echof = true;
   objcts_1.oflag2[oindex_1.bar - 1] &= ~oflags_1.scrdbt;
   prsvec_1.prswon = true;
// 						!FAKE OUT PARSER.
   prsvec_1.prscon = 1;
// 						!FORCE NEW INPUT.
   goto L400;

L1300:
   prsvec_1.prswon = parse_(input_1.inbuf, &input_1.inlnt, &c_false, (ftnlen)1);
   if (!prsvec_1.prswon || prsvec_1.prsa != vindex_1.walkw) {
      goto L1400;
   }
   if (findxt_(&prsvec_1.prso, &play_1.here)) {
      goto L300;
   }
// 						!VALID EXIT?

L1400:
   io___15.ciunit = chan_1.outch;
   s_wsfe(&io___15);
   i__1 = input_1.inlnt;
   for (j = 1; j <= i__1; ++j) {
      do_fio(&c__1, input_1.inbuf + (j - 1), (ftnlen) 1);
   }
   e_wsfe();
   play_1.telflg = true;
// 						!INDICATE OUTPUT.
   goto L1000;
// 						!MORE ECHO ROOM.
// GAME, PAGE 4

// SPECIAL CASE-- TELL <ACTOR>, NEW COMMAND
// NOTE THAT WE CANNOT BE IN THE ECHO ROOM.

L2000:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.actrbt) != 0) {
      goto L2100;
   }
   rspeak_(&c__602);
// 						!CANT DO IT.
   goto L350;
// 						!VAPPLI SUCCEEDS.

L2100:
   play_1.winner = oactor_(&prsvec_1.prso);
// 						!NEW PLAYER.
   play_1.here = advs_1.aroom[play_1.winner - 1];
// 						!NEW LOCATION.
   if (prsvec_1.prscon <= 1) {
      goto L2700;
   }
// 						!ANY INPUT?
   if (parse_(input_1.inbuf, &input_1.inlnt, &c_true, (ftnlen) 1)) {
      goto L2150;
   }
L2700:
   i__ = 341;
// 						!FAILS.
   if (play_1.telflg) {
      i__ = 604;
   }
// 						!GIVE RESPONSE.
   rspeak_(&i__);
L2600:
   play_1.winner = aindex_1.player;
// 						!RESTORE STATE.
   play_1.here = advs_1.aroom[play_1.winner - 1];
   goto L350;

L2150:
   if (aappli_(&advs_1.aactio[play_1.winner - 1])) {
      goto L2400;
   }
// 						!ACTOR HANDLE?
   if (xvehic_(&c__1)) {
      goto L2400;
   }
// 						!VEHICLE HANDLE?
   if (prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every) {
      goto L2900;
   }
   if (!vappli_(&prsvec_1.prsa)) {
      goto L2400;
   }
// 						!VERB HANDLE?
//L2350:
   f = rappli_(&rooms_1.ractio[play_1.here - 1]);

L2400:
   xendmv_(&play_1.telflg);
// 						!DO END OF MOVE.
   goto L2600;
// 						!DONE.

L2900:
   valuac_(&oindex_1.valua);
// 						!ALL OR VALUABLES.
   goto L350;

}

#undef prpvec
#undef objvec
#undef rrand
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqa
#undef switch__
#undef flags

// XENDMV-	EXECUTE END OF MOVE FUNCTIONS.

// DECLARATIONS

Void xendmv_(Bool * flag__) {
// Local variables
   static Bool f;
   static int x;
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool clockd_(int *);
   extern Void thiefd_(void), fightd_(void);
#define objvec ((int *)&pv_1 + 1)
   extern Bool xvehic_(int *);
   extern Void rspeak_(int *);
#define prpvec ((int *)&pv_1 + 3)
   extern Void swordd_(void);

// PARSER OUTPUT

// PARSER STATE

// VILLAINS AND DEMONS

   if (!(*flag__)) {
      rspeak_(&c__341);
   }
// 						!DEFAULT REMARK.
   if (hack_1.thfact) {
      thiefd_();
   }
// 						!THIEF DEMON.
   if (prsvec_1.prswon) {
      fightd_();
   }
// 						!FIGHT DEMON.
   if (hack_1.swdact) {
      swordd_();
   }
// 						!SWORD DEMON.
   if (prsvec_1.prswon) {
      f = clockd_(&x);
   }
// 						!CLOCK DEMON.
   if (prsvec_1.prswon) {
      f = xvehic_(&c__2);
   }
// 						!VEHICLE READOUT.
   return 0;
}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqv

// XVEHIC- EXECUTE VEHICLE FUNCTION

// DECLARATIONS

Bool xvehic_(int * n) {
// System generated locals
   Bool ret_val;

// Local variables
   static int av;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
   extern Bool oappli_(int *, int *);

// GAME STATE

// OBJECTS

// ADVENTURERS

   ret_val = false;
// 						!ASSUME LOSES.
   av = advs_1.avehic[play_1.winner - 1];
// 						!GET VEHICLE.
   if (av != 0) {
      ret_val = oappli_(&objcts_1.oactio[av - 1], n);
   }
   return ret_val;
}

#undef eqo
#undef eqa
