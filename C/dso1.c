#include "F2C.h"
#include "common.h"

// PRINCR- PRINT CONTENTS OF ROOM

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

void princr_(Bool full, int rm) {
// System generated locals
   int i__1, i__2;

// Local variables
   static int i__, j, k;
   extern Bool qhere_(int, int);
   extern Bool qempty_(int);
   extern void rspeak_(int);
   extern void rspsub_(int, int);
   extern void invent_(int);
   extern int oactor_(int);
   extern void princo_(int, int);

// PRINCR, PAGE 2

   j = 329;
// 						!ASSUME SUPERBRIEF FORMAT.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP ON OBJECTS
      if (!qhere_(i__, rm) || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt + oflags_1.ndscbt) != oflags_1.visibt || i__ == advs_1.avehic[play_1.winner - 1]) {
         goto L500;
      }
      if (!(full) && (findex_1.superf || findex_1.brieff && (rooms_1.rflag[play_1.here - 1] & rflag_1.rseen) != 0)) {
         goto L200;
      }

   // DO LONG DESCRIPTION OF OBJECT.

      k = objcts_1.odesco[i__ - 1];
// 						!GET UNTOUCHED.
      if (k == 0 || (objcts_1.oflag2[i__ - 1] & oflags_1.tchbt) != 0) {
         k = objcts_1.odesc1[i__ - 1];
      }
      rspeak_(k);
// 						!DESCRIBE.
      goto L500;
// DO SHORT DESCRIPTION OF OBJECT.

   L200:
      rspsub_(j, objcts_1.odesc2[i__ - 1]);
// 						!YOU CAN SEE IT.
      j = 502;

   L500:
      ;
   }

// NOW LOOP TO PRINT CONTENTS OF OBJECTS IN ROOM.

   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP ON OBJECTS.
      if (!qhere_(i__, rm) || (objcts_1.oflag1[i__ - 1] & oflags_1.visibt + oflags_1.ndscbt) != oflags_1.visibt) {
         goto L1000;
      }
      if ((objcts_1.oflag2[i__ - 1] & oflags_1.actrbt) != 0) {
         i__2 = oactor_(i__);
         invent_(i__2);
      }
      if ((objcts_1.oflag1[i__ - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[i__ - 1] & oflags_1.openbt) == 0 || qempty_(i__)) {
         goto L1000;
      }

   // OBJECT IS NOT EMPTY AND IS OPEN OR TRANSPARENT.

      j = 573;
      if (i__ != oindex_1.tcase) {
         goto L600;
      }
// 						!TROPHY CASE?
      j = 574;
      if ((findex_1.brieff || findex_1.superf) && !(full)) {
         goto L1000;
      }
   L600:
      princo_(i__, j);
// 						!PRINT CONTENTS.

   L1000:
      ;
   }

}

// INVENT- PRINT CONTENTS OF ADVENTURER

// DECLARATIONS

void invent_(int adv) {
// System generated locals
   int i__1;

// Local variables
   static int i__, j;
   extern void rspeak_(int);
   extern void princo_(int, int);
   extern Bool qempty_(int);
   extern void rspsub_(int, int);

// INVENT, PAGE 2

   i__ = 575;
// 						!FIRST LINE.
   if (adv != aindex_1.player) {
      i__ = 576;
   }
// 						!IF NOT ME.
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!LOOP
      if (objcts_1.oadv[j - 1] != adv || (objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0) {
         goto L10;
      }
      rspsub_(i__, objcts_1.odesc2[advs_1.aobj[adv - 1] - 1]);
      i__ = 0;
      rspsub_(502, objcts_1.odesc2[j - 1]);
   L10:
      ;
   }

   if (i__ == 0) {
      goto L25;
   }
// 						!ANY OBJECTS?
   if (adv == aindex_1.player) {
      rspeak_(578);
   }
// 						!NO, TELL HIM.
   return;

L25:
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!LOOP.
      if (objcts_1.oadv[j - 1] != adv || (objcts_1.oflag1[j - 1] & oflags_1.visibt) == 0 || (objcts_1.oflag1[j - 1] & oflags_1.tranbt) == 0 && (objcts_1.oflag2[j - 1] & oflags_1.openbt) == 0) {
         goto L100;
      }
      if (!qempty_(j)) {
         princo_(j, 573);
      }
// 						!IF NOT EMPTY, LIST.
   L100:
      ;
   }
}

// PRINCO-	PRINT CONTENTS OF OBJECT

// DECLARATIONS

void princo_(int obj, int desc) {
// System generated locals
   int i__1;

// Local variables
   static int i__;
   extern void rspsub_(int, int);

   rspsub_(desc, objcts_1.odesc2[obj - 1]);
// 						!PRINT HEADER.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP THRU.
      if (objcts_1.ocan[i__ - 1] == obj) {
         rspsub_(502, objcts_1.odesc2[i__ - 1]);
      }
// L100:
   }
}
