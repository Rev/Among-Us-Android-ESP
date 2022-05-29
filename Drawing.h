//
// Created by Rev on 29/05/2021.
//

#ifndef ImGuiAndroid_Drawing
#define ImGuiAndroid_Drawing

#include "../ImGui/imgui_internal.h"

namespace Drawing
{
    void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color)
    {
        auto background = ImGui::GetBackgroundDrawList();

        if(background)
        {
            background->AddLine(start, end, ImColor(color.x, color.y, color.z, color.w));
        }
    }

    void DrawBox(Rect rect, ImVec4 color)
    {
        ImVec2 v1(rect.x, rect.y);
        ImVec2 v2(rect.x + rect.width, rect.y);
        ImVec2 v3(rect.x + rect.width, rect.y + rect.height);
        ImVec2 v4(rect.x, rect.y + rect.height);

        DrawLine(v1, v2, color);
        DrawLine(v2, v3, color);
        DrawLine(v3, v4, color);
        DrawLine(v4, v1, color);
    }

    void DrawCircle(float X, float Y, float radius, bool filled, ImVec4 color)
    {
        auto background = ImGui::GetBackgroundDrawList();

        if(background)
        {
            if(filled)
            {
                background->AddCircleFilled(ImVec2(X, Y), radius, ImColor(color.x, color.y, color.z, color.w));
            }

            else

            {
                background->AddCircle(ImVec2(X, Y), radius, ImColor(color.x, color.y, color.z, color.w));
            }
        }
    }

    void DrawText2(float fontSize, ImVec2 position, ImVec4 color, const char *text)
    {
        auto background = ImGui::GetBackgroundDrawList();

        if(background)
        {
            background->AddText(NULL, fontSize, position, ImColor(color.x, color.y, color.z, color.w), text);
        }
    }
}

#endif
