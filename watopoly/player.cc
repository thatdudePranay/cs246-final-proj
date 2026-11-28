export module Player;
import <string>;

using namespace std;

export class Player{
    string name;
    char piece; 
    int cash;
    int position;
    int timsCups;
    bool inTimsLine;
    int turnsInTimesLine;
    bool bankrupt;
    static inline int totalTimsCups = 0;

    public:
    Player(string name, char piece, int cash = 1500, int position = 0, int timsCups = 0, bool inTimsLine = false, in turnsInTimesLine = 0);
    
    // Getter functions
    const string &getName() const;
    char getPiece() const;
    int getCash() const;
    int getPosition() const;
    int getTimsCup() const;
    bool getInTimsLine() const;
    int getTurnsInTimsLine() const;
    bool getBankrupt() const;

    // Setter functions
    void setPosition(int newPosition);
    void recieveMoney(int amount);
    bool payMoney(int amount); // False if player lacks cash

    // Cup usage/gainage
    void recieveCup();
    bool useCup();

    // Tims and whatnot functions
    

    int calculateNetWorth(const Board& board) const;
};
