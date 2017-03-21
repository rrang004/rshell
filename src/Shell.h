#include <vector>
#include <string>
#include <cstring>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>                                                                                                                                                
#include <boost/algorithm/string/regex.hpp>                                                                                                                                          
#include <iostream>

#include "PipeCommand.h"
#include "Command.h"

using namespace std;
class Shell
{
    private:
        vector<Command> queue;
        vector<PipeCommand> pipeQueue;
    public:
        void read();
        void priorityParse(string); //For usage of ()
        void parse(string);
        void pipeParse(string); //For commands with | being the only connector
};
