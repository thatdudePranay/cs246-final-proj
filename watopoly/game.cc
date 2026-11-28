export module Game;

using namespace std;

export class Game{
    Board board; 
    vector<unqiue_ptr<Player>> players;
    TurnController turnController;
    RandomGenerator randomGenerator;
    Economy economy; 
    optional<Auction> activeAuction;

    public:
        Game(int playerCount);  

        // Big 5 are not needed, Game will never be moved/copied, destructor is default
        Game(const Game& other) = delete;
        Game(Game&& other) = delete;
        Game& operator=(const Game& other) = delete;
        Game& operator=(Game&& other) = delete;
        ~Game() = default; 

        void roll();
        void roll(int die1, int die2);
        void nextTurn();
        void movePlayer(Player &player, int steps);
        void sendToTims(Player &player); 
};
