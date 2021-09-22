// Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
// All rights reserved, commercial usage strictly prohibited.
// Written by R. M. Supnik.
// Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
#include "F2C.h"
#include "common.h"

#if 0
// Already defined in blkdata.c:
//	buzvoc, prpvoc, dirvoc, adjvoc, vrbvoc, objvoc
// Already defined in dmain.c:
//	screen, puzzle, vers, bats, hyper, rindex,
//	xpars, xsrch, oindex, cindex, aflags, aindex, vindex
// Already redefined and declared as enum types in common.h:
//	rflag, oflags, synflg, objflg
#endif

// Unlisted:
// common /star/
// int mbase, strbit;
struct starCB star;

// common /time/
// int pltime, shour, smin, ssec;
struct timeCB time_;

// common /random/
// int seedy;
struct randomCB random_;

// parser.h:
// common /prsvec/
// int prsa, prsi, prso;
// Bool prswon;
// int prscon;
struct prsvecCB prsvec;

// common /orphs/
// int oflag, oact, oslot, oprep, oname;
struct orphsCB orphs;

// common /last/
// int lastit;
struct lastCB last;

// common /pv/
// int act, o1, o2, p1, p2;
// int act, o1, o2; char p1[6], p2[6]; // In sverbs.c, only.
union pvCB pv;

// common /syntax/
// int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;
struct syntaxCB syntax;

// gamestat.h:
// common /play/
// int winner, here;
// Bool telflg;
struct playCB play;

// rooms.h:
// common /rooms/
// int rlnt, rdesc2, rdesc1[200], rexit[200], ractio[200], rval[200], rflag[200];
struct roomsCB rooms;

// objects.h:
// common /objcts/
// int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220], oroom[220], oadv[220], ocan[220], oread[220];
struct objctsCB objcts;

// common /oroom2/
// int r2lnt, oroom2[20], rroom2[20];
struct oroom2CB oroom2_;

// clock.h:
// common /cevent/
// int clnt, ctick[25], cactio[25];
// Bool cflag[25];
struct ceventCB cevent;

// advers.h:
// common /advs/
// int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[4], aflag[4];
struct advsCB advs;

// flags.h:
// common /findex/
// Bool trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
// int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, pnumb, acell, dcell, cphere;
struct findexCB findex;

// debug.h:
// common /debug/
// int dbgflg, prsflg, gdtflg;
struct debugCB debug;

// villians.h:
// common /hack/
// int thfpos;
// Bool thfflg, thfact, swdact;
// int swdsta;
struct hackCB hack;

// common /vill/
// int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
struct villCB vill;

// state.h:
// common /state/
// int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, egscor, egmxsc;
struct stateCB state;

// curxt.h:
// common /curxt/
// int xtype, xroom1, xstrng, xactio, xobj;
struct curxtCB curxt;

// io.h:
// common /input/
// int inlnt;
// char inbuf[78];
struct inputCB input;

// common /chan/
// int inpch, outch, dbch;
struct chanCB chan;

// mindex.h:
// common /rmsg/
// int mlnt, rtext[1820];
struct rmsgCB rmsg;

// exits.h:
// common /exits/
// int xlnt, travel[900];
struct exitsCB exits;