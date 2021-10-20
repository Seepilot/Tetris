#############################################################################################################
######### Main Makefile with Targets and Rules to build the project
#############################################################################################################

-include Conf.mk

###################################################################################################
######### Object files
###################################################################################################

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OUTPUT_DIR)/,$(OBJS))

###################################################################################################
######### Rules and Targets
###################################################################################################

.SECONDEXPANSION:

all: $(OUTPUT_DIR)/$(PROJECT)

example: $(OUTPUT_DIR)/example

$(OUTPUT_DIR)/%.o: %.c $$(@D)/.f
	$(CC) $< -c $(CFLAGS) -o "$@"

$(OUTPUT_DIR)/%.o: %.cpp $$(@D)/.f
	$(CXX) $< -c $(CXXFLAGS) -o "$@"

$(OUTPUT_DIR)/$(PROJECT): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

$(OUTPUT_DIR)/example: felder.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean: 
	rm -fr $(OUTPUT_DIR)

print_objects: 
	@echo $(OBJS)

print_includes:
	@echo $(INC_DIRS)

%/.f:
	mkdir -p $(dir $@)
	touch $@

.PRECIOUS: %/.f

.PHONY: all clean print_objects print_includes