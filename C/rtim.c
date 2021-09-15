#include "F2C.h"

// Common Block Declarations

extern struct {
   int seedy;
} random_;

#define random_1 random_

#if 1
//(@) Cheat, cheat! We make a ‟fallback” using a hack from the other repository.
#include <time.h>
void ITime_(int HMS[3]) {
   time_t Now; time(&Now);
   struct tm *HereNow = localtime(&Now);
   HMS[0] = HereNow->tm_hour, HMS[1] = HereNow->tm_min, HMS[2] = HereNow->tm_sec;
}
#else
extern Void itime_(int *);
#   define ITime_(HMS) (itime_(HMS))
#endif

Void intime_(int * hours, int * minutes, int * seconds) {
   static int tarray[3];

// 	CALL GETTIM(HOURS, MINUTES, SECONDS, HUNDREDTHS)
   ITime_(tarray);
   *hours = tarray[0];
   *minutes = tarray[1];
   *seconds = tarray[2];
   return 0;
}

Void inirnd_(int * seed) {
   random_1.seedy = *seed;
   return 0;
}

int rnd_(int * maxval) {
// System generated locals
   int ret_val;

   random_1.seedy = random_1.seedy * 1059 + 17 & 2147483647;
   ret_val = random_1.seedy / 100 % *maxval;
   return ret_val;
}

Void exit_(void) {
// NO "CALL EXIT" HERE
   s_stop("", (ftnlen) 0);
   return 0;
}
