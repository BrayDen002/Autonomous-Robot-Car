# /**************************************************************
# * Class: CSC-615-01 Fall 2021
# * Name: Antonino Calabrese
# * Student ID: 920831285
# * Github ID: ringnino
# * Project: Assignment 3 Start your Motors
# *
# * File: Makefile
# *
# * Description: Makefile to run C program
# * Credit for makefile blueprint - Robert Bierman at SFSU
# **************************************************************/

ROOTNAME=assignment3
CC=gcc
CFLAGS= -lwiringPi

$(ROOTNAME):
	$(CC) -o $(ROOTNAME) $(ROOTNAME).c -lm PCA9685.c $(CFLAGS) DEV_Config.c


clean:
	rm $(ROOTNAME)

run: $(ROOTNAME)
	./$(ROOTNAME)
