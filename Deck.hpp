#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Card // Support class for a card
{
private:
    int value;
    string suit;

public:

    Card(){}
    
    Card(int value, string suit)
    {
        this->value = value;
        this->suit = suit;
    }

    int getValue(){return value;}

    string getSuit(){return suit;}

    string toString(){
        string cardValue;

        switch(value){
            case 11:
                cardValue = "Jack";
                break;
            case 12:
                cardValue = "Queen";
                break;
            case 13:
                cardValue ="King";
                break;
            case 14:
                cardValue = "Ace";
                break;
            default:
                cardValue = to_string(value);
        }

        return cardValue + " of " + suit;
    }
};

class Deck //Class for a tasklist
{
private:
    std::vector<pair<Card, bool>> deck; //Each task has a name, due date, and type
    int remainingCards;
public:
    // constructor
    Deck(){

        for(int i = 2; i < 15; i++)
        {
            Card spades(i, "spades");
            Card hearts(i, "hearts");
            Card clubs(i, "clubs");
            Card diamonds(i, "diamonds");

            deck.push_back(make_pair(spades, false));
            deck.push_back(make_pair(hearts, false));
            deck.push_back(make_pair(clubs, false));
            deck.push_back(make_pair(diamonds, false));
        }

        remainingCards = 52;
    }

    auto getDeck(){return deck;}

    auto getRemainingCards(){return remainingCards;}

};


