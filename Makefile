MFILES= program
IFILES= GateController GateStatusPacket Vehicle ParkingLot Parking

SRC=$(addsuffix .cpp, $(MFILES))
OBJS=$(addsuffix .o, $(MFILES))

ISF=$(addsuffix .cpp, $(IFILES))
ISRC=$(addprefix ./interface/, $(ISF))
IOF=$(addsuffix .o, $(IFILES))

CC=g++
LD=g++

CCFLAGS= -c
LDFLAGS=

EXEC=pk_lot

default:
	make plot
	make clean

plot:$(OBJS) $(IOF)
	$(LD) $(LDFLAGS) $(OBJS) $(IOF) -o $(EXEC)
	
$(OBJS):
	$(CC) $(CCFLAGS) $(SRC)
$(IOF):
	$(CC) $(CCFLAGS) $(ISRC)
clean:
	rm *.o
