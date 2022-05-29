//
// Created by Rev on 29/05/2021.
//

#ifndef OFFSETS_H
#define OFFSETS_H

struct Offsets
{
    //Unity:
    DWORD Component_get_transform = LoadClass(OBFUSCATE_BNM("UnityEngine"), OBFUSCATE_BNM("Component")).GetMethodOffsetByName(OBFUSCATE_BNM("get_transform"), 0);
    DWORD Transform_get_position_injected = LoadClass(OBFUSCATE_BNM("UnityEngine"), OBFUSCATE_BNM("Transform")).GetMethodOffsetByName(OBFUSCATE_BNM("get_position_Injected"), 1);
    DWORD Camera_get_main = LoadClass(OBFUSCATE_BNM("UnityEngine"), OBFUSCATE_BNM("Camera")).GetMethodOffsetByName(OBFUSCATE_BNM("get_main"), 0);
    DWORD Camera_WorldToScreenPoint = LoadClass(OBFUSCATE_BNM("UnityEngine"), OBFUSCATE_BNM("Camera")).GetMethodOffsetByName(OBFUSCATE_BNM("WorldToScreenPoint"), 1);
    DWORD Transform_get_position = LoadClass(OBFUSCATE_BNM("UnityEngine"), OBFUSCATE_BNM("Transform")).GetMethodOffsetByName(OBFUSCATE_BNM("get_position"), 0);
    DWORD Display_get_main = LoadClass(OBFUSCATES_BNM("UnityEngine"), OBFUSCATES_BNM("Display"), OBFUSCATES_BNM("UnityEngine.CoreModule.dll")).GetMethodOffsetByName(OBFUSCATES_BNM("get_main"), 0);
    DWORD Display_get_systemWidth = LoadClass(OBFUSCATES_BNM("UnityEngine"), OBFUSCATES_BNM("Display"), OBFUSCATES_BNM("UnityEngine.CoreModule.dll")).GetMethodOffsetByName(OBFUSCATES_BNM("get_systemWidth"), 0);
    DWORD Display_get_systemHeight = LoadClass(OBFUSCATES_BNM("UnityEngine"), OBFUSCATES_BNM("Display"), OBFUSCATES_BNM("UnityEngine.CoreModule.dll")).GetMethodOffsetByName(OBFUSCATES_BNM("get_systemHeight"), 0);

    //Methods:
    DWORD isKillDistance = LoadClass(OBFUSCATE_BNM(""), OBFUSCATE_BNM("GameOptionsData")).GetMethodOffsetByName(OBFUSCATE_BNM("get_KillDistance"), 0);
    DWORD isName = getRealOffset(0xBC43F4); //get_PlayerName (GameData.PlayerInfo)

    //Fields:
    DWORD isCachedData = LoadClass(OBFUSCATE_BNM(""), OBFUSCATE_BNM("PlayerControl")).GetFieldOffset(OBFUSCATE_BNM("_cachedData"));
    DWORD isDead = 0x28; //IsDead (GameData.PlayerInfo)
    DWORD isRole = 0x20; //Role (GameData.PlayerInfo)
    DWORD isRoleType = LoadClass(OBFUSCATE_BNM(""), OBFUSCATE_BNM("RoleBehaviour")).GetFieldOffset(OBFUSCATE_BNM("Role"));

    //Classes:
    LoadClass PlayerControl = LoadClass(OBFUSCATE_BNM(""), OBFUSCATE_BNM("PlayerControl"));
};

Offsets *offsets;

#endif
