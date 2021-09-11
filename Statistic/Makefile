# Adapted from https://gist.github.com/samuelsmal/e43f2001cfc81fee18b6
# Requires the following project directory structure:
#  /bin
#  /obj
#  /src

# Use 'make remove' to clean up the hole project

# Name of target file
TARGET     = Statistic

CXX        = g++
CXXFLAGS   = -std=c++11 \
			 -Wall -Wextra -Werror -Wpointer-arith -Wcast-qual \
			 -pedantic-errors -pedantic \
			 -g

LD         = g++ -o
LDFLAGS    = -Wall -pedantic

SRCDIR     = src
OBJDIR     = obj
BINDIR     = bin
INCTEST    = ../doctest/doctest
SRCTEST    = ../doctest/doctest/parts

SOURCES   := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES  := $(SRCDIR)
INCLUDES  += $(INCTEST)
OBJECTS   := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

RM         = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LD) $@ $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS)  $(INCLUDES:%=-I %) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"