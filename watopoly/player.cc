export module Player;
import <string>;

using namespace std;

const int TIMSLINEPOS = 10;

export class Player{
    string name;
    char piece; 
    int cash;
    int position;
    int timsCups;
    bool inTimsLine;
    int turnsInTimsLine;
    bool bankrupt;
    static inline int totalTimsCups = 0;

    public:

    // Constructor for new game
    Player(const string& name, char piece);
    
    // Constructor for saved game cuz it has more saved info
    Player(const string& name, char piece, int cash, int position,
        int timsCups, bool inTimsLine, int turnsInTimsLine);

    // Need custom destructor to decrement static totalTimsCup on destruction, also delete copy/move
    ~Player();
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player(Player&&) = delete;
    Player& operator=(Player&&) = delete;

    // Getter functions
    const string &getName() const;
    char getPiece() const;
    int getCash() const;
    int getPosition() const;
    int getTimsCup() const;
    bool getInTimsLine() const;
    int getTurnsInTimsLine() const;
    bool getBankrupt() const;
    static int getTotalTimsCups();

    // Setter functions
    void setPosition(int newPosition);
    void receiveMoney(int amount);
    bool payMoney(int amount); // False if player lacks cash

    // Cup usage/gainage
    void receiveCup();
    bool useCup();

    // Functions that Player owns to do tims stuff
    void enterTimsLine();
    void recordFailedTimsRoll();
    void leaveTimsLine();

    // Needs to be implemented after board is made
    int calculateNetWorth(const Board& board) const;
};
