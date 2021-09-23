// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

static Bool protct(void/*int*/);

// Dungeon initialization subroutine
Bool init(void/*int x*/) {
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

   if (protct(/*x*/)) {
      goto L10000;
   }
// 						!PROTECTION VIOLATION?
// print( //F
//    " There appears before you a threatening figure clad ", //F
//    "all over%/ in heavy black armor.  His legs seem like the ", //F
//    "massive trunk%/ of the oak tree.  His broad shoulders and ", //F
//    "helmeted head loom%/ high over your own puny frame, and ", //F
//    "you realize that his powerful%/ arms could easily crush the ", //F
//    "very life from your body.  There%/ hangs from his belt a ", //F
//    "veritable arsenal of deadly weapons:%/ sword, mace, ball ", //F
//    "and chain, dagger, lance, and trident.%/ He speaks with a ", //F
//    "commanding voice:%/%/%20X\"You shall not pass.\"%/%/ As ", //F
//    "he grabs you by the neck all grows dim about you." //F
// ); //F
   BegExSF(6,
      "(\2"
      " There appears before you a threatening figure clad \2,\2"
      "all over\2/\2 in heavy black armor.  His legs seem like the \2,\2"
      "massive trunk\2/\2 of the oak tree.  His broad shoulders and \2,\2"
      "helmeted head loom\2/\2 high over your own puny frame, and \2,\2"
      "you realize that his powerful\2/\2 arms could easily crush the \2,\2"
      "very life from your body.  There\2/\2 hangs from his belt a \2,\2"
      "veritable arsenal of deadly weapons:\2/\2 sword, mace, ball \2,\2"
      "and chain, dagger, lance, and trident.\2/\2 He speaks with a \2,\2"
      "commanding voice:\2//20x,\2\"You shall not pass.\"\2//\2 As \2,\2"
      "he grabs you by the neck all grows dim about you."
      "\2)", 0
   );
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
      switch_[i - 1] = 0;
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

#ifdef ALLOW_GDT
// 	Changed by TAA so that always in wizard ID
   debug_1.gdtflg = 1;
#else
   debug_1.gdtflg = 0;
#endif

   screen_1.fromdr = 0;
// 						!INIT SCOL GOODIES.
   screen_1.scolrm = 0;
   screen_1.scolac = 0;
// INIT, PAGE 4

// NOW RESTORE FROM EXISTING INDEX FILE.

#if 0
// open(unit:1,file:"/usr/share/games/dungeon/dindx.dat", //F
//    status:"OLD", form:"FORMATTED", access:"SEQUENTIAL", err:L1900 //F
// ); //F
   if (OpenF(1, "/usr/share/games/dungeon/dindx.dat", "OLD", "SEQUENTIAL", "FORMATTED", 0) != 0) goto L1900;
#else
// open(unit:1,file:"dindx.dat", //F
//    status:"OLD", form:"FORMATTED", access:"SEQUENTIAL", err:L1900 //F
// ); //F
   if (OpenF(1, "dindx.dat", "OLD", "SEQUENTIAL", "FORMATTED", 0) != 0) goto L1900;
#endif

// read(1, "%I6", &i, &j, &k); //F
   BegInSF(1, "(i6)", 0), DoFio(1, &i, sizeof i), DoFio(1, &j, sizeof j), DoFio(1, &k, sizeof k), EndInSF();
// 						!GET VERSION.
   if (i != vers_1.vmaj || j != vers_1.vmin) {
      goto L1925;
   }
#if 0
// open(unit:chan_1.dbch, file:"/usr/share/games/dungeon/dtext.dat", //F
//    status:"old", form:"unformatted", access:"direct", //F
//    recl:76, err:L1950 //F
// ); //F
   if (OpenF(chan_1.dbch, "/usr/share/games/dungeon/dtext.dat", "OLD", "DIRECT", "UNFORMATTED", 76) != 0) goto L1950;
#else
// open(unit:chan_1.dbch, file:"dtext.dat", //F
//    status:"old", form:"unformatted", access:"direct", //F
//    recl:76, err:L1950 //F
// ); //F
   if (OpenF(chan_1.dbch, "dtext.dat", "OLD", "DIRECT", "UNFORMATTED", 76) != 0) goto L1950;
#endif
#ifdef ALLOW_GDT
// print(" RESTORING FROM \"dindx.dat\""); //F
#endif
// // const char *Fmt = "%I8"; //F
// const char *Fmt = "%I6"; //F
// read(1, Fmt, &state_1.mxscor, &star_1.strbit, &state_1.egmxsc); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &state_1.mxscor, sizeof state_1.mxscor), DoFio(1, &star_1.strbit, sizeof star_1.strbit);
   DoFio(1, &state_1.egmxsc, sizeof state_1.egmxsc);
   EndInSF();
// read(1, Fmt, &rooms_1.rlnt, &rooms_1.rdesc2, rooms_1.rdesc1, rooms_1.rexit, rooms_1.ractio, rooms_1.rval, rooms_1.rflag); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &rooms_1.rlnt, sizeof rooms_1.rlnt);
   DoFio(1, &rooms_1.rdesc2, sizeof rooms_1.rdesc2), DoFio(200, rooms_1.rdesc1, sizeof rooms_1.rdesc1[0]);
   DoFio(200, rooms_1.rexit, sizeof rooms_1.rexit[0]), DoFio(200, rooms_1.ractio, sizeof rooms_1.ractio[0]);
   DoFio(200, rooms_1.rval, sizeof rooms_1.rval[0]), DoFio(200, rooms_1.rflag, sizeof rooms_1.rflag[0]);
   EndInSF();
// read(1, Fmt, &exits_1.xlnt, exits_1.travel); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &exits_1.xlnt, sizeof exits_1.xlnt), DoFio(900, exits_1.travel, sizeof exits_1.travel[0]);
   EndInSF();
// read(1, Fmt, //F
//    objcts_1.olnt, objcts_1.odesc1, objcts_1.odesc2, objcts_1.odesco, objcts_1.oactio, objcts_1.oflag1, objcts_1.oflag2, //F
//    objcts_1.ofval, objcts_1.otval, objcts_1.osize, objcts_1.ocapac, objcts_1.oroom, objcts_1.oadv, objcts_1.ocan, objcts_1.oread //F
// ); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &objcts_1.olnt, sizeof objcts_1.olnt);
   DoFio(220, objcts_1.odesc1, sizeof objcts_1.odesc1[0]), DoFio(220, objcts_1.odesc2, sizeof objcts_1.odesc2[0]);
   DoFio(220, objcts_1.odesco, sizeof objcts_1.odesco[0]), DoFio(220, objcts_1.oactio, sizeof objcts_1.oactio[0]);
   DoFio(220, objcts_1.oflag1, sizeof objcts_1.oflag1[0]), DoFio(220, objcts_1.oflag2, sizeof objcts_1.oflag2[0]);
   DoFio(220, objcts_1.ofval, sizeof objcts_1.ofval[0]), DoFio(220, objcts_1.otval, sizeof objcts_1.otval[0]);
   DoFio(220, objcts_1.osize, sizeof objcts_1.osize[0]), DoFio(220, objcts_1.ocapac, sizeof objcts_1.ocapac[0]);
   DoFio(220, objcts_1.oroom, sizeof objcts_1.oroom[0]), DoFio(220, objcts_1.oadv, sizeof objcts_1.oadv[0]);
   DoFio(220, objcts_1.ocan, sizeof objcts_1.ocan[0]), DoFio(220, objcts_1.oread, sizeof objcts_1.oread[0]);
   EndInSF();
// read(1, Fmt, &oroom2_1.r2lnt, oroom2_1.oroom2, oroom2_1.rroom2); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &oroom2_1.r2lnt, sizeof oroom2_1.r2lnt);
   DoFio(20, oroom2_1.oroom2, sizeof oroom2_1.oroom2[0]), DoFio(20, oroom2_1.rroom2, sizeof oroom2_1.rroom2[0]);
   EndInSF();
// read(1, Fmt, &cevent_1.clnt, cevent_1.ctick, cevent_1.cactio); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &cevent_1.clnt, sizeof cevent_1.clnt);
   DoFio(25, cevent_1.ctick, sizeof cevent_1.ctick[0]), DoFio(25, cevent_1.cactio, sizeof cevent_1.cactio[0]);
   EndInSF();
// read(1, "%L4", cevent_1.cflag); //F
   BegInSF(1, "(l4)", 0);
   DoFio(25, cevent_1.cflag, sizeof cevent_1.cflag[0]);
   EndInSF();
// read(1, Fmt, &vill_1.vlnt, vill_1.villns, vill_1.vprob, vill_1.vopps, vill_1.vbest, vill_1.vmelee); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &vill_1.vlnt, sizeof vill_1.vlnt), DoFio(4, vill_1.villns, sizeof vill_1.villns[0]);
   DoFio(4, vill_1.vprob, sizeof vill_1.vprob[0]), DoFio(4, vill_1.vopps, sizeof vill_1.vopps[0]);
   DoFio(4, vill_1.vbest, sizeof vill_1.vbest[0]), DoFio(4, vill_1.vmelee, sizeof vill_1.vmelee[0]);
   EndInSF();
// read(1, Fmt, &advs_1.alnt, advs_1.aroom, advs_1.ascore, advs_1.avehic, advs_1.aobj, advs_1.aactio, advs_1.astren, advs_1.aflag); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &advs_1.alnt, sizeof advs_1.alnt), DoFio(4, advs_1.aroom, sizeof advs_1.aroom[0]);
   DoFio(4, advs_1.ascore, sizeof advs_1.ascore[0]), DoFio(4, advs_1.avehic, sizeof advs_1.avehic[0]);
   DoFio(4, advs_1.aobj, sizeof advs_1.aobj[0]), DoFio(4, advs_1.aactio, sizeof advs_1.aactio[0]);
   DoFio(4, advs_1.astren, sizeof advs_1.astren[0]), DoFio(4, advs_1.aflag, sizeof advs_1.aflag[0]);
   EndInSF();
// read(1, Fmt, &star_1.mbase, &rmsg_1.mlnt, rmsg_1.rtext); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &star_1.mbase, sizeof star_1.mbase);
   DoFio(1, &rmsg_1.mlnt, sizeof rmsg_1.mlnt), DoFio(1820, rmsg_1.rtext, sizeof rmsg_1.rtext[0]);
   EndInSF();

// close(1); //F
   CloseF(1);
   goto L1025;
// 						!INIT DONE.

// INIT, PAGE 5

// THE INTERNAL DATA BASE IS NOW ESTABLISHED.
// SET UP TO PLAY THE GAME.

L1025:
   intime(&time_1.shour, &time_1.smin, &time_1.ssec);
// 						!GET TIME AND DATE.
// 	CALL IDATE(I,J,K)
// 	CALL IDATE(DATARRY(1))
// 	CALL INIRND(or(DATARRY(1),or(DATARRY(2),DATARRY(3))),
//     &	or(SHOUR,or(SMIN,SSEC)))
// 	NEW WAY TO INITIALIZE /+TAA+/
   i__1 = time_1.shour * 3600 + time_1.smin * 60 + time_1.ssec;
   inirnd(i__1);

   play_1.winner = aindex_1.player;
   last_1.lastit = advs_1.aobj[aindex_1.player - 1];
   play_1.here = advs_1.aroom[play_1.winner - 1];
   hack_1.thfpos = objcts_1.oroom[oindex_1.thief - 1];
   state_1.bloc = objcts_1.oroom[oindex_1.ballo - 1];
   ret_val = true;

#ifdef ALLOW_GDT
// print( //F
//    " USED:%/" //F
//    "%1X%I5 OF%I5 ROOMS%/"	"%1X%I5 OF%I5 EXITS%/"		"%1X%I5 OF%I5 OBJECTS%/"	"%1X%I5 OF%I5 MESSAGES%/" //F
//    "%1X%I5 OF%I5 VILLAINS%/"	"%1X%I5 OF%I5 ADVENTURERS%/"	"%1X%I5 OF%I5 CLOCK EVENTS%/"	"%1X%I5 OF%I5 ROOM2 SLOTS", //F
//    rooms_1.rlnt, rmax,	exits_1.xlnt, xmax,		objcts_1.olnt, omax,		rmsg_1.mlnt, mmax, //F
//    vill_1.vlnt, vmax,	advs_1.alnt, amax,		cevent_1.clnt, cmax,		oroom2_1.r2lnt, r2max //F
// ); //F
// print( //F
//    " MAX SCORE=%I5%/"	" EG SCORE=%I5%/"	" MAX RECNO=%I5%/" //F
//    " RDESC2 BASE=%I5%/"	" MELEE START=%I5%/"	" STAR MASK=%I7", //F
//    state_1.mxscor,		state_1.egmxsc,		recno, //F
//    rooms_1.rdesc2,		star_1.mbase,		star_1.strbit //F
// ); //F
// pause(1); //F
#endif

   return ret_val;
// INIT, PAGE 6

// ERRORS-- INIT FAILS.

L1900:
// print(" I can't open ","dindx.dat","."); //F
   BegExSF(6, "(\2 I can't open \2,\2dindx.dat\2,\2.\2)", 0), EndExSF();
   goto L1975;
L1925:
// print(
//    " \"dindx.dat\" is version %I1.%I1%A1.%/" //F
//    "  I require version %I1.%I1%A1.", //F
//    i, j, k, vers_1.vmaj, vers_1.vmin, vers_1.vedit //F
// ); //F
   BegExSF(6, "(\2 \"dindx.dat\" is version \2,i1,\2.\2,i1,a1,\2.\2/\2 I require version \2,i1,\2.\2,i1,a1,\2.\2)", 0);
   DoFio(1, &i, sizeof i), DoFio(1, &j, sizeof j), DoFio(1, &k, sizeof k);
   DoFio(1, &vers_1.vmaj, sizeof vers_1.vmaj), DoFio(1, &vers_1.vmin, sizeof vers_1.vmin), DoFio(1, &vers_1.vedit, sizeof vers_1.vedit);
   EndExSF();
   goto L1975;
L1950:
// print(" I can't open ","dtext.dat","."); //F
   BegExSF(6, "(\2 I can't open \2,\2dtext.dat\2,\2.\2)", 0), EndExSF();
L1975:
// print( //F
//    " Suddenly a sinister, wraithlike figure appears before ", //F
//    "you,%/ seeming to float in the air.  In a low, sorrowful voice", //F
//    " he says,%/ \"Alas, the very nature of the world has changed, ", //F
//    "and the dungeon%/ cannot be found.  All must now pass away.\"", //F
//    "  Raising his oaken staff%/ in farewell, he fades into the ", //F
//    "spreading darkness.  In his place%/ appears a tastefully ", //F
//    "lettered sign reading:%/%/%23XINITIALIZATION FAILURE%/%/" //F
//    " The darkness becomes all encompassing, and your vision fails." //F
// ); //F
   BegExSF(6,
      "("
      "\2 Suddenly a sinister, wraithlike figure appears before \2,"
      "\2you,\2/\2 seeming to float in the air.  In a low, sorrowful voice\2,"
      "\2 he says,\2/\2 \"Alas, the very nature of the world has changed, \2,"
      "\2and the dungeon\2/\2 cannot be found.  All must now pass away.\"\2,"
      "\2  Raising his oaken staff\2/\2 in farewell, he fades into the \2,"
      "\2spreading darkness.  In his place\2/\2 appears a tastefully \2,"
      "\2lettered sign reading:\2//23x,\2INITIALIZATION FAILURE\2//"
      "\2 The darkness becomes all encompassing, and your vision fails.\2"
      ")", 0
   ), EndExSF();
   return ret_val;
}

// Check for user violation
// This routine should be modified if you wish to add system dependent protection against abuse.
// At the moment, play is permitted under all circumstances.
static Bool protct(void/*int x*/) {
// System generated locals
   Bool ret_val;

   ret_val = true;
   return ret_val;
}
