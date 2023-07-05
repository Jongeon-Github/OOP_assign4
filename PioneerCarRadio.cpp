/*
* Filename: PioneerCarRadio.cpp
* Project: OOP-assign4
* Student ID: 8790144
* By: Jongeon Lee
* Date: Jun 08, 2023
* Description:
*/

#include "PioneerCarRadio.h"
#include "AmFmRadio.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

#pragma warning(disable:4996)

using namespace std;

PioneerCarRadio::PioneerCarRadio() {
    // Start with the radio off
    AmFmRadio::PowerToggle();
}

PioneerCarRadio::~PioneerCarRadio() {
    cout << "PioneerCarRadio is being destroyed." << std::endl;
}

void PioneerCarRadio::Run() {
    char key = {0};
    bool operation = true;
    while (operation) {
        key = getch();
        UserKey(key);
        if (key == 'x') {
            operation = false;
        }
    }
}

void PioneerCarRadio::UserKey(char key) {
    int currentVolume = 0;
    int volumeUp = 1;
    int volumeDown = -1;
    
    switch (key) {
    case 'o':
        AmFmRadio::PowerToggle();
        break;
    case '+':
        currentVolume = AmFmRadio::GetCurrentVolume() + volumeUp;
        AmFmRadio::SetVolume(currentVolume);
        break;
    case '_':
        currentVolume = AmFmRadio::GetCurrentVolume() + volumeDown;
        AmFmRadio::SetVolume(currentVolume);
        break;
    case '=':
        AmFmRadio::ScanUp();
        break;
    case '-':
        AmFmRadio::ScanDown();
        break;
    case 'b':
        AmFmRadio::ToggleBand();
        break;
    case '1':
        AmFmRadio::SelectPresetButton(0);
        break;
    case '2':
        AmFmRadio::SelectPresetButton(1);
        break;
    case '3':
        AmFmRadio::SelectPresetButton(2);
        break;
    case '4':
        AmFmRadio::SelectPresetButton(3);
        break;
    case '5':
        AmFmRadio::SelectPresetButton(4);
        break;
    case '!':
        AmFmRadio::SetPresetButton(0);
        break;
    case '@':
        AmFmRadio::SetPresetButton(1);
        break;
    case '#':
        AmFmRadio::SetPresetButton(2);
        break;
    case '$':
        AmFmRadio::SetPresetButton(3);
        break;
    case '%':
        AmFmRadio::SetPresetButton(4);
        break;
    case 'x':
        return;
    default:
        return;
    }
    DisplayPioneerRadio();
}

void PioneerCarRadio::DisplayPioneerRadio() {
    if (on == true) {
        current_station = round(current_station * 100) / 100; 
        cout << "Pioneer XS440" << endl;
        cout << (on ? "Radio is On" : "Radio is Off") << endl;
        cout << "Volume: " << volume << endl;
        cout << "Current Station: " << current_station << " " << band << endl;
        cout << "AM Buttons:" << endl;
        int numElements = sizeof(presets) / sizeof(presets[0]);
        int matchArrayNum = 1;
        for (int i = 0; i < numElements; i++) {
            if (i < numElements - matchArrayNum) {
                cout << i + matchArrayNum << ":" << setw(8) << setfill(' ') << presets[i].AMFreq << ",  ";
            }
            else {
                cout << i + matchArrayNum << ":" << setw(8) << setfill(' ') << presets[i].AMFreq << endl;
            }
        }
        cout << "FM Buttons:" << endl;
        for (int i = 0; i < numElements; i++) {
            if (i < numElements - matchArrayNum) {
                cout << i + matchArrayNum << ":" << setw(8) << setfill(' ') << presets[i].FMFreq << ",  ";
            }
            else {
                cout << i + matchArrayNum << ":" << setw(8) << setfill(' ') << presets[i].FMFreq << endl << endl;
            }
        }
    }
    else {
        cout << "Pioneer XS440" << endl;
        cout << (on ? "Radio is On" : "Radio is Off") << endl << endl;
    }
}
