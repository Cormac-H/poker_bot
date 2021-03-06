#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <random>
#include <ctime> 
#include <algorithm>

#include "Deck.h"
#include "Equity.cpp"

using namespace std;

const int PLAYER_HAND_SIZE = 2;
//const int PREFLOP = 0;
const int FLOP = 3;
const int TURN = 4;
const int RIVER = 5;


int main() {
  
  
    srand (time(NULL));

    Deck *deck = new Deck(); //Initialize deck

    auto currentDeck = deck->getDeck();
    auto currentRemainingCards = deck->getRemainingCards();

    vector<Card> playerHand; //Initialize hands and poker phase

    vector<Card> tableCards;

    int pokerPhase = FLOP;

    int randomIndex = rand() % 52;

    for(int i = 0; i < PLAYER_HAND_SIZE; i++) //Randomly populate player hand
    {
        while(currentDeck[randomIndex].second == true)
        {
            randomIndex = rand() % 52;        
        }

        playerHand.push_back(currentDeck[randomIndex].first);

        currentDeck[randomIndex].second = true;
    }

    for(int i = 0; i < pokerPhase; i++) //Randomly populate table cards
    {
        while(currentDeck[randomIndex].second == true)
        {
            randomIndex = rand() % 52;        
        }

        tableCards.push_back(currentDeck[randomIndex].first);
        
        currentDeck[randomIndex].second = true;
    }

    currentRemainingCards -= (pokerPhase + PLAYER_HAND_SIZE); //set current remaining cards

    //Print Hands
    cout << "Player Hand: ";
    for(int i = 0; i < playerHand.size()-1; i++){
        cout << playerHand[i].toString() << ", ";
    }

    cout << playerHand[playerHand.size()-1].toString();
    cout << endl;

    cout << endl << "Table Cards: ";
    for(int i = 0; i < tableCards.size()-1; i++){
        cout << tableCards[i].toString() << ", ";
    }
    cout << tableCards[tableCards.size()-1].toString();
    cout << endl << endl;


    //Print Equities
    cout << "         Card Equities" << endl;
    cout << "==========================" << endl;
    cout << "Pair:            |  " << pairOdds(currentDeck, playerHand, tableCards) << endl;
    cout << "Two Pair:        |  " << twoPairOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Three of a Kind: |  " << threeOfAKindOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Straight:        |  " << straightOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Flush:           |  " << flushOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Full House:      |  " << fullHouseOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Four of a kind:  |  " << fourOfAKindOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Straight Flush:  |  " << straightFlushOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Royal Flush:     |  " << royalFlushOdds(currentDeck, playerHand, tableCards) << endl;
    return 0;
}