#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex): 
    worldPosProp(pos),
    texture(tex)
{


}

void Prop::Render(Vector2 knigtPos){
    screenPosProp = Vector2Subtract(worldPosProp, knigtPos);
    DrawTextureEx(texture, screenPosProp, 0, scale, WHITE); 
}

Rectangle Prop::getCollisionRec(Vector2 knigtPos){
    Vector2 screenPos = Vector2Subtract(worldPosProp, knigtPos);
    return Rectangle{
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale
    };
}