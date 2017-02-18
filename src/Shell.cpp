#include "Shell.h"

//WHEN READY TO INTEGRATE TO COMMAND CLASS, CONTROL F AND REPLACE queue WITH QUEUE
Shell::Shell() {
    //create empty vector?
}
Shell::~Shell() {
    //delete each new command
}
//-----------------------------------------------------------------------------
//Read Function
//Known bug: Can enter connectors such as |&, ;|, ;&, &| and it will still parse the commands
//-----------------------------------------------------------------------------
void Shell::read() {
    //Read input
    while (true) {
        cout << "$";
        string rawCommands;
        getline(cin, rawCommands);
        int startIndex = 0;
        // cout << "commands entered: " << rawCommands << endl;
        
     //Parse commands
      vector<string> x;
      boost::split(x, rawCommands, boost::is_any_of("|&;"));
     
    // Clear left spaces
    //   for(int i = 0; i < x.size(); i++) {
    //     boost::trim_left(x.at(i));
    //     cout << "left trimmed" << endl;
    //   }
      
    //   //clear right spaces
    //   for(int i = 0; i < x.size(); i++) {
    //     if(x.at(i)[x.at(i).size()] == ' ') {
    //         boost::trim_right(x.at(i));
    //         cout << "right trimmed" << endl;
    //     }    
    //   }
    //  //clear any empty commands (" ")
       for(int i = 0; i < x.size(); i++) {
           if(x.at(i) == "") {
            //   cout << "line 52" << endl;
                x.erase(x.begin() + i);
           }    
       }
    //   cout << "printing commands" << endl;
       for(int i = 0; i < x.size(); i++) {
        //   cout << x.at(i) << endl;
       }
    // Clear final spaces
    // for(int i = 0; i < x.size(); i++) {
    //       if((x.at(i))[(x.at(i).size()-1)] == ' ')
    //             x.erase(x.begin() + 0);
    //   }
    //ALSO CLEAR ANY COMMANDS WITH COMMANDS, ADD THEM TO PARSER LIST?
      for (int i = 0; i < x.size(); i++) {
        //   cout <<"x" << endl;
          if ((x.at(i)).find('#') != string::npos) {
            //   cout << "comment found" << endl;
                (x.at(i)).erase((x.at(i)).find('#'), x.at(i).size());
          }
      } 
     for (int i = 0; i < x.size(); i++) {
        //  cout << "command" << x.at(i) << endl;
        //  cout << "About to run" << endl;
         Command newC = Command(x.at(i));
        //  cout << "Times run: " << (i + 1) << endl;
        //  queue.push_back(newC);
     }
    //run commands, if one of the key words was exit, end program!
       // run();        
               
        // displayVector();
    }
}
void Shell::run() {
    //call Command's run function 
    for (int i = 0; i < queue.size(); i++) {
        // (queue.at(i)).execute();
    }

}
void Shell::specialExit() {
    //possibly have the exit inside command class instead
}
void Shell::displayVector() {
    // cout << "size of vector: " << queue.size() << endl;
    // cout << "Printing commands.." << endl;
    // for(int i = 0; i < this->queue.size(); i++) {
    //     cout << queue.at(i) << endl;
    // }
    
}
    
