#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <cctype>
using namespace std;

class Command {
    private:
        // string paraList;
        // const char* command;
        // char *const parmList;
    public:
        Command(string);
        // ~Command();
        // void execute();
        void displayCommand();
    
};