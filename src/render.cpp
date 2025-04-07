#include <iostream>

#include <fmt/format.h>
#include <imgui.h>
#include <implot.h>
#include "render.hpp"

WindowClass::WindowClass() : 
    state(std::make_shared<GameState>(GameState::Intro)), 
    introScreen(state),border(Border()),
    score(Score()), 
    snake(state, score), 
    treat(Treat()), 
    gameOverScreen(state){}

void WindowClass::Draw(std::string_view label)
{
    constexpr static auto window_flags =
        ImGuiWindowFlags_NoResize | 
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoTitleBar;
    constexpr static auto window_size = ImVec2(900.0F, 900.0F);
    constexpr static auto window_pos = ImVec2(0.0F, 0.0F);


    ImGui::SetNextWindowSize(window_size);
    ImGui::SetNextWindowPos(window_pos);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin(label.data(), nullptr, window_flags);

    if(*state == GameState::Intro) {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10.0f, 10.0f));
        introScreen.DrawIntroScreen();
        ImGui::PopStyleVar();
    }

    if(*state == GameState::Running) {
        ImGui::BeginChild("BorderLayer", window_size, false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse );
        border.DrawBorder();
        ImGui::EndChild();

        snake.DrawSnake();

        treat.DrawTreat();

        snake.CollisionWithTreat(treat);

        score.DrawScore();
    }

    if(*state == GameState::GameOver) {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10.0f, 10.0f));
        gameOverScreen.DrawGameOverScreen(snake, score.GetScore(), treat);
        ImGui::PopStyleVar();
    }

    ImGui::End();
    ImGui::PopStyleVar();

}

void render(WindowClass &window_obj)
{
    window_obj.Draw("Snake Game");
}
