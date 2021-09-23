// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

static void xendmv(Bool);
static Bool xvehic(int);

// Main command loop for dungeon
void game_(void) {
// System generated locals
   int i__1;

// Local variables
   Bool f;
   int i, j;

// Initialized data
   static const char secho[1 * 4] = "E" "C" "H" "O";
#ifdef ALLOW_GDT
// Initialized Data
   static const char gdtstr[1 * 3] = "G" "D" "T";
#endif
// GAME, PAGE 2

// START UP, DESCRIBE CURRENT LOCATION.

   rspeak(1);
// 						!WELCOME ABOARD.
   f = rmdesc(3);
// 						!START GAME.

// NOW LOOP, READING AND EXECUTING COMMANDS.

L100:
   play.winner = aindex.player;
// 						!PLAYER MOVING.
   play.telflg = false;
// 						!ASSUME NOTHING TOLD.
   if (prsvec.prscon <= 1) {
      rdline(input.inbuf, input.inlnt, 1, sizeof input.inbuf[0]);
   }

#ifdef ALLOW_GDT
   for (i = 1; i <= 3; i++) {
// 						!CALL ON GDT?
      if (input.inbuf[i + prsvec.prscon - 2] != gdtstr[i - 1]) goto L200;
// L150: continue;
   }
   gdt();
// 						!YES, INVOKE.
   goto L100;
// 						!ONWARD.
#endif

//L200:
   ++state.moves;
   prsvec.prswon = parse(input.inbuf, input.inlnt, true/*, sizeof input.inbuf[0]*/);
   if (!prsvec.prswon) {
      goto L400;
   }
// 						!PARSE LOSES?
   if (xvehic(1)) {
      goto L400;
   }
// 						!VEHICLE HANDLE?

   if (prsvec.prsa == vindex.tellw) {
      goto L2000;
   }
// 						!TELL?
L300:
   if (prsvec.prso == oindex.valua || prsvec.prso == oindex.every) {
      goto L900;
   }
   if (!vappli(prsvec.prsa)) {
      goto L400;
   }
// 						!VERB OK?
L350:
   if (!findex.echof && play.here == rindex_.echor) {
      goto L1000;
   }
   f = rappli(rooms.ractio[play.here - 1]);

L400:
   xendmv(play.telflg);
// 						!DO END OF MOVE.
   if (!lit(play.here)) {
      prsvec.prscon = 1;
   }
   goto L100;

L900:
   valuac(oindex.valua);
   goto L350;
// GAME, PAGE 3

// SPECIAL CASE-- ECHO ROOM.
// IF INPUT IS NOT 'ECHO' OR A DIRECTION, JUST ECHO.

L1000:
   rdline(input.inbuf, input.inlnt, 0, sizeof input.inbuf[0]);
   ++state.moves;
// 						!CHARGE FOR MOVES.
   for (i = 1; i <= 4; ++i) {
// 						!INPUT = ECHO?
      if (input.inbuf[i - 1] != secho[i - 1]) {
         goto L1300;
      }
// L1100:
   }

//   Note: the following DO loop was changed from DO 1200 I=5,78
//     The change was necessary because the RDLINE function was changed,
//      and no longer provides a 78 character buffer padded with blanks.

   i__1 = input.inlnt;
   for (i = 5; i <= i__1; ++i) {
      if (input.inbuf[i - 1] != ' ') {
         goto L1300;
      }
// L1200:
   }

   rspeak(571);
// 						!KILL THE ECHO.
   findex.echof = true;
   objcts.oflag2[oindex.bar - 1] &= ~ScrDO;
   prsvec.prswon = true;
// 						!FAKE OUT PARSER.
   prsvec.prscon = 1;
// 						!FORCE NEW INPUT.
   goto L400;

L1300:
   prsvec.prswon = parse(input.inbuf, input.inlnt, false/*, sizeof input.inbuf[0]*/);
   if (!prsvec.prswon || prsvec.prsa != vindex.walkw) {
      goto L1400;
   }
   if (findxt(prsvec.prso, play.here)) {
      goto L300;
   }
// 						!VALID EXIT?

L1400:
// write(chan.outch, "%1X%78A1", (input.inbuf(j), j = 1, input.inlnt)); //F
   BegExSF(chan.outch, "(1x,78a1)", 0);
   i__1 = input.inlnt;
   for (j = 1; j <= i__1; ++j) DoFio(1, input.inbuf + (j - 1), sizeof input.inbuf[0]);
   EndExSF();
   play.telflg = true;
// 						!INDICATE OUTPUT.
   goto L1000;
// 						!MORE ECHO ROOM.
// GAME, PAGE 4

// SPECIAL CASE-- TELL <ACTOR>, NEW COMMAND
// NOTE THAT WE CANNOT BE IN THE ECHO ROOM.

L2000:
   if ((objcts.oflag2[prsvec.prso - 1] & ActrO) != 0) {
      goto L2100;
   }
   rspeak(602);
// 						!CANT DO IT.
   goto L350;
// 						!VAPPLI SUCCEEDS.

L2100:
   play.winner = oactor(prsvec.prso);
// 						!NEW PLAYER.
   play.here = advs.aroom[play.winner - 1];
// 						!NEW LOCATION.
   if (prsvec.prscon <= 1) {
      goto L2700;
   }
// 						!ANY INPUT?
   if (parse(input.inbuf, input.inlnt, true/*, sizeof input.inbuf[0])*/)) {
      goto L2150;
   }
L2700:
   i = 341;
// 						!FAILS.
   if (play.telflg) {
      i = 604;
   }
// 						!GIVE RESPONSE.
   rspeak(i);
L2600:
   play.winner = aindex.player;
// 						!RESTORE STATE.
   play.here = advs.aroom[play.winner - 1];
   goto L350;

L2150:
   if (aappli(advs.aactio[play.winner - 1])) {
      goto L2400;
   }
// 						!ACTOR HANDLE?
   if (xvehic(1)) {
      goto L2400;
   }
// 						!VEHICLE HANDLE?
   if (prsvec.prso == oindex.valua || prsvec.prso == oindex.every) {
      goto L2900;
   }
   if (!vappli(prsvec.prsa)) {
      goto L2400;
   }
// 						!VERB HANDLE?
//L2350:
   f = rappli(rooms.ractio[play.here - 1]);

L2400:
   xendmv(play.telflg);
// 						!DO END OF MOVE.
   goto L2600;
// 						!DONE.

L2900:
   valuac(oindex.valua);
// 						!ALL OR VALUABLES.
   goto L350;
}

// Execute end of move functions.
static void xendmv(Bool flag) {
// Local variables
   Bool f;
#if 0
   int x; //(@) Not actually used.
#endif

   if (!(flag)) {
      rspeak(341);
   }
// 						!DEFAULT REMARK.
   if (hack.thfact) {
      thiefd();
   }
// 						!THIEF DEMON.
   if (prsvec.prswon) {
      fightd();
   }
// 						!FIGHT DEMON.
   if (hack.swdact) {
      swordd();
   }
// 						!SWORD DEMON.
   if (prsvec.prswon) {
      f = clockd(/*x*/);
   }
// 						!CLOCK DEMON.
   if (prsvec.prswon) {
      f = xvehic(2);
   }
// 						!VEHICLE READOUT.
}

// Execute vehicle function
static Bool xvehic(int n) {
// System generated locals
   Bool ret_val;

// Local variables
   int av;

   ret_val = false;
// 						!ASSUME LOSES.
   av = advs.avehic[play.winner - 1];
// 						!GET VEHICLE.
   if (av != 0) {
      ret_val = oappli(objcts.oactio[av - 1], n);
   }
   return ret_val;
}
