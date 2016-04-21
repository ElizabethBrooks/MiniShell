/*
	Name: Elizabeth Brooks
	Date: April 14, 2016
	File: CS470_Lab1_BrooksE
*/
//Imports
#include <cstdio>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <sstream>
//Namespace for inputs/outputs
using namespace std;
//Function for tokenizing the user input arguments
vector<string> split(const string &sIn, char del) {
	//Declare variables for tokenization
    stringstream subS(sIn);
    string ss;
    vector<string> tokenizedS;
    //Loop through the string for sub strings
    while (getline(subS, ss, del))
    {
        tokenizedS.push_back(ss);
    }
    //Return the tokenized string
    return tokenizedS;
}
//The main method, where the program begins
int main(int argc, char* argv[])
{
	//Declare variables for use in the shell program
	bool runShell = true; //Start true and loop until false
	string inputArgs; //User input
	int resultArgs = 0; //Result of user input function/args
    string tempString; //Temporary string used for determining result to be displayed
    //Loop until the user selects to exit    
	while(runShell)
	{
		//Retrieve user input,
        getline(cin, inputArgs);
        std::vector<std::string> tokens;     
		tokens= split(inputArgs,' '); 
		//then perform the function (arg) entered by the user
		if(tokens[0].compare("exit") ==0) //1. exit command operation
        {
            if(tokens.size() == 2)
            {
            	//Reurn result of operation
                return std::stoi(tokens[1]);
            }
            //Reurn result of operation
            return resultArgs;
        }
        if(tokens[0].compare("mkdir")==0) //2. mkdir command operation
        {
            if(tokens.size() >1)
            {
                for(int i=1; i<tokens.size();i++)
                {
                    tempString.append(tokens.at(i));
                    tempString.append(" ");
                }
                //Reurn result of operation
                resultArgs = mkdir(tempString.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            }
            //Reurn result of operation
            resultArgs = mkdir("./Default",S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }
        if(tokens[0].compare("cmp")==0) //4. cmp command operation
        {
        	//Reurn result of operation
            resultArgs = system(std::string("cmp " + tokens[1] + " " + tokens[2]).c_str());
        }
        if(tokens[0].compare("ls")==0) //3. ls command operation
        {
        	//Reurn result of operation
            resultArgs = system("ls");
        }
	}
	//Program complete, exit return
	return 0;
}