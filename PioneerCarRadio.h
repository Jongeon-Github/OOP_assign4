/*
* Filename: PioneerCarRadio.h
* Project: OOP-assign4
* Student ID: 8790144
* By: Jongeon Lee
* Date: Jun 08, 2023
* Description: 
*/


#ifndef PIONEERCARRADIO_H
#define PIONEERCARRADIO_H

#include "AmFmRadio.h"

class PioneerCarRadio : public AmFmRadio
{
private:
    void UserKey(char key);
    void DisplayPioneerRadio();

public:
    PioneerCarRadio();
    ~PioneerCarRadio();
    void Run();
};
#endif  