#include "Command.h"

Command::Command(string commandStr) {
    cout << "The string executing is:" << commandStr << ":" << endl;
    //Check to see if the exit command is ran
    if (commandStr.find("exit") != string::npos) {
        exit(1);
    }
    // cout << "Check" << endl;
    //split string into command and parameters
    // cout << commandStr << endl;
    vector<string> commands;
        if (commandStr.find(" ") != string::npos) {
        commands.push_back(commandStr.substr(0, commandStr.find(" ")));
    // cout << commands.at(0) << endl;
        commands.push_back(commandStr.substr(commandStr.find(" ") + 1, commandStr.size()-1));
    // cout << "Check.5" << endl;
    }
    else {
        commands.push_back(commandStr);
        commands.push_back(" ");
    
    }
    // cout << "1: " << commands.at(0) << "2: " << commands.at(1) << endl;
    // cout << "Check1" << endl;
    // cout << ":" << commands.at(0) << ":" << commands.at(1) << ":" << " are both parts of the command" << endl;
    const char* command = (commands.at(0)).c_str();
    char** parameters;
    // cout << "Check2" << endl;
    // cout << (commands.at(1)).size() << endl;
    // charArr new char*[5] = "Hello";
    parameters = new char*[(commands.at(1).size() + 1)];
    // cout << "33" << endl;
    cout << *parameters << endl;
    // fill(*parameters, *(parameters + 4), 'a');
    // cout << "34" << endl;
    // for(unsigned i = 0; *parameters != '\0';parameters++)
    // {
    //     cout << ":" << *parameters << "-" << i << endl;
    //     i++;
    // }
    // cout << "Check3" << endl;
    // string practicestring = "Test";
    // char* test = (commands.at(1)).c_str();
    // *parameters;
    // cout << "check 3.5" << endl;
    // const char* copyString = new char; 
    // copyString = (commands.at(1)).c_str();
    // cout << "calling strcpy" << endl;
    strcpy(*parameters, (commands.at(1)).c_str());
    // *parameters = test;
    // cout << "Check4" << endl;
    // *parameters = strtok(*parameters, " ");
    // cout << "Check6" << endl;
    pid_t pid;
    // int status;
    if ((pid = fork()) < 0) {
        // cout << "Error" << endl;
        exit(1);
    }
    else if (pid == 0) {          /* for the child process:         */
        if (execvp(command, parameters) < 0) {     /* execute the command  */
            perror("Command did not execute: ");
        }
    }
    else {                                  /* for the parent:      */
        // while (wait(&status) != pid)       /* wait for completion  */
        // ;
    }
    //Run the command and check if it ran properply
    // if (execvp(command, parameters) < 0) {
    //     //Show why the command did not run
    //     perror("Command did not execute: ");
    // };
    return;
}

// Command::~Command() {
//     delete commandStr;
// }

// void Command::execute() {
    // if (execvp(command, parmList) < 0) {
    //     perror("Command did not execute: ");
    // }
    // return;
// }

void Command::displayCommand() {
    // cout << command << " was added" << endl;
    return;
}
