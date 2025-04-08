#ifndef SNAKE_H
#define SNAKE_H

#include "imgui.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <memory>

#include "Treat.hpp"
#include "../Game.hpp"
#include "Score.hpp"


enum class Direction {
    Up, 
    Down, 
    Left, 
    Right,
    Idle
};

class Snake {
public:
    Snake(std::shared_ptr<GameState> state, Score& score);
    void DrawSnake();
    void Move();
    void Grow();
    void CollisionWithTreat(Treat& treat);
    bool initialized;

private:
    float moveTimer;
    float moveInterval;
    Direction direction;
    Direction nextDirection;
    std::vector<ImVec2> body;
    float gridSize;
    std::shared_ptr<GameState> state;

private:    
    void CollisionWithBorder();
    void CollisionWithBody();
    Score& score;
};

#endif