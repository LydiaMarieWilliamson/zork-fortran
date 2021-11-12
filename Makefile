## Makefile for creating dungeon.
## 2012/12/04 bkw: modified for use with gnu fortran 4.7.x.
## 2021/09/13 LMW: modified for use with gfortran 11.2.1 20210728.

## The system link command (or else copy).
#LN=cp
LN=ln -sf

## The system remove command.
#RM=del
RM=rm -f

## The Fortran compiler, suitable for the target system.
#FC = g77
FC = gfortran

ifeq ($(DEBUG),1)
gdt = gdt
DLINE = -fd-lines-as-code
else
DLINE = -fd-lines-as-comments
endif

APP = dungeon
## Where it should go.
#BINDIR = $(DESTDIR)/usr/bin
#APPDIR = $(DESTDIR)/usr/share/games/$(APP)
## Where it's going now, for the time being.
BINDIR = .
APPDIR = .

## The modules - grouped together as they appear in version 3.2.
dungeon = dmain
game = dgame dinit
objects = lightp objcts sobjs nobjs ballop villns
parser = np blkdata np1 np2 np3
rooms = rooms nrooms
subr = dsub dso1 dso2 dso3 dso4 dso5 dso6 dso7 rtim
timefnc = clockr demons actors
verbs = sverbs verbs dverb1 dverb2
MODS = $(dungeon) $(game) $(objects) $(parser) $(rooms) $(subr) $(timefnc) $(verbs) $(gdt)
OBJS = $(MODS:%=%.o)

.f.o:
	$(FC) $(FFLAGS) -fbackslash $(DLINE) -c $<

$(APP): $(OBJS) dindx.dat dtext.dat
	$(FC) $(OBJS) -o $@

test: $(APP) Test0.in Test1.in Test2.in
	@./$(APP) 655600000 <Test0.in > Ex0 && diff -d Test0.ex Ex0 && rm Ex0 && \
	./$(APP) 657578356 <Test1.in > Ex1 && diff -d Test1.ex Ex1 && rm Ex1 && \
	./$(APP) 655596513 <Test2.in > Ex2 && diff -d Test2.ex Ex2 && rm Ex2 && \
	./$(APP) 655596508 <Test2.in > Ex3 && diff -d Test3.ex Ex3 && rm Ex3 && \
	./$(APP) 655596587 <Test2.in > Ex4 && diff -d Test4.ex Ex4 && rm Ex4 && \
	./$(APP) 655596590 <Test2.in > Ex5 && diff -d Test5.ex Ex5 && rm Ex5 && \
	./$(APP) 655596594 <Test2.in > Ex6 && diff -d Test6.ex Ex6 && rm Ex6 && \
	./$(APP) 655596596 <Test2.in > Ex7 && diff -d Test7.ex Ex7 && rm Ex7 && \
	./$(APP) 657577982 <Test2.in > Ex8 && diff -d Test8.ex Ex8 && rm Ex8 && \
	./$(APP) 657577797 <Test2.in > Ex9 && diff -d Test9.ex Ex9 && rm Ex9 && \
	echo "Tests passed."

clean:
	$(RM) $(OBJS)
	$(RM) core dsave.dat *~
untest:
	$(RM) Ex*
	$(RM) Test*.in
undat:
	$(RM) dindx.dat
	$(RM) dtext.dat
clobber: clean untest undat
	$(RM) $(APP)

## Temporary expedients.
Test0.in:
	@$(LN) C2021/Test0.in .
Test1.in:
	@$(LN) C2021/Test1.in .
Test2.in:
	@$(LN) C2021/Test2.in .
dindx.dat:
	@$(LN) C2021/dindx.dat .
dtext.dat:
	@$(LN) C2021/dtext.dat .

install: $(APP)
	mkdir -p $(BINDIR) $(APPDIR)
	install -s $(APP) $(BINDIR)
	install *.dat $(APPDIR)
