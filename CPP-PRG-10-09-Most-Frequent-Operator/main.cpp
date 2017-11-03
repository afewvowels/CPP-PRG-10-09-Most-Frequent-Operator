//
//  main.cpp
//  CPP-PRG-10-09-Most-Frequent-Operator
//
//  Created by Keith Smith on 11/3/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts either a pointer to a C-string, or a string object, as its
//  argument. The function should return the character that appears most frequently in the
//  string. Demonstrate the function in a complete program.

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string *getUserString(string *);
char *convertStringToC(string *, char *);
char *findMostCommonLetter(char *, char *);



int main()
{
    string *strInput = nullptr;
    strInput = new string;
    
    strInput= getUserString(strInput);
    
    char *chrArray = nullptr;
    chrArray = new char[strInput->size()];
    
    chrArray = convertStringToC(strInput, chrArray);
    
    delete [] strInput;
    strInput = nullptr;
    
    char *chrLetter = nullptr;
    chrLetter = new char;
    
    chrLetter = findMostCommonLetter(chrArray, chrLetter);
    
    delete [] chrArray;
    chrArray = nullptr;
    
    
    
    return 0;
}

string *getUserString(string *strString)
{
    cout << "Please enter a string:\n";
    getline(cin, *strString);
    
    return strString;
}

char *convertStringToC(string *strString, char *chrArr)
{
    *chrArr = *strString->c_str();
    
    return chrArr;
}


char *findMostCommonLetter(char *chrArr, char *chrLetter)
{
    
    
    return chrLetter;
}
