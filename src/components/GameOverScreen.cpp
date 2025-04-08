#include "GameOverScreen.hpp"

GameOverScreen::GameOverScreen(std::shared_ptr<GameState> newState) : 
    state(newState),
    isGameOverPopupOpen(false) {}

void GameOverScreen::DrawGameOverScreen(Snake& snake, Score& score, Treat& treat) {
    ImGui::OpenPopup("Game Over!");

    isGameOverPopupOpen = true;

    GameOverPopup(snake, score, treat);
    
}

void GameOverScreen::GameOverPopup(Snake& snake, Score& score, Treat& treat) {
    if(ImGui::BeginPopupModal("Game Over!", &isGameOverPopupOpen, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse)) {
        ImGui::Text("Score: %d. Would you like to try again?", score.GetScore());

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));         
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.3f, 0.3f, 1.0f)); 
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.0f, 0.0f, 1.0f));   

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f); 

        if (ImGui::Button("Try Again!")) {
            *state = GameState::Running;
            snake.initialized = false;
            treat.initialized = false;
            score.ResetScore();
        }

        ImGui::PopStyleColor(3);
        ImGui::PopStyleVar();

        ImGui::EndPopup();
    }
}