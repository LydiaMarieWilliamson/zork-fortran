#include "F2C.h"

// Common Block Declarations

extern struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;

#define prsvec_1 prsvec_

extern union {
   struct {
      int oflag, oact, oslot, oprep, oname;
   } _1;
   struct {
      int a, b, c__, d__, e;
   } _2;
} orphs_;

#define orphs_1 (orphs_._1)
#define orphs_2 (orphs_._2)

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
   int inlnt;
   char inbuf[78];
} input_;

#define input_1 input_

extern struct {
   int inpch, outch, dbch;
} chan_;

#define chan_1 chan_

extern struct {
   int dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

extern struct {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;

#define xsrch_1 xsrch_

// Table of constant values

static int c__78 = 78;
static int c__0 = 0;
static int c__601 = 601;

// RDLINE-	READ INPUT LINE

// COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142
// ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED
// WRITTEN BY R. M. SUPNIK

// DECLARATIONS

void rdline_(char *buffer, int length, int who, ftnlen buffer_len) {
// Format strings
   static char fmt_50[] = "(\002 >\002,$)";
   static char fmt_100[] = "(78a1)";

// System generated locals
   int i__1;

// Local variables
   static int i__;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

// Fortran I/O blocks
   static cilist io___6 = { 0, 0, 0, fmt_50, 0 };
   static cilist io___7 = { 0, 0, 0, fmt_100, 0 };

// PARSER OUTPUT

// PARSER STATE

// I/O VARIABLES

// Parameter adjustments
   --buffer;

// Function Body
L5:
   switch (who + 1) {
      case 1:
         goto L90;
      case 2:
         goto L10;
   }
// 						!SEE WHO TO PROMPT FOR.
L10:
   io___6.ciunit = chan_1.outch;
   s_wsfe(&io___6);
   e_wsfe();
// 						!PROMPT FOR GAME.
L90:
   io___7.ciunit = chan_1.inpch;
   s_rsfe(&io___7);
   do_fio(&c__78, buffer + 1, (ftnlen) 1);
   e_rsfe();
   for (length = 78; length >= 1; --(length)) {
      if (*(unsigned char *)&buffer[length] != ' ') {
         goto L250;
      }
// L200:
   }
   goto L5;
// 						!TRY AGAIN.

// 	check for shell escape here before things are
// 	converted to upper case

// NO SHELL ESCAPE /+TAA+/
L250:
// 250	if (buffer(1) .ne. '!') go to 300
// 	do 275 j=2,length
// 	  sysbuf(j-1:j-1) = buffer(j)
// 275	continue
// 	sysbuf(j:j) = char(0)
// 	call system(sysbuf)
// 	go to 5
// CONVERT TO UPPER CASE
//L300:
   i__1 = length;
   for (i__ = 1; i__ <= i__1; ++i__) {
      if (*(unsigned char *)&buffer[i__] >= 'a' && *(unsigned char *)&buffer[i__] <= 'z') {
         *(unsigned char *)&buffer[i__] = (char)(*(unsigned char *)&buffer[i__] - 32);
      }
// L400:
   }
   if (length == 0) {
      goto L5;
   }
   prsvec_1.prscon = 1;
// 						!RESTART LEX SCAN.
}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp

// PARSE-	TOP LEVEL PARSE ROUTINE

// DECLARATIONS
static Bool lex_(char *, int, int *, int *, Bool, ftnlen);

// THIS ROUTINE DETAILS ON BIT 0 OF PRSFLG

Bool parse_(char *inbuf, int inlnt, Bool vbflag, ftnlen inbuf_len) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   static int x;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
   extern void orphan_(int, int, int, int, int);
   extern int sparse_(int *, int, Bool);
#define prpvec ((int *)&pv_1 + 3)
   extern Bool synmch_(/*int*/);
   static int outbuf[40], outlnt;

// PARSER OUTPUT

// PARSER STATE

// D	DFLAG=IAND(PRSFLG,1).NE.0

// Parameter adjustments
   --inbuf;

// Function Body
   ret_val = false;
// 						!ASSUME FAILS.
   prsvec_1.prsa = 0;
// 						!ZERO OUTPUTS.
   prsvec_1.prsi = 0;
   prsvec_1.prso = 0;

   if (!lex_(inbuf + 1, inlnt, outbuf, &outlnt, vbflag, (ftnlen) 1)) {
      goto L100;
   }
   if ((i__1 = sparse_(outbuf, outlnt, vbflag)) < 0) {
      goto L100;
   } else if (i__1 == 0) {
      goto L200;
   } else {
      goto L300;
   }
// 						!DO SYN SCAN.

// PARSE REQUIRES VALIDATION

L200:
   if (!(vbflag)) {
      goto L350;
   }
// 						!ECHO MODE, FORCE FAIL.
   if (!synmch_(/*x*/)) {
      goto L100;
   }
// 						!DO SYN MATCH.
   if (prsvec_1.prso > 0 && prsvec_1.prso < xsrch_1.xmin) {
      last_1.lastit = prsvec_1.prso;
   }

// SUCCESSFUL PARSE OR SUCCESSFUL VALIDATION

L300:
   ret_val = true;
L350:
   orphan_(c__0, c__0, c__0, c__0, c__0);
// 						!CLEAR ORPHANS.
// D	if(dflag) write(0,*) 'parse good'
// D	IF(DFLAG) PRINT 10,PARSE,PRSA,PRSO,PRSI
// D10	FORMAT(' PARSE RESULTS- ',L7,3I7)
   return ret_val;

// PARSE FAILS, DISALLOW CONTINUATION

L100:
   prsvec_1.prscon = 1;
// D	if(dflag) write(0,*) 'parse failed'
// D	IF(DFLAG) PRINT 10,PARSE,PRSA,PRSO,PRSI
   return ret_val;

}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp

// ORPHAN- SET UP NEW ORPHANS

// DECLARATIONS

void orphan_(int o1, int o2, int o3, int o4, int o5) {

   orphs_2.a = o1;
// 						!SET UP NEW ORPHANS.
   orphs_2.b = o2;
   orphs_2.c__ = o3;
   orphs_2.d__ = o4;
   orphs_2.e = o5;
}

// LEX-	LEXICAL ANALYZER

// THIS ROUTINE DETAILS ON BIT 1 OF PRSFLAG

static Bool lex_(char *inbuf, int inlnt, int * outbuf, int * op, Bool vbflag, ftnlen inbuf_len) {
// Initialized data

   static char dlimit[1 * 9] = "A" "Z" "x" "1" "9" "x" "-" "-" "x";

// System generated locals
   Bool ret_val;

// Local variables
   static int i__;
   static char j[1];
   static int k, j1, j2, cp;
#define orp ((int *)&orphs_1)
#define syn ((int *)&syntax_1)
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
   extern void rspeak_(int);
#define prpvec ((int *)&pv_1 + 3)

// PARSER OUTPUT

// PARSER STATE

// Parameter adjustments
   --outbuf;
   --inbuf;

// Function Body

   for (i__ = 1; i__ <= 40; ++i__) {
// 						!CLEAR OUTPUT BUF.
      outbuf[i__] = 0;
// L100:
   }

// D	DFLAG=IAND(PRSFLG,2).NE.0
   ret_val = false;
// 						!ASSUME LEX FAILS.
   *op = -1;
// 						!OUTPUT PTR.
L50:
   *op += 2;
// 						!ADV OUTPUT PTR.
   cp = 0;
// 						!CHAR PTR=0.

L200:
   if (prsvec_1.prscon > inlnt) {
      goto L1000;
   }
// 						!END OF INPUT?
   *(unsigned char *)j = *(unsigned char *)&inbuf[prsvec_1.prscon];
// 						!NO, GET CHARACTER,
   ++prsvec_1.prscon;
// 						!ADVANCE PTR.
   if (*(unsigned char *)j == '.') {
      goto L1000;
   }
// 						!END OF COMMAND?
   if (*(unsigned char *)j == ',') {
      goto L1000;
   }
// 						!END OF COMMAND?
   if (*(unsigned char *)j == ' ') {
      goto L6000;
   }
// 						!SPACE?
   for (i__ = 1; i__ <= 9; i__ += 3) {
// 						!SCH FOR CHAR.
      if (*(unsigned char *)j >= *(unsigned char *)&dlimit[i__ - 1] && *(unsigned char *)j <= *(unsigned char *)&dlimit[i__]) {
         goto L4000;
      }
// L500:
   }

   if (vbflag) {
      rspeak_(c__601);
   }
// 						!GREEK TO ME, FAIL.
   return ret_val;

// END OF INPUT, SEE IF PARTIAL WORD AVAILABLE.

L1000:
   if (prsvec_1.prscon > inlnt) {
      prsvec_1.prscon = 1;
   }
// 						!FORCE PARSE RESTART.
   if (cp == 0 && *op == 1) {
      return ret_val;
   }
   if (cp == 0) {
      *op += -2;
   }
// 						!ANY LAST WORD?
   ret_val = true;
// D	IF(DFLAG) PRINT 10,CP,OP,PRSCON,(OUTBUF(I),I=1,OP+1)
// D10	FORMAT(' LEX RESULTS- ',3I7/1X,10I7)
   return ret_val;

// LEGITIMATE CHARACTERS: LETTER, DIGIT, OR HYPHEN.

L4000:
   j1 = *(unsigned char *)j - *(unsigned char *)&dlimit[i__ + 1];
// D	IF(DFLAG) PRINT 20,J,J1,CP
// D20	FORMAT(' LEX- CHAR= ',A1,2I7)
   if (cp >= 6) {
      goto L200;
   }
// 						!IGNORE IF TOO MANY CHAR.
   k = *op + cp / 3;
// 						!COMPUTE WORD INDEX.
   switch (cp % 3 + 1) {
      case 1:
         goto L4100;
      case 2:
         goto L4200;
      case 3:
         goto L4300;
   }
// 						!BRANCH ON CHAR.
L4100:
   j2 = j1 * 780;
// 						!CHAR 1... *780
   outbuf[k] = outbuf[k] + j2 + j2;
// 						!*1560 (40 ADDED BELOW).
L4200:
   outbuf[k] += j1 * 39;
// 						!*39 (1 ADDED BELOW).
L4300:
   outbuf[k] += j1;
// 						!*1.
   ++cp;
   goto L200;
// 						!GET NEXT CHAR.

// SPACE

L6000:
   if (cp == 0) {
      goto L200;
   }
// 						!ANY WORD YET?
   goto L50;
// 						!YES, ADV OP.

}

#undef prpvec
#undef objvec
#undef pvec
#undef syn
#undef orp
