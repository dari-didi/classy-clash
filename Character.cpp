

#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;
}
Vector2 Character::getScreenPos(){
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - (0.5f * width * scale),
        static_cast<float>(windowHeight) / 2.0f - (0.5f * height * scale)
    };
}

void Character::tick(float deltaTime)
{
    
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    Basecharacter::tick(deltaTime);

    Vector2 origin{};
    if (rightLeft > 0.f)
    {
        origin = {0.f, weapon.height * scale};
    } else {
        origin = {0.f, 0.f};
    }
    

    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x, getScreenPos().y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, 0.f, WHITE);

}