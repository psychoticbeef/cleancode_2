EXE = csvviewer
TEST = test

CC=g++

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cc)
SRC_EXE  := $(filter-out src/test.cc, $(SRC))
SRC_TEST := $(filter-out src/main.cc, $(SRC))
OBJ_EXE  =  $(SRC_EXE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_TEST =  $(SRC_TEST:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS = -Iinclude -std=c++11
CFLAGS += -Wall
LDFLAGS += -g -Llib
LDLIBS += -lm
LDLIBS_TEST=-L/usr/local/lib -lgtest -lgtest_main -lgmock -lgmock_main -lpthread

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ_EXE)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(TEST): $(OBJ_TEST)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) $(LDLIBS_TEST) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXE) $(TEST)
