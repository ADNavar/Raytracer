.SUFFIXES:
.SUFFIXES: .c .cpp .o

CC = g++

OBJS=main.o   \
     entity.o     \
     sceneobj.o   \
     plane.o      \
     sphere.o     \
     pointlight.o \
     lighting.o   \
     hitinfo.o    \
     image.o   \
     list.o   \
     raytrace.o \
     readVals.o \
     render.o \
     scene.o \
     tuple.o \
     window.o \
     myvector.o \
     mycolor.o

CXXFLAGS=-g -Wall

all: ray


${OBJS}: entity.h     \
         sceneobj.h   \
         plane.h      \
         sphere.h     \
         pointlight.h \
         myvector.h   \
         hitinfo.h    \
         image.h      \
         list.h       \
         ray.h        \
         raytrace.h   \
         readVals.h   \
         render.h     \
         scene.h      \
         tuple.h      \
         window.h     \
         Makefile

ray: ${OBJS}
	-echo Linking $@
	g++ -o $@ ${OBJS}

test:
	./ray  scene.txt  img.ppm

clean:
	rm -f *.o ray

