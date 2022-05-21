#ifndef PLAYERS_H
#define PLAYERS_H

#include "Drawing.h"

bool isESP;
bool isESPLine;
bool isESPBox;
bool isESPObject;
bool isESPList;
bool isESPKillDistance;

int (*Display_get_height)(void *);
int (*Display_get_width)(void *);
void *(*Display_get_main)();

Vector3 (*WorldToScreenPoint)(void *instance, Vector3);
void (*Screen_SetResolution)(int width, int height, bool fullscreen);
Vector3 (*Transform_get_position)(void *instance);
void (*get_position)(void *instance, Vector3 *_vectorInstance);
void *(*get_main)();
void *(*get_transform)(void *instance);

int (*get_isKillDistance)(void *instance);
monoString *(*PlayerName)(void *instance);

void AttachFunctions()
{
    WorldToScreenPoint = (Vector3(*)(void*, Vector3)) offsets->Camera_WorldToScreenPoint;
    Transform_get_position = (Vector3 (*)(void*)) offsets->Transform_get_position;
    get_position = (void (*)(void *, Vector3*)) offsets->Transform_get_position_injected;
    get_transform = (void *(*)(void*)) offsets->Component_get_transform;
    get_main = (void*(*)()) offsets->Camera_get_main;

    get_isKillDistance = (int(*)(void *)) offsets->isKillDistance;
    PlayerName = (monoString *(*)(void *)) offsets->isName;
}

Vector3 getPosition(void *transform)
{
    return Transform_get_position(get_transform(transform));
}

#endif