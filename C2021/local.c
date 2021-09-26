// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include <stdio.h>
#include <string.h>
#include "extern.h"
#include "common.h"

// Check for user violation
// This routine should be modified if you wish to add system dependent protection against abuse.
// At the moment, play is permitted under all circumstances.
Bool protct(void/*int x*/) {
// System generated locals
   Bool ret_val;

   ret_val = true;
   return ret_val;
}

FILE *OpenInF(const char *File, const char *Mode) { return fopen((File), (Mode)); }

unsigned IOErrs = 0U;

// Read an integer from a line in the index file
int GetWord(FILE *InF) {
   int A = 0, n = fscanf(InF, "%6d\n", &A);
   if (n < 1) IOErrs++;
   return A;
}

// Read a number of integers from separate lines in the index file
void GetWords(int Lim, int *WordP, FILE *InF) {
   while (Lim-- > 0) *WordP++ = GetWord(InF);
}

// Read a number of boolean valies from separate lines in the index file
void GetFlags(int Lim, Bool *FlagP, FILE *InF) {
   while (Lim-- > 0) {
      char Ch = '\0'; int n = fscanf(InF, " %c\n", &Ch);
      if (n < 1 || (Ch != 'T' && Ch != 'F')) IOErrs++;
      *FlagP++ = Ch == 'T';
   }
}

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
