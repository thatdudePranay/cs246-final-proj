export module TurnController;

export class TurnController {
    vector<unique_ptr<Player>> 

    public:
        TurnController(); // Constructor is needed

        // No Move/Copy is needed for TurnController, as there will only be one in-use. Delete is needed
        TurnController(const turnController& other) = delete;
        TurnController(turnController&& other) = delete;
        TurnController& operator=(const turnController& other) = delete;
        TurnController& operator=(turnController&& other) = delete;
        ~TurnController(); 

        void processRoll(int die1, int die2); 
        void advanceTurn();
        void resolveTimsTurn();
};
