#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <random>
#include <ctime> 
#include <algorithm>

#include "Deck.hpp"
using namespace std;

double pairOdds(std::vector<pair<Card, bool>> &deck, vector<Card> &playerHand, vector<Card> &tableCards)
{
    vector<int> cardValues(13,0); //track count of each card value

    double outs = 0; //track future cards that would result in a pair

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

    // If no pair was found on the river pair is impossible
    if(tableCards.size() == 5) 
    { 
        return 0;
    }

    double remainingCards = 52 - playerHand.size() - tableCards.size();

    double firstCardOdds = outs/remainingCards;

    if(tableCards.size() == 4){ // Return current odds if on turn
        return firstCardOdds;
    }

    double notFirstCardOdds = (remainingCards - outs)/ remainingCards;
    double secondCardOdds = outs /(remainingCards-1);

    return (notFirstCardOdds * secondCardOdds) + firstCardOdds;
}

double twoPairOdds(std::vector<pair<Card, bool>> &deck, vector<Card> &playerHand, vector<Card> &tableCards)
{
    vector<int> cardValues(13,0); //track count of each card value

    double outs = 0; //track future cards that would result in a pair

    int currentPosition = 0;

    // Store current cards in hashmap and get outs
    for(int i = 0; i < playerHand.size(); i++)
    {
        currentPosition = playerHand[i].getValue() - 2;

        cardValues[currentPosition]++;
        
        outs += 3;
    }
    
    for(int i = 0; i < tableCards.size(); i++)
    {
        currentPosition = tableCards[i].getValue() - 2;

        cardValues[currentPosition]++;
        
        outs += 3;
    }

    // Return 100 if 2 pair already exists
    //if()

    // If no pair was found on the river pair is impossible
    if(tableCards.size() == 5) 
    { 
        return 0;
    }

    double remainingCards = 52 - playerHand.size() - tableCards.size();

    double firstCardOdds = outs/remainingCards;

    if(tableCards.size() == 4){ // Return current odds if on turn
        return firstCardOdds;
    }

    double notFirstCardOdds = (remainingCards - outs)/ remainingCards;
    double secondCardOdds = outs /(remainingCards-1);

    return (notFirstCardOdds * secondCardOdds) + firstCardOdds;
}

