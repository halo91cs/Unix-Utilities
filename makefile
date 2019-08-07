# Makefile for CSCI1730 P02: Utility functions
GPP=g++
CFLAGS=-Wall -std=c++14 -g -O0 -pedantic-errors

All:  	
	 $(GPP) $(CFLAGS) -o size size.cpp
	 $(GPP) $(CFLAGS) -o dirlist dirlist.cpp
	 $(GPP) $(CFLAGS) -o newest newest.cpp
	 $(GPP) $(CFLAGS) -o largest largest.cpp

clean:		
	 rm -rf size
	 rm -rf dirlist
	 rm -rf newest
	 rm -rf largest

