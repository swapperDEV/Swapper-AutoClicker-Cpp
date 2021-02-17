// swapper clicker.cpp
#include <iostream>
#include <Windows.h>
using namespace std;

int speed;
int config() {
    cout << "SWAPPER ACLICKER - Please choose the speed how often the click is to be triggered in ms \n ";
    int speed;
    cin >> speed;
    return speed;
}
void menu() {
    cout << "Key 'x' enable, key 'z' disable, key 'o' to change options speed \n";
}
void clicker() {
    bool click = false;
    while (true) {
        if (GetAsyncKeyState('X')) {
            cout << "CLICKER START WITH SPEED:" << speed << "\n";
            click = true;
        }
        else if (GetAsyncKeyState('Z')) {
            click = false;
        }
        else if (GetAsyncKeyState('O')) {
            speed = config();
        }
        if (click == true) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(speed); 
        }
    }
}


int main()
{
    speed = config();
    system("cls");
    menu();
    clicker();
    return 0;
}

