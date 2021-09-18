// parser.h:

// PARSER OUTPUT

// common /prsvec/
extern struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;
#define prsvec_1 prsvec_

// PARSER STATE

// common /orphs/
extern struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;
#define orphs_1 orphs_
// int orp[5]; // equivalence(orphs_1.oflag, orp);
#define orp ((int *)&orphs_1)

// common /last/
extern struct {
   int lastit;
} last_;
#define last_1 last_

// common /pv/
extern union {
   struct {
      int act, o1, o2, p1, p2;
   } _1;
   struct { // Used only in sverbs.c, and only for p1[] and p2[].
      int act, o1, o2;
      char p1[6], p2[6];
   } _2;
} pv_;
#define pv_1 (pv_._1)
// int objvec[2]; // equivalence(objvec[1], pv_1.o1);
#define objvec ((int *)&pv_1 + 1)
// int prpvec[2]; // equivalence(prpvec[1], pv_1.p1);
#define prpvec ((int *)&pv_1 + 3)
// int pvec[5]; // equivalence(pvec, pv_1.act);
#define pvec ((int *)&pv_1)
#define pv_2 (pv_._2)

// common /syntax/
extern struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2;
   int iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;
#define syntax_1 syntax_
// int syn[11]; // equivalence(syntax_1.vflag, syn);
#define syn ((int *)&syntax_1)

// common /synflg/
extern struct synflg_1_ {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;
#define synflg_1 synflg_

// common /objflg/
extern struct objflg_1_ {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;
#define objflg_1 objflg_
