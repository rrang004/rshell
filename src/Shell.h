#include <vector>
#include <string>
#include <cstring>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>                                                                                                                                                
#include <boost/algorithm/string/regex.hpp>                                                                                                                                          
#include <iostream>
#include "Command.h"

using namespace std;
class Shell
{
    private:
        vector<Command> queue;
    public:
        void read();
        void priorityParse(string); //For usage of ()
        void parse(string);
    
};
