#include "TreasureHunter.h"
#include "GameBoard.h"
#include "GameLogic.h"

TreasureHunter::TreasureHunter(int x, int y, GameBoard& board){
    lX = x;
    lY = y;
    _board = &board;
    _goal =  board.getGoalLocation();
}
TreasureHunter::~TreasureHunter(){
}

void TreasureHunter::changeBoard(GameBoard& newBoard){
    _board = &newBoard;
 _goal =  newBoard.getGoalLocation();

 }
void TreasureHunter::changeBoard(GameBoard* newBoard){
    _board = newBoard;
 _goal =  newBoard->getGoalLocation();

  }

int TreasureHunter::computeScore(std::string inputString){
    currentScore = 50;
    for (int i = 0 ; i < inputString.length();i++){
        if(computeTreasure()==true){
           currentScore = currentScore +10;
        }
        if (_board->isEnemy(_Hunter) ){
         computeEnemy(inputString.at(i),inputString);
        }
        if(currentScore ==0){
            return currentScore;
            i = inputString.length()-1;
         }

    switch(inputString.at(i))
    {
        case 'u':
               if(std::abs(_goal.getY()-lY)>std::abs(_goal.getY()-(lY+1))) {
                 currentScore++;
                 }
               else {
                   currentScore = currentScore -2;
               }
               _Hunter.setY(lY+1);
               lY=lY+1;
                  break;
        case 'd':
               if(std::abs(_goal.getY()-lY)>std::abs(_goal.getY()-(lY-1))){
                 currentScore++;
                  }
               else {
                   currentScore = currentScore -2;
                   }
               _Hunter.setY(lY-1);
               lY=lY-1;
                  break;
 case 'l':
               if(std::abs(_goal.getX()-lX)>std::abs(_goal.getX()-(lX-1))){
                  currentScore++;}
               else {
                   currentScore = currentScore -2;}
             _Hunter.setX(lX-1);
             lX=lX+1;
                  break;
        case 'r':
               if(std::abs(_goal.getX()-lX)>std::abs(_goal.getX()-(lX+1)) ){
               currentScore++;}
               else {
                   currentScore = currentScore -2;}
               _Hunter.setX(lX+1);
               lX=lX-1;
                  break;
        case 'a': computeEnemy('a',inputString);
                  break;
        case 'b':
                  break;
       default :
        currentScore--;
                  break;
     }
    }
   return currentScore;
}

bool TreasureHunter::computeEnemy(char letter ,std::string inputString){
   if (!(_board->isEnemy(_Hunter) && (letter =='a' |GameLogic::containsKonamiCode(inputString) == true))){
                    _board->killEnemy(_Hunter);
                    return false;
                 }
                 return true;
}

bool TreasureHunter::computeTreasure(){
return _board->isTreasure(_Hunter);
}
