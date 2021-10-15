.SUFFIXES:
.SUFFIXES: .o .dep .ec .cpp

PROJECT_ROOT = $(shell pwd)
SRCS_CPP    = $(shell ls $(PROJECT_ROOT)/*.cpp 2> /dev/null)
OBJS 		= $(SRCS_CPP:.cpp=.o)

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g 
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2 
else
endif

all: copyOnWrite

copyOnWrite:	$(OBJS)
	$(CXX) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<
	
%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr copyOnWrite $(OBJS)
