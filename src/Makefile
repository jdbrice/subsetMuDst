
# project name and executable name
project = treeSubset
# source suffix
source = .cpp 
# object files to make
objects = app.o histoBook.o chainLoader.o 

sources = $(wildcard *.cpp)
headers = $(wildcard ../include/*.h)

# ROOT libs and includes
ROOTCFLAGS    	= $(shell root-config --cflags)
ROOTLIBS      	= $(shell root-config --libs)
ROOTGLIBS     	= $(shell root-config --glibs)

# Custom Project includes and libs
includes		= -I../include -I. -I$(ROOTSYS)/include -I$(ROOTDEV)/include 
libraries 			= 	$(ROOTLIBS) -lGui -lHtml -lGuiHtml $(CERNLIBS) $(SYSLIBS) \

cxx 		= g++ -std=c++0x
flags 		= -Wall -g $(ROOTCFLAGS) $(includes) -Wno-write-strings -m32 -fno-inline
compile 	= $(cxx) $(flags) -c 
ldFlags  	= -m32 -g

all: $(project)

$(project): $(objects)
		$(cxx) $(ldFlags) -o  $(project) $(objects) $(ROOTGLIBS) $(libraries)
		@cp $(project) ../bin

%.o: %$(source)
		$(compile)  $<

clean:
		@rm -f $(objects) $(project)
		@rm -f ../bin/$(project)
		@echo "clean done"

full:
	clean
	$(project)

#doc:
#	@echo "Generating documentation..." 	\					
#	cldoc generate $(CXXFLAGS) --			\
#		--report 							\
#		--merge docs 						\
#		--output html 						\
#		$(sources) $(headers)
