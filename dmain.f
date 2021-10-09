C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Main program
	PROGRAM DUNGEO
C
C DUNGEON, PAGE 3
C
C 1) INITIALIZE DATA STRUCTURES
C 2) PLAY GAME
C
	IMPLICIT INTEGER (A-Z)
	LOGICAL INIT

	IF(INIT()) CALL GAME
C						!IF INIT, PLAY GAME.
	CALL EXIT
	END
C						!DONE
	BLOCK DATA
	IMPLICIT INTEGER (A-Z)
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'screen.h'
	include 'puzzle.h'
C
C MISCELLANEOUS VARIABLES
C
	CHARACTER VEDIT
	COMMON /STAR/ MBASE,STRBIT
	COMMON /VERS/ VMAJ,VMIN,VEDIT
	COMMON /BATS/ BATDRP(9)
	include 'io.h'
	include 'debug.h'
	COMMON /HYPER/ HFACTR
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'exits.h'
	include 'curxt.h'
	include 'xpars.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'clock.h'

	include 'villians.h'
	include 'advers.h'
	include 'verbs.h'
	include 'flags.h'
C DUNGEON, PAGE 2
C
C DATA STATEMENTS FOR CONSTANT ARRAYS
C
	DATA VMAJ/2/,VMIN/8/,VEDIT/'A'/
C
	DATA BATDRP/66,67,68,69,70,71,72,65,73/
C
	DATA HFACTR/500/
C
	DATA SDIR/Z'4000'/,SIND/Z'2000'/,SSTD/Z'1000'/,
     &SFLIP/Z'800'/,SDRIV/Z'400'/,SVMASK/Z'1FF'/
	DATA VABIT/Z'4000'/,VRBIT/Z'2000'/,VTBIT/Z'1000'/,
     &VCBIT/Z'800'/,VEBIT/Z'400'/,VFBIT/Z'200'/,
     &VPMASK/Z'1FF'/
C
	DATA SCOLDR/O'2000',153,O'12000',154,O'6000',152,O'16000',151/
	DATA SCOLWL/151,207,O'6000',152,208,O'16000',
     &153,206,O'12000',154,205,O'2000'/
C
	DATA CPDR/O'2000',-8,O'4000',-7,O'6000',1,O'10000',9,
     &O'12000',8,O'14000',7,O'16000',-1,O'20000',-9/
	DATA CPWL/205,-8,206,8,207,1,208,-1/
	DATA CPVEC/1,1,1,1,1,1,1,1,
     &1,0,-1,0,0,-1,0,1,
     &1,-1,0,1,0,-2,0,1,
     &1,0,0,0,0,1,0,1,
     &1,-3,0,0,-1,-1,0,1,
     &1,0,0,-1,0,0,0,1,
     &1,1,1,0,0,0,1,1,
     &1,1,1,1,1,1,1,1/
C
	DATA RSEEN/Z'8000'/,RLIGHT/Z'4000'/,RLAND/Z'2000'/
	DATA RWATER/Z'1000'/,RAIR/Z'800'/,RSACRD/Z'400'/,
     &RFILL/Z'200'/
	DATA RMUNG/Z'100'/,RBUCK/Z'80'/,RHOUSE/Z'40'/,
     &RNWALL/Z'20'/,REND/Z'10'/
C
	DATA WHOUS/2/,LROOM/8/,CELLA/9/
	DATA MTROL/10/,MAZE1/11/
	DATA MGRAT/25/,MAZ15/30/
	DATA FORE1/31/,FORE3/33/,CLEAR/36/,RESER/40/
	DATA STREA/42/,EGYPT/44/,ECHOR/49/
	DATA TSHAF/61/
	DATA BSHAF/76/,MMACH/77/,DOME/79/,MTORC/80/
	DATA CAROU/83/
	DATA RIDDL/91/,LLD2/94/,TEMP1/96/,TEMP2/97/,MAINT/100/
	DATA MCYCL/101/,BLROO/102/,TREAS/103/,RIVR1/107/,RIVR2/108/
	DATA 	RIVR3/109/
	DATA RIVR4/112/,RIVR5/113/,FCHMP/114/,MBARR/119/,FALLS/120/
	DATA MRAIN/121/,POG/122/,VLBOT/126/,VAIR1/127/,VAIR2/128/
	DATA 	VAIR3/129/,VAIR4/130/
	DATA LEDG2/131/,LEDG3/132/,LEDG4/133/,MSAFE/135/,CAGER/140/
	DATA CAGED/141/,TWELL/142/,BWELL/143/,ALICE/144/,ALISM/145/
	DATA 	ALITR/146/,MTREE/147/,BKENT/148/
	DATA BKVW/151/,BKTWI/153/,BKVAU/154/,BKBOX/155/
	DATA	CRYPT/157/,TSTRS/158/,MRANT/159/
	DATA MREYE/160/,MRA/161/,MRB/162/,MRC/163/,MRG/164/
	DATA	MRD/165/,FDOOR/166/,MRAE/167/
	DATA MRCE/171/,MRCW/172/,MRGE/173/,MRGW/174/,MRDW/176/
	DATA	INMIR/177/,SCORR/179/
	DATA NCORR/182/,PARAP/183/,CELL/184/,PCELL/185/,NCELL/186/
	DATA	CPANT/188/,CPOUT/189/
	DATA CPUZZ/190/
C
	DATA XMIN/O'2000'/,XMAX/O'40000'/,XUP/O'22000'/,XDOWN/O'24000'/
	DATA XNORTH/O'2000'/,XSOUTH/O'12000'/,XENTER/O'32000'/,
     &XEXIT/O'34000'/
	DATA XEAST/O'6000'/,XWEST/O'16000'/
	DATA XRMASK/Z'FF'/,XDMASK/Z'7C00'/,XFMASK/Z'03'/
	DATA XFSHFT/Z'100'/,XASHFT/Z'100'/
	DATA XELNT/1,2,3,3/
	DATA XNORM/1/,XNO/2/,XCOND/3/,XDOOR/4/,XLFLAG/Z'8000'/
C
	DATA VISIBT/Z'8000'/,READBT/Z'4000'/,TAKEBT/Z'2000'/,
     &DOORBT/Z'1000'/,TRANBT/Z'800'/,FOODBT/Z'400'/,
     &NDSCBT/Z'200'/,DRNKBT/Z'100'/, CONTBT/Z'80'/,
     &LITEBT/Z'40'/,VICTBT/Z'20'/,BURNBT/Z'10'/,
     &FLAMBT/Z'8'/,TOOLBT/Z'4'/,TURNBT/Z'2'/,ONBT/Z'1'/
C
	DATA FINDBT/Z'8000'/,SLEPBT/Z'4000'/,SCRDBT/Z'2000'/,
     &TIEBT/Z'1000'/, CLMBBT/Z'800'/,ACTRBT/Z'400'/,
     &WEAPBT/Z'200'/,FITEBT/Z'100'/, VILLBT/Z'80'/,
     &STAGBT/Z'40'/,TRYBT/Z'20'/,NOCHBT/Z'10'/,
     &OPENBT/Z'8'/,TCHBT/Z'4'/,VEHBT/Z'2'/,SCHBT/Z'1'/
C
	DATA GARLI/2/,FOOD/3/,GUNK/4/,COAL/5/,MACHI/7/,DIAMO/8/
	DATA	TCASE/9/,BOTTL/10/
	DATA WATER/11/,ROPE/12/,KNIFE/13/,SWORD/14/,LAMP/15/,BLAMP/16/
	DATA	RUG/17/,LEAVE/18/,TROLL/19/,AXE/20/
	DATA RKNIF/21/,KEYS/23/,BAR/26/,ICE/30/
	DATA COFFI/33/,TORCH/34/,TBASK/35/,FBASK/36/,IRBOX/39/
	DATA GHOST/42/,TRUNK/45/,BELL/46/,BOOK/47/,CANDL/48/
	DATA MATCH/51/,TUBE/54/,PUTTY/55/,WRENC/56/,SCREW/57/
	DATA	CYCLO/58/,CHALI/59/
	DATA THIEF/61/,STILL/62/,WINDO/63/,GRATE/65/,DOOR/66/
	DATA HPOLE/71/,RBUTT/79/,LEAK/78/,RAILI/75/
	DATA POT/85/,STATU/86/,IBOAT/87/,DBOAT/88/,PUMP/89/,RBOAT/90/
	DATA STICK/92/,BUOY/94/,SHOVE/96/,GUANO/97/,BALLO/98/,RECEP/99/
	DATA BROPE/101/,HOOK1/102/,HOOK2/103/,SAFE/105/,SSLOT/107/
	DATA	BRICK/109/,FUSE/110/
	DATA GNOME/111/,BLABE/112/,DBALL/113/,TOMB/119/
	DATA LCASE/123/,CAGE/124/,RCAGE/125/,SPHER/126/,SQBUT/127/
	DATA FLASK/132/,POOL/133/,SAFFR/134/,BUCKE/137/,ORICE/139/
	DATA	ECAKE/138/,RDICE/140/
	DATA BLICE/141/,ROBOT/142/,FTREE/145/,BILLS/148/,PORTR/149/
	DATA SCOL/151/,ZGNOM/152/,EGG/154/,BEGG/155/,BAUBL/156/
	DATA	CANAR/157/,BCANA/158/,YLWAL/159/
	DATA RDWAL/161/,PINDR/164/
	DATA RBEAM/171/,ODOOR/172/,QDOOR/173/,CDOOR/175/
	DATA	NUM1/178/
	DATA NUM8/185/,WARNI/186/,CSLIT/187/,GCARD/188/,STLDR/189/
	DATA ITOBJ/192/,OPLAY/193/,EVERY/194/
	DATA	VALUA/195/,SAILO/196/,TEETH/197/,WALL/198/
	DATA HANDS/200/,LUNGS/201/,AVIAT/202/
	DATA WNORT/205/,GWATE/209/,MASTER/215/
C
	DATA CEVCUR/1/,CEVMNT/2/,CEVLNT/3/,CEVMAT/4/,
     &CEVCND/5/,CEVBAL/6/,CEVBRN/7/,CEVFUS/8/,
     &CEVLED/9/,CEVSAF/10/,CEVVLG/11/,CEVGNO/12/,
     &CEVBUC/13/,CEVSPH/14/,CEVEGH/15/,
     &CEVFOR/16/,CEVSCL/17/,CEVZGI/18/,CEVZGO/19/,
     &CEVSTE/20/,CEVMRS/21/,CEVPIN/22/,CEVINQ/23/,
     &CEVFOL/24/
C
	DATA ASTAG/O'100000'/
	DATA PLAYER/1/,AROBOT/2/,AMASTR/3/
C
	DATA CINTW/1/,DEADXW/2/,FRSTQW/3/,INXW/4/
	DATA OUTXW/5/,WALKIW/6/,FIGHTW/7/,FOOW/8/
C
	DATA READW/100/,MELTW/101/
	DATA INFLAW/102/,DEFLAW/103/,ALARMW/104/,EXORCW/105/
	DATA PLUGW/106/,KICKW/107/,WAVEW/108/,RAISEW/109/,LOWERW/110/
	DATA RUBW/111/,PUSHW/112/,UNTIEW/113/,TIEW/114/,TIEUPW/115/
	DATA TURNW/116/,BREATW/117/,KNOCKW/118/,LOOKW/119/
	DATA EXAMIW/120/,SHAKEW/121/,MOVEW/122/,TRNONW/123/,TRNOFW/124/
	DATA OPENW/125/,CLOSEW/126/,FINDW/127/,WAITW/128/,SPINW/129/
	DATA BOARDW/130/,UNBOAW/131/,TAKEW/132/,INVENW/133/
	DATA FILLW/134/,EATW/135/,DRINKW/136/,BURNW/137/
	DATA MUNGW/138/,KILLW/139/,ATTACW/141/
	DATA SWINGW/140/,WALKW/142/,TELLW/143/,PUTW/144/
	DATA DROPW/145/,GIVEW/146/,POURW/147/,THROWW/148/
C
	DATA DIGW/89/,LEAPW/91/,STAYW/73/,FOLLOW/85/
	DATA HELLOW/151/,LOOKIW/152/,LOOKUW/153/,PUMPW/154/
	DATA WINDW/155/,CLMBW/156/,CLMBUW/157/,CLMBDW/158/,TRNTOW/159/
	END
