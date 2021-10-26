## Makefile for creating dungeon.
## 2012/12/04 bkw: modified for use with gnu fortran 4.7.x.
## 2021/09/13 LMW: modified for use with gfortran 11.2.1 20210728.

## The Fortran compiler, suitable for the target system.
#FC = g77
FC = gfortran

ifeq ($(DEBUG),1)
GDT = gdt.f
DLINE = -fd-lines-as-code
else
DLINE = -fd-lines-as-comments
endif

APP = dungeon
## Where it should go.
#BINDIR = $(DESTDIR)/usr/bin
#APPDIR = $(DESTDIR)/usr/share/games/$(APP)
## Where it's going now, for the time being.
BINDIR=.
APPDIR=.

FORS =  actors.f ballop.f clockr.f demons.f \
	dgame.f dinit.f dmain.f dso1.f dso2.f \
	dso3.f dso4.f dso5.f dso6.f dso7.f \
	dsub.f dverb1.f dverb2.f lightp.f \
	nobjs.f np.f np2.f np3.f nrooms.f objcts.f \
	rooms.f sobjs.f sverbs.f verbs.f villns.f \
	np1.f blkdata.f rtim.f $(GDT)

$(APP): $(FORS)
	$(FC) $(FFLAGS) -fbackslash $(DLINE) -o $(APP) $(FORS)

test: $(APP)
	@./$(APP) 655596513 <Test.in > Ex0 && diff -d Test0.ex Ex0 && rm Ex0 && \
	./$(APP) 655596508 <Test.in > Ex1 && diff -d Test1.ex Ex1 && rm Ex1 && \
	./$(APP) 655596587 <Test.in > Ex2 && diff -d Test2.ex Ex2 && rm Ex2 && \
	./$(APP) 655596590 <Test.in > Ex3 && diff -d Test3.ex Ex3 && rm Ex3 && \
	./$(APP) 655596594 <Test.in > Ex4 && diff -d Test4.ex Ex4 && rm Ex4 && \
	./$(APP) 655596596 <Test.in > Ex5 && diff -d Test5.ex Ex5 && rm Ex5 && \
	echo "Tests passed."

clean:
	rm -f $(APP)
	rm -f core dsave.dat *~
clobber: clean
	rm -f Ex{0,1,2,3,4,5}

install: $(APP)
	mkdir -p $(BINDIR) $(APPDIR)
	install -s $(APP) $(BINDIR)
	install *.dat $(APPDIR)
