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

struct synflg_1_ {
   integer sdir, sind, sstd, sflip, sdriv, svmask;
};

#define synflg_1 (*(struct synflg_1_ *) &synflg_)

struct objflg_1_ {
   integer vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
};

#define objflg_1 (*(struct objflg_1_ *) &objflg_)

struct {
   integer winner, here;
   logical telflg;
} play_;

#define play_1 play_

struct {
   integer moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

struct screen_1_ {
   integer fromdr, scolrm, scolac, scoldr[8], scolwl[12];
};

#define screen_1 (*(struct screen_1_ *) &screen_)

struct puzzle_1_ {
   integer cpdr[16], cpwl[8], cpvec[64];
};

#define puzzle_1 (*(struct puzzle_1_ *) &puzzle_)

struct {
   integer mbase, strbit;
} star_;

#define star_1 star_

struct vers_1_ {
   integer vmaj, vmin;
   char vedit[1];
};

#define vers_1 (*(struct vers_1_ *) &vers_)

struct bats_1_ {
   integer batdrp[9];
};

#define bats_1 (*(struct bats_1_ *) &bats_)

struct {
   integer inlnt;
   char inbuf[78];
} input_;

#define input_1 input_

struct {
   integer inpch, outch, dbch;
} chan_;

#define chan_1 chan_

struct {
   integer dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

struct hyper_1_ {
   integer hfactr;
};

#define hyper_1 (*(struct hyper_1_ *) &hyper_)

struct {
   integer rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

struct rflag_1_ {
   integer rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
};

#define rflag_1 (*(struct rflag_1_ *) &rflag_)

struct rindex_1_ {
   integer whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls,
      mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw,
      mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
};

#define rindex_1 (*(struct rindex_1_ *) &rindex_)

struct {
   integer xlnt, travel[900];
} exits_;

#define exits_1 exits_

struct {
   integer xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_

struct xpars_1_ {
   integer xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
};

#define xpars_1 (*(struct xpars_1_ *) &xpars_)

struct xsrch_1_ {
   integer xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
};

#define xsrch_1 (*(struct xsrch_1_ *) &xsrch_)

struct {
   integer olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   integer r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct oflags_1_ {
   integer visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt,
      schbt;
};

#define oflags_1 (*(struct oflags_1_ *) &oflags_)

struct oindex_1_ {
   integer garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw,
      cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage,
      spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs,
      sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
};

#define oindex_1 (*(struct oindex_1_ *) &oindex_)

struct {
   integer clnt, ctick[25], cactio[25];
   logical cflag[25];
} cevent_;

#define cevent_1 cevent_

struct cindex_1_ {
   integer cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
};

#define cindex_1 (*(struct cindex_1_ *) &cindex_)

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

struct aflags_1_ {
   integer astag;
};

#define aflags_1 (*(struct aflags_1_ *) &aflags_)

struct aindex_1_ {
   integer player, arobot, amastr;
};

#define aindex_1 (*(struct aindex_1_ *) &aindex_)

struct vindex_1_ {
   integer cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw,
      openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw,
      clmbuw, clmbdw, trntow;
};

#define vindex_1 (*(struct vindex_1_ *) &vindex_)

struct {
   logical trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf,
      frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   integer btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

/* Initialized data */

struct {
   integer e_1[6];
} synflg_ = { 16384, 8192, 4096, 2048, 1024, 511 };

struct {
   integer e_1[7];
} objflg_ = { 16384, 8192, 4096, 2048, 1024, 512, 511 };

struct {
   integer fill_1[3];
   integer e_2[20];
} screen_ = { { 0 }, 1024, 153, 5120, 154, 3072, 152, 7168, 151, 151, 207,
3072, 152, 208, 7168, 153, 206, 5120, 154, 205, 1024
};

struct {
   integer e_1[88];
} puzzle_ = { 1024, -8, 2048, -7, 3072, 1, 4096, 9, 5120, 8, 6144, 7,
   7168, -1, 8192, -9, 205, -8, 206, 8, 207, 1, 208, -1, 1, 1, 1, 1,
   1, 1, 1, 1, 1, 0, -1, 0, 0, -1, 0, 1, 1, -1, 0, 1, 0, -2, 0, 1, 1,
   0, 0, 0, 0, 1, 0, 1, 1, -3, 0, 0, -1, -1, 0, 1, 1, 0, 0, -1, 0,
   0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

struct {
   integer e_1[2];
   char e_2[1];
} vers_ = { 2, 6, "A" };

struct {
   integer e_1[9];
} bats_ = { 66, 67, 68, 69, 70, 71, 72, 65, 73 };

struct {
   integer e_1;
} hyper_ = { 500 };

struct {
   integer e_1[12];
} rflag_ = { 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32,
   16
};

struct {
   integer e_1[86];
} rindex_ = { 2, 8, 9, 10, 11, 25, 30, 31, 33, 36, 40, 42, 44, 49, 61, 76,
   77, 79, 80, 83, 91, 94, 96, 97, 100, 102, 103, 107, 108, 109,
   101, 112, 113, 114, 120, 119, 121, 122, 126, 127, 128, 129, 130,
   131, 132, 133, 135, 140, 141, 142, 143, 144, 145, 146, 147, 148,
   151, 153, 154, 155, 157, 158, 159, 160, 161, 162, 163, 164, 165,
   166, 167, 171, 172, 173, 174, 176, 177, 179, 182, 183, 184, 185,
   186, 188, 189, 190
};

struct {
   integer e_1[14];
} xpars_ = { 255, 31744, 3, 256, 256, 1, 2, 3, 3, 1, 2, 3, 4, 32768 };

struct {
   integer e_1[10];
} xsrch_ = { 1024, 16384, 10240, 9216, 1024, 5120, 13312, 14336, 3072,
   7168
};

struct {
   integer e_1[32];
} oflags_ = { 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32,
   16, 8, 4, 2, 1, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256,
   128, 64, 32, 16, 8, 4, 2, 1
};

struct {
   integer e_1[121];
} oindex_ = { 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
   20, 21, 23, 30, 26, 33, 34, 35, 36, 39, 42, 45, 46, 47, 48, 51,
   54, 55, 56, 57, 58, 59, 61, 62, 63, 65, 66, 71, 78, 79, 75, 85,
   86, 87, 88, 89, 90, 92, 94, 96, 98, 99, 97, 101, 102, 103, 105,
   107, 109, 110, 111, 112, 113, 119, 123, 124, 125, 126, 127, 132,
   133, 134, 137, 138, 139, 140, 141, 142, 145, 148, 149, 151, 152,
   154, 155, 156, 157, 158, 159, 161, 164, 171, 172, 173, 175, 178,
   185, 186, 187, 188, 189, 200, 198, 201, 196, 202, 197, 192, 194,
   195, 193, 205, 209, 215
};

struct {
   integer e_1[24];
} cindex_ = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
   18, 19, 20, 21, 22, 23, 24
};

struct {
   integer e_1;
} aflags_ = { 32768 };

struct {
   integer e_1[3];
} aindex_ = { 1, 2, 3 };

struct {
   integer e_1[70];
} vindex_ = { 1, 2, 3, 4, 5, 6, 7, 8, 101, 100, 102, 103, 104, 105, 106,
   107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
   120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132,
   133, 134, 135, 136, 137, 138, 139, 141, 140, 142, 143, 144, 145,
   146, 147, 148, 89, 91, 73, 85, 151, 152, 153, 154, 155, 156, 157,
   158, 159
};

/* DUNGEON-- MAIN PROGRAM */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* Main program */ int MAIN__(void) {
   static integer x;
   extern /* Subroutine */ int game_(void);
   extern logical init_(integer *);
   extern /* Subroutine */ int exit_(void);

/* DECLARATIONS */

/* DUNGEON, PAGE 3 */

/* 1) INITIALIZE DATA STRUCTURES */
/* 2) PLAY GAME */

   if (init_(&x)) {
      game_();
   }
/* 						!IF INIT, PLAY GAME. */
   exit_();
/* 						!DONE */
   return 0;
} /* MAIN__ */

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* SCREEN OF LIGHT */

/* MISCELLANEOUS VARIABLES */

/* PUZZLE ROOM STATE */

/* I/O VARIABLES */

/* ROOMS */

/* EXITS */

/* CURRENT EXITS */

/* OBJECTS */

/* CLOCK INTERRUPTS */

/* VILLAINS AND DEMONS */

/* ADVENTURERS */

/* VERBS */

/* DUNGEON, PAGE 2 */

/* DATA STATEMENTS FOR CONSTANT ARRAYS */

/* FLAGS */

/* Main program alias */ int dungeo_() {
   MAIN__();
   return 0;
}
