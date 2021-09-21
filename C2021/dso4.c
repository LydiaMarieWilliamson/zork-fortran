// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

// Steal winner's valuables
int robadv(int adv, int nr, int nc, int na) {
// System generated locals
   int ret_val, i__1;

// Local variables
   int i;

   ret_val = 0;
// 						!COUNT OBJECTS
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
      if (objcts_1.oadv[i - 1] != adv || objcts_1.otval[i - 1] <= 0 || (objcts_1.oflag2[i - 1] & ScrDO) != 0) {
         goto L100;
      }
      newsta(i, 0, nr, nc, na);
// 						!STEAL OBJECT
      ++ret_val;
   L100:
      ;
   }
   return ret_val;
}

// Steal room valuables
int robrm(int rm, int pr, int nr, int nc, int na) {
// System generated locals
   int ret_val, i__1, i__2;

// Local variables
   int i;

   ret_val = 0;
// 						!COUNT OBJECTS
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOP ON OBJECTS.
      if (!qhere(i, rm)) {
         goto L100;
      }
      if (objcts_1.otval[i - 1] <= 0 || (objcts_1.oflag2[i - 1] & ScrDO) != 0 || (objcts_1.oflag1[i - 1] & VisiO) == 0 || !prob(pr, pr)) {
         goto L50;
      }
      newsta(i, 0, nr, nc, na);
      ++ret_val;
      objcts_1.oflag2[i - 1] |= TChO;
      goto L100;
   L50:
      if ((objcts_1.oflag2[i - 1] & ActrO) != 0) {
         i__2 = oactor(i);
         ret_val += robadv(i__2, nr, nc, na);
      }
   L100:
      ;
   }
   return ret_val;
}

// See if villain is winning
Bool winnin(int vl, int hr) {
// System generated locals
   Bool ret_val;

// Local variables
   int ps, vs;

   vs = objcts_1.ocapac[vl - 1];
// 						!VILLAIN STRENGTH
   ps = vs - fights(hr, true);
// 						!HIS MARGIN OVER HERO
   ret_val = prob(90, 100);
   if (ps > 3) {
      return ret_val;
   }
// 						!+3... 90% WINNING
   ret_val = prob(75, 85);
   if (ps > 0) {
      return ret_val;
   }
// 						!>0... 75% WINNING
   ret_val = prob(50, 30);
   if (ps == 0) {
      return ret_val;
   }
// 						!=0... 50% WINNING
   ret_val = prob(25, 25);
   if (vs > 1) {
      return ret_val;
   }
// 						!ANY VILLAIN STRENGTH.
   ret_val = prob(10, 0);
   return ret_val;
}

// Compute fight strength
int fights(int h, Bool flg) {
// Initialized data
   const int smin = 2;
   const int smax = 7;

// System generated locals
   int ret_val;

// Local variables

// GAME STATE

   ret_val = smin + ((smax - smin) * advs_1.ascore[(20 + (0 + (h - 1 << 2)) - 20) / 4] + state_1.mxscor / 2) / state_1.mxscor;
   if (flg) {
      ret_val += advs_1.astren[h - 1];
   }
   return ret_val;
}

// Compute villain strength
int vilstr(int v) {
// System generated locals
   int ret_val, i__1, i__2, i__3;

// Local variables
   int i;

// VILSTR, PAGE 2

   ret_val = objcts_1.ocapac[v - 1];
   if (ret_val <= 0) {
      return ret_val;
   }
   if (v != oindex_1.thief || !findex_1.thfenf) {
      goto L100;
   }
   findex_1.thfenf = false;
// 						!THIEF UNENGROSSED.
   ret_val = min(ret_val, 2);
// 						!NO BETTER THAN 2.

L100:
   i__1 = vill_1.vlnt;
   for (i = 1; i <= i__1; ++i) {
// 						!SEE IF  BEST WEAPON.
      if (vill_1.villns[i - 1] == v && prsvec_1.prsi == vill_1.vbest[i - 1]) {
// Computing MAX
         i__2 = 1, i__3 = ret_val - 1;
         ret_val = max(i__2, i__3);
      }
// L200:
   }
   return ret_val;
}
