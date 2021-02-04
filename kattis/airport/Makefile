CC = g++
CXXFLAGS = -std=gnu++17

INCDIR = lib/inc
LIBDIR = lib
OBJDIR = obj
SRCDIR = lib/src

_OBJS = point.o edge.o

OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

CXXFLAGS += -I$(INCDIR)
CXXFLAGS += -L$(LIBDIR)


SAMPLEDATAADDR = https://open.kattis.com/problems/airport/file/statement/samples.zip

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CXXFLAGS) -fpic

$(LIBDIR)/geomlib.a: $(OBJS)
	ar rvs lib/geomlib.a $^

test: $(LIBDIR)/geomlib.a
	g++ -o pointtest pointtest.cpp -lgeomlib -lgtest -lgmock -L/usr/local/lib -Llib  $(CXXFLAGS)
	g++ -o edgetest edgetest.cpp -lgeomlib -lgtest -lgmock -L/usr/local/lib  -Llib $(CXXFLAGS)

app: $(LIBDIR)/geomlib.a
	g++ -o airport airport.cpp $(LIBDIR)/geomlib.a -std=c++17

1.in: clean
	wget $(SAMPLEDATAADDR) && unzip samples.zip
2.in: clean
	wget $(SAMPLEDATAADDR) && unzip samples.zip

run: app 1.in 2.in
	./airport < 1.in
	./airport < 2.in

clean:
	rm *.exe *~ 1.in 2.in 1.ans 2.ans
