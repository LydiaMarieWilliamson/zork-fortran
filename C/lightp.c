#include "F2C.h"
#include "common.h"

// LIGHTP-	LIGHT PROCESSOR

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool lightp_(int obj) {
// System generated locals
   Bool ret_val;

// Local variables
   static int flobts;
   extern void rspeak_(int);
   extern void newsta_(int, int, int, int, int);
   static int i__;
   extern void bug_(int, int);

// FUNCTIONS AND DATA

// LIGHTP, PAGE 2

   ret_val = true;
// 						!ASSUME WINS
   flobts = oflags_1.flambt + oflags_1.litebt + oflags_1.onbt;
   if (obj != oindex_1.candl) {
      goto L20000;
   }
// 						!CANDLE?
   if (findex_1.orcand != 0) {
      goto L19100;
   }
// 						!FIRST REF?
   findex_1.orcand = 1;
// 						!YES, CANDLES ARE
   cevent_1.ctick[cindex_1.cevcnd - 1] = 50;
// 						!BURNING WHEN SEEN.

L19100:
   if (prsvec_1.prsi == oindex_1.candl) {
      goto L10;
   }
// 						!IGNORE IND REFS.
   if (prsvec_1.prsa != vindex_1.trnofw) {
      goto L19200;
   }
// 						!TURN OFF?
   i__ = 513;
// 						!ASSUME OFF.
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      i__ = 514;
   }
// 						!IF ON, DIFFERENT.
   cevent_1.cflag[cindex_1.cevcnd - 1] = false;
// 						!DISABLE COUNTDOWN.
   objcts_1.oflag1[oindex_1.candl - 1] &= ~oflags_1.onbt;
   rspeak_(i__);
   return ret_val;

L19200:
   if (prsvec_1.prsa != vindex_1.burnw && prsvec_1.prsa != vindex_1.trnonw) {
      goto L10;
   }
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.litebt) != 0) {
      goto L19300;
   }
   rspeak_(515);
// 						!CANDLES TOO SHORT.
   return ret_val;

L19300:
   if (prsvec_1.prsi != 0) {
      goto L19400;
   }
// 						!ANY FLAME?
   rspeak_(516);
// 						!NO, LOSE.
   prsvec_1.prswon = false;
   return ret_val;

L19400:
   if (prsvec_1.prsi != oindex_1.match || !((objcts_1.oflag1[oindex_1.match - 1] & oflags_1.onbt) != 0)) {
      goto L19500;
   }
   i__ = 517;
// 						!ASSUME OFF.
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      i__ = 518;
   }
// 						!IF ON, JOKE.
   objcts_1.oflag1[oindex_1.candl - 1] |= oflags_1.onbt;
   cevent_1.cflag[cindex_1.cevcnd - 1] = true;
// 						!RESUME COUNTDOWN.
   rspeak_(i__);
   return ret_val;

L19500:
   if (prsvec_1.prsi != oindex_1.torch || !((objcts_1.oflag1[oindex_1.torch - 1] & oflags_1.onbt) != 0)) {
      goto L19600;
   }
   if ((objcts_1.oflag1[oindex_1.candl - 1] & oflags_1.onbt) != 0) {
      goto L19700;
   }
// 						!ALREADY ON?
   newsta_(oindex_1.candl, 521, 0, 0, 0);
// 						!NO, VAPORIZE.
   return ret_val;

L19600:
   rspeak_(519);
// 						!CANT LIGHT WITH THAT.
   return ret_val;

L19700:
   rspeak_(520);
// 						!ALREADY ON.
   return ret_val;

L20000:
   if (obj != oindex_1.match) {
      bug_(6, obj);
   }
   if (prsvec_1.prsa != vindex_1.trnonw || prsvec_1.prso != oindex_1.match) {
      goto L20500;
   }
   if (findex_1.ormtch != 0) {
      goto L20100;
   }
// 						!ANY MATCHES LEFT?
   rspeak_(183);
// 						!NO, LOSE.
   return ret_val;

L20100:
   --findex_1.ormtch;
// 						!DECREMENT NO MATCHES.
   objcts_1.oflag1[oindex_1.match - 1] |= flobts;
   cevent_1.ctick[cindex_1.cevmat - 1] = 2;
// 						!COUNTDOWN.
   rspeak_(184);
   return ret_val;

L20500:
   if (prsvec_1.prsa != vindex_1.trnofw || (objcts_1.oflag1[oindex_1.match - 1] & oflags_1.onbt) == 0) {
      goto L10;
   }
   objcts_1.oflag1[oindex_1.match - 1] &= ~flobts;
   cevent_1.ctick[cindex_1.cevmat - 1] = 0;
   rspeak_(185);
   return ret_val;

// HERE FOR FALSE RETURN

L10:
   ret_val = false;
   return ret_val;
}
