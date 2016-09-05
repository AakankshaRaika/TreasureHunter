#include <string>
#include "GameLogic.h"

/*
 *Returns whether or not the Konami Code was contained in the input
 */
bool GameLogic::containsKonamiCode(std::string inputFile){
    // 1 point
std::string whatWeWant = "uuddlrlrba";
std::size_t found = inputFile.find(whatWeWant);
if (found >= 0 && found < inputFile.length()){
return true;}
return false;
}






