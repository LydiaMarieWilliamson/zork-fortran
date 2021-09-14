/*  -- translated by f2c (version 20190311).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
   integer seedy;
} random_;

#define random_1 random_

/* Subroutine */ int intime_(integer * hours, integer * minutes, integer *
   seconds) {
   extern /* Subroutine */ int itime_(integer *);
   static integer tarray[3];

/* 	CALL GETTIM(HOURS, MINUTES, SECONDS, HUNDREDTHS) */
   itime_(tarray);
   *hours = tarray[0];
   *minutes = tarray[1];
   *seconds = tarray[2];
   return 0;
} /* intime_ */

/* Subroutine */ int inirnd_(integer * seed) {
   random_1.seedy = *seed;
   return 0;
} /* inirnd_ */

integer rnd_(integer * maxval) {
/* System generated locals */
   integer ret_val;

   random_1.seedy = random_1.seedy * 1059 + 17 & 2147483647;
   ret_val = random_1.seedy / 100 % *maxval;
   return ret_val;
} /* rnd_ */

/* Subroutine */ int exit_(void) {
/* Builtin functions */
/* Subroutine */ int s_stop(char *, ftnlen);

/* NO "CALL EXIT" HERE */
   s_stop("", (ftnlen) 0);
   return 0;
} /* exit_ */
