#include "F2C.h"

#if 0
// Already defined in blkdata.c:
//	buzvoc, prpvoc, dirvoc, adjvoc, vrbvoc, objvoc
#endif

#if 0
// Already defined in dmain.c:
//	synflg, objflg, screen, puzzle, vers, bats, hyper, rflag, rindex,
//	xpars, xsrch, oflags, oindex, cindex, aflags, aindex, vindex
#endif

// advs:
struct {
   int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
} advs_;

// cevent:
struct {
   int clnt, ctick[25], cactio[25];
   Bool cflag[25];
} cevent_;

// chan:
struct {
   int inpch, outch, dbch;
} chan_;

// curxt:
struct {
   int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

// debug:
struct {
   int dbgflg, prsflg, gdtflg;
} debug_;

// exits:
struct {
   int xlnt, travel[900];
} exits_;

// findex:
struct {
   Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
   int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
} findex_;

// hack:
struct {
   int thfpos;
   Bool thfflg, thfact, swdact;
   int swdsta;
} hack_;

// input:
struct {
   int inlnt;
   char inbuf[78];
} input_;

// last:
struct {
   int lastit;
} last_;

// objcts:
struct {
   int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

// oroom2:
struct {
   int r2lnt, oroom2[20], rroom2[20];
} oroom2_;

// orphs:
struct {
   int oflag, oact, oslot, oprep, oname;
} orphs_;

// play:
struct {
   int winner, here;
   Bool telflg;
} play_;

// prsvec:
struct {
   int prsa, prsi, prso;
   Bool prswon;
   int prscon;
} prsvec_;

// pv:
struct {
   int act, o1, o2, p1, p2;
} pv_;

// random:
struct {
   int seedy;
} random_;

// rmsg:
struct {
   int mlnt, rtext[1820];
} rmsg_;

// rooms:
struct {
   int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
} rooms_;

// star:
struct {
   int mbase, strbit;
} star_;

// state:
struct {
   int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
} state_;

// syntax:
struct {
   int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
} syntax_;

// time:
struct {
   int pltime, shour, smin, ssec;
} time_;

// vill:
struct {
   int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;
