C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C RAPPL2- SPECIAL PURPOSE ROOM ROUTINES, PART 2
	LOGICAL FUNCTION RAPPL2(RI)
	IMPLICIT INTEGER (A-Z)
	LOGICAL QOPEN,QHERE
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'io.h'
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'objects.h'
	include 'oflags.h'
	include 'oindex.h'
	include 'xsrch.h'
	include 'clock.h'
	include 'advers.h'
	include 'verbs.h'
	include 'flags.h'
C
C In-line function
	QOPEN(R)=iand(OFLAG2(R),OPENBT).NE.0
C
C Initialized data
	DATA NEWRMS/38/
C RAPPL2, PAGE 2
C
	RAPPL2=.TRUE.
	GO TO (38000,39000,40000,41000,42000,43000,44000,
     &	45000,46000,47000,48000,49000,50000,
     &	51000,52000,53000,54000,55000,56000,
     &	57000,58000,59000,60000),
     &	(RI-NEWRMS+1)
	CALL BUG(70,RI)
	RETURN
C
C R38--	MIRROR D ROOM
C
38000	IF(PRSA.EQ.LOOKW) CALL LOOKTO(FDOOR,MRG,0,682,681)
	RETURN
C
C R39--	MIRROR G ROOM
C
39000	IF(PRSA.EQ.WALKIW) CALL JIGSUP(685)
	RETURN
C
C R40--	MIRROR C ROOM
C
40000	IF(PRSA.EQ.LOOKW) CALL LOOKTO(MRG,MRB,683,0,681)
	RETURN
C
C R41--	MIRROR B ROOM
C
41000	IF(PRSA.EQ.LOOKW) CALL LOOKTO(MRC,MRA,0,0,681)
	RETURN
C
C R42--	MIRROR A ROOM
C
42000	IF(PRSA.EQ.LOOKW) CALL LOOKTO(MRB,0,0,684,681)
	RETURN
C RAPPL2, PAGE 3
C
C R43--	MIRROR C EAST/WEST
C
43000	IF(PRSA.EQ.LOOKW) CALL EWTELL(HERE,683)
	RETURN
C
C R44--	MIRROR B EAST/WEST
C
44000	IF(PRSA.EQ.LOOKW) CALL EWTELL(HERE,686)
	RETURN
C
C R45--	MIRROR A EAST/WEST
C
45000	IF(PRSA.EQ.LOOKW) CALL EWTELL(HERE,687)
	RETURN
C
C R46--	INSIDE MIRROR
C
46000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(688)
C						!DESCRIBE
C
C NOW DESCRIBE POLE STATE.
C
C CASES 1,2--	MDIR=270 & MLOC=MRB, POLE IS UP OR IN HOLE
C CASES 3,4--	MDIR=0 V MDIR=180, POLE IS UP OR IN CHANNEL
C CASE 5--	POLE IS UP
C
	I=689
C						!ASSUME CASE 5.
	IF((MDIR.EQ.270).AND.(MLOC.EQ.MRB))
     &	I=690+MIN0(POLEUF,1)
	IF(MOD(MDIR,180).EQ.0)
     &	I=692+MIN0(POLEUF,1)
	CALL RSPEAK(I)
C						!DESCRIBE POLE.
	CALL RSPSUB(694,695+(MDIR/45))
C						!DESCRIBE ARROW.
	RETURN
C RAPPL2, PAGE 4
C
C R47--	MIRROR EYE ROOM
C
47000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=704
C						!ASSUME BEAM STOP.
	DO 47100 J=1,OLNT
	  IF(QHERE(J,HERE).AND.(J.NE.RBEAM)) GO TO 47200
47100	CONTINUE
	I=703
47200	CALL RSPSUB(I,ODESC2(J))
C						!DESCRIBE BEAM.
	CALL LOOKTO(MRA,0,0,0,0)
C						!LOOK NORTH.
	RETURN
C
C R48--	INSIDE CRYPT
C
48000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=46
C						!CRYPT IS OPEN/CLOSED.
	IF(QOPEN(TOMB)) I=12
	CALL RSPSUB(705,I)
	RETURN
C
C R49--	SOUTH CORRIDOR
C
49000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL RSPEAK(706)
C						!DESCRIBE.
	I=46
C						!ODOOR IS OPEN/CLOSED.
	IF(QOPEN(ODOOR)) I=12
	IF(LCELL.EQ.4) CALL RSPSUB(707,I)
C						!DESCRIBE ODOOR IF THERE.
	RETURN
C
C R50--	BEHIND DOOR
C
50000	IF(PRSA.NE.WALKIW) GO TO 50100
C						!WALK IN?
	CFLAG(CEVFOL)=.TRUE.
C						!MASTER FOLLOWS.
	CTICK(CEVFOL)=-1
	RETURN
C
50100	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=46
C						!QDOOR IS OPEN/CLOSED.
	IF(QOPEN(QDOOR)) I=12
	CALL RSPSUB(708,I)
	RETURN
C RAPPL2, PAGE 5
C
C R51--	FRONT DOOR
C
51000	IF(PRSA.EQ.WALKIW) CTICK(CEVFOL)=0
C						!IF EXITS, KILL FOLLOW.
	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	CALL LOOKTO(0,MRD,709,0,0)
C						!DESCRIBE SOUTH.
	I=46
C						!PANEL IS OPEN/CLOSED.
	IF(INQSTF) I=12
C						!OPEN IF INQ STARTED.
	J=46
C						!QDOOR IS OPEN/CLOSED.
	IF(QOPEN(QDOOR)) J=12
	CALL RSPSB2(710,I,J)
	RETURN
C
C R52--	NORTH CORRIDOR
C
52000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=46
	IF(QOPEN(CDOOR)) I=12
C						!CDOOR IS OPEN/CLOSED.
	CALL RSPSUB(711,I)
	RETURN
C
C R53--	PARAPET
C
53000	IF(PRSA.EQ.LOOKW) CALL RSPSUB(712,712+PNUMB)
	RETURN
C
C R54--	CELL
C
54000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=721
C						!CDOOR IS OPEN/CLOSED.
	IF(QOPEN(CDOOR)) I=722
	CALL RSPEAK(I)
	I=46
C						!ODOOR IS OPEN/CLOSED.
	IF(QOPEN(ODOOR)) I=12
	IF(LCELL.EQ.4) CALL RSPSUB(723,I)
C						!DESCRIBE.
	RETURN
C
C R55--	PRISON CELL
C
55000	IF(PRSA.EQ.LOOKW) CALL RSPEAK(724)
C						!LOOK?
	RETURN
C
C R56--	NIRVANA CELL
C
56000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=46
C						!ODOOR IS OPEN/CLOSED.
	IF(QOPEN(ODOOR)) I=12
	CALL RSPSUB(725,I)
	RETURN
C RAPPL2, PAGE 6
C
C R57--	NIRVANA AND END OF GAME
C
57000	IF(PRSA.NE.WALKIW) RETURN
C						!WALKIN?
	CALL RSPEAK(726)
	CALL SCORE(.FALSE.)
C moved to exit routine	CLOSE(DBCH)
	CALL EXIT
C
C R58--	TOMB ROOM
C
58000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=46
C						!TOMB IS OPEN/CLOSED.
	IF(QOPEN(TOMB)) I=12
	CALL RSPSUB(792,I)
	RETURN
C
C R59--	PUZZLE SIDE ROOM
C
59000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	I=861
C						!ASSUME DOOR CLOSED.
	IF(CPOUTF) I=862
C						!OPEN?
	CALL RSPEAK(I)
C						!DESCRIBE.
	RETURN
C
C R60--	PUZZLE ROOM
C
60000	IF(PRSA.NE.LOOKW) RETURN
C						!LOOK?
	IF(CPUSHF) GO TO 60100
C						!STARTED PUZZLE?
	CALL RSPEAK(868)
C						!NO, DESCRIBE.
	IF(iand(OFLAG2(WARNI),TCHBT).NE.0) CALL RSPEAK(869)
	RETURN
C
60100	CALL CPINFO(880,CPHERE)
C						!DESCRIBE ROOM.
	RETURN
	END
C
C LOOKTO--	DESCRIBE VIEW IN MIRROR HALLWAY
	SUBROUTINE LOOKTO(NRM,SRM,NT,ST,HT)
	IMPLICIT INTEGER(A-Z)
	include 'gamestat.h'
	include 'flags.h'
C LOOKTO, PAGE 2
C
	CALL RSPEAK(HT)
C						!DESCRIBE HALL.
	CALL RSPEAK(NT)
C						!DESCRIBE NORTH VIEW.
	CALL RSPEAK(ST)
C						!DESCRIBE SOUTH VIEW.
	DIR=0
C						!ASSUME NO DIRECTION.
	IF(IABS(MLOC-HERE).NE.1) GO TO 200
C						!MIRROR TO N OR S?
	IF(MLOC.EQ.NRM) DIR=695
	IF(MLOC.EQ.SRM) DIR=699
C						!DIR=N/S.
	IF(MOD(MDIR,180).NE.0) GO TO 100
C						!MIRROR N-S?
	CALL RSPSUB(847,DIR)
C						!YES, HE SEES PANEL
	CALL RSPSB2(848,DIR,DIR)
C						!AND NARROW ROOMS.
	GO TO 200
C
100	M1=MRHERE(HERE)
C						!WHICH MIRROR?
	MRBF=0
C						!ASSUME INTACT.
	IF(((M1.EQ.1).AND..NOT.MR1F).OR.
     &	((M1.EQ.2).AND..NOT.MR2F)) MRBF=1
	CALL RSPSUB(849+MRBF,DIR)
C						!DESCRIBE.
	IF((M1.EQ.1).AND.MROPNF) CALL RSPEAK(823+MRBF)
	IF(MRBF.NE.0) CALL RSPEAK(851)
C
200	I=0
C						!ASSUME NO MORE TO DO.
	IF((NT.EQ.0).AND.((DIR.EQ.0).OR.(DIR.EQ.699))) I=852
	IF((ST.EQ.0).AND.((DIR.EQ.0).OR.(DIR.EQ.695))) I=853
	IF((NT+ST+DIR).EQ.0) I=854
	IF(HT.NE.0) CALL RSPEAK(I)
C						!DESCRIBE HALLS.
	RETURN
	END
C
C EWTELL--	DESCRIBE E/W NARROW ROOMS
	SUBROUTINE EWTELL(RM,ST)
	IMPLICIT INTEGER(A-Z)
	LOGICAL M1
C
C ROOMS
	include 'rindex.h'
	include 'flags.h'
C EWTELL, PAGE 2
C
C NOTE THAT WE ARE EAST OR WEST OF MIRROR, AND
C MIRROR MUST BE N-S.
C
	M1=(MDIR+(MOD(RM-MRAE,2)*180)).EQ.180
	I=819+MOD(RM-MRAE,2)
C						!GET BASIC E/W STRING.
	IF((M1.AND..NOT.MR1F).OR.(.NOT.M1.AND..NOT.MR2F))
     &	I=I+2
	CALL RSPEAK(I)
	IF(M1.AND.MROPNF) CALL RSPEAK(823+((I-819)/2))
	CALL RSPEAK(825)
	CALL RSPEAK(ST)
	RETURN
	END
