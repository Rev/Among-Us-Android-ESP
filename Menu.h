#ifndef MENU_H
#define MENU_H

#include "Drawing.h"
#include "Players.h"

namespace Menu
{
    int width;
    int height;

    void DrawMenu()
    {
        void *displays = Display_get_main();

        if(Display_get_main != nullptr)
        {
            width = Display_get_width(displays);
            height = Display_get_height(displays);

            ImGui::SetNextWindowSize(ImVec2(width * 0.9, height * 0.8));
            ImGui::Begin(OBFUSCATE("Among Us - Player List By Rev"));

            monoList<void **> *AllPlayerControls = offsets->PlayerControl.GetFieldByName<monoList<void **> *>("AllPlayerControls", nullptr);
            void *isGameOptions = offsets->PlayerControl.GetFieldByName<void *>("GameOptions", nullptr);

            if(isESP)
            {
                for (int i = 0; i < AllPlayerControls->getSize(); i++)
                {
                    auto Players = AllPlayerControls->getItems()[i];

                    if (Players != nullptr)
                    {
                        void *_cachedData = *(void **) ((uint64_t) Players + offsets->isCachedData);

                        if (_cachedData)
                        {
                            if(isESP)
                            {
                                auto isPlayerLocation = WorldToScreenPoint(get_main(), getPosition(Players));

                                if(isESPObject)
                                {
                                    std::string playerInfo;
                                    playerInfo += OBFUSCATE("Objects Active: ");
                                    playerInfo += std::to_string((int32_t) AllPlayerControls->getSize());

                                    ESP::DrawText2(height * 0.065f, ImVec2(height * 0.830f,  width * 0.01f), ImVec4(1,1,1,1), playerInfo.c_str());
                                }

                                if(isESPList)
                                {
                                    ImVec2 NameLocation[15];
                                    NameLocation[i] = ImVec2(width / 1.161f, (height / 1.953f) - i * 33.0f);

                                    ImVec2 StatusLocation[15];
                                    StatusLocation[i] = ImVec2(width / 1.041f, (height / 1.953f) - i * 33.0f);

                                    ImVec2 RoleLocation[15];
                                    RoleLocation[i] = ImVec2(width / 1.356f, (height / 1.953f) - i * 33.0f);

                                    monoString *isPlayerName = PlayerName(_cachedData);

                                    ESP::DrawText2(height * 0.035f, NameLocation[i], ImVec4(1,1,1,1), isPlayerName->get_string_old().c_str());

                                    bool isDead = *(bool *)((uint64_t)_cachedData + offsets->isDead);
                                    std::string isAliveInfo = isDead ? OBFUSCATE("Dead") : OBFUSCATE("Alive");

                                    ESP::DrawText2(height * 0.035f, StatusLocation[i], ImVec4(1,1,1,1), isAliveInfo.c_str());

                                    void *isRoleBehaviour = *(void **) ((uint64_t) _cachedData + offsets->isRole);

                                    if(isRoleBehaviour)
                                    {
                                        int isRole = *(int *)((uint64_t)isRoleBehaviour + offsets->isRoleType);

                                        if(isRole == 0)
                                        {
                                            ESP::DrawText2(height * 0.035f, RoleLocation[i], ImVec4(1, 1, 1, 1), OBFUSCATE("Crewmate"));
                                        }

                                        if(isRole == 1)
                                        {
                                            ESP::DrawText2(height * 0.035f, RoleLocation[i], ImVec4(1, 1, 1, 1), OBFUSCATE("Impostor"));
                                        }

                                        if(isRole == 2)
                                        {
                                            ESP::DrawText2(height * 0.035f, RoleLocation[i], ImVec4(1, 1, 1, 1), OBFUSCATE("Scientist"));
                                        }

                                        if(isRole == 3)
                                        {
                                            ESP::DrawText2(height * 0.035f, RoleLocation[i], ImVec4(1, 1, 1, 1), OBFUSCATE("Engineer"));
                                        }

                                        if(isRole == 4)
                                        {
                                            ESP::DrawText2(height * 0.035f, RoleLocation[i], ImVec4(1, 1, 1, 1), OBFUSCATE("Guardian Angel"));
                                        }

                                        if(isRole == 5)
                                        {
                                            ESP::DrawText2(height * 0.035f, RoleLocation[i], ImVec4(1, 1, 1, 1), OBFUSCATE("Shape Shifter"));
                                        }
                                    }
                                }

                                float isBoxWidth = (float) width / 16.0f;
                                float isBoxHeight = (float) height / 10.0f;

                                Vector2 isLocator = Vector2(isPlayerLocation.X, height - isPlayerLocation.Y);
                                Rect playerRect(isLocator.X - (isBoxHeight / 2), isLocator.Y - (isBoxWidth / 2), isBoxHeight, isBoxWidth);

                                if(isESPLine)
                                {
                                    void *isRoleBehaviour = *(void **) ((uint64_t) _cachedData + offsets->isRole);

                                    if(isRoleBehaviour)
                                    {

                                        int isRole = *(int *)((uint64_t)isRoleBehaviour + offsets->isRoleType);

                                        if(isRole == 0)
                                        {
                                            ESP::DrawLine(ImVec2(width * 0.5f, height * 0.5f), ImVec2(isPlayerLocation.X, height - isPlayerLocation.Y), ImVec4(0, 0, 1, 1));
                                        }

                                        if(isRole == 1)
                                        {
                                            ESP::DrawLine(ImVec2(width * 0.5f, height * 0.5f), ImVec2(isPlayerLocation.X, height - isPlayerLocation.Y), ImVec4(1, 0, 0, 1));
                                        }

                                        if(isRole == 2 || isRole == 3 || isRole == 4 || isRole == 5)
                                        {
                                            ESP::DrawLine(ImVec2(width * 0.5f, height), ImVec2(isPlayerLocation.X, height - isPlayerLocation.Y), ImVec4(0, 1, 0, 1));
                                        }
                                    }
                                }

                                if (isESPBox)
                                {
                                    void *isRoleBehaviour = *(void **) ((uint64_t) _cachedData + offsets->isRole);

                                    if(isRoleBehaviour)
                                    {
                                        int isRole = *(int *)((uint64_t)isRoleBehaviour + offsets->isRoleType);

                                        if(isRole == 0)
                                        {
                                            ESP::DrawBox(playerRect, ImVec4(0, 0, 1, 1));
                                        }

                                        if(isRole == 1)
                                        {
                                            ESP::DrawBox(playerRect, ImVec4(1, 0, 0, 1));
                                        }

                                        if(isRole == 2 || isRole == 3 || isRole == 4 || isRole == 5)
                                        {
                                            ESP::DrawBox(playerRect, ImVec4(0, 1, 0, 1));
                                        }
                                    }
                                }

                                if(isGameOptions != nullptr)
                                {
                                    if(isESPKillDistance)
                                    {
                                        if(get_isKillDistance(isGameOptions) == 0) //Short
                                        {
                                            ESP::DrawCircle(isLocator.X - (isBoxHeight / 20.0f), isLocator.Y - (isBoxHeight / 20.0f), height / 8.35f, false, ImVec4(1, 1, 1, 1));
                                        }

                                        if(get_isKillDistance(isGameOptions) == 1) //Medium
                                        {
                                            ESP::DrawCircle(isLocator.X - (isBoxHeight / 20.0f), isLocator.Y - (isBoxHeight / 20.0f), height / 3.85f, false, ImVec4(1, 1, 1, 1));
                                        }

                                        if(get_isKillDistance(isGameOptions) == 2) //Long
                                        {
                                            ESP::DrawCircle(isLocator.X - (isBoxHeight / 20.0f), isLocator.Y - (isBoxHeight / 20.0f), height / 2.65f, false, ImVec4(1, 1, 1, 1));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (ImGui::BeginTabBar(OBFUSCATE("")))
            {
                if (ImGui::BeginTabItem(OBFUSCATE("Player List")))
                {
                    ImGui::Checkbox(OBFUSCATE("Enable"), &isESP);

                    if(isESP)
                    {
                        ImGui::Indent(25.0f);

                        ImGui::Checkbox(OBFUSCATE("Lines"), &isESPLine);

                        ImGui::Checkbox(OBFUSCATE("2D Boxes"), &isESPBox);

                        ImGui::Checkbox(OBFUSCATE("Objects Active"), &isESPObject);

                        ImGui::Checkbox(OBFUSCATE("List"), &isESPList);

                        ImGui::Checkbox(OBFUSCATE("Kill Distance"), &isESPKillDistance);

                        ImGui::Unindent(25.0f);
                    }

                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }

            ImGui::End();
        }

    }
}

#endif