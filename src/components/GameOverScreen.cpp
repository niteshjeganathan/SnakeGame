#include "GameOverScreen.hpp"

GameOverScreen::GameOverScreen(std::shared_ptr<GameState> newState) : 
    state(newState),
    isGameOverPopupOpen(false) {}

void GameOverScreen::DrawGameOverScreen(Snake& snake, int score, Treat& treat) {
    ImGui::OpenPopup("Game Over!");

    isGameOverPopupOpen = true;

    GameOverPopup(snake, score, treat);
    
}

void GameOverScreen::GameOverPopup(Snake& snake, int score, Treat& treat) {
    if(ImGui::BeginPopupModal("Game Over!", &isGameOverPopupOpen, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse)) {
        ImGui::Text("Score: %d. Would you like to try again?", score);

        if (ImGui::Button("Try Again!")) {
            *state = GameState::Running;
            snake.initialized = false;
            treat.initialized = false;
        }

        ImGui::EndPopup();
    }
}