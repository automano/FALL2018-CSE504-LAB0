//
// Created by Zhening Li on 2/23/18.
//
#include "card.h"
#include "common.h"

int ParseFile(vector<Card> & cardV, char * inputF){
    ifstream MyFile;
    MyFile.open(inputF);

    if(!MyFile.is_open()){
        cout << "Open file failed!" << endl;
        return OPEN_FILE_FAILED;
    }

    string temp_string;
    Card temp_card = {};
    while(MyFile >> temp_string){
        if(Validator(temp_string)){
            temp_card.card_rank = GetRank(temp_string);
            temp_card.card_suit = GetSuit(temp_string);
            cardV.push_back(temp_card);
        }
    }
    return SUCCESS;
}

int PrintCard(const vector<Card> & cardV){
    if(cardV.empty()){
        cout<<"Empty Card Vector!"<<endl;
        return EMPTY_CARD_VECTOR;
    }

    for (auto card: cardV) {
        string output = GetCard(card.card_rank, card.card_suit);
        cout<<output<<endl;
    }
    return SUCCESS;
}
// Helper Function

// helper function to check the input string is valid or not
bool Validator(string &temp){
    if(temp.length() != 2 && temp.length() != 3) // string length is not 2 or 3
        return false;

    LowerCase(temp); // convert to lowercase

    // suit check
    if(temp[temp.length() - 1] != 'c' && temp[temp.length() - 1] != 'd' && temp[temp.length() - 1] != 'h' && temp[temp.length() - 1] != 's') // last char is not c, d, h, s
        return false;

    if(temp.size() == 2){ // rank check
        if(temp[0] != '2' && temp[0] != '3' && temp[0] != '4' && temp[0] != '5' && temp[0] != '6' && temp[0] != '7'
           && temp[0] != '8' && temp[0] != '9' && temp[0] != 'j' && temp[0] != 'q' && temp[0] != 'k' && temp[0] != 'a')
        return false;
    }
    if(temp.size() == 3){ // 10
        if(temp[0] != '1' || temp[1] != '0')
        return false;
    }
    return true;
}

// get card suit - string to enum
CardSuit GetSuit(string & temp){
    if(temp[temp.length() - 1] == 'c')
        return CLUBS;
    else if (temp[temp.length() - 1] == 'd')
        return DIAMONDS;
    else if (temp[temp.length() - 1] == 'h')
        return HEARTS;
    else if(temp[temp.length() - 1] == 's')
        return SPADES;
}

// get card rank - string to enum
CardRank  GetRank(string & temp){
    if (temp.length() != 2) {
        if (temp.length() == 3) {
            return TEN;
        }
    } else {
        if (temp[0] == '2')
            return TWO;
        else if (temp[0] == '3')
            return THREE;
        else if (temp[0] == '4')
            return FOUR;
        else if (temp[0] == '5')
            return FIVE;
        else if (temp[0] == '6')
            return SIX;
        else if (temp[0] == '7')
            return SEVEN;
        else if (temp[0] == '8')
            return EIGHT;
        else if (temp[0] == '9')
            return NINE;
        else if (temp[0] == 'j')
            return JACK;
        else if (temp[0] == 'q')
            return QUEEN;
        else if (temp[0] == 'k')
            return KING;
        else if (temp[0] == 'a')
            return ACE;
    }
}

// generate card info - enum to string
string GetCard(CardRank card_rank, CardSuit card_suit) {
    string result;
    // push rank
    if(card_rank == TWO)
        result.push_back('2');
    else if(card_rank == THREE)
        result.push_back('3');
    else if(card_rank == FOUR)
        result.push_back('4');
    else if(card_rank == FIVE)
        result.push_back('5');
    else if(card_rank == SIX)
        result.push_back('6');
    else if(card_rank == SEVEN)
        result.push_back('7');
    else if(card_rank == EIGHT)
        result.push_back('8');
    else if(card_rank == NINE)
        result.push_back('9');
    else if(card_rank == TEN){
        result.push_back('1');
        result.push_back('0');
    }
    else if(card_rank == JACK)
        result.push_back('J');
    else if(card_rank == QUEEN)
        result.push_back('Q');
    else if(card_rank == KING)
        result.push_back('K');
    else if(card_rank == ACE)
        result.push_back('A');

    if(card_suit == CLUBS)
        result.push_back('C');
    else if(card_suit == DIAMONDS)
        result.push_back('D');
    else if(card_suit == HEARTS)
        result.push_back('H');
    else if(card_suit == SPADES)
        result.push_back('S');

    return result;
}
