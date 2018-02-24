//
// Created by Zhening Li on 2/23/18.
// Naming Rules are followed Google C++ Style Guide https://google.github.io/styleguide/cppguide.html#Naming
//

#ifndef LAB0_CARD_H
#define LAB0_CARD_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum CardSuit{CLUBS, DIAMONDS, HEARTS, SPADES};
enum CardRank{TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct Card{
    CardSuit card_suit;
    CardRank card_rank;
};

int ParseFile(vector<Card> & cardV, char * inputF);
int PrintCard(const vector<Card> & cardV);
bool Validator(string &temp);
CardSuit GetSuit(string & temp);
CardRank GetRank(string & temp);
string GetCard(CardRank card_rank, CardSuit card_suit);

#endif //LAB0_CARD_H
