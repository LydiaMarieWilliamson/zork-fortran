C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C Encrypt password
	SUBROUTINE ENCRYP(INW,OUTW)
	IMPLICIT INTEGER(A-Z)
	CHARACTER INW(6),OUTW(6)
	CHARACTER  KEYW(6),UKEYW(6)
	INTEGER UINW(6)
	DATA KEYW/'E','C','O','R','M','S'/
C
	UINWS=0
C						!UNBIASED INW SUM.
	UKEYWS=0
C						!UNBIASED KEYW SUM.
	J=1
C						!POINTER IN KEYWORD.
	DO 100 I=1,6
C						!UNBIAS, COMPUTE SUMS.
	  UKEYW(I)=char(ichar(KEYW(I))-64)
	  IF(INW(J).LE.char(64)) J=1
C	  UINW(I)=char(ichar(INW(J))-64)
	  UINW(I)=ichar(INW(J))-64
	  UKEYWS=UKEYWS+ichar(UKEYW(I))
	  UINWS=UINWS+UINW(I)
	  J=J+1
100	CONTINUE
C
	USUM=MOD(UINWS,8)+(8*MOD(UKEYWS,8))
C						!COMPUTE MASK.
	DO 200 I=1,6
	  J=IAND(IEOR(IEOR(UINW(I),ichar(UKEYW(I))),USUM),31)
	  USUM=MOD(USUM+1,32)
	  IF(J.GT.26) J=MOD(J,26)
	  OUTW(I)=char(MAX0(1,J)+64)
200	CONTINUE
	RETURN
	END
C
C Move to next state in puzzle room
	SUBROUTINE CPGOTO(ST)
	IMPLICIT INTEGER(A-Z)
C
	COMMON /HYPER/ HFACTR
	include 'rooms.h'
	include 'rflag.h'
	include 'rindex.h'
	include 'objects.h'
	include 'oflags.h'
	include 'flags.h'
C CPGOTO, PAGE 2
C
	RFLAG(CPUZZ)=IAND(RFLAG(CPUZZ),not(RSEEN))
	DO 100 I=1,OLNT
C						!RELOCATE OBJECTS.
	  IF((OROOM(I).EQ.CPUZZ).AND.
     &	(IAND(OFLAG2(I),(ACTRBT+VILLBT)).EQ.0))
     &	CALL NEWSTA(I,0,CPHERE*HFACTR,0,0)
	  IF(OROOM(I).EQ.(ST*HFACTR))
     &	CALL NEWSTA(I,0,CPUZZ,0,0)
100	CONTINUE
	CPHERE=ST
	RETURN
	END
C
C Describe puzzle room
	SUBROUTINE CPINFO(RMK,ST)
	IMPLICIT INTEGER(A-Z)
	INTEGER DGMOFT(8)
	CHARACTER  DGM(8),PICT(5)
C
	COMMON /CHAN/ INPCH,OUTCH,INDEXCH,STORYCH
C
C PUZZLE ROOM
C
	COMMON /PUZZLE/ CPDR(16),CPWL(8),CPVEC(64)
	include 'flags.h'
C
C FUNCTIONS AND LOCAL DATA
C
C
	DATA DGMOFT/-9,-8,-7,-1,1,7,8,9/
	DATA PICT/'S','S','S',' ','M'/
C CPINFO, PAGE 2
C
	CALL RSPEAK(RMK)
	DO 100 I=1,8
	  J=DGMOFT(I)
	  DGM(I)=PICT(CPVEC(ST+J)+4)
C						!GET PICTURE ELEMENT.
	  IF((IABS(J).EQ.1).OR.(IABS(J).EQ.8)) GO TO 100
	  K=8
	  IF(J.LT.0) K=-8
C						!GET ORTHO DIR.
	  L=J-K
	  IF((CPVEC(ST+K).NE.0).AND.(CPVEC(ST+L).NE.0))
     &	DGM(I)='?'
100	CONTINUE
 	WRITE(OUTCH,10) DGM
C
	IF(ST.EQ.10) CALL RSPEAK(870)
C						!AT HOLE?
	IF(ST.EQ.37) CALL RSPEAK(871)
C						!AT NICHE?
	I=872
C						!DOOR OPEN?
	IF(CPOUTF) I=873
	IF(ST.EQ.52) CALL RSPEAK(I)
C						!AT DOOR?
	IF(CPVEC(ST+1).EQ.-2) CALL RSPEAK(874)
C						!EAST LADDER?
	IF(CPVEC(ST-1).EQ.-3) CALL RSPEAK(875)
C						!WEST LADDER?
	RETURN
C
10	FORMAT('       |',A2,1X,A2,1X,A2,'|'/,
     &' West  |',A2,' .. ',A2,'|  East',/
     &'       |',A2,1X,A2,1X,A2,'|')
	END
