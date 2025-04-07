#ifndef SCORE_H
#define SCORE_H

#include "imgui.h"

class Score {
public:     
    Score();
    void DrawScore();
    int GetScore();
    void IncrementScore();

private:
    int score;
};

#endif