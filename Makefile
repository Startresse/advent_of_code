# --------------------------------------------------------
# Generic Makefile
#
# Author 	: startresse
# Date 		: 02/06/2020
#
# Changelog :
#	02/06/2020 - first version
# --------------------------------------------------------

# project name
TARGET		= main

# compilation
CC			= g++
CFLAGS		= -W -Wall -ansi -pedantic -O3 -std=c++17

# linking
LINKER 		= g++
LFLAGS		=

# directories
SRCDIR			= src
BINDIR			= bin
OBJDIR			= obj

# files
SOURCES		= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES	= $(wildcard $(SRCDIR)/*.h)
OBJECTS		= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# custom commands
rm			= rm -rf 

# creating required directories if needed

# building rules
$(BINDIR)/$(TARGET): create_directories $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

create_directories:
ifeq ($(wildcard $(OBJDIR)/.),)
	@mkdir $(OBJDIR)
	@echo "Created "$(OBJDIR)"/"
endif
ifeq ($(wildcard $(BINDIR)/.),)
	@mkdir $(BINDIR)
	@echo "Created "$(BINDIR)"/"
endif

# cleaning rules
.PHONY: clean remove

clean:
	@$(rm) $(OBJECTS)
	@echo "Object files removed!"

remove:
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

fullclean: clean remove
	@$(rm) $(BINDIR)
	@$(rm) $(OBJDIR)
	@echo "Full directory clean complete!"