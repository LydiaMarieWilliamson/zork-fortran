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

int DoUio(size_t N, void *X, size_t dN) {
   int do_uio(int *, char *, SizeT);
   int n = (int)N; char *x = (char *)X; SizeT dn = (SizeT)dN;
   return do_uio(&n, x, dn);
}

int CompS(char *A, char *B, size_t N) {
   int s_cmp(char *, char *, SizeT, SizeT);
   SizeT n = (SizeT)N;
   return s_cmp(A, B, n, n);
}

void StopS(char *A, size_t N) {
   int /* Subroutine */ s_stop(char *, SizeT);
   SizeT n = (size_t)N;
   (void)s_stop(A, n);
}

int OpenF(int Unit, char *File, char *Sta, char *Acc, char *Fm, int Rl) {
   typedef struct {
      Bit _Err;
      Int _Unit;
      char *_File;
      SizeT _FileN;
      char *_Sta;
      char *_Acc;
      char *_Fm;
      Int _Rl;
      char *_Blank;
   } olist;
   int f_open(olist *);
   Int N = File == NULL? 0: strlen(File);
   olist L = (olist){ _Err: (Bit)true, _Unit: (Int)Unit, _File: File, _FileN: N, _Sta: Sta, _Acc: Acc, _Fm: Fm, _Rl: (Int)Rl, _Blank: NULL };
   return f_open(&L);
}

int CloseF(int Unit) {
   typedef struct {
      Bit _Err;
      Int _Unit;
      char *_Sta;
   } cllist;
   int f_clos(cllist *);
   cllist L = (cllist){ _Err: (Bit)false, _Unit: (Int)Unit, _Sta: NULL };
   return f_clos(&L);
}

typedef struct {
   Bit _Err;
   Int _Unit;
   Bit _End;
   char *_Format;
   Int _Rec;
} cilist;

int BegInDU(int Unit, int Rec) {
   int s_rdue(cilist *);
   cilist L = (cilist){_Err: (Bit)false, _Unit: (Int)Unit, _End: (Bit)false, _Format: NULL, _Rec: (Int)Rec};
   return s_rdue(&L);
}

int EndInDU(void) {
   int e_rdue(void);
   return e_rdue();
}

int BegInSF(int Unit, char *Format) {
   int s_rsfe(cilist *);
   cilist L = (cilist){_Err: (Bit)false, _Unit: (Int)Unit, _End: (Bit)false, _Format: Format, _Rec: (Int)0};
   return s_rsfe(&L);
}

int EndInSF(void) {
   int e_rsfe(void);
   return e_rsfe();
}

int BegInSU(int Unit) {
   int s_rsue(cilist *);
   cilist L = (cilist){_Err: (Bit)false, _Unit: (Int)Unit, _End: (Bit)false, _Format: NULL, _Rec: (Int)0};
   return s_rsue(&L);
}

int EndInSU(void) {
   int e_rsue(void);
   return e_rsue();
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

int BegExSU(int Unit) {
   int s_wsue(cilist *);
   cilist L = (cilist){_Err: (Bit)false, _Unit: (Int)Unit, _End: (Bit)false, _Format: NULL, _Rec: (Int)0};
   return s_wsue(&L);
}

int EndExSU(void) {
   int e_wsue(void);
   return e_wsue();
}
