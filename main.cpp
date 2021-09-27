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

int PLAYER_HAND_SIZE = 2;
int PREFLOP = 0;
int FLOP = 3;
int TURN = 4;
int RIVER = 5;


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
    for(auto i : playerHand){
        cout << i.toString() << " ";
    }

    cout << endl << "Table Cards: ";
    for(auto i : tableCards){
        cout << i.toString() << " ";
    }

    cout << endl << endl;


    //Print Equities
    cout << "         Card Equities" << endl;
    cout << "==========================" << endl;
    cout << "Pair:            |  " << pairOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Two Pair:        |  " << twoPairOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Three of a Kind: |  " << threeOfAKindOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Straight:        |  " << straightOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Flush:           |  " << flushOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Full House:      |  " << fullHouseOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Four of a kind:  |  " << fourOfAKindOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Straight Flush:  |  " << straightFlushOdds(currentDeck, playerHand, tableCards) << endl;
    // cout << "Royal Flush:     |  " << royalFlushOdds(currentDeck, playerHand, tableCards) << endl;
    return 0;
}