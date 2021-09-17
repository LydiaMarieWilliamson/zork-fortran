#include "F2C.h"
#include "parser.h"

// parser.h:
struct synflg_1_ synflg_ = (struct synflg_1_){
   sdir: 16384, sind: 8192, sstd: 4096, sflip: 2048, sdriv: 1024, svmask: 511
};

struct objflg_1_ objflg_ = (struct objflg_1_){
   vabit: 16384, vrbit: 8192, vtbit: 4096, vcbit: 2048, vebit: 1024, vfbit: 512, vpmask: 511
};

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

struct screen_1_ {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_ = (struct screen_1_){
   fromdr: 0, scolrm: 0, scolac: 0,
   scoldr: { 1024, 153, 5120, 154, 3072, 152, 7168, 151 },
   scolwl: { 151, 207, 3072, 152, 208, 7168, 153, 206, 5120, 154, 205, 1024 }
};
#define screen_1 screen_

// puzzle.h: (Unlisted)

// PUZZLE ROOM STATE

struct puzzle_1_ {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_ = (struct puzzle_1_){
   cpdr: { 1024, -8, 2048, -7, 3072, 1, 4096, 9, 5120, 8, 6144, 7, 7168, -1, 8192, -9 },
   cpwl: { 205, -8, 206, 8, 207, 1, 208, -1 },
   cpvec: {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 0, -1, 0, 0, -1, 0, 1,
      1, -1, 0, 1, 0, -2, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
      1, -3, 0, 0, -1, -1, 0, 1, 1, 0, 0, -1, 0, 0, 0, 1,
      1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
   }
};
#define puzzle_1 puzzle_

// star.h: (Unlisted)
extern struct {
   int mbase, strbit;
} star_;
#define star_1 star_

// vers.h: (Unlisted)
union {
   struct vers_1_ {
      int vmaj, vmin;
      char vedit[1];
   } _1;
   struct vers_2_ {
      int vmaj, vmin, vedit;
   } _2;
} vers_ = {
// int vmaj;
   2,
// int vmin;
   6,
// char vedit[1];
   { "A" }
};
#define vers_1 (vers_._1)
#define vers_2 (vers_._2)

// bats.h: (Unlisted)
struct bats_1_ {
   int batdrp[9];
} bats_ = (struct bats_1_){
   batdrp: { 66, 67, 68, 69, 70, 71, 72, 65, 73 }
};
#define bats_1 bats_

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
struct hyper_1_ {
   int hfactr;
} hyper_ = (struct hyper_1_){
   hfactr: 500
};
#define hyper_1 hyper_

// rooms.h:

// ROOMS

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;
#define rooms_1 rooms_

// rflag.h:

struct rflag_1_ {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_ = (struct rflag_1_){
   rseen: 32768, rlight: 16384, rland: 8192, rwater: 4096, rair: 2048, rsacrd: 1024,
   rfill: 512, rmung: 256, rbuck: 128, rhouse: 64, rnwall: 32, rend: 16
};
#define rflag_1 rflag_

// rindex.h:

struct rindex_1_ {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_ = (struct rindex_1_){
   whous: 2, lroom: 8, cella: 9, mtrol: 10, maze1: 11, mgrat: 25, maz15: 30, fore1: 31, fore3: 33, clear: 36,
   reser: 40, strea: 42, egypt: 44, echor: 49, tshaf: 61, bshaf: 76, mmach: 77, dome: 79, mtorc: 80, carou: 83,
   riddl: 91, lld2: 94, temp1: 96, temp2: 97, maint: 100, blroo: 102, treas: 103, rivr1: 107, rivr2: 108, rivr3: 109,
   mcycl: 101, rivr4: 112, rivr5: 113, fchmp: 114, falls: 120, mbarr: 119, mrain: 121, pog: 122, vlbot: 126, vair1: 127,
   vair2: 128, vair3: 129, vair4: 130, ledg2: 131, ledg3: 132, ledg4: 133, msafe: 135, cager: 140, caged: 141, twell: 142,
   bwell: 143, alice: 144, alism: 145, alitr: 146, mtree: 147, bkent: 148, bkvw: 151, bktwi: 153, bkvau: 154, bkbox: 155,
   crypt: 157, tstrs: 158, mrant: 159, mreye: 160, mra: 161, mrb: 162, mrc: 163, mrg: 164, mrd: 165, fdoor: 166,
   mrae: 167, mrce: 171, mrcw: 172, mrge: 173, mrgw: 174, mrdw: 176, inmir: 177, scorr: 179, ncorr: 182, parap: 183,
   cell: 184, pcell: 185, ncell: 186, cpant: 188, cpout: 189, cpuzz: 190
};
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

// xpars.h:

struct xpars_1_ {
   int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_ = (struct xpars_1_){
   xrmask: 255, xdmask: 31744, xfmask: 3, xfshft: 256, xashft: 256,
   xelnt: { 1, 2, 3, 3 },
   xnorm: 1, xno: 2, xcond: 3, xdoor: 4, xlflag: 32768
};
#define xpars_1 xpars_

// xsrch.h:

struct xsrch_1_ {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_ = (struct xsrch_1_){
   xmin: 1024, xmax: 16384, xdown: 10240, xup: 9216, xnorth: 1024,
   xsouth: 5120, xenter: 13312, xexit: 14336, xeast: 3072, xwest: 7168
};
#define xsrch_1 xsrch_

// objects.h:

// OBJECTS

extern struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;
#define objcts_1 objcts_

extern struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;
#define oroom2_1 oroom2_

// oflags.h:

struct oflags_1_ {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_ = (struct oflags_1_){
   visibt: 32768, readbt: 16384, takebt: 8192, doorbt: 4096, tranbt: 2048, foodbt: 1024, ndscbt: 512, drnkbt: 256,
   contbt: 128, litebt: 64, victbt: 32, burnbt: 16, flambt: 8, toolbt: 4, turnbt: 2, onbt: 1,
   findbt: 32768, slepbt: 16384, scrdbt: 8192, tiebt: 4096, clmbbt: 2048, actrbt: 1024, weapbt: 512, fitebt: 256,
   villbt: 128, stagbt: 64, trybt: 32, nochbt: 16, openbt: 8, tchbt: 4, vehbt: 2, schbt: 1
};
#define oflags_1 oflags_

// oindex.h:

struct oindex_1_ {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_ = (struct oindex_1_){
   garli: 2, food: 3, gunk: 4, coal: 5, machi: 7, diamo: 8, tcase: 9, bottl: 10,
   water: 11, rope: 12, knife: 13, sword: 14, lamp: 15, blamp: 16, rug: 17, leave: 18,
   troll: 19, axe: 20, rknif: 21, keys: 23, ice: 30, bar: 26, coffi: 33, torch: 34,
   tbask: 35, fbask: 36, irbox: 39, ghost: 42, trunk: 45, bell: 46, book: 47, candl: 48,
   match: 51, tube: 54, putty: 55, wrenc: 56, screw: 57, cyclo: 58, chali: 59, thief: 61,
   still: 62, windo: 63, grate: 65, door: 66, hpole: 71, leak: 78, rbutt: 79, raili: 75,
   pot: 85, statu: 86, iboat: 87, dboat: 88, pump: 89, rboat: 90, stick: 92, buoy: 94,
   shove: 96, ballo: 98, recep: 99, guano: 97, brope: 101, hook1: 102, hook2: 103, safe: 105,
   sslot: 107, brick: 109, fuse: 110, gnome: 111, blabe: 112, dball: 113, tomb: 119, lcase: 123,
   cage: 124, rcage: 125, spher: 126, sqbut: 127, flask: 132, pool: 133, saffr: 134, bucke: 137,
   ecake: 138, orice: 139, rdice: 140, blice: 141, robot: 142, ftree: 145, bills: 148, portr: 149,
   scol: 151, zgnom: 152, egg: 154, begg: 155, baubl: 156, canar: 157, bcana: 158, ylwal: 159,
   rdwal: 161, pindr: 164, rbeam: 171, odoor: 172, qdoor: 173, cdoor: 175, num1: 178, num8: 185,
   warni: 186, cslit: 187, gcard: 188, stldr: 189, hands: 200, wall: 198, lungs: 201, sailo: 196,
   aviat: 202, teeth: 197, itobj: 192, every: 194, valua: 195, oplay: 193, wnort: 205, gwate: 209, master: 215
};
#define oindex_1 oindex_

// clock.h:

// CLOCK INTERRUPTS

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;
#define cevent_1 cevent_

struct cindex_1_ {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_ = (struct cindex_1_){
   cevcur: 1, cevmnt: 2, cevlnt: 3, cevmat: 4, cevcnd: 5, cevbal: 6, cevbrn: 7, cevfus: 8,
   cevled: 9, cevsaf: 10, cevvlg: 11, cevgno: 12, cevbuc: 13, cevsph: 14, cevegh: 15, cevfor: 16,
   cevscl: 17, cevzgi: 18, cevzgo: 19, cevste: 20, cevmrs: 21, cevpin: 22, cevinq: 23, cevfol: 24
};
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

// advers.h:

// ADVENTURERS

extern struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;
#define advs_1 advs_

struct aflags_1_ {
   int astag;
} aflags_ = (struct aflags_1_){
   astag: 32768
};
#define aflags_1 aflags_

struct aindex_1_ {
   int player, arobot, amastr;
} aindex_ = (struct aindex_1_){
   player: 1, arobot: 2, amastr: 3
};
#define aindex_1 aindex_

// verbs.h:

// VERBS

struct vindex_1_ {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_ = (struct vindex_1_){
   cintw: 1, deadxw: 2, frstqw: 3, inxw: 4, outxw: 5, walkiw: 6, fightw: 7, foow: 8,
   meltw: 101, readw: 100, inflaw: 102, deflaw: 103, alarmw: 104, exorcw: 105, plugw: 106, kickw: 107,
   wavew: 108, raisew: 109, lowerw: 110, rubw: 111, pushw: 112, untiew: 113, tiew: 114, tieupw: 115,
   turnw: 116, breatw: 117, knockw: 118, lookw: 119, examiw: 120, shakew: 121, movew: 122, trnonw: 123,
   trnofw: 124, openw: 125, closew: 126, findw: 127, waitw: 128, spinw: 129, boardw: 130, unboaw: 131,
   takew: 132, invenw: 133, fillw: 134, eatw: 135, drinkw: 136, burnw: 137, mungw: 138, killw: 139,
   attacw: 141, swingw: 140, walkw: 142, tellw: 143, putw: 144, dropw: 145, givew: 146, pourw: 147, throww: 148,
   digw: 89, leapw: 91, stayw: 73, follow: 85, hellow: 151, lookiw: 152, lookuw: 153, pumpw: 154,
   windw: 155, clmbw: 156, clmbuw: 157, clmbdw: 158, trntow: 159
};
#define vindex_1 vindex_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// DUNGEON-- MAIN PROGRAM

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// Main program
int MAIN__(void) {
   static int x;
   extern void game_(void);
   extern Bool init_(int);
   extern void exit_(void);

// DECLARATIONS

// DUNGEON, PAGE 3

// 1) INITIALIZE DATA STRUCTURES
// 2) PLAY GAME

   if (init_(x)) {
      game_();
   }
// 						!IF INIT, PLAY GAME.
   exit_();
// 						!DONE
   return 0;
}

// MISCELLANEOUS VARIABLES

// DUNGEON, PAGE 2

// DATA STATEMENTS FOR CONSTANT ARRAYS

// FLAGS

// Main program alias
int dungeo_(void) {
   MAIN__();
   return 0;
}
