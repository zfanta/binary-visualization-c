CC = gcc

TARGETS = step-0-binarize step-1-matrixize step-2-visualize
BUILD_DIR = ./build

all: $(TARGETS)

directory:
	mkdir -p build

step-0-binarize: directory
	$(CC) step-0-binarize.c -o $(BUILD_DIR)/step-0-binarize

step-1-matrixize: directory
	$(CC) step-1-matrixize.c -o $(BUILD_DIR)/step-1-matrixize

step-2-visualize: directory
	$(CC) step-2-visualize.c -o $(BUILD_DIR)/step-2-visualize

clean:
	rm -rf $(BUILD_DIR)
