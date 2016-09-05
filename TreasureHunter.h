#ifndef UNTITLED_TREASUREHUNTER_H
#define UNTITLED_TREASUREHUNTER_H

#include "GameBoard.h"
#include <iostream>


class TreasureHunter : public GameLogic  {
    private:
     //GameBoard _board;
GameBoard* _board;
Location _goal;
int lX;
int lY;
int currentScore;
Location _Hunter;

    public:

    //The Params are the starting locations of the Hunter, x and y respectiv$
        TreasureHunter(int, int, GameBoard&);
        ~TreasureHunter();

        void changeBoard(GameBoard&);
        void changeBoard(GameBoard*);
        int computeLetters(std::string);
        bool computeEnemy(char,std::string);
        bool computeTreasure();
        virtual int computeScore(std::string inputString);
};

#endif //UNTITLED_TREASUREHUNTER_H


