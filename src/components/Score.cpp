#include "Score.hpp"

Score::Score() : score(0) {}

void Score::DrawScore() {
    ImGui::SetCursorPos(ImVec2(ImGui::GetWindowSize().x - 150.0F, 20.0F));

    ImGui::Text("Current Score: %d", score);
}

int Score::GetScore() {
    return score;
}

void Score::IncrementScore() {
    score++;
}

void Score::ResetScore() {
    score = 0;
}