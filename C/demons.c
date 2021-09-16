#include "F2C.h"

// Common Block Declarations

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
   int winner, here;
   Bool telflg;
} play_;

#define play_1 play_

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
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

extern struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

extern struct {
   int thfpos;
   Bool thfflg, thfact, swdact;
   int swdsta;
} hack_;

#define hack_1 hack_

extern struct {
   int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_

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
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

extern struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_

extern struct {
   int mbase, strbit;
} star_;

#define star_1 star_

extern struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;

#define cevent_1 cevent_

extern struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

extern struct {
   int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_

extern struct {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;

#define xsrch_1 xsrch_

extern struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

// Table of constant values

static int c__0 = 0;
static Bool c_false = false;
static int c__3 = 3;
static int c__1 = 1;
static int c__591 = 591;
static Bool c_true = true;
static int c__592 = 592;
static int c__593 = 593;
static int c__594 = 594;
static int c__595 = 595;
static int c__10 = 10;
static int c__25 = 25;
static int c__605 = 605;
static int c__572 = 572;
static int c__596 = 596;

// FIGHTD- INTERMOVE FIGHT DEMON

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

void fightd_(void) {
// Initialized data

   static int rout = 1;

// System generated locals
   int i__1, i__2;

// Local variables
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)
   static Bool f;
   static int i__, j, ra;
#define eqa ((int *)&advs_1 + 1)
   static int obj;
   extern int rnd_(int);
#define eqo ((int *)&objcts_1 + 1)
   static int res;
#define eqv ((int *)&vill_1 + 1)
#define orp ((int *)&orphs_1)
   static int out;
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool prob_(int, int);
   extern int blow_(int, int, int, Bool, int);
#define objvec ((int *)&pv_1 + 1)
   extern Bool oappli_(int, int);
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// OBJECTS

// VILLAINS AND DEMONS

// ADVENTURERS

// VERBS

// FLAGS

// FUNCTIONS AND DATA

// FIGHTD, PAGE 2

   i__1 = vill_1.vlnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP THRU VILLAINS.
      vill_1.vopps[i__ - 1] = 0;
// 						!CLEAR OPPONENT SLOT.
      obj = vill_1.villns[i__ - 1];
// 						!GET OBJECT NO.
      ra = objcts_1.oactio[obj - 1];
// 						!GET HIS ACTION.
      if (play_1.here != objcts_1.oroom[obj - 1]) {
         goto L2200;
      }
// 						!ADVENTURER STILL HERE?
      if (obj == oindex_1.thief && findex_1.thfenf) {
         goto L2400;
      }
// 						!THIEF ENGROSSED?
      if (objcts_1.ocapac[obj - 1] >= 0) {
         goto L2050;
      }
// 						!YES, VILL AWAKE?
      if (vill_1.vprob[i__ - 1] == 0 || !prob_(vill_1.vprob[i__ - 1], vill_1.vprob[i__ - 1])) {
         goto L2025;
      }
      objcts_1.ocapac[obj - 1] = (i__2 = objcts_1.ocapac[obj - 1], abs(i__2));
      vill_1.vprob[i__ - 1] = 0;
      if (ra == 0) {
         goto L2400;
      }
// 						!ANYTHING TO DO?
      prsvec_1.prsa = vindex_1.inxw;
// 						!YES, WAKE HIM UP.
      f = oappli_(ra, c__0);
      goto L2400;
// 						!NOTHING ELSE HAPPENS.

   L2025:
      vill_1.vprob[i__ - 1] += 10;
// 						!INCREASE WAKEUP PROB.
      goto L2400;
// 						!NOTHING ELSE.

   L2050:
      if ((objcts_1.oflag2[obj - 1] & oflags_1.fitebt) == 0) {
         goto L2100;
      }
      vill_1.vopps[i__ - 1] = obj;
// 						!FIGHTING, SET UP OPP.
      goto L2400;

   L2100:
      if (ra == 0) {
         goto L2400;
      }
// 						!NOT FIGHTING,
      prsvec_1.prsa = vindex_1.frstqw;
// 						!SET UP PROBABILITY
      if (!oappli_(ra, c__0)) {
         goto L2400;
      }
// 						!OF FIGHTING.
      objcts_1.oflag2[obj - 1] |= oflags_1.fitebt;
      vill_1.vopps[i__ - 1] = obj;
// 						!SET UP OPP.
      goto L2400;

   L2200:
      if ((objcts_1.oflag2[obj - 1] & oflags_1.fitebt) == 0 || ra == 0) {
         goto L2300;
      }
      prsvec_1.prsa = vindex_1.fightw;
// 						!HAVE A FIGHT.
      f = oappli_(ra, c__0);
   L2300:
      if (obj == oindex_1.thief) {
         findex_1.thfenf = false;
      }
// 						!TURN OFF ENGROSSED.
      advs_1.aflag[aindex_1.player - 1] &= ~aflags_1.astag;
      objcts_1.oflag2[obj - 1] &= ~(oflags_1.stagbt + oflags_1.fitebt);
      if (objcts_1.ocapac[obj - 1] >= 0 || ra == 0) {
         goto L2400;
      }
      prsvec_1.prsa = vindex_1.inxw;
// 						!WAKE HIM UP.
      f = oappli_(ra, c__0);
      objcts_1.ocapac[obj - 1] = (i__2 = objcts_1.ocapac[obj - 1], abs(i__2));
   L2400:
      ;
   }
// FIGHTD, PAGE 3

// NOW DO ACTUAL COUNTERBLOWS.

   out = 0;
// 						!ASSUME HERO OK.
L2600:
   i__1 = vill_1.vlnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!LOOP THRU OPPS.
      j = vill_1.vopps[i__ - 1];
      if (j == 0) {
         goto L2700;
      }
// 						!SLOT EMPTY?
      prsvec_1.prscon = 1;
// 						!STOP CMD STREAM.
      ra = objcts_1.oactio[j - 1];
      if (ra == 0) {
         goto L2650;
      }
// 						!VILLAIN ACTION?
      prsvec_1.prsa = vindex_1.fightw;
// 						!SEE IF
      if (oappli_(ra, c__0)) {
         goto L2700;
      }
// 						!SPECIAL ACTION.
   L2650:
      res = blow_(aindex_1.player, j, vill_1.vmelee[i__ - 1], c_false, out);
// 						!STRIKE BLOW.
      if (res < 0) {
         return;
      }
// 						!IF HERO DEAD, EXIT.
      if (res == rout) {
         out = rnd_(c__3) + 2;
      }
// 						!IF HERO OUT, SET FLG.
   L2700:
      ;
   }
   --out;
// 						!DECREMENT OUT COUNT.
   if (out > 0) {
      goto L2600;
   }
// 						!IF STILL OUT, GO AGAIN.
}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqv
#undef eqo
#undef eqa
#undef switch__
#undef flags

// BLOW- STRIKE BLOW

// DECLARATIONS

int blow_(int h__, int v, int rmk, Bool hflg, int out) {
// Initialized data

   static int rmiss = 0;
   static int rout = 1;
   static int rkill = 2;
   static int rstag = 5;
   static int rlose = 6;
   static int rhes = 7;
   static int rsit = 8;
   static int def1r[3] = { 1, 2, 3 };
   static int def2r[4] = { 13, 23, 24, 25 };
   static int def3r[5] = { 35, 36, 46, 47, 57 };
   static int rvectr[66] = {
      0, 0, 0, 0, 5, 5, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 5, 5, 3, 3, 1,
      0, 0, 0, 5, 5, 3, 3, 3, 1, 2, 2, 2, 0, 0, 0, 0, 0, 5, 5, 3, 3, 4, 4, 0, 0, 0, 5, 5, 3, 3, 3, 4, 4,
      4, 0, 5, 5, 3, 3, 3, 3, 4, 4, 4
   };
   static int rstate[45] = {
      5000, 3005, 3008, 4011, 3015, 3018, 1021, 0, 0, 5022,
      3027, 3030, 4033, 3037, 3040, 1043, 0, 0, 4044, 2048, 4050, 4054, 5058, 4063,
      4067, 3071, 1074, 4075, 1079, 4080, 4084, 4088, 4092, 4096, 4100, 1104, 4105,
      2109, 4111, 4115, 4119, 4123, 4127, 3131, 3134
   };

// Format strings
   static char fmt_10[] = "(\002 BLOW 10-- \002,3i7,l7,i7)";
   static char fmt_2050[] = "(\002 BLOW 2050-- \002,5i7)";
   static char fmt_2650[] = "(\002 BLOW 2650-- \002,5i7)";

// System generated locals
   int ret_val, i__1, i__2;

// Local variables
   static Bool f;
   static int i__, j, oa, ra, od, mi, dv, def;
#define eqa ((int *)&advs_1 + 1)
#define eqc ((int *)&cevent_1 + 1)
   static int tbl;
   extern int rnd_(int);
#define eqo ((int *)&objcts_1 + 1)
   static int att, res;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
   extern Bool prob_(int, int);
   extern int fwim_(int, int, int, int, int, Bool);
   static int dweap;
#define objvec ((int *)&pv_1 + 1)
   extern Bool oappli_(int, int);
#define prpvec ((int *)&pv_1 + 3)
   static int pblose;
   extern void rspeak_(int);
   extern int fights_(int, Bool);
   extern int vilstr_(int);
   extern void rspsub_(int, int);
   extern void jigsup_(int);
   extern void newsta_(int, int, int, int, int);

// Fortran I/O blocks
   static cilist io___43 = { 0, 6, 0, fmt_10, 0 };
   static cilist io___51 = { 0, 6, 0, fmt_2050, 0 };
   static cilist io___56 = { 0, 6, 0, fmt_2650, 0 };

// PARSE VECTOR

// 	LOGICAL PRSWON

// GAME STATE

// MISCELLANEOUS VARIABLES

// PARSER OUTPUT

// PARSER STATE

// OBJECTS

// CLOCK INTERRUPTS

// ADVENTURERS

// VERBS

// FUNCTIONS AND DATA

// BLOW, PAGE 3

   ra = objcts_1.oactio[(2644 + (0 + (v - 1 << 2)) - 2644) / 4];
// 						!GET VILLAIN ACTION,
   dv = objcts_1.odesc2[v - 1];
// 						!DESCRIPTION.
   ret_val = rmiss;
// 						!ASSUME NO RESULT.
   s_wsfe(&io___43);
   do_fio(&c__1, (char *)&(h__),(ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&(v),(ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&(rmk),(ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&(hflg),(ftnlen) sizeof(Bool));
   do_fio(&c__1, (char *)&(out),(ftnlen) sizeof(int));
   e_wsfe();
   if (!(hflg)) {
      goto L1000;
   }
// 						!HERO STRIKING BLOW?

// HERO IS ATTACKER, VILLAIN IS DEFENDER.

   pblose = 10;
// 						!BAD LK PROB.
   objcts_1.oflag2[v - 1] |= oflags_1.fitebt;
   if ((advs_1.aflag[h__ - 1] & aflags_1.astag) == 0) {
      goto L100;
   }
   rspeak_(c__591);
// 						!YES, CANT FIGHT.
   advs_1.aflag[h__ - 1] &= ~aflags_1.astag;
   return ret_val;

L100:
   att = fights_(h__, c_true);
// 						!GET HIS STRENGTH.
   oa = att;
   def = vilstr_(v);
// 						!GET VILL STRENGTH.
   od = def;
   dweap = 0;
// 						!ASSUME NO WEAPON.
   i__1 = objcts_1.olnt;
   for (i__ = 1; i__ <= i__1; ++i__) {
// 						!SEARCH VILLAIN.
      if (objcts_1.ocan[i__ - 1] == v && (objcts_1.oflag2[i__ - 1] & oflags_1.weapbt) != 0) {
         dweap = i__;
      }
// L200:
   }
   if (v == advs_1.aobj[aindex_1.player - 1]) {
      goto L300;
   }
// 						!KILLING SELF?
   if (def != 0) {
      goto L2000;
   }
// 						!DEFENDER ALIVE?
   rspsub_(c__592, dv);
// 						!VILLAIN DEAD.
   return ret_val;

L300:
   jigsup_(c__593);
// 						!KILLING SELF.
   return ret_val;

// VILLAIN IS ATTACKER, HERO IS DEFENDER.

L1000:
   pblose = 50;
// 						!BAD LK PROB.
   advs_1.aflag[h__ - 1] &= ~aflags_1.astag;
   if ((objcts_1.oflag2[v - 1] & oflags_1.stagbt) == 0) {
      goto L1200;
   }
   objcts_1.oflag2[v - 1] &= ~oflags_1.stagbt;
   rspsub_(c__594, dv);
// 						!DESCRIBE.
   return ret_val;

L1200:
   att = vilstr_(v);
// 						!SET UP ATT, DEF.
   oa = att;
   def = fights_(h__, c_true);
   if (def <= 0) {
      return ret_val;
   }
// 						!DONT ALLOW DEAD DEF.
   od = fights_(h__, c_false);
   dweap = (i__1 = fwim_(c__0, oflags_1.weapbt, c__0, c__0, h__, c_true), abs(i__1));
// 						!FIND A WEAPON.
// BLOW, PAGE 4

// PARTIES ARE NOW EQUIPPED.  DEF CANNOT BE ZERO.
// ATT MUST BE > 0.

L2000:
   s_wsfe(&io___51);
   do_fio(&c__1, (char *)&att, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&oa, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&def, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&od, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&dweap, (ftnlen) sizeof(int));
   e_wsfe();
   if (def > 0) {
      goto L2100;
   }
// 						!DEF ALIVE?
   res = rkill;
   if (hflg) {
      rspsub_(c__595, dv);
   }
// 						!DEADER.
   goto L3000;

L2100:
   if ((i__1 = def - 2) < 0) {
      goto L2200;
   } else if (i__1 == 0) {
      goto L2300;
   } else {
      goto L2400;
   }
// 						!DEF <2,=2,>2
L2200:
   att = min(att, 3);
// 						!SCALE ATT.
   tbl = def1r[att - 1];
// 						!CHOOSE TABLE.
   goto L2500;

L2300:
   att = min(att, 4);
// 						!SCALE ATT.
   tbl = def2r[att - 1];
// 						!CHOOSE TABLE.
   goto L2500;

L2400:
   att -= def;
// 						!SCALE ATT.
// Computing MIN
   i__1 = 2, i__2 = max(-2, att);
   att = min(i__1, i__2) + 3;
   tbl = def3r[att - 1];

L2500:
   res = rvectr[tbl + rnd_(c__10) - 1];
// 						!GET RESULT.
   if (out == 0) {
      goto L2600;
   }
// 						!WAS HE OUT?
   if (res == rstag) {
      goto L2550;
   }
// 						!YES, STAG--> HES.
   res = rsit;
// 						!OTHERWISE, SITTING.
   goto L2600;
L2550:
   res = rhes;
L2600:
   if (res == rstag && dweap != 0 && prob_(c__25, pblose)) {
      res = rlose;
   }

   mi = rstate[(rmk - 1) * 9 + res];
// 						!CHOOSE TABLE ENTRY.
   if (mi == 0) {
      goto L3000;
   }
   i__1 = mi / 1000;
   i__ = mi % 1000 + rnd_(i__1) + star_1.mbase + 1;
   j = dv;
   if (!(hflg) && dweap != 0) {
      j = objcts_1.odesc2[dweap - 1];
   }
   s_wsfe(&io___56);
   do_fio(&c__1, (char *)&res, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&mi, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&i__, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&j, (ftnlen) sizeof(int));
   do_fio(&c__1, (char *)&star_1.mbase, (ftnlen) sizeof(int));
   e_wsfe();
   rspsub_(i__, j);
// 						!PRESENT RESULT.
// BLOW, PAGE 5

// NOW APPLY RESULT

L3000:
   switch (res + 1) {
      case 1:
         goto L4000;
      case 2:
         goto L3100;
      case 3:
         goto L3200;
      case 4:
         goto L3300;
      case 5:
         goto L3400;
      case 6:
         goto L3500;
      case 7:
         goto L3600;
      case 8:
         goto L4000;
      case 9:
         goto L3200;
   }

L3100:
   if (hflg) {
      def = -def;
   }
// 						!UNCONSCIOUS.
   goto L4000;

L3200:
   def = 0;
// 						!KILLED OR SITTING DUCK.
   goto L4000;

L3300:
// Computing MAX
   i__1 = 0, i__2 = def - 1;
   def = max(i__1, i__2);
// 						!LIGHT WOUND.
   goto L4000;

L3400:
// Computing MAX
   i__1 = 0, i__2 = def - 2;
   def = max(i__1, i__2);
// 						!SERIOUS WOUND.
   goto L4000;

L3500:
   if (hflg) {
      goto L3550;
   }
// 						!STAGGERED.
   advs_1.aflag[h__ - 1] |= aflags_1.astag;
   goto L4000;

L3550:
   objcts_1.oflag2[v - 1] |= oflags_1.stagbt;
   goto L4000;

L3600:
   newsta_(dweap, c__0, play_1.here, c__0, c__0);
// 						!LOSE WEAPON.
   dweap = 0;
   if (hflg) {
      goto L4000;
   }
// 						!IF HERO, DONE.
   dweap = (i__1 = fwim_(c__0, oflags_1.weapbt, c__0, c__0, h__, c_true), abs(i__1));
// 						!GET NEW.
   if (dweap != 0) {
      rspsub_(c__605, objcts_1.odesc2[dweap - 1]);
   }
// BLOW, PAGE 6

L4000:
   ret_val = res;
// 						!RETURN RESULT.
   if (!(hflg)) {
      goto L4500;
   }
// 						!HERO?
   objcts_1.ocapac[v - 1] = def;
// 						!STORE NEW CAPACITY.
   if (def != 0) {
      goto L4100;
   }
// 						!DEAD?
   objcts_1.oflag2[v - 1] &= ~oflags_1.fitebt;
   rspsub_(c__572, dv);
// 						!HE DIES.
   newsta_(v, c__0, c__0, c__0, c__0);
// 						!MAKE HIM DISAPPEAR.
   if (ra == 0) {
      return ret_val;
   }
// 						!IF NX TO DO, EXIT.
   prsvec_1.prsa = vindex_1.deadxw;
// 						!LET HIM KNOW.
   f = oappli_(ra, c__0);
   return ret_val;

L4100:
   if (res != rout || ra == 0) {
      return ret_val;
   }
   prsvec_1.prsa = vindex_1.outxw;
// 						!LET HIM BE OUT.
   f = oappli_(ra, c__0);
   return ret_val;

L4500:
   advs_1.astren[h__ - 1] = -10000;
// 						!ASSUME DEAD.
   if (def != 0) {
      advs_1.astren[h__ - 1] = def - od;
   }
   if (def >= od) {
      goto L4600;
   }
   cevent_1.ctick[cindex_1.cevcur - 1] = 30;
   cevent_1.cflag[cindex_1.cevcur - 1] = true;
L4600:
   if (fights_(h__, c_true) > 0) {
      return ret_val;
   }
   advs_1.astren[h__ - 1] = 1 - fights_(h__, c_false);
// 						!HE'S DEAD.
   jigsup_(c__596);
   ret_val = -1;
   return ret_val;

}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqc
#undef eqa

// SWORDD- SWORD INTERMOVE DEMON

// DECLARATIONS
static Bool infest_(int);

void swordd_(void) {
// System generated locals
   int i__1, i__2;

// Local variables
   static int i__, ng;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define eqv ((int *)&vill_1 + 1)
#define xflag ((int *)&curxt_1 + 4)
   extern void rspeak_(int);
   extern Bool findxt_(int, int);

// GAME STATE

// CURRENT EXITS

// OBJECTS

// VILLAINS AND DEMONS

// SWORDD, PAGE 2

// ADVENTURERS

   if (objcts_1.oadv[oindex_1.sword - 1] != aindex_1.player) {
      goto L500;
   }
// 						!HOLDING SWORD?
   ng = 2;
// 						!ASSUME VILL CLOSE.
   if (infest_(play_1.here)) {
      goto L300;
   }
// 						!VILL HERE?
   ng = 1;
   i__1 = xsrch_1.xmax;
   i__2 = xsrch_1.xmin;
   for (i__ = xsrch_1.xmin; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
// 						!NO, SEARCH ROOMS.
      if (!findxt_(i__, play_1.here)) {
         goto L200;
      }
// 						!ROOM THAT WAY?
      switch (curxt_1.xtype) {
         case 1:
            goto L50;
         case 2:
            goto L200;
         case 3:
            goto L50;
         case 4:
            goto L50;
      }
// 						!SEE IF ROOM AT ALL.
   L50:
      if (infest_(curxt_1.xroom1)) {
         goto L300;
      }
// 						!CHECK ROOM.
   L200:
      ;
   }
   ng = 0;
// 						!NO GLOW.

L300:
   if (ng == hack_1.swdsta) {
      return;
   }
// 						!ANY STATE CHANGE?
   i__2 = ng + 495;
   rspeak_(i__2);
// 						!YES, TELL NEW STATE.
   hack_1.swdsta = ng;
   return;

L500:
   hack_1.swdact = false;
// 						!DROPPED SWORD,
// return;
// 						!DISABLE DEMON.
}

#undef xflag
#undef eqv
#undef eqo
#undef eqa

// INFEST-	SUBROUTINE TO TEST FOR INFESTED ROOM

// DECLARATIONS

static Bool infest_(int r__) {
// System generated locals
   Bool ret_val;

// Local variables
#define eqo ((int *)&objcts_1 + 1)
#define eqv ((int *)&vill_1 + 1)
#define flags ((Bool *)&findex_1)
#define switch__ ((int *)&findex_1 + 46)

// ROOMS

// OBJECTS

// VILLAINS AND DEMONS

// FLAGS

   if (!findex_1.endgmf) {
      ret_val = objcts_1.oroom[oindex_1.cyclo - 1] == r__ || objcts_1.oroom[oindex_1.troll - 1] == r__ || objcts_1.oroom[oindex_1.thief - 1] == r__ && hack_1.thfact;
   }
   if (findex_1.endgmf) {
      ret_val = r__ == rindex_1.mrg || r__ == rindex_1.mrge || r__ == rindex_1.mrgw || r__ == rindex_1.inmir && findex_1.mloc == rindex_1.mrg;
   }
   return ret_val;
}

#undef switch__
#undef flags
#undef eqv
#undef eqo
