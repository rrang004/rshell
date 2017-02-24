#include "Shell.h"

//-----------------------------------------------------------------------------
//Read Function
//Known bug: Can enter connectors such as |&, ;|, ;&, &| and it will still parse the commands
//-----------------------------------------------------------------------------
void Shell::read() {
    while (true) {
            char hostname[128];
            if (gethostname(hostname, 128) < 0) {
                perror("Hostname error!");
            }
            cout << hostname;
            cout << "$";
            string rawCommands;
            getline(cin, rawCommands);
        
        //Parse commands
        vector<string> x;
        boost::split(x, rawCommands, boost::is_any_of("|&;"));
     
        // Clear left spaces
        for(int i = 0; i < x.size(); i++) {
            boost::trim_left(x.at(i));
        }
      
        //clear right spaces
        for(int i = 0; i < x.size(); i++) {
            if(x.at(i)[x.at(i).size()] == ' ') {
                boost::trim_right(x.at(i));
            }    
        }
        //clear any empty commands (" ")
        for(unsigned i = 0; i < x.size(); i++) {
            if(x.at(i) == "") {
                x.erase(x.begin() + i);
           }    
        }
        //ALSO CLEAR ANY COMMANDS WITH COMMENTS, ADD THEM TO PARSER LIST
        for (unsigned i = 0; i < x.size(); i++) {
            if ((x.at(i)).find('#') != string::npos) {
                (x.at(i)).erase((x.at(i)).find('#'), x.at(i).size());
          }
        } 
        for (unsigned i = 0; i < x.size(); i++) {
            if(x.at(i) == "") {
            }
            else {
                Command newC = Command(x.at(i));
                queue.push_back(newC);
            }
        }
    }
}    