//
// Created by Zhening Li on 2/24/18.
//

#include "common.h"

const int A_to_a = 32; // 'A'-'a'=32
/**
* Usage Message function
*/
int UsageMessage(char * program_name, string promote)
{
    cout << "Usage: " << program_name << " " << promote << endl;
    return WRONG_ARGUMENTS_NUMBER;
}

/**
* Function that takes a reference to a C++ style string
* and modifies that string so that all of the alphabetic characters in it become lowercase
*/
void LowerCase(string &temp)
{
    for (char &i : temp) {
        if (i >= 'A'&& i <= 'Z')
        {
            i = static_cast<char>(i + A_to_a);
        }
    }
}