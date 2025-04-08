#include "Border.hpp"

Border::Border() : borderSize(ImVec2(15.0F, 15.0F)) {}


void Border::DrawBorder() {
    ImVec2 window_pos = ImGui::GetWindowPos();
    ImVec2 window_size = ImGui::GetWindowSize();

    //Top border
    for (float x = 0; x <= window_size.x - borderSize.x; x += borderSize.x) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x + x, window_pos.y));
        DrawBorderUnit();
    }

    //Bottom border
    for (float x = 0; x <= window_size.x - borderSize.x; x += borderSize.x) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x + x, window_pos.y + window_size.y - borderSize.y));
        DrawBorderUnit();
    }

    //Left border
    for (float y = borderSize.y; y <= window_size.y - borderSize.y * 2; y += borderSize.y) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x, window_pos.y + y));
        DrawBorderUnit();
    }

    //Right border
    for (float y = borderSize.y; y <= window_size.y - borderSize.y * 2; y += borderSize.y) {
        ImGui::SetCursorScreenPos(ImVec2(window_pos.x + window_size.x - borderSize.x, window_pos.y + y));
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