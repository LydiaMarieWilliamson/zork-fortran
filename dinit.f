C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Dungeon initialization subroutine
	LOGICAL FUNCTION INIT()
	IMPLICIT INTEGER (A-Z)
	LOGICAL PROTCT
	INTEGER*4 TIME2001
	include 'parser.h'
	include 'gamestat.h'
	include 'state.h'
	include 'screen.h'
	include 'mindex.h'
C
C MISCELLANEOUS VARIABLES
C
	INTEGER AC
	CHARACTER(100) SEEDS
	INTEGER*4 SEED
        CHARACTER VEDIT
	INTEGER*4 PLTIME,STIME
	COMMON /STAR/ MBASE,STRBIT
	COMMON /VERS/ VMAJ,VMIN,VEDIT
	COMMON /TIME/ PLTIME,STIME
	include 'io.h'
	include 'debug.h'
	COMMON /HYPER/ HFACTR
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'exits.h'
	include 'curxt.h'
	include 'xpars.h'
	include 'objects.h'
	include 'oindex.h'
	include 'clock.h'
	include 'villians.h'
	include 'advers.h'
	include 'flags.h'
C INIT, PAGE 2
C
C FIRST CHECK FOR PROTECTION VIOLATION
C
	IF(PROTCT()) GO TO 10000
C						!PROTECTION VIOLATION?
	PRINT 10100
10100	FORMAT('There appears before you a threatening figure clad ',
     &'all over'/'in heavy black armor.  His legs seem like the ',
     &'massive trunk'/'of the oak tree.  His broad shoulders and ',
     &'helmeted head loom'/'high over your own puny frame, and ',
     &'you realize that his powerful'/'arms could easily crush the ',
     &'very life from your body.  There'/'hangs from his belt a ',
     &'veritable arsenal of deadly weapons:'/'sword, mace, ball ',
     &'and chain, dagger, lance, and trident.'/'He speaks with a ',
     &'commanding voice:'//20X,'"You shall not pass."'//'As ',
     &'he grabs you by the neck all grows dim about you.')
	CALL EXIT
C
C NOW START INITIALIZATION PROPER
C
10000	INIT=.FALSE.
C						!ASSUME INIT FAILS.
	MMAX=1050
C						!SET UP ARRAY LIMITS.
	OMAX=220
	RMAX=200
	VMAX=4
	AMAX=4
	CMAX=25
	FMAX=46
	SMAX=22
	XMAX=900
	R2MAX=20
C
	MLNT=0
C						!INIT ARRAY COUNTERS.
	OLNT=0
	RLNT=0
	VLNT=0
	ALNT=0
	CLNT=0
	XLNT=1
	R2LNT=0
C
	LTSHFT=10
C						!SET UP STATE VARIABLES.
	MXSCOR=LTSHFT
	EGSCOR=0
	EGMXSC=0
	MXLOAD=100
	RWSCOR=0
	DEATHS=0
	MOVES=0
	PLTIME=0
	MUNGRM=0
	HS=0
	PRSA=0
C						!CLEAR PARSE VECTOR.
	PRSI=0
	PRSO=0
	PRSCON=1
	OFLAG=0
C						!CLEAR ORPHANS.
	OACT=0
	OSLOT=0
	OPREP=0
	ONAME=0
	THFFLG=.FALSE.
C						!THIEF NOT INTRODUCED BUT
	THFACT=.TRUE.
C						!IS ACTIVE.
	SWDACT=.FALSE.
C						!SWORD IS INACTIVE.
	SWDSTA=0
C						!SWORD IS OFF.
C
	MBASE=0
C						!INIT MELEE BASE.
C   LOGICAL UNIT NRS: 5=STDIN, 6=STDOUT
	INPCH=5
C						!TTY INPUT
	OUTCH=6
	INDEXCH=1
	STORYCH=2
C						!DATA BASE.
C INIT, PAGE 3
C
C INIT ALL ARRAYS.
C
	DO 5 I=1,CMAX
C						!CLEAR CLOCK EVENTS
	  CFLAG(I)=.FALSE.
	  CTICK(I)=0
	  CACTIO(I)=0
5	CONTINUE
C
	DO 10 I=1,FMAX
C						!CLEAR FLAGS.
	  FLAGS(I)=.FALSE.
10	CONTINUE
	BUOYF=.TRUE.
C						!SOME START AS TRUE.
	EGYPTF=.TRUE.
	CAGETF=.TRUE.
	MR1F=.TRUE.
	MR2F=.TRUE.
	FOLLWF=.TRUE.
	DO 12 I=1,SMAX
C						!CLEAR SWITCHES.
	  SWITCH(I)=0
12	CONTINUE
	ORMTCH=4
C						!NUMBER OF MATCHES.
	LCELL=1
	PNUMB=1
	MDIR=270
	MLOC=MRB
	CPHERE=10
C
	DO 15 I=1,R2MAX
C						!CLEAR ROOM 2 ARRAY.
	  RROOM2(I)=0
	  OROOM2(I)=0
15	CONTINUE
C
	DO 20 I=1,XMAX
C						!CLEAR TRAVEL ARRAY.
	  TRAVEL(I)=0
20	CONTINUE
C
	DO 30 I=1,VMAX
C						!CLEAR VILLAINS ARRAYS.
	  VOPPS(I)=0
	  VPROB(I)=0
	  VILLNS(I)=0
	  VBEST(I)=0
	  VMELEE(I)=0
30	CONTINUE
C
	DO 40 I=1,OMAX
C						!CLEAR OBJECT ARRAYS.
	  ODESC1(I)=0
	  ODESC2(I)=0
	  ODESCO(I)=0
	  OREAD(I)=0
	  OACTIO(I)=0
	  OFLAG1(I)=0
	  OFLAG2(I)=0
	  OFVAL(I)=0
	  OTVAL(I)=0
	  OSIZE(I)=0
	  OCAPAC(I)=0
	  OCAN(I)=0
	  OADV(I)=0
	  OROOM(I)=0
40	CONTINUE
C
	DO 50 I=1,RMAX
C						!CLEAR ROOM ARRAYS.
	  RDESC1(I)=0
	  RDESC2(I)=0
	  RACTIO(I)=0
	  RFLAG(I)=0
	  RVAL(I)=0
	  REXIT(I)=0
50	CONTINUE
C
	DO 60 I=1,MMAX
C						!CLEAR MESSAGE DIRECTORY.
	  RTEXT(I)=0
60	CONTINUE
C
	DO 70 I=1,AMAX
C						!CLEAR ADVENTURER'S ARRAYS.
	  AROOM(I)=0
	  ASCORE(I)=0
	  AVEHIC(I)=0
	  AOBJ(I)=0
	  AACTIO(I)=0
	  ASTREN(I)=0
	  AFLAG(I)=0
70	CONTINUE
C
	DBGFLG=0
	PRSFLG=0
C
C allow setting gdtflg true if user id matches wizard id
C this way, the wizard doesn't have to recompile to use gdt
C
C	Changed by TAA so that always in wizard ID
D	gdtflg=1
C
	FROMDR=0
C						!INIT SCOL GOODIES.
	SCOLRM=0
	SCOLAC=0
C INIT, PAGE 4
C
C NOW RESTORE FROM EXISTING INDEX FILE.
C
C	OPEN(UNIT=INDEXCH,file='/usr/share/games/dungeon/dindx.dat',
	OPEN(UNIT=INDEXCH,file='dindx.dat',
     &	status='OLD',FORM='FORMATTED',ACCESS='SEQUENTIAL',ERR=1900)
	READ(INDEXCH,*) I,J,K
C						!GET VERSION.
	IF((I.NE.VMAJ).OR.(J.NE.VMIN))
     &	GO TO 1925

C	OPEN(UNIT=STORYCH,file='/usr/share/games/dungeon/dtext.dat',
	OPEN(UNIT=STORYCH,file='dtext.dat',
     &	STATUS='OLD',ACCESS='STREAM',ERR=1950)

D	PRINT 150
D150	FORMAT('RESTORING FROM "dindx.dat"')
	READ(INDEXCH,*) MXSCOR,EGMXSC
	READ(INDEXCH,*) RLNT,RDESC1(1:RLNT),RDESC2(1:RLNT),REXIT(1:RLNT),
     &	RACTIO(1:RLNT),RVAL(1:RLNT),RFLAG(1:RLNT)
	READ(INDEXCH,*) XLNT,TRAVEL(1:XLNT)
	READ(INDEXCH,*) OLNT,ODESC1(1:OLNT),ODESC2(1:OLNT),ODESCO(1:OLNT),
     &	OACTIO(1:OLNT),OFLAG1(1:OLNT),OFLAG2(1:OLNT),OFVAL(1:OLNT),
     &	OTVAL(1:OLNT),OSIZE(1:OLNT),OCAPAC(1:OLNT),OROOM(1:OLNT),
     &	OADV(1:OLNT),OCAN(1:OLNT),OREAD(1:OLNT)
	READ(INDEXCH,*) R2LNT,OROOM2(1:R2LNT),RROOM2(1:R2LNT)
	READ(INDEXCH,*) CLNT,CTICK(1:CLNT),CACTIO(1:CLNT)
	READ(INDEXCH,*) CFLAG(1:CLNT)
	READ(INDEXCH,*) VLNT,VILLNS(1:VLNT),VPROB(1:VLNT),VOPPS(1:VLNT),
     &	VBEST(1:VLNT),VMELEE(1:VLNT)
	READ(INDEXCH,*) ALNT,AROOM(1:ALNT),ASCORE(1:ALNT),AVEHIC(1:ALNT),
     &	AOBJ(1:ALNT),AACTIO(1:ALNT),ASTREN(1:ALNT),AFLAG(1:ALNT)
	READ(INDEXCH,*) STRBIT,MBASE
	READ(INDEXCH,*) MLNT,RTEXT(1:MLNT)
C
	CLOSE(INDEXCH)
	GO TO 1025
C						!INIT DONE.
C
C130	FORMAT(I8)
C130	FORMAT(I6)
C135	FORMAT(L4)
C INIT, PAGE 5
C
C THE INTERNAL DATA BASE IS NOW ESTABLISHED.
C SET UP TO PLAY THE GAME.
C
1025	STIME=TIME2001()
C						!GET TIMESTAMP.
C	https://riptutorial.com/fortran/example/26615/passing-command-line-arguments
C	Check for the number of inputs.
	AC=COMMAND_ARGUMENT_COUNT()
	IF(AC.LT.1)THEN
	   SEED=STIME
	ELSEIF(AC.LT.2)THEN
C	Read in the and convert it to a long integer.
	   CALL GET_COMMAND_ARGUMENT(1,SEEDS)
	   READ(SEEDS,*,ERR=1850)SEED
	ELSE
	   GO TO 1875
	ENDIF
	CALL INIRND(SEED)
C
	WINNER=PLAYER
	LASTIT=AOBJ(PLAYER)
	HERE=AROOM(WINNER)
	THFPOS=OROOM(THIEF)
	BLOC=OROOM(BALLO)
	INIT=.TRUE.
C
D	PRINT 1050,RLNT,RMAX,XLNT,XMAX,OLNT,OMAX,MLNT,MMAX,
D    &  VLNT,VMAX,ALNT,AMAX,CLNT,CMAX,R2LNT,R2MAX
D1050	FORMAT('USED:'/I5,' OF',I5,' ROOMS'/
D    &  I5,' OF',I5,' EXITS'/
D    &  I5,' OF',I5,' OBJECTS'/
D    &  I5,' OF',I5,' MESSAGES'/
D    &  I5,' OF',I5,' VILLAINS'/
D    &  I5,' OF',I5,' ADVENTURERS'/
D    &  I5,' OF',I5,' CLOCK EVENTS'/
D    &  I5,' OF',I5,' ROOM2 SLOTS')
D	PRINT 1150,MXSCOR,EGMXSC,STRBIT,MBASE
D1150	FORMAT('MAX SCORE=',I5/'EG SCORE=',I5/
D    &  'STAR MASK=',I7/'MELEE START=',I5)
D	PAUSE 1
C
	RETURN
C INIT, PAGE 6
C
C ERRORS-- INIT FAILS.
C
1850	WRITE(*,*)'Invalid random number seed: ',SEEDS,'.'
	GO TO 1975
1875	WRITE(*,*)'Too many command line arguments ',AC,'.'
	WRITE(*,*)'Usage: dungeon [Seed].'
	GO TO 1975
1900	PRINT 910
	GO TO 1975
1925	PRINT 920,I,J,K,VMAJ,VMIN,VEDIT
	GO TO 1975
1950	PRINT 960
1975    PRINT 980
	RETURN
910	FORMAT('I can''t open ','dindx.dat','.')
920	FORMAT('"dindx.dat" is version ',I1,'.',I1,A1,'.'/
     &	'I require version ',I1,'.',I1,A1,'.')
960	FORMAT('I can''t open ','dtext.dat','.')
980	FORMAT('Suddenly a sinister, wraithlike figure appears before ',
     &'you,'/'seeming to float in the air.  In a low, sorrowful voice',
     &' he says,'/'"Alas, the very nature of the world has changed, ',
     &'and the dungeon'/'cannot be found.  All must now pass away."',
     &'  Raising his oaken staff'/'in farewell, he fades into the ',
     &'spreading darkness.  In his place'/'appears a tastefully ',
     &'lettered sign reading:'//23X,'INITIALIZATION FAILURE'//
     &'The darkness becomes all encompassing, and your vision fails.')
	END
C
C Check for user violation
C This routine should be modified if you wish to add system
C dependent protection against abuse.
C
C At the moment, play is permitted under all circumstances.
	LOGICAL FUNCTION PROTCT()
	IMPLICIT INTEGER(A-Z)
C
	PROTCT=.TRUE.
	RETURN
	END

