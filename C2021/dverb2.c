// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

static int cxappl(int);

// Save game state
void savegm(void) {
   prsvec.prswon = false;
// 						!DISABLE GAME.
// Note: save file format is different for PDP versus non-PDP versions

// open(unit:1, file:"dsave.dat", access:"SEQUENTIAL", status:"UNKNOWN", form:"UNFORMATTED", err:L100); //F
   if (OpenF(1, "dsave.dat", "UNKNOWN", "SEQUENTIAL", "UNFORMATTED", 0) != 0) goto L100;

   int PlTime = gttime();
// 						!GET TIME.

#define PutVar(Var) DoUio(1, (void *)&(Var), sizeof (Var))
#define PutArr(N, Buf) DoUio((N), (void *)(Buf), sizeof (Buf)[0])

// write(1, vmaj, vmin, vedit); //F
   BegExSU(1);
{  int Edit = vedit; PutVar(vmaj), PutVar(vmin), PutVar(Edit); }
   EndExSU();
// write(1, //F
//    play.winner, play.here, hack.thfpos, play.telflg, hack.thfflg, hack.thfact, //F
//    hack.swdact, hack.swdsta, puzzle.cpvec //F
// ); //F
   BegExSU(1);
   PutVar(play.winner), PutVar(play.here), PutVar(hack.thfpos);
   PutVar(play.telflg), PutVar(hack.thfflg), PutVar(hack.thfact);
   PutVar(hack.swdact), PutVar(hack.swdsta), PutArr(64, puzzle.cpvec);
   EndExSU();
// write(1, //F
//    PlTime, state.moves, state.deaths, state.rwscor, state.egscor, state.mxload, //F
//    state.ltshft, state.bloc, state.mungrm, state.hs, screen.fromdr, screen.scolrm, screen.scolac //F
// ); //F
   BegExSU(1);
   PutVar(PlTime), PutVar(state.moves), PutVar(state.deaths), PutVar(state.rwscor);
   PutVar(state.egscor), PutVar(state.mxload);
   PutVar(state.ltshft), PutVar(state.bloc), PutVar(state.mungrm), PutVar(state.hs),
   PutVar(screen.fromdr), PutVar(screen.scolrm), PutVar(screen.scolac);
   EndExSU();
// write(1, //F
//   objcts.odesc1, objcts.odesc2, objcts.oflag1, objcts.oflag2, objcts.ofval, objcts.otval, //F
//   objcts.osize, objcts.ocapac, objcts.oroom, objcts.oadv, objcts.ocan //F
// ); //F
   BegExSU(1);
   PutArr(220, objcts.odesc1), PutArr(220, objcts.odesc2), PutArr(220, objcts.oflag1), PutArr(220, objcts.oflag2);
   PutArr(220, objcts.ofval), PutArr(220, objcts.otval);
   PutArr(220, objcts.osize), PutArr(220, objcts.ocapac);
   PutArr(220, objcts.oroom), PutArr(220, objcts.oadv), PutArr(220, objcts.ocan);
   EndExSU();
// write(1, rooms.rval, rooms.rflag); //F
   BegExSU(1);
   PutArr(200, rooms.rval), PutArr(200, rooms.rflag);
   EndExSU();
// write(1, advs.aroom, advs.ascore, advs.avehic, advs.astren, advs.aflag); //F
   BegExSU(1);
   PutArr(4, advs.aroom), PutArr(4, advs.ascore), PutArr(4, advs.avehic), PutArr(4, advs.astren), PutArr(4, advs.aflag);
   EndExSU();
// write(1, flags, switch_, vill.vprob, cevent.cflag, cevent.ctick); //F
   BegExSU(1);
   PutArr(46, flags), PutArr(22, switch_), PutArr(4, vill.vprob), PutArr(25, cevent.cflag), PutArr(25, cevent.ctick);
   EndExSU();

// close(unit:1); //F
   CloseF(1);
   rspeak(597);
   return;

L100:
   rspeak(598);
// 						!CANT DO IT.
}

// Restore game state
void rstrgm(void) {
   prsvec.prswon = false;
// 						!DISABLE GAME.
// Note: save file format is different for PDP versus non-PDP versions

// open(unit:1, file:"dsave.dat", access:"SEQUENTIAL", status:"OLD", form:"UNFORMATTED", err:L100); //F
   if (OpenF(1, "dsave.dat", "OLD", "SEQUENTIAL", "UNFORMATTED", 0) != 0) goto L100;

#define GetVar(Var) DoUio(1, (void *)&(Var), sizeof (Var))
#define GetArr(N, Buf) DoUio((N), (void *)(Buf), sizeof (Buf)[0])

// read(1, &Maj, &Min, &Edit); //F
   int Maj, Min, Edit; BegInSU(1), GetVar(Maj), GetVar(Min), GetVar(Edit), EndInSU();
   if (Maj != vmaj || Min != vmin) goto L200;

// read(1, //F
//    &play.winner, &play.here, &hack.thfpos, &play.telflg, &play.thfflg, &hack.thfflg, //F
//    &hack.swdact, &hack.swdsta, &puzzle.cpvec //F
// ); //F
   BegInSU(1);
   GetVar(play.winner), GetVar(play.here), GetVar(hack.thfpos);
   GetVar(play.telflg), GetVar(hack.thfflg), GetVar(hack.thfact);
   GetVar(hack.swdact), GetVar(hack.swdsta), GetArr(64, puzzle.cpvec);
   EndInSU();
// read(1, //F
//    &time_.pltime, &state.moves, &state.deaths, &state.rwscor, &state.egscor, &state.mxload, //F
//    &state.ltshft, &state.bloc, &state.mungrm, &state.hs, &state.fromdr, &state.scolrm, &state.scolac //F
// ); //F
   BegInSU(1);
   GetVar(time_.pltime), GetVar(state.moves), GetVar(state.deaths), GetVar(state.rwscor);
   GetVar(state.egscor), GetVar(state.mxload);
   GetVar(state.ltshft), GetVar(state.bloc), GetVar(state.mungrm), GetVar(state.hs), GetVar(screen.fromdr);
   GetVar(screen.scolrm), GetVar(screen.scolac);
   EndInSU();
// read(1, //F
//    &objcts.odesc1, &objcts.odesc2, &objcts.oflag1, &objcts.oflag2, &objcts.ofval, &objcts.otval, //F
//    &objcts.osize, &objcts.ocapac, &objcts.oroom, &objcts.oadv, &objcts.ocan //F
// ); //F
   BegInSU(1);
   GetArr(220, objcts.odesc1), GetArr(220, objcts.odesc2), GetArr(220, objcts.oflag1), GetArr(220, objcts.oflag2);
   GetArr(220, objcts.ofval), GetArr(220, objcts.otval);
   GetArr(220, objcts.osize), GetArr(220, objcts.ocapac);
   GetArr(220, objcts.oroom), GetArr(220, objcts.oadv), GetArr(220, objcts.ocan);
   EndInSU();
// read(1, rooms.rval, rooms.rflag); //F
   BegInSU(1);
   GetArr(200, rooms.rval), GetArr(200, rooms.rflag);
   EndInSU();
// read(1, &advs.aroom, &advs.ascore, &advs.avehic, &advs.astren, &advs.aflag); //F
   BegInSU(1);
   GetArr(4, advs.aroom), GetArr(4, advs.ascore), GetArr(4, advs.avehic), GetArr(4, advs.astren), GetArr(4, advs.aflag);
   EndInSU();
// read(1, flags, switch_, &vill.vprob, cevent.cflag, cevent.ctick); //F
   BegInSU(1);
   GetArr(46, flags), GetArr(22, switch_), GetArr(4, vill.vprob), GetArr(25, cevent.cflag), GetArr(25, cevent.ctick);
   EndInSU();

// close(unit:1); //F
   CloseF(1);
   rspeak(599);
   return;

L100:
   rspeak(598);
// 						!CANT DO IT.
   return;

L200:
   rspeak(600);
// 						!OBSOLETE VERSION
// close(unit:1); //F
   CloseF(1);
}

// Move in specified direction
Bool walk(/*int x*/) {
// System generated locals
   Bool ret_val;

// WALK, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   if (play.winner != PlayerAX || lit(play.here) || prob(25, 25)) {
      goto L500;
   }
   if (!findxt(prsvec.prso, play.here)) {
      goto L450;
   }
// 						!INVALID EXIT? GRUE
// 						!
   switch (curxt.xtype) {
      case 1:
         goto L400;
      case 2:
         goto L200;
      case 3:
         goto L100;
      case 4:
         goto L300;
   }
// 						!DECODE EXIT TYPE.
   bug(9, curxt.xtype);

L100:
   if (cxappl(curxt.xactio) != 0) {
      goto L400;
   }
// 						!CEXIT... RETURNED ROOM?
   if (flags[*xflag - 1]) {
      goto L400;
   }
// 						!NO, FLAG ON?
L200:
   jigsup(523);
// 						!BAD EXIT, GRUE
// 						!
   return ret_val;

L300:
   if (cxappl(curxt.xactio) != 0) {
      goto L400;
   }
// 						!DOOR... RETURNED ROOM?
   if ((objcts.oflag2[curxt.xobj - 1] & OpenO) != 0) {
      goto L400;
   }
// 						!NO, DOOR OPEN?
   jigsup(523);
// 						!BAD EXIT, GRUE
// 						!
   return ret_val;

L400:
   if (lit(curxt.xroom1)) {
      goto L900;
   }
// 						!VALID ROOM, IS IT LIT?
L450:
   jigsup(522);
// 						!NO, GRUE
// 						!
   return ret_val;

// ROOM IS LIT, OR WINNER IS NOT PLAYER (NO GRUE).

L500:
   if (findxt(prsvec.prso, play.here)) {
      goto L550;
   }
// 						!EXIT EXIST?
L525:
   curxt.xstrng = 678;
// 						!ASSUME WALL.
   if (prsvec.prso == UpDX) {
      curxt.xstrng = 679;
   }
// 						!IF UP, CANT.
   if (prsvec.prso == DownDX) {
      curxt.xstrng = 680;
   }
// 						!IF DOWN, CANT.
   if ((rooms.rflag[play.here - 1] & NWallR) != 0) {
      curxt.xstrng = 524;
   }
   rspeak(curxt.xstrng);
   prsvec.prscon = 1;
// 						!STOP CMD STREAM.
   return ret_val;

L550:
   switch (curxt.xtype) {
      case 1:
         goto L900;
      case 2:
         goto L600;
      case 3:
         goto L700;
      case 4:
         goto L800;
   }
// 						!BRANCH ON EXIT TYPE.
   bug(9, curxt.xtype);

L700:
   if (cxappl(curxt.xactio) != 0) {
      goto L900;
   }
// 						!CEXIT... RETURNED ROOM?
   if (flags[*xflag - 1]) {
      goto L900;
   }
// 						!NO, FLAG ON?
L600:
   if (curxt.xstrng == 0) {
      goto L525;
   }
// 						!IF NO REASON, USE STD.
   rspeak(curxt.xstrng);
// 						!DENY EXIT.
   prsvec.prscon = 1;
// 						!STOP CMD STREAM.
   return ret_val;

L800:
   if (cxappl(curxt.xactio) != 0) {
      goto L900;
   }
// 						!DOOR... RETURNED ROOM?
   if ((objcts.oflag2[curxt.xobj - 1] & OpenO) != 0) {
      goto L900;
   }
// 						!NO, DOOR OPEN?
   if (curxt.xstrng == 0) {
      curxt.xstrng = 525;
   }
// 						!IF NO REASON, USE STD.
   rspsub(curxt.xstrng, objcts.odesc2[curxt.xobj - 1]);
   prsvec.prscon = 1;
// 						!STOP CMD STREAM.
   return ret_val;

L900:
   ret_val = moveto(curxt.xroom1, play.winner);
// 						!MOVE TO ROOM.
   if (ret_val) {
      ret_val = rmdesc(0);
   }
// 						!DESCRIBE ROOM.
   return ret_val;
}

// Conditional exit processors
static int cxappl(int ri) {
// System generated locals
   int ret_val, i__1;

// Local variables
   int i, j, k;
   int nxt;
   int ldir;

// CXAPPL, PAGE 2

   ret_val = 0;
// 						!NO RETURN.
   if (ri == 0) {
      return ret_val;
   }
// 						!IF NO ACTION, DONE.
   switch (ri) {
      case 1:
         goto L1000;
      case 2:
         goto L2000;
      case 3:
         goto L3000;
      case 4:
         goto L4000;
      case 5:
         goto L5000;
      case 6:
         goto L6000;
      case 7:
         goto L7000;
      case 8:
         goto L8000;
      case 9:
         goto L9000;
      case 10:
         goto L10000;
      case 11:
         goto L11000;
      case 12:
         goto L12000;
      case 13:
         goto L13000;
      case 14:
         goto L14000;
   }
   bug(5, ri);

// C1- COFFIN-CURE

L1000:
   findex.egyptf = objcts.oadv[CoffiOX - 1] != play.winner;
// 						!T IF NO COFFIN.
   return ret_val;

// C2- CAROUSEL EXIT
// C5- CAROUSEL OUT

L2000:
   if (findex.caroff) {
      return ret_val;
   }
// 						!IF FLIPPED, NOTHING.
L2500:
   rspeak(121);
// 						!SPIN THE COMPASS.
L5000:
   i = xpars.xelnt[xpars.xcond - 1] * rnd(8);
// 						!CHOOSE RANDOM EXIT.
   curxt.xroom1 = exits.travel[rooms.rexit[play.here - 1] + i - 1] & xpars.xrmask;
   ret_val = curxt.xroom1;
// 						!RETURN EXIT.
   return ret_val;

// C3- CHIMNEY FUNCTION

L3000:
   findex.litldf = false;
// 						!ASSUME HEAVY LOAD.
   j = 0;
   i__1 = objcts.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!COUNT OBJECTS.
      if (objcts.oadv[i - 1] == play.winner) {
         ++j;
      }
// L3100:
   }

   if (j > 2) {
      return ret_val;
   }
// 						!CARRYING TOO MUCH?
   curxt.xstrng = 446;
// 						!ASSUME NO LAMP.
   if (objcts.oadv[LampOX - 1] != play.winner) {
      return ret_val;
   }
// 						!NO LAMP?
   findex.litldf = true;
// 						!HE CAN DO IT.
   if ((objcts.oflag2[DoorOX - 1] & OpenO) == 0) {
      objcts.oflag2[DoorOX - 1] &= ~TChO;
   }
   return ret_val;

// C4-	FROBOZZ FLAG (MAGNET ROOM, FAKE EXIT)
// C6-	FROBOZZ FLAG (MAGNET ROOM, REAL EXIT)

L4000:
   if (findex.caroff) {
      goto L2500;
   }
// 						!IF FLIPPED, GO SPIN.
   findex.frobzf = false;
// 						!OTHERWISE, NOT AN EXIT.
   return ret_val;

L6000:
   if (findex.caroff) {
      goto L2500;
   }
// 						!IF FLIPPED, GO SPIN.
   findex.frobzf = true;
// 						!OTHERWISE, AN EXIT.
   return ret_val;

// C7-	FROBOZZ FLAG (BANK ALARM)

L7000:
   findex.frobzf = objcts.oroom[BillsOX - 1] != 0 && objcts.oroom[PortrOX - 1] != 0;
   return ret_val;
// CXAPPL, PAGE 3

// C8-	FROBOZZ FLAG (MRGO)

L8000:
   findex.frobzf = false;
// 						!ASSUME CANT MOVE.
   if (findex.mloc != curxt.xroom1) {
      goto L8100;
   }
// 						!MIRROR IN WAY?
   if (prsvec.prso == NorthDX || prsvec.prso == SouthDX) {
      goto L8200;
   }
   if (findex.mdir % 180 != 0) {
      goto L8300;
   }
// 						!MIRROR MUST BE N-S.
   curxt.xroom1 = (curxt.xroom1 - MrArX << 1) + MrAerX;
// 						!CALC EAST ROOM.
   if (prsvec.prso > SouthDX) {
      ++curxt.xroom1;
   }
// 						!IF SW/NW, CALC WEST.
L8100:
   ret_val = curxt.xroom1;
   return ret_val;

L8200:
   curxt.xstrng = 814;
// 						!ASSUME STRUC BLOCKS.
   if (findex.mdir % 180 == 0) {
      return ret_val;
   }
// 						!IF MIRROR N-S, DONE.
L8300:
   ldir = findex.mdir;
// 						!SEE WHICH MIRROR.
   if (prsvec.prso == SouthDX) {
      ldir = 180;
   }
   curxt.xstrng = 815;
// 						!MIRROR BLOCKS.
   if (ldir > 180 && !findex.mr1f || ldir < 180 && !findex.mr2f) {
      curxt.xstrng = 816;
   }
   return ret_val;

// C9-	FROBOZZ FLAG (MIRIN)

L9000:
   if (mrhere(play.here) != 1) {
      goto L9100;
   }
// 						!MIRROR 1 HERE?
   if (findex.mr1f) {
      curxt.xstrng = 805;
   }
// 						!SEE IF BROKEN.
   findex.frobzf = findex.mropnf;
// 						!ENTER IF OPEN.
   return ret_val;

L9100:
   findex.frobzf = false;
// 						!NOT HERE,
   curxt.xstrng = 817;
// 						!LOSE.
   return ret_val;
// CXAPPL, PAGE 4

// C10-	FROBOZZ FLAG (MIRROR EXIT)

L10000:
   findex.frobzf = false;
// 						!ASSUME CANT.
   ldir = (prsvec.prso - NorthDX) / NorthDX * 45;
// 						!XLATE DIR TO DEGREES.
   if (!findex.mropnf || (findex.mdir + 270) % 360 != ldir && prsvec.prso != ExitDX) {
      goto L10200;
   }
   curxt.xroom1 = (findex.mloc - MrArX << 1) + MrAerX + 1 - findex.mdir / 180;
// 						!ASSUME E-W EXIT.
   if (findex.mdir % 180 == 0) {
      goto L10100;
   }
// 						!IF N-S, OK.
   curxt.xroom1 = findex.mloc + 1;
// 						!ASSUME N EXIT.
   if (findex.mdir > 180) {
      curxt.xroom1 = findex.mloc - 1;
   }
// 						!IF SOUTH.
L10100:
   ret_val = curxt.xroom1;
   return ret_val;

L10200:
   if (!findex.wdopnf || (findex.mdir + 180) % 360 != ldir && prsvec.prso != ExitDX) {
      return ret_val;
   }
   curxt.xroom1 = findex.mloc + 1;
// 						!ASSUME N.
   if (findex.mdir == 0) {
      curxt.xroom1 = findex.mloc - 1;
   }
// 						!IF S.
   rspeak(818);
// 						!CLOSE DOOR.
   findex.wdopnf = false;
   ret_val = curxt.xroom1;
   return ret_val;

// C11-	MAYBE DOOR.  NORMAL MESSAGE IS THAT DOOR IS CLOSED.
// 	BUT IF LCELL.NE.4, DOOR ISNT THERE.

L11000:
   if (findex.lcell != 4) {
      curxt.xstrng = 678;
   }
// 						!SET UP MSG.
   return ret_val;

// C12-	FROBZF (PUZZLE ROOM MAIN ENTRANCE)

L12000:
   findex.frobzf = true;
// 						!ALWAYS ENTER.
   findex.cphere = 10;
// 						!SET SUBSTATE.
   return ret_val;

// C13-	CPOUTF (PUZZLE ROOM SIZE ENTRANCE)

L13000:
   findex.cphere = 52;
// 						!SET SUBSTATE.
   return ret_val;
// CXAPPL, PAGE 5

// C14-	FROBZF (PUZZLE ROOM TRANSITIONS)

L14000:
   findex.frobzf = false;
// 						!ASSSUME LOSE.
   if (prsvec.prso != UpDX) {
      goto L14100;
   }
// 						!UP?
   if (findex.cphere != 10) {
      return ret_val;
   }
// 						!AT EXIT?
   curxt.xstrng = 881;
// 						!ASSUME NO LADDER.
   if (puzzle.cpvec[findex.cphere] != -2) {
      return ret_val;
   }
// 						!LADDER HERE?
   rspeak(882);
// 						!YOU WIN.
   findex.frobzf = true;
// 						!LET HIM OUT.
   return ret_val;

L14100:
   if (findex.cphere != 52 || prsvec.prso != WestDX || !findex.cpoutf) {
      goto L14200;
   }
   findex.frobzf = true;
// 						!YES, LET HIM OUT.
   return ret_val;

L14200:
   for (i = 1; i <= 16; i += 2) {
// 						!LOCATE EXIT.
      if (prsvec.prso == puzzle.cpdr[i - 1]) {
         goto L14400;
      }
// L14300:
   }
   return ret_val;
// 						!NO SUCH EXIT.

L14400:
   j = puzzle.cpdr[i];
// 						!GET DIRECTIONAL OFFSET.
   nxt = findex.cphere + j;
// 						!GET NEXT STATE.
   k = 8;
// 						!GET ORTHOGONAL DIR.
   if (j < 0) {
      k = -8;
   }
   if ((abs(j) == 1 || abs(j) == 8 || (puzzle.cpvec[findex.cphere + k - 1] == 0 || puzzle.cpvec[nxt - k - 1] == 0)) && puzzle.cpvec[nxt - 1] == 0) {
      goto L14500;
   }
   return ret_val;

L14500:
   cpgoto(nxt);
// 						!MOVE TO STATE.
   curxt.xroom1 = CPuzzRX;
// 						!STAY IN ROOM.
   ret_val = curxt.xroom1;
   return ret_val;
}
