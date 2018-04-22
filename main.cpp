//
//  main.cpp
//  PlayCards
//
//  Created by Menno Dillen on 11.03.18.
//  Copyright © 2018 Menno Dillen. All rights reserved.
//

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};

enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

std::array<Card, 52> initiateDeck()
{
    int card {0};
    std::array<Card, 52> deck;
    for (int countRank = 0; countRank < MAX_RANKS; ++countRank)
    {
        for (int countSuit = 0; countSuit < MAX_SUITS; ++countSuit)
        {
            deck[card]
            = { static_cast<CardRank>(countRank), static_cast<CardSuit>(countSuit) };
            card++;
        }
    }
return deck;
}

void printCard(const Card& card)
{
    switch(card.rank)
    {
        case RANK_2:
            std::cout << '2';
            break;
        case RANK_3:
            std::cout << '3';
            break;
        case RANK_4:
            std::cout << '4';
            break;
        case RANK_5:
            std::cout << '5';
            break;
        case RANK_6:
            std::cout << '6';
            break;
        case RANK_7:
            std::cout << '7';
            break;
        case RANK_8:
            std::cout << '8';
            break;
        case RANK_9:
            std::cout << '9';
            break;
        case RANK_10:
            std::cout << 'T';
            break;
        case RANK_JACK:
            std::cout << 'J';
            break;
        case RANK_QUEEN:
            std::cout << 'Q';
            break;
        case RANK_KING:
            std::cout << 'K';
            break;
        case RANK_ACE:
            std::cout << 'A';
            break;
    }
    
    switch(card.suit)
    {
        case SUIT_CLUB:
            std::cout << 'C';
            break;
        case SUIT_DIAMOND:
            std::cout << 'D';
            break;
        case SUIT_HEART:
            std::cout << 'H';
            break;
        case SUIT_SPADE:
            std::cout << 'S';
            break;
    }
}

void printDeck(const std::array<Card, 52>& deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void swapCard(Card& card1, Card& card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

void shuffleDeck(std::array<Card, 52>& deck)
{
    for (auto& card : deck)
    {
        swapCard(card, deck[getRandomNumber(0, 51)]);
    }
}

int getCardValue(const Card& card)
{
    int value;
    
    switch(card.rank)
    {
        case RANK_2:
            value = 2;
            break;
        case RANK_3:
            value = 3;
            break;
        case RANK_4:
            value = 4;
            break;
        case RANK_5:
            value = 5;
            break;
        case RANK_6:
            value = 6;
            break;
        case RANK_7:
            value = 7;
            break;
        case RANK_8:
            value = 8;
            break;
        case RANK_9:
            value = 9;
            break;
        case RANK_10:
            value = 10;
            break;
        case RANK_JACK:
            value = 10;
            break;
        case RANK_QUEEN:
            value = 10;
            break;
        case RANK_KING:
            value = 10;
            break;
        case RANK_ACE:
            value = 11;
            break;
    }
    return value;
}

bool playBlackjack(std::array<Card, 52>& deck)
{
    Card* cardPtr = &deck[0];
    int scoreDealer;
    int scorePlayer;
    scoreDealer = getCardValue(*cardPtr++);
    bool winner {true};
    return winner;
}

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    
    std::array<Card, 52> deck = initiateDeck(); // initiate deck to zero
    
    printDeck(deck);
    
    shuffleDeck(deck);
    
    printDeck(deck);
    
    bool win = playBlackjack(deck);
    
    return 0;
}
