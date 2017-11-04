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
int *generateArrayTally(char *, string *);
char *sortArrayNumbers(int *, char *, string *);
void displayOutputMessage(char *, int *);
void swap(int *, int *);
void swap(char *, char *);


int main()
{
    int *intArrTally = nullptr;
    
    string *strInput = nullptr;
    strInput = new string;
    
    strInput= getUserString(strInput);
    
    char *chrArray = nullptr;
    chrArray = new char[strInput->size()];
    
    chrArray = convertStringToC(strInput, chrArray);
    
    intArrTally = generateArrayTally(chrArray, strInput);
    
    chrArray = sortArrayNumbers(intArrTally, chrArray, strInput);
    
    delete strInput;
    strInput = nullptr;
    
    char *chrLetter = nullptr;
    chrLetter = new char;
    
//    delete [] chrArray;
//    chrArray = nullptr;
    
    displayOutputMessage(chrArray, intArrTally);
    
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
    strcpy(chrArr, strString->c_str());
    
    return chrArr;
}

int *generateArrayTally(char *chrArr, string *strInput)
{
    char *chrArrSorted = nullptr;
    int *intArrTally = nullptr;
    
    chrArrSorted = new char[strInput->size()];
    intArrTally = new int[strInput->size()];
    
    for (int i = 0 ; i < strInput->size() ; i++)
    {
        chrArrSorted[i] = chrArr[i];
        intArrTally[i] = 0;
    }
    
    for (int i = 0 ; i < strInput->size() ; i++)
    {
        for (int j = 0 ; j < strInput->size() ; j++)
        {
            if (chrArr[i] == chrArrSorted[j])
            {
                chrArrSorted[j] = chrArr[i];
                intArrTally[j]++;
                break;
            }
        }
    }
    
    return intArrTally;
}

char *sortArrayNumbers(int *intArrTally, char *chrArr, string *strInput)
{
    int intStart;
    int intMinIndex;
    
    int *fltMinElement = nullptr;
    
    char *strMinElement = nullptr;
    
    for(intStart = 0 ; intStart < (strInput->length() - 1) ; intStart++)
    {
        intMinIndex = intStart;
        fltMinElement = &intArrTally[intStart];
        
        for(int index = (intStart + 1) ; index < strInput->length() ; index++)
        {
            if(intArrTally[index] > *fltMinElement)
            {
                fltMinElement = &intArrTally[index];
                strMinElement = &chrArr[index];
                intMinIndex = index;
            }
        }
        swap(intArrTally[intMinIndex], intArrTally[intStart]);
        swap(chrArr[intMinIndex], chrArr[intStart]);
    }
    
//    cout << "Tally sorted: " << endl;
//    for (int i = 0 ; i < strInput->length() ; i++)
//    {
//        cout << *(intArrTally + i) << endl;
//    }
    cout << endl;
    
    return chrArr;
}

void displayOutputMessage(char *chrLetter, int *intTally)
{
    if (intTally[0] != 1)
    {
        cout << "The most frequent character is the character \'" << chrLetter[0] << "\'.\n";
    }
    else if (intTally[0] == 1)
    {
        cout << "There was no most frequent letter in that string.\n";
    }
    else
    {
        cout << "ERROR DISPLAYING RESULTS\n";
        exit(1);
    }
}

void swap(int *intA, int *intB)
{
    int *intTemp = nullptr;
    intTemp = new int;
    
    intTemp = intA;
    intA = intB;
    intB = intTemp;
}

void swap(char *chrA, char *chrB)
{
    char *chrTemp = nullptr;
    chrTemp = new char;
    
    chrTemp = chrA;
    chrA = chrB;
    chrB = chrTemp;
}
