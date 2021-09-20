// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "extern.h"
#include "common.h"

static Bool lex(char *, int, int *, int *, Bool/*, size_t*/);

// RDLINE-	READ INPUT LINE
void rdline(char *buffer, int length, int who, size_t buffer_unit) {
// System generated locals
   int i__1;

// Local variables
   int i;

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
   BegExSF(chan_1.outch, /*50*/"(\002 >\002,$)", 0);
   EndExSF();
// 						!PROMPT FOR GAME.
L90:
   BegInSF(chan_1.inpch, /*100*/"(78a1)", 0);
   DoFio(78, buffer + 1, buffer_unit);
   EndInSF();
   for (length = 78; length >= 1; --(length)) {
      if (buffer[length] != ' ') {
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
   for (i = 1; i <= i__1; ++i) {
      if (buffer[i] >= 'a' && buffer[i] <= 'z') {
         buffer[i] = (char)(buffer[i] - 32);
      }
// L400:
   }
   if (length == 0) {
      goto L5;
   }
   prsvec_1.prscon = 1;
// 						!RESTART LEX SCAN.
}

// PARSE-	TOP LEVEL PARSE ROUTINE
// THIS ROUTINE DETAILS ON BIT 0 OF PRSFLG
Bool parse(char *inbuf, int inlnt, Bool vbflag/*, size_t inbuf_unit*/) {
// System generated locals
   int i__1;
   Bool ret_val;

// Local variables
   int x;
   int outbuf[40], outlnt;

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

   if (!lex(inbuf + 1, inlnt, outbuf, &outlnt, vbflag/*, inbuf_unit*/)) {
      goto L100;
   }
   if ((i__1 = sparse(outbuf, outlnt, vbflag)) < 0) {
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
   if (!synmch(/*x*/)) {
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
   orphan(0, 0, 0, 0, 0);
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

// ORPHAN- SET UP NEW ORPHANS
void orphan(int o1, int o2, int o3, int o4, int o5) {

   orphs_1.oflag = o1;
// 						!SET UP NEW ORPHANS.
   orphs_1.oact = o2;
   orphs_1.oslot = o3;
   orphs_1.oprep = o4;
   orphs_1.oname = o5;
}

// LEX-	LEXICAL ANALYZER
// THIS ROUTINE DETAILS ON BIT 1 OF PRSFLAG
static Bool lex(char *inbuf, int inlnt, int *outbuf, int *op, Bool vbflag/*, size_t inbuf_unit*/) {
// Initialized data
   static const char dlimit[1 * 9] = "A" "Z" "x" "1" "9" "x" "-" "-" "x";

// System generated locals
   Bool ret_val;

// Local variables
   int i;
   char j;
   int k, j1, j2, cp;

// Parameter adjustments
   --outbuf;
   --inbuf;

// Function Body

   for (i = 1; i <= 40; ++i) {
// 						!CLEAR OUTPUT BUF.
      outbuf[i] = 0;
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
   j = inbuf[prsvec_1.prscon];
// 						!NO, GET CHARACTER,
   ++prsvec_1.prscon;
// 						!ADVANCE PTR.
   if (j == '.') {
      goto L1000;
   }
// 						!END OF COMMAND?
   if (j == ',') {
      goto L1000;
   }
// 						!END OF COMMAND?
   if (j == ' ') {
      goto L6000;
   }
// 						!SPACE?
   for (i = 1; i <= 9; i += 3) {
// 						!SCH FOR CHAR.
      if (j >= dlimit[i - 1] && j <= dlimit[i]) {
         goto L4000;
      }
// L500:
   }

   if (vbflag) {
      rspeak(601);
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
   j1 = j - dlimit[i + 1];
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
