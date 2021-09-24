// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "extern.h"
#include "common.h"

// Game debugging tool
void gdt(void) {
#ifdef ALLOW_GDT
// Initialized data
   const int cmdmax = 38;
   static char dbgcmd[2 * 38] =
      "DR" "DO" "DA" "DC" "DX" "DH" "DL" "DV" "DF" "DS" "AF" "HE" "NR" "NT" "NC" "ND" "RR" "RT" "RC"
      "RD" "TK" "EX" "AR" "AO" "AA" "AC" "AX" "AV" "D2" "DN" "AN" "DM" "DT" "AH" "DP" "PD" "DZ" "AZ";
   static char ldbgcmd[2 * 38] =
      "dr" "do" "da" "dc" "dx" "dh" "dl" "dv" "df" "ds" "af" "he" "nr" "nt" "nc" "nd" "rr" "rt" "rc"
      "rd" "tk" "ex" "ar" "ao" "aa" "ac" "ax" "av" "d2" "dn" "an" "dm" "dt" "ah" "dp" "pd" "dz" "az";
   static const int argtyp[38] = {
      2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 3, 3, 3, 3, 1, 3, 2, 2, 1, 2, 1, 0, 0, 0, 0, 1
   };

// static char Format0[] = "   RANGE   CONTENTS"; //F
// static char Format1[] = " Old=%L2%6XNew= %$"; //F
// static char Format2[] = " Old= %I6%6XNew= %$"; //F
   static char Format0[] = "(\2   RANGE   CONTENTS\2)";
   static char Format1[] = "(\2 Old=\2,l2,6x,\2New= \2,$)";
   static char Format2[] = "(\2 Old= \2,i6,6x,\2New= \2,$)";

// System generated locals
   int i__1, i__2;

// Local variables
   int i, j, k, l, l1;
   char cmd[2];
   int fmax, smax;

// GDT, PAGE 2

// FIRST, VALIDATE THAT THE CALLER IS AN IMPLEMENTER.

   fmax = 46;
// 						!SET ARRAY LIMITS.
   smax = 22;

   if (debug.gdtflg != 0) {
      goto L2000;
   }
// 						!IF OK, SKIP.
// write(chan.outch, " You are not an authorized user."); //F
   BegExSF(chan.outch, "(\2 You are not an authorized user.\2)"), EndExSF();
// 						!NOT AN IMPLEMENTER.
   return;
// 						!BOOT HIM OFF

// GDT, PAGE 2A

// HERE TO GET NEXT COMMAND

L2000:
// write(chan.outch, " GDT>%$"); //F
   BegExSF(chan.outch, "(\2 GDT>\2,$)"), EndExSF();
// 						!OUTPUT PROMPT.
// read(chan.inpch, "%A2", cmd); //F
   BegInSF(chan.inpch, "(a2)"), DoFio(1, cmd, sizeof cmd), EndInSF();
// 						!GET COMMAND.
   if (CompS(cmd, "  ", sizeof cmd) == 0) {
      goto L2000;
   }
// 						!IGNORE BLANKS.
   i__1 = cmdmax;
   for (i = 1; i <= i__1; ++i) {
// 						!LOOK IT UP.
      if (CompS(cmd, dbgcmd + (i - 1 << 1), sizeof cmd) == 0) {
         goto L2300;
      }
// 						!FOUND?
// 	  check for lower case command, as well
      if (CompS(cmd, ldbgcmd + (i - 1 << 1), sizeof cmd) == 0) {
         goto L2300;
      }
// L2100:
   }
L2200:
// write(chan.outch, " ?"); //F
   BegExSF(chan.outch, "(\2 ?\2)"), EndExSF();
// 						!NO, LOSE.
   goto L2000;

//L230:
//L240:
//L225:
//L235:
//L245:

L2300:
   switch (argtyp[i - 1] + 1) {
      case 1:
         goto L2400;
      case 2:
         goto L2500;
      case 3:
         goto L2600;
      case 4:
         goto L2700;
   }
// 						!BRANCH ON ARG TYPE.
   goto L2200;
// 						!ILLEGAL TYPE.

L2700:
// write(chan.outch, " Idx,Ary:  %$"); //F
   BegExSF(chan.outch, "(\2 Idx,Ary:  \2,$)"), EndExSF();
// 						!TYPE 3, REQUEST ARRAY COORDS.
// read(chan.inpch, "%2I6", &j, &k); //F
   BegInSF(chan.inpch, "(2i6)"), DoFio(1, &j, sizeof j), DoFio(1, &k, sizeof k), EndInSF();
   goto L2400;

L2600:
// write(chan.outch, " Limits:   %$"); //F
   BegExSF(chan.outch, "(\2 Limits:   \2,$)"), EndExSF();
// 						!TYPE 2, READ BOUNDS.
// read(chan.inpch, "%2I6", &j, &k); //F
   BegInSF(chan.inpch, "(2i6)"), DoFio(1, &j, sizeof j), DoFio(1, &k, sizeof k), EndInSF();
   if (k == 0) {
      k = j;
   }
   goto L2400;

L2500:
// write(chan.outch, " Entry:    %$"); //F
   BegExSF(chan.outch, "(\2 Entry:    \2,$)"), EndExSF();
// 						!TYPE 1, READ ENTRY NO.
// read(chan.inpch, "%I6", &j); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &j, sizeof j), EndInSF();
L2400:
   switch (i) {
      case 1:
         goto L10000;
      case 2:
         goto L11000;
      case 3:
         goto L12000;
      case 4:
         goto L13000;
      case 5:
         goto L14000;
      case 6:
         goto L15000;
      case 7:
         goto L16000;
      case 8:
         goto L17000;
      case 9:
         goto L18000;
      case 10:
         goto L19000;
      case 11:
         goto L20000;
      case 12:
         goto L21000;
      case 13:
         goto L22000;
      case 14:
         goto L23000;
      case 15:
         goto L24000;
      case 16:
         goto L25000;
      case 17:
         goto L26000;
      case 18:
         goto L27000;
      case 19:
         goto L28000;
      case 20:
         goto L29000;
      case 21:
         goto L30000;
      case 22:
         goto L31000;
      case 23:
         goto L32000;
      case 24:
         goto L33000;
      case 25:
         goto L34000;
      case 26:
         goto L35000;
      case 27:
         goto L36000;
      case 28:
         goto L37000;
      case 29:
         goto L38000;
      case 30:
         goto L39000;
      case 31:
         goto L40000;
      case 32:
         goto L41000;
      case 33:
         goto L42000;
      case 34:
         goto L43000;
      case 35:
         goto L44000;
      case 36:
         goto L45000;
      case 37:
         goto L46000;
      case 38:
         goto L47000;
   }
   goto L2200;
// 						!WHAT???
// GDT, PAGE 3

// DR-- DISPLAY ROOMS

L10000:
   if (!(j > 0 && j <= rooms.rlnt && (k > 0 && k <= rooms.rlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
// write(chan.outch, " RM#  DESC1  EXITS ACTION  VALUE  FLAGS"); //F
   BegExSF(chan.outch, "(\2 RM#  DESC1  EXITS ACTION  VALUE  FLAGS\2)"), EndExSF();
// 						!COL HDRS.
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, "%1X%I3%4(1X,I6)%1X%I6", i, (eqr(i, l), l = 1, 5)); //F
      BegExSF(chan.outch, "(1x,i3,4(1x,i6),1x,i6)"), DoFio(1, &i, sizeof i);
      for (l = 1; l <= 5; ++l) DoFio(1, &eqr[i - 1 + 200 * (l - 1)], sizeof eqr[0]);
      EndExSF();
// L10100:
   }
   goto L2000;

// DO-- DISPLAY OBJECTS

L11000:
   if (!(j > 0 && j <= objcts.olnt && (k > 0 && k <= objcts.olnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
// write(chan.outch, " OB# DESC1 DESC2 DESCO ACT FLAGS1 FLAGS2 FVL TVL SIZE CAPAC ROOM ADV CON  READ"); //F
   BegExSF(chan.outch, "(\2 OB# DESC1 DESC2 DESCO ACT FLAGS1 FLAGS2 FVL TVL  SIZE CAPAC ROOM ADV CON  READ\2)"), EndExSF();
// 						!COL HDRS
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, "%1X%I3%3I6%I4%2I7%2I4%2I6%1X%3I4%I6", i, (eqo(i, l), l = 1, 14)); //F
      BegExSF(chan.outch, "(1x,i3,3i6,i4,2i7,2i4,2i6,1x,3i4,i6)"), DoFio(1, &i, sizeof i);
      for (l = 1; l <= 14; ++l) DoFio(1, &eqo[i - 1 + 220 * (l - 1)], sizeof eqo[0]);
      EndExSF();
// L11100:
   }
   goto L2000;

// DA-- DISPLAY ADVENTURERS

L12000:
   if (!(j > 0 && j <= advs.alnt && (k > 0 && k <= advs.alnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
// write(chan.outch, " AD#   ROOM  SCORE  VEHIC OBJECT ACTION  STREN  FLAGS"); //F
   BegExSF(chan.outch, "(\2 AD#   ROOM  SCORE  VEHIC OBJECT ACTION  STREN  FLAGS\2)"), EndExSF();
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, "%1X%I3%6(1X,I6)%1X%I6", i, (eqa(i, l), l = 1, 7)); //F
      BegExSF(chan.outch, "(1x,i3,6(1x,i6),1x,i6)"), DoFio(1, &i, sizeof i);
      for (l = 1; l <= 7; ++l) DoFio(1, &eqa[i - 1 + ((l - 1) << 2)], sizeof eqa[0]);
      EndExSF();
// L12100:
   }
   goto L2000;

// DC-- DISPLAY CLOCK EVENTS

L13000:
   if (!(j > 0 && j <= cevent.clnt && (k > 0 && k <= cevent.clnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
// write(chan.outch, " CL#   TICK ACTION  FLAG"); //F
   BegExSF(chan.outch, "(\2 CL#   TICK ACTION  FLAG\2)"), EndExSF();
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, "%1X%I3%1X%I6%1X%I6%5X%L1", i, (eqc(i, l), l = 1, 2), cflag(i)); //F
      BegExSF(chan.outch, "(1x,i3,1x,i6,1x,i6,5x,l1)"), DoFio(1, &i, sizeof i);
      for (l = 1; l <= 2; ++l) DoFio(1, &eqc[i - 1 + 25 * (l - 1)], sizeof eqc[0]);
      DoFio(1, &cevent.cflag[i - 1], sizeof cevent.cflag[0]);
      EndExSF();
// L13100:
   }
   goto L2000;

// DX-- DISPLAY EXITS

L14000:
   if (!(j > 0 && j <= exits.xlnt && (k > 0 && k <= exits.xlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
// write(chan.outch, Format0); //F
   BegExSF(chan.outch, Format0), EndExSF();
// 						!COL HDRS.
   i__1 = k;
   for (i = j; i <= i__1; i += 10) {
// 						!TEN PER LINE.
// Computing MIN
      i__2 = i + 9;
      l = min(i__2, k);
// 						!COMPUTE END OF LINE.
//    write(chan.outch, "%1X%I3-%I3%3X%10I7", i, l, (travel(l1), l1 = i, l)); //F
      BegExSF(chan.outch, "(1x,i3,\2-\2,i3,3x,10i7)"), DoFio(1, &i, sizeof i), DoFio(1, &l, sizeof l);
      i__2 = l;
      for (l1 = i; l1 <= i__2; ++l1) DoFio(1, &exits.travel[l1 - 1], sizeof exits.travel[0]);
      EndExSF();
// L14100:
   }
   goto L2000;

// DH-- DISPLAY HACKS

L15000:
// write(chan.outch, " THFPOS=%I6, THFFLG=%L2,THFACT=%L2%/ SWDACT=%L2, SWDSTA=%I2", thfpos, thfflg, thfact, swdact, swdsta); //F
   BegExSF(chan.outch, "(\2 THFPOS=\2,i6,\2, THFFLG=\2,l2,\2,THFACT=\2,l2/\2 SWDACT=\2,l2,\2, SWDSTA=\2,i2)");
   DoFio(1, &hack.thfpos, sizeof hack.thfpos), DoFio(1, &hack.thfflg, sizeof hack.thfflg);
   DoFio(1, &hack.thfact, sizeof hack.thfact);
   DoFio(1, &hack.swdact, sizeof hack.swdact), DoFio(1, &hack.swdsta, sizeof hack.swdsta);
   EndExSF();
   goto L2000;

// DL-- DISPLAY LENGTHS

L16000:
// write(chan.outch, " R=%I6, X=%I6, O=%I6, C=%I6%/ V=%I6, A=%I6, M=%I6, R2=%I5%/ MBASE=%I6, STRBIT=%I6", rlnt, xlnt, olnt, clnt, vlnt, alnt, mlnt, r2lnt, mbase, strbit); //F
   BegExSF(chan.outch, "(\2 R=\2,i6,\2, X=\2,i6,\2, O=\2,i6,\2, C=\2,i6/\2 V=\2,i6,\2, A=\2,i6,\2, M=\2,i6,\2, R2=\2,i5/\2 MBASE=\2,i6,\2, STRBIT=\2,i6)");
   DoFio(1, &rooms.rlnt, sizeof rooms.rlnt), DoFio(1, &exits.xlnt, sizeof exits.xlnt);
   DoFio(1, &objcts.olnt, sizeof objcts.olnt), DoFio(1, &cevent.clnt, sizeof cevent.clnt);
   DoFio(1, &vill.vlnt, sizeof vill.vlnt), DoFio(1, &advs.alnt, sizeof advs.alnt);
   DoFio(1, &rmsg.mlnt, sizeof rmsg.mlnt), DoFio(1, &oroom2_.r2lnt, sizeof oroom2_.r2lnt);
   DoFio(1, &star.mbase, sizeof star.mbase), DoFio(1, &star.strbit, sizeof star.strbit);
   EndExSF();
   goto L2000;

// DV-- DISPLAY VILLAINS

L17000:
   if (!(j > 0 && j <= vill.vlnt && (k > 0 && k <= vill.vlnt) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
// write(chan.outch, " VL# OBJECT   PROB   OPPS   BEST  MELEE"); //F
   BegExSF(chan.outch, "(\2 VL# OBJECT   PROB   OPPS   BEST  MELEE\2)"), EndExSF();
// 						!COL HDRS
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, "%1X%I3%5(1X,I6)", i, (eqv(i, l), l = 1, 5)); //F
      BegExSF(chan.outch, "(1x,i3,5(1x,i6))"), DoFio(1, &i, sizeof i);
      for (l = 1; l <= 5; ++l) DoFio(1, &eqv[i - 1 + ((l - 1) << 2)], sizeof eqv[0]);
      EndExSF();
// L17100:
   }
   goto L2000;

// DF-- DISPLAY FLAGS

L18000:
   if (!(j > 0 && j <= fmax && (k > 0 && k <= fmax) && j <= k)) {
      goto L2200;
   }
// 						!ARGS VALID?
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, " Flag #%I2 = %L1", i, flags(i)); //F
      BegExSF(chan.outch, "(\2 Flag #\2,i2,\2 = \2,l1)");
      DoFio(1, &i, sizeof i), DoFio(1, &flags[i - 1], sizeof flags[0]);
      EndExSF();
// L18100:
   }
   goto L2000;

// DS-- DISPLAY STATE

L19000:
// write(chan.outch, " Parse vector=%3(1X,I6)%1X%L6%1X%I6", prsa, prso, prsi, prswon, prscon); //F
   BegExSF(chan.outch, "(\2 Parse vector=\2,3(1x,i6),1x,l6,1x,i6)");
   DoFio(1, &prsvec.prsa, sizeof prsvec.prsa), DoFio(1, &prsvec.prso, sizeof prsvec.prso);
   DoFio(1, &prsvec.prsi, sizeof prsvec.prsi);
   DoFio(1, &prsvec.prswon, sizeof prsvec.prswon), DoFio(1, &prsvec.prscon, sizeof prsvec.prscon);
   EndExSF();
// write(chan.outch, " Play vector= %2(1X,I6)%1X%L6", winner, here, telflg); //F
   BegExSF(chan.outch, "(\2 Play vector= \2,2(1x,i6),1x,l6)");
   DoFio(1, &play.winner, sizeof play.winner), DoFio(1, &play.here, sizeof play.here);
   DoFio(1, &play.telflg, sizeof play.telflg);
   EndExSF();
// write(chan.outch, " State vector=%9(1X,I6)%/%14X%2(1X,I6)", moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc); //F
   BegExSF(chan.outch, "(\2 State vector=\2,9(1x,i6)/14x,2(1x,i6))");
   DoFio(1, &state.moves, sizeof state.moves), DoFio(1, &state.deaths, sizeof state.deaths);
   DoFio(1, &state.rwscor, sizeof state.rwscor), DoFio(1, &state.mxscor, sizeof state.mxscor);
   DoFio(1, &state.mxload, sizeof state.mxload), DoFio(1, &state.ltshft, sizeof state.ltshft);
   DoFio(1, &state.bloc, sizeof state.bloc), DoFio(1, &state.mungrm, sizeof state.mungrm);
   DoFio(1, &state.hs, sizeof state.hs);
   DoFio(1, &state.egscor, sizeof state.egscor), DoFio(1, &state.egmxsc, sizeof state.egmxsc);
   EndExSF();
// write(chan.outch, " Scol vector= %1X%I6%2(1X,I6)", fromdr, scolrm, scolac); //F
   BegExSF(chan.outch, "(\2 Scol vector= \2,1x,i6,2(1x,i6))");
   DoFio(1, &screen.fromdr, sizeof screen.fromdr);
   DoFio(1, &screen.scolrm, sizeof screen.scolrm), DoFio(1, &screen.scolac, sizeof screen.scolac);
   EndExSF();
   goto L2000;

// GDT, PAGE 4

// AF-- ALTER FLAGS

L20000:
   if (!(j > 0 && j <= fmax)) {
      goto L2200;
   }
// 						!ENTRY NO VALID?
// write(chan.outch, Format1, flags(j)); //F
   BegExSF(chan.outch, Format1), DoFio(1, &flags[j - 1], sizeof flags[0]), EndExSF();
// 						!TYPE OLD, GET NEW.
// read(chan.inpch, "%L1", &flags(j)); //F
   BegInSF(chan.inpch, "(l1)"), DoFio(1, &flags[j - 1], sizeof flags[0]), EndInSF();
   goto L2000;

// 21000-- HELP

L21000:
// write(chan.outch, //F
//    " Valid commands are:%/" //F
//    " AA- Alter ADVS%/"		" AC- Alter CEVENT%/"		" AF- Alter FINDEX%/" //F
//    " AH- Alter HERE%/"		" AN- Alter switches%/"		" AO- Alter OBJCTS%/" //F
//    " AR- Alter ROOMS%/"		" AV- Alter VILLS%/"		" AX- Alter EXITS%/" //F
//    " AZ- Alter PUZZLE%/"		" DA- Display ADVS%/"		" DC- Display CEVENT%/" //F
//    " DF- Display FINDEX%/"		" DH- Display HACKS%/"		" DL- Display lengths%/" //F
//    " DM- Display RTEXT%/"		" DN- Display switches%/"	" DO- Display OBJCTS%/" //F
//    " DP- Display parser%/"		" DR- Display ROOMS%/"		" DS- Display state%/" //F
//    " DT- Display text%/"		" DV- Display VILLS%/"		" DX- Display EXITS%/" //F
//    " DZ- Display PUZZLE%/"		" D2- Display ROOM2%/"		" EX- Exit%/" //F
//    " HE- Type this message%/"	" NC- No cyclops%/"		" ND- No deaths%/" //F
//    " NR- No robber%/"		" NT- No troll%/"		" PD- Program detail%/" //F
//    " RC- Restore cyclops%/"		" RD- Restore deaths%/"		" RR- Restore robber%/" //F
//    " RT- Restore troll%/"		" TK- Take." //F
// ); //F
   BegExSF(chan.outch,
      "(\2"
      " Valid commands are:\2/\2"
      " AA- Alter ADVS\2/\2"		" AC- Alter CEVENT\2/\2"	" AF- Alter FINDEX\2/\2"
      " AH- Alter HERE\2/\2"		" AN- Alter switches\2/\2"	" AO- Alter OBJCTS\2/\2"
      " AR- Alter ROOMS\2/\2"		" AV- Alter VILLS\2/\2"		" AX- Alter EXITS\2/\2"
      " AZ- Alter PUZZLE\2/\2"		" DA- Display ADVS\2/\2"	" DC- Display CEVENT\2/\2"
      " DF- Display FINDEX\2/\2"	" DH- Display HACKS\2/\2"	" DL- Display lengths\2/\2"
      " DM- Display RTEXT\2/\2"		" DN- Display switches\2/\2"	" DO- Display OBJCTS\2/\2"
      " DP- Display parser\2/\2"	" DR- Display ROOMS\2/\2"	" DS- Display state\2/\2"
      " DT- Display text\2/\2"		" DV- Display VILLS\2/\2"	" DX- Display EXITS\2/\2"
      " DZ- Display PUZZLE\2/\2"	" D2- Display ROOM2\2/\2"	" EX- Exit\2/\2"
      " HE- Type this message\2/\2"	" NC- No cyclops\2/\2"		" ND- No deaths\2/\2"
      " NR- No robber\2/\2"		" NT- No troll\2/\2"		" PD- Program detail\2/\2"
      " RC- Restore cyclops\2/\2"	" RD- Restore deaths\2/\2"	" RR- Restore robber\2/\2"
      " RT- Restore troll\2/\2"		" TK- Take."
      "\2)"
   );
   EndExSF();
   goto L2000;

// NR-- NO ROBBER

L22000:
   hack.thfflg = false;
// 						!DISABLE ROBBER.
   hack.thfact = false;
   newsta(ThiefOX, 0, 0, 0, 0);
// 						!VANISH THIEF.
// write(chan.outch, " No robber."); //F
   BegExSF(chan.outch, "(\2 No robber.\2)"), EndExSF();
   goto L2000;

// NT-- NO TROLL

L23000:
   findex.trollf = true;
   newsta(TrollOX, 0, 0, 0, 0);
// write(chan.outch, " No troll."); //F
   BegExSF(chan.outch, "(\2 No troll.\2)"), EndExSF();
   goto L2000;

// NC-- NO CYCLOPS

L24000:
   findex.cyclof = true;
   newsta(CycloOX, 0, 0, 0, 0);
// write(chan.outch, " No cyclops."); //F
   BegExSF(chan.outch, "(\2 No cyclops.\2)"), EndExSF();
   goto L2000;

// ND-- IMMORTALITY MODE

L25000:
   debug.dbgflg = 1;
// write(chan.outch, " No deaths."); //F
   BegExSF(chan.outch, "(\2 No deaths.\2)"), EndExSF();
   goto L2000;

// RR-- RESTORE ROBBER

L26000:
   hack.thfact = true;
// write(chan.outch, " Restored robber."); //F
   BegExSF(chan.outch, "(\2 Restored robber.\2)"), EndExSF();
   goto L2000;

// RT-- RESTORE TROLL

L27000:
   findex.trollf = false;
   newsta(TrollOX, 0, MTrolRX, 0, 0);
// write(chan.outch, " Restored troll."); //F
   BegExSF(chan.outch, "(\2 Restored troll.\2)"), EndExSF();
   goto L2000;

// RC-- RESTORE CYCLOPS

L28000:
   findex.cyclof = false;
   findex.magicf = false;
   newsta(CycloOX, 0, MCyclRX, 0, 0);
// write(chan.outch, " Restored cyclops."); //F
   BegExSF(chan.outch, "(\2 Restored cyclops.\2)"), EndExSF();
   goto L2000;

// RD-- MORTAL MODE

L29000:
   debug.dbgflg = 0;
// write(chan.outch, " Restored deaths."); //F
   BegExSF(chan.outch, "(\2 Restored deaths.\2)"), EndExSF();
   goto L2000;

// GDT, PAGE 5

// TK-- TAKE

L30000:
   if (!(j > 0 && j <= objcts.olnt)) {
      goto L2200;
   }
// 						!VALID OBJECT?
   newsta(j, 0, 0, 0, play.winner);
// 						!YES, TAKE OBJECT.
// write(chan.outch, " Taken."); //F
   BegExSF(chan.outch, "(\2 Taken.\2)"), EndExSF();
// 						!TELL.
   goto L2000;

// EX-- GOODBYE

L31000:
   prsvec.prscon = 1;
   return;

// AR--	ALTER ROOM ENTRY

L32000:
   if (!(j > 0 && j <= rooms.rlnt && (k > 0 && k <= 5))) {
      goto L2200;
   }
// 						!INDICES VALID?
// write(chan.outch, Format2, eqr(j, k)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &eqr[j - 1 + 200 * (k - 1)], sizeof eqr[0]), EndExSF();
// 						!TYPE OLD, GET NEW.
// read(chan.inpch, "%I6", &eqr(j, k)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &eqr[j - 1 + 200 * (k - 1)], sizeof eqr[0]), EndInSF();
   goto L2000;

// AO-- ALTER OBJECT ENTRY

L33000:
   if (!(j > 0 && j <= objcts.olnt && (k > 0 && k <= 14))) {
      goto L2200;
   }
// 						!INDICES VALID?
// write(chan.outch, Format2, eqo(j, k)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &eqo[j - 1 + 220 * (k - 1)], sizeof eqo[0]), EndExSF();
// read(chan.inpch, "%I6", &eqo(j, k)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &eqo[j - 1 + 220 * (k - 1)], sizeof eqo[0]), EndInSF();
   goto L2000;

// AA-- ALTER ADVS ENTRY

L34000:
   if (!(j > 0 && j <= advs.alnt && (k > 0 && k <= 7))) {
      goto L2200;
   }
// 						!INDICES VALID?
// write(chan.outch, Format2, eqa(j, k)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &eqa[j - 1 + ((k - 1) << 2)], sizeof eqa[0]), EndExSF();
// read(chan.inpch, "%I6", &eqa(j, k)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &eqa[j - 1 + ((k - 1) << 2)], sizeof eqa[0]), EndInSF();
   goto L2000;

// AC-- ALTER CLOCK EVENTS

L35000:
   if (!(j > 0 && j <= cevent.clnt && (k > 0 && k <= 3))) {
      goto L2200;
   }
// 						!INDICES VALID?
   if (k == 3) {
      goto L35500;
   }
// 						!FLAGS ENTRY?
// write(chan.outch, Format2, eqc(j, k)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &eqc[j - 1 + 25 * (k - 1)], sizeof eqc[0]), EndExSF();
// read(chan.inpch, "%I6", &eqc(j, k)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &eqc[j - 1 + 25 * (k - 1)], sizeof eqc[0]), EndInSF();
   goto L2000;

L35500:
// write(chan.outch, Format1, cflag(j)); //F
   BegExSF(chan.outch, Format1), DoFio(1, &cevent.cflag[j - 1], sizeof cevent.cflag[0]), EndExSF();
// read(chan.inpch, "%L1", &cevent.cflag); //F
   BegInSF(chan.inpch, "(l1)"), DoFio(1, &cevent.cflag[j - 1], sizeof cevent.cflag[0]), EndInSF();
   goto L2000;
// GDT, PAGE 6

// AX-- ALTER EXITS

L36000:
   if (!(j > 0 && j <= exits.xlnt)) {
      goto L2200;
   }
// 						!ENTRY NO VALID?
// write(chan.outch, Format2, travel(j)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &exits.travel[j - 1], sizeof exits.travel[0]), EndExSF();
// read(chan.inpch, "%I6", &exits.travel(j)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &exits.travel[j - 1], sizeof exits.travel[0]), EndInSF();
   goto L2000;

// AV-- ALTER VILLAINS

L37000:
   if (!(j > 0 && j <= vill.vlnt && (k > 0 && k <= 5))) {
      goto L2200;
   }
// 						!INDICES VALID?
// write(chan.outch, Format2, eqv(j, k)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &eqv[j - 1 + ((k - 1) << 2)], sizeof eqv[0]), EndExSF();
// read(chan.inpch, "%I6", &eqv(j, k)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &eqv[j - 1 + ((k - 1) << 2)], sizeof eqv[0]), EndInSF();
   goto L2000;

// D2-- DISPLAY ROOM2 LIST

L38000:
   if (!(j > 0 && j <= oroom2_.r2lnt && (k > 0 && k <= oroom2_.r2lnt) && j <= k)) {
      goto L2200;
   }
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, " #%I2   Room=%I6   Obj=%I6", i, rroom2(i), oroom2(i)); //F
      BegExSF(chan.outch, "(\2 #\2,i2,\2   Room=\2,i6,\2   Obj=\2,i6)");
      DoFio(1, &i, sizeof i);
      DoFio(1, &oroom2_.rroom2[i - 1], sizeof oroom2_.rroom2[0]);
      DoFio(1, &oroom2_.oroom2[i - 1], sizeof oroom2_.oroom2[0]);
      EndExSF();
// L38100:
   }
   goto L2000;

// DN-- DISPLAY SWITCHES

L39000:
   if (!(j > 0 && j <= smax && (k > 0 && k <= smax) && j <= k)) {
      goto L2200;
   }
// 						!VALID?
   i__1 = k;
   for (i = j; i <= i__1; ++i) {
//    write(chan.outch, " Switch #%I2 = %I6", i, switch_(i)); //F
      BegExSF(chan.outch, "(\2 Switch #\2,i2,\2 = \2,i6)");
      DoFio(1, &i, sizeof i), DoFio(1, &switch_[i - 1], sizeof switch_[0]);
      EndExSF();
// L39100:
   }
   goto L2000;

// AN-- ALTER SWITCHES

L40000:
   if (!(j > 0 && j <= smax)) {
      goto L2200;
   }
// 						!VALID ENTRY?
// write(chan.outch, Format2, switch_(j)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &switch_[j - 1], sizeof switch_[0]), EndExSF();
// read(chan.inpch, "%I6", &switch_(j)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &switch_[j - 1], sizeof switch_[0]), EndInSF();
   goto L2000;

// DM-- DISPLAY MESSAGES

L41000:
   if (!(j > 0 && j <= rmsg.mlnt && (k > 0 && k <= rmsg.mlnt) && j <= k)) {
      goto L2200;
   }
// 						!VALID LIMITS?
// write(chan.outch, Format0); //F
   BegExSF(chan.outch, Format0), EndExSF();
   i__1 = k;
   for (i = j; i <= i__1; i += 10) {
// Computing MIN
      i__2 = i + 9;
      l = min(i__2, k);
//    write(chan.outch, "%1X%I3"-%I3%3X%10(1X,I6)", i, l, (rtext(l1), l1 = i, l)); //F
      BegExSF(chan.outch, "(1x,i3,\2-\2,i3,3x,10(1x,i6))"), DoFio(1, &i, sizeof i), DoFio(1, &l, sizeof l);
      i__2 = l;
      for (l1 = i; l1 <= i__2; ++l1) DoFio(1, &rmsg.rtext[l1 - 1], sizeof rmsg.rtext[0]);
      EndExSF();
// L41100:
   }
   goto L2000;

// DT-- DISPLAY TEXT

L42000:
   rspeak(j);
   goto L2000;

// AH--	ALTER HERE

L43000:
// write(chan.outch, Format2, here); //F
   BegExSF(chan.outch, Format2), DoFio(1, &play.here, sizeof play.here), EndExSF();
// read(chan.inpch, "%I6", &play.here); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &play.here, sizeof play.here), EndInSF();
   eqa[0] = play.here;
   goto L2000;

// DP--	DISPLAY PARSER STATE

L44000:
// write(chan.outch, " ORPHS= %I7%I7%4I7%/ PV=    %I7%4I7%/ SYN=   %6I7%/%15X%5I7", orp, lastit, pvec, syn); //F
   BegExSF(chan.outch, "(\2 ORPHS= \2,i7,i7,4i7/\2 PV=    \2,i7,4i7/\2 SYN=   \2,6i7/15x,5i7)");
   DoFio(5, orp, sizeof orp[0]), DoFio(1, &last.lastit, sizeof last.lastit);
   DoFio(5, pvec, sizeof pvec[0]), DoFio(11, syn, sizeof syn[0]);
   EndExSF();
   goto L2000;

// PD--	PROGRAM DETAIL DEBUG

L45000:
// write(chan.outch, Format2, prsflg); //F
   BegExSF(chan.outch, Format2), DoFio(1, &debug.prsflg, sizeof debug.prsflg), EndExSF();
// 						!TYPE OLD, GET NEW.
// read(chan.inpch, "%I6", &debug.prsflg); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &debug.prsflg, sizeof debug.prsflg), EndInSF();
   goto L2000;

// DZ--	DISPLAY PUZZLE ROOM

L46000:
   for (i = 1; i <= 64; i += 8) {
// 						!DISPLAY PUZZLE
//    write(chan.outch, "%2X%8I3", (cpvec(j), j = i, i + 7)); //F
      BegExSF(chan.outch, "(2x,8i3)");
      i__1 = i + 7;
      for (j = i; j <= i__1; ++j) DoFio(1, &puzzle.cpvec[j - 1], sizeof puzzle.cpvec[0]);
      EndExSF();
// L46100:
   }
   goto L2000;

// AZ--	ALTER PUZZLE ROOM

L47000:
   if (!(j > 0 && j <= 64)) {
      goto L2200;
   }
// 						!VALID ENTRY?
// write(chan.outch, Format2, cpvec(j)); //F
   BegExSF(chan.outch, Format2), DoFio(1, &puzzle.cpvec[j - 1], sizeof puzzle.cpvec[0]), EndExSF();
// 						!OUTPUT OLD,
// read(chan.inpch, "%I6", &puzzle.cpvec(j)); //F
   BegInSF(chan.inpch, "(i6)"), DoFio(1, &puzzle.cpvec[j - 1], sizeof puzzle.cpvec[0]), EndInSF();
   goto L2000;
#endif
}
