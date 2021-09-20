// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

// parser.h:
// common /synflg/
// enum synflagCB; // Declared and defined in common.h.

// common /objflg/
// enum objflagCB; // Declared and defined in common.h.

// screen.h:
// common /screen/
struct screenCB screen = (struct screenCB){
   fromdr: 0, scolrm: 0, scolac: 0,
   scoldr: { 1024, 153, 5120, 154, 3072, 152, 7168, 151 },
   scolwl: { 151, 207, 3072, 152, 208, 7168, 153, 206, 5120, 154, 205, 1024 }
};

// puzzle.h:
// common /puzzle/
struct puzzleCB puzzle = (struct puzzleCB){
   cpdr: { 1024, -8, 2048, -7, 3072, 1, 4096, 9, 5120, 8, 6144, 7, 7168, -1, 8192, -9 },
   cpwl: { 205, -8, 206, 8, 207, 1, 208, -1 },
   cpvec: {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 0, -1, 0, 0, -1, 0, 1,
      1, -1, 0, 1, 0, -2, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
      1, -3, 0, 0, -1, -1, 0, 1, 1, 0, 0, -1, 0, 0, 0, 1,
      1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
   }
};

// common /vers/
union versCB vers = {
// int vmaj;
   2,
// int vmin;
   6,
// char vedit[1];
   { "A" }
};

// common /bats/
struct batsCB bats = (struct batsCB){
   batdrp: { 66, 67, 68, 69, 70, 71, 72, 65, 73 }
};

// common /hyper/
struct hyperCB hyper = (struct hyperCB){
   hfactr: 500
};

// rflag.h:
// common /rflag/
// enum rflagCB; // Declared and defined in common.h.

// rindex.h:
// common /rindex/
struct rindexCB rindex_ = (struct rindexCB){
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

// xsrch.h:
// common /xsrch/
struct xsrchCB xsrch = (struct xsrchCB){
   xmin: 1024, xmax: 16384, xdown: 10240, xup: 9216, xnorth: 1024,
   xsouth: 5120, xenter: 13312, xexit: 14336, xeast: 3072, xwest: 7168
};

// xpars.h:
// common /xpars/
struct xparsCB xpars = (struct xparsCB){
   xrmask: 255, xdmask: 31744, xfmask: 3, xfshft: 256, xashft: 256,
   xelnt: { 1, 2, 3, 3 },
   xnorm: 1, xno: 2, xcond: 3, xdoor: 4, xlflag: 32768
};

// oflags.h:
// common /oflags/
// enum oflagsCB; // Declared and defined in common.h.

// oindex.h:
// common /oindex/
struct oindexCB oindex = (struct oindexCB){
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

// clock.h:
// common /cindex/
struct cindexCB cindex = (struct cindexCB){
   cevcur: 1, cevmnt: 2, cevlnt: 3, cevmat: 4, cevcnd: 5, cevbal: 6, cevbrn: 7, cevfus: 8,
   cevled: 9, cevsaf: 10, cevvlg: 11, cevgno: 12, cevbuc: 13, cevsph: 14, cevegh: 15, cevfor: 16,
   cevscl: 17, cevzgi: 18, cevzgo: 19, cevste: 20, cevmrs: 21, cevpin: 22, cevinq: 23, cevfol: 24
};

// advers.h:
// common /aflags/
struct aflagsCB aflags = (struct aflagsCB){
   astag: 32768
};

// common /aindex/
struct aindexCB aindex = (struct aindexCB){
   player: 1, arobot: 2, amastr: 3
};

// verbs.h:
// common /vindex/
struct vindexCB vindex = (struct vindexCB){
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

// DUNGEON-- MAIN PROGRAM
int MAIN__(void) {
#if 0
   int x;
#endif

// DUNGEON, PAGE 3

// 1) INITIALIZE DATA STRUCTURES
// 2) PLAY GAME

   if (init(/*x*/)) {
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
int dungeo(void) {
   MAIN__();
   return 0;
}
