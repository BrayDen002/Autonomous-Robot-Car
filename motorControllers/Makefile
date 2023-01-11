# /**************************************************************
# * Class: CSC-615-01 Fall 2021
# * Name: Antonino Calabrese
# * Student ID: 920831285
# * Github ID: ringnino
# * Project: Final Project
# *
# * File: Makefile
# *
# * Description: Makefile to run C program
# * Credit for makefile blueprint - Robert Bierman at SFSU
# **************************************************************/
ROOTNAME=finalproject
CC=gcc
CFLAGS= -lwiringPi

$(ROOTNAME):
	$(CC) -o $(ROOTNAME) $(ROOTNAME).c motor.c echoSensor.c $(CFLAGS)

clean:
	rm $(ROOTNAME)

run:$(ROOTNAME)
	./$(ROOTNAME)
