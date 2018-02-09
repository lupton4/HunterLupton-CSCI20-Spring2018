/*
 * Name        : Final_Game of Death
 * Author      : Hunter Lupton
 * Description : Text adventure game where you might die
 * Sources Used: L. Sathrum
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "CinReader.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class FinalGame{
public:
    FinalGame();
    void Start();

private:
    void RoomOne();
    void RoomTwo();
    void RoomThree();
    void RoomFour();
    void RoomFive();
    int RoomEnd();
    void ClearScreen();
    int current_room_;
    int playerStat;
    CinReader reader;
    bool hasStaffOfRah;
    bool hasHeartOfAnubis;
    bool hasEyeOfHorus;
    bool hasSandsOfSet;
    bool pedestal;
};
