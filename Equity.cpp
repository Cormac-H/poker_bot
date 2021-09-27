#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <random>
#include <ctime> 
#include <algorithm>

#include "Deck.h"
using namespace std;

double pairOdds(std::vector<pair<Card, bool>> &deck, vector<Card> &playerHand, vector<Card> &tableCards)
{
    vector<int> cardValues(13,0); //track count of each card value

    int outs = 0; //track future cards that would result in a pair

    int currentPosition = 0;

    //Check if a pair already exists and get outs
    for(int i = 0; i < playerHand.size(); i++)
    {
        currentPosition = playerHand[i].getValue() - 2;

        cardValues[currentPosition]++;
        
        outs += 3;

        if(cardValues[currentPosition] > 1){
            return 100.00;
        }
    }
    
    for(int i = 0; i < tableCards.size(); i++)
    {
        currentPosition = tableCards[i].getValue() - 2;

        cardValues[currentPosition]++;
        
        outs += 3;

        if(cardValues[currentPosition] > 1){
            return 100.00;
        }
    }
    return 0.0;
}