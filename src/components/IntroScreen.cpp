#include "IntroScreen.hpp"
#include <iostream>

IntroScreen::IntroScreen(std::shared_ptr<GameState> newState) : isIntroOpen(true), state(newState) {}

void IntroScreen::DrawIntroScreen() {
    ImGui::OpenPopup("Snake Game Intro");

    IntroPopup();
}

void IntroScreen::IntroPopup() {
    if(ImGui::BeginPopupModal("Snake Game Intro", &isIntroOpen, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse)) {
        ImGui::Text("Welcome to Snake Game!");

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));         
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.3f, 0.3f, 1.0f)); 
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.0f, 0.0f, 1.0f));   

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f); 

        const auto returnPressed = ImGui::IsKeyPressed(ImGuiKey_Enter);

        if (ImGui::Button("Start") || returnPressed) {
            isIntroOpen = false;
            ImGui::CloseCurrentPopup();
            *state = GameState::Running;
        }

        ImGui::PopStyleVar();
        ImGui::PopStyleColor(3);

        ImGui::EndPopup();
    }
}