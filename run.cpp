#include <iostream>

#include "GameBoard.h"
#include "GameLogic.h"
#include "TreasureHunter.h"

using namespace std;

int main() {
    Location goalLocation(5, 7);
    GameBoard board(goalLocation);
    board.addTreasure(Location(8, 9));
    board.addTreasure(Location(-3, 6));
    board.addTreasure(Location(12, -1));

    board.addEnemy(Location(5, 6));
    board.addEnemy(Location(4, 7));


    cout << "Expect true: " << board.isTreasure(Location(8,9)) << endl;
    cout << "Expect true: " << board.isTreasure(Location(-3,6)) << endl;
    cout << "Expect true: " << board.isTreasure(Location(12,-1)) << endl;
    cout << "Expect true: " << board.isEnemy(Location(5,6)) << endl;
    cout << "Expect true: " << board.isEnemy(Location(4,7)) << endl;

    board.killEnemy(Location(5,6));
    board.removeTreasure(Location(-3,6));

    cout << "Expect false: " << board.isTreasure(Location(-3,6)) << endl;
    cout << "Expect false: " << board.isTreasure(Location(-2,6)) << endl;
    cout << "Expect false: " << board.isTreasure(Location(12,1)) << endl;
    cout << "Expect false: " << board.isEnemy(Location(5,6)) << endl;
    cout << "Expect false: " << board.isEnemy(Location(43,7)) << endl;

    cout << "goal: " << board.getGoalLocation().getX() << " " << board.getGoalLocation().getY() << endl;

    TreasureHunter treasureHunter(0, 0, board);

    // try different userInput strings by changing this value

string userInput = "uddlrrab" ;// Original run.cpp input
//Old Board Score = 47 (Loss: No more moves)
//New Board Score = 41 (Loss: No more moves)

string userInput2 = "qqqqqqqqqqqqqqqqqqqqqqqqqqq";
//Old Board Score = 0 (Loss: Score <= 0)
//New Board Score = 0 (Loss: Score <= 0)

string userInput3 = "rrrrruuuuuuu";
//Old Board Score = 162  (Win)
//New Board Score = 138 (Loss: No more moves)

string userInput4 = "udasdflkasdab";
//Old Board Score = 39  (Win)
//New Board Score = 28 (Loss: No more moves)

string userInput5="udlaldubbbdaaarudiiodllaaabdlrlruuddlrlrba";
//Old Board: 25 (Loss: No more moves)
//New Board: 0 (Loss: Score <= 0)

             cout << (treasureHunter.containsKonamiCode(userInput) ?
             "Found code" : "No code entered")<<endl;
             cout << (treasureHunter.containsKonamiCode(userInput2) ?
             "Found code" : "No code entered")<<endl;
             cout << (treasureHunter.containsKonamiCode(userInput3) ?
             "Found code" : "No code entered")<<endl;
             cout << (treasureHunter.containsKonamiCode(userInput4) ?
             "Found code" : "No code entered")<<endl;
             out << (treasureHunter.containsKonamiCode(userInput5) ?
             "Found code" : "No code entered")<<endl;

cout << "\nscore with old board is: " << treasureHunter.computeScore(userInput);
cout << "\nscore with old board is: " << treasureHunter.computeScore(userInput2);
cout << "\nscore with old board is: " << treasureHunter.computeScore(userInput3);
cout << "\nscore with old board is: " << treasureHunter.computeScore(userInput4);
cout << "\nscore with old board is: " << treasureHunter.computeScore(userInput5);

    Location newGoalLocation(-1, 3);
    GameBoard newBoard(newGoalLocation);
    board.addTreasure(Location(0, 2));
    board.addTreasure(Location(-10, 8));
    board.addTreasure(Location(3, 12));


    board.addEnemy(Location(-1, 1));
    board.addEnemy(Location(5, 2));

    treasureHunter.changeBoard(newBoard);
    treasureHunter.changeBoard(&newBoard);

    cout << "\nscore with new board is: " << treasureHunter.computeScore(userInput);
    cout << "\nscore with new board is: " << treasureHunter.computeScore(userInput2);
    cout << "\nscore with new board is: " << treasureHunter.computeScore(userInput3);
    cout << "\nscore with new board is: " << treasureHunter.computeScore(userInput4);
     cout << "\nscore with new board is: " << treasureHunter.computeScore(userInput5);
    cout << endl;

    return 0;
}
