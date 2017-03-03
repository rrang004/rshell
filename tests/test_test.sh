#!/bin/bash
test Shell.cpp 
[ -e Shell.cpp ] 
test junkfile.cpp
[ -e junkfile.cpp ]
test -f main.cpp
[ -f main.cpp ]
