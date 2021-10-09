C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Save game state
	SUBROUTINE SAVEGM
	IMPLICIT INTEGER (A-Z)
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'screen.h'
	include 'puzzle.h'
	include 'rooms.h'
	include 'exits.h'
	include 'objects.h'
	include 'clock.h'
	include 'villians.h'
	include 'advers.h'
	include 'flags.h'
C
C MISCELLANEOUS VARIABLES
C
        CHARACTER VEDIT
	COMMON /VERS/ VMAJ,VMIN,VEDIT
	COMMON /TIME/ PLTIME,SHOUR,SMIN,SSEC
C
	PRSWON=.FALSE.
C						!DISABLE GAME.
C Note: save file format is different for PDP versus non-PDP versions
C
	OPEN (UNIT=1,file='dsave.dat',ACCESS='SEQUENTIAL',
     &	status='UNKNOWN',FORM='UNFORMATTED',ERR=100)
C
	CALL GTTIME(TIMEPL)
C						!GET TIME.
	WRITE(1) VMAJ,VMIN,VEDIT
	WRITE(1) WINNER,HERE,THFPOS,TELFLG,THFFLG,THFACT,
     &	SWDACT,SWDSTA,CPVEC
	WRITE(1) TIMEPL,MOVES,DEATHS,RWSCOR,EGSCOR,MXLOAD,
     &	LTSHFT,BLOC,MUNGRM,HS,FROMDR,SCOLRM,SCOLAC
	WRITE(1) ODESC1,ODESC2,OFLAG1,OFLAG2,OFVAL,OTVAL,
     &	OSIZE,OCAPAC,OROOM,OADV,OCAN
	WRITE(1) RVAL,RFLAG
	WRITE(1) AROOM,ASCORE,AVEHIC,ASTREN,AFLAG
	WRITE(1) FLAGS,SWITCH,VPROB,CFLAG,CTICK
C
	CLOSE(UNIT=1)
	CALL RSPEAK(597)
	RETURN
C
100	CALL RSPEAK(598)
C						!CANT DO IT.
	RETURN
	END
C
C Restore game state
	SUBROUTINE RSTRGM
	IMPLICIT INTEGER (A-Z)
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'screen.h'
	include 'puzzle.h'
	include 'rooms.h'
	include 'exits.h'
	include 'objects.h'
	include 'clock.h'
	include 'villians.h'
	include 'advers.h'
	include 'flags.h'
C
C MISCELLANEOUS VARIABLES
C
        CHARACTER EDITV,VEDIT
	COMMON /VERS/ VMAJ,VMIN,VEDIT
	COMMON /TIME/ PLTIME,SHOUR,SMIN,SSEC
C
	PRSWON=.FALSE.
C						!DISABLE GAME.
C Note: save file format is different for PDP versus non-PDP versions
C
	OPEN (UNIT=1,file='dsave.dat',ACCESS='SEQUENTIAL',
     &	status='OLD',FORM='UNFORMATTED',ERR=100)
C
	READ(1) MAJV,MINV,EDITV
	IF((MAJV.NE.VMAJ).OR.(MINV.NE.VMIN)) GO TO 200
C
	READ(1) WINNER,HERE,THFPOS,TELFLG,THFFLG,THFACT,
     &	SWDACT,SWDSTA,CPVEC
	READ(1) PLTIME,MOVES,DEATHS,RWSCOR,EGSCOR,MXLOAD,
     &	LTSHFT,BLOC,MUNGRM,HS,FROMDR,SCOLRM,SCOLAC
	READ(1) ODESC1,ODESC2,OFLAG1,OFLAG2,OFVAL,OTVAL,
     &	OSIZE,OCAPAC,OROOM,OADV,OCAN
	READ(1) RVAL,RFLAG
	READ(1) AROOM,ASCORE,AVEHIC,ASTREN,AFLAG
	READ(1) FLAGS,SWITCH,VPROB,CFLAG,CTICK
C
	CLOSE(UNIT=1)
	CALL RSPEAK(599)
	RETURN
C
100	CALL RSPEAK(598)
C						!CANT DO IT.
	RETURN
C
200	CALL RSPEAK(600)
C						!OBSOLETE VERSION
	CLOSE (UNIT=1)
	RETURN
	END
C
C Move in specified direction
	LOGICAL FUNCTION WALK()
	IMPLICIT INTEGER(A-Z)
	LOGICAL FINDXT,QOPEN,LIT,PROB,MOVETO,RMDESC
	include 'parser.h'
	include 'gamestat.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'curxt.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'oflags.h'
	include 'clock.h'

	include 'villians.h'
	include 'advers.h'
	include 'flags.h'
C
C In-line function
	QOPEN(O)=IAND(OFLAG2(O),OPENBT).NE.0
C WALK, PAGE 2
C
	WALK=.TRUE.
C						!ASSUME WINS.
	IF((WINNER.NE.PLAYER).OR.LIT(HERE).OR.PROB(25,25))
     &	GO TO 500
	IF(.NOT.FINDXT(PRSO,HERE)) GO TO 450
C						!INVALID EXIT? GRUE
C						!
	GO TO (400,200,100,300),XTYPE
C						!DECODE EXIT TYPE.
	CALL BUG(9,XTYPE)
C
100	IF(CXAPPL(XACTIO).NE.0) GO TO 400
C						!CEXIT... RETURNED ROOM?
	IF(FLAGS(XFLAG)) GO TO 400
C						!NO, FLAG ON?
200	CALL JIGSUP(523)
C						!BAD EXIT, GRUE
C						!
	RETURN
C
300	IF(CXAPPL(XACTIO).NE.0) GO TO 400
C						!DOOR... RETURNED ROOM?
	IF(QOPEN(XOBJ)) GO TO 400
C						!NO, DOOR OPEN?
	CALL JIGSUP(523)
C						!BAD EXIT, GRUE
C						!
	RETURN
C
400	IF(LIT(XROOM1)) GO TO 900
C						!VALID ROOM, IS IT LIT?
450	CALL JIGSUP(522)
C						!NO, GRUE
C						!
	RETURN
C
C ROOM IS LIT, OR WINNER IS NOT PLAYER (NO GRUE).
C
500	IF(FINDXT(PRSO,HERE)) GO TO 550
C						!EXIT EXIST?
525	XSTRNG=678
C						!ASSUME WALL.
	IF(PRSO.EQ.XUP) XSTRNG=679
C						!IF UP, CANT.
	IF(PRSO.EQ.XDOWN) XSTRNG=680
C						!IF DOWN, CANT.
	IF(IAND(RFLAG(HERE),RNWALL).NE.0) XSTRNG=524
	CALL RSPEAK(XSTRNG)
	PRSCON=1
C						!STOP CMD STREAM.
	RETURN
C
550	GO TO (900,600,700,800),XTYPE
C						!BRANCH ON EXIT TYPE.
	CALL BUG(9,XTYPE)
C
700	IF(CXAPPL(XACTIO).NE.0) GO TO 900
C						!CEXIT... RETURNED ROOM?
	IF(FLAGS(XFLAG)) GO TO 900
C						!NO, FLAG ON?
600	IF(XSTRNG.EQ.0) GO TO 525
C						!IF NO REASON, USE STD.
	CALL RSPEAK(XSTRNG)
C						!DENY EXIT.
	PRSCON=1
C						!STOP CMD STREAM.
	RETURN
C
800	IF(CXAPPL(XACTIO).NE.0) GO TO 900
C						!DOOR... RETURNED ROOM?
	IF(QOPEN(XOBJ)) GO TO 900
C						!NO, DOOR OPEN?
	IF(XSTRNG.EQ.0) XSTRNG=525
C						!IF NO REASON, USE STD.
	CALL RSPSUB(XSTRNG,ODESC2(XOBJ))
	PRSCON=1
C						!STOP CMD STREAM.
	RETURN
C
900	WALK=MOVETO(XROOM1,WINNER)
C						!MOVE TO ROOM.
	IF(WALK) WALK=RMDESC(0)
C						!DESCRIBE ROOM.
	RETURN
	END
C
C Conditional exit processors
	INTEGER FUNCTION CXAPPL(RI)
	IMPLICIT INTEGER (A-Z)
	include 'gamestat.h'
	include 'parser.h'
	include 'puzzle.h'
	include 'rooms.h'
	include 'rindex.h'
	include 'exits.h'
	include 'curxt.h'
	include 'xpars.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'advers.h'
	include 'flags.h'
C CXAPPL, PAGE 2
C
	CXAPPL=0
C						!NO RETURN.
	IF(RI.EQ.0) RETURN
C						!IF NO ACTION, DONE.
	GO TO (1000,2000,3000,4000,5000,6000,7000,
     &	8000,9000,10000,11000,12000,13000,14000),RI
	CALL BUG(5,RI)
C
C C1- COFFIN-CURE
C
1000	EGYPTF=OADV(COFFI).NE.WINNER
C						!T IF NO COFFIN.
	RETURN
C
C C2- CAROUSEL EXIT
C C5- CAROUSEL OUT
C
2000	IF(CAROFF) RETURN
C						!IF FLIPPED, NOTHING.
2500	CALL RSPEAK(121)
C						!SPIN THE COMPASS.
5000	I=XELNT(XCOND)*RND(8)
C						!CHOOSE RANDOM EXIT.
	XROOM1=IAND(TRAVEL(REXIT(HERE)+I),XRMASK)
	CXAPPL=XROOM1
C						!RETURN EXIT.
	RETURN
C
C C3- CHIMNEY FUNCTION
C
3000	LITLDF=.FALSE.
C						!ASSUME HEAVY LOAD.
	J=0
	DO 3100 I=1,OLNT
C						!COUNT OBJECTS.
	  IF(OADV(I).EQ.WINNER) J=J+1
3100	CONTINUE
C
	IF(J.GT.2) RETURN
C						!CARRYING TOO MUCH?
	XSTRNG=446
C						!ASSUME NO LAMP.
	IF(OADV(LAMP).NE.WINNER) RETURN
C						!NO LAMP?
	LITLDF=.TRUE.
C						!HE CAN DO IT.
	IF(IAND(OFLAG2(DOOR),OPENBT).EQ.0)
     &	OFLAG2(DOOR)=IAND(OFLAG2(DOOR), not(TCHBT))
	RETURN
C
C C4-	FROBOZZ FLAG (MAGNET ROOM, FAKE EXIT)
C C6-	FROBOZZ FLAG (MAGNET ROOM, REAL EXIT)
C
4000	IF(CAROFF) GO TO 2500
C						!IF FLIPPED, GO SPIN.
	FROBZF=.FALSE.
C						!OTHERWISE, NOT AN EXIT.
	RETURN
C
6000	IF(CAROFF) GO TO 2500
C						!IF FLIPPED, GO SPIN.
	FROBZF=.TRUE.
C						!OTHERWISE, AN EXIT.
	RETURN
C
C C7-	FROBOZZ FLAG (BANK ALARM)
C
7000	FROBZF=(OROOM(BILLS).NE.0).AND.(OROOM(PORTR).NE.0)
	RETURN
C CXAPPL, PAGE 3
C
C C8-	FROBOZZ FLAG (MRGO)
C
8000	FROBZF=.FALSE.
C						!ASSUME CANT MOVE.
	IF(MLOC.NE.XROOM1) GO TO 8100
C						!MIRROR IN WAY?
	IF((PRSO.EQ.XNORTH).OR.(PRSO.EQ.XSOUTH)) GO TO 8200
	IF(MOD(MDIR,180).NE.0) GO TO 8300
C						!MIRROR MUST BE N-S.
	XROOM1=((XROOM1-MRA)*2)+MRAE
C						!CALC EAST ROOM.
	IF(PRSO.GT.XSOUTH) XROOM1=XROOM1+1
C						!IF SW/NW, CALC WEST.
8100	CXAPPL=XROOM1
	RETURN
C
8200	XSTRNG=814
C						!ASSUME STRUC BLOCKS.
	IF(MOD(MDIR,180).EQ.0) RETURN
C						!IF MIRROR N-S, DONE.
8300	LDIR=MDIR
C						!SEE WHICH MIRROR.
	IF(PRSO.EQ.XSOUTH) LDIR=180
	XSTRNG=815
C						!MIRROR BLOCKS.
	IF(((LDIR.GT.180).AND..NOT.MR1F).OR.
     &  ((LDIR.LT.180).AND..NOT.MR2F)) XSTRNG=816
	RETURN
C
C C9-	FROBOZZ FLAG (MIRIN)
C
9000	IF(MRHERE(HERE).NE.1) GO TO 9100
C						!MIRROR 1 HERE?
	IF(MR1F) XSTRNG=805
C						!SEE IF BROKEN.
	FROBZF=MROPNF
C						!ENTER IF OPEN.
	RETURN
C
9100	FROBZF=.FALSE.
C						!NOT HERE,
	XSTRNG=817
C						!LOSE.
	RETURN
C CXAPPL, PAGE 4
C
C C10-	FROBOZZ FLAG (MIRROR EXIT)
C
10000	FROBZF=.FALSE.
C						!ASSUME CANT.
	LDIR=((PRSO-XNORTH)/XNORTH)*45
C						!XLATE DIR TO DEGREES.
	IF(.NOT.MROPNF .OR.
     &	((MOD(MDIR+270,360).NE.LDIR).AND.(PRSO.NE.XEXIT)))
     &	GO TO 10200
	XROOM1=((MLOC-MRA)*2)+MRAE+1-(MDIR/180)
C						!ASSUME E-W EXIT.
	IF(MOD(MDIR,180).EQ.0) GO TO 10100
C						!IF N-S, OK.
	XROOM1=MLOC+1
C						!ASSUME N EXIT.
	IF(MDIR.GT.180) XROOM1=MLOC-1
C						!IF SOUTH.
10100	CXAPPL=XROOM1
	RETURN
C
10200	IF(.NOT.WDOPNF .OR.
     &	((MOD(MDIR+180,360).NE.LDIR).AND.(PRSO.NE.XEXIT)))
     &	RETURN
	XROOM1=MLOC+1
C						!ASSUME N.
	IF(MDIR.EQ.0) XROOM1=MLOC-1
C						!IF S.
	CALL RSPEAK(818)
C						!CLOSE DOOR.
	WDOPNF=.FALSE.
	CXAPPL=XROOM1
	RETURN
C
C C11-	MAYBE DOOR.  NORMAL MESSAGE IS THAT DOOR IS CLOSED.
C	BUT IF LCELL.NE.4, DOOR ISNT THERE.
C
11000	IF(LCELL.NE.4) XSTRNG=678
C						!SET UP MSG.
	RETURN
C
C C12-	FROBZF (PUZZLE ROOM MAIN ENTRANCE)
C
12000	FROBZF=.TRUE.
C						!ALWAYS ENTER.
	CPHERE=10
C						!SET SUBSTATE.
	RETURN
C
C C13-	CPOUTF (PUZZLE ROOM SIZE ENTRANCE)
C
13000	CPHERE=52
C						!SET SUBSTATE.
	RETURN
C CXAPPL, PAGE 5
C
C C14-	FROBZF (PUZZLE ROOM TRANSITIONS)
C
14000	FROBZF=.FALSE.
C						!ASSSUME LOSE.
	IF(PRSO.NE.XUP) GO TO 14100
C						!UP?
	IF(CPHERE.NE.10) RETURN
C						!AT EXIT?
	XSTRNG=881
C						!ASSUME NO LADDER.
	IF(CPVEC(CPHERE+1).NE.-2) RETURN
C						!LADDER HERE?
	CALL RSPEAK(882)
C						!YOU WIN.
	FROBZF=.TRUE.
C						!LET HIM OUT.
	RETURN
C
14100	IF((CPHERE.NE.52).OR.(PRSO.NE.XWEST).OR..NOT.CPOUTF)
     &	GO TO 14200
	FROBZF=.TRUE.
C						!YES, LET HIM OUT.
	RETURN
C
14200	DO 14300 I=1,16,2
C						!LOCATE EXIT.
	  IF(PRSO.EQ.CPDR(I)) GO TO 14400
14300	CONTINUE
	RETURN
C						!NO SUCH EXIT.
C
14400	J=CPDR(I+1)
C						!GET DIRECTIONAL OFFSET.
	NXT=CPHERE+J
C						!GET NEXT STATE.
	K=8
C						!GET ORTHOGONAL DIR.
	IF(J.LT.0) K=-8
	IF((((IABS(J).EQ.1).OR.(IABS(J).EQ.8)).OR.
     &   ((CPVEC(CPHERE+K).EQ.0).OR.(CPVEC(NXT-K).EQ.0))).AND.
     &    (CPVEC(NXT).EQ.0)) GO TO 14500
	RETURN
C
14500	CALL CPGOTO(NXT)
C						!MOVE TO STATE.
	XROOM1=CPUZZ
C						!STAY IN ROOM.
	CXAPPL=XROOM1
	RETURN
	END
