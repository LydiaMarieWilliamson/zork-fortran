C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Main verb processing routine
	LOGICAL FUNCTION VAPPLI(RI)
	IMPLICIT INTEGER (A-Z)
	LOGICAL LIT,OBJACT
	LOGICAL QEMPTY,RMDESC,CLOCKD
	LOGICAL QOPEN,EDIBLE,DRKBLE
	LOGICAL TAKE,PUT,DROP,WALK
	LOGICAL QHERE,SVERBS,FINDXT,OAPPLI,F
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
C
	COMMON /STAR/ MBASE,STRBIT
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'xsrch.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'advers.h'
	include 'verbs.h'
C
C In-line functions
	QOPEN(R)=IAND(OFLAG2(R),OPENBT).NE.0
	EDIBLE(R)=IAND(OFLAG1(R),FOODBT).NE.0
	DRKBLE(R)=IAND(OFLAG1(R),DRNKBT).NE.0
C
C Initialized data
	DATA MXNOP/39/,MXSMP/99/
C VAPPLI, PAGE 2
C
	VAPPLI=.TRUE.
C						!ASSUME WINS.
C
	IF(PRSO.GT.220) GO TO 5
C
	IF(PRSO.NE.0) ODO2=ODESC2(PRSO)
C						!SET UP DESCRIPTORS.
5	IF(PRSI.NE.0) ODI2=ODESC2(PRSI)
	AV=AVEHIC(WINNER)
	RMK=372+RND(6)
C						!REMARK FOR HACK-HACKS.
C
	IF(RI.EQ.0) GO TO 10
C						!ZERO IS FALSE.
	IF(RI.LE.MXNOP) RETURN
C						!NOP?
	IF(RI.LE.MXSMP) GO TO 100
C						!SIMPLE VERB?
	GO TO (18000,20000,
     &       22000,23000,24000,25000,26000,27000,28000,29000,30000,
     & 31000,32000,33000,34000,35000,36000,      38000,39000,40000,
     & 41000,42000,43000,44000,45000,46000,47000,48000,49000,50000,
     & 51000,52000,53000,      55000,56000,      58000,59000,60000,
     &             63000,64000,65000,66000,      68000,69000,70000,
     & 71000,72000,73000,74000,            77000,78000,
     & 80000,81000,82000,83000,84000,85000,86000,87000,88000),
     &	(RI-MXSMP)
	CALL BUG(7,RI)
C
C ALL VERB PROCESSORS RETURN HERE TO DECLARE FAILURE.
C
10	VAPPLI=.FALSE.
C						!LOSE.
	RETURN
C
C SIMPLE VERBS ARE HANDLED EXTERNALLY.
C
100	VAPPLI=SVERBS(RI)
	RETURN
C VAPPLI, PAGE 3
C
C V100--	READ.  OUR FIRST REAL VERB.
C
18000	IF(LIT(HERE)) GO TO 18100
C						!ROOM LIT?
	CALL RSPEAK(356)
C						!NO, CANT READ.
	RETURN
C
18100	IF(PRSI.EQ.0) GO TO 18200
C						!READ THROUGH OBJ?
	IF(IAND(OFLAG1(PRSI),TRANBT).NE.0) GO TO 18200
	CALL RSPSUB(357,ODI2)
C						!NOT TRANSPARENT.
	RETURN
C
18200	IF(IAND(OFLAG1(PRSO),READBT).NE.0) GO TO 18300
	CALL RSPSUB(358,ODO2)
C						!NOT READABLE.
	RETURN
C
18300	IF(.NOT.OBJACT()) CALL RSPEAK(OREAD(PRSO))
	RETURN
C
C V101--	MELT.  UNLESS OBJECT HANDLES, JOKE.
C
20000	IF(.NOT.OBJACT()) CALL RSPSUB(361,ODO2)
	RETURN
C
C V102--	INFLATE.  WORKS ONLY WITH BOATS.
C
22000	IF(.NOT.OBJACT()) CALL RSPEAK(368)
C						!OBJ HANDLE?
	RETURN
C
C V103--	DEFLATE.
C
23000	IF(.NOT.OBJACT()) CALL RSPEAK(369)
C						!OBJ HANDLE?
	RETURN
C VAPPLI, PAGE 4
C
C V104--	ALARM.  IF SLEEPING, WAKE HIM UP.
C
24000	IF(IAND(OFLAG2(PRSO),SLEPBT).EQ.0) GO TO 24100
	VAPPLI=OBJACT()
C						!SLEEPING, LET OBJ DO.
	RETURN
C
24100	CALL RSPSUB(370,ODO2)
C						!JOKE.
	RETURN
C
C V105--	EXORCISE.  OBJECTS HANDLE.
C
25000	F=OBJACT()
C						!OBJECTS HANDLE.
	RETURN
C
C V106--	PLUG.  LET OBJECTS HANDLE.
C
26000	IF(.NOT.OBJACT()) CALL RSPEAK(371)
	RETURN
C
C V107--	KICK.  IF OBJECT IGNORES, JOKE.
C
27000	IF(.NOT.OBJACT()) CALL RSPSB2(378,ODO2,RMK)
	RETURN
C
C V108--	WAVE.  SAME.
C
28000	IF(.NOT.OBJACT()) CALL RSPSB2(379,ODO2,RMK)
	RETURN
C
C V109,V110--	RAISE, LOWER.  SAME.
C
29000	CONTINUE
30000	IF(.NOT.OBJACT()) CALL RSPSB2(380,ODO2,RMK)
	RETURN
C
C V111--	RUB.  SAME.
C
31000	IF(.NOT.OBJACT()) CALL RSPSB2(381,ODO2,RMK)
	RETURN
C
C V112--	PUSH.  SAME.
C
32000	IF(.NOT.OBJACT()) CALL RSPSB2(382,ODO2,RMK)
	RETURN
C VAPPLI, PAGE 5
C
C V113--	UNTIE.  IF OBJECT IGNORES, JOKE.
C
33000	IF(OBJACT()) RETURN
C						!OBJECT HANDLE?
	I=383
C						!NO, NOT TIED.
	IF(IAND(OFLAG2(PRSO),TIEBT).EQ.0) I=384
	CALL RSPEAK(I)
	RETURN
C
C V114--	TIE.  NEVER REALLY WORKS.
C
34000	IF(IAND(OFLAG2(PRSO),TIEBT).NE.0) GO TO 34100
	CALL RSPEAK(385)
C						!NOT TIEABLE.
	RETURN
C
34100	IF(.NOT.OBJACT()) CALL RSPSUB(386,ODO2)
C						!JOKE.
	RETURN
C
C V115--	TIE UP.  NEVER REALLY WORKS.
C
35000	IF(IAND(OFLAG2(PRSI),TIEBT).NE.0) GO TO 35100
	CALL RSPSUB(387,ODO2)
C						!NOT TIEABLE.
	RETURN
C
35100	I=388
C						!ASSUME VILLAIN.
	IF(IAND(OFLAG2(PRSO),VILLBT).EQ.0) I=389
	CALL RSPSUB(I,ODO2)
C						!JOKE.
	RETURN
C
C V116--	TURN.  OBJECT MUST HANDLE.
C
36000	IF(IAND(OFLAG1(PRSO),TURNBT).NE.0) GO TO 36100
	CALL RSPEAK(390)
C						!NOT TURNABLE.
	RETURN
C
36100	IF(IAND(OFLAG1(PRSI),TOOLBT).NE.0) GO TO 36200
	CALL RSPSUB(391,ODI2)
C						!NOT A TOOL.
	RETURN
C
36200	VAPPLI=OBJACT()
C						!LET OBJECT HANDLE.
	RETURN
C
C V117--	BREATHE.  BECOMES INFLATE WITH LUNGS.
C
38000	PRSA=INFLAW
	PRSI=LUNGS
	GO TO 22000
C						!HANDLE LIKE INFLATE.
C
C V118--	KNOCK.  MOSTLY JOKE.
C
39000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	I=394
C						!JOKE FOR DOOR.
	IF(IAND(OFLAG1(PRSO),DOORBT).EQ.0) I=395
	CALL RSPSUB(I,ODO2)
C						!JOKE FOR NONDOORS TOO.
	RETURN
C
C V119--	LOOK.
C
40000	IF(PRSO.NE.0) GO TO 41500
C						!SOMETHING TO LOOK AT?
	VAPPLI=RMDESC(3)
C						!HANDLED BY RMDESC.
	RETURN
C
C V120--	EXAMINE.
C
41000	IF(PRSO.NE.0) GO TO 41500
C						!SOMETHING TO EXAMINE?
	VAPPLI=RMDESC(0)
C						!HANDLED BY RMDESC.
	RETURN
C
41500	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	I=OREAD(PRSO)
C						!GET READING MATERIAL.
	IF(I.NE.0) CALL RSPEAK(I)
C						!OUTPUT IF THERE,
	IF(I.EQ.0) CALL RSPSUB(429,ODO2)
C						!OTHERWISE DEFAULT.
	PRSA=FOOW
C						!DEFUSE ROOM PROCESSORS.
	RETURN
C
C V121--	SHAKE.  IF HOLLOW OBJECT, SOME ACTION.
C
42000	IF(OBJACT()) RETURN
C						!OBJECT HANDLE?
	IF(IAND(OFLAG2(PRSO),VILLBT).EQ.0) GO TO 42100
	CALL RSPEAK(371)
C						!JOKE FOR VILLAINS.
	RETURN
C
42100	IF(QEMPTY(PRSO).OR.(IAND(OFLAG1(PRSO),TAKEBT).EQ.0))
     &	GO TO 10
	IF(QOPEN(PRSO)) GO TO 42300
C						!OPEN?  SPILL.
	CALL RSPSUB(396,ODO2)
C						!NO, DESCRIBE NOISE.
	RETURN
C
42300	CALL RSPSUB(397,ODO2)
C						!SPILL THE WORKS.
	DO 42500 I=1,OLNT
C						!SPILL CONTENTS.
	  IF(OCAN(I).NE.PRSO) GO TO 42500
C						!INSIDE?
	  OFLAG2(I)=IOR(OFLAG2(I),TCHBT)
	  IF(AV.EQ.0) GO TO 42400
C						!IN VEHICLE?
	  CALL NEWSTA(I,0,0,AV,0)
C						!YES, SPILL IN THERE.
	  GO TO 42500
C
42400	  CALL NEWSTA(I,0,HERE,0,0)
C						!NO, SPILL ON FLOOR,
	  IF(I.EQ.WATER) CALL NEWSTA(I,133,0,0,0)
C						!BUT WATER DISAPPEARS.
42500	CONTINUE
	RETURN
C
C V122--	MOVE.  MOSTLY JOKES.
C
43000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	I=398
C						!ASSUME NOT HERE.
	IF(QHERE(PRSO,HERE)) I=399
	CALL RSPSUB(I,ODO2)
C						!JOKE.
	RETURN
C VAPPLI, PAGE 6
C
C V123--	TURN ON.
C
44000	F=LIT(HERE)
C						!RECORD IF LIT.
	IF(OBJACT()) GO TO 44300
C						!OBJ HANDLE?
	IF((IAND(OFLAG1(PRSO),LITEBT).NE.0).AND.
     &	(OADV(PRSO).EQ.WINNER)) GO TO 44100
	CALL RSPEAK(400)
C						!CANT DO IT.
	RETURN
C
44100	IF(IAND(OFLAG1(PRSO),ONBT).EQ.0) GO TO 44200
	CALL RSPEAK(401)
C						!ALREADY ON.
	RETURN
C
44200	OFLAG1(PRSO)=IOR(OFLAG1(PRSO),ONBT)
	CALL RSPSUB(404,ODO2)
44300	IF(.NOT.F .AND.LIT(HERE)) F=RMDESC(0)
C						!ROOM NEWLY LIT.
	RETURN
C
C V124--	TURN OFF.
C
45000	IF(OBJACT()) GO TO 45300
C						!OBJ HANDLE?
	IF((IAND(OFLAG1(PRSO),LITEBT).NE.0).AND.
     &	(OADV(PRSO).EQ.WINNER)) GO TO 45100
	CALL RSPEAK(402)
C						!CANT DO IT.
	RETURN
C
45100	IF(IAND(OFLAG1(PRSO),ONBT).NE.0) GO TO 45200
	CALL RSPEAK(403)
C						!ALREADY OFF.
	RETURN
C
45200	OFLAG1(PRSO)=IAND(OFLAG1(PRSO), not(ONBT))
	CALL RSPSUB(405,ODO2)
45300	IF(.NOT.LIT(HERE)) CALL RSPEAK(406)
C						!MAY BE DARK.
	RETURN
C
C V125--	OPEN.  A FINE MESS.
C
46000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(IAND(OFLAG1(PRSO),CONTBT).NE.0) GO TO 46100
46050	CALL RSPSUB(407,ODO2)
C						!NOT OPENABLE.
	RETURN
C
46100	IF(OCAPAC(PRSO).NE.0) GO TO 46200
	CALL RSPSUB(408,ODO2)
C						!NOT OPENABLE.
	RETURN
C
46200	IF(.NOT.QOPEN(PRSO)) GO TO 46225
	CALL RSPEAK(412)
C						!ALREADY OPEN.
	RETURN
C
46225	OFLAG2(PRSO)=IOR(OFLAG2(PRSO),OPENBT)
	IF((IAND(OFLAG1(PRSO),TRANBT).NE.0).OR.QEMPTY(PRSO))
     &	GO TO 46300
	CALL PRINCO(PRSO,410)
C						!PRINT CONTENTS.
	RETURN
C
46300	CALL RSPEAK(409)
C						!DONE
	RETURN
C
C V126--	CLOSE.
C
47000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(IAND(OFLAG1(PRSO),CONTBT).EQ.0) GO TO 46050
	IF(OCAPAC(PRSO).NE.0) GO TO 47100
	CALL RSPSUB(411,ODO2)
C						!NOT CLOSABLE.
	RETURN
C
47100	IF(QOPEN(PRSO)) GO TO 47200
C						!OPEN?
	CALL RSPEAK(413)
C						!NO, JOKE.
	RETURN
C
47200	OFLAG2(PRSO)=IAND(OFLAG2(PRSO), not(OPENBT))
	CALL RSPEAK(414)
C						!DONE.
	RETURN
C VAPPLI, PAGE 7
C
C V127--	FIND.  BIG MEGILLA.
C
48000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	I=415
C						!DEFAULT CASE.
	IF(QHERE(PRSO,HERE)) GO TO 48300
C						!IN ROOM?
	IF(OADV(PRSO).EQ.WINNER) GO TO 48200
C						!ON WINNER?
	J=OCAN(PRSO)
C						!DOWN ONE LEVEL.
	IF(J.EQ.0) GO TO 10
	IF(((IAND(OFLAG1(J),TRANBT).EQ.0).AND.
     & (.NOT.QOPEN(J).OR.(IAND(OFLAG1(J),(DOORBT+CONTBT)).EQ.0))))
     &	GO TO 10
	I=417
C						!ASSUME IN ROOM.
	IF(QHERE(J,HERE)) GO TO 48100
	IF(OADV(J).NE.WINNER) GO TO 10
C						!NOT HERE OR ON PERSON.
	I=418
48100	CALL RSPSUB(I,ODESC2(J))
C						!DESCRIBE FINDINGS.
	RETURN
C
48200	I=416
48300	CALL RSPSUB(I,ODO2)
C						!DESCRIBE FINDINGS.
	RETURN
C
C V128--	WAIT.  RUN CLOCK DEMON.
C
49000	CALL RSPEAK(419)
C						!TIME PASSES.
	DO 49100 I=1,3
	  IF(CLOCKD()) RETURN
49100	CONTINUE
	RETURN
C
C V129--	SPIN.
C V159--	TURN TO.
C
50000	CONTINUE
88000	IF(.NOT.OBJACT()) CALL RSPEAK(663)
C						!IF NOT OBJ, JOKE.
	RETURN
C
C V130--	BOARD.  WORKS WITH VEHICLES.
C
51000	IF(IAND(OFLAG2(PRSO),VEHBT).NE.0) GO TO 51100
	CALL RSPSUB(421,ODO2)
C						!NOT VEHICLE, JOKE.
	RETURN
C
51100	IF(QHERE(PRSO,HERE)) GO TO 51200
C						!HERE?
	CALL RSPSUB(420,ODO2)
C						!NO, JOKE.
	RETURN
C
51200	IF(AV.EQ.0) GO TO 51300
C						!ALREADY GOT ONE?
	CALL RSPSUB(422,ODO2)
C						!YES, JOKE.
	RETURN
C
51300	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	CALL RSPSUB(423,ODO2)
C						!DESCRIBE.
	AVEHIC(WINNER)=PRSO
	IF(WINNER.NE.PLAYER) OCAN(AOBJ(WINNER))=PRSO
	RETURN
C
C V131--	DISEMBARK.
C
52000	IF(AV.EQ.PRSO) GO TO 52100
C						!FROM VEHICLE?
	CALL RSPEAK(424)
C						!NO, JOKE.
	RETURN
C
52100	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(IAND(RFLAG(HERE),RLAND).NE.0) GO TO 52200
	CALL RSPEAK(425)
C						!NOT ON LAND.
	RETURN
C
52200	AVEHIC(WINNER)=0
	CALL RSPEAK(426)
	IF(WINNER.NE.PLAYER) CALL NEWSTA(AOBJ(WINNER),0,HERE,0,0)
	RETURN
C
C V132--	TAKE.  HANDLED EXTERNALLY.
C
53000	VAPPLI=TAKE(.TRUE.)
	RETURN
C
C V133--	INVENTORY.  PROCESSED EXTERNALLY.
C
55000	CALL INVENT(WINNER)
	RETURN
C VAPPLI, PAGE 8
C
C V134--	FILL.  STRANGE DOINGS WITH WATER.
C
56000	IF(PRSI.NE.0) GO TO 56050
C						!ANY OBJ SPECIFIED?
	IF(IAND(RFLAG(HERE),(RWATER+RFILL)).NE.0) GO TO 56025
	CALL RSPEAK(516)
C						!NOTHING TO FILL WITH.
	PRSWON=.FALSE.
C						!YOU LOSE.
	RETURN
C
56025	PRSI=GWATE
C						!USE GLOBAL WATER.
56050	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF((PRSI.NE.GWATE).AND.(PRSI.NE.WATER))
     &	CALL RSPSB2(444,ODI2,ODO2)
	RETURN
C
C V135,V136--	EAT/DRINK
C
58000	CONTINUE
59000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(PRSO.EQ.GWATE) GO TO 59500
C						!DRINK GLOBAL WATER?
	IF(.NOT.EDIBLE(PRSO)) GO TO 59400
C						!EDIBLE?
	IF(OADV(PRSO).EQ.WINNER) GO TO 59200
C						!YES, ON WINNER?
59100	CALL RSPSUB(454,ODO2)
C						!NOT ACCESSIBLE.
	RETURN
C
59200	IF(PRSA.EQ.DRINKW) GO TO 59300
C						!DRINK FOOD?
	CALL NEWSTA(PRSO,455,0,0,0)
C						!NO, IT DISAPPEARS.
	RETURN
C
59300	CALL RSPEAK(456)
C						!YES, JOKE.
	RETURN
C
59400	IF(.NOT.DRKBLE(PRSO)) GO TO 59600
C						!DRINKABLE?
	IF(OCAN(PRSO).EQ.0) GO TO 59100
C						!YES, IN SOMETHING?
	IF(OADV(OCAN(PRSO)).NE.WINNER) GO TO 59100
	IF(QOPEN(OCAN(PRSO))) GO TO 59500
C						!CONT OPEN?
	CALL RSPEAK(457)
C						!NO, JOKE.
	RETURN
C
59500	CALL NEWSTA(PRSO,458,0,0,0)
C						!GONE.
	RETURN
C
59600	CALL RSPSUB(453,ODO2)
C						!NOT FOOD OR DRINK.
	RETURN
C
C V137--	BURN.  COMPLICATED.
C
60000	IF(IAND(OFLAG1(PRSI),(FLAMBT+LITEBT+ONBT)).NE.
     &	(FLAMBT+LITEBT+ONBT)) GO TO 60400
	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(OCAN(PRSO).NE.RECEP) GO TO 60050
C						!BALLOON?
	IF(OAPPLI(OACTIO(BALLO),0)) RETURN
C						!DID IT HANDLE?
60050	IF(IAND(OFLAG1(PRSO),BURNBT).EQ.0) GO TO 60300
	IF(OADV(PRSO).NE.WINNER) GO TO 60100
C						!CARRYING IT?
	CALL RSPSUB(459,ODO2)
	CALL JIGSUP(460)
	RETURN
C
60100	J=OCAN(PRSO)
C						!GET CONTAINER.
	IF(QHERE(PRSO,HERE).OR. ((AV.NE.0).AND.(J.EQ.AV)))
     &	GO TO 60200
	IF(J.EQ.0) GO TO 60150
C						!INSIDE?
	IF(.NOT.QOPEN(J)) GO TO 60150
C						!OPEN?
	IF(QHERE(J,HERE).OR.((AV.NE.0).AND.(OCAN(J).EQ.AV)))
     &	GO TO 60200
60150	CALL RSPEAK(461)
C						!CANT REACH IT.
	RETURN
C
60200	CALL RSPSUB(462,ODO2)
C						!BURN IT.
	CALL NEWSTA(PRSO,0,0,0,0)
	RETURN
C
60300	CALL RSPSUB(463,ODO2)
C						!CANT BURN IT.
	RETURN
C
60400	CALL RSPSUB(301,ODI2)
C						!CANT BURN IT WITH THAT.
	RETURN
C VAPPLI, PAGE 9
C
C V138--	MUNG.  GO TO COMMON ATTACK CODE.
C
63000	I=466
C						!CHOOSE PHRASE.
	IF(IAND(OFLAG2(PRSO),VILLBT).NE.0) GO TO 66100
	IF(.NOT.OBJACT()) CALL RSPSB2(466,ODO2,RMK)
	RETURN
C
C V139--	KILL.  GO TO COMMON ATTACK CODE.
C
64000	I=467
C						!CHOOSE PHRASE.
	GO TO 66100
C
C V140--	SWING.  INVERT OBJECTS, FALL THRU TO ATTACK.
C
65000	J=PRSO
C						!INVERT.
	PRSO=PRSI
	PRSI=J
	J=ODO2
	ODO2=ODI2
	ODI2=J
	PRSA=ATTACW
C						!FOR OBJACT.
C
C V141--	ATTACK.  FALL THRU TO ATTACK CODE.
C
66000	I=468
C
C COMMON MUNG/ATTACK/SWING/KILL CODE.
C
66100	IF(PRSO.NE.0) GO TO 66200
C						!ANYTHING?
	CALL RSPEAK(469)
C						!NO, JOKE.
	RETURN
C
66200	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(IAND(OFLAG2(PRSO),VILLBT).NE.0) GO TO 66300
	IF(IAND(OFLAG1(PRSO),VICTBT).EQ.0)
     &	CALL RSPSUB(470,ODO2)
	RETURN
C
66300	J=471
C						!ASSUME NO WEAPON.
	IF(PRSI.EQ.0) GO TO 66500
	IF(IAND(OFLAG2(PRSI),WEAPBT).EQ.0) GO TO 66400
	MELEE=1
C						!ASSUME SWORD.
	IF(PRSI.NE.SWORD) MELEE=2
C						!MUST BE KNIFE.
	I=BLOW(PLAYER,PRSO,MELEE,.TRUE.,0)
C						!STRIKE BLOW.
	RETURN
C
66400	J=472
C						!NOT A WEAPON.
66500	CALL RSPSB2(I,ODO2,J)
C						!JOKE.
	RETURN
C VAPPLI, PAGE 10
C
C V142--	WALK.  PROCESSED EXTERNALLY.
C
68000	VAPPLI=WALK()
	RETURN
C
C V143--	TELL.  PROCESSED IN GAME.
C
69000	CALL RSPEAK(603)
	RETURN
C
C V144--	PUT.  PROCESSED EXTERNALLY.
C
70000	VAPPLI=PUT()
	RETURN
C
C V145,V146,V147,V148--	DROP/GIVE/POUR/THROW
C
71000	CONTINUE
72000	CONTINUE
73000	CONTINUE
74000	VAPPLI=DROP()
	RETURN
C
C V149--	SAVE
C
77000	IF(IAND(RFLAG(TSTRS),RSEEN).EQ.0) GO TO 77100
	CALL RSPEAK(828)
C						!NO SAVES IN ENDGAME.
	RETURN
C
77100	CALL SAVEGM
	RETURN
C
C V150--	RESTORE
C
78000	IF(IAND(RFLAG(TSTRS),RSEEN).EQ.0) GO TO 78100
	CALL RSPEAK(829)
C						!NO RESTORES IN ENDGAME.
 	RETURN
C
78100	CALL RSTRGM

	RETURN
C VAPPLI, PAGE 11
C
C V151--	HELLO
C
80000	IF(PRSO.NE.0) GO TO 80100
C						!ANY OBJ?
	CALL RSPEAK(346+RND(4))
C						!NO, VANILLA HELLO.
	RETURN
C
80100	IF(PRSO.NE.AVIAT) GO TO 80200
C						!HELLO AVIATOR?
	CALL RSPEAK(350)
C						!NOTHING HAPPENS.
	RETURN
C
80200	IF(PRSO.NE.SAILO) GO TO 80300
C						!HELLO SAILOR?
	HS=HS+1
C						!COUNT.
	I=351
C						!GIVE NORMAL OR
	IF(MOD(HS,10).EQ.0) I=352
C						!RANDOM MESSAGE.
	IF(MOD(HS,20).EQ.0) I=353
	CALL RSPEAK(I)
C						!SPEAK UP.
	RETURN
C
80300	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	I=354
C						!ASSUME VILLAIN.
	IF(IAND(OFLAG2(PRSO),(VILLBT+ACTRBT)).EQ.0) I=355
	CALL RSPSUB(I,ODO2)
C						!HELLO THERE
C						!
	RETURN
C
C V152--	LOOK INTO
C
81000	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	IF(IAND(OFLAG1(PRSO),DOORBT).EQ.0) GO TO 81300
	IF(.NOT.QOPEN(PRSO)) GO TO 81200
C						!OPEN?
	CALL RSPSUB(628,ODO2)
C						!OPEN DOOR- UNINTERESTING.
	RETURN
C
81200	CALL RSPSUB(525,ODO2)
C						!CLOSED DOOR- CANT SEE.
	RETURN
C
81300	IF(IAND(OFLAG2(PRSO),VEHBT).NE.0) GO TO 81400
	IF(QOPEN(PRSO).OR.(IAND(OFLAG1(PRSO),TRANBT).NE.0))
     &	GO TO 81400
	IF(IAND(OFLAG1(PRSO),CONTBT).NE.0) GO TO 81200
	CALL RSPSUB(630,ODO2)
C						!CANT LOOK INSIDE.
	RETURN
C
81400	IF(QEMPTY(PRSO)) GO TO 81500
C						!VEH OR SEE IN.  EMPTY?
	CALL PRINCO(PRSO,573)
C						!NO, LIST CONTENTS.
	RETURN
C
81500	CALL RSPSUB(629,ODO2)
C						!EMPTY.
	RETURN
C
C V153--	LOOK UNDER
C
82000	IF(.NOT.OBJACT()) CALL RSPEAK(631)
C						!OBJECT HANDLE?
	RETURN
C VAPPLI, PAGE 12
C
C V154--	PUMP
C
83000	IF((OROOM(PUMP).EQ.HERE).OR.(OADV(PUMP).EQ.WINNER))
     &	GO TO 83100
	CALL RSPEAK(632)
C						!NO.
	RETURN
C
83100	PRSI=PUMP
C						!BECOMES INFLATE
	PRSA=INFLAW
C						!X WITH PUMP.
	GO TO 22000
C						!DONE.
C
C V155--	WIND
C
84000	IF(.NOT.OBJACT()) CALL RSPSUB(634,ODO2)
C						!OBJ HANDLE?
	RETURN
C
C V156--	CLIMB
C V157--	CLIMB UP
C V158--	CLIMB DOWN
C
85000	CONTINUE
86000	CONTINUE
87000	I=XUP
C						!ASSUME UP.
	IF(PRSA.EQ.CLMBDW) I=XDOWN
C						!UNLESS CLIMB DN.
	F=(IAND(OFLAG2(PRSO),CLMBBT)).NE.0
	IF(F.AND.FINDXT(I,HERE)) GO TO 87500
C						!ANYTHING TO CLIMB?
	IF(OBJACT()) RETURN
C						!OBJ HANDLE?
	I=657
	IF(F) I=524
C						!VARIETY OF JOKES.
	IF(.NOT.F .AND.((PRSO.EQ.WALL).OR.
     &	((PRSO.GE.WNORT).AND.(PRSO.LE.WNORT+3))))
     &	I=656
	CALL RSPEAK(I)
C						!JOKE.
	RETURN
C
87500	PRSA=WALKW
C						!WALK
	PRSO=I
C						!IN SPECIFIED DIR.
	VAPPLI=WALK()
	RETURN
	END
C
C Clock demon for intermove clock events
	LOGICAL FUNCTION CLOCKD()
	IMPLICIT INTEGER (A-Z)
C
C CLOCK INTERRUPTS
C
	include 'clock.h'
C
	CLOCKD=.FALSE.
C						!ASSUME NO ACTION.
	DO 100 I=1,CLNT
	  IF(.NOT.CFLAG(I) .OR.(CTICK(I).EQ.0)) GO TO 100
	  IF(CTICK(I).LT.0) GO TO 50
C						!PERMANENT ENTRY?
	  CTICK(I)=CTICK(I)-1
	  IF(CTICK(I).NE.0) GO TO 100
C						!TIMER EXPIRED?
50	  CLOCKD=.TRUE.
	  CALL CEVAPP(CACTIO(I))
C						!DO ACTION.
100	CONTINUE
	RETURN
	END
