// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).

// The functions for dungeon.

// The remnant of f2c.h (begin)
// Assumes C99, which is now (well into the 21st century) POSIX.
// That means: boolean types, function prototypes, ‟rb” and ‟wb” for fopen(), ‟const”, ‟void”, etc.
#include <stdbool.h>
#include <stdlib.h> // For abs().
#include <stdio.h>

// This type will be nativized to ‟bool”, after it's made OK to do so.
typedef int Bool; // Logical.

#define min(A, B)	((A) <= (B)? (A): (B))
#define max(A, B)	((A) >= (B)? (A): (B))

// local.c:
Bool protct(void/*int*/);
Bool wizard(void);

// The remnant of f2c.h (begin)
extern unsigned IOErrs;
FILE *OpenInF(const char *File, const char *Mode);
int GetWord(FILE *InF);
void GetWords(int Lim, int *WordP, FILE *InF);
void GetFlags(int Lim, Bool *FlagP, FILE *InF);

void more_init(void);
char *more_input(char *, size_t);
void more_output(const char *, ...);
// The remnant of f2c.h (end)

// actors.c:
Bool aappli(int);
void thiefd(void);

// ballop.c:
Bool ballop(int);

// clockr.c:
void cevapp(int);

// demons.c:
void fightd(void);
int blow(int, int, int, Bool, int);
void swordd(void);

// dgame.c:
void game_(void);

// dinit.c:
Bool init(void/*int*/);

// dso1.c:
void princr(Bool, int);
void invent(int);
void princo(int, int);

// dso2.c:
Bool moveto(int, int);
void score(Bool);
void scrupd(int);

// dso3.c:
Bool findxt(int, int);
int fwim(int, int, int, int, int, Bool);
Bool yesno(int, int, int);

// dso4.c:
int robadv(int, int, int, int);
int robrm(int, int, int, int, int);
Bool winnin(int, int);
int fights(int, Bool);
int vilstr(int);

// dso5.c:
int gttime(void);
Bool opncls(int, int, int);
Bool lit(int);
int weight(int, int, int);

// dso6.c:
Bool ghere(int, int);
int mrhere(int);

// dso7.c:
void encryp(const char *, char *);
void cpgoto(int);
void cpinfo(int, int);

// dsub.c:
void rspeak(int);
void rspsub(int, int);
void rspsb2(int, int, int);
Bool objact(void/*int*/);
void bug(int, int);
void newsta(int, int, int, int, int);
Bool qhere(int, int);
Bool qempty(int);
void jigsup(int);
int oactor(int);
Bool prob(int, int);
Bool rmdesc(int);
Bool rappli(int);

// dverb1.c:
Bool take(Bool);
Bool drop(void/*Bool*/);
Bool put(void/*Bool*/);
void valuac(int);

// dverb2.c:
void savegm(void);
void rstrgm(void);
Bool walk(void/*int*/);

// gdt.c:
void gdt(void);

// lightp.c:
Bool lightp(int);

// nobjs.c:
Bool nobjs(int/*, int*/);

// np1.c:
int sparse(const int *, int, Bool);

// np2.c:
int getobj(int, int, int);
int schlst(int, int, int, int, int, int);

// np3.c:
Bool synmch(void/*int*/);

// np.c:
void rdline(char *, size_t, int);
Bool parse(char *, Bool);
void orphan(int, int, int, int, int);

// nrooms.c:
Bool rappl2(int);

// objcts.c:
Bool oappli(int, int);

// rooms.c:
Bool rappl1(int);

// rtim.c:
void intime(int *, int *, int *);
void inirnd(int);
int rnd(int);
void exit_(void);

// sobjs.c:
Bool sobjs(int, int);

// sverbs.c:
Bool sverbs(int);

// verbs.c:
Bool vappli(int);
Bool clockd(void/*int*/);

// villns.c:
Bool trollp(void/*int*/);
Bool cyclop(void/*int*/);
Bool thiefp(void/*int*/);
