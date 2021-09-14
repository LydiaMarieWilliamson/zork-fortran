#include "F2C.h"

// Common Block Declarations

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
   int mbase, strbit;
} star_;

#define star_1 star_

struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

// Table of constant values

static int c__60 = 60;

// GHERE--	IS GLOBAL ACTUALLY IN THIS ROOM?

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool ghere_(int * obj, int * rm) {
// System generated locals
   Bool ret_val;

// Local variables
   extern Void bug_(int *, int *);
#define eqr ((int *)&rooms_1 + 2)
#define rrand ((int *)&rooms_1 + 602)

// ROOMS

// GHERE, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   switch (*obj - star_1.strbit) {
      case 1:
         goto L1000;
      case 2:
         goto L1000;
      case 3:
         goto L1000;
      case 4:
         goto L1000;
      case 5:
         goto L1000;
      case 6:
         goto L1000;
      case 7:
         goto L1000;
      case 8:
         goto L1000;
      case 9:
         goto L1000;
      case 10:
         goto L1000;
      case 11:
         goto L1000;
      case 12:
         goto L2000;
      case 13:
         goto L3000;
      case 14:
         goto L4000;
      case 15:
         goto L5000;
      case 16:
         goto L5000;
      case 17:
         goto L5000;
      case 18:
         goto L6000;
      case 19:
         goto L7000;
      case 20:
         goto L8000;
      case 21:
         goto L9000;
      case 22:
         goto L9100;
      case 23:
         goto L8000;
      case 24:
         goto L10000;
      case 25:
         goto L11000;
   }
   bug_(&c__60, obj);

// 1000--	STARS ARE ALWAYS HERE

L1000:
   return ret_val;

// 2000--	BIRD

L2000:
   ret_val = *rm >= rindex_1.fore1 && *rm < rindex_1.clear || *rm == rindex_1.mtree;
   return ret_val;

// 3000--	TREE

L3000:
   ret_val = *rm >= rindex_1.fore1 && *rm < rindex_1.clear && *rm != rindex_1.fore3;
   return ret_val;

// 4000--	NORTH WALL

L4000:
   ret_val = *rm >= rindex_1.bkvw && *rm <= rindex_1.bkbox || *rm == rindex_1.cpuzz;
   return ret_val;

// 5000--	EAST, SOUTH, WEST WALLS

L5000:
   ret_val = *rm >= rindex_1.bkvw && *rm < rindex_1.bkbox || *rm == rindex_1.cpuzz;
   return ret_val;

// 6000--	GLOBAL WATER

L6000:
   ret_val = (rooms_1.rflag[*rm - 1] & rflag_1.rwater + rflag_1.rfill) != 0;
   return ret_val;

// 7000--	GLOBAL GUARDIANS

L7000:
   ret_val = *rm >= rindex_1.mrc && *rm <= rindex_1.mrd || *rm >= rindex_1.mrce && *rm <= rindex_1.mrdw || *rm == rindex_1.inmir;
   return ret_val;

// 8000--	ROSE/CHANNEL

L8000:
   ret_val = *rm >= rindex_1.mra && *rm <= rindex_1.mrd || *rm == rindex_1.inmir;
   return ret_val;

// 9000--	MIRROR
// 9100		PANEL

L9100:
   if (*rm == rindex_1.fdoor) {
      return ret_val;
   }
// 						!PANEL AT FDOOR.
L9000:
   ret_val = *rm >= rindex_1.mra && *rm <= rindex_1.mrc || *rm >= rindex_1.mrae && *rm <= rindex_1.mrcw;
   return ret_val;

// 10000--	MASTER

L10000:
   ret_val = *rm == rindex_1.fdoor || *rm == rindex_1.ncorr || *rm == rindex_1.parap || *rm == rindex_1.cell;
   return ret_val;

// 11000--	LADDER

L11000:
   ret_val = *rm == rindex_1.cpuzz;
   return ret_val;

}

#undef rrand
#undef eqr

// MRHERE--	IS MIRROR HERE?

// DECLARATIONS

int mrhere_(int * rm) {
// System generated locals
   int ret_val, i__1;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// ROOMS

// MRHERE, PAGE 2

// FLAGS

   if (*rm < rindex_1.mrae || *rm > rindex_1.mrdw) {
      goto L100;
   }

// RM IS AN E-W ROOM, MIRROR MUST BE N-S (MDIR= 0 OR 180)

   ret_val = 1;
// 						!ASSUME MIRROR 1 HERE.
   if ((*rm - rindex_1.mrae) % 2 == findex_1.mdir / 180) {
      ret_val = 2;
   }
   return ret_val;

// RM IS NORTH OR SOUTH OF MIRROR.  IF MIRROR IS N-S OR NOT
// WITHIN ONE ROOM OF RM, LOSE.

L100:
   ret_val = 0;
   if ((i__1 = findex_1.mloc - *rm, abs(i__1)) != 1 || findex_1.mdir % 180 == 0) {
      return ret_val;
   }

// RM IS WITHIN ONE OF MLOC, AND MDIR IS E-W

   ret_val = 1;
   if (*rm < findex_1.mloc && findex_1.mdir < 180 || *rm > findex_1.mloc && findex_1.mdir > 180) {
      ret_val = 2;
   }
   return ret_val;
}

#undef switch__
#undef flags
