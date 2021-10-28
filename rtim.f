C Copyright (c) 1980, InfoCom Computers and Communications, Cambridge MA 02142
C All rights reserved, commercial usage strictly prohibited.
C Written by R. M. Supnik.
C Revisions Copyright (c) 2021, Darth Spectra (Lydia Marie Williamson).
C
C The time since 2001, in seconds.
	INTEGER*4 FUNCTION TIME2001()
	   INTEGER DT(8)
	   INTEGER Y,M,D,TZ,HR,MN,SC!,CN
	   INTEGER*4 T
	   PARAMETER (LEAP2000=2000/4-2000/100+2000/400)
	   CALL DATE_AND_TIME(VALUES=DT)
	   Y=DT(1)
	   M=DT(2)
	   D=DT(3)
	   TZ=DT(4)
	   HR=DT(5)
	   MN=DT(6)
	   SC=DT(7)
C	   CN=DT(8)
	   T=365*(M-1)/12
	   IF(M.LT.8)T=T-1
	   IF(M.LT.3)THEN
	      T=T+M
	   ELSE
	      IF(
     &	         (MOD(Y,4).EQ.0).AND.(
     &	            (MOD(Y,100).NE.0).OR.(MOD(Y,400).EQ.0)
     &	         )
     &	      )T=T+1
C	      IF(MOD(Y,4).EQ.0)T=T+1
C	      IF(MOD(Y,100).EQ.0)T=T-1
C	      IF(MOD(Y,400).EQ.0)T=T+1
	   ENDIF
	   T=T+D-1
	   Y=Y-1
	   T=T+365*(Y-2000)+Y/4-Y/100+Y/400-LEAP2000
	   TIME2001=60*(60*(24*T+HR)+MN-TZ)+SC
	   RETURN
	END

	SUBROUTINE RANDS(S0,S1)
	INTEGER*4 S0,M0,A0,Q0,R0,SEED0
	INTEGER*4 S1,M1,A1,Q1,R1,SEED1
	COMMON /RANDOM/ M0,A0,Q0,R0,SEED0
	COMMON /RANDOM/ M1,A1,Q1,R1,SEED1
	M0=1+2*3*7*631*81031 ! = 2^31 - 85
	A0=40014
	Q0=M0/A0
	R0=MOD(M0,A0)
	M1=1+2*19*31*1019*1789 ! = 2^31 - 249
	A1=40692
	Q1=M1/A1
	R1=MOD(M1,A1)
	SEED0=MOD(S0,M0)
	SEED1=MOD(S1,M1)
	END

C A random long integer in [1,M0-1].
C P.L'Ecuyer, "Efficient and portable combined random number generators",
C CACM 31(6), June 1988, 742-751.
C The period of the generator is:
C	(M0-1)(M1-1)/2 = 2*3*7*19*31*631*1019*1789*81031 = 2^61-360777242114
	INTEGER*4 FUNCTION RANDZ()
	INTEGER*4 M0,A0,Q0,R0,SEED0
	INTEGER*4 M1,A1,Q1,R1,SEED1
	COMMON /RANDOM/ M0,A0,Q0,R0,SEED0
	COMMON /RANDOM/ M1,A1,Q1,R1,SEED1
	INTEGER K0,K1
C       This requires:
C       *	(M0-1)/2 and (M1-1)/2 be relatively prime,
C       *	A0^2 < M0 and A1^2 < M1,
C       *	0 <= SEED0 < M0, 0 <= SEED1 < M1.
C       Under these conditions, the following is equivalent to:
C       *	SEED0=MOD(A0*SEED0,M0),SEED1=MOD(A1*SEED1,M1);
C       and 0 <= SEED0 < M0, 0 <= SEED1 < M1 continues to hold.
	K0=SEED0/Q0;
	SEED0=A0*(SEED0-K0*Q0)-K0*R0;
	IF(SEED0.LT.0)SEED0=SEED0+M0;
	K1=SEED1/Q1;
	SEED1=A1*(SEED1-K1*Q1)-K1*R1;
	IF(SEED1.LT.0)SEED1=SEED1+M1;
C The result is in the range [0,M0-2].
	RANDZ=SEED0-SEED1;
	IF(RANDZ.LT.1)RANDZ=RANDZ+M0-1;
	RETURN
	END

C The last remnant of the seed update routine from the Fortran original
C is used, here, to initialize the seed.
	SUBROUTINE INIRND(SEED)
	INTEGER*4 SEED,SEED1
        SEED1=SEED*INT(Z'423')+INT(Z'11')
	CALL RANDS(SEED,SEED1)
	END

C A random integer in [0,MAXVAL-1].
	INTEGER FUNCTION RND(MAXVAL)
	INTEGER*4 RANDZ
	INTEGER MAXVAL
	RND=MOD(RANDZ(),MAXVAL)
	RETURN
	END

	SUBROUTINE EXIT
C NO "CALL EXIT" HERE
	STOP
	END
