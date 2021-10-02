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

    // If no pair was found on the River pair is impossible
    if(tableCards.size() == 5) 
    { 
        return 0;
    }

    double remainingCards = 52 - playerHand.size() - tableCards.size(); // Calculate remaining cards in deck

    double firstCardOdds = outs/remainingCards; // Odds of getting a pair after drawing one card

    if(tableCards.size() == 4){ // Return current odds if on Turn
        return firstCardOdds;
    }

    double notFirstCardOdds = (remainingCards - outs)/ remainingCards;
    double secondCardOdds = (outs+3) /(remainingCards-1); // outs increase after not finding a card

    return (notFirstCardOdds * secondCardOdds) + firstCardOdds; // Odds of drawing a pair on either the first or second draw after Flop
}


double twoPairOdds(std::vector<pair<Card, bool>> &deck, vector<Card> &playerHand, vector<Card> &tableCards)
{
    vector<int> cardValues(13,0); //track count of each card value

    double outs = 0; //track future cards that would result in a pair

    int currentPosition = 0;

    int pairCounter = 0;

    // Store current cards in hashmap and get outs
    for(int i = 0; i < playerHand.size(); i++)
    {
        currentPosition = playerHand[i].getValue() - 2;

        cardValues[currentPosition]++;

        outs += 3;

        //Track pairs
        if(cardValues[currentPosition] == 2)
        {
            pairCounter++;
            outs -= 6; // remove all potential outs by already finding a pair
        }
    }
    
    for(int i = 0; i < tableCards.size(); i++)
    {
        currentPosition = tableCards[i].getValue() - 2;

        cardValues[currentPosition]++;
        
        outs += 3;

        //Track pairs
        if(cardValues[currentPosition] == 2)
        {
            pairCounter++;
            outs -= 6; // remove all potential outs by already finding a pair
        }
        else if (cardValues[currentPosition] == 3)
        {
            pairCounter++;
            outs -= 8; // Edge case where a triple is found, only 1 out remains for un-paired card
        } 
    }

    if(pairCounter >= 2)
    {
        return 100.00; // Return 100 if 2 pair already exists
    }


    // Handle case where no pairs are present
    
    if((pairCounter == 0 && tableCards.size() != 3))
    { 
        return 0.00; // If no pair was found and it is turn or river 2 pair is now impossible
    }
    
    double remainingCards = 52 - playerHand.size() - tableCards.size(); // Calculate remaining cards in deck

    if (pairCounter == 0)
    {
        double firstCardOdds = outs/remainingCards; 
        double secondCardOdds = (outs-3)/(remainingCards - 1); // Subtract 3 odds because a pair was created

        return firstCardOdds * secondCardOdds; // Odds of forming a pair on the Turn and the River after having none by Flop
    }


    //Handle case where 1 pair is already present

    double firstCardOdds = outs/remainingCards; //Calculate odds to make a pair on drawing one card (varies by outs)

    if(pairCounter == 1 && tableCards.size() == 3)
    {
        double notFirstCardOdds = (remainingCards - outs)/ remainingCards;
        double secondCardOdds = (outs + 3) /(remainingCards - 1);

        double fourOfAKindOdds = 1 / remainingCards * 1 / (remainingCards - 1); // Rare edge case where four-of-a-kind is drawn

        return (notFirstCardOdds * secondCardOdds) + firstCardOdds + fourOfAKindOdds;
    }
    
    if(pairCounter == 1 && tableCards.size() == 4) // Return current odds if on Turn
    { 
        return firstCardOdds;
    }

    return -1; //something has gone wrong
}

