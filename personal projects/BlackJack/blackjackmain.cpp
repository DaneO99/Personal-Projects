#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

struct Cards
{
    string suit;
    string rank;
    int value;
};

class Game
{
    private:
    int playerscore;
    int dealerscore;
    double bet;
    vector<Cards> dealerhand;
    vector<Cards> playerhand;
    vector<Cards> deck;

    public:
    Game(): playerscore(0), dealerscore(0)
    {
        string suits[] = {"Spade", "Diamond", "Hearts", "Clubs"};
        string rank[] = {"Ace", "King", "Queen","Jack","10","9","8","7","6","5","4","3","2"};
        int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10 , 11};

        for(const auto suit : suits)
        {
            for(int i = 0; i < 13; i++)
            {
                deck.push_back(Cards{suit, rank[i], values[i]});
            }
        }
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
    }

    void deal_initialcards();
    void startgame();
    void playerturn();
    void dealerturn();
    void updatescores();
    void determine_winner();
    int calculateHand(vector<Cards> &hand);
    double placeBets(double playerFunds);
    void handleSplit();
};

int main()
{
    Game blackjack;
    blackjack.startgame();
}

void Game :: deal_initialcards()
{
    playerhand.push_back(deck.back());
    deck.pop_back();
    playerhand.push_back(deck.back());
    deck.pop_back();

    dealerhand.push_back(deck.back());
    deck.pop_back();
    dealerhand.push_back(deck.back());
    deck.pop_back();

}

void Game :: startgame()
{
    char answer;
    deal_initialcards();
    placeBets(bet);
        if(playerhand[0].rank == playerhand[1].rank)
    {
        cout << "Do you want to split your two: " << playerhand[0].rank <<" (y/n)?";
        cin >> answer;
        if(answer == 'Y' || 'y')
        {
            handleSplit();
        }
        else
        {
            playerturn();
        }
    }
    else
    {
        playerturn();
    }
    dealerturn();
    updatescores();
    determine_winner();
}

void Game :: playerturn()
{
    char action;
    bool turnover = false;

    while(!turnover)
    {
        for(const auto& card :playerhand)
        {
            cout << "Your hand: ";
            cout << card.rank << " of "<< card.suit;
        }
    }
}

void Game :: dealerturn()
{

}

void Game :: updatescores()
{

}

void Game :: determine_winner()
{

}
int Game :: calculateHand(vector<Cards> &hand)
{
    int total = 0;
    int ace_count = 0;
    for(const auto& card : hand)
    {
        total += card.value;
        if(card.rank == "Ace")
        {
            ace_count++;
        }
    }
    while(total > 21 && ace_count > 0)
    {
        total -= 10;
        ace_count--;
    }
return total;
}

double Game::placeBets(double playerFunds) {
    double bet = 0.0;

    // Ask the player to place a bet
    while (true) {
        cout << "Place your bet (available funds: $" << playerFunds << "): ";
        cin >> bet;

        // Validate the bet
        if (cin.fail() || bet <= 0) {
            cout << "Invalid bet amount. Please enter a positive number." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
        } else if (bet > playerFunds) {
            cout << "You don't have enough funds to place that bet. Try a lower amount." << endl;
        } else {
            break; // Valid bet, exit the loop
        }
    }

    return bet;
}


void Game ::handleSplit()
{
    vector<Cards> first_hand = {playerhand[0]};
    vector<Cards> second_hand = {playerhand[1]};

    first_hand.push_back(deck.back());
    deck.pop_back();
    second_hand.push_back(deck.back());
    deck.pop_back();


}