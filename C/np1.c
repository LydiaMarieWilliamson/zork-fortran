#include "F2C.h"

/* Common Block Declarations */

struct {
   integer prsa, prsi, prso;
   logical prswon;
   integer prscon;
} prsvec_;

#define prsvec_1 prsvec_

struct {
   integer oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_

struct {
   integer lastit;
} last_;

#define last_1 last_

struct {
   integer act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_

struct {
   integer vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

#define syntax_1 syntax_

struct {
   integer sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

#define synflg_1 synflg_

struct {
   integer vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

#define objflg_1 objflg_

struct {
   integer winner, here;
   logical telflg;
} play_;

#define play_1 play_

struct {
   integer dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

struct {
   integer olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
   , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_

struct {
   integer r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

struct {
   integer garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

struct {
   integer alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

#define advs_1 advs_

struct {
   integer astag;
} aflags_;

#define aflags_1 aflags_

struct {
   integer player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

struct {
   integer cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;

#define vindex_1 vindex_

struct {
   integer bvoc[20];
} buzvoc_;

#define buzvoc_1 buzvoc_

struct {
   integer pvoc[45];
} prpvoc_;

#define prpvoc_1 prpvoc_

struct {
   integer dvoc[75];
} dirvoc_;

#define dirvoc_1 dirvoc_

union {
   struct {
      integer avoc1[184], avoc2[114], avoc3[106], avocnd;
   } _1;
   struct {
      doublereal eqv_pad[225];
   } _2;
} adjvoc_;

#define adjvoc_1 (adjvoc_._1)
#define adjvoc_2 (adjvoc_._2)

union {
   struct {
      integer vvoc1[92], vvoc1a[108], vvoc1b[38], vvoc2[104], vvoc3[136], vvoc4[116], vvoc5[134], vvoc6[117], vvoc7[89], vvocnd;
   } _1;
   struct {
      doublereal eqv_pad[475];
   } _2;
} vrbvoc_;

#define vrbvoc_1 (vrbvoc_._1)
#define vrbvoc_2 (vrbvoc_._2)

union {
   struct {
      integer ovoc1[159], ovoc2[144], ovoc3[150], ovoc4[128], ovoc5[111], ovoc6[104], ovoc6a[97], ovoc7[127], ovocnd;
   } _1;
   struct {
      doublereal eqv_pad[525];
   } _2;
} objvoc_;

#define objvoc_1 (objvoc_._1)
#define objvoc_2 (objvoc_._2)

/* Table of constant values */

static integer c__601 = 601;
static integer c__0 = 0;
static integer c__616 = 616;
static integer c__620 = 620;
static integer c__619 = 619;
static integer c_n1 = -1;
static integer c__617 = 617;
static integer c__621 = 621;
static integer c__622 = 622;

/* SPARSE-	START OF PARSE */

/* COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142 */
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

/* DECLARATIONS */

/* THIS ROUTINE DETAILS ON BIT 2 OF PRSFLG */

integer sparse_(integer * lbuf, integer * llnt, logical * vbflag) {
/* Initialized data */

   static integer r50min = 1600;
   static integer r50wal = 36852;

/* System generated locals */
   integer ret_val, i__1, i__2;

/* Local variables */
   static integer i__, j, adj;
#define eqa ((integer *)&advs_1 + 1)
   static integer obj;
#define eqo ((integer *)&objcts_1 + 1)
   extern logical lit_(integer *);
#define orp ((integer *)&orphs_1)
#define syn ((integer *)&syntax_1)
#define pvec ((integer *)&pv_1)
#define avoc ((integer *)&adjvoc_1)
#define vvoc ((integer *)&vrbvoc_1)
#define ovoc ((integer *)&objvoc_1)
   static integer prep, pptr, lbuf1, lbuf2;
#define objvec ((integer *)&pv_1 + 1)
#define prpvec ((integer *)&pv_1 + 3)
   static integer buzlnt, prplnt, dirlnt;
   extern /* Subroutine */ int rspeak_(integer *);
   extern integer getobj_(integer *, integer *, integer *);
   extern /* Subroutine */ int rspsub_(integer *, integer *), orphan_(integer *, integer *, integer *, integer *, integer *);

/* PARSER OUTPUT */

/* PARSER STATE */

/* GAME STATE */

/* OBJECTS */

/* ADVENTURERS */

/* VERBS */

/* SPARSE, PAGE 2 */

/* FUNCTIONS AND DATA */

/* VOCABULARIES */

/*   THE FOLLOWING DATA STATEMENT ORIGINALLY WAS: */

/* 	DATA R50MIN/1RA/,R50WAL/3RWAL/ */

/* Parameter adjustments */
   --lbuf;

/* Function Body */
/* SPARSE, PAGE 7 */

/* SET UP FOR PARSING */

   ret_val = -1;
/* 						!ASSUME PARSE FAILS. */
   adj = 0;
/* 						!CLEAR PARTS HOLDERS. */
   pv_1.act = 0;
   prep = 0;
   pptr = 0;
   pv_1.o1 = 0;
   pv_1.o2 = 0;
   pv_1.p1 = 0;
   pv_1.p2 = 0;
/* D	DFLAG=IAND(PRSFLG,4).NE.0 */

   buzlnt = 20;
   prplnt = 48;
   dirlnt = 75;
/* SPARSE, PAGE 8 */

/* NOW LOOP OVER INPUT BUFFER OF LEXICAL TOKENS. */

   i__1 = *llnt;
   for (i__ = 1; i__ <= i__1; i__ += 2) {
/* 						!TWO WORDS/TOKEN. */
      lbuf1 = lbuf[i__];
/* 						!GET CURRENT TOKEN. */
      lbuf2 = lbuf[i__ + 1];
/* D	  if(DFLAG) write(0,*) 'lbuf1=',lbuf1,' lbuf2=',lbuf2 */
      if (lbuf1 == 0) {
         goto L1500;
      }
/* 						!END OF BUFFER? */

/* CHECK FOR BUZZ WORD */

      i__2 = buzlnt;
      for (j = 1; j <= i__2; j += 2) {
         if (lbuf1 == buzvoc_1.bvoc[j - 1] && lbuf2 == buzvoc_1.bvoc[j]) {
            goto L1000;
         }
   /* L50: */
      }

/* CHECK FOR ACTION OR DIRECTION */

      if (pv_1.act != 0) {
         goto L75;
      }
/* 						!GOT ACTION ALREADY? */
      j = 1;
/* 						!CHECK FOR ACTION. */
   L125:
      if (lbuf1 == vvoc[j - 1] && lbuf2 == vvoc[j]) {
         goto L3000;
      }
/* L150: */
      j += 2;
/* 						!ADV TO NEXT SYNONYM. */
      if (!(vvoc[j - 1] > 0 && vvoc[j - 1] < r50min)) {
         goto L125;
      }
/* 						!ANOTHER VERB? */
      j = j + vvoc[j - 1] + 1;
/* 						!NO, ADVANCE OVER SYNTAX. */
      if (vvoc[j - 1] != -1) {
         goto L125;
      }
/* 						!TABLE DONE? */

   L75:
      if (pv_1.act != 0 && (vvoc[pv_1.act - 1] != r50wal || prep != 0)) {
         goto L200;
      }
      i__2 = dirlnt;
      for (j = 1; j <= i__2; j += 3) {
/* 						!THEN CHK FOR DIR. */
         if (lbuf1 == dirvoc_1.dvoc[j - 1] && lbuf2 == dirvoc_1.dvoc[j]) {
            goto L2000;
         }
   /* L100: */
      }

/* NOT AN ACTION, CHECK FOR PREPOSITION, ADJECTIVE, OR OBJECT. */

   L200:
      i__2 = prplnt;
      for (j = 1; j <= i__2; j += 3) {
/* 						!LOOK FOR PREPOSITION. */
         if (lbuf1 == prpvoc_1.pvoc[j - 1] && lbuf2 == prpvoc_1.pvoc[j]) {
            goto L4000;
         }
   /* L250: */
      }

      j = 1;
/* 						!LOOK FOR ADJECTIVE. */
   L300:
      if (lbuf1 == avoc[j - 1] && lbuf2 == avoc[j]) {
         goto L5000;
      }
      ++j;
   L325:
      ++j;
/* 						!ADVANCE TO NEXT ENTRY. */
      if (avoc[j - 1] > 0 && avoc[j - 1] < r50min) {
         goto L325;
      }
/* 						!A RADIX 50 CONSTANT? */
      if (avoc[j - 1] != -1) {
         goto L300;
      }
/* 						!POSSIBLY, END TABLE? */

      j = 1;
/* 						!LOOK FOR OBJECT. */
   L450:
      if (lbuf1 == ovoc[j - 1] && lbuf2 == ovoc[j]) {
         goto L600;
      }
      ++j;
   L500:
      ++j;
      if (ovoc[j - 1] > 0 && ovoc[j - 1] < r50min) {
         goto L500;
      }
      if (ovoc[j - 1] != -1) {
         goto L450;
      }

   /* NOT RECOGNIZABLE */

      if (*vbflag) {
         rspeak_(&c__601);
      }
      return ret_val;
/* SPARSE, PAGE 9 */

/* OBJECT PROCESSING (CONTINUATION OF DO LOOP ON PREV PAGE) */

   L600:
      obj = getobj_(&j, &adj, &c__0);
/* 						!IDENTIFY OBJECT. */
/* D	  IF(DFLAG) PRINT 60,J,OBJ */
/* D60	  FORMAT(' SPARSE- OBJ AT ',I6,'  OBJ= ',I6) */
      if (obj <= 0) {
         goto L6000;
      }
/* 						!IF LE, COULDNT. */
      if (obj != oindex_1.itobj) {
         goto L650;
      }
/* 						!"IT"? */
      obj = getobj_(&c__0, &c__0, &last_1.lastit);
/* 						!FIND LAST. */
      if (obj <= 0) {
         goto L6000;
      }
/* 						!IF LE, COULDNT. */

   L650:
      if (prep == 9) {
         goto L8000;
      }
/* 						!"OF" OBJ? */
      if (pptr == 2) {
         goto L7000;
      }
/* 						!TOO MANY OBJS? */
      ++pptr;
      objvec[pptr - 1] = obj;
/* 						!STUFF INTO VECTOR. */
      prpvec[pptr - 1] = prep;
   L700:
      prep = 0;
      adj = 0;
/* Go to end of do loop (moved "1000 CONTINUE" to end of module, to avoid */
/* complaints about people jumping back into the doloop.) */
      goto L1000;
/* SPARSE, PAGE 10 */

/* SPECIAL PARSE PROCESSORS */

/* 2000--	DIRECTION */

   L2000:
      prsvec_1.prsa = vindex_1.walkw;
      prsvec_1.prso = dirvoc_1.dvoc[j + 1];
      ret_val = 1;
/* D	IF(DFLAG) PRINT 10,J */
/* D10	FORMAT(' SPARSE- DIR AT ',I6) */
      return ret_val;

/* 3000--	ACTION */

   L3000:
      pv_1.act = j;
      orphs_1.oact = 0;
/* D	IF(DFLAG) PRINT 20,J */
/* D20	FORMAT(' SPARSE- ACT AT ',I6) */
/* D	if(dflag) write(0,*) 'count=',vvoc(j+2),' vnr=',vvoc(j+3) */
      goto L1000;

/* 4000--	PREPOSITION */

   L4000:
      if (prep != 0) {
         goto L4500;
      }
      prep = prpvoc_1.pvoc[j + 1];
      adj = 0;
/* D	IF(DFLAG) PRINT 30,J */
/* D30	FORMAT(' SPARSE- PREP AT ',I6) */
      goto L1000;

   L4500:
      if (*vbflag) {
         rspeak_(&c__616);
      }
      return ret_val;

/* 5000--	ADJECTIVE */

   L5000:
      adj = j;
      j = orphs_1.oname & orphs_1.oflag;
/* D	IF(DFLAG) PRINT 40,ADJ,J */
/* D40	FORMAT(' SPARSE- ADJ AT ',I6,' ORPHAN= ',I6) */
      if (j != 0 && i__ >= *llnt) {
         goto L600;
      }
      goto L1000;

/* 6000--	UNIDENTIFIABLE OBJECT (INDEX INTO OVOC IS J) */

   L6000:
      if (obj < 0) {
         goto L6100;
      }
      j = 579;
      if (lit_(&play_1.here)) {
         j = 618;
      }
      if (*vbflag) {
         rspeak_(&j);
      }
      return ret_val;

   L6100:
      if (obj != -10000) {
         goto L6200;
      }
      if (*vbflag) {
         rspsub_(&c__620, &objcts_1.odesc2[advs_1.avehic[play_1.winner - 1] - 1]);
      }
      return ret_val;

   L6200:
      if (*vbflag) {
         rspeak_(&c__619);
      }
      if (pv_1.act == 0) {
         pv_1.act = orphs_1.oflag & orphs_1.oact;
      }
      orphan_(&c_n1, &pv_1.act, &pv_1.o1, &prep, &j);
      return ret_val;

/* 7000--	TOO MANY OBJECTS. */

   L7000:
      if (*vbflag) {
         rspeak_(&c__617);
      }
      return ret_val;

/* 8000--	RANDOMNESS FOR "OF" WORDS */

   L8000:
      if (objvec[pptr - 1] == obj) {
         goto L700;
      }
      if (*vbflag) {
         rspeak_(&c__601);
      }
      return ret_val;

/* End of do-loop. */

   L1000:
      ;
   }
/* 						!AT LAST. */

/* NOW SOME MISC CLEANUP -- We fell out of the do-loop */

L1500:
   if (pv_1.act == 0) {
      pv_1.act = orphs_1.oflag & orphs_1.oact;
   }
   if (pv_1.act == 0) {
      goto L9000;
   }
/* 						!IF STILL NONE, PUNT. */
   if (adj != 0) {
      goto L10000;
   }
/* 						!IF DANGLING ADJ, PUNT. */

   if (orphs_1.oflag != 0 && orphs_1.oprep != 0 && prep == 0 && pv_1.o1 != 0 && pv_1.o2 == 0 && pv_1.act == orphs_1.oact) {
      goto L11000;
   }

   ret_val = 0;
/* 						!PARSE SUCCEEDS. */
   if (prep == 0) {
      goto L1750;
   }
/* 						!IF DANGLING PREP, */
   if (pptr == 0 || prpvec[pptr - 1] != 0) {
      goto L12000;
   }
   prpvec[pptr - 1] = prep;
/* 						!CVT TO 'PICK UP FROB'. */

/* 1750--	RETURN A RESULT */

L1750:
/* 						!WIN. */
/* D	IF(DFLAG) PRINT 70,ACT,O1,O2,P1,P2 */
/* D70	FORMAT(' SPARSE RESULTS- ',5I7) */
/* D	if(dflag) write(0,*) 'sparse=',sparse */
   return ret_val;
/* 						!LOSE. */

/* 9000--	NO ACTION, PUNT */

L9000:
   if (pv_1.o1 == 0) {
      goto L10000;
   }
/* 						!ANY DIRECT OBJECT? */
   if (*vbflag) {
      rspsub_(&c__621, &objcts_1.odesc2[pv_1.o1 - 1]);
   }
/* 						!WHAT TO DO? */
   orphan_(&c_n1, &c__0, &pv_1.o1, &c__0, &c__0);
   return ret_val;

/* 10000--	TOTAL CHOMP */

L10000:
   if (*vbflag) {
      rspeak_(&c__622);
   }
/* 						!HUH? */
   return ret_val;

/* 11000--	ORPHAN PREPOSITION.  CONDITIONS ARE */
/* 		O1.NE.0, O2=0, PREP=0, ACT=OACT */

L11000:
   if (orphs_1.oslot != 0) {
      goto L11500;
   }
/* 						!ORPHAN OBJECT? */
   pv_1.p1 = orphs_1.oprep;
/* 						!NO, JUST USE PREP. */
   goto L1750;

L11500:
   pv_1.o2 = pv_1.o1;
/* 						!YES, USE AS DIRECT OBJ. */
   pv_1.p2 = orphs_1.oprep;
   pv_1.o1 = orphs_1.oslot;
   pv_1.p1 = 0;
   goto L1750;

/* 12000--	TRUE HANGING PREPOSITION. */
/* 		ORPHAN FOR LATER. */

L12000:
   orphan_(&c_n1, &pv_1.act, &c__0, &prep, &c__0);
/* 						!ORPHAN PREP. */
   goto L1750;

} /* sparse_ */

#undef prpvec
#undef objvec
#undef ovoc
#undef vvoc
#undef avoc
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqa
