CC = gcc
CFLAGS = -Wall -Werror -O2 -Iinclude

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib

TARGET = libctest.a
TARGET_PATH = $(LIB_DIR)/$(TARGET) 

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INSTALL_PREFIX = /usr/local

all: $(TARGET_PATH)

$(TARGET_PATH): $(OBJ)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(wildcard $(INC_DIR)/*.h)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	@echo "Installing to $(INSTALL_PREFIX)"
	install -Dm644 $(TARGET_PATH) $(INSTALL_PREFIX)/lib/$(TARGET)
	install -d $(INSTALL_PREFIX)/include/
	install -m644 $(wildcard $(INC_DIR)/*.h) $(INSTALL_PREFIX)/include/
	@echo "Installation complete"

uninstall:
	rm -f $(INSTALL_PREFIX)/lib/$(TARGET)
	$(foreach hdr,$(wildcard $(INC_DIR)/*.h), rm -f $(INSTALL_PREFIX)/include/$(notdir $(hdr));)

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

remake: clean all

