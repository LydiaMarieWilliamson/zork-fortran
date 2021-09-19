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
	./$(APP) <Test.in >Ex && diff -d Test.ex Ex && rm Ex

clean:
	rm -f $(APP)
clobber: clean
	rm -f Ex

install: $(APP)
	mkdir -p $(BINDIR) $(APPDIR)
	install -s $(APP) $(BINDIR)
	install *.dat $(APPDIR)
