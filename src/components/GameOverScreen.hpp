#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include "imgui.h"
#include <memory>

#include "../Game.hpp"
#include "Snake.hpp"
#include "Score.hpp"

class GameOverScreen {
public:
    GameOverScreen(std::shared_ptr<GameState> state);
    void DrawGameOverScreen(Snake& snake, Score& score, Treat& treat);
    void GameOverPopup(Snake& snake, Score& score, Treat& treat);

private:
    std::shared_ptr<GameState> state;
    bool isGameOverPopupOpen;
};



#endif