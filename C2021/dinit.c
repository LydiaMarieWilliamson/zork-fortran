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

   rmsg.mlnt = 0;
// 						!INIT ARRAY COUNTERS.
   objcts.olnt = 0;
   rooms.rlnt = 0;
   vill.vlnt = 0;
   advs.alnt = 0;
   cevent.clnt = 0;
   exits.xlnt = 1;
   oroom2_.r2lnt = 0;

   state.ltshft = 10;
// 						!SET UP STATE VARIABLES.
   state.mxscor = state.ltshft;
   state.egscor = 0;
   state.egmxsc = 0;
   state.mxload = 100;
   state.rwscor = 0;
   state.deaths = 0;
   state.moves = 0;
   time_.pltime = 0;
   state.mungrm = 0;
   state.hs = 0;
   prsvec.prsa = 0;
// 						!CLEAR PARSE VECTOR.
   prsvec.prsi = 0;
   prsvec.prso = 0;
   prsvec.prscon = 1;
   orphs.oflag = 0;
// 						!CLEAR ORPHANS.
   orphs.oact = 0;
   orphs.oslot = 0;
   orphs.oprep = 0;
   orphs.oname = 0;
   hack.thfflg = false;
// 						!THIEF NOT INTRODUCED BUT
   hack.thfact = true;
// 						!IS ACTIVE.
   hack.swdact = false;
// 						!SWORD IS INACTIVE.
   hack.swdsta = 0;
// 						!SWORD IS OFF.

   recno = 1;
// 						!INIT DB FILE POINTER.
   star.mbase = 0;
// 						!INIT MELEE BASE.
//   LOGICAL UNIT NRS: 5=STDIN, 6=STDOUT
   chan.inpch = 5;
// 						!TTY INPUT
   chan.outch = 6;
   chan.dbch = 2;
// 						!DATA BASE.
// INIT, PAGE 3

// INIT ALL ARRAYS.

   i__1 = cmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR CLOCK EVENTS
      cevent.cflag[i - 1] = false;
      cevent.ctick[i - 1] = 0;
      cevent.cactio[i - 1] = 0;
// L5:
   }

   i__1 = fmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR FLAGS.
      flags[i - 1] = false;
// L10:
   }
   findex.buoyf = true;
// 						!SOME START AS TRUE.
   findex.egyptf = true;
   findex.cagetf = true;
   findex.mr1f = true;
   findex.mr2f = true;
   findex.follwf = true;
   i__1 = smax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR SWITCHES.
      switch_[i - 1] = 0;
// L12:
   }
   findex.ormtch = 4;
// 						!NUMBER OF MATCHES.
   findex.lcell = 1;
   findex.pnumb = 1;
   findex.mdir = 270;
   findex.mloc = MrBrX;
   findex.cphere = 10;

   i__1 = r2max;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR ROOM 2 ARRAY.
      oroom2_.rroom2[i - 1] = 0;
      oroom2_.oroom2[i - 1] = 0;
// L15:
   }

   i__1 = xmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR TRAVEL ARRAY.
      exits.travel[i - 1] = 0;
// L20:
   }

   i__1 = vmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR VILLAINS ARRAYS.
      vill.vopps[i - 1] = 0;
      vill.vprob[i - 1] = 0;
      vill.villns[i - 1] = 0;
      vill.vbest[i - 1] = 0;
      vill.vmelee[i - 1] = 0;
// L30:
   }

   i__1 = omax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR OBJECT ARRAYS.
      objcts.odesc1[i - 1] = 0;
      objcts.odesc2[i - 1] = 0;
      objcts.odesco[i - 1] = 0;
      objcts.oread[i - 1] = 0;
      objcts.oactio[i - 1] = 0;
      objcts.oflag1[i - 1] = 0;
      objcts.oflag2[i - 1] = 0;
      objcts.ofval[i - 1] = 0;
      objcts.otval[i - 1] = 0;
      objcts.osize[i - 1] = 0;
      objcts.ocapac[i - 1] = 0;
      objcts.ocan[i - 1] = 0;
      objcts.oadv[i - 1] = 0;
      objcts.oroom[i - 1] = 0;
// L40:
   }

   rooms.rdesc2 = 0;
// 						!CLEAR DESC BASE PTR.
   i__1 = rmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR ROOM ARRAYS.
      rooms.rdesc1[i - 1] = 0;
      rooms.ractio[i - 1] = 0;
      rooms.rflag[i - 1] = 0;
      rooms.rval[i - 1] = 0;
      rooms.rexit[i - 1] = 0;
// L50:
   }

   i__1 = mmax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR MESSAGE DIRECTORY.
      rmsg.rtext[i - 1] = 0;
// L60:
   }

   i__1 = amax;
   for (i = 1; i <= i__1; ++i) {
// 						!CLEAR ADVENTURER'S ARRAYS.
      advs.aroom[i - 1] = 0;
      advs.ascore[i - 1] = 0;
      advs.avehic[i - 1] = 0;
      advs.aobj[i - 1] = 0;
      advs.aactio[i - 1] = 0;
      advs.astren[i - 1] = 0;
      advs.aflag[i - 1] = 0;
// L70:
   }

   debug.dbgflg = 0;
   debug.prsflg = 0;

// allow setting gdtflg true if user id matches wizard id
// this way, the wizard doesn't have to recompile to use gdt

#ifdef ALLOW_GDT
// 	Changed by TAA so that always in wizard ID
   debug.gdtflg = 1;
#else
   debug.gdtflg = 0;
#endif

   screen.fromdr = 0;
// 						!INIT SCOL GOODIES.
   screen.scolrm = 0;
   screen.scolac = 0;
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
   if (i != vmaj || j != vmin) {
      goto L1925;
   }
#if 0
// open(unit:chan.dbch, file:"/usr/share/games/dungeon/dtext.dat", //F
//    status:"old", form:"unformatted", access:"direct", //F
//    recl:76, err:L1950 //F
// ); //F
   if (OpenF(chan.dbch, "/usr/share/games/dungeon/dtext.dat", "OLD", "DIRECT", "UNFORMATTED", 76) != 0) goto L1950;
#else
// open(unit:chan.dbch, file:"dtext.dat", //F
//    status:"old", form:"unformatted", access:"direct", //F
//    recl:76, err:L1950 //F
// ); //F
   if (OpenF(chan.dbch, "dtext.dat", "OLD", "DIRECT", "UNFORMATTED", 76) != 0) goto L1950;
#endif
#ifdef ALLOW_GDT
// print(" RESTORING FROM \"dindx.dat\""); //F
#endif
// // const char *Fmt = "%I8"; //F
// const char *Fmt = "%I6"; //F
// read(1, Fmt, &state.mxscor, &star.strbit, &state.egmxsc); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &state.mxscor, sizeof state.mxscor), DoFio(1, &star.strbit, sizeof star.strbit);
   DoFio(1, &state.egmxsc, sizeof state.egmxsc);
   EndInSF();
// read(1, Fmt, &rooms.rlnt, &rooms.rdesc2, rooms.rdesc1, rooms.rexit, rooms.ractio, rooms.rval, rooms.rflag); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &rooms.rlnt, sizeof rooms.rlnt);
   DoFio(1, &rooms.rdesc2, sizeof rooms.rdesc2), DoFio(200, rooms.rdesc1, sizeof rooms.rdesc1[0]);
   DoFio(200, rooms.rexit, sizeof rooms.rexit[0]), DoFio(200, rooms.ractio, sizeof rooms.ractio[0]);
   DoFio(200, rooms.rval, sizeof rooms.rval[0]), DoFio(200, rooms.rflag, sizeof rooms.rflag[0]);
   EndInSF();
// read(1, Fmt, &exits.xlnt, exits.travel); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &exits.xlnt, sizeof exits.xlnt), DoFio(900, exits.travel, sizeof exits.travel[0]);
   EndInSF();
// read(1, Fmt, //F
//    objcts.olnt, objcts.odesc1, objcts.odesc2, objcts.odesco, objcts.oactio, objcts.oflag1, objcts.oflag2, //F
//    objcts.ofval, objcts.otval, objcts.osize, objcts.ocapac, objcts.oroom, objcts.oadv, objcts.ocan, objcts.oread //F
// ); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &objcts.olnt, sizeof objcts.olnt);
   DoFio(220, objcts.odesc1, sizeof objcts.odesc1[0]), DoFio(220, objcts.odesc2, sizeof objcts.odesc2[0]);
   DoFio(220, objcts.odesco, sizeof objcts.odesco[0]), DoFio(220, objcts.oactio, sizeof objcts.oactio[0]);
   DoFio(220, objcts.oflag1, sizeof objcts.oflag1[0]), DoFio(220, objcts.oflag2, sizeof objcts.oflag2[0]);
   DoFio(220, objcts.ofval, sizeof objcts.ofval[0]), DoFio(220, objcts.otval, sizeof objcts.otval[0]);
   DoFio(220, objcts.osize, sizeof objcts.osize[0]), DoFio(220, objcts.ocapac, sizeof objcts.ocapac[0]);
   DoFio(220, objcts.oroom, sizeof objcts.oroom[0]), DoFio(220, objcts.oadv, sizeof objcts.oadv[0]);
   DoFio(220, objcts.ocan, sizeof objcts.ocan[0]), DoFio(220, objcts.oread, sizeof objcts.oread[0]);
   EndInSF();
// read(1, Fmt, &oroom2_.r2lnt, oroom2_.oroom2, oroom2_.rroom2); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &oroom2_.r2lnt, sizeof oroom2_.r2lnt);
   DoFio(20, oroom2_.oroom2, sizeof oroom2_.oroom2[0]), DoFio(20, oroom2_.rroom2, sizeof oroom2_.rroom2[0]);
   EndInSF();
// read(1, Fmt, &cevent.clnt, cevent.ctick, cevent.cactio); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &cevent.clnt, sizeof cevent.clnt);
   DoFio(25, cevent.ctick, sizeof cevent.ctick[0]), DoFio(25, cevent.cactio, sizeof cevent.cactio[0]);
   EndInSF();
// read(1, "%L4", cevent.cflag); //F
   BegInSF(1, "(l4)", 0);
   DoFio(25, cevent.cflag, sizeof cevent.cflag[0]);
   EndInSF();
// read(1, Fmt, &vill.vlnt, vill.villns, vill.vprob, vill.vopps, vill.vbest, vill.vmelee); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &vill.vlnt, sizeof vill.vlnt), DoFio(4, vill.villns, sizeof vill.villns[0]);
   DoFio(4, vill.vprob, sizeof vill.vprob[0]), DoFio(4, vill.vopps, sizeof vill.vopps[0]);
   DoFio(4, vill.vbest, sizeof vill.vbest[0]), DoFio(4, vill.vmelee, sizeof vill.vmelee[0]);
   EndInSF();
// read(1, Fmt, &advs.alnt, advs.aroom, advs.ascore, advs.avehic, advs.aobj, advs.aactio, advs.astren, advs.aflag); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &advs.alnt, sizeof advs.alnt), DoFio(4, advs.aroom, sizeof advs.aroom[0]);
   DoFio(4, advs.ascore, sizeof advs.ascore[0]), DoFio(4, advs.avehic, sizeof advs.avehic[0]);
   DoFio(4, advs.aobj, sizeof advs.aobj[0]), DoFio(4, advs.aactio, sizeof advs.aactio[0]);
   DoFio(4, advs.astren, sizeof advs.astren[0]), DoFio(4, advs.aflag, sizeof advs.aflag[0]);
   EndInSF();
// read(1, Fmt, &star.mbase, &rmsg.mlnt, rmsg.rtext); //F
   BegInSF(1, "(i6)", 0);
   DoFio(1, &star.mbase, sizeof star.mbase);
   DoFio(1, &rmsg.mlnt, sizeof rmsg.mlnt), DoFio(1820, rmsg.rtext, sizeof rmsg.rtext[0]);
   EndInSF();

// close(1); //F
   CloseF(1);
   goto L1025;
// 						!INIT DONE.

// INIT, PAGE 5

// THE INTERNAL DATA BASE IS NOW ESTABLISHED.
// SET UP TO PLAY THE GAME.

L1025:
   intime(&time_.shour, &time_.smin, &time_.ssec);
// 						!GET TIME AND DATE.
// 	CALL IDATE(I,J,K)
// 	CALL IDATE(DATARRY(1))
// 	CALL INIRND(or(DATARRY(1),or(DATARRY(2),DATARRY(3))),
//     &	or(SHOUR,or(SMIN,SSEC)))
// 	NEW WAY TO INITIALIZE /+TAA+/
   i__1 = time_.shour * 3600 + time_.smin * 60 + time_.ssec;
   inirnd(i__1);

   play.winner = PlayerAX;
   last.lastit = advs.aobj[PlayerAX - 1];
   play.here = advs.aroom[play.winner - 1];
   hack.thfpos = objcts.oroom[ThiefOX - 1];
   state.bloc = objcts.oroom[BalloOX - 1];
   ret_val = true;

#ifdef ALLOW_GDT
// print( //F
//    " USED:%/" //F
//    "%1X%I5 OF%I5 ROOMS%/"	"%1X%I5 OF%I5 EXITS%/"		"%1X%I5 OF%I5 OBJECTS%/"	"%1X%I5 OF%I5 MESSAGES%/" //F
//    "%1X%I5 OF%I5 VILLAINS%/"	"%1X%I5 OF%I5 ADVENTURERS%/"	"%1X%I5 OF%I5 CLOCK EVENTS%/"	"%1X%I5 OF%I5 ROOM2 SLOTS", //F
//    rooms.rlnt, rmax,	exits.xlnt, xmax,		objcts.olnt, omax,		rmsg.mlnt, mmax, //F
//    vill.vlnt, vmax,	advs.alnt, amax,		cevent.clnt, cmax,		oroom2_.r2lnt, r2max //F
// ); //F
// print( //F
//    " MAX SCORE=%I5%/"	" EG SCORE=%I5%/"	" MAX RECNO=%I5%/" //F
//    " RDESC2 BASE=%I5%/"	" MELEE START=%I5%/"	" STAR MASK=%I7", //F
//    state.mxscor,		state.egmxsc,		recno, //F
//    rooms.rdesc2,		star.mbase,		star.strbit //F
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
//    i, j, k, vmaj, vmin, vedit //F
// ); //F
   BegExSF(6, "(\2 \"dindx.dat\" is version \2,i1,\2.\2,i1,a1,\2.\2/\2 I require version \2,i1,\2.\2,i1,a1,\2.\2)", 0);
   DoFio(1, &i, sizeof i), DoFio(1, &j, sizeof j), DoFio(1, &k, sizeof k);
{  int Edit = vedit; DoFio(1, &vmaj, sizeof vmaj), DoFio(1, &vmin, sizeof vmin), DoFio(1, &Edit, sizeof Edit); }
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
