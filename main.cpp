#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <random>
#include <ctime> 
#include <algorithm>

#include "Deck.h"

using namespace std;

int PLAYER_HAND_SIZE = 2;
int FLOP = 3;
int TURN = 4;
int RIVER = 5;

int main() {
  
  
    srand (time(NULL));

    Deck *deck = new Deck();

    auto currentDeck = deck->getDeck();

    vector<Card> playerHand;

    vector<Card> tableCards;

    int pokerPhase = FLOP;

    int randomIndex = rand() % 52;

    for(int i = 0; i < PLAYER_HAND_SIZE; i++)
    {
        while(currentDeck[randomIndex].second == true)
        {
            randomIndex = rand() % 52;        
        }

        playerHand.push_back(currentDeck[randomIndex].first);

        currentDeck[randomIndex].second = true;
    }

    for(int i = 0; i < pokerPhase; i++)
    {
        while(currentDeck[randomIndex].second == true)
        {
            randomIndex = rand() % 52;        
        }

        tableCards.push_back(currentDeck[randomIndex].first);
        
        currentDeck[randomIndex].second = true;
    }

    cout << "Player Hand: ";
    for(auto i : playerHand){
        cout << i.toString() << " ";
    }

    cout << endl << "Table Cards: ";
    for(auto i : tableCards){
        cout << i.toString() << " ";
    }

    return 0;
}