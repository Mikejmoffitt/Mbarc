CXX=g++
CFLAGS=
LDFLAGS=
INCLUDE=

OBJS=Mbarc.cpp usageTest.cpp
OUT=mbarc

all: mbarc_rule

clean:
	rm -rf *.o mbarc

mbarc_rule: $(OJBS)
	$(CXX) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)
