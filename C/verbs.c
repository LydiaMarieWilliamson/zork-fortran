#include "F2C.h"
#include "common.h"

// VAPPLI- MAIN VERB PROCESSING ROUTINE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

Bool vappli_(int ri) {
// Initialized data

   static int mxnop = 39;
   static int mxsmp = 99;

// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   extern void rspeak_(int);
   extern void rspsub_(int, int);
   extern void rspsb2_(int, int, int);
   extern void newsta_(int, int, int, int, int);
   extern void princo_(int, int);
   extern void invent_(int);
   extern void jigsup_(int);
   static int melee;
   extern void savegm_(void);
   extern void rstrgm_(void);
   static Bool f;
   static int i__, j,/* x,*/ av;
   extern void bug_(int, int);
   extern int rnd_(int);
   extern Bool lit_(int);
   static int rmk;
   extern Bool put_(/*Bool*/);
   static int odi2, odo2;
   extern Bool take_(Bool);
   extern Bool walk_(/*int*/);
   extern Bool drop_(/*Bool*/);
   extern int blow_(int, int, int, Bool, int);
   extern Bool qhere_(int, int);
   extern Bool clockd_(/*int*/);
   extern Bool objact_(/*int*/);
   extern Bool rmdesc_(int);
   extern Bool oappli_(int, int);
   extern Bool findxt_(int, int);
   extern Bool sverbs_(int);
   extern Bool qempty_(int);

// FUNCTIONS AND DATA

// VAPPLI, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.

   if (prsvec_1.prso > 220) {
      goto L5;
   }

   if (prsvec_1.prso != 0) {
      odo2 = objcts_1.odesc2[prsvec_1.prso - 1];
   }
// 						!SET UP DESCRIPTORS.
L5:
   if (prsvec_1.prsi != 0) {
      odi2 = objcts_1.odesc2[prsvec_1.prsi - 1];
   }
   av = advs_1.avehic[play_1.winner - 1];
   rmk = rnd_(6) + 372;
// 						!REMARK FOR HACK-HACKS.

   if (ri == 0) {
      goto L10;
   }
// 						!ZERO IS FALSE.
   if (ri <= mxnop) {
      return ret_val;
   }
// 						!NOP?
   if (ri <= mxsmp) {
      goto L100;
   }
// 						!SIMPLE VERB?
   switch (ri - mxsmp) {
      case 1:
         goto L18000;
      case 2:
         goto L20000;
      case 3:
         goto L22000;
      case 4:
         goto L23000;
      case 5:
         goto L24000;
      case 6:
         goto L25000;
      case 7:
         goto L26000;
      case 8:
         goto L27000;
      case 9:
         goto L28000;
      case 10:
         goto L29000;
      case 11:
         goto L30000;
      case 12:
         goto L31000;
      case 13:
         goto L32000;
      case 14:
         goto L33000;
      case 15:
         goto L34000;
      case 16:
         goto L35000;
      case 17:
         goto L36000;
      case 18:
         goto L38000;
      case 19:
         goto L39000;
      case 20:
         goto L40000;
      case 21:
         goto L41000;
      case 22:
         goto L42000;
      case 23:
         goto L43000;
      case 24:
         goto L44000;
      case 25:
         goto L45000;
      case 26:
         goto L46000;
      case 27:
         goto L47000;
      case 28:
         goto L48000;
      case 29:
         goto L49000;
      case 30:
         goto L50000;
      case 31:
         goto L51000;
      case 32:
         goto L52000;
      case 33:
         goto L53000;
      case 34:
         goto L55000;
      case 35:
         goto L56000;
      case 36:
         goto L58000;
      case 37:
         goto L59000;
      case 38:
         goto L60000;
      case 39:
         goto L63000;
      case 40:
         goto L64000;
      case 41:
         goto L65000;
      case 42:
         goto L66000;
      case 43:
         goto L68000;
      case 44:
         goto L69000;
      case 45:
         goto L70000;
      case 46:
         goto L71000;
      case 47:
         goto L72000;
      case 48:
         goto L73000;
      case 49:
         goto L74000;
      case 50:
         goto L77000;
      case 51:
         goto L78000;
      case 52:
         goto L80000;
      case 53:
         goto L81000;
      case 54:
         goto L82000;
      case 55:
         goto L83000;
      case 56:
         goto L84000;
      case 57:
         goto L85000;
      case 58:
         goto L86000;
      case 59:
         goto L87000;
      case 60:
         goto L88000;
   }
   bug_(7, ri);

// ALL VERB PROCESSORS RETURN HERE TO DECLARE FAILURE.

L10:
   ret_val = false;
// 						!LOSE.
   return ret_val;

// SIMPLE VERBS ARE HANDLED EXTERNALLY.

L100:
   ret_val = sverbs_(ri);
   return ret_val;
// VAPPLI, PAGE 3

// V100--	READ.  OUR FIRST REAL VERB.

L18000:
   if (lit_(play_1.here)) {
      goto L18100;
   }
// 						!ROOM LIT?
   rspeak_(356);
// 						!NO, CANT READ.
   return ret_val;

L18100:
   if (prsvec_1.prsi == 0) {
      goto L18200;
   }
// 						!READ THROUGH OBJ?
   if ((objcts_1.oflag1[prsvec_1.prsi - 1] & oflags_1.tranbt) != 0) {
      goto L18200;
   }
   rspsub_(357, odi2);
// 						!NOT TRANSPARENT.
   return ret_val;

L18200:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.readbt) != 0) {
      goto L18300;
   }
   rspsub_(358, odo2);
// 						!NOT READABLE.
   return ret_val;

L18300:
   if (!objact_(/*x*/)) {
      rspeak_(objcts_1.oread[prsvec_1.prso - 1]);
   }
   return ret_val;

// V101--	MELT.  UNLESS OBJECT HANDLES, JOKE.

L20000:
   if (!objact_(/*x*/)) {
      rspsub_(361, odo2);
   }
   return ret_val;

// V102--	INFLATE.  WORKS ONLY WITH BOATS.

L22000:
   if (!objact_(/*x*/)) {
      rspeak_(368);
   }
// 						!OBJ HANDLE?
   return ret_val;

// V103--	DEFLATE.

L23000:
   if (!objact_(/*x*/)) {
      rspeak_(369);
   }
// 						!OBJ HANDLE?
   return ret_val;
// VAPPLI, PAGE 4

// V104--	ALARM.  IF SLEEPING, WAKE HIM UP.

L24000:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.slepbt) == 0) {
      goto L24100;
   }
   ret_val = objact_(/*x*/);
// 						!SLEEPING, LET OBJ DO.
   return ret_val;

L24100:
   rspsub_(370, odo2);
// 						!JOKE.
   return ret_val;

// V105--	EXORCISE.  OBJECTS HANDLE.

L25000:
   f = objact_(/*x*/);
// 						!OBJECTS HANDLE.
   return ret_val;

// V106--	PLUG.  LET OBJECTS HANDLE.

L26000:
   if (!objact_(/*x*/)) {
      rspeak_(371);
   }
   return ret_val;

// V107--	KICK.  IF OBJECT IGNORES, JOKE.

L27000:
   if (!objact_(/*x*/)) {
      rspsb2_(378, odo2, rmk);
   }
   return ret_val;

// V108--	WAVE.  SAME.

L28000:
   if (!objact_(/*x*/)) {
      rspsb2_(379, odo2, rmk);
   }
   return ret_val;

// V109,V110--	RAISE, LOWER.  SAME.

L29000:
L30000:
   if (!objact_(/*x*/)) {
      rspsb2_(380, odo2, rmk);
   }
   return ret_val;

// V111--	RUB.  SAME.

L31000:
   if (!objact_(/*x*/)) {
      rspsb2_(381, odo2, rmk);
   }
   return ret_val;

// V112--	PUSH.  SAME.

L32000:
   if (!objact_(/*x*/)) {
      rspsb2_(382, odo2, rmk);
   }
   return ret_val;
// VAPPLI, PAGE 5

// V113--	UNTIE.  IF OBJECT IGNORES, JOKE.

L33000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJECT HANDLE?
   i__ = 383;
// 						!NO, NOT TIED.
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.tiebt) == 0) {
      i__ = 384;
   }
   rspeak_(i__);
   return ret_val;

// V114--	TIE.  NEVER REALLY WORKS.

L34000:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.tiebt) != 0) {
      goto L34100;
   }
   rspeak_(385);
// 						!NOT TIEABLE.
   return ret_val;

L34100:
   if (!objact_(/*x*/)) {
      rspsub_(386, odo2);
   }
// 						!JOKE.
   return ret_val;

// V115--	TIE UP.  NEVER REALLY WORKS.

L35000:
   if ((objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.tiebt) != 0) {
      goto L35100;
   }
   rspsub_(387, odo2);
// 						!NOT TIEABLE.
   return ret_val;

L35100:
   i__ = 388;
// 						!ASSUME VILLAIN.
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt) == 0) {
      i__ = 389;
   }
   rspsub_(i__, odo2);
// 						!JOKE.
   return ret_val;

// V116--	TURN.  OBJECT MUST HANDLE.

L36000:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.turnbt) != 0) {
      goto L36100;
   }
   rspeak_(390);
// 						!NOT TURNABLE.
   return ret_val;

L36100:
   if ((objcts_1.oflag1[prsvec_1.prsi - 1] & oflags_1.toolbt) != 0) {
      goto L36200;
   }
   rspsub_(391, odi2);
// 						!NOT A TOOL.
   return ret_val;

L36200:
   ret_val = objact_(/*x*/);
// 						!LET OBJECT HANDLE.
   return ret_val;

// V117--	BREATHE.  BECOMES INFLATE WITH LUNGS.

L38000:
   prsvec_1.prsa = vindex_1.inflaw;
   prsvec_1.prsi = oindex_1.lungs;
   goto L22000;
// 						!HANDLE LIKE INFLATE.

// V118--	KNOCK.  MOSTLY JOKE.

L39000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   i__ = 394;
// 						!JOKE FOR DOOR.
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.doorbt) == 0) {
      i__ = 395;
   }
   rspsub_(i__, odo2);
// 						!JOKE FOR NONDOORS TOO.
   return ret_val;

// V119--	LOOK.

L40000:
   if (prsvec_1.prso != 0) {
      goto L41500;
   }
// 						!SOMETHING TO LOOK AT?
   ret_val = rmdesc_(3);
// 						!HANDLED BY RMDESC.
   return ret_val;

// V120--	EXAMINE.

L41000:
   if (prsvec_1.prso != 0) {
      goto L41500;
   }
// 						!SOMETHING TO EXAMINE?
   ret_val = rmdesc_(0);
// 						!HANDLED BY RMDESC.
   return ret_val;

L41500:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   i__ = objcts_1.oread[prsvec_1.prso - 1];
// 						!GET READING MATERIAL.
   if (i__ != 0) {
      rspeak_(i__);
   }
// 						!OUTPUT IF THERE,
   if (i__ == 0) {
      rspsub_(429, odo2);
   }
// 						!OTHERWISE DEFAULT.
   prsvec_1.prsa = vindex_1.foow;
// 						!DEFUSE ROOM PROCESSORS.
   return ret_val;

// V121--	SHAKE.  IF HOLLOW OBJECT, SOME ACTION.

L42000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJECT HANDLE?
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt) == 0) {
      goto L42100;
   }
   rspeak_(371);
// 						!JOKE FOR VILLAINS.
   return ret_val;

L42100:
   if (qempty_(prsvec_1.prso) || (objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.takebt) == 0) {
      goto L10;
   }
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.openbt) != 0) {
      goto L42300;
   }
// 						!OPEN?  SPILL.
   rspsub_(396, odo2);
// 						!NO, DESCRIBE NOISE.
   return ret_val;

L42300:
   rspsub_(397, odo2);
// 						!SPILL THE WORKS.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!SPILL CONTENTS.
      if (objcts_1.ocan[i__ - 1] != prsvec_1.prso) {
         goto L42500;
      }
// 						!INSIDE?
      objcts_1.oflag2[i__ - 1] |= oflags_1.tchbt;
      if (av == 0) {
         goto L42400;
      }
// 						!IN VEHICLE?
      newsta_(i__, 0, 0, av, 0);
// 						!YES, SPILL IN THERE.
      goto L42500;

   L42400:
      newsta_(i__, 0, play_1.here, 0, 0);
// 						!NO, SPILL ON FLOOR,
      if (i__ == oindex_1.water) {
         newsta_(i__, 133, 0, 0, 0);
      }
// 						!BUT WATER DISAPPEARS.
   L42500:
      ;
   }
   return ret_val;

// V122--	MOVE.  MOSTLY JOKES.

L43000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   i__ = 398;
// 						!ASSUME NOT HERE.
   if (qhere_(prsvec_1.prso, play_1.here)) {
      i__ = 399;
   }
   rspsub_(i__, odo2);
// 						!JOKE.
   return ret_val;
// VAPPLI, PAGE 6

// V123--	TURN ON.

L44000:
   f = lit_(play_1.here);
// 						!RECORD IF LIT.
   if (objact_(/*x*/)) {
      goto L44300;
   }
// 						!OBJ HANDLE?
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.litebt) != 0 && objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner) {
      goto L44100;
   }
   rspeak_(400);
// 						!CANT DO IT.
   return ret_val;

L44100:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.onbt) == 0) {
      goto L44200;
   }
   rspeak_(401);
// 						!ALREADY ON.
   return ret_val;

L44200:
   objcts_1.oflag1[prsvec_1.prso - 1] |= oflags_1.onbt;
   rspsub_(404, odo2);
L44300:
   if (!f && lit_(play_1.here)) {
      f = rmdesc_(0);
   }
// 						!ROOM NEWLY LIT.
   return ret_val;

// V124--	TURN OFF.

L45000:
   if (objact_(/*x*/)) {
      goto L45300;
   }
// 						!OBJ HANDLE?
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.litebt) != 0 && objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner) {
      goto L45100;
   }
   rspeak_(402);
// 						!CANT DO IT.
   return ret_val;

L45100:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.onbt) != 0) {
      goto L45200;
   }
   rspeak_(403);
// 						!ALREADY OFF.
   return ret_val;

L45200:
   objcts_1.oflag1[prsvec_1.prso - 1] &= ~oflags_1.onbt;
   rspsub_(405, odo2);
L45300:
   if (!lit_(play_1.here)) {
      rspeak_(406);
   }
// 						!MAY BE DARK.
   return ret_val;

// V125--	OPEN.  A FINE MESS.

L46000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.contbt) != 0) {
      goto L46100;
   }
L46050:
   rspsub_(407, odo2);
// 						!NOT OPENABLE.
   return ret_val;

L46100:
   if (objcts_1.ocapac[prsvec_1.prso - 1] != 0) {
      goto L46200;
   }
   rspsub_(408, odo2);
// 						!NOT OPENABLE.
   return ret_val;

L46200:
   if (!((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.openbt) != 0)) {
      goto L46225;
   }
   rspeak_(412);
// 						!ALREADY OPEN.
   return ret_val;

L46225:
   objcts_1.oflag2[prsvec_1.prso - 1] |= oflags_1.openbt;
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.tranbt) != 0 || qempty_(prsvec_1.prso)) {
      goto L46300;
   }
   princo_(prsvec_1.prso, 410);
// 						!PRINT CONTENTS.
   return ret_val;

L46300:
   rspeak_(409);
// 						!DONE
   return ret_val;

// V126--	CLOSE.

L47000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.contbt) == 0) {
      goto L46050;
   }
   if (objcts_1.ocapac[prsvec_1.prso - 1] != 0) {
      goto L47100;
   }
   rspsub_(411, odo2);
// 						!NOT CLOSABLE.
   return ret_val;

L47100:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.openbt) != 0) {
      goto L47200;
   }
// 						!OPEN?
   rspeak_(413);
// 						!NO, JOKE.
   return ret_val;

L47200:
   objcts_1.oflag2[prsvec_1.prso - 1] &= ~oflags_1.openbt;
   rspeak_(414);
// 						!DONE.
   return ret_val;
// VAPPLI, PAGE 7

// V127--	FIND.  BIG MEGILLA.

L48000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   i__ = 415;
// 						!DEFAULT CASE.
   if (qhere_(prsvec_1.prso, play_1.here)) {
      goto L48300;
   }
// 						!IN ROOM?
   if (objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner) {
      goto L48200;
   }
// 						!ON WINNER?
   j = objcts_1.ocan[prsvec_1.prso - 1];
// 						!DOWN ONE LEVEL.
   if (j == 0) {
      goto L10;
   }
   if ((objcts_1.oflag1[j - 1] & oflags_1.tranbt) == 0 && (!((objcts_1.oflag2[j - 1] & oflags_1.openbt) != 0) || (objcts_1.oflag1[j - 1] & oflags_1.doorbt + oflags_1.contbt) == 0)) {
      goto L10;
   }
   i__ = 417;
// 						!ASSUME IN ROOM.
   if (qhere_(j, play_1.here)) {
      goto L48100;
   }
   if (objcts_1.oadv[j - 1] != play_1.winner) {
      goto L10;
   }
// 						!NOT HERE OR ON PERSON.
   i__ = 418;
L48100:
   rspsub_(i__, objcts_1.odesc2[j - 1]);
// 						!DESCRIBE FINDINGS.
   return ret_val;

L48200:
   i__ = 416;
L48300:
   rspsub_(i__, odo2);
// 						!DESCRIBE FINDINGS.
   return ret_val;

// V128--	WAIT.  RUN CLOCK DEMON.

L49000:
   rspeak_(419);
// 						!TIME PASSES.
   for (i__ = 1; i__ <= 3; ++i__) {
      if (clockd_(/*x*/)) {
         return ret_val;
      }
// L49100:
   }
   return ret_val;

// V129--	SPIN.
// V159--	TURN TO.

L50000:
L88000:
   if (!objact_(/*x*/)) {
      rspeak_(663);
   }
// 						!IF NOT OBJ, JOKE.
   return ret_val;

// V130--	BOARD.  WORKS WITH VEHICLES.

L51000:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.vehbt) != 0) {
      goto L51100;
   }
   rspsub_(421, odo2);
// 						!NOT VEHICLE, JOKE.
   return ret_val;

L51100:
   if (qhere_(prsvec_1.prso, play_1.here)) {
      goto L51200;
   }
// 						!HERE?
   rspsub_(420, odo2);
// 						!NO, JOKE.
   return ret_val;

L51200:
   if (av == 0) {
      goto L51300;
   }
// 						!ALREADY GOT ONE?
   rspsub_(422, odo2);
// 						!YES, JOKE.
   return ret_val;

L51300:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   rspsub_(423, odo2);
// 						!DESCRIBE.
   advs_1.avehic[play_1.winner - 1] = prsvec_1.prso;
   if (play_1.winner != aindex_1.player) {
      objcts_1.ocan[advs_1.aobj[play_1.winner - 1] - 1] = prsvec_1.prso;
   }
   return ret_val;

// V131--	DISEMBARK.

L52000:
   if (av == prsvec_1.prso) {
      goto L52100;
   }
// 						!FROM VEHICLE?
   rspeak_(424);
// 						!NO, JOKE.
   return ret_val;

L52100:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if ((rooms_1.rflag[play_1.here - 1] & rflag_1.rland) != 0) {
      goto L52200;
   }
   rspeak_(425);
// 						!NOT ON LAND.
   return ret_val;

L52200:
   advs_1.avehic[play_1.winner - 1] = 0;
   rspeak_(426);
   if (play_1.winner != aindex_1.player) {
      newsta_(advs_1.aobj[play_1.winner - 1], 0, play_1.here, 0, 0);
   }
   return ret_val;

// V132--	TAKE.  HANDLED EXTERNALLY.

L53000:
   ret_val = take_(true);
   return ret_val;

// V133--	INVENTORY.  PROCESSED EXTERNALLY.

L55000:
   invent_(play_1.winner);
   return ret_val;
// VAPPLI, PAGE 8

// V134--	FILL.  STRANGE DOINGS WITH WATER.

L56000:
   if (prsvec_1.prsi != 0) {
      goto L56050;
   }
// 						!ANY OBJ SPECIFIED?
   if ((rooms_1.rflag[play_1.here - 1] & rflag_1.rwater + rflag_1.rfill) != 0) {
      goto L56025;
   }
   rspeak_(516);
// 						!NOTHING TO FILL WITH.
   prsvec_1.prswon = false;
// 						!YOU LOSE.
   return ret_val;

L56025:
   prsvec_1.prsi = oindex_1.gwate;
// 						!USE GLOBAL WATER.
L56050:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if (prsvec_1.prsi != oindex_1.gwate && prsvec_1.prsi != oindex_1.water) {
      rspsb2_(444, odi2, odo2);
   }
   return ret_val;

// V135,V136--	EAT/DRINK

L58000:
L59000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if (prsvec_1.prso == oindex_1.gwate) {
      goto L59500;
   }
// 						!DRINK GLOBAL WATER?
   if (!((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.foodbt) != 0)) {
      goto L59400;
   }
// 						!EDIBLE?
   if (objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner) {
      goto L59200;
   }
// 						!YES, ON WINNER?
L59100:
   rspsub_(454, odo2);
// 						!NOT ACCESSIBLE.
   return ret_val;

L59200:
   if (prsvec_1.prsa == vindex_1.drinkw) {
      goto L59300;
   }
// 						!DRINK FOOD?
   newsta_(prsvec_1.prso, 455, 0, 0, 0);
// 						!NO, IT DISAPPEARS.
   return ret_val;

L59300:
   rspeak_(456);
// 						!YES, JOKE.
   return ret_val;

L59400:
   if (!((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.drnkbt) != 0)) {
      goto L59600;
   }
// 						!DRINKABLE?
   if (objcts_1.ocan[prsvec_1.prso - 1] == 0) {
      goto L59100;
   }
// 						!YES, IN SOMETHING?
   if (objcts_1.oadv[objcts_1.ocan[prsvec_1.prso - 1] - 1] != play_1.winner) {
      goto L59100;
   }
   if ((objcts_1.oflag2[objcts_1.ocan[prsvec_1.prso - 1] - 1] & oflags_1.openbt) != 0) {
      goto L59500;
   }
// 						!CONT OPEN?
   rspeak_(457);
// 						!NO, JOKE.
   return ret_val;

L59500:
   newsta_(prsvec_1.prso, 458, 0, 0, 0);
// 						!GONE.
   return ret_val;

L59600:
   rspsub_(453, odo2);
// 						!NOT FOOD OR DRINK.
   return ret_val;

// V137--	BURN.  COMPLICATED.

L60000:
   if ((objcts_1.oflag1[prsvec_1.prsi - 1] & oflags_1.flambt + oflags_1.litebt + oflags_1.onbt) != oflags_1.flambt + oflags_1.litebt + oflags_1.onbt) {
      goto L60400;
   }
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if (objcts_1.ocan[prsvec_1.prso - 1] != oindex_1.recep) {
      goto L60050;
   }
// 						!BALLOON?
   if (oappli_(objcts_1.oactio[oindex_1.ballo - 1], 0)) {
      return ret_val;
   }
// 						!DID IT HANDLE?
L60050:
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.burnbt) == 0) {
      goto L60300;
   }
   if (objcts_1.oadv[prsvec_1.prso - 1] != play_1.winner) {
      goto L60100;
   }
// 						!CARRYING IT?
   rspsub_(459, odo2);
   jigsup_(460);
   return ret_val;

L60100:
   j = objcts_1.ocan[prsvec_1.prso - 1];
// 						!GET CONTAINER.
   if (qhere_(prsvec_1.prso, play_1.here) || av != 0 && j == av) {
      goto L60200;
   }
   if (j == 0) {
      goto L60150;
   }
// 						!INSIDE?
   if (!((objcts_1.oflag2[j - 1] & oflags_1.openbt) != 0)) {
      goto L60150;
   }
// 						!OPEN?
   if (qhere_(j, play_1.here) || av != 0 && objcts_1.ocan[j - 1] == av) {
      goto L60200;
   }
L60150:
   rspeak_(461);
// 						!CANT REACH IT.
   return ret_val;

L60200:
   rspsub_(462, odo2);
// 						!BURN IT.
   newsta_(prsvec_1.prso, 0, 0, 0, 0);
   return ret_val;

L60300:
   rspsub_(463, odo2);
// 						!CANT BURN IT.
   return ret_val;

L60400:
   rspsub_(301, odi2);
// 						!CANT BURN IT WITH THAT.
   return ret_val;
// VAPPLI, PAGE 9

// V138--	MUNG.  GO TO COMMON ATTACK CODE.

L63000:
   i__ = 466;
// 						!CHOOSE PHRASE.
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt) != 0) {
      goto L66100;
   }
   if (!objact_(/*x*/)) {
      rspsb2_(466, odo2, rmk);
   }
   return ret_val;

// V139--	KILL.  GO TO COMMON ATTACK CODE.

L64000:
   i__ = 467;
// 						!CHOOSE PHRASE.
   goto L66100;

// V140--	SWING.  INVERT OBJECTS, FALL THRU TO ATTACK.

L65000:
   j = prsvec_1.prso;
// 						!INVERT.
   prsvec_1.prso = prsvec_1.prsi;
   prsvec_1.prsi = j;
   j = odo2;
   odo2 = odi2;
   odi2 = j;
   prsvec_1.prsa = vindex_1.attacw;
// 						!FOR OBJACT.

// V141--	ATTACK.  FALL THRU TO ATTACK CODE.

L66000:
   i__ = 468;

// COMMON MUNG/ATTACK/SWING/KILL CODE.

L66100:
   if (prsvec_1.prso != 0) {
      goto L66200;
   }
// 						!ANYTHING?
   rspeak_(469);
// 						!NO, JOKE.
   return ret_val;

L66200:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt) != 0) {
      goto L66300;
   }
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.victbt) == 0) {
      rspsub_(470, odo2);
   }
   return ret_val;

L66300:
   j = 471;
// 						!ASSUME NO WEAPON.
   if (prsvec_1.prsi == 0) {
      goto L66500;
   }
   if ((objcts_1.oflag2[prsvec_1.prsi - 1] & oflags_1.weapbt) == 0) {
      goto L66400;
   }
   melee = 1;
// 						!ASSUME SWORD.
   if (prsvec_1.prsi != oindex_1.sword) {
      melee = 2;
   }
// 						!MUST BE KNIFE.
   i__ = blow_(aindex_1.player, prsvec_1.prso, melee, true, 0);
// 						!STRIKE BLOW.
   return ret_val;

L66400:
   j = 472;
// 						!NOT A WEAPON.
L66500:
   rspsb2_(i__, odo2, j);
// 						!JOKE.
   return ret_val;
// VAPPLI, PAGE 10

// V142--	WALK.  PROCESSED EXTERNALLY.

L68000:
   ret_val = walk_(/*x*/);
   return ret_val;

// V143--	TELL.  PROCESSED IN GAME.

L69000:
   rspeak_(603);
   return ret_val;

// V144--	PUT.  PROCESSED EXTERNALLY.

L70000:
   ret_val = put_(/*true*/);
   return ret_val;

// V145,V146,V147,V148--	DROP/GIVE/POUR/THROW

L71000:
L72000:
L73000:
L74000:
   ret_val = drop_(/*false*/);
   return ret_val;

// V149--	SAVE

L77000:
   if ((rooms_1.rflag[rindex_1.tstrs - 1] & rflag_1.rseen) == 0) {
      goto L77100;
   }
   rspeak_(828);
// 						!NO SAVES IN ENDGAME.
   return ret_val;

L77100:
   savegm_();
   return ret_val;

// V150--	RESTORE

L78000:
   if ((rooms_1.rflag[rindex_1.tstrs - 1] & rflag_1.rseen) == 0) {
      goto L78100;
   }
   rspeak_(829);
// 						!NO RESTORES IN ENDGAME.
   return ret_val;

L78100:
   rstrgm_();
   return ret_val;
// VAPPLI, PAGE 11

// V151--	HELLO

L80000:
   if (prsvec_1.prso != 0) {
      goto L80100;
   }
// 						!ANY OBJ?
   i__1 = rnd_(4) + 346;
   rspeak_(i__1);
// 						!NO, VANILLA HELLO.
   return ret_val;

L80100:
   if (prsvec_1.prso != oindex_1.aviat) {
      goto L80200;
   }
// 						!HELLO AVIATOR?
   rspeak_(350);
// 						!NOTHING HAPPENS.
   return ret_val;

L80200:
   if (prsvec_1.prso != oindex_1.sailo) {
      goto L80300;
   }
// 						!HELLO SAILOR?
   ++state_1.hs;
// 						!COUNT.
   i__ = 351;
// 						!GIVE NORMAL OR
   if (state_1.hs % 10 == 0) {
      i__ = 352;
   }
// 						!RANDOM MESSAGE.
   if (state_1.hs % 20 == 0) {
      i__ = 353;
   }
   rspeak_(i__);
// 						!SPEAK UP.
   return ret_val;

L80300:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   i__ = 354;
// 						!ASSUME VILLAIN.
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.villbt + oflags_1.actrbt) == 0) {
      i__ = 355;
   }
   rspsub_(i__, odo2);
// 						!HELLO THERE
// 						!
   return ret_val;

// V152--	LOOK INTO

L81000:
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.doorbt) == 0) {
      goto L81300;
   }
   if (!((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.openbt) != 0)) {
      goto L81200;
   }
// 						!OPEN?
   rspsub_(628, odo2);
// 						!OPEN DOOR- UNINTERESTING.
   return ret_val;

L81200:
   rspsub_(525, odo2);
// 						!CLOSED DOOR- CANT SEE.
   return ret_val;

L81300:
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.vehbt) != 0) {
      goto L81400;
   }
   if ((objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.openbt) != 0 || (objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.tranbt) != 0) {
      goto L81400;
   }
   if ((objcts_1.oflag1[prsvec_1.prso - 1] & oflags_1.contbt) != 0) {
      goto L81200;
   }
   rspsub_(630, odo2);
// 						!CANT LOOK INSIDE.
   return ret_val;

L81400:
   if (qempty_(prsvec_1.prso)) {
      goto L81500;
   }
// 						!VEH OR SEE IN.  EMPTY?
   princo_(prsvec_1.prso, 573);
// 						!NO, LIST CONTENTS.
   return ret_val;

L81500:
   rspsub_(629, odo2);
// 						!EMPTY.
   return ret_val;

// V153--	LOOK UNDER

L82000:
   if (!objact_(/*x*/)) {
      rspeak_(631);
   }
// 						!OBJECT HANDLE?
   return ret_val;
// VAPPLI, PAGE 12

// V154--	PUMP

L83000:
   if (objcts_1.oroom[oindex_1.pump - 1] == play_1.here || objcts_1.oadv[oindex_1.pump - 1] == play_1.winner) {
      goto L83100;
   }
   rspeak_(632);
// 						!NO.
   return ret_val;

L83100:
   prsvec_1.prsi = oindex_1.pump;
// 						!BECOMES INFLATE
   prsvec_1.prsa = vindex_1.inflaw;
// 						!X WITH PUMP.
   goto L22000;
// 						!DONE.

// V155--	WIND

L84000:
   if (!objact_(/*x*/)) {
      rspsub_(634, odo2);
   }
// 						!OBJ HANDLE?
   return ret_val;

// V156--	CLIMB
// V157--	CLIMB UP
// V158--	CLIMB DOWN

L85000:
L86000:
L87000:
   i__ = xsrch_1.xup;
// 						!ASSUME UP.
   if (prsvec_1.prsa == vindex_1.clmbdw) {
      i__ = xsrch_1.xdown;
   }
// 						!UNLESS CLIMB DN.
   f = (objcts_1.oflag2[prsvec_1.prso - 1] & oflags_1.clmbbt) != 0;
   if (f && findxt_(i__, play_1.here)) {
      goto L87500;
   }
// 						!ANYTHING TO CLIMB?
   if (objact_(/*x*/)) {
      return ret_val;
   }
// 						!OBJ HANDLE?
   i__ = 657;
   if (f) {
      i__ = 524;
   }
// 						!VARIETY OF JOKES.
   if (!f && (prsvec_1.prso == oindex_1.wall || prsvec_1.prso >= oindex_1.wnort && prsvec_1.prso <= oindex_1.wnort + 3)) {
      i__ = 656;
   }
   rspeak_(i__);
// 						!JOKE.
   return ret_val;

L87500:
   prsvec_1.prsa = vindex_1.walkw;
// 						!WALK
   prsvec_1.prso = i__;
// 						!IN SPECIFIED DIR.
   ret_val = walk_(/*x*/);
   return ret_val;

}

// CLOCKD- CLOCK DEMON FOR INTERMOVE CLOCK EVENTS

// DECLARATIONS

Bool clockd_(/*int x*/) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int i__;
   extern void cevapp_(int);

   ret_val = false;
// 						!ASSUME NO ACTION.
   i__1 = cevent_1.clnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (!cevent_1.cflag[i__ - 1] || cevent_1.ctick[i__ - 1] == 0) {
         goto L100;
      }
      if (cevent_1.ctick[i__ - 1] < 0) {
         goto L50;
      }
// 						!PERMANENT ENTRY?
      --cevent_1.ctick[i__ - 1];
      if (cevent_1.ctick[i__ - 1] != 0) {
         goto L100;
      }
// 						!TIMER EXPIRED?
   L50:
      ret_val = true;
      cevapp_(cevent_1.cactio[i__ - 1]);
// 						!DO ACTION.
   L100:
      ;
   }
   return ret_val;

}
