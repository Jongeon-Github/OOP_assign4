/*
* Filename: PioneerCarRadio.h
* Project: OOP-assign4
* Student ID: 8790144
* By: Jongeon Lee
* Date: Jun 08, 2023
* Description: Header file for the PioneerCarRadio class.
*/

#ifndef PIONEERCARRADIO_H
#define PIONEERCARRADIO_H

#include "AmFmRadio.h"

class PioneerCarRadio : public AmFmRadio
{
private:
    // Gets key from user`s input
    void UserKey(char key);

    // Display all information of car radio
    void DisplayPioneerRadio();

public:
    // Constructor and Destructor
    PioneerCarRadio();
    ~PioneerCarRadio();

    // Runs the car radio program
    void Run();
};
#endif  