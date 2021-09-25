// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include <string.h>

// A wrapper for the built-in functions defined in the f2c library.
// I/O stuff.
#ifdef f2c_i2
// for -i2
typedef short Bit, SizeT, Int;
#else
typedef long Bit, SizeT, Int;
#endif

int DoFio(size_t N, void *X, size_t dN) {
   int do_fio(int *, char *, SizeT);
   int n = (int)N; char *x = (char *)X; SizeT dn = (SizeT)dN;
   return do_fio(&n, x, dn);
}

typedef struct {
   Bit _Err;
   Int _Unit;
   Bit _End;
   char *_Format;
   Int _Rec;
} cilist;

int BegInSF(int Unit, char *Format) {
   int s_rsfe(cilist *);
   cilist L = (cilist){_Err: (Bit)false, _Unit: (Int)Unit, _End: (Bit)false, _Format: Format, _Rec: (Int)0};
   return s_rsfe(&L);
}

int EndInSF(void) {
   int e_rsfe(void);
   return e_rsfe();
}

int BegExSF(int Unit, char *Format) {
   int s_wsfe(cilist *);
   cilist L = (cilist){_Err: (Bit)false, _Unit: (Int)Unit, _End: (Bit)false, _Format: Format, _Rec: (Int)0};
   return s_wsfe(&L);
}

int EndExSF(void) {
   int e_wsfe(void);
   return e_wsfe();
}
