# System-dependent makefile options for ONCVPSP
# This must be carefully edited before executing "make" in src
#
# Copyright (c) 1989-2014 by D. R. Hamann, Mat-Sim Research LLC and Rutgers
# University
 
##### Edit the following lines to correspond to your compilers ####

F77        = /opt/homebrew/bin/gfortran	
F90        = /opt/homebrew/bin/gfortran	
CC         = /opt/homebrew/bin/gcc-15	
FCCPP      = /opt/homebrew/bin/cpp-15

FLINKER     = $(F90)

FCCPPFLAGS = -ansi -DLIBXC_VERSION=400  #Use this for versions >400 

##### Edit the following optimization flags for your system ####

# For Fortran compiler flags
FFLAGS  = -O3 -ffast-math -funroll-loops -mcpu=native -flto=16 -funsafe-math-optimizations

# For C compiler flags
CFLAGS  = -O3 -mcpu=native -flto=16


##### Edit the following LAPACK and BLAS library paths for your system ####

LIBS += -L/opt/homebrew/opt/lapack/lib -llapack -lblas

##### Edit the following for to use libxc if available #####

OBJS_LIBXC = exc_libxc_stub.o

LIBS += -L/Users/christian.tantardini/Softs/lib/libxc-6.0.0/lib -lxcf90 -lxcf03 -lxc
FFLAGS += -I/Users/christian.tantardini/Softs/lib/libxc-6.0.0/include
FCCPPFLAGS += -I/Users/christian.tantardini/Softs/lib/libxc-6.0.0/include
OBJS_LIBXC = functionals.o exc_libxc.o 
