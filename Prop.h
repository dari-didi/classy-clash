#include "raylib.h"

class Prop
{
private:
    /* data */
    Vector2 worldPosProp{};
    Texture2D texture{};
    Vector2 screenPosProp{};

    float scale{4.0f};

public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 knigtPos);
    Rectangle getCollisionRec(Vector2 knigtPos);
};