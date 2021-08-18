## dLabPro makefiles
## - System configuration
##
## AUTHOR : Frank Duckhorn
## PACKAGE: dLabPro/make
##
## Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
## - Chair of System Theory and Speech Technology, TU Dresden
## - Chair of Communications Engineering, BTU Cottbus
## 
## This file is part of dLabPro.
## 
## dLabPro is free software: you can redistribute it and/or modify it under the
## terms of the GNU Lesser General Public License as published by the Free
## Software Foundation, either version 3 of the License, or (at your option)
## any later version.
## 
## dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
## WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
## FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
## details.
## 
## You should have received a copy of the GNU Lesser General Public License
## along with dLabPro. If not, see <http://www.gnu.org/licenses/>.

ifeq ($(GCC),)
  GCC=gcc
endif
ifeq ($(GPP),)
  GPP=g++
endif

## Common settings
ifdef (${CGENPATH})
  DCG = ${CGENPATH}/dcg
else
  DCG = dcg
endif

INCL += -I$(DLABPRO_HOME)/include -I$(DLABPRO_HOME)/include/automatic -I$(PRG_PATH)
vpath %.h $(DLABPRO_HOME)/include $(DLABPRO_HOME)/include/automatic $(PRG_PATH)

ifneq (${MACHINE},)
  MEXT=.${MACHINE}
else
  MEXT=
endif

## Detect compile OS
## Implemented values: lin32, lin64, mingw32, mingw64, cygwin64, msv1, msv2

# for alignment exceptions workarounds
ARCHITECTURE=x86

# Test #1 for MSVC
ifneq (${DLABPRO_USE_MSVC},)
  ifeq (${DLABPRO_USE_MSVC},1)
    ## - MSVC
    OS = msv1
  else ifeq (${DLABPRO_USE_MSVC},2)
    ## - MSVC 6.0 - 32-Bit C/C++-Compiler for x86
    OS = msv2
  else
    $(error Unimplemented MSVC Version: "$(DLABPRO_USE_MSVC)")
  endif
else 
  # Test #2 for machine of gcc
  OS := $(call lc,$(shell $(GCC) -dumpmachine))
  ifneq ($(OS),)
    ifneq ($(and $(findstring -linux,$(OS)),$(findstring x86_64-,$(OS))),)
      OS = lin64
    else ifneq ($(and $(findstring -linux,$(OS)),$(findstring x86-,$(OS))),)
      OS = lin32
    else ifneq ($(and $(findstring -linux,$(OS)),$(findstring i686-,$(OS))),)
      OS = lin32
    else ifneq ($(findstring mingw32,$(OS)),)
      OS = mingw32
    else ifneq ($(and $(findstring -pc-cygwin,$(OS)),$(findstring x86_64-,$(OS))),)
      OS = cygwin64
    # GCC on ARM
    else ifneq ($(and $(findstring -linux,$(OS)),$(findstring arm-,$(OS))),)
      OS = lin32
      ARCHITECTURE=arm
    # CLANG on ARM (Raspbian)
    else ifneq ($(and $(findstring -linux-gnueabihf,$(OS)),$(findstring armv6k-,$(OS))),)
      OS = lin32
      ARCHITECTURE=arm
    # CLANG on ARM (Debian buster)
    else ifneq ($(and $(findstring -linux-gnueabihf,$(OS)),$(findstring armv7l-,$(OS))),)
      OS = lin32
      ARCHITECTURE=arm
    else
      $(error Unimplemented machine of gcc: "$(OS)")
    endif
  else
    # Test #3 for machine uname
    OS := $(call lc,$(shell uname))
    ifeq ($(OS),Linux)
      OS = lin64
    else ifneq ($(findstring mingw32,$(OS)),)
      OS = mingw32
    else ifneq ($(findstring cygwin,$(OS)),)
      OS = cygwin64
    else
      $(error Unimplemented operating system: "$(OS)")
    endif
  endif
endif

## Detect git head revision
DLPREV  = $(DLABPRO_HOME)/include/automatic/dlp_rev.h
GITREV  = unkown
GITHEAD = $(DLABPRO_HOME)/.git/HEAD
ifneq ($(wildcard $(GITHEAD)),)
  GITREV := $(shell cat $(GITHEAD))
  ifneq ($(filter ref:,$(GITREV)),)
    GITREV := $(shell cat $(DLABPRO_HOME)/.git/$(filter-out ref:,$(GITREV)))
  endif
endif
ifneq ($(wildcard $(DLPREV)),)
 GITREVO := $(subst ",,$(filter-out \#define __DLP_BUILD,$(shell cat $(DLPREV))))
else
  GITREVO = CREATE
endif
ifneq ($(GITREVO),$(GITREV))
  $(shell echo "" >&2)
  $(shell echo "// Update dlp_rev.h with new revision $(GITREV)" >&2)
  $(shell echo '#define __DLP_BUILD "$(GITREV)"' >$(DLPREV))
endif

## EOF
