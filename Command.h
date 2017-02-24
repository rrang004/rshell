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
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>                                                                                                                                                
#include <boost/algorithm/string/regex.hpp>                                                                                                                                          
#include <sys/wait.h>
using namespace std;

class Command {
    public:
        Command(string);
};