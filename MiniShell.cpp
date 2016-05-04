/*
	Name: Elizabeth Brooks
	Date Modified: May 04, 2016
	File: CS470 Lab1
*/
//Imports
#include <cstdio>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <sstream>
//Namespace declaration
using namespace std;
//Function for tokenizing the user input arguments
vector<string> split(const string &sIn, char del){
	//Declare variables for tokenization
    stringstream subS(sIn); //Set string to be tokenized
    //Prepare substrings
    string ss;
    vector<string> tokenizedS;
    while(getline(subS, ss, del)) tokenizedS.push_back(ss); //Loop through the string for sub strings
    return tokenizedS; //Return the tokenized string
} //End split
//The main method, where the program begins
int main(int argc, char* argv[]){
	//Declare variables for use in the shell program
	bool runShell=true; //Start true and loop until false
	string inputArgs; //User input
	string resultArgs=""; //Result of user input function/args
    string tempString; //Temporary string used for determining result to be displayed
    int result; //Result of string to int conversion
    //Loop until the user selects to exit    
	while(runShell){ //Retrieve user input while the exit command has not been entered
        getline(cin, inputArgs);
        std::vector<std::string> tokens;     
		tokens=split(inputArgs,' '); //Split string function
		//Perform the function (arg) entered by the user
		if(tokens[0].compare("exit")==0){ //1. exit command operation
            resultArgs="Exiting...";
            std::cout << resultArgs << endl; //Return result of operation
            return 1; //Exit program
        }else if(tokens[0].compare("mkdir")==0){ //2. mkdir command operation
            if(tokens.size()>1) { //Determine if input is delimited
                for(int i=1;i<tokens.size();i++){ //Tokenize input string
                    tempString.append(tokens.at(i));
                    tempString.append(" ");
                } //End inner for
                resultArgs=mkdir(tempString.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); //Result of operation
            } //End outer for
            resultArgs=mkdir("./Default",S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); //Result of operation
        }else if(tokens[0].compare("cmp")==0){ //4. cmp command operation
            resultArgs=system(std::string("cmp "+tokens[1]+" "+tokens[2]).c_str()); //Result of operation
        }else if(tokens[0].compare("ls")==0){ //3. ls command operation
            resultArgs=system("ls"); //Result of operation
        }else{ //Display error message
            resultArgs="Incorrect input...";
        } //End else, if
        std::cout << resultArgs << endl; //Print result of operation
	} //End while
	return 0; //Program complete, exit return
} //End main
