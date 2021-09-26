## Makefile for Dungeon/Zork

## The system link command (or else copy).
#LN=cp
LN=ln -sf

## The Dungeon/Zork program provides a ‟more” facility which tries to figure out how many rows the terminal has.
## Several mechanisms are supported for determining this; the most common one has been left uncommented.
## If you have trouble, especially when linking, you may have to select a different option.

LIBS =
TERMFLAG = -DMORE_NONE

## End of more options

## Uncomment the following line if you want to have access to the game debugging tool.
## This is invoked by typing ‟gdt”.
## It is not much use except for debugging.
#GDTFLAG = -DALLOW_GDT

## Compilation flags
## Development
CFLAGS = -g
## Production
#CFLAGS = -O2

## Object files
OBJS =	common.o local.o \
	actors.o ballop.o blkdata.o clockr.o demons.o dgame.o dinit.o dmain.o dso1.o dso2.o dso3.o \
	dso4.o dso5.o dso6.o dso7.o dsub.o dverb1.o dverb2.o gdt.o lightp.o nobjs.o np1.o \
	np2.o np3.o np.o nrooms.o objcts.o rooms.o rtim.o sobjs.o sverbs.o verbs.o villns.o

APP = Zork

.c.o:
	$(CC) $(CFLAGS) -c $<

$(APP): $(OBJS)
	$(CC) $(CFLAGS) -o $(APP) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
undat:
	rm -f dindx.dat
	rm -f dtext.dat
clobber: clean undat
	rm -f $(APP)

## Temporary expedients.
dinit.o: dindx.dat dtext.dat
dindx.dat:
	$(LN) ../dindx.dat .
dtext.dat:
	$(LN) ../dtext.dat .

local.o: local.c
	$(CC) $(CFLAGS) $(TERMFLAG) -c local.c

$(OBJS): extern.h common.h
