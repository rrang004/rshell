#include "Command.h"

Command::Command(string commandStr) {
    // cout << "Run" << endl;
    //trim spaces
    boost::trim(commandStr);
            
    
    this->isValid = true;
    this->filePath = false;
    //Check to see if the exit command is ran
    if (commandStr.find("exit") != string::npos) {
        exit(1);
    }
    char* commandPtr[250];
    string fileDir;
    string flagC;
    if ((commandStr.substr(0,4) == "test") || (commandStr.substr(0,1) == "[")) {
        this->filePath = true;
        if (commandStr.find("-") != string::npos) {
            int position = commandStr.find("-");
            flagC = commandStr.substr(position + 1, 1);
            int positionS = commandStr.find("-") + 3;
            
            if (commandStr.find("]")) {
                int positionE = commandStr.find("]") - 1;
                fileDir = commandStr.substr(positionS, (positionE - positionS));
            }
            else {
                fileDir = commandStr.substr(positionS);
            }
        }
        else {
            flagC = "e";
            if (commandStr.find("]") != string::npos) {
                int positionE = commandStr.find("]") - 2;
                fileDir = commandStr.substr(2, (positionE - 1));
            }
            else {
                fileDir = commandStr.substr(5);
            }
        }
        
    }
    
    else {
    
    //Create a char from the string
    int i = 0;
    char commandC[250];
    
    //Make pointers for arguements
    char* token;
    
    //Copy over string
    strcpy(commandC, commandStr.c_str());
    token=strtok(commandC," ");
    
    //allocate memory for arguments
    
    commandPtr[0] = (char*)malloc(strlen(token));
    commandPtr[0] = token;
    
    // Check for any separating characters
    token=strtok(NULL," ");
    
    //For each argument, add a pointer
    while(token!=NULL) {
        i++;
        commandPtr[i]=(char*)malloc(strlen(token));
        commandPtr[i]=token;
        token=strtok(NULL," ");
                                    }
    //add a NULL
    commandPtr[i+1]=NULL;
    
    }
    int waitC;
    const char* filePtr = fileDir.c_str();
    // cout << flagC << endl;
    // cout << filePtr << endl;
    //Queue commands
    pid_t pid;
    if ((pid = fork()) < 0) {
        cout << "Error" << endl;
        exit(1);
    }
    else if (pid == 0) {
        //Execute the pointer
        if (filePath == true) {
            struct stat sb;
            bool coutC = false;
            if (flagC == "e") {
                if (stat(filePtr, &sb) == 0) {
                    cout << "(True)" << endl;
                    coutC = true;
                }
            }
            else if (flagC == "f") {
                if (S_ISREG(sb.st_mode)) {
                    cout << "(True)" << endl;
                    coutC = true;
                }
            }
            else if (flagC == "d") {
                if (S_ISDIR(sb.st_mode)) {
                    cout << "(True)" << endl;
                    coutC = true;
                }
            }
            if (coutC != true) {
                cout << "(False)" << endl;
            }
        }
        
        else if (execvp(commandPtr[0], commandPtr) < 0) {  
            //any reason why it didn't run
            perror("Command did not execute: ");
            this->isValid = false;
        }
    }
    else {     
        while (wait(&waitC) != pid);
    }

return;
}
