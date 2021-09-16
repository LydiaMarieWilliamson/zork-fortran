#include "F2C.h"

// Common Block Declarations

extern struct {
   int winner, here;
   Bool telflg;
} play_;

#define play_1 play_

extern struct {
   int mlnt, rtext[1820];
} rmsg_;

#define rmsg_1 rmsg_

extern struct {
   int inlnt;
   char inbuf[78];
} input_;

#define input_1 input_

extern struct {
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

extern struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;

#define prsvec_1 prsvec_

extern struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

extern struct {
   int lastit;
} last_;

#define last_1 last_

extern struct {
   int act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

extern struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

extern struct {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

extern struct {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

extern struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

extern struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

extern struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

extern struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_

extern struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

#define rflag_1 rflag_

extern struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

extern struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

extern struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

extern struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

extern struct {
   int astag;
} aflags_;

#define aflags_1 aflags_

extern struct {
   int player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

extern struct {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;

#define screen_1 screen_

extern struct {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;

#define xsrch_1 xsrch_

extern struct {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

// Table of constant values

static int c__0 = 0;
static int c__1 = 1;
static int c__432 = 432;
static int c__10 = 10;
static int c__9 = 9;
static int c__8 = 8;
static int c_n10 = -10;
static int c__625 = 625;
static int c__7 = 7;
static Bool c_false = false;
static int c__40 = 40;
static int c__100 = 100;
static int c__2 = 2;
static int c__430 = 430;
static int c__80 = 80;
static int c__431 = 431;

// RESIDENT SUBROUTINES FOR DUNGEON

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// RSPEAK-- OUTPUT RANDOM MESSAGE ROUTINE

// CALLED BY--

// 	CALL RSPEAK(MSGNUM)

void rspeak_(int n) {
   extern void rspsb2_(int, int, int);

   rspsb2_(n, c__0, c__0);
}

// RSPSUB-- OUTPUT RANDOM MESSAGE WITH SUBSTITUTABLE ARGUMENT

// CALLED BY--

// 	CALL RSPSUB(MSGNUM,SUBNUM)

void rspsub_(int n, int s1) {
   extern void rspsb2_(int, int, int);

   rspsb2_(n, s1, c__0);
}

// RSPSB2-- OUTPUT RANDOM MESSAGE WITH UP TO TWO SUBSTITUTABLE ARGUMENTS

// CALLED BY--

// 	CALL RSPSB2(MSGNUM,SUBNUM1,SUBNUM2)

void rspsb2_(int n, int s1, int s2) {
// Format strings
   static char fmt_650[] = "(1x,74a1)";

// System generated locals
   int i__1;

// Local variables
   static int i__, j, x, y, z__;
   static char b1[74], b2[74], b3[74];
   static int k1, k2, x1;
   static short jrec, oldrec, newrec;

// Fortran I/O blocks
   static cilist io___4 = { 0, 0, 0, 0, 0 };
   static cilist io___9 = { 0, 0, 0, fmt_650, 0 };
   static cilist io___11 = { 0, 0, 0, 0, 0 };
   static cilist io___16 = { 0, 0, 0, 0, 0 };

// DECLARATIONS

// GAME STATE

// MESSAGE INDEX

// CONVERT ALL ARGUMENTS FROM DICTIONARY NUMBERS (IF POSITIVE)
// TO ABSOLUTE RECORD NUMBERS.

// I/O VARIABLES

   x = n;
// 						!SET UP WORK VARIABLES.
   y = s1;
   z__ = s2;
   if (x > 0) {
      x = rmsg_1.rtext[x - 1];
   }
// 						!IF >0, LOOK UP IN RTEXT.
   if (y > 0) {
      y = rmsg_1.rtext[y - 1];
   }
   if (z__ > 0) {
      z__ = rmsg_1.rtext[z__ - 1];
   }
   x = abs(x);
// 						!TAKE ABS VALUE.
   y = abs(y);
   z__ = abs(z__);
   if (x == 0) {
      return;
   }
// 						!ANYTHING TO DO?
   play_1.telflg = true;
// 						!SAID SOMETHING.

   io___4.ciunit = chan_1.dbch;
   io___4.cirec = x;
   s_rdue(&io___4);
   do_uio(&c__1, (char *)&oldrec, (ftnlen) sizeof(short));
   do_uio(&c__1, b1, (ftnlen) 74);
   e_rdue();

L100:
   for (i__ = 1; i__ <= 74; ++i__) {
      x1 = (x & 31) + i__;
      *(unsigned char *)&b1[i__ - 1] = (char)(*(unsigned char *)&b1[i__ - 1] ^ x1);
// L150:
   }

L200:
   if (y == 0) {
      goto L400;
   }
// 						!ANY SUBSTITUTABLE?
   for (i__ = 1; i__ <= 74; ++i__) {
// 						!YES, LOOK FOR #.
      if (*(unsigned char *)&b1[i__ - 1] == '#') {
         goto L1000;
      }
// L300:
   }

L400:
   for (i__ = 74; i__ >= 1; --i__) {
// 						!BACKSCAN FOR BLANKS.
      if (*(unsigned char *)&b1[i__ - 1] != ' ') {
         goto L600;
      }
// L500:
   }

L600:
   io___9.ciunit = chan_1.outch;
   s_wsfe(&io___9);
   i__1 = i__;
   for (j = 1; j <= i__1; ++j) {
      do_fio(&c__1, b1 + (j - 1), j - (j - 1));
   }
   e_wsfe();
   ++x;
// 						!ON TO NEXT RECORD.
   io___11.ciunit = chan_1.dbch;
   io___11.cirec = x;
   s_rdue(&io___11);
   do_uio(&c__1, (char *)&newrec, (ftnlen) sizeof(short));
   do_uio(&c__1, b1, (ftnlen) 74);
   e_rdue();
   if (oldrec == newrec) {
      goto L100;
   }
// 						!CONTINUATION?
   return;
// 						!NO, EXIT.

// SUBSTITUTION WITH SUBSTITUTABLE AVAILABLE.
// I IS INDEX OF # IN B1.
// Y IS NUMBER OF RECORD TO SUBSTITUTE.

// PROCEDURE:
//   1) COPY REST OF B1 TO B2
//   2) READ SUBSTITUTABLE OVER B1
//   3) RESTORE TAIL OF ORIGINAL B1

// THE IMPLICIT ASSUMPTION HERE IS THAT THE SUBSTITUTABLE STRING
// IS VERY SHORT (i.e. MUCH LESS THAN ONE RECORD).

L1000:
   k2 = 1;
// 						!TO
   for (k1 = i__ + 1; k1 <= 74; ++k1) {
// 						!COPY REST OF B1.
      *(unsigned char *)&b2[k2 - 1] = *(unsigned char *)&b1[k1 - 1];
      ++k2;
// L1100:
   }

//   READ SUBSTITUTE STRING INTO B3, AND DECRYPT IT:

   io___16.ciunit = chan_1.dbch;
   io___16.cirec = y;
   s_rdue(&io___16);
   do_uio(&c__1, (char *)&jrec, (ftnlen) sizeof(short));
   do_uio(&c__1, b3, (ftnlen) 74);
   e_rdue();
   for (k1 = 1; k1 <= 74; ++k1) {
      x1 = (y & 31) + k1;
      *(unsigned char *)&b3[k1 - 1] = (char)(*(unsigned char *)&b3[k1 - 1] ^ x1);
// L1150:
   }

//   FILL REMAINDER OF B1 WITH CHARACTERS FROM B3:

   k2 = 1;
   for (k1 = i__; k1 <= 74; ++k1) {
      *(unsigned char *)&b1[k1 - 1] = *(unsigned char *)&b3[k2 - 1];
      ++k2;
// L1180:
   }

//   FIND END OF SUBSTITUTE STRING IN B1:

   for (j = 74; j >= 1; --j) {
// 						!ELIM TRAILING BLANKS.
      if (*(unsigned char *)&b1[j - 1] != ' ') {
         goto L1300;
      }
// L1200:
   }

//   PUT TAIL END OF B1 (NOW IN B2) BACK INTO B1 AFTER SUBSTITUTE STRING:

L1300:
   k1 = 1;
// 						!FROM
   for (k2 = j + 1; k2 <= 74; ++k2) {
// 						!COPY REST OF B1 BACK.
      *(unsigned char *)&b1[k2 - 1] = *(unsigned char *)&b2[k1 - 1];
      ++k1;
// L1400:
   }

   y = z__;
// 						!SET UP FOR NEXT
   z__ = 0;
// 						!SUBSTITUTION AND
   goto L200;
// 						!RECHECK LINE.

}

// OBJACT-- APPLY OBJECTS FROM PARSE VECTOR

// DECLARATIONS

Bool objact_(/*int x*/) {
// System generated locals
   Bool ret_val;

// Local variables
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
   extern Bool oappli_(int, int);
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// OBJECTS

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prsi == 0) {
      goto L100;
   }
// 						!IND OBJECT?
   if (oappli_(objcts_1.oactio[prsvec_1.prsi - 1], c__0)) {
      return ret_val;
   }
// 						!YES, LET IT HANDLE.

L100:
   if (prsvec_1.prso == 0) {
      goto L200;
   }
// 						!DIR OBJECT?
   if (oappli_(objcts_1.oactio[prsvec_1.prso - 1], c__0)) {
      return ret_val;
   }
// 						!YES, LET IT HANDLE.

L200:
   ret_val = false;
// 						!LOSES.
   return ret_val;
}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo

// BUG-- REPORT FATAL SYSTEM ERROR

// CALLED BY--

// 	CALL BUG(NO,PAR)

void bug_(int a, int b) {
// Format strings
   static char fmt_100[] = "(\002 PROGRAM ERROR \002,i2,\002, PARAMETER=" "\002,i6)";

// Local variables
   extern void exit_(void);

// Fortran I/O blocks
   static cilist io___25 = { 0, 6, 0, fmt_100, 0 };

   s_wsfe(&io___25);
   do_fio(&c__1, (char *)&(a),(ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&(b),(ftnlen) sizeof(int));
   e_wsfe();
   if (debug_1.dbgflg != 0) {
      return;
   }
   exit_();
}

// NEWSTA-- SET NEW STATUS FOR OBJECT

// CALLED BY--

// 	CALL NEWSTA(OBJECT,STRING,NEWROOM,NEWCON,NEWADV)

void newsta_(int o, int r__, int rm, int cn, int ad) {
// Local variables
#define eqo ((int *)&objcts_1 + 1)
   extern void rspeak_(int);

// OBJECTS

   rspeak_(r__);
   objcts_1.oroom[o - 1] = rm;
   objcts_1.ocan[o - 1] = cn;
   objcts_1.oadv[o - 1] = ad;
}

#undef eqo

// QHERE-- TEST FOR OBJECT IN ROOM

// DECLARATIONS

Bool qhere_(int obj, int rm) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)

// OBJECTS

   ret_val = true;
   if (objcts_1.oroom[obj - 1] == rm) {
      return ret_val;
   }
// 						!IN ROOM?
   i__1 = oroom2_1.r2lnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!NO, SCH ROOM2.
      if (oroom2_1.oroom2[i__ - 1] == obj && oroom2_1.rroom2[i__ - 1] == rm) {
         return ret_val;
      }
// L100:
   }
   ret_val = false;
// 						!NOT PRESENT.
   return ret_val;
}

#undef eqo

// QEMPTY-- TEST FOR OBJECT EMPTY

// DECLARATIONS

Bool qempty_(int obj) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int i__;
#define eqo ((int *)&objcts_1 + 1)

// OBJECTS

   ret_val = false;
// 						!ASSUME LOSE.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (objcts_1.ocan[i__ - 1] == obj) {
         return ret_val;
      }
// 						!INSIDE TARGET?
// L100:
   }
   ret_val = true;
   return ret_val;
}

#undef eqo

// JIGSUP- YOU ARE DEAD

// DECLARATIONS

void jigsup_(int desc) {
// Initialized data

   static int rlist[9] = { 8, 6, 36, 35, 34, 4, 34, 6, 5 };

// System generated locals
   int i__1;
   cllist cl__1;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   extern void rspeak_(int);
   extern void rspsub_(int, int);
   extern void newsta_(int, int, int, int, int);
   extern void scrupd_(int);
   static int nonofl;
   extern void score_(Bool);
   static Bool f;
   static int i__, j;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern void exit_(void);
   extern Bool qhere_(int, int);
#define rrand ((int *)&rooms_1 + 602)
   extern Bool yesno_(int, int, int);
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
   extern Bool moveto_(int, int);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// I/O VARIABLES

// ROOMS

// OBJECTS

// ADVENTURERS

// FUNCTIONS AND DATA

// FLAGS

// JIGSUP, PAGE 2

   rspeak_(desc);
// 						!DESCRIBE SAD STATE.
   prsvec_1.prscon = 1;
// 						!STOP PARSER.
   if (debug_1.dbgflg != 0) {
      return;
   }
// 						!IF DBG, EXIT.
   advs_1.avehic[play_1.winner - 1] = 0;
// 						!GET RID OF VEHICLE.
   if (play_1.winner == aindex_1.player) {
      goto L100;
   }
// 						!HIMSELF?
   rspsub_(c__432, objcts_1.odesc2[advs_1.aobj[play_1.winner - 1] - 1]);
// 						!NO, SAY WHO DIED.
   newsta_(advs_1.aobj[play_1.winner - 1], c__0, c__0, c__0, c__0);
// 						!SEND TO HYPER SPACE.
   return;

L100:
   if (findex_1.endgmf) {
      goto L900;
   }
// 						!NO RECOVERY IN END GAME.
   if (state_1.deaths >= 2) {
      goto L1000;
   }
// 						!DEAD TWICE? KICK HIM OFF.
   if (!yesno_(c__10, c__9, c__8)) {
      goto L1100;
   }
// 						!CONTINUE?

   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!TURN OFF FIGHTING.
      if (qhere_(j, play_1.here)) {
         objcts_1.oflag2[j - 1] &= ~oflags_1.fitebt;
      }
// L50:
   }

   ++state_1.deaths;
   scrupd_(c_n10);
// 						!CHARGE TEN POINTS.
   f = moveto_(rindex_1.fore1, play_1.winner);
// 						!REPOSITION HIM.
   findex_1.egyptf = true;
// 						!RESTORE COFFIN.
   if (objcts_1.oadv[oindex_1.coffi - 1] == play_1.winner) {
      newsta_(oindex_1.coffi, c__0, rindex_1.egypt, c__0, c__0);
   }
   objcts_1.oflag2[oindex_1.door - 1] &= ~oflags_1.tchbt;
   objcts_1.oflag1[oindex_1.robot - 1] = (objcts_1.oflag1[oindex_1.robot - 1] | oflags_1.visibt) & ~oflags_1.ndscbt;
   if (objcts_1.oroom[oindex_1.lamp - 1] != 0 || objcts_1.oadv[oindex_1.lamp - 1] == play_1.winner) {
      newsta_(oindex_1.lamp, c__0, rindex_1.lroom, c__0, c__0);
   }

// NOW REDISTRIBUTE HIS VALUABLES AND OTHER BELONGINGS.

// THE LAMP HAS BEEN PLACED IN THE LIVING ROOM.
// THE FIRST 8 NON-VALUABLES ARE PLACED IN LOCATIONS AROUND THE HOUSE.
// HIS VALUABLES ARE PLACED AT THE END OF THE MAZE.
// REMAINING NON-VALUABLES ARE PLACED AT THE END OF THE MAZE.

   i__ = 1;
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!LOOP THRU OBJECTS.
      if (objcts_1.oadv[j - 1] != play_1.winner || objcts_1.otval[j - 1] != 0) {
         goto L200;
      }
      ++i__;
      if (i__ > 9) {
         goto L400;
      }
// 						!MOVE TO RANDOM LOCATIONS.
      newsta_(j, c__0, rlist[i__ - 1], c__0, c__0);
   L200:
      ;
   }

L400:
   i__ = rooms_1.rlnt + 1;
// 						!NOW MOVE VALUABLES.
   nonofl = rflag_1.rair + rflag_1.rwater + rflag_1.rsacrd + rflag_1.rend;
// 						!DONT MOVE HERE.
   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
      if (objcts_1.oadv[j - 1] != play_1.winner || objcts_1.otval[j - 1] == 0) {
         goto L300;
      }
   L250:
      --i__;
// 						!FIND NEXT ROOM.
      if ((rooms_1.rflag[i__ - 1] & nonofl) != 0) {
         goto L250;
      }
      newsta_(j, c__0, i__, c__0, c__0);
// 						!YES, MOVE.
   L300:
      ;
   }

   i__1 = objcts_1.olnt;
   for (j = 1; j <= i__1; ++j) {
// 						!NOW GET RID OF REMAINDER.
      if (objcts_1.oadv[j - 1] != play_1.winner) {
         goto L500;
      }
   L450:
      --i__;
// 						!FIND NEXT ROOM.
      if ((rooms_1.rflag[i__ - 1] & nonofl) != 0) {
         goto L450;
      }
      newsta_(j, c__0, i__, c__0, c__0);
   L500:
      ;
   }
   return;

// CAN'T OR WON'T CONTINUE, CLEAN UP AND EXIT.

L900:
   rspeak_(c__625);
// 						!IN ENDGAME, LOSE.
   goto L1100;

L1000:
   rspeak_(c__7);
// 						!INVOLUNTARY EXIT.
L1100:
   score_(c_false);
// 						!TELL SCORE.
   cl__1.cerr = 0;
   cl__1.cunit = chan_1.dbch;
   cl__1.csta = 0;
   f_clos(&cl__1);
   exit_();

}

#undef prpvec
#undef objvec
#undef rrand
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqa
#undef switch__
#undef flags

// OACTOR-	GET ACTOR ASSOCIATED WITH OBJECT

// DECLARATIONS

int oactor_(int obj) {
// System generated locals
   int ret_val, i__1;

// Local variables
   static int i__;
#define eqa ((int *)&advs_1 + 1)
   extern void bug_(int, int);

// ADVENTURERS

   i__1 = advs_1.alnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP THRU ACTORS.
      ret_val = i__;
// 						!ASSUME FOUND.
      if (advs_1.aobj[i__ - 1] == obj) {
         return ret_val;
      }
// 						!FOUND IT?
// L100:
   }
   bug_(c__40, obj);
// 						!NO, DIE.
   return ret_val;
}

#undef eqa

// PROB-		COMPUTE PROBABILITY

// DECLARATIONS

Bool prob_(int g, int b) {
// System generated locals
   Bool ret_val;

// Local variables
   static int i__;
   extern int rnd_(int);
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// FLAGS

   i__ = g;
// 						!ASSUME GOOD LUCK.
   if (findex_1.badlkf) {
      i__ = b;
   }
// 						!IF BAD, TOO BAD.
   ret_val = rnd_(c__100) < i__;
// 						!COMPUTE.
   return ret_val;
}

#undef switch__
#undef flags

// RMDESC-- PRINT ROOM DESCRIPTION

// RMDESC PRINTS A DESCRIPTION OF THE CURRENT ROOM.
// IT IS ALSO THE PROCESSOR FOR VERBS 'LOOK' AND 'EXAMINE'.

Bool rmdesc_(int full) {
// System generated locals
   Bool ret_val, L__1;

// Local variables
   static int i__, ra;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqr ((int *)&rooms_1 + 2)
   extern Bool lit_(int);
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool prob_(int, int);
#define flags ((Bool *)&findex_1)
#define rrand ((int *)&rooms_1 + 602)
#define objvec ((int *)&pv_1 + 1)
   extern Bool rappli_(int);
#define prpvec ((int *)&pv_1 + 3)
#define switch__ ((int *)&findex_1 + 46)
   extern void rspeak_(int);
   extern void rspsub_(int, int);
   extern void princr_(Bool, int);

// FULL=	0/1/2/3=	SHORT/OBJ/ROOM/FULL

// DECLARATIONS

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// SCREEN OF LIGHT

// ROOMS

// OBJECTS

// ADVENTURERS

// VERBS

// RMDESC, PAGE 2

// FLAGS

   ret_val = true;
// 						!ASSUME WINS.
   if (prsvec_1.prso < xsrch_1.xmin) {
      goto L50;
   }
// 						!IF DIRECTION,
   screen_1.fromdr = prsvec_1.prso;
// 						!SAVE AND
   prsvec_1.prso = 0;
// 						!CLEAR.
L50:
   if (play_1.here == advs_1.aroom[aindex_1.player - 1]) {
      goto L100;
   }
// 						!PLAYER JUST MOVE?
   rspeak_(c__2);
// 						!NO, JUST SAY DONE.
   prsvec_1.prsa = vindex_1.walkiw;
// 						!SET UP WALK IN ACTION.
   return ret_val;

L100:
   if (lit_(play_1.here)) {
      goto L300;
   }
// 						!LIT?
   rspeak_(c__430);
// 						!WARN OF GRUE.
   ret_val = false;
   return ret_val;

L300:
   ra = rooms_1.ractio[play_1.here - 1];
// 						!GET ROOM ACTION.
   if (full == 1) {
      goto L600;
   }
// 						!OBJ ONLY?
   i__ = rooms_1.rdesc2 - play_1.here;
// 						!ASSUME SHORT DESC.
   if (full == 0 && (findex_1.superf || (rooms_1.rflag[play_1.here - 1] & rflag_1.rseen) != 0 && (findex_1.brieff || prob_(c__80, c__80)))) {
      goto L400;
   }
   i__ = rooms_1.rdesc1[play_1.here - 1];
// 						!USE LONG.
   if (i__ != 0 || ra == 0) {
      goto L400;
   }
// 						!IF GOT DESC, SKIP.
   prsvec_1.prsa = vindex_1.lookw;
// 						!PRETEND LOOK AROUND.
   if (!rappli_(ra)) {
      goto L100;
   }
// 						!ROOM HANDLES, NEW DESC?
   prsvec_1.prsa = vindex_1.foow;
// 						!NOP PARSER.
   goto L500;

L400:
   rspeak_(i__);
// 						!OUTPUT DESCRIPTION.
L500:
   if (advs_1.avehic[play_1.winner - 1] != 0) {
      rspsub_(c__431, objcts_1.odesc2[advs_1.avehic[play_1.winner - 1] - 1]);
   }

L600:
   if (full != 2) {
      L__1 = full != 0;
      princr_(L__1, play_1.here);
   }
   rooms_1.rflag[play_1.here - 1] |= rflag_1.rseen;
   if (full != 0 || ra == 0) {
      return ret_val;
   }
// 						!ANYTHING MORE?
   prsvec_1.prsa = vindex_1.walkiw;
// 						!GIVE HIM A SURPISE.
   if (!rappli_(ra)) {
      goto L100;
   }
// 						!ROOM HANDLES, NEW DESC?
   prsvec_1.prsa = vindex_1.foow;
   return ret_val;

}

#undef switch__
#undef prpvec
#undef objvec
#undef rrand
#undef flags
#undef pvec
#undef syn
#undef orp
#undef eqr
#undef eqo
#undef eqa

// RAPPLI-	ROUTING ROUTINE FOR ROOM APPLICABLES

// DECLARATIONS

Bool rappli_(int ri) {
// Initialized data

   static int newrms = 38;

// System generated locals
   Bool ret_val;

// Local variables
   extern Bool rappl1_(int);
   extern Bool rappl2_(int);

   ret_val = true;
// 						!ASSUME WINS.
   if (ri == 0) {
      return ret_val;
   }
// 						!IF ZERO, WIN.
   if (ri < newrms) {
      ret_val = rappl1_(ri);
   }
// 						!IF OLD, PROCESSOR 1.
   if (ri >= newrms) {
      ret_val = rappl2_(ri);
   }
// 						!IF NEW, PROCESSOR 2.
   return ret_val;
}
