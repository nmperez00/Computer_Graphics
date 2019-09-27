#sample Makefile for using OpenGL of Red Hat Linux 7.x
#CS 420, Tong Yu, Fall 2002
                                                                                
PROG    = atom
CFLAGS  = -w -s -O2 -ansi -DSHM
XLIBS   = -lX11 -lXext 
LIBS    = -lglut -lGLU -lGL
INCLS   = -I/usr/X11R/include 
LIBDIR  = -L/usr/X11/lib -L/usr/X11R6/lib -L./
#source codes
SRCS = $(PROG).cpp atom.cpp
#substitute .cpp by .o to obtain object filenames
OBJS = $(SRCS:.cpp=.o)
                                                                                
#$< evaluates to the target's dependencies,
#$@ evaluates to the target
  
$(PROG): $(OBJS)
	g++ -o $@ $(OBJS)  $(LIBDIR) $(LIBS) $(XLIBS)
                                                                                
$(OBJS):
	g++ -c  $*.cpp $(INCLS)
                                                                                
clean:
	rm $(OBJS) 
                                                                                

  
