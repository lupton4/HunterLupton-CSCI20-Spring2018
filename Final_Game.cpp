#include "Final_game.h"
#include <windows.h>
FinalGame::FinalGame(){
    current_room_ = 1;
    hasEyeOfHorus = false;
    hasHeartOfAnubis = false;
    hasStaffOfRah = false;
    hasSandsOfSet = false;
    playerStat = 0;
    pedestal = false;
}
void FinalGame::Start(){
    bool GameStat = true;
    while (GameStat){
        switch (current_room_){
        case 1:
            RoomOne();
            break;
        case 2:
            RoomTwo();
            break;
        case 3:
            RoomThree();
            break;
        case 4:
            RoomFour();
            break;
        case 5:
            RoomFive();
            break;
        case 6:
            RoomEnd();
            if (hasEyeOfHorus == true && hasHeartOfAnubis == true && hasSandsOfSet == true && hasStaffOfRah == true && pedestal == true){
            GameStat = false;
            break;
        }

        }

    }

}
inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }
void FinalGame::RoomOne(){
    ClearScreen();
    if (playerStat == 0){
        cout << "You wake up in the middle of a room while wrapped in linens all over your body" << endl;
        cout << "Would you like to unwrap yourself? Y/N  ";
        playerStat = 1;
        char x = reader.readChar("yYNn");
        ClearScreen();
        if (x == 'y' || x == 'Y'){
            cout << "You successfully unwrap yourself and take a look around the room." << endl;
        }
        if (x == 'n' || x =='N'){
            cout << "Too bad you can't just lay there.\n" << "You struggle to get unwrapped because you are weak but eventually succeed." << endl;
            cout << "You take a look around the room." << endl;
        }
    }
    cout << "There is a pedestal in the middle, and four dark doorways with symbols above them." << endl;
    cout <<"What would you like to do?\n" << "Look at pedestal = P\n" << "Look at doorways = D \n";
    char y = reader.readChar("pPdD");
    ClearScreen();
    if (y == 'p' || y == 'P'){
        cout << "You step up to the pedestal and notice it has four engravings on the top\n"
        << "The engravings are of a staff, a bag of sand, an eye, and a heart.\n";
        if (hasEyeOfHorus == true && hasHeartOfAnubis == true && hasSandsOfSet == true && hasStaffOfRah == true){
            cout << "All of the items you have collected have the same markings as the pedestal, would you like to place them on it?  Y/N  \n";
            char c = reader.readChar("YyNn");
            ClearScreen();
            if (c == 'Y' || c =='y'){
                cout << "You place all four items on their respective engravings\n"
                << "The ground starts shaking and the pedestal shrinks into the ground\n"
                << " A deep voice shouts: The gods are satisfied with you!\n"
                << "Large rumbling can be heard as a you see a doorway begin to form in which you can see bright daylight\n"
                << "You run out and realize you are finally free of this strange place!!\n";
                Sleep(18000);
                current_room_ = 6;
            }
            }else{
                cout << "You memorize the markings and step back away from the pedestal and take a look around.\n" << endl;
            }


    }
    cout << " You take a closer look at the doorways, they each have a mark above them.\n"
    << " An eye, a bag of sand, a heart, and a staff\n" << "You decide to go though one of the doorways. Now the question is, which one?\n"
    << " Eye = E   Sand = S   Heart = H  Staff = T\n";
    char z = reader.readChar("EeSsHhTt");

    //Eye Room
    if (z == 'E' || z == 'e'){
        current_room_ = 2;
    }
    //Sand Room
    else if (z == 'S' || z == 's'){
        current_room_ = 3;
    }
    //Heart Room
    else if (z == 'H' || z == 'h'){
        current_room_ = 4;
    }
    //Staff Room
    else if (z == 't' || z == 'T'){
        current_room_ = 5;
    }



}
void FinalGame::RoomTwo(){
    bool lever = false;
    ClearScreen();
    cout << "You step into room that is filled to the brim with fog, you can't see two inches in front of your face.\n"
    << "You faintly see a shadow of a smaller pedestal across the room.\n"
    << "How would you like to get across the room?\n"
    << "Follow the walls = walls  or Head straight through the middle = middle?\n";
    string x = reader.readString("walls middle");
    ClearScreen();
    if (x == "walls"){
        cout << "You follow along the wall around the room, but stumble upon a lever.\n"
        << "Would you like to pull the lever?  Y/N \n";
        char y = reader.readChar("yYnN");
        ClearScreen();
        if (y == 'y' || y == 'Y'){
            cout << "You pull the lever and you can hear clunks and clanks all across the room, eventually they stop.\n";
            lever = true;
        }
        cout << "You continue your path alongside the walls around the room until you reach the pedestal.\n";
        }
     if (x == "middle"){
        cout << "You decide to go directly through the middle of the room with no visibility\n"
        << "You feel a plate move below your feet. You have a feeling like you should duck\n"
        << "Do you duck?  Y/N \n";
        char z = reader.readChar("yYnN");
        ClearScreen();
        if (z == 'y' || z == 'Y'){
            cout << "You duck but a spike comes from the ground and impales your skull!\n"
            <<" YOU DIED \n";
            Sleep(5000);
            hasEyeOfHorus = false;
            hasHeartOfAnubis = false;
            hasStaffOfRah = false;
            hasSandsOfSet = false;
            playerStat = 0;
            pedestal = false;
            current_room_ = 1;
        }
        else if (z == 'N' || z == 'n'){
            cout << "You decide not to duck for some reason.\n"
            << "A spike come through your legs narrowly missing your whole body, good thing you didn't duck.\n";

            cout << "You continue your way across the room eventually making it to the pedestal.\n";
        }
     }
        if (lever && hasEyeOfHorus == false){
            cout << "On the pedestal there seems to be an ancient golden eye placed on top.\n"
            << "Seeing as you can't see anything else in this room, you grab the eye.\n";
            hasEyeOfHorus = true;
            cout << "You decide there is no reason for you to stay in this room.\n"
            << "You make it back to the doorway safely crossing the room in the same way you did before.\n";
            Sleep(13000);
            current_room_ = 1;
            }else {
                cout << "The pedestal seems to be covered with a stone cover not allowing access to the pedestal\n";

        cout << "You decide there is no reason for you to stay in this room.\n"
        << "You make it back to the doorway safely crossing the room in the same way you did before.\n";
        Sleep(13000);
        current_room_ = 1;
            }

}
void FinalGame::RoomThree(){
    ClearScreen();
    cout << "You enter the room and it is bright and the floors and what it looks like the ceiling too is covered in sand.\n";
    if (hasSandsOfSet == false){
        cout << "You see a pedestal as the other side of the room with a bag on top.\n";
    }
    else {
        cout << "You see a pedestal with nothing on top of it.\n";
    }
    cout << "In the room there is nothing but the pedestal, sand, and a wooden board next to you\n";
    Sleep(10000);
    ClearScreen();
    cout << "How would you like to get across the room?\n"
    << "Walk across(It's just sand) = walk or use the board = board.\n";
    string x = reader.readString("walk board");
    if (x == "walk"){
        cout << "You start walking towards the pedestal and it seems like you are going to make it.\n"
        << "Your foot starts sinking just as you reach the pedestal.\n"
        << "Soon your whole body is underneath the hot sand.\n";
        Sleep(12000);
        ClearScreen();
        cout << "You suffocated underneath the sand along with multiple other bodies surrounding you.\n"
        << "YOU DIED!!\n";
        Sleep(5000);
        hasEyeOfHorus = false;
        hasHeartOfAnubis = false;
        hasStaffOfRah = false;
        hasSandsOfSet = false;
        playerStat = 0;
        pedestal = false;
        current_room_ = 1;
    }
    if (x == "board"){
        cout << "You practically boogie board all the way across the room towards the pedestal.\n"
        << "When you get there the board appears to sink a little but not too much.\n";
        if (hasSandsOfSet == false){
            cout << "There is what appears to be, a bag of sand on the pedestal.\n"
            << "Would you like to take the bag?  Y/N \n";
            char y = reader.readChar("YyNn");
            ClearScreen();
            if (y == 'Y' || y == 'y'){
                cout << "You take the bag and you here a thundering voice yell: Return my desert to me!! \n";
                hasSandsOfSet = true;
            }
            else {
                cout << "You decide to not grab the bag..... Really dude??\n";
            }
        }
        else{
            cout << "You look at the pedestal and it has an engraving of a bag of sand.\n";
        }
        cout << "You decide to head back to the main room you were in before.\n";
        Sleep(10000);
        current_room_ = 1;
    }

}
void FinalGame::RoomFour(){
    ClearScreen();
    cout << "You appear in a dark lit room with it seems shadows moving along the walls.\n"
    << "Your whole body is on edge, and you suddenly feel dead inside.\n";
    Sleep(10000);
    ClearScreen();
    cout << " In the middle of the room you can see an outline of a scale with something on it.\n"
    << "You need to get a closer look.\n";
    Sleep(10000);
    ClearScreen();
    cout << "Would you like to head towards the scale or go back?\n"
    << "Scale = scale and back = back. \n";
    string x = reader.readString("scale back");
    ClearScreen();
    if (x == "scale" && hasHeartOfAnubis == false){
        cout << "You begin to walk towards the scale.\n"
        << "It seems like the shadows on the walls seem agitated and keep moving closer to you with every step.\n"
        << "As you approach the scale, a large shadowy figure envelopes the whole room.\n";
        Sleep(13000);
        ClearScreen();
        cout << "His head is larger than you and is of the shape of a jackal.\n"
        << " He summons a ghostly scale and places a feather on one end.\n"
        << " As you would feel a knife through your heart he plunges his hand into your chest pulling out a shadow of your heart.\n";
        Sleep(13000);
        ClearScreen();
        cout << " He places your shadow of a heart onto the other end of the scale.\n";
         if (hasSandsOfSet == true){
            cout << "As your heart weighs down the scale. The figure looks at you with death in his eyes.\n"
            << "He with no emotion states: You have in your possession great evil, you are not worthy.\n";
            Sleep(10000);
            ClearScreen();
            cout << "With just a wave of his hand you slowly disintegrate into just a shadow. \n"
            << "You feel yourself being sucked into the walls of the room.\n"
            << "YOU DIED\n";
            Sleep(9000);
            hasEyeOfHorus = false;
            hasHeartOfAnubis = false;
            hasStaffOfRah = false;
            hasSandsOfSet = false;
            playerStat = 0;
            pedestal = false;
            current_room_ = 1;
         }
         if (hasSandsOfSet == false){
            cout << "As the feather pulls the scale down. The figure looks at you with light in his eyes.\n"
            << "With almost no emotion except a slight grin he states: You are pure, you are worthy.\n";
            Sleep(12000);
            ClearScreen();
            cout << "He hands you the real heart on the scale and without saying a word he disappears into the wall.\n";
            hasHeartOfAnubis = true;
         }
    }
    cout << "You walk back into the main room.\n";
    Sleep(5000);
    ClearScreen();
    current_room_ = 1;

}
void FinalGame::RoomFive(){
    ClearScreen();
    cout << "As you walk in the room, a deep and threating voice echoes around the room.\n"
    << "You stand there trembling as you hear the voice say: Do not go any further if you have not proven yourself!!\n";
    Sleep(9000);
    ClearScreen();
    cout << "Would you like to proceed?  Y/N \n";
    char x = reader.readChar("yYnN");
    ClearScreen();
        if (x == 'y' || x == 'Y'){
            cout << "You walk even further into the bright room. You feel like you're staring into the sun!\n";
            if (hasEyeOfHorus && hasHeartOfAnubis && hasSandsOfSet){
                cout << "The voice rumbles the whole room and says: You come to me with evidence of your worth!! \n"
                << "I shall offer you the final piece. \n"
                << " The light that is blinding you comes down to a slightly glowing man in a robe.\n";
                Sleep(9000);
                ClearScreen();
                cout << "He humbly offers you his staff and ominously tells you to not give it to set.\n"
                << "Do you accept his offer?  Y/N \n";
                char y = reader.readChar("yYnN");
                ClearScreen();
                if (y == 'y' || y == 'Y'){
                    cout << "You take the staff and feel the warmth it brings. \n"
                    << "The man tells you to leave and you promptly do so because who doesn't listen to the sun god?\n"
                    << "You head back to the main room.\n";
                    hasStaffOfRah = true;
                    Sleep(9000);
                    current_room_ = 1;
                }
                else {
                    cout << "The man grows into a giant fireball and yells: How dare you not accept my gift!!\n"
                    << "You burst into flames and fall onto the floor screaming for help!\n"
                    << "YOU DIED/n";
                    Sleep(9000);
                hasEyeOfHorus = false;
                hasHeartOfAnubis = false;
                hasStaffOfRah = false;
                hasSandsOfSet = false;
                playerStat = 0;
                pedestal = false;
                current_room_ = 1;
                }
            }
            else {
                cout << "You feel as though the light is getting brighter and brighter.\n"
                << "Suddenly a bright beam of light hits you incinerating you instantly. \n"
                << "YOU DIED\n";
                Sleep(9000);
                hasEyeOfHorus = false;
                hasHeartOfAnubis = false;
                hasStaffOfRah = false;
                hasSandsOfSet = false;
                playerStat = 0;
                pedestal = false;
                current_room_ = 1;
            }

        }
        else {
            cout << "You heed the warnings of the voice and leave in  a hurry.\n";
            Sleep(4000);
            current_room_ = 1;
        }
}
int FinalGame::RoomEnd(){
pedestal = true;
return 0;
}
void FinalGame::ClearScreen(){
 #ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}



