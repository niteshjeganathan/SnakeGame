#include "Snake.hpp"

Snake::Snake(std::shared_ptr<GameState> newState, Score& newScore) : 
    initialized(false),
    moveTimer(0.0f), 
    moveInterval(0.1f), 
    direction(Direction::Idle), 
    nextDirection(Direction::Idle), 
    body(std::vector<ImVec2>{ ImVec2(0.0f, 0.0f) }), 
    gridSize(15.0F),
    state(newState), 
    score(newScore)
{}

void Snake::DrawSnake() {
    if(!initialized) {
        body.clear();
        ImVec2 window_pos = ImGui::GetWindowPos();
        ImVec2 window_size = ImGui::GetWindowSize();

        float padding = gridSize;

        int cols = static_cast<int>((window_size.x - 2.0f * padding) / gridSize);
        int rows = static_cast<int>((window_size.y - 2.0f * padding) / gridSize);

        float spawn_x = window_pos.x + padding + static_cast<float>((rand() % cols) * static_cast<int>(gridSize));
        float spawn_y = window_pos.y + padding + static_cast<float>((rand() % rows) * static_cast<int>(gridSize));

        body.push_back(ImVec2(spawn_x, spawn_y));

        initialized = true;
    }

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImU32 fill_color = IM_COL32(255, 165, 0, 255); //Orange

    for (const ImVec2& segment : body) {
        ImVec2 bottom_right(segment.x + gridSize, segment.y + gridSize);
        draw_list->AddRectFilled(segment, bottom_right, fill_color, 3.0f);
    }

    if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow))  nextDirection = Direction::Left;
    if (ImGui::IsKeyPressed(ImGuiKey_RightArrow)) nextDirection = Direction::Right;
    if (ImGui::IsKeyPressed(ImGuiKey_UpArrow))    nextDirection = Direction::Up;
    if (ImGui::IsKeyPressed(ImGuiKey_DownArrow))  nextDirection = Direction::Down;

    if(initialized)
        Move();
}

void Snake::Move() {
    float deltaTime = ImGui::GetIO().DeltaTime;
    moveTimer += deltaTime;

    if (moveTimer < moveInterval)
        return;

    moveTimer = 0.0f;

    direction = nextDirection;

    CollisionWithBorder();
    CollisionWithBody();

    if (direction != Direction::Idle) {
        std::vector<ImVec2> previousPositions = body;

        switch (direction) {
            case Direction::Left:  body[0].x -= gridSize; break;
            case Direction::Right: body[0].x += gridSize; break;
            case Direction::Up:    body[0].y -= gridSize; break;
            case Direction::Down:  body[0].y += gridSize; break;
            default: break;
        }

        for (size_t i = 1; i < body.size(); ++i) {
            body[i] = previousPositions[i - 1];
        }
    }
}

void Snake::Grow() {
    if (body.empty()) return;

    ImVec2 tail = body.back();
    ImVec2 new_segment = tail;

    switch (direction) {
        case Direction::Left:
            new_segment.x += gridSize;  
            break;
        case Direction::Right:
            new_segment.x -= gridSize;  
            break;
        case Direction::Up:
            new_segment.y += gridSize;  
            break;
        case Direction::Down:
            new_segment.y -= gridSize;  
            break;
        default:
            break;
    }

    body.push_back(new_segment);
}

void Snake::CollisionWithBorder() {
    ImVec2 window_pos = ImGui::GetWindowPos();
    ImVec2 window_size = ImGui::GetWindowSize();
    ImVec2 window_end = ImVec2(window_pos.x + window_size.x, window_pos.y + window_size.y);

    ImVec2& head = body[0];

    if (head.x < window_pos.x + 2 * gridSize ||
        head.x + 3 * gridSize > window_end.x ||
        head.y < window_pos.y + 2 * gridSize ||
        head.y + 3 * gridSize > window_end.y) {
        
        direction = Direction::Idle;
        nextDirection = Direction::Idle;
        *state = GameState::GameOver;
    }
}

void Snake::CollisionWithTreat(Treat& treat) {
    ImVec2& head = body[0];

    if (head.x == treat.position.x && head.y == treat.position.y) {
        Grow();                    
        treat.initialized = false; 
        score.IncrementScore();
    }
}

void Snake::CollisionWithBody() {
    ImVec2& head = body[0];

    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i].x == head.x && body[i].y == head.y) {
            direction = Direction::Idle; 
            nextDirection = Direction::Idle;\
            *state = GameState::GameOver;
            break;
        }
    }
}