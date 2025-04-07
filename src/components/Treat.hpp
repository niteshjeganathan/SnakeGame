#ifndef TREAT_H
#define TREAT_H

#include "imgui.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class Treat {
public:
    Treat();
    void DrawTreat();
    ImVec2 position;
    bool initialized = false;
private:
    float gridSize = 15.0f; 
};

#endif