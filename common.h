//
// Created by Zhening Li on 2/24/18.
//

#ifndef LAB0_COMMON_H
#define LAB0_COMMON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum CommandIndices
{
    PROGRAM_NAME,
    FILE_NAME,
    CDM_ARGUMENTS_NUMBER,
};

enum ProgramStatus
{
    SUCCESS,
    OPEN_FILE_FAILED,
    WRONG_ARGUMENTS_NUMBER,
    EMPTY_CARD_VECTOR,
};

int UsageMessage(char * program_name, string promote);
void LowerCase(string &temp);

#endif //LAB0_COMMON_H
