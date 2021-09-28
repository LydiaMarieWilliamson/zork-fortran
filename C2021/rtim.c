// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
// C99 is now locked in and assumed.
#include <time.h> // For time() and localtime().
#include <stdlib.h> // For exit() and rand().
#include "extern.h"
#include "common.h"

//(@) Cheat, cheat! We make a ‟fallback” for ‟itime” using a hack from the other repository.
static void itime(int HMS[3]) {
   time_t Now; time(&Now);
   struct tm *HereNow = localtime(&Now);
   HMS[0] = HereNow->tm_hour, HMS[1] = HereNow->tm_min, HMS[2] = HereNow->tm_sec;
}

void intime(int *hours, int *minutes, int *seconds) {
   int tarray[3];

// gettim(*hours, *minutes, *seconds, hundredths);
   itime(tarray);
   *hours = tarray[0];
   *minutes = tarray[1];
   *seconds = tarray[2];
}

// common /random/
static int seedy;

void inirnd(int seed) {
#if 0
   seedy = seed;
#else
   srand((unsigned)(seedy = seed));
#endif
}

int rnd(int maxval) {
#if 0
   seedy = seedy * 1059 + 17 & 2147483647;
   return seedy / 100 % maxval;
#else
   return rand() % maxval;
#endif
}

void exit_(void) {
// NO "CALL EXIT" HERE
// stop(); //F
   fprintf(stderr, "End of game.\n");
   exit(0);
}
