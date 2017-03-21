#include "PipeCommand.h"
#include <fstream>
PipeCommand::PipeCommand (string pipeStr) {
    //3 test cases: <, >, >> (< output, > input, >> append)
    //parse string for <, >, >> occurrance and use dup2 to redirect the output?
    
    //>> can be used to pipe output into a text file and will append to any existing text in that file
    //> Overwrite output in a file
    //< Take input from a file
    string command;
    string parameters;
    string parameters2;
    if (pipeStr.find(">>") != string::npos) {
       command = pipeStr.substr(0,pipeStr.find(">>"));
    //   cout << "Command = " << command << endl;
       parameters = pipeStr.substr(0, pipeStr.find(">>") - 1);
       parameters2 = pipeStr.substr(pipeStr.find(">>") + 2, (pipeStr.length() - pipeStr.find(">>") + 1));
    //   cout << "Parameters = " << parameters << endl;
        boost::trim(command);
       boost::trim(parameters);
       boost::trim(parameters2);
       //**FIX File amending process
        // cout << parameters << " " << parameters2 << endl;
        char file1[250];
        strcpy(file1, parameters.c_str());
        char txtAdd[] = ".txt";
        char* fileArray1 = new char[strlen(file1) + strlen(txtAdd)];
        strcpy(fileArray1, file1);
        strcat(fileArray1, txtAdd);
        char file2[250];
        strcpy(file2, parameters2.c_str());
        // char txtAdd[] = ".txt";
        char* fileArray2 = new char[strlen(file2) + strlen(txtAdd)];
        strcpy(fileArray2, file2);
        strcat(fileArray2, txtAdd);
        cout << fileArray1 << " " << fileArray2 << endl;
        fstream fileOut;
        fileOut.open(fileArray1);
        fstream fileOut2;
        fileOut2.open(fileArray2, ios_base::app | ios_base::out);
        
        string copy;
        while (getline(fileOut, copy)) {
        // cout << "copy = " << copy << endl;
        fileOut2 << copy;
        }
    }
    else if (pipeStr.find("<") != string::npos) {
       command = pipeStr.substr(0,pipeStr.find("<"));
    //   cout << "Command = " << command << endl;
       parameters = pipeStr.substr(0, pipeStr.find("<") - 1);
       parameters2 = pipeStr.substr(pipeStr.find("<") + 1, (pipeStr.length() - pipeStr.find(">")));
    //   cout << "Parameters = " << parameters << endl;
        boost::trim(command);
       boost::trim(parameters);
       boost::trim(parameters2);
       //**FIX Will it always be cat to read files to buffer? file < file?
       //Find file name location
    //   int size1 = (pipeStr.find(" ") - 1);
       
       //Put file contents to buffer
       if (pipeStr.substr(0,3) == "cat") {
            char fileC[250];
            strcpy(fileC, parameters.c_str());
            char txtAdd[] = ".txt";
            char* fileArray = new char[strlen(fileC) + strlen(txtAdd)];
            strcpy(fileArray, fileC);
            strcat(fileArray, txtAdd);
            fstream fileOut;
            fileOut.open(fileArray);
            vector<string> x(1000);
            int i = 0;
            while (fileOut >> x[i])
            {
                i++;
            }
            // cout << "end of loop" << endl;
            for (unsigned i = 0; i < x.size(); i++) {
                cout << x.at(i);
            }
            cout << endl;
            string toBuffer = "";
            for (unsigned i = 0; i < x.size(); i++) {
                toBuffer += x.at(i);
            }
            strcpy(buffer, toBuffer.c_str());
            
        unsigned j = 0;
        // cout << "Conatins: ";
        while (j <= strlen(this->buffer) ) {
           cout << buffer[j];
           j++;
        }    
       }
       else { //file < file
        // cout << parameters << " " << parameters2 << endl;
        char file1[250];
        strcpy(file1, parameters.c_str());
        char txtAdd[] = ".txt";
        char* fileArray1 = new char[strlen(file1) + strlen(txtAdd)];
        strcpy(fileArray1, file1);
        strcat(fileArray1, txtAdd);
        char file2[250];
        strcpy(file2, parameters2.c_str());
        // char txtAdd[] = ".txt";
        char* fileArray2 = new char[strlen(file2) + strlen(txtAdd)];
        strcpy(fileArray2, file2);
        strcat(fileArray2, txtAdd);
        fstream fileOut;
        fileOut.open(fileArray2);
        fstream fileOut2;
        fileOut2.open(fileArray1);
        
        string copy;
        while (getline(fileOut, copy)) {
        fileOut2 << copy;
            
        }
        // vector<string> x(1000);
        // int i = 0;
        // while (fileOut >> x[i])
        // {
        //     i++;
        // }
        // // cout << "end of loop" << endl;
        // for (unsigned i = 0; i < x.size(); i++) {
        //     cout << x.at(i);
        // }
        // cout << endl;
        // string toBuffer = "";
        // for (unsigned i = 0; i < x.size(); i++) {
        //     toBuffer += x.at(i);
        // }
        // strcpy(buffer, toBuffer.c_str());
        
        
        

   
           }
       }
       
    // }
    else if (pipeStr.find(">") != string::npos) {
       command = pipeStr.substr(0,pipeStr.find(">"));
    //   cout << "Command = " << command << endl;
       parameters = pipeStr.substr(0, pipeStr.find(">") - 1);
       parameters2 = pipeStr.substr(pipeStr.find(">") + 1, pipeStr.length()-1);
    //   cout << "Parameters = " << parameters << endl;
        boost::trim(command);
       boost::trim(parameters);
       boost::trim(parameters2);
    //**FIX Command infront of >? How to implement **Maybe split entirely from this if statement, treat as another string
    //**FIX Will there be file > file?
    //This method only works if its 2 files
    //   int size1 = (pipeStr.find(" ") - 1);
            char file1[250];
            strcpy(file1, parameters.c_str());
            char txtAdd[] = ".txt";
            char* fileArray1 = new char[strlen(file1) + strlen(txtAdd)];
            strcpy(fileArray1, file1);
            strcat(fileArray1, txtAdd);
            char file2[250];
            strcpy(file2, parameters2.c_str());
            // char txtAdd[] = ".txt";
            char* fileArray2 = new char[strlen(file2) + strlen(txtAdd)];
            strcpy(fileArray2, file2);
            strcat(fileArray2, txtAdd);
            
        fstream fileOut2;
        fileOut2.open(fileArray2);
        fstream fileOut;
        fileOut.open(fileArray1);
        
        string copy;
        while (getline(fileOut, copy)) {
        fileOut2 << copy;
            
        }
            
            
        // if (dup2(fileArray1, fileArray2) == -1) {
        //     cout << "File Error";
        //     exit(1);
        // }
        
        //Takes buffer and writes to directed file
        // while (fgets(parameters, sizeof(buffer), buffer)!=NULL) {
        //     fputs(parameters, buffer);
        // }
        // ofstream fileOut;
        // fileOut.open(parameters + ".txt");
        
    
       
    }
    else {
        //**FIX How previous buffer works with next popen, possibly adding two char* together
        //File to send command results to
        // cout << "Starting command process" << endl;
        char commandC[250];
        strcpy(commandC, pipeStr.c_str());
        char* bufferArray = new char[strlen(commandC) + strlen(buffer) + 1];
        strcpy(bufferArray, commandC);
        strcat(bufferArray, buffer);
        FILE* bufferFile;
        
        // cout << bufferArray << endl;
        
        // cout << "Created char* with command and buffer" << endl;
        // int k = 0;
        // cout << "Conatins: ";
        // while (k <= strlen(this->buffer) ) {
        //   cout << buffer[k];
        //   k++;
        // }
        //Run popen
        //**Make pipeStr to const char*?
        if (!(bufferFile = popen(bufferArray, "r"))) {
            cout << "Failed to open" << endl;
        }
        //Trasfer file to buffer
        // cout << "Ran popen" << endl;
        char buff [100];
        while(fgets(buff, sizeof(buff), bufferFile)!=NULL) {
        //   cout << "e";
           puts(buff);
        //   cout << "d";
        }
        
        
        
        // fstream bufferF;
        // bufferF.open(bufferFile);
        // vector<string> x(1000);
        // int i = 0;
        // while (bufferF >> x[i])
        // {
        //     i++;
        // }
        // cout << "end of loop" << endl;
        // for (unsigned i = 0; i < x.size(); i++) {
        //     cout << x.at(i);
        // }
        // cout << endl;
        // string toBuffer = "";
        // for (unsigned i = 0; i < x.size(); i++) {
        //     toBuffer += x.at(i);
        // }
        // strcpy(buffer, toBuffer.c_str());
        // cout << "Made new buffer" << endl;
        //Close file
        pclose(bufferFile);
        unsigned j = 0;
        // cout << "Conatins: ";
        while (j <= strlen(this->buffer) ) {
           cout << buffer[j];
           j++;
        }
    }
}
    
    
    
