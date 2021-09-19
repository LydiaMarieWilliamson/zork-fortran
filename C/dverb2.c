// SAVE- SAVE GAME STATE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

#include "F2C.h"
#include "extern.h"
#include "common.h"

static int cxappl_(int);

void savegm_(void) {
// System generated locals
   int i__1;

// Local variables
   int i;

// MISCELLANEOUS VARIABLES

   prsvec_1.prswon = false;
// 						!DISABLE GAME.
// Note: save file format is different for PDP vs. non-PDP versions

   i__1 = OpenF(1, "dsave.dat", "UNKNOWN", "SEQUENTIAL", "UNFORMATTED", 0);
   if (i__1 != 0) {
      goto L100;
   }

   i = gttime_();
// 						!GET TIME.
   BegExSU(1, 0, 0);
   DoUio(1, &vers_2.vmaj, sizeof vers_2.vmaj);
   DoUio(1, &vers_2.vmin, sizeof vers_2.vmin);
   DoUio(1, &vers_2.vedit, sizeof vers_2.vedit);
   EndExSU();
   BegExSU(1, 0, 0);
   DoUio(1, &play_1.winner, sizeof play_1.winner);
   DoUio(1, &play_1.here, sizeof play_1.here);
   DoUio(1, &hack_1.thfpos, sizeof hack_1.thfpos);
   DoUio(1, &play_1.telflg, sizeof play_1.telflg);
   DoUio(1, &hack_1.thfflg, sizeof hack_1.thfflg);
   DoUio(1, &hack_1.thfact, sizeof hack_1.thfact);
   DoUio(1, &hack_1.swdact, sizeof hack_1.swdact);
   DoUio(1, &hack_1.swdsta, sizeof hack_1.swdsta);
   DoUio(64, puzzle_1.cpvec, sizeof puzzle_1.cpvec[0]);
   EndExSU();
   BegExSU(1, 0, 0);
   DoUio(1, &i, sizeof i);
   DoUio(1, &state_1.moves, sizeof state_1.moves);
   DoUio(1, &state_1.deaths, sizeof state_1.deaths);
   DoUio(1, &state_1.rwscor, sizeof state_1.rwscor);
   DoUio(1, &state_1.egscor, sizeof state_1.egscor);
   DoUio(1, &state_1.mxload, sizeof state_1.mxload);
   DoUio(1, &state_1.ltshft, sizeof state_1.ltshft);
   DoUio(1, &state_1.bloc, sizeof state_1.bloc);
   DoUio(1, &state_1.mungrm, sizeof state_1.mungrm);
   DoUio(1, &state_1.hs, sizeof state_1.hs);
   DoUio(1, &screen_1.fromdr, sizeof screen_1.fromdr);
   DoUio(1, &screen_1.scolrm, sizeof screen_1.scolrm);
   DoUio(1, &screen_1.scolac, sizeof screen_1.scolac);
   EndExSU();
   BegExSU(1, 0, 0);
   DoUio(220, objcts_1.odesc1, sizeof objcts_1.odesc1[0]);
   DoUio(220, objcts_1.odesc2, sizeof objcts_1.odesc2[0]);
   DoUio(220, objcts_1.oflag1, sizeof objcts_1.oflag1[0]);
   DoUio(220, objcts_1.oflag2, sizeof objcts_1.oflag2[0]);
   DoUio(220, objcts_1.ofval, sizeof objcts_1.ofval[0]);
   DoUio(220, objcts_1.otval, sizeof objcts_1.otval[0]);
   DoUio(220, objcts_1.osize, sizeof objcts_1.osize[0]);
   DoUio(220, objcts_1.ocapac, sizeof objcts_1.ocapac[0]);
   DoUio(220, objcts_1.oroom, sizeof objcts_1.oroom[0]);
   DoUio(220, objcts_1.oadv, sizeof objcts_1.oadv[0]);
   DoUio(220, objcts_1.ocan, sizeof objcts_1.ocan[0]);
   EndExSU();
   BegExSU(1, 0, 0);
   DoUio(200, rooms_1.rval, sizeof rooms_1.rval[0]);
   DoUio(200, rooms_1.rflag, sizeof rooms_1.rflag[0]);
   EndExSU();
   BegExSU(1, 0, 0);
   DoUio(4, advs_1.aroom, sizeof advs_1.aroom[0]);
   DoUio(4, advs_1.ascore, sizeof advs_1.ascore[0]);
   DoUio(4, advs_1.avehic, sizeof advs_1.avehic[0]);
   DoUio(4, advs_1.astren, sizeof advs_1.astren[0]);
   DoUio(4, advs_1.aflag, sizeof advs_1.aflag[0]);
   EndExSU();
   BegExSU(1, 0, 0);
   DoUio(46, flags, sizeof flags[0]);
   DoUio(22, switch_, sizeof switch_[0]);
   DoUio(4, vill_1.vprob, sizeof vill_1.vprob[0]);
   DoUio(25, cevent_1.cflag, sizeof cevent_1.cflag[0]);
   DoUio(25, cevent_1.ctick, sizeof cevent_1.ctick[0]);
   EndExSU();

   CloseF(1);
   rspeak_(597);
   return;

L100:
   rspeak_(598);
// 						!CANT DO IT.
}

// RESTORE- RESTORE GAME STATE

void rstrgm_(void) {
// System generated locals
   int i__1;

// Local variables
   int i, j, k;

// MISCELLANEOUS VARIABLES

   prsvec_1.prswon = false;
// 						!DISABLE GAME.
// Note: save file format is different for PDP vs. non-PDP versions

   i__1 = OpenF(1, "dsave.dat", "OLD", "SEQUENTIAL", "UNFORMATTED", 0);
   if (i__1 != 0) {
      goto L100;
   }

   BegInSU(1, 0, 0);
   DoUio(1, &i, sizeof i);
   DoUio(1, &j, sizeof j);
   DoUio(1, &k, sizeof k);
   EndInSU();
   if (i != vers_2.vmaj || j != vers_2.vmin) {
      goto L200;
   }

   BegInSU(1, 0, 0);
   DoUio(1, &play_1.winner, sizeof play_1.winner);
   DoUio(1, &play_1.here, sizeof play_1.here);
   DoUio(1, &hack_1.thfpos, sizeof hack_1.thfpos);
   DoUio(1, &play_1.telflg, sizeof play_1.telflg);
   DoUio(1, &hack_1.thfflg, sizeof hack_1.thfflg);
   DoUio(1, &hack_1.thfact, sizeof hack_1.thfact);
   DoUio(1, &hack_1.swdact, sizeof hack_1.swdact);
   DoUio(1, &hack_1.swdsta, sizeof hack_1.swdsta);
   DoUio(64, puzzle_1.cpvec, sizeof puzzle_1.cpvec[0]);
   EndInSU();
   BegInSU(1, 0, 0);
   DoUio(1, &time_1.pltime, sizeof time_1.pltime);
   DoUio(1, &state_1.moves, sizeof state_1.moves);
   DoUio(1, &state_1.deaths, sizeof state_1.deaths);
   DoUio(1, &state_1.rwscor, sizeof state_1.rwscor);
   DoUio(1, &state_1.egscor, sizeof state_1.egscor);
   DoUio(1, &state_1.mxload, sizeof state_1.mxload);
   DoUio(1, &state_1.ltshft, sizeof state_1.ltshft);
   DoUio(1, &state_1.bloc, sizeof state_1.bloc);
   DoUio(1, &state_1.mungrm, sizeof state_1.mungrm);
   DoUio(1, &state_1.hs, sizeof state_1.hs);
   DoUio(1, &screen_1.fromdr, sizeof screen_1.fromdr);
   DoUio(1, &screen_1.scolrm, sizeof screen_1.scolrm);
   DoUio(1, &screen_1.scolac, sizeof screen_1.scolac);
   EndInSU();
   BegInSU(1, 0, 0);
   DoUio(220, objcts_1.odesc1, sizeof objcts_1.odesc1[0]);
   DoUio(220, objcts_1.odesc2, sizeof objcts_1.odesc2[0]);
   DoUio(220, objcts_1.oflag1, sizeof objcts_1.oflag1[0]);
   DoUio(220, objcts_1.oflag2, sizeof objcts_1.oflag2[0]);
   DoUio(220, objcts_1.ofval, sizeof objcts_1.ofval[0]);
   DoUio(220, objcts_1.otval, sizeof objcts_1.otval[0]);
   DoUio(220, objcts_1.osize, sizeof objcts_1.osize[0]);
   DoUio(220, objcts_1.ocapac, sizeof objcts_1.ocapac[0]);
   DoUio(220, objcts_1.oroom, sizeof objcts_1.oroom[0]);
   DoUio(220, objcts_1.oadv, sizeof objcts_1.oadv[0]);
   DoUio(220, objcts_1.ocan, sizeof objcts_1.ocan[0]);
   EndInSU();
   BegInSU(1, 0, 0);
   DoUio(200, rooms_1.rval, sizeof rooms_1.rval[0]);
   DoUio(200, rooms_1.rflag, sizeof rooms_1.rflag[0]);
   EndInSU();
   BegInSU(1, 0, 0);
   DoUio(4, advs_1.aroom, sizeof advs_1.aroom[0]);
   DoUio(4, advs_1.ascore, sizeof advs_1.ascore[0]);
   DoUio(4, advs_1.avehic, sizeof advs_1.avehic[0]);
   DoUio(4, advs_1.astren, sizeof advs_1.astren[0]);
   DoUio(4, advs_1.aflag, sizeof advs_1.aflag[0]);
   EndInSU();
   BegInSU(1, 0, 0);
   DoUio(46, flags, sizeof flags[0]);
   DoUio(22, switch_, sizeof switch_[0]);
   DoUio(4, vill_1.vprob, sizeof vill_1.vprob[0]);
   DoUio(25, cevent_1.cflag, sizeof cevent_1.cflag[0]);
   DoUio(25, cevent_1.ctick, sizeof cevent_1.ctick[0]);
   EndInSU();

   CloseF(1);
   rspeak_(599);
   return;

L100:
   rspeak_(598);
// 						!CANT DO IT.
   return;

L200:
   rspeak_(600);
// 						!OBSOLETE VERSION
   CloseF(1);
}

// WALK- MOVE IN SPECIFIED DIRECTION

Bool walk_(/*int x*/) {
// System generated locals
   Bool ret_val;

// WALK, PAGE 2

   ret_val = true;
// 						!ASSUME WINS.
   if (play_1.winner != aindex_1.player || lit_(play_1.here) || prob_(25, 25)) {
      goto L500;
   }
   if (!findxt_(prsvec_1.prso, play_1.here)) {
      goto L450;
   }
// 						!INVALID EXIT? GRUE
// 						!
   switch (curxt_1.xtype) {
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
   bug_(9, curxt_1.xtype);

L100:
   if (cxappl_(curxt_1.xactio) != 0) {
      goto L400;
   }
// 						!CEXIT... RETURNED ROOM?
   if (flags[*xflag - 1]) {
      goto L400;
   }
// 						!NO, FLAG ON?
L200:
   jigsup_(523);
// 						!BAD EXIT, GRUE
// 						!
   return ret_val;

L300:
   if (cxappl_(curxt_1.xactio) != 0) {
      goto L400;
   }
// 						!DOOR... RETURNED ROOM?
   if ((objcts_1.oflag2[curxt_1.xobj - 1] & OpenO) != 0) {
      goto L400;
   }
// 						!NO, DOOR OPEN?
   jigsup_(523);
// 						!BAD EXIT, GRUE
// 						!
   return ret_val;

L400:
   if (lit_(curxt_1.xroom1)) {
      goto L900;
   }
// 						!VALID ROOM, IS IT LIT?
L450:
   jigsup_(522);
// 						!NO, GRUE
// 						!
   return ret_val;

// ROOM IS LIT, OR WINNER IS NOT PLAYER (NO GRUE).

L500:
   if (findxt_(prsvec_1.prso, play_1.here)) {
      goto L550;
   }
// 						!EXIT EXIST?
L525:
   curxt_1.xstrng = 678;
// 						!ASSUME WALL.
   if (prsvec_1.prso == xsrch_1.xup) {
      curxt_1.xstrng = 679;
   }
// 						!IF UP, CANT.
   if (prsvec_1.prso == xsrch_1.xdown) {
      curxt_1.xstrng = 680;
   }
// 						!IF DOWN, CANT.
   if ((rooms_1.rflag[play_1.here - 1] & NWallR) != 0) {
      curxt_1.xstrng = 524;
   }
   rspeak_(curxt_1.xstrng);
   prsvec_1.prscon = 1;
// 						!STOP CMD STREAM.
   return ret_val;

L550:
   switch (curxt_1.xtype) {
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
   bug_(9, curxt_1.xtype);

L700:
   if (cxappl_(curxt_1.xactio) != 0) {
      goto L900;
   }
// 						!CEXIT... RETURNED ROOM?
   if (flags[*xflag - 1]) {
      goto L900;
   }
// 						!NO, FLAG ON?
L600:
   if (curxt_1.xstrng == 0) {
      goto L525;
   }
// 						!IF NO REASON, USE STD.
   rspeak_(curxt_1.xstrng);
// 						!DENY EXIT.
   prsvec_1.prscon = 1;
// 						!STOP CMD STREAM.
   return ret_val;

L800:
   if (cxappl_(curxt_1.xactio) != 0) {
      goto L900;
   }
// 						!DOOR... RETURNED ROOM?
   if ((objcts_1.oflag2[curxt_1.xobj - 1] & OpenO) != 0) {
      goto L900;
   }
// 						!NO, DOOR OPEN?
   if (curxt_1.xstrng == 0) {
      curxt_1.xstrng = 525;
   }
// 						!IF NO REASON, USE STD.
   rspsub_(curxt_1.xstrng, objcts_1.odesc2[curxt_1.xobj - 1]);
   prsvec_1.prscon = 1;
// 						!STOP CMD STREAM.
   return ret_val;

L900:
   ret_val = moveto_(curxt_1.xroom1, play_1.winner);
// 						!MOVE TO ROOM.
   if (ret_val) {
      ret_val = rmdesc_(0);
   }
// 						!DESCRIBE ROOM.
   return ret_val;
}

// CXAPPL- CONDITIONAL EXIT PROCESSORS

static int cxappl_(int ri) {
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
   bug_(5, ri);

// C1- COFFIN-CURE

L1000:
   findex_1.egyptf = objcts_1.oadv[oindex_1.coffi - 1] != play_1.winner;
// 						!T IF NO COFFIN.
   return ret_val;

// C2- CAROUSEL EXIT
// C5- CAROUSEL OUT

L2000:
   if (findex_1.caroff) {
      return ret_val;
   }
// 						!IF FLIPPED, NOTHING.
L2500:
   rspeak_(121);
// 						!SPIN THE COMPASS.
L5000:
   i = xpars_1.xelnt[xpars_1.xcond - 1] * rnd_(8);
// 						!CHOOSE RANDOM EXIT.
   curxt_1.xroom1 = exits_1.travel[rooms_1.rexit[play_1.here - 1] + i - 1] & xpars_1.xrmask;
   ret_val = curxt_1.xroom1;
// 						!RETURN EXIT.
   return ret_val;

// C3- CHIMNEY FUNCTION

L3000:
   findex_1.litldf = false;
// 						!ASSUME HEAVY LOAD.
   j = 0;
   i__1 = objcts_1.olnt;
   for (i = 1; i <= i__1; ++i) {
// 						!COUNT OBJECTS.
      if (objcts_1.oadv[i - 1] == play_1.winner) {
         ++j;
      }
// L3100:
   }

   if (j > 2) {
      return ret_val;
   }
// 						!CARRYING TOO MUCH?
   curxt_1.xstrng = 446;
// 						!ASSUME NO LAMP.
   if (objcts_1.oadv[oindex_1.lamp - 1] != play_1.winner) {
      return ret_val;
   }
// 						!NO LAMP?
   findex_1.litldf = true;
// 						!HE CAN DO IT.
   if ((objcts_1.oflag2[oindex_1.door - 1] & OpenO) == 0) {
      objcts_1.oflag2[oindex_1.door - 1] &= ~TChO;
   }
   return ret_val;

// C4-	FROBOZZ FLAG (MAGNET ROOM, FAKE EXIT)
// C6-	FROBOZZ FLAG (MAGNET ROOM, REAL EXIT)

L4000:
   if (findex_1.caroff) {
      goto L2500;
   }
// 						!IF FLIPPED, GO SPIN.
   findex_1.frobzf = false;
// 						!OTHERWISE, NOT AN EXIT.
   return ret_val;

L6000:
   if (findex_1.caroff) {
      goto L2500;
   }
// 						!IF FLIPPED, GO SPIN.
   findex_1.frobzf = true;
// 						!OTHERWISE, AN EXIT.
   return ret_val;

// C7-	FROBOZZ FLAG (BANK ALARM)

L7000:
   findex_1.frobzf = objcts_1.oroom[oindex_1.bills - 1] != 0 && objcts_1.oroom[oindex_1.portr - 1] != 0;
   return ret_val;
// CXAPPL, PAGE 3

// C8-	FROBOZZ FLAG (MRGO)

L8000:
   findex_1.frobzf = false;
// 						!ASSUME CANT MOVE.
   if (findex_1.mloc != curxt_1.xroom1) {
      goto L8100;
   }
// 						!MIRROR IN WAY?
   if (prsvec_1.prso == xsrch_1.xnorth || prsvec_1.prso == xsrch_1.xsouth) {
      goto L8200;
   }
   if (findex_1.mdir % 180 != 0) {
      goto L8300;
   }
// 						!MIRROR MUST BE N-S.
   curxt_1.xroom1 = (curxt_1.xroom1 - rindex_1.mra << 1) + rindex_1.mrae;
// 						!CALC EAST ROOM.
   if (prsvec_1.prso > xsrch_1.xsouth) {
      ++curxt_1.xroom1;
   }
// 						!IF SW/NW, CALC WEST.
L8100:
   ret_val = curxt_1.xroom1;
   return ret_val;

L8200:
   curxt_1.xstrng = 814;
// 						!ASSUME STRUC BLOCKS.
   if (findex_1.mdir % 180 == 0) {
      return ret_val;
   }
// 						!IF MIRROR N-S, DONE.
L8300:
   ldir = findex_1.mdir;
// 						!SEE WHICH MIRROR.
   if (prsvec_1.prso == xsrch_1.xsouth) {
      ldir = 180;
   }
   curxt_1.xstrng = 815;
// 						!MIRROR BLOCKS.
   if (ldir > 180 && !findex_1.mr1f || ldir < 180 && !findex_1.mr2f) {
      curxt_1.xstrng = 816;
   }
   return ret_val;

// C9-	FROBOZZ FLAG (MIRIN)

L9000:
   if (mrhere_(play_1.here) != 1) {
      goto L9100;
   }
// 						!MIRROR 1 HERE?
   if (findex_1.mr1f) {
      curxt_1.xstrng = 805;
   }
// 						!SEE IF BROKEN.
   findex_1.frobzf = findex_1.mropnf;
// 						!ENTER IF OPEN.
   return ret_val;

L9100:
   findex_1.frobzf = false;
// 						!NOT HERE,
   curxt_1.xstrng = 817;
// 						!LOSE.
   return ret_val;
// CXAPPL, PAGE 4

// C10-	FROBOZZ FLAG (MIRROR EXIT)

L10000:
   findex_1.frobzf = false;
// 						!ASSUME CANT.
   ldir = (prsvec_1.prso - xsrch_1.xnorth) / xsrch_1.xnorth * 45;
// 						!XLATE DIR TO DEGREES.
   if (!findex_1.mropnf || (findex_1.mdir + 270) % 360 != ldir && prsvec_1.prso != xsrch_1.xexit) {
      goto L10200;
   }
   curxt_1.xroom1 = (findex_1.mloc - rindex_1.mra << 1) + rindex_1.mrae + 1 - findex_1.mdir / 180;
// 						!ASSUME E-W EXIT.
   if (findex_1.mdir % 180 == 0) {
      goto L10100;
   }
// 						!IF N-S, OK.
   curxt_1.xroom1 = findex_1.mloc + 1;
// 						!ASSUME N EXIT.
   if (findex_1.mdir > 180) {
      curxt_1.xroom1 = findex_1.mloc - 1;
   }
// 						!IF SOUTH.
L10100:
   ret_val = curxt_1.xroom1;
   return ret_val;

L10200:
   if (!findex_1.wdopnf || (findex_1.mdir + 180) % 360 != ldir && prsvec_1.prso != xsrch_1.xexit) {
      return ret_val;
   }
   curxt_1.xroom1 = findex_1.mloc + 1;
// 						!ASSUME N.
   if (findex_1.mdir == 0) {
      curxt_1.xroom1 = findex_1.mloc - 1;
   }
// 						!IF S.
   rspeak_(818);
// 						!CLOSE DOOR.
   findex_1.wdopnf = false;
   ret_val = curxt_1.xroom1;
   return ret_val;

// C11-	MAYBE DOOR.  NORMAL MESSAGE IS THAT DOOR IS CLOSED.
// 	BUT IF LCELL.NE.4, DOOR ISNT THERE.

L11000:
   if (findex_1.lcell != 4) {
      curxt_1.xstrng = 678;
   }
// 						!SET UP MSG.
   return ret_val;

// C12-	FROBZF (PUZZLE ROOM MAIN ENTRANCE)

L12000:
   findex_1.frobzf = true;
// 						!ALWAYS ENTER.
   findex_1.cphere = 10;
// 						!SET SUBSTATE.
   return ret_val;

// C13-	CPOUTF (PUZZLE ROOM SIZE ENTRANCE)

L13000:
   findex_1.cphere = 52;
// 						!SET SUBSTATE.
   return ret_val;
// CXAPPL, PAGE 5

// C14-	FROBZF (PUZZLE ROOM TRANSITIONS)

L14000:
   findex_1.frobzf = false;
// 						!ASSSUME LOSE.
   if (prsvec_1.prso != xsrch_1.xup) {
      goto L14100;
   }
// 						!UP?
   if (findex_1.cphere != 10) {
      return ret_val;
   }
// 						!AT EXIT?
   curxt_1.xstrng = 881;
// 						!ASSUME NO LADDER.
   if (puzzle_1.cpvec[findex_1.cphere] != -2) {
      return ret_val;
   }
// 						!LADDER HERE?
   rspeak_(882);
// 						!YOU WIN.
   findex_1.frobzf = true;
// 						!LET HIM OUT.
   return ret_val;

L14100:
   if (findex_1.cphere != 52 || prsvec_1.prso != xsrch_1.xwest || !findex_1.cpoutf) {
      goto L14200;
   }
   findex_1.frobzf = true;
// 						!YES, LET HIM OUT.
   return ret_val;

L14200:
   for (i = 1; i <= 16; i += 2) {
// 						!LOCATE EXIT.
      if (prsvec_1.prso == puzzle_1.cpdr[i - 1]) {
         goto L14400;
      }
// L14300:
   }
   return ret_val;
// 						!NO SUCH EXIT.

L14400:
   j = puzzle_1.cpdr[i];
// 						!GET DIRECTIONAL OFFSET.
   nxt = findex_1.cphere + j;
// 						!GET NEXT STATE.
   k = 8;
// 						!GET ORTHOGONAL DIR.
   if (j < 0) {
      k = -8;
   }
   if ((abs(j) == 1 || abs(j) == 8 || (puzzle_1.cpvec[findex_1.cphere + k - 1] == 0 || puzzle_1.cpvec[nxt - k - 1] == 0)) && puzzle_1.cpvec[nxt - 1] == 0) {
      goto L14500;
   }
   return ret_val;

L14500:
   cpgoto_(nxt);
// 						!MOVE TO STATE.
   curxt_1.xroom1 = rindex_1.cpuzz;
// 						!STAY IN ROOM.
   ret_val = curxt_1.xroom1;
   return ret_val;

}
