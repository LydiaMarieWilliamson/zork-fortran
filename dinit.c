#include "F2C.h"
#include "common.h"
#include "extern.h"

// INIT-- DUNGEON INITIALIZATION SUBROUTINE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS
static Bool protct_(int);

Bool init_(int x) {
// Format strings
   static char fmt_0[] = "(\002 Suddenly a sinister, wraithlike figure appears before \002,\002you,\002/\002 seeming to float in the air.  In a low, sorrowful voice\002,\002 he says,\002/\002 \"Alas, the very nature of the world has changed, \002,\002and the dungeon\002/\002 cannot be found.  All must now pass away.\"\002,\002  Raising his oaken staff\002/\002 in farewell, he fades into the \002,\002spreading darkness.  In his place\002/\002 appears a tastefully \002,\002lettered sign reading:\002//23x,\002INITIALIZATION FAILURE\002//\002 The darkness becomes all encompassing, and your vision fails.\002)";

// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   int xmax, r2max, dirmax, recno;
   int i, j, k;
   int mmax, omax, rmax, vmax, amax, cmax, fmax, smax;

// MISCELLANEOUS VARIABLES

// INIT, PAGE 2

// FIRST CHECK FOR PROTECTION VIOLATION

   if (protct_(x)) {
      goto L10000;
   }
// 						!PROTECTION VIOLATION?
   BegExSF(6, /*10100*/"(\002 There appears before you a threatening figure clad \002,\002all over\002/\002 in heavy black armor.  His legs seem like the \002,\002massive trunk\002/\002 of the oak tree.  His broad shoulders and \002,\002helmeted head loom\002/\002 high over your own puny frame, and \002,\002you realize that his powerful\002/\002 arms could easily crush the \002,\002very life from your body.  There\002/\002 hangs from his belt a \002,\002veritable arsenal of deadly weapons:\002/\002 sword, mace, ball \002,\002and chain, dagger, lance, and trident.\002/\002 He speaks with a \002,\002commanding voice:\002//20x,\002\"You shall not pass.\"\002//\002 As \002,\002he grabs you by the neck all grows dim about you.\002)", 0);
   EndExSF();
   exit_();

// NOW START INITIALIZATION PROPER

L10000:
   ret_val = false;
// 						!ASSUME INIT FAILS.
   mmax = 1820;
// 						!SET UP ARRAY LIMITS.
   omax = 220;
   rmax = 200;
   vmax = 4;
   amax = 4;
   cmax = 25;
   fmax = 46;
   smax = 22;
   xmax = 900;
   r2max = 20;
   dirmax = 15;

   rmsg_1.mlnt = 0;
// 						!INIT ARRAY COUNTERS.
   objcts_1.olnt = 0;
   rooms_1.rlnt = 0;
   vill_1.vlnt = 0;
   advs_1.alnt = 0;
   cevent_1.clnt = 0;
   exits_1.xlnt = 1;
   oroom2_1.r2lnt = 0;

   state_1.ltshft = 10;
// 						!SET UP STATE VARIABLES.
   state_1.mxscor = state_1.ltshft;
   state_1.egscor = 0;
   state_1.egmxsc = 0;
   state_1.mxload = 100;
   state_1.rwscor = 0;
   state_1.deaths = 0;
   state_1.moves = 0;
   time_1.pltime = 0;
   state_1.mungrm = 0;
   state_1.hs = 0;
   prsvec_1.prsa = 0;
// 						!CLEAR PARSE VECTOR.
   prsvec_1.prsi = 0;
   prsvec_1.prso = 0;
   prsvec_1.prscon = 1;
   orphs_1.oflag = 0;
// 						!CLEAR ORPHANS.
   orphs_1.oact = 0;
   orphs_1.oslot = 0;
   orphs_1.oprep = 0;
   orphs_1.oname = 0;
   hack_1.thfflg = false;
// 						!THIEF NOT INTRODUCED BUT
   hack_1.thfact = true;
// 						!IS ACTIVE.
   hack_1.swdact = false;
// 						!SWORD IS INACTIVE.
   hack_1.swdsta = 0;
// 						!SWORD IS OFF.

   recno = 1;
// 						!INIT DB FILE POINTER.
   star_1.mbase = 0;
// 						!INIT MELEE BASE.
//   LOGICAL UNIT NRS: 5=STDIN, 6=STDOUT
   chan_1.inpch = 5;
// 						!TTY INPUT
   chan_1.outch = 6;
   chan_1.dbch = 2;
// 						!DATA BASE.
// INIT, PAGE 3

// INIT ALL ARRAYS.

   i__1 = cmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR CLOCK EVENTS
      cevent_1.cflag[i - 1] = false;
      cevent_1.ctick[i - 1] = 0;
      cevent_1.cactio[i - 1] = 0;
// L5:
   }

   i__1 = fmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR FLAGS.
      flags[i - 1] = false;
// L10:
   }
   findex_1.buoyf = true;
// 						!SOME START AS TRUE.
   findex_1.egyptf = true;
   findex_1.cagetf = true;
   findex_1.mr1f = true;
   findex_1.mr2f = true;
   findex_1.follwf = true;
   i__1 = smax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR SWITCHES.
      switch__[i - 1] = 0;
// L12:
   }
   findex_1.ormtch = 4;
// 						!NUMBER OF MATCHES.
   findex_1.lcell = 1;
   findex_1.pnumb = 1;
   findex_1.mdir = 270;
   findex_1.mloc = rindex_1.mrb;
   findex_1.cphere = 10;

   i__1 = r2max;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR ROOM 2 ARRAY.
      oroom2_1.rroom2[i - 1] = 0;
      oroom2_1.oroom2[i - 1] = 0;
// L15:
   }

   i__1 = xmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR TRAVEL ARRAY.
      exits_1.travel[i - 1] = 0;
// L20:
   }

   i__1 = vmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR VILLAINS ARRAYS.
      vill_1.vopps[i - 1] = 0;
      vill_1.vprob[i - 1] = 0;
      vill_1.villns[i - 1] = 0;
      vill_1.vbest[i - 1] = 0;
      vill_1.vmelee[i - 1] = 0;
// L30:
   }

   i__1 = omax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR OBJECT ARRAYS.
      objcts_1.odesc1[i - 1] = 0;
      objcts_1.odesc2[i - 1] = 0;
      objcts_1.odesco[i - 1] = 0;
      objcts_1.oread[i - 1] = 0;
      objcts_1.oactio[i - 1] = 0;
      objcts_1.oflag1[i - 1] = 0;
      objcts_1.oflag2[i - 1] = 0;
      objcts_1.ofval[i - 1] = 0;
      objcts_1.otval[i - 1] = 0;
      objcts_1.osize[i - 1] = 0;
      objcts_1.ocapac[i - 1] = 0;
      objcts_1.ocan[i - 1] = 0;
      objcts_1.oadv[i - 1] = 0;
      objcts_1.oroom[i - 1] = 0;
// L40:
   }

   rooms_1.rdesc2 = 0;
// 						!CLEAR DESC BASE PTR.
   i__1 = rmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR ROOM ARRAYS.
      rooms_1.rdesc1[i - 1] = 0;
      rooms_1.ractio[i - 1] = 0;
      rooms_1.rflag[i - 1] = 0;
      rooms_1.rval[i - 1] = 0;
      rooms_1.rexit[i - 1] = 0;
// L50:
   }

   i__1 = mmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR MESSAGE DIRECTORY.
      rmsg_1.rtext[i - 1] = 0;
// L60:
   }

   i__1 = amax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR ADVENTURER'S ARRAYS.
      advs_1.aroom[i - 1] = 0;
      advs_1.ascore[i - 1] = 0;
      advs_1.avehic[i - 1] = 0;
      advs_1.aobj[i - 1] = 0;
      advs_1.aactio[i - 1] = 0;
      advs_1.astren[i - 1] = 0;
      advs_1.aflag[i - 1] = 0;
// L70:
   }

   debug_1.dbgflg = 0;
   debug_1.prsflg = 0;

// allow setting gdtflg true if user id matches wizard id
// this way, the wizard doesn't have to recompile to use gdt

// 	Changed by TAA so that always in wizard ID
// D	gdtflg=1

   screen_1.fromdr = 0;
// 						!INIT SCOL GOODIES.
   screen_1.scolrm = 0;
   screen_1.scolac = 0;
// INIT, PAGE 4

// NOW RESTORE FROM EXISTING INDEX FILE.

// 	OPEN(UNIT=1,file='/usr/share/games/dungeon/dindx.dat',
   i__1 = OpenF(1, "dindx.dat", "OLD", "SEQUENTIAL", "FORMATTED", 0);
   if (i__1 != 0) {
      goto L1900;
   }

   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &i, sizeof i);
   DoFio(1, &j, sizeof j);
   DoFio(1, &k, sizeof k);
   EndInSF();
// 						!GET VERSION.
   if (i != vers_2.vmaj || j != vers_2.vmin) {
      goto L1925;
   }
// 	OPEN(UNIT=DBCH,file='/usr/share/games/dungeon/dtext.dat',
   i__1 = OpenF(chan_1.dbch, "dtext.dat", "OLD", "DIRECT", "UNFORMATTED", 76);
   if (i__1 != 0) {
      goto L1950;
   }
// D	PRINT 150
// D150	FORMAT(' RESTORING FROM "dindx.dat"')
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &state_1.mxscor, sizeof state_1.mxscor);
   DoFio(1, &star_1.strbit, sizeof star_1.strbit);
   DoFio(1, &state_1.egmxsc, sizeof state_1.egmxsc);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &rooms_1.rlnt, sizeof rooms_1.rlnt);
   DoFio(1, &rooms_1.rdesc2, sizeof rooms_1.rdesc2);
   DoFio(200, rooms_1.rdesc1, sizeof rooms_1.rdesc1[0]);
   DoFio(200, rooms_1.rexit, sizeof rooms_1.rexit[0]);
   DoFio(200, rooms_1.ractio, sizeof rooms_1.ractio[0]);
   DoFio(200, rooms_1.rval, sizeof rooms_1.rval[0]);
   DoFio(200, rooms_1.rflag, sizeof rooms_1.rflag[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &exits_1.xlnt, sizeof exits_1.xlnt);
   DoFio(900, exits_1.travel, sizeof exits_1.travel[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &objcts_1.olnt, sizeof objcts_1.olnt);
   DoFio(220, objcts_1.odesc1, sizeof objcts_1.odesc1[0]);
   DoFio(220, objcts_1.odesc2, sizeof objcts_1.odesc2[0]);
   DoFio(220, objcts_1.odesco, sizeof objcts_1.odesco[0]);
   DoFio(220, objcts_1.oactio, sizeof objcts_1.oactio[0]);
   DoFio(220, objcts_1.oflag1, sizeof objcts_1.oflag1[0]);
   DoFio(220, objcts_1.oflag2, sizeof objcts_1.oflag2[0]);
   DoFio(220, objcts_1.ofval, sizeof objcts_1.ofval[0]);
   DoFio(220, objcts_1.otval, sizeof objcts_1.otval[0]);
   DoFio(220, objcts_1.osize, sizeof objcts_1.osize[0]);
   DoFio(220, objcts_1.ocapac, sizeof objcts_1.ocapac[0]);
   DoFio(220, objcts_1.oroom, sizeof objcts_1.oroom[0]);
   DoFio(220, objcts_1.oadv, sizeof objcts_1.oadv[0]);
   DoFio(220, objcts_1.ocan, sizeof objcts_1.ocan[0]);
   DoFio(220, objcts_1.oread, sizeof objcts_1.oread[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &oroom2_1.r2lnt, sizeof oroom2_1.r2lnt);
   DoFio(20, oroom2_1.oroom2, sizeof oroom2_1.oroom2[0]);
   DoFio(20, oroom2_1.rroom2, sizeof oroom2_1.rroom2[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &cevent_1.clnt, sizeof cevent_1.clnt);
   DoFio(25, cevent_1.ctick, sizeof cevent_1.ctick[0]);
   DoFio(25, cevent_1.cactio, sizeof cevent_1.cactio[0]);
   EndInSF();
   BegInSF(1, /*135*/"(l4)", 0);
   DoFio(25, cevent_1.cflag, sizeof cevent_1.cflag[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &vill_1.vlnt, sizeof vill_1.vlnt);
   DoFio(4, vill_1.villns, sizeof vill_1.villns[0]);
   DoFio(4, vill_1.vprob, sizeof vill_1.vprob[0]);
   DoFio(4, vill_1.vopps, sizeof vill_1.vopps[0]);
   DoFio(4, vill_1.vbest, sizeof vill_1.vbest[0]);
   DoFio(4, vill_1.vmelee, sizeof vill_1.vmelee[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &advs_1.alnt, sizeof advs_1.alnt);
   DoFio(4, advs_1.aroom, sizeof advs_1.aroom[0]);
   DoFio(4, advs_1.ascore, sizeof advs_1.ascore[0]);
   DoFio(4, advs_1.avehic, sizeof advs_1.avehic[0]);
   DoFio(4, advs_1.aobj, sizeof advs_1.aobj[0]);
   DoFio(4, advs_1.aactio, sizeof advs_1.aactio[0]);
   DoFio(4, advs_1.astren, sizeof advs_1.astren[0]);
   DoFio(4, advs_1.aflag, sizeof advs_1.aflag[0]);
   EndInSF();
   BegInSF(1, /*130*/"(i6)", 0);
   DoFio(1, &star_1.mbase, sizeof star_1.mbase);
   DoFio(1, &rmsg_1.mlnt, sizeof rmsg_1.mlnt);
   DoFio(1820, rmsg_1.rtext, sizeof rmsg_1.rtext[0]);
   EndInSF();

   CloseF(1);
   goto L1025;
// 						!INIT DONE.

// 130	FORMAT(I8)
// INIT, PAGE 5

// THE INTERNAL DATA BASE IS NOW ESTABLISHED.
// SET UP TO PLAY THE GAME.

L1025:
   intime_(&time_1.shour, &time_1.smin, &time_1.ssec);
// 						!GET TIME AND DATE.
// 	CALL IDATE(I,J,K)
// 	CALL IDATE(DATARRY(1))
// 	CALL INIRND(or(DATARRY(1),or(DATARRY(2),DATARRY(3))),
//     &	or(SHOUR,or(SMIN,SSEC)))
// 	NEW WAY TO INITIALIZE /+TAA+/
   i__1 = time_1.shour * 3600 + time_1.smin * 60 + time_1.ssec;
   inirnd_(i__1);

   play_1.winner = aindex_1.player;
   last_1.lastit = advs_1.aobj[aindex_1.player - 1];
   play_1.here = advs_1.aroom[play_1.winner - 1];
   hack_1.thfpos = objcts_1.oroom[oindex_1.thief - 1];
   state_1.bloc = objcts_1.oroom[oindex_1.ballo - 1];
   ret_val = true;

// D	PRINT 1050,RLNT,RMAX,XLNT,XMAX,OLNT,OMAX,MLNT,MMAX,
// D    &  VLNT,VMAX,ALNT,AMAX,CLNT,CMAX,R2LNT,R2MAX
// D1050	FORMAT(' USED:'/1X,I5,' OF',I5,' ROOMS'/
// D    &  1X,I5,' OF',I5,' EXITS'/
// D    &  1X,I5,' OF',I5,' OBJECTS'/
// D    &  1X,I5,' OF',I5,' MESSAGES'/
// D    &  1X,I5,' OF',I5,' VILLAINS'/
// D    &  1X,I5,' OF',I5,' ADVENTURERS'/
// D    &  1X,I5,' OF',I5,' CLOCK EVENTS'/
// D    &  1X,I5,' OF',I5,' ROOM2 SLOTS')
// D	PRINT 1150,MXSCOR,EGMXSC,RECNO,RDESC2,MBASE,STRBIT
// D1150	FORMAT(' MAX SCORE=',I5/' EG SCORE=',I5/
// D    &  ' MAX RECNO=',I5/' RDESC2 BASE=',I5/
// D    &  ' MELEE START=',I5/' STAR MASK=',I7)
// D	PAUSE 1

   return ret_val;
// INIT, PAGE 6

// ERRORS-- INIT FAILS.

L1900:
   BegExSF(6, /*910*/"(\002 I can't open \002,\002dindx.dat\002,\002.\002)", 0);
   EndExSF();
   BegExSF(6, /*980*/fmt_0, 0);
   EndExSF();
   return ret_val;
L1925:
   BegExSF(6, /*920*/"(\002 \"dindx.dat\" is version \002,i1,\002.\002,i1,a1,\002.\002/\002 I require version \002,i1,\002.\002,i1,a1,\002.\002)", 0);
   DoFio(1, &i, sizeof i);
   DoFio(1, &j, sizeof j);
   DoFio(1, &k, sizeof k);
   DoFio(1, &vers_2.vmaj, sizeof vers_2.vmaj);
   DoFio(1, &vers_2.vmin, sizeof vers_2.vmin);
   DoFio(1, &vers_2.vedit, sizeof vers_2.vedit);
   EndExSF();
   BegExSF(6, /*980*/fmt_0, 0);
   EndExSF();
   return ret_val;
L1950:
   BegExSF(6, /*960*/"(\002 I can't open \002,\002dtext.dat\002,\002.\002)", 0);
   EndExSF();
   BegExSF(6, /*980*/fmt_0, 0);
   EndExSF();
   return ret_val;

}

// PROTCT-- CHECK FOR USER VIOLATION

// THIS ROUTINE SHOULD BE MODIFIED IF YOU WISH TO ADD SYSTEM
// DEPENDANT PROTECTION AGAINST ABUSE.

// AT THE MOMENT, PLAY IS PERMITTED UNDER ALL CIRCUMSTANCES.

static Bool protct_(int x) {
// System generated locals
   Bool ret_val;

   ret_val = true;
   return ret_val;
}
