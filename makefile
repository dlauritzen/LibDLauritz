################################################################################
##
## Makefile for LibDLauritz
## By Dallin Lauritzen
##
## Version 0.1a
## Authors: Dallin Lauritzen
##
## See README for more information
##
################################################################################

################################################################################
## Folders and Settings
################################################################################

BIN=bin
LIB=lib
OBJ=obj
SRC=src
INC=include

TEST_SRC=test/src
TEST_OBJ=test/obj

## Names of sub-projects. This variable is used to let the makefile know
## to compile the folders
SUBPROJECTS = dltest dllog

## Name and location of the library
OPSYS = $(shell uname)
LIBNAME=libdlauritz.so
LIBFILE=$(LIB)/$(LIBNAME)

## Name of test executable
TEST_EXE = $(BIN)/tester

## Compiler flags
CXXFLAGS = -g -Wall -I $(INC) # options when compiling object files
LIBFLAGS = -shared # options when linking shared library


## Automated lists of source files
SOURCES = $(foreach file, $(shell find $(SRC) | grep .cpp), $(file))
OS = $(patsubst $(SRC)%, $(OBJ)%, $(SOURCES:.cpp=.o))
TEST_SOURCES = $(foreach file, $(shell find $(TEST_SRC) | grep .cpp), $(file))
TEST_OS = $(patsubst $(TEST_SRC)%, $(TEST_OBJ)%, $(TEST_SOURCES:.cpp=.o))

## Macro to remove all sub-project compiled code
RM_OBJS = $(foreach proj, $(SUBPROJECTS), $(RM) $(OBJ)/$(proj)/*;)

## Installation information
ifndef PREFIX
  PREFIX=/Users/dallinlauritzen/Libraries
endif
INSTALL_DIR=$(PREFIX)
INSTALL_LIB=$(INSTALL_DIR)/lib
INSTALL_INC=$(INSTALL_DIR)/include/dlauritz

################################################################################
## Pseudo-Targets
################################################################################

## Default. Build library and tester
all: lib tester

## Build the test executable
tester: $(TEST_EXE)

## Build the library
lib: $(LIBFILE)

## Run the tester
test: all
	@$(TEST_EXE)

## Copy library and include files into relevant folders
install: lib
	@echo "Installing libdlauritz library and headers to $(PREFIX)."
	@-mkdir $(INSTALL_INC)
	@cp -pR $(INC)/* $(INSTALL_INC)/.
	@cp $(LIBFILE) $(INSTALL_LIB)/$(LIBNAME)

## Remove installed files
uninstall:
	@echo "Uninstalling libdlauritz"
	@-$(RM) $(INSTALL_LIB)/$(LIBNAME)
	@-$(RM) -r $(INSTALL_INC)

## Recompile and install
reinstall: clean uninstall install

## Remove generated files
clean:
	@echo "Removing generated files."
	@-$(RM) $(LIBFILE)
	@-$(RM_OBJS)
	@-$(RM) $(TEST_EXE)
	@-$(RM) $(TEST_OBJ)/*

## Clean and build
rebuild: clean all

## Commit to github
commit: clean
	git add *
	git commit
	git push

## Update from github
update:
	git pull

## Print various information
info:
	@echo "Sources: $(SOURCES)"
	@echo "OS: $(OS)"
	@echo "Test Sources: $(TEST_SOURCES)"
	@echo "Test OS: $(TEST_OS)"

################################################################################
## Compile Targets
################################################################################

## Link the test executable
$(TEST_EXE): $(TEST_OS)
	@echo "Linking testing executable $@"
	@$(LINK.cpp)  -L $(LIB) $(OUTPUT_OPTION) $^ -ldlauritz

## Package the library
$(LIBFILE): $(OS)
	@echo "Linking shared library: $@"
	@$(LINK.cpp) $(LIBFLAGS) $(OUTPUT_OPTION) $^

## Compile project code
$(OBJ)/%.o: $(SRC)/%.cpp
	@echo "Compiling object file $<"
	@$(COMPILE.cpp) -fPIC $(OUTPUT_OPTION) $<

## Compile test code
$(TEST_OBJ)/%.o: $(TEST_SRC)/%.cpp
	@echo "Compiling test object file $<"
	@$(COMPILE.cpp) $(OUTPUT_OPTION) $<


################################################################################
## END OF MAKEFILE
################################################################################
