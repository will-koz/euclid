CC := gcc

FILE := main.c
OUT := euclid

all:
	$(CC) $(FILE) -o $(OUT)
