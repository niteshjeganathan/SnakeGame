#ifndef BORDER_H
#define BORDER_H

#include "imgui.h"
#include <cstdint>


class Border {
public: 
    Border();
    void DrawBorder();

private:
    void DrawBorderUnit();
};

#endif