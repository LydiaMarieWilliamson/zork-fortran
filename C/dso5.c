#include "F2C.h"
#include "common.h"
#include "extern.h"

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// GTTIME-- GET TOTAL TIME PLAYED

// DECLARATIONS

int gttime_(void) {
   static int h__, m, s;

   intime_(&h__, &m, &s);
   int t = h__ * 60 + m - (time_1.shour * 60 + time_1.smin);
   if (t < 0) {
      t += 1440;
   }
   return t += time_1.pltime;
}

// OPNCLS-- PROCESS OPEN/CLOSE FOR DOORS

// DECLARATIONS

Bool opncls_(int obj, int so, int sc) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables

// FUNCTIONS AND DATA

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prsa == vindex_1.closew) {
      goto L100;
   }
// 						!CLOSE?
   if (prsvec_1.prsa == vindex_1.openw) {
      goto L50;
   }
// 						!OPEN?
   ret_val = false;
// 						!LOSE
   return ret_val;

L50:
   if ((objcts_1.oflag2[obj - 1] & oflags_1.openbt) != 0) {
      goto L200;
   }
// 						!OPEN... IS IT?
   rspeak_(so);
   objcts_1.oflag2[obj - 1] |= oflags_1.openbt;
   return ret_val;

L100:
   if (!((objcts_1.oflag2[obj - 1] & oflags_1.openbt) != 0)) {
      goto L200;
   }
// 						!CLOSE... IS IT?
   rspeak_(sc);
   objcts_1.oflag2[obj - 1] &= ~oflags_1.openbt;
   return ret_val;

L200:
   i__1 = rnd_(3) + 125;
   rspeak_(i__1);
// 						!DUMMY.
   return ret_val;
}

// LIT-- IS ROOM LIT?

// DECLARATIONS

Bool lit_(int rm) {
// System generated locals
   int i__1, i__2;
   Bool ret_val;

// Local variables
   static int i, j, oa;

   ret_val = true;
// 						!ASSUME WINS
   if ((rooms_1.rflag[rm - 1] & rflag_1.rlight) != 0) {
      return ret_val;
   }

   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOK FOR LIT OBJ
      if (qhere_(i, rm)) {
         goto L100;
      }
// 						!IN ROOM?
      oa = objcts_1.oadv[i - 1];
// 						!NO
      if (oa <= 0) {
         goto L1000;
      }
// 						!ON ADV?
      if (advs_1.aroom[oa - 1] != rm) {
         goto L1000;
      }
// 						!ADV IN ROOM?

// OBJ IN ROOM OR ON ADV IN ROOM

   L100:
      if ((objcts_1.oflag1[i - 1] & oflags_1.onbt) != 0) {
         return ret_val;
      }
      if ((objcts_1.oflag1[i - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[i - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[i - 1] & oflags_1.openbt) == 0) {
         goto L1000;
      }

   // OBJ IS VISIBLE AND OPEN OR TRANSPARENT

      i__2 = objcts_1.olnt;
      for (j = 1; j <= i__2; ++j) {
         if (objcts_1.ocan[j - 1] == i && (objcts_1.oflag1[j - 1] & oflags_1.onbt) != 0) {
            return ret_val;
         }
   // L500:
      }
   L1000:
      ;
   }
   ret_val = false;
   return ret_val;
}

// WEIGHT- RETURNS SUM OF WEIGHT OF QUALIFYING OBJECTS

// DECLARATIONS

int weight_(int rm, int cn, int ad) {
// System generated locals
   int ret_val, i__1;

// Local variables
   static int i, j;

   ret_val = 0;
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!OMIT BIG FIXED ITEMS.
      if (objcts_1.osize[i - 1] >= 10000) {
         goto L100;
      }
// 						!IF FIXED, FORGET IT.
      if (qhere_(i, rm) && rm != 0 || objcts_1.oadv[i - 1] == ad && ad != 0) {
         goto L50;
      }
      j = i;
// 						!SEE IF CONTAINED.
   L25:
      j = objcts_1.ocan[j - 1];
// 						!GET NEXT LEVEL UP.
      if (j == 0) {
         goto L100;
      }
// 						!END OF LIST?
      if (j != cn) {
         goto L25;
      }
   L50:
      ret_val += objcts_1.osize[i - 1];
   L100:
      ;
   }
   return ret_val;
}
