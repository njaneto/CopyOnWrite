.SUFFIXES:
.SUFFIXES: .o .dep .ec .cpp

PROJECT_ROOT = $(shell pwd)
SRCS_CPP    = $(shell ls $(PROJECT_ROOT)/*.cpp 2> /dev/null)
INCLUDE_DIR = -I../src -I$(POCO_BASE)/CppUnit/include
OBJS 		= $(SRCS_CPP:.cpp=.o) 

LINK =  ../src/CowAsciiString.o -L$(POCO_BASE)/lib/Linux/$(SO_PLATAFORM)  -lCppUnit

all: $(OBJS) 
	$(CXX) $? $(LINK) -o testrunner

.cpp.o:
	$(CC) $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -fr testrunner $(OBJS)
