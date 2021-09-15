#ifndef OnceOnlyF2C_h
#define OnceOnlyF2C_h

// Based on f2c.h: The Standard Fortran to C header file.
#include <stdbool.h>

// These types will be nativized, after it's made OK to do so.
typedef long Bool; // Logical.
typedef int Void; // Subroutine.

// I/O stuff.
#ifdef f2c_i2
// for -i2
typedef short flag, ftnlen, ftnint;
#else
typedef long flag, ftnlen, ftnint;
#endif

// external read, write
typedef struct {
   flag cierr;
   ftnint ciunit;
   flag ciend;
   char *cifmt;
   ftnint cirec;
} cilist;

// open
typedef struct {
   flag oerr;
   ftnint ounit;
   char *ofnm;
   ftnlen ofnmlen;
   char *osta;
   char *oacc;
   char *ofm;
   ftnint orl;
   char *oblnk;
} olist;

// close
typedef struct {
   flag cerr;
   ftnint cunit;
   char *csta;
} cllist;

#define abs(X)		((X) >= 0? (X): -(X))
#define min(A, B)	((A) <= (B)? (A): (B))
#define max(A, B)	((A) >= (B)? (A): (B))

// Built-in functions (defined in the f2c library):
int do_fio(int *, char *, ftnlen);
int do_uio(int *, char *, ftnlen);
int e_rdue(void);
int e_rsfe(void);
int e_rsue(void);
int e_wsfe(void);
int e_wsue(void);
int f_clos(cllist *);
int f_open(olist *);
int s_cmp(char *, char *, ftnlen, ftnlen);
int s_rdue(cilist *);
int s_rsfe(cilist *);
int s_rsue(cilist *);
int s_wsfe(cilist *);
int s_wsue(cilist *);
Void s_stop(char *, ftnlen);

#endif // OnceOnly
