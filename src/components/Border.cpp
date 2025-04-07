#include "Border.hpp"

Border::Border() {}


void Border::DrawBorder() {
    ImVec2 window_pos = ImGui::GetWindowPos();
    ImVec2 window_size = ImGui::GetWindowSize();

    ImVec2 unit_size(15, 15);

    //Top border
    for (float x = 0; x <= window_size.x - unit_size.x; x += unit_size.x) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x + x, window_pos.y));
        DrawBorderUnit();
    }

    //Bottom border
    for (float x = 0; x <= window_size.x - unit_size.x; x += unit_size.x) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x + x, window_pos.y + window_size.y - unit_size.y));
        DrawBorderUnit();
    }

    //Left border
    for (float y = unit_size.y; y <= window_size.y - unit_size.y * 2; y += unit_size.y) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x, window_pos.y + y));
        DrawBorderUnit();
    }

    //Right border
    for (float y = unit_size.y; y <= window_size.y - unit_size.y * 2; y += unit_size.y) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x + window_size.x - unit_size.x, window_pos.y + y));
        DrawBorderUnit();
    }
}

void Border::DrawBorderUnit() {
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    ImVec2 pos = ImGui::GetCursorScreenPos();

    ImVec2 size(15, 15); 

    ImVec2 bottom_right(pos.x + size.x, pos.y + size.y);

    ImU32 fill_color = IM_COL32(0, 0, 0, 0);  

    ImU32 border_color = IM_COL32(255, 255, 255, 255);  

    draw_list->AddRectFilled(pos, bottom_right, fill_color);

    draw_list->AddRect(pos, bottom_right, border_color, 0.0f, 0, 2.0f);  

    ImGui::Dummy(size);
}