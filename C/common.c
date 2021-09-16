#include "F2C.h"

#if 0
// Already defined in blkdata.c:
// buzvoc:
struct {
   int bvoc[20];
} buzvoc_;

// prpvoc:
struct {
   int pvoc[45];
} prpvoc_;

// dirvoc:
struct {
   int dvoc[75];
} dirvoc_;

// adjvoc:
union {
   struct {
      int avoc1[184], avoc2[114], avoc3[106], avocnd;
   } _1;
   struct {
      double eqv_pad[225];
   } _2;
} adjvoc_;

// vrbvoc:
union {
   struct {
      int vvoc1[92], vvoc1a[108], vvoc1b[38], vvoc2[104], vvoc3[136], vvoc4[116], vvoc5[134], vvoc6[117], vvoc7[89], vvocnd;
   } _1;
   struct {
      double eqv_pad[475];
   } _2;
} vrbvoc_;

// objvoc:
union {
   struct {
      int ovoc1[159], ovoc2[144], ovoc3[150], ovoc4[128], ovoc5[111], ovoc6[104], ovoc6a[97], ovoc7[127], ovocnd;
   } _1;
   struct {
      double eqv_pad[525];
   } _2;
} objvoc_;
#endif

#if 0
// Already defined in dmain.c:
// synflg:
struct {
   int sdir, sind, sstd, sflip, sdriv, svmask;
} synflg_;

// objflg:
struct {
   int vabit, vrbit, vtbit, vcbit, vebit, vfbit, vpmask;
} objflg_;

// screen:
struct {
   int fromdr, scolrm, scolac, scoldr[8], scolwl[12];
} screen_;

// puzzle:
struct {
   int cpdr[16], cpwl[8], cpvec[64];
} puzzle_;

// vers:
struct {
   int vmaj, vmin;
   char vedit[1];
} vers_;

// bats:
struct {
   int batdrp[9];
} bats_;

// hyper:
struct {
   int hfactr;
} hyper_;

// rflag:
struct {
   int rseen, rlight, rland, rwater, rair, rsacrd, rfill, rmung, rbuck, rhouse, rnwall, rend;
} rflag_;

// rindex:
struct {
   int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant, cpout, cpuzz;
} rindex_;

// xpars:
struct {
   int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, xcond, xdoor, xlflag;
} xpars_;

// xsrch:
struct {
   int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, xwest;
} xsrch_;

// oflags:
struct {
   int visibt, readbt, takebt, doorbt, tranbt, foodbt, ndscbt, drnkbt, contbt, litebt, victbt, burnbt, flambt, toolbt, turnbt, onbt, findbt, slepbt, scrdbt, tiebt, clmbbt, actrbt, weapbt, fitebt, villbt, stagbt, trybt, nochbt, openbt, tchbt, vehbt, schbt;
} oflags_;

// oindex:
struct {
   int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, book, candl, match, tube, putty, wrenc, screw, cyclo, chali, thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

// cindex:
struct {
   int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

// aflags:
struct {
   int astag;
} aflags_;

// aindex:
struct {
   int player, arobot, amastr;
} aindex_;

// vindex:
struct {
   int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw, eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, trntow;
} vindex_;
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
