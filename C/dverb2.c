/*  -- translated by f2c (version 20190311).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
   integer prsa, prsi, prso;
   logical prswon;
   integer prscon;
} prsvec_;

#define prsvec_1 prsvec_

struct {
   integer oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

struct {
   integer lastit;
} last_;

#define last_1 last_

struct {
   integer act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

struct {
   integer vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

struct {
   integer sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

struct {
   integer vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

struct {
   integer winner, here;
   logical telflg;
} play_;

#define play_1 play_

struct {
   integer moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

struct {
   integer fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;

#define screen_1 screen_

struct {
   integer cpdr[16], cpwl[8], cpvec[64];
} puzzle_;

#define puzzle_1 puzzle_

struct {
   integer rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct {
   integer xlnt, travel[900];
} exits_;

#define exits_1 exits_

struct {
   integer olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   integer r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct {
   integer clnt, ctick[25], cactio[25];
   logical cflag[25];
} cevent_;

#define cevent_1 cevent_

struct {
   integer cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

struct {
   integer thfpos;
   logical thfflg, thfact, swdact;
   integer swdsta;
} hack_;

#define hack_1 hack_

struct {
   integer vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_

struct {
   integer alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

struct {
   integer astag;
} aflags_;

#define aflags_1 aflags_

struct {
   integer player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

struct {
   logical trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf,
      frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   integer btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

struct {
   integer vmaj, vmin, vedit;
} vers_;

#define vers_1 vers_

struct {
   integer pltime, shour, smin, ssec;
} time_;

#define time_1 time_

struct {
   integer rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

struct {
   integer xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_

struct {
   integer xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;

#define xsrch_1 xsrch_

struct {
   integer visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt,
      schbt;
} oflags_;

#define oflags_1 oflags_

struct {
   integer whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls,
      mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw,
      mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

struct {
   integer xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;

#define xpars_1 xpars_

struct {
   integer garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw,
      cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage,
      spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs,
      sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

/* Table of constant values */

static integer c__1 = 1;
static integer c__64 = 64;
static integer c__220 = 220;
static integer c__200 = 200;
static integer c__4 = 4;
static integer c__46 = 46;
static integer c__22 = 22;
static integer c__25 = 25;
static integer c__597 = 597;
static integer c__598 = 598;
static integer c__599 = 599;
static integer c__600 = 600;
static integer c__9 = 9;
static integer c__523 = 523;
static integer c__522 = 522;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c__121 = 121;
static integer c__8 = 8;
static integer c__818 = 818;
static integer c__882 = 882;

/* SAVE- SAVE GAME STATE */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* DECLARATIONS */

/* Subroutine */ int savegm_(void) {
/* System generated locals */
   integer i__1;
   olist o__1;
   cllist cl__1;

/* Builtin functions */
   integer f_open(olist *), s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void), f_clos(cllist *);

/* Local variables */
   static integer i__;
#define eqa ((integer *)&advs_1 + 1)
#define eqc ((integer *)&cevent_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
#define eqv ((integer *)&vill_1 + 1)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
#define flags ((logical *)&findex_1)
#define rrand ((integer *)&rooms_1 + 602)
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
#define switch__ ((integer *)&findex_1 + 46)
   extern /* Subroutine */ int gttime_(integer *), rspeak_(integer *);

/* Fortran I/O blocks */
   static cilist io___15 = { 0, 1, 0, 0, 0 };
   static cilist io___16 = { 0, 1, 0, 0, 0 };
   static cilist io___17 = { 0, 1, 0, 0, 0 };
   static cilist io___18 = { 0, 1, 0, 0, 0 };
   static cilist io___19 = { 0, 1, 0, 0, 0 };
   static cilist io___20 = { 0, 1, 0, 0, 0 };
   static cilist io___21 = { 0, 1, 0, 0, 0 };

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* SCREEN OF LIGHT */

/* PUZZLE ROOM STATE */

/* ROOMS */

/* EXITS */

/* OBJECTS */

/* CLOCK INTERRUPTS */

/* VILLAINS AND DEMONS */

/* ADVENTURERS */

/* MISCELLANEOUS VARIABLES */

/* FLAGS */

   prsvec_1.prswon = FALSE_;
/* 						!DISABLE GAME. */
/* Note: save file format is different for PDP vs. non-PDP versions */

   o__1.oerr = 1;
   o__1.ounit = 1;
   o__1.ofnmlen = 9;
   o__1.ofnm = "dsave.dat";
   o__1.orl = 0;
   o__1.osta = "UNKNOWN";
   o__1.oacc = "SEQUENTIAL";
   o__1.ofm = "UNFORMATTED";
   o__1.oblnk = 0;
   i__1 = f_open(&o__1);
   if (i__1 != 0) {
      goto L100;
   }

   gttime_(&i__);
/* 						!GET TIME. */
   s_wsue(&io___15);
   do_uio(&c__1, (char *)&vers_1.vmaj, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&vers_1.vmin, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&vers_1.vedit, (ftnlen) sizeof(integer));
   e_wsue();
   s_wsue(&io___16);
   do_uio(&c__1, (char *)&play_1.winner, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&play_1.here, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&hack_1.thfpos, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&play_1.telflg, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.thfflg, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.thfact, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.swdact, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.swdsta, (ftnlen) sizeof(integer));
   do_uio(&c__64, (char *)&puzzle_1.cpvec[0], (ftnlen) sizeof(integer));
   e_wsue();
   s_wsue(&io___17);
   do_uio(&c__1, (char *)&i__, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.moves, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.deaths, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.rwscor, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.egscor, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.mxload, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.ltshft, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.bloc, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.mungrm, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.hs, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&screen_1.fromdr, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&screen_1.scolrm, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&screen_1.scolac, (ftnlen) sizeof(integer));
   e_wsue();
   s_wsue(&io___18);
   do_uio(&c__220, (char *)&objcts_1.odesc1[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.odesc2[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oflag1[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oflag2[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.ofval[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.otval[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.osize[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.ocapac[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oroom[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oadv[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.ocan[0], (ftnlen) sizeof(integer));
   e_wsue();
   s_wsue(&io___19);
   do_uio(&c__200, (char *)&rooms_1.rval[0], (ftnlen) sizeof(integer));
   do_uio(&c__200, (char *)&rooms_1.rflag[0], (ftnlen) sizeof(integer));
   e_wsue();
   s_wsue(&io___20);
   do_uio(&c__4, (char *)&advs_1.aroom[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.ascore[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.avehic[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.astren[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.aflag[0], (ftnlen) sizeof(integer));
   e_wsue();
   s_wsue(&io___21);
   do_uio(&c__46, (char *)&flags[0], (ftnlen) sizeof(logical));
   do_uio(&c__22, (char *)&switch__[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&vill_1.vprob[0], (ftnlen) sizeof(integer));
   do_uio(&c__25, (char *)&cevent_1.cflag[0], (ftnlen) sizeof(logical));
   do_uio(&c__25, (char *)&cevent_1.ctick[0], (ftnlen) sizeof(integer));
   e_wsue();

   cl__1.cerr = 0;
   cl__1.cunit = 1;
   cl__1.csta = 0;
   f_clos(&cl__1);
   rspeak_(&c__597);
   return 0;

 L100:
   rspeak_(&c__598);
/* 						!CANT DO IT. */
   return 0;
} /* savegm_ */

#undef switch__
#undef prpvec
#undef objvec
#undef rrand
#undef flags
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqr
#undef eqo
#undef eqc
#undef eqa

/* RESTORE- RESTORE GAME STATE */

/* DECLARATIONS */

/* Subroutine */ int rstrgm_(void) {
/* System generated locals */
   integer i__1;
   olist o__1;
   cllist cl__1;

/* Builtin functions */
   integer f_open(olist *), s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void), f_clos(cllist *);

/* Local variables */
   static integer i__, j, k;
#define eqa ((integer *)&advs_1 + 1)
#define eqc ((integer *)&cevent_1 + 1)
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
#define eqv ((integer *)&vill_1 + 1)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
#define flags ((logical *)&findex_1)
#define rrand ((integer *)&rooms_1 + 602)
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
#define switch__ ((integer *)&findex_1 + 46)
   extern /* Subroutine */ int rspeak_(integer *);

/* Fortran I/O blocks */
   static cilist io___35 = { 0, 1, 0, 0, 0 };
   static cilist io___39 = { 0, 1, 0, 0, 0 };
   static cilist io___40 = { 0, 1, 0, 0, 0 };
   static cilist io___41 = { 0, 1, 0, 0, 0 };
   static cilist io___42 = { 0, 1, 0, 0, 0 };
   static cilist io___43 = { 0, 1, 0, 0, 0 };
   static cilist io___44 = { 0, 1, 0, 0, 0 };

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* SCREEN OF LIGHT */

/* PUZZLE ROOM STATE */

/* ROOMS */

/* EXITS */

/* OBJECTS */

/* CLOCK INTERRUPTS */

/* VILLAINS AND DEMONS */

/* ADVENTURERS */

/* MISCELLANEOUS VARIABLES */

/* FLAGS */

   prsvec_1.prswon = FALSE_;
/* 						!DISABLE GAME. */
/* Note: save file format is different for PDP vs. non-PDP versions */

   o__1.oerr = 1;
   o__1.ounit = 1;
   o__1.ofnmlen = 9;
   o__1.ofnm = "dsave.dat";
   o__1.orl = 0;
   o__1.osta = "OLD";
   o__1.oacc = "SEQUENTIAL";
   o__1.ofm = "UNFORMATTED";
   o__1.oblnk = 0;
   i__1 = f_open(&o__1);
   if (i__1 != 0) {
      goto L100;
   }

   s_rsue(&io___35);
   do_uio(&c__1, (char *)&i__, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&j, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&k, (ftnlen) sizeof(integer));
   e_rsue();
   if (i__ != vers_1.vmaj || j != vers_1.vmin) {
      goto L200;
   }

   s_rsue(&io___39);
   do_uio(&c__1, (char *)&play_1.winner, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&play_1.here, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&hack_1.thfpos, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&play_1.telflg, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.thfflg, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.thfact, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.swdact, (ftnlen) sizeof(logical));
   do_uio(&c__1, (char *)&hack_1.swdsta, (ftnlen) sizeof(integer));
   do_uio(&c__64, (char *)&puzzle_1.cpvec[0], (ftnlen) sizeof(integer));
   e_rsue();
   s_rsue(&io___40);
   do_uio(&c__1, (char *)&time_1.pltime, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.moves, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.deaths, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.rwscor, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.egscor, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.mxload, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.ltshft, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.bloc, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.mungrm, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&state_1.hs, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&screen_1.fromdr, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&screen_1.scolrm, (ftnlen) sizeof(integer));
   do_uio(&c__1, (char *)&screen_1.scolac, (ftnlen) sizeof(integer));
   e_rsue();
   s_rsue(&io___41);
   do_uio(&c__220, (char *)&objcts_1.odesc1[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.odesc2[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oflag1[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oflag2[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.ofval[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.otval[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.osize[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.ocapac[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oroom[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.oadv[0], (ftnlen) sizeof(integer));
   do_uio(&c__220, (char *)&objcts_1.ocan[0], (ftnlen) sizeof(integer));
   e_rsue();
   s_rsue(&io___42);
   do_uio(&c__200, (char *)&rooms_1.rval[0], (ftnlen) sizeof(integer));
   do_uio(&c__200, (char *)&rooms_1.rflag[0], (ftnlen) sizeof(integer));
   e_rsue();
   s_rsue(&io___43);
   do_uio(&c__4, (char *)&advs_1.aroom[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.ascore[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.avehic[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.astren[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&advs_1.aflag[0], (ftnlen) sizeof(integer));
   e_rsue();
   s_rsue(&io___44);
   do_uio(&c__46, (char *)&flags[0], (ftnlen) sizeof(logical));
   do_uio(&c__22, (char *)&switch__[0], (ftnlen) sizeof(integer));
   do_uio(&c__4, (char *)&vill_1.vprob[0], (ftnlen) sizeof(integer));
   do_uio(&c__25, (char *)&cevent_1.cflag[0], (ftnlen) sizeof(logical));
   do_uio(&c__25, (char *)&cevent_1.ctick[0], (ftnlen) sizeof(integer));
   e_rsue();

   cl__1.cerr = 0;
   cl__1.cunit = 1;
   cl__1.csta = 0;
   f_clos(&cl__1);
   rspeak_(&c__599);
   return 0;

 L100:
   rspeak_(&c__598);
/* 						!CANT DO IT. */
   return 0;

 L200:
   rspeak_(&c__600);
/* 						!OBSOLETE VERSION */
   cl__1.cerr = 0;
   cl__1.cunit = 1;
   cl__1.csta = 0;
   f_clos(&cl__1);
   return 0;
} /* rstrgm_ */

#undef switch__
#undef prpvec
#undef objvec
#undef rrand
#undef flags
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqr
#undef eqo
#undef eqc
#undef eqa

/* WALK- MOVE IN SPECIFIED DIRECTION */

/* DECLARATIONS */

logical walk_(integer * x) {
/* System generated locals */
   logical ret_val;

/* Local variables */
#define eqa ((integer *)&advs_1 + 1)
#define eqc ((integer *)&cevent_1 + 1)
   extern /* Subroutine */ int bug_(integer *, integer *);
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
   extern logical lit_(integer *);
#define eqv ((integer *)&vill_1 + 1)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
   extern logical prob_(integer *, integer *);
#define xflag ((integer *)&curxt_1 + 4)
#define rrand ((integer *)&rooms_1 + 602)
#define flags ((logical *)&findex_1)
#define objvec ((integer *)&pv_1 + 1)
   extern logical rmdesc_(integer *), findxt_(integer *, integer *);
#define prpvec ((integer *)&pv_1 + 3)
   extern logical moveto_(integer *, integer *);
#define switch__ ((integer *)&findex_1 + 46)
   extern integer cxappl_(integer *);
   extern /* Subroutine */ int jigsup_(integer *), rspeak_(integer *), rspsub_(integer *, integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* ROOMS */

/* CURRENT EXITS */

/* OBJECTS */

/* CLOCK INTERRUPTS */

/* VILLAINS AND DEMONS */

/* ADVENTURERS */

/* FUNCTIONS AND DATA */

/* FLAGS */

/* WALK, PAGE 2 */

   ret_val = TRUE_;
/* 						!ASSUME WINS. */
   if (play_1.winner != aindex_1.player || lit_(&play_1.here) || prob_(&c__25, &c__25)) {
      goto L500;
   }
   if (!findxt_(&prsvec_1.prso, &play_1.here)) {
      goto L450;
   }
/* 						!INVALID EXIT? GRUE */
/* 						! */
   switch (curxt_1.xtype) {
      case 1:
         goto L400;
      case 2:
         goto L200;
      case 3:
         goto L100;
      case 4:
         goto L300;
   }
/* 						!DECODE EXIT TYPE. */
   bug_(&c__9, &curxt_1.xtype);

 L100:
   if (cxappl_(&curxt_1.xactio) != 0) {
      goto L400;
   }
/* 						!CEXIT... RETURNED ROOM? */
   if (flags[*xflag - 1]) {
      goto L400;
   }
/* 						!NO, FLAG ON? */
 L200:
   jigsup_(&c__523);
/* 						!BAD EXIT, GRUE */
/* 						! */
   return ret_val;

 L300:
   if (cxappl_(&curxt_1.xactio) != 0) {
      goto L400;
   }
/* 						!DOOR... RETURNED ROOM? */
   if ((objcts_1.oflag2[curxt_1.xobj - 1] & oflags_1.openbt) != 0) {
      goto L400;
   }
/* 						!NO, DOOR OPEN? */
   jigsup_(&c__523);
/* 						!BAD EXIT, GRUE */
/* 						! */
   return ret_val;

 L400:
   if (lit_(&curxt_1.xroom1)) {
      goto L900;
   }
/* 						!VALID ROOM, IS IT LIT? */
 L450:
   jigsup_(&c__522);
/* 						!NO, GRUE */
/* 						! */
   return ret_val;

/* ROOM IS LIT, OR WINNER IS NOT PLAYER (NO GRUE). */

 L500:
   if (findxt_(&prsvec_1.prso, &play_1.here)) {
      goto L550;
   }
/* 						!EXIT EXIST? */
 L525:
   curxt_1.xstrng = 678;
/* 						!ASSUME WALL. */
   if (prsvec_1.prso == xsrch_1.xup) {
      curxt_1.xstrng = 679;
   }
/* 						!IF UP, CANT. */
   if (prsvec_1.prso == xsrch_1.xdown) {
      curxt_1.xstrng = 680;
   }
/* 						!IF DOWN, CANT. */
   if ((rooms_1.rflag[play_1.here - 1] & rflag_1.rnwall) != 0) {
      curxt_1.xstrng = 524;
   }
   rspeak_(&curxt_1.xstrng);
   prsvec_1.prscon = 1;
/* 						!STOP CMD STREAM. */
   return ret_val;

 L550:
   switch (curxt_1.xtype) {
      case 1:
         goto L900;
      case 2:
         goto L600;
      case 3:
         goto L700;
      case 4:
         goto L800;
   }
/* 						!BRANCH ON EXIT TYPE. */
   bug_(&c__9, &curxt_1.xtype);

 L700:
   if (cxappl_(&curxt_1.xactio) != 0) {
      goto L900;
   }
/* 						!CEXIT... RETURNED ROOM? */
   if (flags[*xflag - 1]) {
      goto L900;
   }
/* 						!NO, FLAG ON? */
 L600:
   if (curxt_1.xstrng == 0) {
      goto L525;
   }
/* 						!IF NO REASON, USE STD. */
   rspeak_(&curxt_1.xstrng);
/* 						!DENY EXIT. */
   prsvec_1.prscon = 1;
/* 						!STOP CMD STREAM. */
   return ret_val;

 L800:
   if (cxappl_(&curxt_1.xactio) != 0) {
      goto L900;
   }
/* 						!DOOR... RETURNED ROOM? */
   if ((objcts_1.oflag2[curxt_1.xobj - 1] & oflags_1.openbt) != 0) {
      goto L900;
   }
/* 						!NO, DOOR OPEN? */
   if (curxt_1.xstrng == 0) {
      curxt_1.xstrng = 525;
   }
/* 						!IF NO REASON, USE STD. */
   rspsub_(&curxt_1.xstrng, &objcts_1.odesc2[curxt_1.xobj - 1]);
   prsvec_1.prscon = 1;
/* 						!STOP CMD STREAM. */
   return ret_val;

 L900:
   ret_val = moveto_(&curxt_1.xroom1, &play_1.winner);
/* 						!MOVE TO ROOM. */
   if (ret_val) {
      ret_val = rmdesc_(&c__0);
   }
/* 						!DESCRIBE ROOM. */
   return ret_val;
} /* walk_ */

#undef switch__
#undef prpvec
#undef objvec
#undef flags
#undef rrand
#undef xflag
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqr
#undef eqo
#undef eqc
#undef eqa

/* CXAPPL- CONDITIONAL EXIT PROCESSORS */

/* DECLARATIONS */

integer cxappl_(integer * ri) {
/* System generated locals */
   integer ret_val, i__1;

/* Local variables */
#define flags ((logical *)&findex_1)
#define switch__ ((integer *)&findex_1 + 46)
   extern /* Subroutine */ int rspeak_(integer *);
   extern integer mrhere_(integer *);
   extern /* Subroutine */ int cpgoto_(integer *);
   static integer i__, j, k;
#define eqa ((integer *)&advs_1 + 1)
   extern /* Subroutine */ int bug_(integer *, integer *);
   extern integer rnd_(integer *);
#define eqo ((integer *)&objcts_1 + 1)
#define eqr ((integer *)&rooms_1 + 2)
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
   static integer nxt;
#define pvec ((integer *)&pv_1)
   static integer ldir;
#define rrand ((integer *)&rooms_1 + 602)
#define xflag ((integer *)&curxt_1 + 4)
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)

/* GAME STATE */

/* PARSER OUTPUT */

/* PARSER STATE */

/* PUZZLE ROOM STATE */

/* ROOMS */

/* EXITS */

/* CURRENT EXITS */

/* OBJECTS */

/* ADVENTURERS */

/* CXAPPL, PAGE 2 */

/* FLAGS */

   ret_val = 0;
/* 						!NO RETURN. */
   if (*ri == 0) {
      return ret_val;
   }
/* 						!IF NO ACTION, DONE. */
   switch (*ri) {
      case 1:
         goto L1000;
      case 2:
         goto L2000;
      case 3:
         goto L3000;
      case 4:
         goto L4000;
      case 5:
         goto L5000;
      case 6:
         goto L6000;
      case 7:
         goto L7000;
      case 8:
         goto L8000;
      case 9:
         goto L9000;
      case 10:
         goto L10000;
      case 11:
         goto L11000;
      case 12:
         goto L12000;
      case 13:
         goto L13000;
      case 14:
         goto L14000;
   }
   bug_(&c__5, ri);

/* C1- COFFIN-CURE */

 L1000:
   findex_1.egyptf = objcts_1.oadv[oindex_1.coffi - 1] != play_1.winner;
/* 						!T IF NO COFFIN. */
   return ret_val;

/* C2- CAROUSEL EXIT */
/* C5- CAROUSEL OUT */

 L2000:
   if (findex_1.caroff) {
      return ret_val;
   }
/* 						!IF FLIPPED, NOTHING. */
 L2500:
   rspeak_(&c__121);
/* 						!SPIN THE COMPASS. */
 L5000:
   i__ = xpars_1.xelnt[xpars_1.xcond - 1] * rnd_(&c__8);
/* 						!CHOOSE RANDOM EXIT. */
   curxt_1.xroom1 = exits_1.travel[rooms_1.rexit[play_1.here - 1] + i__ - 1]
      & xpars_1.xrmask;
   ret_val = curxt_1.xroom1;
/* 						!RETURN EXIT. */
   return ret_val;

/* C3- CHIMNEY FUNCTION */

 L3000:
   findex_1.litldf = FALSE_;
/* 						!ASSUME HEAVY LOAD. */
   j = 0;
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
/* 						!COUNT OBJECTS. */
      if (objcts_1.oadv[i__ - 1] == play_1.winner) {
         ++j;
      }
/* L3100: */
   }

   if (j > 2) {
      return ret_val;
   }
/* 						!CARRYING TOO MUCH? */
   curxt_1.xstrng = 446;
/* 						!ASSUME NO LAMP. */
   if (objcts_1.oadv[oindex_1.lamp - 1] != play_1.winner) {
      return ret_val;
   }
/* 						!NO LAMP? */
   findex_1.litldf = TRUE_;
/* 						!HE CAN DO IT. */
   if ((objcts_1.oflag2[oindex_1.door - 1] & oflags_1.openbt) == 0) {
      objcts_1.oflag2[oindex_1.door - 1] &= ~oflags_1.tchbt;
   }
   return ret_val;

/* C4-	FROBOZZ FLAG (MAGNET ROOM, FAKE EXIT) */
/* C6-	FROBOZZ FLAG (MAGNET ROOM, REAL EXIT) */

 L4000:
   if (findex_1.caroff) {
      goto L2500;
   }
/* 						!IF FLIPPED, GO SPIN. */
   findex_1.frobzf = FALSE_;
/* 						!OTHERWISE, NOT AN EXIT. */
   return ret_val;

 L6000:
   if (findex_1.caroff) {
      goto L2500;
   }
/* 						!IF FLIPPED, GO SPIN. */
   findex_1.frobzf = TRUE_;
/* 						!OTHERWISE, AN EXIT. */
   return ret_val;

/* C7-	FROBOZZ FLAG (BANK ALARM) */

 L7000:
   findex_1.frobzf = objcts_1.oroom[oindex_1.bills - 1] != 0 && objcts_1.oroom[oindex_1.portr - 1] != 0;
   return ret_val;
/* CXAPPL, PAGE 3 */

/* C8-	FROBOZZ FLAG (MRGO) */

 L8000:
   findex_1.frobzf = FALSE_;
/* 						!ASSUME CANT MOVE. */
   if (findex_1.mloc != curxt_1.xroom1) {
      goto L8100;
   }
/* 						!MIRROR IN WAY? */
   if (prsvec_1.prso == xsrch_1.xnorth || prsvec_1.prso == xsrch_1.xsouth) {
      goto L8200;
   }
   if (findex_1.mdir % 180 != 0) {
      goto L8300;
   }
/* 						!MIRROR MUST BE N-S. */
   curxt_1.xroom1 = (curxt_1.xroom1 - rindex_1.mra << 1) + rindex_1.mrae;
/* 						!CALC EAST ROOM. */
   if (prsvec_1.prso > xsrch_1.xsouth) {
      ++curxt_1.xroom1;
   }
/* 						!IF SW/NW, CALC WEST. */
 L8100:
   ret_val = curxt_1.xroom1;
   return ret_val;

 L8200:
   curxt_1.xstrng = 814;
/* 						!ASSUME STRUC BLOCKS. */
   if (findex_1.mdir % 180 == 0) {
      return ret_val;
   }
/* 						!IF MIRROR N-S, DONE. */
 L8300:
   ldir = findex_1.mdir;
/* 						!SEE WHICH MIRROR. */
   if (prsvec_1.prso == xsrch_1.xsouth) {
      ldir = 180;
   }
   curxt_1.xstrng = 815;
/* 						!MIRROR BLOCKS. */
   if (ldir > 180 && !findex_1.mr1f || ldir < 180 && !findex_1.mr2f) {
      curxt_1.xstrng = 816;
   }
   return ret_val;

/* C9-	FROBOZZ FLAG (MIRIN) */

 L9000:
   if (mrhere_(&play_1.here) != 1) {
      goto L9100;
   }
/* 						!MIRROR 1 HERE? */
   if (findex_1.mr1f) {
      curxt_1.xstrng = 805;
   }
/* 						!SEE IF BROKEN. */
   findex_1.frobzf = findex_1.mropnf;
/* 						!ENTER IF OPEN. */
   return ret_val;

 L9100:
   findex_1.frobzf = FALSE_;
/* 						!NOT HERE, */
   curxt_1.xstrng = 817;
/* 						!LOSE. */
   return ret_val;
/* CXAPPL, PAGE 4 */

/* C10-	FROBOZZ FLAG (MIRROR EXIT) */

 L10000:
   findex_1.frobzf = FALSE_;
/* 						!ASSUME CANT. */
   ldir = (prsvec_1.prso - xsrch_1.xnorth) / xsrch_1.xnorth * 45;
/* 						!XLATE DIR TO DEGREES. */
   if (!findex_1.mropnf || (findex_1.mdir + 270) % 360 != ldir && prsvec_1.prso != xsrch_1.xexit) {
      goto L10200;
   }
   curxt_1.xroom1 = (findex_1.mloc - rindex_1.mra << 1) + rindex_1.mrae + 1 - findex_1.mdir / 180;
/* 						!ASSUME E-W EXIT. */
   if (findex_1.mdir % 180 == 0) {
      goto L10100;
   }
/* 						!IF N-S, OK. */
   curxt_1.xroom1 = findex_1.mloc + 1;
/* 						!ASSUME N EXIT. */
   if (findex_1.mdir > 180) {
      curxt_1.xroom1 = findex_1.mloc - 1;
   }
/* 						!IF SOUTH. */
 L10100:
   ret_val = curxt_1.xroom1;
   return ret_val;

 L10200:
   if (!findex_1.wdopnf || (findex_1.mdir + 180) % 360 != ldir && prsvec_1.prso != xsrch_1.xexit) {
      return ret_val;
   }
   curxt_1.xroom1 = findex_1.mloc + 1;
/* 						!ASSUME N. */
   if (findex_1.mdir == 0) {
      curxt_1.xroom1 = findex_1.mloc - 1;
   }
/* 						!IF S. */
   rspeak_(&c__818);
/* 						!CLOSE DOOR. */
   findex_1.wdopnf = FALSE_;
   ret_val = curxt_1.xroom1;
   return ret_val;

/* C11-	MAYBE DOOR.  NORMAL MESSAGE IS THAT DOOR IS CLOSED. */
/* 	BUT IF LCELL.NE.4, DOOR ISNT THERE. */

 L11000:
   if (findex_1.lcell != 4) {
      curxt_1.xstrng = 678;
   }
/* 						!SET UP MSG. */
   return ret_val;

/* C12-	FROBZF (PUZZLE ROOM MAIN ENTRANCE) */

 L12000:
   findex_1.frobzf = TRUE_;
/* 						!ALWAYS ENTER. */
   findex_1.cphere = 10;
/* 						!SET SUBSTATE. */
   return ret_val;

/* C13-	CPOUTF (PUZZLE ROOM SIZE ENTRANCE) */

 L13000:
   findex_1.cphere = 52;
/* 						!SET SUBSTATE. */
   return ret_val;
/* CXAPPL, PAGE 5 */

/* C14-	FROBZF (PUZZLE ROOM TRANSITIONS) */

 L14000:
   findex_1.frobzf = FALSE_;
/* 						!ASSSUME LOSE. */
   if (prsvec_1.prso != xsrch_1.xup) {
      goto L14100;
   }
/* 						!UP? */
   if (findex_1.cphere != 10) {
      return ret_val;
   }
/* 						!AT EXIT? */
   curxt_1.xstrng = 881;
/* 						!ASSUME NO LADDER. */
   if (puzzle_1.cpvec[findex_1.cphere] != -2) {
      return ret_val;
   }
/* 						!LADDER HERE? */
   rspeak_(&c__882);
/* 						!YOU WIN. */
   findex_1.frobzf = TRUE_;
/* 						!LET HIM OUT. */
   return ret_val;

 L14100:
   if (findex_1.cphere != 52 || prsvec_1.prso != xsrch_1.xwest || !findex_1.cpoutf) {
      goto L14200;
   }
   findex_1.frobzf = TRUE_;
/* 						!YES, LET HIM OUT. */
   return ret_val;

 L14200:
   for (i__ = 1; i__ <= 16; i__ += 2) {
/* 						!LOCATE EXIT. */
      if (prsvec_1.prso == puzzle_1.cpdr[i__ - 1]) {
         goto L14400;
      }
/* L14300: */
   }
   return ret_val;
/* 						!NO SUCH EXIT. */

 L14400:
   j = puzzle_1.cpdr[i__];
/* 						!GET DIRECTIONAL OFFSET. */
   nxt = findex_1.cphere + j;
/* 						!GET NEXT STATE. */
   k = 8;
/* 						!GET ORTHOGONAL DIR. */
   if (j < 0) {
      k = -8;
   }
   if ((abs(j) == 1 || abs(j) == 8 || (puzzle_1.cpvec[findex_1.cphere + k - 1] == 0 || puzzle_1.cpvec[nxt - k - 1] == 0)) && puzzle_1.cpvec[nxt - 1] == 0) {
      goto L14500;
   }
   return ret_val;

 L14500:
   cpgoto_(&nxt);
/* 						!MOVE TO STATE. */
   curxt_1.xroom1 = rindex_1.cpuzz;
/* 						!STAY IN ROOM. */
   ret_val = curxt_1.xroom1;
   return ret_val;

} /* cxappl_ */

#undef prpvec
#undef objvec
#undef xflag
#undef rrand
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqa
#undef switch__
#undef flags
