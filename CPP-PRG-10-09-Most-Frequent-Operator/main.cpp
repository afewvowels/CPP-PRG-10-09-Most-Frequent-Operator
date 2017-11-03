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

using namespace std;

char *getUserString(char *, int *);
int *adjustArrSize(char *, int *);
void resizeArray(char *, char *, int *);



int main()
{
    int *intArrSize = nullptr;
    intArrSize = new int;
    *intArrSize = 999;
    
    char *chrArrayTemp = nullptr;
    chrArrayTemp = new char[*intArrSize];
    
    string *strInput = nullptr;
    strInput = new string;
    
    chrArrayTemp= getUserString(chrArrayTemp, intArrSize);
    
    intArrSize = adjustArrSize(chrArrayTemp, intArrSize);
    
    char *chrArray = nullptr;
    chrArray = new char[*intArrSize];
    
    resizeArray(chrArray, chrArrayTemp, intArrSize);
    
    delete [] chrArrayTemp;
    chrArrayTemp = nullptr;
    
    
    
    return 0;
}

char *getUserString(char *chrArr, int *intSize)
{
    cout << "Please enter a string:\n";
    cin.getline(chrArr, *intSize);
    
    return chrArr;
}

int *adjustArrSize(char *chrArr, int *intSize)
{
    int *intCounter = nullptr;
    intCounter = new int;
    *intCounter = 0;
    
    for (int i = 0 ; i < *intSize ; i++)
    {
        *intCounter += 1;
        
        if (chrArr[i] == '\0')
        {
            break;
        }
    }
    
    *intSize = *intCounter;
    
    return intSize;
}

void resizeArray(char *chrArr1, char *chrArr2, int *intSize)
{
    for (int i = 0 ; i < *intSize ; i++)
    {
        chrArr2[i] = chrArr1[i];
    }
}
