#include "raylib.h"
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

class Basecharacter
{
protected:
    /* data */
    Texture2D texture{};
    Texture2D idle{};
    Texture2D run{};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};

    float speed{10.f};
    float rightLeft{1.f};

    float runningTime{0.f};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};

    float width{};
    float height{};
    float scale{4.0f};

public:
    Basecharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
};

#endif