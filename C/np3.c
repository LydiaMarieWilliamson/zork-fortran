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
   int bvoc[20];
} buzvoc_;

#define buzvoc_1 buzvoc_

extern struct {
   int pvoc[45];
} prpvoc_;

#define prpvoc_1 prpvoc_

extern struct {
   int dvoc[75];
} dirvoc_;

#define dirvoc_1 dirvoc_

extern union {
   struct {
      int avoc1[184], avoc2[114], avoc3[106], avocnd;
   } _1;
   struct {
      double eqv_pad[225];
   } _2;
} adjvoc_;

#define adjvoc_1 (adjvoc_._1)
#define adjvoc_2 (adjvoc_._2)

extern union {
   struct {
      int vvoc1[92], vvoc1a[108], vvoc1b[38], vvoc2[104], vvoc3[136], vvoc4[116], vvoc5[134], vvoc6[117], vvoc7[89], vvocnd;
   } _1;
   struct {
      double eqv_pad[475];
   } _2;
} vrbvoc_;

#define vrbvoc_1 (vrbvoc_._1)
#define vrbvoc_2 (vrbvoc_._2)

extern union {
   struct {
      int ovoc1[159], ovoc2[144], ovoc3[150], ovoc4[128], ovoc5[111], ovoc6[104], ovoc6a[97], ovoc7[127], ovocnd;
   } _1;
   struct {
      double eqv_pad[525];
   } _2;
} objvoc_;

#define objvoc_1 (objvoc_._1)
#define objvoc_2 (objvoc_._2)

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

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
   int mbase, strbit;
} star_;

#define star_1 star_

extern struct {
   int winner, here;
   Bool telflg;
} play_;

#define play_1 play_

extern struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

#define state_1 state_

extern struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

#define oflags_1 oflags_

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

// Table of constant values

static int c_n1 = -1;
static int c__0 = 0;
static int c__623 = 623;
static int c__624 = 624;
static int c__601 = 601;
static int c__566 = 566;
static int c__445 = 445;
static int c__665 = 665;
static int c__672 = 672;
static int c__558 = 558;
static int c__559 = 559;

// SYNMCH--	SYNTAX MATCHER

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

// THIS ROUTINE DETAILS ON BIT 4 OF PRSFLG

Bool synmch_(void) {
// Initialized data

   static int r50min = 1600;

// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int j;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define avoc ((int *)&adjvoc_1)
#define pvec ((int *)&pv_1)
   static int newj;
   extern int gwim_(int *, int *, int *);
#define ovoc ((int *)&objvoc_1)
#define vvoc ((int *)&vrbvoc_1)
   static int drive, limit, qprep, sprep, dforce;
#define objvec ((int *)&pv_1 + 1)
   extern Bool takeit_(int *, int *);
   extern Void rspeak_(int *), orphan_(int *, int *, int *, int *, int *);
#define prpvec ((int *)&pv_1 + 3)
   extern Bool syneql_(int *, int *, int *, int *, int *);
   extern Void unpacks_(int *, int *);

// PARSER OUTPUT

// PARSER STATE

// VOCABULARIES

//   THE FOLLOWING DATA STATEMENT WAS ORIGINALLY:

// 	DATA R50MIN/1RA/

   ret_val = false;
// D	DFLAG=IAND(PRSFLG, 16).NE.0
/* D	if(DFLAG)write(0,*) 'synflags=',sdir,sind,sstd,sflip,sdriv,svmask */
   j = pv_1.act;
// 						!SET UP PTR TO SYNTAX.
   drive = 0;
// 						!NO DEFAULT.
   dforce = 0;
// 						!NO FORCED DEFAULT.
   qprep = orphs_1.oflag & orphs_1.oprep;
L100:
   j += 2;
// 						!FIND START OF SYNTAX.
   if (vvoc[j - 1] <= 0 || vvoc[j - 1] >= r50min) {
      goto L100;
   }
   limit = j + vvoc[j - 1] + 1;
// 						!COMPUTE LIMIT.
   ++j;
// 						!ADVANCE TO NEXT.

L200:
   unpacks_(&j, &newj);
// 						!UNPACK SYNTAX.
// D	IF(DFLAG) PRINT 60,O1,P1,DOBJ,DFL1,DFL2
// D60	FORMAT(' SYNMCH INPUTS TO SYNEQL- ',5I7)
   sprep = syntax_1.dobj & objflg_1.vpmask;
   if (!syneql_(&pv_1.p1, &pv_1.o1, &syntax_1.dobj, &syntax_1.dfl1, &syntax_1.dfl2)) {
      goto L1000;
   }
// D	IF(DFLAG) PRINT 60,O2,P2,IOBJ,IFL1,IFL2
   sprep = syntax_1.iobj & objflg_1.vpmask;
   if (syneql_(&pv_1.p2, &pv_1.o2, &syntax_1.iobj, &syntax_1.ifl1, &syntax_1.ifl2)) {
      goto L6000;
   }

// SYNTAX MATCH FAILS, TRY NEXT ONE.

   if (pv_1.o2 != 0) {
      goto L3000;
   } else {
      goto L500;
   }
// 						!IF O2=0, SET DFLT.
L1000:
   if (pv_1.o1 != 0) {
      goto L3000;
   } else {
      goto L500;
   }
// 						!IF O1=0, SET DFLT.
L500:
   if (qprep == 0 || qprep == sprep) {
      dforce = j;
   }
// 						!IF PREP MCH.
   if ((syntax_1.vflag & synflg_1.sdriv) != 0) {
      drive = j;
   }
L3000:
   j = newj;
   if (j < limit) {
      goto L200;
   }
// 						!MORE TO DO?
// SYNMCH, PAGE 2

// MATCH HAS FAILED.  IF DEFAULT SYNTAX EXISTS, TRY TO SNARF
// ORPHANS OR GWIMS, OR MAKE NEW ORPHANS.

// D	IF(DFLAG) PRINT 20,DRIVE,DFORCE
// D20	FORMAT(' SYNMCH, DRIVE=',2I6)
   if (drive == 0) {
      drive = dforce;
   }
// 						!NO DRIVER? USE FORCE.
   if (drive == 0) {
      goto L10000;
   }
// 						!ANY DRIVER?
   unpacks_(&drive, &dforce);
// 						!UNPACK DFLT SYNTAX.

// TRY TO FILL DIRECT OBJECT SLOT IF THAT WAS THE PROBLEM.

   if ((syntax_1.vflag & synflg_1.sdir) == 0 || pv_1.o1 != 0) {
      goto L4000;
   }

// FIRST TRY TO SNARF ORPHAN OBJECT.

   pv_1.o1 = orphs_1.oflag & orphs_1.oslot;
   if (pv_1.o1 == 0) {
      goto L3500;
   }
// 						!ANY ORPHAN?
   if (syneql_(&pv_1.p1, &pv_1.o1, &syntax_1.dobj, &syntax_1.dfl1, &syntax_1.dfl2)) {
      goto L4000;
   }

// ORPHAN FAILS, TRY GWIM.

L3500:
   pv_1.o1 = gwim_(&syntax_1.dobj, &syntax_1.dfw1, &syntax_1.dfw2);
// 						!GET GWIM.
// D	IF(DFLAG) PRINT 30,O1
// D30	FORMAT(' SYNMCH- DO GWIM= ',I6)
   if (pv_1.o1 > 0) {
      goto L4000;
   }
// 						!TEST RESULT.
   i__1 = syntax_1.dobj & objflg_1.vpmask;
   orphan_(&c_n1, &pv_1.act, &c__0, &i__1, &c__0);
   rspeak_(&c__623);
   return ret_val;

// TRY TO FILL INDIRECT OBJECT SLOT IF THAT WAS THE PROBLEM.

L4000:
   if ((syntax_1.vflag & synflg_1.sind) == 0 || pv_1.o2 != 0) {
      goto L6000;
   }
   pv_1.o2 = gwim_(&syntax_1.iobj, &syntax_1.ifw1, &syntax_1.ifw2);
// 						!GWIM.
// D	IF(DFLAG) PRINT 40,O2
// D40	FORMAT(' SYNMCH- IO GWIM= ',I6)
   if (pv_1.o2 > 0) {
      goto L6000;
   }
   if (pv_1.o1 == 0) {
      pv_1.o1 = orphs_1.oflag & orphs_1.oslot;
   }
   i__1 = syntax_1.dobj & objflg_1.vpmask;
   orphan_(&c_n1, &pv_1.act, &pv_1.o1, &i__1, &c__0);
   rspeak_(&c__624);
   return ret_val;

// TOTAL CHOMP

L10000:
   rspeak_(&c__601);
// 						!CANT DO ANYTHING.
   return ret_val;
// SYNMCH, PAGE 3

// NOW TRY TO TAKE INDIVIDUAL OBJECTS AND
// IN GENERAL CLEAN UP THE PARSE VECTOR.

L6000:
   if ((syntax_1.vflag & synflg_1.sflip) == 0) {
      goto L5000;
   }
   j = pv_1.o1;
// 						!YES.
   pv_1.o1 = pv_1.o2;
   pv_1.o2 = j;

L5000:
   prsvec_1.prsa = syntax_1.vflag & synflg_1.svmask;
   prsvec_1.prso = pv_1.o1;
// 						!GET DIR OBJ.
   prsvec_1.prsi = pv_1.o2;
// 						!GET IND OBJ.
   if (!takeit_(&prsvec_1.prso, &syntax_1.dobj)) {
      return ret_val;
   }
// 						!TRY TAKE.
   if (!takeit_(&prsvec_1.prsi, &syntax_1.iobj)) {
      return ret_val;
   }
// 						!TRY TAKE.
   ret_val = true;
// D	IF(DFLAG) PRINT 50,SYNMCH,PRSA,PRSO,PRSI,ACT,O1,O2
// D50	FORMAT(' SYNMCH- RESULTS ',L1,6I7)
   return ret_val;

}

#undef prpvec
#undef objvec
#undef vvoc
#undef ovoc
#undef pvec
#undef avoc
#undef syn
#undef orp

// UNPACKS-	UNPACK SYNTAX SPECIFICATION, ADV POINTER

// DECLARATIONS

Void unpacks_(int * oldj, int * j) {
// Local variables
   static int i__;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define avoc ((int *)&adjvoc_1)
#define pvec ((int *)&pv_1)
#define ovoc ((int *)&objvoc_1)
#define vvoc ((int *)&vrbvoc_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// VOCABULARIES

// PARSER OUTPUT

// PARSER STATE

   for (i__ = 1; i__ <= 11; ++i__) {
// 						!CLEAR SYNTAX.
      syn[i__ - 1] = 0;
// L10:
   }

   syntax_1.vflag = vvoc[*oldj - 1];
   *j = *oldj + 1;
   if ((syntax_1.vflag & synflg_1.sdir) == 0) {
      return 0;
   }
   syntax_1.dfl1 = -1;
// 						!ASSUME STD.
   syntax_1.dfl2 = -1;
   if ((syntax_1.vflag & synflg_1.sstd) == 0) {
      goto L100;
   }
   syntax_1.dfw1 = -1;
// 						!YES.
   syntax_1.dfw2 = -1;
   syntax_1.dobj = objflg_1.vabit + objflg_1.vrbit + objflg_1.vfbit;
   goto L200;

L100:
   syntax_1.dobj = vvoc[*j - 1];
// 						!NOT STD.
   syntax_1.dfw1 = vvoc[*j];
   syntax_1.dfw2 = vvoc[*j + 1];
   *j += 3;
   if ((syntax_1.dobj & objflg_1.vebit) == 0) {
      goto L200;
   }
   syntax_1.dfl1 = syntax_1.dfw1;
// 						!YES.
   syntax_1.dfl2 = syntax_1.dfw2;

L200:
   if ((syntax_1.vflag & synflg_1.sind) == 0) {
      return 0;
   }
   syntax_1.ifl1 = -1;
// 						!ASSUME STD.
   syntax_1.ifl2 = -1;
   syntax_1.iobj = vvoc[*j - 1];
   syntax_1.ifw1 = vvoc[*j];
   syntax_1.ifw2 = vvoc[*j + 1];
   *j += 3;
   if ((syntax_1.iobj & objflg_1.vebit) == 0) {
      return 0;
   }
   syntax_1.ifl1 = syntax_1.ifw1;
// 						!YES.
   syntax_1.ifl2 = syntax_1.ifw2;
   return 0;

}

#undef prpvec
#undef objvec
#undef vvoc
#undef ovoc
#undef pvec
#undef avoc
#undef syn
#undef orp

// SYNEQL-	TEST FOR SYNTAX EQUALITY

// DECLARATIONS

Bool syneql_(int * prep, int * obj, int * sprep, int * sfl1, int * sfl2) {
// System generated locals
   Bool ret_val;

// Local variables
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// OBJECTS

// PARSER OUTPUT

// PARSER STATE

   if (*obj == 0) {
      goto L100;
   }
// 						!ANY OBJECT?
   ret_val = *prep == (*sprep & objflg_1.vpmask) && (*sfl1 & objcts_1.oflag1[*obj - 1] | *sfl2 & objcts_1.oflag2[*obj - 1]) != 0;
   return ret_val;

L100:
   ret_val = *prep == 0 && *sfl1 == 0 && *sfl2 == 0;
   return ret_val;

}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo

// TAKEIT-	PARSER BASED TAKE OF OBJECT

// DECLARATIONS

Bool takeit_(int * obj, int * sflag) {
// System generated locals
   Bool ret_val;

// Local variables
   static int x;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
   static int odo2;
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)
   extern Void rspsub_(int *, int *);
   extern int schlst_(int *, int *, int *, int *, int *, int *);
   extern Void rspeak_(int *);
   extern int weight_(int *, int *, int *);
   extern Void newsta_(int *, int *, int *, int *, int *), scrupd_(int *);

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// OBJECTS

// TAKEIT, PAGE 2

// ADVENTURERS

   ret_val = false;
// 						!ASSUME LOSES.
   if (*obj == 0 || *obj > star_1.strbit) {
      goto L4000;
   }
// 						!NULL/STARS WIN.
   odo2 = objcts_1.odesc2[*obj - 1];
// 						!GET DESC.
   x = objcts_1.ocan[*obj - 1];
// 						!GET CONTAINER.
   if (x == 0 || (*sflag & objflg_1.vfbit) == 0) {
      goto L500;
   }
   if ((objcts_1.oflag2[x - 1] & oflags_1.openbt) != 0) {
      goto L500;
   }
   rspsub_(&c__566, &odo2);
// 						!CANT REACH.
   return ret_val;

L500:
   if ((*sflag & objflg_1.vrbit) == 0) {
      goto L1000;
   }
   if ((*sflag & objflg_1.vtbit) == 0) {
      goto L2000;
   }

// SHOULD BE IN ROOM (VRBIT NE 0) AND CAN BE TAKEN (VTBIT NE 0)

   if (schlst_(&c__0, &c__0, &play_1.here, &c__0, &c__0, obj) <= 0) {
      goto L4000;
   }
// 						!IF NOT, OK.

// ITS IN THE ROOM AND CAN BE TAKEN.

   if ((objcts_1.oflag1[*obj - 1] & oflags_1.takebt) != 0 && (objcts_1.oflag2[*obj - 1] & oflags_1.trybt) == 0) {
      goto L3000;
   }

// NOT TAKEABLE.  IF WE CARE, FAIL.

   if ((*sflag & objflg_1.vcbit) == 0) {
      goto L4000;
   }
   rspsub_(&c__445, &odo2);
   return ret_val;

// 1000--	IT SHOULD NOT BE IN THE ROOM.
// 2000--	IT CANT BE TAKEN.

L2000:
   if ((*sflag & objflg_1.vcbit) == 0) {
      goto L4000;
   }
L1000:
   if (schlst_(&c__0, &c__0, &play_1.here, &c__0, &c__0, obj) <= 0) {
      goto L4000;
   }
   rspsub_(&c__665, &odo2);
   return ret_val;
// TAKEIT, PAGE 3

// OBJECT IS IN THE ROOM, CAN BE TAKEN BY THE PARSER,
// AND IS TAKEABLE IN GENERAL.  IT IS NOT A STAR.
// TAKING IT SHOULD NOT HAVE SIDE AFFECTS.
// IF IT IS INSIDE SOMETHING, THE CONTAINER IS OPEN.
// THE FOLLOWING CODE IS LIFTED FROM SUBROUTINE TAKE.

L3000:
   if (*obj != advs_1.avehic[play_1.winner - 1]) {
      goto L3500;
   }
// 						!TAKE VEHICLE?
   rspeak_(&c__672);
   return ret_val;

L3500:
   if (x != 0 && objcts_1.oadv[x - 1] == play_1.winner || weight_(&c__0, obj, &play_1.winner) + objcts_1.osize[*obj - 1] <= state_1.mxload) {
      goto L3700;
   }
   rspeak_(&c__558);
// 						!TOO BIG.
   return ret_val;

L3700:
   newsta_(obj, &c__559, &c__0, &c__0, &play_1.winner);
// 						!DO TAKE.
   objcts_1.oflag2[*obj - 1] |= oflags_1.tchbt;
   scrupd_(&objcts_1.ofval[*obj - 1]);
   objcts_1.ofval[*obj - 1] = 0;

L4000:
   ret_val = true;
// 						!SUCCESS.
   return ret_val;

}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqa

// GWIM- GET WHAT I MEAN IN AMBIGOUS SITUATIONS

// DECLARATIONS

int gwim_(int * sflag, int * sfw1, int * sfw2) {
// System generated locals
   int ret_val;

// Local variables
   static int av;
#define eqa ((int *)&advs_1 + 1)
#define eqo ((int *)&objcts_1 + 1)
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
   static int nobj, robj;
#define pvec ((int *)&pv_1)
   extern int fwim_(int *, int *, int *, int *, int *, Bool *);
   static Bool nocare;
#define objvec ((int *)&pv_1 + 1)
   extern Bool takeit_(int *, int *);
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// GAME STATE

// OBJECTS

// GWIM, PAGE 2

// ADVENTURERS

   ret_val = -1;
// 						!ASSUME LOSE.
   av = advs_1.avehic[play_1.winner - 1];
   nobj = 0;
   nocare = (*sflag & objflg_1.vcbit) == 0;

// FIRST SEARCH ADVENTURER

   if ((*sflag & objflg_1.vabit) != 0) {
      nobj = fwim_(sfw1, sfw2, &c__0, &c__0, &play_1.winner, &nocare);
   }
   if ((*sflag & objflg_1.vrbit) != 0) {
      goto L100;
   }
L50:
   ret_val = nobj;
   return ret_val;

// ALSO SEARCH ROOM

L100:
   robj = fwim_(sfw1, sfw2, &play_1.here, &c__0, &c__0, &nocare);
   if (robj < 0) {
      goto L500;
   } else if (robj == 0) {
      goto L50;
   } else {
      goto L200;
   }
// 						!TEST RESULT.

// ROBJ > 0

L200:
   if (av == 0 || robj == av || (objcts_1.oflag2[robj - 1] & oflags_1.findbt) != 0) {
      goto L300;
   }
   if (objcts_1.ocan[robj - 1] != av) {
      goto L50;
   }
// 						!UNREACHABLE? TRY NOBJ
L300:
   if (nobj != 0) {
      return ret_val;
   }
// 						!IF AMBIGUOUS, RETURN.
   if (!takeit_(&robj, sflag)) {
      return ret_val;
   }
// 						!IF UNTAKEABLE, RETURN
   ret_val = robj;
L500:
   return ret_val;

}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
#undef eqo
#undef eqa