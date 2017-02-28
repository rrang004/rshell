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
        cout << "$ ";
        string rawCommands;
        getline(cin, rawCommands);
        
        //Check if they entered parentheses
        if(rawCommands[0] == '(') {
            priorityParse(rawCommands);
        }
        else {
            parse(rawCommands);       
        }
    }    
}    
//-------------------------------------------
//CURRENT BUGS AS OF 2/26:
//-Entering & or | as connectors causes entire code to run
//-------------------------------------------
void Shell::priorityParse(string commands) {
     //verify all parentheses match up
     int leftParens = 0;
     int rightParens = 0;
     vector<string> connectors;
     for (unsigned i = 0; i < commands.length(); i++) {
         if (commands[i] == '(')
            leftParens++;
         else if (commands[i] == ')')
            rightParens++;
     }
    if (rightParens != leftParens) { //unbalanced
        cout << "Error: Mismatched parentheses" << endl;
        return; 
     }
     //get connectors
    for(unsigned i = 0; i < commands.length(); i++) {
        if (commands[i] == '&' && commands[i+1] == '&')
            connectors.push_back("&&");
        else if (commands[i] == '|' && commands[i+1] == '|')
            connectors.push_back("||");
    }
    // cout << "displaying connectors" << endl;
    // for(int i = 0; i < connectors.size(); i++) {
    //     cout << connectors.at(i) << endl;
    // }
    //parse individual commands
            //Parse commands
            vector<string> x;
            boost::split(x, commands, boost::is_any_of("|&;"));
     
            // Clear left spaces
            for(unsigned i = 0; i < x.size(); i++) {
                boost::trim_left(x.at(i));
            }
      
            //clear right spaces
            for(unsigned i = 0; i < x.size(); i++) {
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
            
            //Delete all parentheses
            for (unsigned i = 0; i < x.size(); i++) {
                boost::erase_all(x.at(i), "(");
                boost::erase_all(x.at(i), ")");
            }
            
    //test: display commands        
    // cout << "displaying parsed commands" << endl;
    // for(unsigned i = 0; i < x.size(); i++) {
        // cout << x.at(i) << endl;
    // }
    //execute commands
    //need flag for if it errored
    // cout << "connectors size: " << connectors.size() << endl;
    for (unsigned i = 0; i < x.size(); i++) {
        if(x.at(i) == "") {
        }
        else {
            Command newC = Command(x.at(i));
            queue.push_back(newC);
            
            if (i < connectors.size()) { //make sure you aren't exceeding total number of connectors
                if (connectors.at(i) == "||" && newC.isValid != false) { //commands ran correctly, don't need to proceed past ||
                    return;
                }
                // if (newC.isValid == false && connectors.at(i) == "&&") {
                // }
            }
        }
    }
}
//-------------------------------------------
//KNOWN BUGS:
//
//-------------------------------------------
void Shell::parse(string commands) {
         //Parse commands
            vector<string> x;
            boost::split(x, commands, boost::is_any_of("|&;"));
     
            // Clear left spaces
            for(unsigned i = 0; i < x.size(); i++) {
                boost::trim_left(x.at(i));
            }
      
            //clear right spaces
            for(unsigned i = 0; i < x.size(); i++) {
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
//TEST WITH MAKE!
