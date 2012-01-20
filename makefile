
BIN=bin
LIB=lib
OBJ=obj
SRC=src
INC=include

SUBPROJECTS = dltest dllog

LIBNAME=libdlauritz.so
LIBFILE=$(LIB)/$(LIBNAME)

TEST_EXE = $(BIN)/tester

OSYS = $(shell uname)
CXXFLAGS = -g -Wall -I $(INC) # options when compiling object files
LIBFLAGS = -shared # options when linking shared library

SOURCES = $(foreach file, $(shell find -s -f $(SRC) | grep .cpp), $(file))
OS = $(patsubst $(SRC)%, $(OBJ)%, $(SOURCES:.cpp=.o))

TEST_SRC=test/src
TEST_OBJ=test/obj

TEST_SOURCES = $(foreach file, $(shell find -s -f $(TEST_SRC) | grep .cpp), $(file))
TEST_OS = $(patsubst $(TEST_SRC)%, $(TEST_OBJ)%, $(TEST_SOURCES:.cpp=.o))

ifndef PREFIX
  PREFIX=/Users/dallinlauritzen/Libraries
endif

INSTALL_DIR=$(PREFIX)
INSTALL_LIB=$(INSTALL_DIR)/lib
INSTALL_INC=$(INSTALL_DIR)/include/dlauritz

RM_OBJS = $(foreach proj, $(SUBPROJECTS), $(RM) $(OBJ)/$(proj)/*;)

all: lib tester

rebuild: clean all

tester: $(TEST_EXE)

test: all
	@$(TEST_EXE)

lib: $(LIBFILE)

install: lib
	@echo "Installing libdlauritz library and headers to $(PREFIX)."
	@-mkdir $(INSTALL_INC)
	@cp -pR $(INC)/* $(INSTALL_INC)/.
	@cp $(LIBFILE) $(INSTALL_LIB)/$(LIBNAME)

uninstall:
	@echo "Uninstalling libdlauritz"
	@-$(RM) $(INSTALL_LIB)/$(LIBNAME)
	@-$(RM) -r $(INSTALL_INC)

reinstall: clean uninstall install

clean:
	@echo "Removing generated files."
	@-$(RM) $(LIBFILE)
	@-$(RM_OBJS)
	@-$(RM) $(TEST_EXE)
	@-$(RM) $(TEST_OBJ)/*

info:
	@echo "Sources: $(SOURCES)"
	@echo "OS: $(OS)"
	@echo "Test Sources: $(TEST_SOURCES)"
	@echo "Test OS: $(TEST_OS)"

$(TEST_EXE): $(TEST_OS)
	@echo "Linking testing executable $@"
	@$(LINK.cpp)  -L $(LIB) $(OUTPUT_OPTION) $^ -ldlauritz

$(LIBFILE): $(OS)
	@echo "Linking shared library: $@"
	@$(LINK.cpp) $(LIBFLAGS) $(OUTPUT_OPTION) $^

$(OBJ)/%.o: $(SRC)/%.cpp
	@echo "Compiling object file $<"
	@$(COMPILE.cpp) -fPIC $(OUTPUT_OPTION) $<

$(TEST_OBJ)/%.o: $(TEST_SRC)/%.cpp
	@echo "Compiling test object file $<"
	@$(COMPILE.cpp) $(OUTPUT_OPTION) $<

