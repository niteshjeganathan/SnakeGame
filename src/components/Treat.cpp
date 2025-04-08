#include "Treat.hpp"

Treat::Treat() : position(ImVec2(0.0F, 0.0F)), gridSize(15.0F) {}

void Treat::DrawTreat() {
    if (!initialized) {
        ImVec2 window_pos = ImGui::GetWindowPos();
        ImVec2 window_size = ImGui::GetWindowSize();

        float padding = gridSize;

        int cols = static_cast<int>((window_size.x - 2.0f * padding) / gridSize);
        int rows = static_cast<int>((window_size.y - 2.0f * padding) / gridSize);

        float spawn_x = window_pos.x + padding + static_cast<float>((rand() % cols) * static_cast<int>(gridSize));
        float spawn_y = window_pos.y + padding + static_cast<float>((rand() % rows) * static_cast<int>(gridSize));

        position = ImVec2(spawn_x, spawn_y);
        initialized = true;
    }

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImU32 fill_color = IM_COL32(255, 255, 255, 255); 

    ImVec2 bottom_right(position.x + gridSize, position.y + gridSize);
    draw_list->AddRectFilled(position, bottom_right, fill_color, 3.0f);
}