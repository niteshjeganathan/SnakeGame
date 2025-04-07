#ifndef INTROSCREEN_H
#define INTROSCREEN_H

#include "imgui.h"
#include <memory>

#include "../Game.hpp"

class IntroScreen {
public:
    IntroScreen(std::shared_ptr<GameState> state);
    void DrawIntroScreen();
private:
    bool isIntroOpen;
    std::shared_ptr<GameState> state;

private: 
    void IntroPopup();

};

#endif