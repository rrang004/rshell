#include "Command.h"

Command::Command(string commandStr) {
    this->isValid = true;
    //Check to see if the exit command is ran
    if (commandStr.find("exit") != string::npos) {
        exit(1);
    }
    
    //Create a char from the string
    int i = 0;
    char commandC[250];
    
    //Make pointers for arguements
    char* token;
    
    //Copy over string
    strcpy(commandC, commandStr.c_str());
    token=strtok(commandC," ");
    
    //allocate memory for arguments
    char* commandPtr[250];
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
    int waitC;
    
    //Queue commands
    pid_t pid;
    if ((pid = fork()) < 0) {
        cout << "Error" << endl;
        exit(1);
    }
    else if (pid == 0) {
        //Execute the pointer
        if (execvp(commandPtr[0], commandPtr) < 0) {  
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
