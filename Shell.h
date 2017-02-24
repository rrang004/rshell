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
    //vector<string> testqueue;
    public:
        //Shell();
        //~Shell();
        void read();
        // void run();
        // void specialExit();
        // void displayVector(); //for testing
    
};