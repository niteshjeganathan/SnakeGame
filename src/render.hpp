#pragma once

#include <cstdint>
#include <string_view>
#include "components/Border.hpp"
#include "components/Snake.hpp"
#include "components/Treat.hpp"
#include "Game.hpp"
#include "components/IntroScreen.hpp"
#include "components/GameOverScreen.hpp"
#include "components/Score.hpp"
#include <memory>

class WindowClass
{
public:
    WindowClass();
    void Draw(std::string_view label);

private:
    std::shared_ptr<GameState> state;
    IntroScreen introScreen;
    Border border;
    Score score;
    Snake snake;
    Treat treat;
    GameOverScreen gameOverScreen;
};

void render(WindowClass &window_obj);
