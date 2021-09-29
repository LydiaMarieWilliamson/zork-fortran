// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

#ifndef StoryFile
#   if defined unix
#      define StoryFile "/usr/share/games/dungeon/dtext.dat"
#   else
#      error I need a definition for StoryFile
#   endif
#endif
#ifndef IndexFile
#   if defined unix
#      define IndexFile "/usr/share/games/dungeon/dindx.dat"
#   else
#      error I need a definition for IndexFile
#   endif
#endif
#ifndef MyStoryFile
#   define MyStoryFile "dtext.dat"
#endif
#ifndef MyIndexFile
#   define MyIndexFile "dindx.dat"
#endif

// Dungeon initialization subroutine
Bool init(void/*int x*/) {
// System generated locals
   Bool ret_val;

// Local variables
   int xmax, r2max, dirmax, recno;
   int Maj, Min, Edit;
   FILE *IndexF;
   int mmax, omax, rmax, vmax, amax, cmax, fmax, smax;

   more_init();

// INIT, PAGE 2

// FIRST CHECK FOR PROTECTION VIOLATION

   if (protct(/*x*/)) {
      goto L10000;
   }
// 						!PROTECTION VIOLATION?
// print( //F
//    "There appears before you a threatening figure clad ", //F
//    "all over%/in heavy black armor.  His legs seem like the ", //F
//    "massive trunk%/of the oak tree.  His broad shoulders and ", //F
//    "helmeted head loom%/high over your own puny frame, and ", //F
//    "you realize that his powerful%/arms could easily crush the ", //F
//    "very life from your body.  There%/hangs from his belt a ", //F
//    "veritable arsenal of deadly weapons:%/sword, mace, ball ", //F
//    "and chain, dagger, lance, and trident.%/He speaks with a ", //F
//    "commanding voice:%/%/%20X\"You shall not pass.\"%/%/As ", //F
//    "he grabs you by the neck all grows dim about you." //F
// ); //F
   more_output("There appears before you a threatening figure clad all over\n");
   more_output("in heavy black armor.  His legs seem like the massive trunk\n");
   more_output("of the oak tree.  His broad shoulders and helmeted head loom\n");
   more_output("high over your own puny frame, and you realize that his powerful\n");
   more_output("arms could easily crush the very life from your body.  There\n");
   more_output("hangs from his belt a veritable arsenal of deadly weapons:\n");
   more_output("sword, mace, ball and chain, dagger, lance, and trident.\n");
   more_output("He speaks with a commanding voice:\n");
   more_output("\n");
   more_output("                    \"You shall not pass.\"\n");
   more_output("\n");
   more_output("As he grabs you by the neck all grows dim about you.\n");
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
// INIT, PAGE 3

// INIT ALL ARRAYS.

   for (int c = 0; c < cmax; c++) {
// 						!CLEAR CLOCK EVENTS
      cevent.cflag[c] = false;
      cevent.ctick[c] = 0;
      cevent.cactio[c] = 0;
// L5:
   }

   for (int f = 0; f < fmax; f++) {
// 						!CLEAR FLAGS.
      flags[f] = false;
// L10:
   }
   findex.buoyf = true;
// 						!SOME START AS TRUE.
   findex.egyptf = true;
   findex.cagetf = true;
   findex.mr1f = true;
   findex.mr2f = true;
   findex.follwf = true;
   for (int s = 0; s < smax; s++) {
// 						!CLEAR SWITCHES.
      switch_[s] = 0;
// L12:
   }
   findex.ormtch = 4;
// 						!NUMBER OF MATCHES.
   findex.lcell = 1;
   findex.pnumb = 1;
   findex.mdir = 270;
   findex.mloc = MrBrX;
   findex.cphere = 10;

   for (int r2 = 0; r2 < r2max; r2++) {
// 						!CLEAR ROOM 2 ARRAY.
      oroom2_.rroom2[r2] = 0;
      oroom2_.oroom2[r2] = 0;
// L15:
   }

   for (int x = 0; x < xmax; x++) {
// 						!CLEAR TRAVEL ARRAY.
      exits.travel[x] = 0;
// L20:
   }

   for (int v = 0; v < vmax; v++) {
// 						!CLEAR VILLAINS ARRAYS.
      vill.vopps[v] = 0;
      vill.vprob[v] = 0;
      vill.villns[v] = 0;
      vill.vbest[v] = 0;
      vill.vmelee[v] = 0;
// L30:
   }

   for (int o = 0; o < omax; o++) {
// 						!CLEAR OBJECT ARRAYS.
      objcts.odesc1[o] = 0;
      objcts.odesc2[o] = 0;
      objcts.odesco[o] = 0;
      objcts.oread[o] = 0;
      objcts.oactio[o] = 0;
      objcts.oflag1[o] = 0;
      objcts.oflag2[o] = 0;
      objcts.ofval[o] = 0;
      objcts.otval[o] = 0;
      objcts.osize[o] = 0;
      objcts.ocapac[o] = 0;
      objcts.ocan[o] = 0;
      objcts.oadv[o] = 0;
      objcts.oroom[o] = 0;
// L40:
   }

   rooms.rdesc2 = 0;
// 						!CLEAR DESC BASE PTR.
   for (int r = 0; r < rmax; r++) {
// 						!CLEAR ROOM ARRAYS.
      rooms.rdesc1[r] = 0;
      rooms.ractio[r] = 0;
      rooms.rflag[r] = 0;
      rooms.rval[r] = 0;
      rooms.rexit[r] = 0;
// L50:
   }

   for (int m = 0; m < mmax; m++) {
// 						!CLEAR MESSAGE DIRECTORY.
      rmsg.rtext[m] = 0;
// L60:
   }

   for (int a = 0; a < amax; a++) {
// 						!CLEAR ADVENTURER'S ARRAYS.
      advs.aroom[a] = 0;
      advs.ascore[a] = 0;
      advs.avehic[a] = 0;
      advs.aobj[a] = 0;
      advs.aactio[a] = 0;
      advs.astren[a] = 0;
      advs.aflag[a] = 0;
// L70:
   }

   debug.dbgflg = 0;
   debug.prsflg = 0;

// allow setting gdtflg true if user id matches wizard id
// this way, the wizard doesn't have to recompile to use gdt

#ifdef ALLOW_GDT
   debug.gdtflg = wizard();
#else
   debug.gdtflg = 0;
#endif

   screen.fromdr = 0;
// 						!INIT SCOL GOODIES.
   screen.scolrm = 0;
   screen.scolac = 0;
// INIT, PAGE 4

// NOW RESTORE FROM EXISTING INDEX FILE.

// open(unit:1, file:MyIndexFile, status:"OLD", form:"FORMATTED", access:"SEQUENTIAL", err:L1900); //F
   if ((IndexF = OpenInF(MyIndexFile, "r")) == NULL && (IndexF = OpenInF(IndexFile, "r")) == NULL) goto L1900;

// read(1, "%I6", &Maj, &Min, &Edit); //F
   Maj = GetWord(IndexF), Min = GetWord(IndexF), Edit = GetWord(IndexF);
// 						!GET VERSION.
   if (Maj != vmaj || Min != vmin) {
      goto L1925;
   }
// open(unit:storych, file:MyStoryFile, status:"old", form:"unformatted", access:"direct", recl:76, err:L1950); //F
   if ((StoryF = OpenInF(MyStoryFile, "rb")) == NULL && (StoryF = OpenInF(StoryFile, "rb")) == NULL) goto L1950;
#ifdef ALLOW_GDT
// print("RESTORING FROM \"" IndexFile "\""); //F
#endif
// // const char *Fmt = "%I8"; //F
// const char *Fmt = "%I6"; //F
// read(1, Fmt, &state.mxscor, &star.strbit, &state.egmxsc); //F
   state.mxscor = GetWord(IndexF), star.strbit = GetWord(IndexF), state.egmxsc = GetWord(IndexF);
// read(1, Fmt, &rooms.rlnt, &rooms.rdesc2, rooms.rdesc1, rooms.rexit, rooms.ractio, rooms.rval, rooms.rflag); //F
   rooms.rlnt = GetWord(IndexF);
   rooms.rdesc2 = GetWord(IndexF), GetWords(rmax, rooms.rdesc1, IndexF);
   GetWords(rmax, rooms.rexit, IndexF), GetWords(rmax, rooms.ractio, IndexF);
   GetWords(rmax, rooms.rval, IndexF), GetWords(rmax, rooms.rflag, IndexF);
// read(1, Fmt, &exits.xlnt, exits.travel); //F
   exits.xlnt = GetWord(IndexF), GetWords(xmax, exits.travel, IndexF);
// read(1, Fmt, //F
//    objcts.olnt, objcts.odesc1, objcts.odesc2, objcts.odesco, objcts.oactio, objcts.oflag1, objcts.oflag2, //F
//    objcts.ofval, objcts.otval, objcts.osize, objcts.ocapac, objcts.oroom, objcts.oadv, objcts.ocan, objcts.oread //F
// ); //F
   objcts.olnt = GetWord(IndexF);
   GetWords(omax, objcts.odesc1, IndexF), GetWords(omax, objcts.odesc2, IndexF);
   GetWords(omax, objcts.odesco, IndexF), GetWords(omax, objcts.oactio, IndexF);
   GetWords(omax, objcts.oflag1, IndexF), GetWords(omax, objcts.oflag2, IndexF);
   GetWords(omax, objcts.ofval, IndexF), GetWords(omax, objcts.otval, IndexF);
   GetWords(omax, objcts.osize, IndexF), GetWords(omax, objcts.ocapac, IndexF);
   GetWords(omax, objcts.oroom, IndexF), GetWords(omax, objcts.oadv, IndexF);
   GetWords(omax, objcts.ocan, IndexF), GetWords(omax, objcts.oread, IndexF);
// read(1, Fmt, &oroom2_.r2lnt, oroom2_.oroom2, oroom2_.rroom2); //F
   oroom2_.r2lnt = GetWord(IndexF);
   GetWords(r2max, oroom2_.oroom2, IndexF), GetWords(r2max, oroom2_.rroom2, IndexF);
// read(1, Fmt, &cevent.clnt, cevent.ctick, cevent.cactio); //F
   cevent.clnt = GetWord(IndexF);
   GetWords(cmax, cevent.ctick, IndexF), GetWords(cmax, cevent.cactio, IndexF);
// read(1, "%L4", cevent.cflag); //F
   GetFlags(cmax, cevent.cflag, IndexF);
// read(1, Fmt, &vill.vlnt, vill.villns, vill.vprob, vill.vopps, vill.vbest, vill.vmelee); //F
   vill.vlnt = GetWord(IndexF), GetWords(vmax, vill.villns, IndexF);
   GetWords(vmax, vill.vprob, IndexF), GetWords(vmax, vill.vopps, IndexF);
   GetWords(vmax, vill.vbest, IndexF), GetWords(vmax, vill.vmelee, IndexF);
// read(1, Fmt, &advs.alnt, advs.aroom, advs.ascore, advs.avehic, advs.aobj, advs.aactio, advs.astren, advs.aflag); //F
   advs.alnt = GetWord(IndexF), GetWords(amax, advs.aroom, IndexF);
   GetWords(amax, advs.ascore, IndexF), GetWords(amax, advs.avehic, IndexF);
   GetWords(amax, advs.aobj, IndexF), GetWords(amax, advs.aactio, IndexF);
   GetWords(amax, advs.astren, IndexF), GetWords(amax, advs.aflag, IndexF);
// read(1, Fmt, &star.mbase, &rmsg.mlnt, rmsg.rtext); //F
   star.mbase = GetWord(IndexF);
   rmsg.mlnt = GetWord(IndexF), GetWords(mmax, rmsg.rtext, IndexF);

// close(1); //F
   fclose(IndexF);
// 						!INIT DONE.
   if (IOErrs > 0) {
      goto L1940;
   }

// INIT, PAGE 5

// THE INTERNAL DATA BASE IS NOW ESTABLISHED.
// SET UP TO PLAY THE GAME.

// L1025:
   intime(&time_.shour, &time_.smin, &time_.ssec);
// 						!GET TIME AND DATE.
// Day: datarry[0], Month: datarry[1], Year: datarry[2].
// idate(datarry);
// inirnd(datarry[0] | datarry[1] | datarry[2] | shour | smin | ssec);
// 	NEW WAY TO INITIALIZE /+TAA+/
   inirnd(time_.shour * 3600 + time_.smin * 60 + time_.ssec);

   play.winner = PlayerAX;
   last.lastit = advs.aobj[PlayerAX - 1];
   play.here = advs.aroom[play.winner - 1];
   hack.thfpos = objcts.oroom[ThiefOX - 1];
   state.bloc = objcts.oroom[BalloOX - 1];
   ret_val = true;

#ifdef ALLOW_GDT
// print( //F
//    "USED:%/" //F
//    "%I5 OF%I5 ROOMS%/"	"%I5 OF%I5 EXITS%/"		"%I5 OF%I5 OBJECTS%/"		"%I5 OF%I5 MESSAGES%/" //F
//    "%I5 OF%I5 VILLAINS%/"	"%I5 OF%I5 ADVENTURERS%/"	"%I5 OF%I5 CLOCK EVENTS%/"	"%I5 OF%I5 ROOM2 SLOTS", //F
//    rooms.rlnt, rmax,	exits.xlnt, xmax,		objcts.olnt, omax,		rmsg.mlnt, mmax, //F
//    vill.vlnt, vmax,	advs.alnt, amax,		cevent.clnt, cmax,		oroom2_.r2lnt, r2max //F
// ); //F
// print( //F
//    "MAX SCORE=%I5%/"		"EG SCORE=%I5%/"	"MAX RECNO=%I5%/" //F
//    "RDESC2 BASE=%I5%/"	"MELEE START=%I5%/"	"STAR MASK=%I7", //F
//    state.mxscor,		state.egmxsc,		recno, //F
//    rooms.rdesc2,		star.mbase,		star.strbit //F
// ); //F
// pause(1); //F
#endif

   return ret_val;
// INIT, PAGE 6

// ERRORS-- INIT FAILS.

L1900:
// print("I can't open ",MyIndexFile,"."); //F
   more_output("I can't open " MyIndexFile ".\n");
   goto L1975;
L1925:
// print( //F
//    "\"" MyIndexFile "\" is version %I1.%I1%A1.%/" //F
//    "I require version %I1.%I1%A1.", //F
//    Maj, Min, Edit, vmaj, vmin, vedit //F
// ); //F
   more_output("\"" MyIndexFile "\" is version %1d.%1d%c.\n", Maj, Min, Edit);
   more_output("I require version %1d.%1d%c.\n", vmaj, vmin, (int)vedit);
   goto L1975;
L1940:
   more_output("I can't read " MyIndexFile ": %1d error(s) found.", IOErrs);
L1950:
// print("I can't open ", MyStoryFile, "."); //F
   more_output("I can't open " MyStoryFile ".\n");
L1975:
// print( //F
//    "Suddenly a sinister, wraithlike figure appears before ", //F
//    "you,%/seeming to float in the air.  In a low, sorrowful voice", //F
//    " he says,%/\"Alas, the very nature of the world has changed, ", //F
//    "and the dungeon%/cannot be found.  All must now pass away.\"", //F
//    "  Raising his oaken staff%/in farewell, he fades into the ", //F
//    "spreading darkness.  In his place%/appears a tastefully ", //F
//    "lettered sign reading:%/%/%23XINITIALIZATION FAILURE%/%/", //F
//    "The darkness becomes all encompassing, and your vision fails." //F
// ); //F
   more_output("Suddenly a sinister, wraithlike figure appears before you,\n");
   more_output("seeming to float in the air.  In a low, sorrowful voice he says,\n");
   more_output("\"Alas, the very nature of the world has changed, and the dungeon\n");
   more_output("cannot be found.  All must now pass away.\"  Raising his oaken staff\n");
   more_output("in farewell, he fades into the spreading darkness.  In his place\n");
   more_output("appears a tastefully lettered sign reading:\n");
   more_output("\n");
   more_output("                       INITIALIZATION FAILURE\n");
   more_output("\n");
   more_output("The darkness becomes all encompassing, and your vision fails.\n");
   return ret_val;
}
