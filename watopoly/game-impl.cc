module Game;

Game::Game(int playerCount): board{}, players{}, turnController{}, economy{}, randomGenerator{} {}

void Game::roll() {
    int die1 = randomGenerator.randomInt(1,6);
    int die2 = randomGenerator.randomInt(1,6);
    roll(die1, die2);
}

void Game::roll(int die1, int die2) { 
    // Handle supplied vals testing and asks turncontroller about tims and double rulls, if player m0oves call movePlayer 
}

void nextTurn();
void movePlayer(Player &player, int steps);
void sendToTims(Player &player) {

}

