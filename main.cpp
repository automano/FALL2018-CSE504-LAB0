#include "card.h"
#include "common.h"

int main(int argc, char *argv[])
{
    if (argc == CDM_ARGUMENTS_NUMBER)
    {
        char * file_name = argv[FILE_NAME];
        vector<Card> card_vector;
        if(!ParseFile(card_vector, file_name))
            return PrintCard(card_vector);
        else
            return ParseFile(card_vector, file_name);

    }
    else
    {
        char * program_name = argv[PROGRAM_NAME];
        string second_argument = "<File Name>";
        return UsageMessage(program_name, second_argument);// call usage message
    }
}