// Based on f2c.h: The Standard Fortran to C header file.
#include <stdbool.h>
#include <stdlib.h>

// These types will be nativized, after it's made OK to do so.
typedef long Bool; // Logical.

#define abs(X)		((X) >= 0? (X): -(X))
#define min(A, B)	((A) <= (B)? (A): (B))
#define max(A, B)	((A) >= (B)? (A): (B))

// A wrapper for the built-in functions defined in the f2c library.
int DoFio(size_t N, void *X, size_t dN);
int DoUio(size_t N, void *X, size_t dN);
int CompS(char *A, char *B, size_t N);
void StopS(char *A, size_t N);
int OpenF(int Unit, char *File, char *Sta, char *Acc, char *Fm, int Rl);
int CloseF(int Unit);
int BegInDU(int Unit, char *Format, int Rec);
int EndInDU(void);
int BegInSF(int Unit, char *Format, int Rec);
int EndInSF(void);
int BegInSU(int Unit, char *Format, int Rec);
int EndInSU(void);
int BegExSF(int Unit, char *Format, int Rec);
int EndExSF(void);
int BegExSU(int Unit, char *Format, int Rec);
int EndExSU(void);
