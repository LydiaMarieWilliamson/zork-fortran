C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C AAPPLI- APPLICABLES FOR ADVENTURERS
	LOGICAL FUNCTION AAPPLI(RI)
	IMPLICIT INTEGER (A-Z)
	LOGICAL F,MOVETO
	include 'parser.h'
	include 'gamestat.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'clock.h'
	include 'advers.h'
	include 'verbs.h'
	include 'flags.h'
C AAPPLI, PAGE 2
C
	IF(RI.EQ.0) GO TO 10
C						!IF ZERO, NO APP.
	AAPPLI=.TRUE.
C						!ASSUME WINS.
	GO TO (1000,2000),RI
C						!BRANCH ON ADV.
	CALL BUG(11,RI)
C
C COMMON FALSE RETURN.
C
10	AAPPLI=.FALSE.
	RETURN
C
C A1--	ROBOT.  PROCESS MOST COMMANDS GIVEN TO ROBOT.
C
1000	IF((PRSA.NE.RAISEW).OR.(PRSO.NE.RCAGE)) GO TO 1200
	CFLAG(CEVSPH)=.FALSE.
C						!ROBOT RAISED CAGE.
	WINNER=PLAYER
C						!RESET FOR PLAYER.
	F=MOVETO(CAGER,WINNER)
C						!MOVE TO NEW ROOM.
	CALL NEWSTA(CAGE,567,CAGER,0,0)
C						!INSTALL CAGE IN ROOM.
	CALL NEWSTA(ROBOT,0,CAGER,0,0)
C						!INSTALL ROBOT IN ROOM.
	AROOM(AROBOT)=CAGER
C						!ALSO MOVE ROBOT/ADV.
	CAGESF=.TRUE.
C						!CAGE SOLVED.
	OFLAG1(ROBOT)=IAND(OFLAG1(ROBOT),NOT(NDSCBT))
	OFLAG1(SPHER)=IOR(OFLAG1(SPHER),TAKEBT)
	RETURN
C
1200	IF((PRSA.NE.DRINKW).AND.(PRSA.NE.EATW)) GO TO 1300
	CALL RSPEAK(568)
C						!EAT OR DRINK, JOKE.
	RETURN
C
1300	IF(PRSA.NE.READW) GO TO 1400
C						!READ,
	CALL RSPEAK(569)
C						!JOKE.
	RETURN
C
1400	IF((PRSA.EQ.WALKW).OR.(PRSA.EQ.TAKEW).OR.(PRSA.EQ.DROPW)
     & .OR.(PRSA.EQ.PUTW).OR.(PRSA.EQ.PUSHW).OR.(PRSA.EQ.THROWW)
     & .OR.(PRSA.EQ.TURNW).OR.(PRSA.EQ.LEAPW)) GO TO 10
	CALL RSPEAK(570)
C						!JOKE.
	RETURN
C AAPPLI, PAGE 3
C
C A2--	MASTER.  PROCESS MOST COMMANDS GIVEN TO MASTER.
C
2000	IF(IAND(OFLAG2(QDOOR),OPENBT).NE.0) GO TO 2100
	CALL RSPEAK(783)
C						!NO MASTER YET.
	RETURN
C
2100	IF(PRSA.NE.WALKW) GO TO 2200
C						!WALK?
	I=784
C						!ASSUME WONT.
	IF(((HERE.EQ.SCORR).AND.
     &	((PRSO.EQ.XNORTH).OR.(PRSO.EQ.XENTER))).OR.
     &  ((HERE.EQ.NCORR).AND.
     &	((PRSO.EQ.XSOUTH).OR.(PRSO.EQ.XENTER))))
     &	I=785
	CALL RSPEAK(I)
	RETURN
C
2200	IF((PRSA.EQ.TAKEW).OR.(PRSA.EQ.DROPW).OR.(PRSA.EQ.PUTW).OR.
     &  (PRSA.EQ.THROWW).OR.(PRSA.EQ.PUSHW).OR.(PRSA.EQ.TURNW).OR.
     &  (PRSA.EQ.SPINW).OR.(PRSA.EQ.TRNTOW).OR.(PRSA.EQ.FOLLOW).OR.
     &  (PRSA.EQ.STAYW).OR.(PRSA.EQ.OPENW).OR.(PRSA.EQ.CLOSEW).OR.
     &  (PRSA.EQ.KILLW)) GO TO 10
	CALL RSPEAK(786)
C						!MASTER CANT DO IT.
	RETURN
	END
C
C THIEFD-	INTERMOVE THIEF DEMON
	SUBROUTINE THIEFD
	IMPLICIT INTEGER (A-Z)
	LOGICAL ONCE,PROB,QHERE,QSTILL,LIT,WINNIN
	INCLUDE 'gamestat.h'
C
	INCLUDE 'debug.h'
	INCLUDE 'rooms.h'
	INCLUDE 'rflag.h'
	INCLUDE 'rindex.h'
	INCLUDE 'objects.h'
	INCLUDE 'oflags.h'
	INCLUDE 'oindex.h'
	INCLUDE 'villians.h'
	INCLUDE 'flags.h'
C
C In-line function
	QSTILL(R)=(QHERE(STILL,R).OR.(OADV(STILL).EQ.-THIEF))
C THIEFD, PAGE 2
C
D	DFLAG=IAND(PRSFLG, 32768).NE.0
C						!SET UP DETAIL FLAG.
	ONCE=.FALSE.
C						!INIT FLAG.
1025	RHERE=OROOM(THIEF)
C						!VISIBLE POS.
	IF(RHERE.NE.0) THFPOS=RHERE
C
	IF(THFPOS.EQ.HERE) GO TO 1100
C						!THIEF IN WIN RM?
	IF(THFPOS.NE.TREAS) GO TO 1400
C						!THIEF NOT IN TREAS?
C
C THIEF IS IN TREASURE ROOM, AND WINNER IS NOT.
C
D	IF(DFLAG) PRINT 10
D10	FORMAT(' THIEFD-- IN TREASURE ROOM')
	IF(RHERE.EQ.0) GO TO 1050
C						!VISIBLE?
	CALL NEWSTA(THIEF,0,0,0,0)
C						!YES, VANISH.
	RHERE=0
	IF(QSTILL(TREAS)) CALL NEWSTA(STILL,0,0,THIEF,0)
1050	I=ROBADV(-THIEF,THFPOS,0,0)
C						!DROP VALUABLES.
	IF(QHERE(EGG,THFPOS)) OFLAG2(EGG)=IOR(OFLAG2(EGG),OPENBT)
	GO TO 1700
C
C THIEF AND WINNER IN SAME ROOM.
C
1100	IF(THFPOS.EQ.TREAS) GO TO 1700
C						!IF TREAS ROOM, NOTHING.
	IF(IAND(RFLAG(THFPOS),RLIGHT).NE.0) GO TO 1400
D	IF(DFLAG) PRINT 20
D20	FORMAT(' THIEFD-- IN ADV ROOM')
	IF(THFFLG) GO TO 1300
C						!THIEF ANNOUNCED?
	IF((RHERE.NE.0).OR.PROB(70,70)) GO TO 1150
C						!IF INVIS AND 30%.
	IF(OCAN(STILL).NE.THIEF) GO TO 1700
C						!ABORT IF NO STILLETTO.
	CALL NEWSTA(THIEF,583,THFPOS,0,0)
C						!INSERT THIEF INTO ROOM.
	THFFLG=.TRUE.
C						!THIEF IS ANNOUNCED.
	RETURN
C
1150	IF((RHERE.EQ.0).OR.(IAND(OFLAG2(THIEF),FITEBT).EQ.0))
     &	GO TO 1200
	IF(WINNIN(THIEF,WINNER)) GO TO 1175
C						!WINNING?
	CALL NEWSTA(THIEF,584,0,0,0)
C						!NO, VANISH THIEF.
	OFLAG2(THIEF)=IAND(OFLAG2(THIEF), not(FITEBT))
	IF(QSTILL(THFPOS)) CALL NEWSTA(STILL,0,0,THIEF,0)
	RETURN
C
1175	IF(PROB(90,90)) GO TO 1700
C						!90% CHANCE TO STAY.
C
1200	IF((RHERE.EQ.0).OR.PROB(70,70)) GO TO 1250
C						!IF VISIBLE AND 30%
	CALL NEWSTA(THIEF,585,0,0,0)
C						!VANISH THIEF.
	IF(QSTILL(THFPOS)) CALL NEWSTA(STILL,0,0,THIEF,0)
	RETURN
C
1300	IF(RHERE.EQ.0) GO TO 1700
C						!ANNOUNCED.  VISIBLE?
1250	IF(PROB(70,70)) RETURN
C						!70% CHANCE TO DO NOTHING.
	THFFLG=.TRUE.
	NR=ROBRM(THFPOS,100,0,0,-THIEF)+ROBADV(WINNER,0,0,-THIEF)
	I=586
C						!ROBBED EM.
	IF(RHERE.NE.0) I=588
C						!WAS HE VISIBLE?
	IF(NR.NE.0) I=I+1
C						!DID HE GET ANYTHING?
	CALL NEWSTA(THIEF,I,0,0,0)
C						!VANISH THIEF.
	IF(QSTILL(THFPOS))
     &	CALL NEWSTA(STILL,0,0,THIEF,0)
	IF((NR.NE.0).AND..NOT.LIT(THFPOS)) CALL RSPEAK(406)
	RHERE=0
	GO TO 1700
C						!ONWARD.
C
C NOT IN ADVENTURERS ROOM.
C
1400	CALL NEWSTA(THIEF,0,0,0,0)
C						!VANISH.
	RHERE=0
D	IF(DFLAG) PRINT 30,THFPOS
D30	FORMAT(' THIEFD-- IN ROOM ',I4)
	IF(QSTILL(THFPOS))
     &	CALL NEWSTA(STILL,0,0,THIEF,0)
	IF(IAND(RFLAG(THFPOS),RSEEN).EQ.0) GO TO 1700
	I=ROBRM(THFPOS,75,0,0,-THIEF)
C						!ROB ROOM 75%.
	IF((THFPOS.LT.MAZE1).OR.(THFPOS.GT.MAZ15).OR.
     &	(HERE.LT.MAZE1).OR.(HERE.GT.MAZ15)) GO TO 1500
	DO 1450 I=1,OLNT
C						!BOTH IN MAZE.
	  IF(.NOT.QHERE(I,THFPOS).OR.PROB(60,60).OR.
     &	(IAND(OFLAG1(I),(VISIBT+TAKEBT)).NE.(VISIBT+TAKEBT)))
     &	GO TO 1450
	  CALL RSPSUB(590,ODESC2(I))
C						!TAKE OBJECT.
	  IF(PROB(40,20)) GO TO 1700
	  CALL NEWSTA(I,0,0,0,-THIEF)
C						!MOST OF THE TIME.
	  OFLAG2(I)=IOR(OFLAG2(I),TCHBT)
	  GO TO 1700
1450	CONTINUE
	GO TO 1700
C
1500	DO 1550 I=1,OLNT
C						!NOT IN MAZE.
	  IF(.NOT.QHERE(I,THFPOS).OR.(OTVAL(I).NE.0).OR.PROB(80,60).OR.
     &	(IAND(OFLAG1(I),(VISIBT+TAKEBT)).NE.(VISIBT+TAKEBT)))
     &	GO TO 1550
	  CALL NEWSTA(I,0,0,0,-THIEF)
	  OFLAG2(I)=IOR(OFLAG2(I),TCHBT)
	  GO TO 1700
1550	CONTINUE
C
C NOW MOVE TO NEW ROOM.
C
1700	IF(OADV(ROPE).EQ.-THIEF) DOMEF=.FALSE.
	IF(ONCE) GO TO 1800
	ONCE=.NOT.ONCE
1750	THFPOS=THFPOS-1
C						!NEXT ROOM.
	IF(THFPOS.LE.0) THFPOS=RLNT
	IF(IAND(RFLAG(THFPOS),(RLAND+RSACRD+REND)).NE.RLAND)
     &	GO TO 1750
	THFFLG=.FALSE.
C						!NOT ANNOUNCED.
	GO TO 1025
C						!ONCE MORE.
C
C ALL DONE.
C
1800	IF(THFPOS.EQ.TREAS) RETURN
C						!IN TREASURE ROOM?
	J=591
C						!NO, DROP STUFF.
	IF(THFPOS.NE.HERE) J=0
	DO 1850 I=1,OLNT
	  IF((OADV(I).NE.-THIEF).OR.PROB(70,70).OR.
     &	(OTVAL(I).GT.0)) GO TO 1850
	  CALL NEWSTA(I,J,THFPOS,0,0)
	  J=0
1850	CONTINUE
	RETURN
	END
