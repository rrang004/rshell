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
#include <cstring>
#include <sstream>
#include <fcntl.h> 
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>                                                                                                                                                
#include <boost/algorithm/string/regex.hpp>                                                                                                                                          
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
using namespace std;

class PipeCommand {
    private:
        char buffer[1000];
    public:
        PipeCommand(string);
        bool isValid;
        bool filePath;
};
