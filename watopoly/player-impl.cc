module Player;
import <string>;
import <utility>;

using namespace std;

Player::Player(const string& name, char piece): name{name}, piece{piece}, 
    cash{1500}, position{0}, timsCups{0}, 
    inTimsLine{false}, turnsInTimsLine{0}, bankrupt{false} {}

Player::Player(const string& name, char piece, int cash, int position,
    int timsCups, bool inTimsLine, int turnsInTimsLine, bool bankrupt): name{name}, piece{piece},
    cash{cash}, position{position}, timsCups{timsCups},
    inTimsLine{inTimsLine}, turnsInTimsLine{turnsInTimsLine}, bankrupt{bankrupt} {
        totalTimsCups += timsCups;
    }

const string &Player::getName() const {return name;}
char Player::getPiece() const {return piece;}
int Player::getCash() const {return cash;}
int Player::getPosition() const {return position;}
int Player::getTimsCup() const {return timsCups;}
bool Player::getInTimsLine() const {return inTimsLine;}
int Player::getTurnsInTimsLine() const {return turnsInTimesLine;}
bool Player::getBankrupt() const {return bankrupt;}
int Player::getTotalTimsCups() {return totalTimsCups;}

void Player::setPosition(int newPosition) {position = newPosition;}
void Player::receiveMoney(int amount) {cash += amount;}
bool Player::payMoney(int amount) {
    if (amount > cash) return false;
    cash -= amount;
    return true;
}

void Player::receiveCup() {
    timsCups++; 
    totalTimsCups++;
}

bool Player::useCup() {
    if (timsCups == 0) return false;
    timsCup--;
    totalTimsCups--;
    return true;
}

void Player::enterTimsLine() {
    position = TIMSLINEPOS;
    inTimsLine = true;
    turnsInTimsLine = 0;
}

void Player::recordFailedTimsRoll() {
    ++turnsInTimesLine;
}

void Player::leaveTimsLine() {
    inTimsLine = false;
    turnsInTimesLine = 0;
}

// Needs to be implemented after board is made
int calculateNetWorth(const Board& board) const;
