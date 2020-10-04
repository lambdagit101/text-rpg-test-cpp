#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int charage = 21;
string charname = "James";
int charheight = 182;
int charhealth = 80;
bool chararmed = false;

void clear_screen(char fill = ' ') {
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void game() {
    clear_screen();
    int dialogchoice;
    cout << "You wake up in a small house and you see an old lady making food." << endl;
    cout << "Possible dialog choices:" << endl << "1 - Where am I?" << endl << "2 - Who are you?" << endl << "3 - Get me out of here!" << endl << "4 - *silence*" << endl << "" << endl << "> ";
    cin >> dialogchoice;
    clear_screen();
    if (dialogchoice == 1 || dialogchoice == 2 || dialogchoice >= 4) {
        if (dialogchoice == 1) {
            cout << charname << ": Where am I?" << endl;
        } else if (dialogchoice == 2) {
            cout << charname << ": Who are you?" << endl;
        } else if (dialogchoice >= 4) {
            cout << charname << ": *silence*" << endl;
        }
        cout << "Old lady: Oh, you're awake! What's your name sweetie?" << endl;
        cout << charname << ": " << charname << ". My name is " << charname << "." << endl;
        cout << "Old lady: Good morning, " << charname << "! I made a chicken soup for you." << endl;
        cout << "Possible dialog choices:" << endl << endl << "1 - Thank you." << endl << "2 - No thanks." << endl << "" << endl << "> ";
        cin >> dialogchoice;
        clear_screen();
        if (dialogchoice == 1) {
            cout << charname << ": Thank you." << endl;
            cout << "Old lady: Here you go." << endl;
            charhealth += 20;
            cout << "20 HP RESTORED" << endl;
        } else {
            cout << charname << ": No thanks, I'm fine." << endl;
            cout << "Old lady: Alright then." << endl;
        }
        cout << "Old lady: Feel free to take a look around and take what you find." << endl << "You find an M9 Pistol and a pocket knife." << endl << endl << "1 - Take it" << endl << "2 - Leave it" << endl << " " << endl << "> ";
        cin >> dialogchoice;
        clear_screen();
        cout << "Old lady: Oh, you found my old pocket knife and gun. It's a long story how I got them." << endl;
        if (dialogchoice == 1) {
            chararmed = true;
            cout << "PICKED UP PISTOL AND POCKET KNIFE" << endl;
        } else {
            cout << charname << ": I don't need them." << endl;
            cout << "Old lady: Are you sure? There is danger out here." << endl;
        }
        cout << charname << ": Yeah. And by the way, what is your name?" << endl;
        cout << "Old lady: My name is Elizabeth." << endl;
        cout << charname << ": Alright, I think this is where I say Goodbye." << endl;
        cout << "Elizabeth: Goodbye, " << charname << "." << endl;
        cout << "You go around the forest Elizabeth's house was in, and find a bear." << endl;
        int bearenemy = 50;
        cout << "Possible actions:" << endl << endl << "1 - Shoot the bear" << endl << "2 - Attack the bear with your pocket knife" << endl << "3 - Flee" << endl << "" << endl << "> ";
        cin >> dialogchoice;
        clear_screen();
        if (dialogchoice == 1 && chararmed == false) {
            cout << "You tried attacking the bear with the M9 Pistol." << endl << "Your gun is missing." << endl << "Game Over: You got killed by a bear in combat" << endl;
            system("pause");
            return;
        } else if (dialogchoice == 1 && chararmed == true) {
            bearenemy -= 20;
            cout << "You tried attacking the bear with the M9 Pistol." << endl << "You dealt 50 damage" << endl << "You killed the bear" << endl;
            system("pause");
            clear_screen();
            cout << "You found a lake with fresh water." << endl << "Your current HP is " << charhealth << endl << "Possible actions:" << endl << endl << "1 - Drink from it (Your HP is filled)" << endl << "2 - Leave it" << endl << endl << "> ";
            cin >> dialogchoice;
            clear_screen();
            if (dialogchoice == 1) {
                if (charhealth == 100) {
                    cout << "Your HP is already full." << endl;
                } else {
                    charhealth = 100;
                    cout << "Your HP has been refilled. It is now " << charhealth << "." << endl;
                }
            } else {
                cout << "You go away from the lake, your HP being at " << charhealth << "." << endl;
            }
            system("pause");
            clear_screen();
            cout << "Thank you for playing, " << charname << "." << endl;
            system("pause");
            return;
        } else if (dialogchoice == 2) {
            cout << "You tried attacking the bear with your pocket knife." << endl << "The attack failed " << endl << "Game Over: You got killed by a bear in combat" << endl;
            system("pause");
        } else {
            cout << "You ran away from the fight." << endl << "You got chased down by the bear." << "Game Over: You got killed by a bear while fleeing" << endl;
            system("pause");
        }

    } else if (dialogchoice == 3) {
        cout << charname << ": What is this place? Get me out of here!" << endl;
        cout << "Old lady: No need to get scared. I'm here to protect you." << endl;
        cout << charname << ": I do need to get scared, what is this place!?" << endl;
        cout << "Old lady: I welcome you into my place, make you some food, and this is how you repay me?" << endl;
        cout << "Game over: The old lady threw you out of her house." << endl;
        system("pause");
        return;
    }
}

void charcreatingprocess() {
    clear_screen();
    cout << "Character Name: ";
    cin >> charname;
    clear_screen();
    cout << "Character Height: ";
    cin >> charheight;
    clear_screen();
    cout << "Character Age: ";
    cin >> charage;
    clear_screen();
    if (charname.find(" ") == 0 || charname == "") {
        charname = "James";
    }
    if (charage == 0 || charage < 18) {
        charage = 21;
    }
    if (charheight == 0) {
        charheight = 182;
    }
    string menuoption;
    cout << "Summary:" << endl;
    cout << "" << endl;
    cout << "Character Name: " << charname << endl << "Character Age: " << charage << endl << "Character Height: " << charheight << " cm" << endl << "" << endl << "Do you wish to continue? [Y/N]" << endl;
    cout << "" << endl;
    cout << "> ";
    cin >> menuoption;
    if (menuoption == "Y" || menuoption == "y") {
        cout << "Loading..." << endl;
        game();
        return;
    } else {
        charcreatingprocess();
        return;
    }
}

void charcreator() {
    string proceedcharcreate;
    clear_screen() ;
    cout << "Welcome to the Character Creator!" << endl;
    cout << "" << endl;
    cout << "You will be going through a list of questions" << endl;
    cout << "that define how your character will be in the" << endl;
    cout << "game. A list of things the character creator" << endl;
    cout << "will ask you to specify are:" << endl;
    cout << "-Your character's name (Default is James)" << endl;
    cout << "-Your character's age (Default is 21)" << endl;
    cout << "-Your character's height (Default is 1.82 meters)" << endl;
    cout << "After this process, the game will start with your" << endl;
    cout << "custom character, that characters in-game will refer to." << endl;
    cout << "Do you wish to proceed? [Y/N]" << endl;
    cout << "" << endl;
    cout << "> ";
    cin >> proceedcharcreate;
    if (proceedcharcreate == "Y" || proceedcharcreate == "y") {
        charcreatingprocess();
    } else {
        return;
    }
}

int main()
{
    clear_screen();
    int mainmenuchoice;
    cout << "Random Text RPG from the internet" << endl;
    cout << "" <<endl;
    cout << "1 - Play with default character" << endl;
    cout << "2 - Character Creator" << endl;
    cout << "3 - Exit" << endl;
    cout << "" << endl;
    cout << "> ";
    cin >> mainmenuchoice;
    if (mainmenuchoice == 2) {
        charcreator();
    } else if (mainmenuchoice == 3) {
        return 0;
    } else if (mainmenuchoice == 1) {
        game();
    }
}
