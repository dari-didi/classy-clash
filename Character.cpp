#include <string>
#include <iostream>
#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth),
                                                    windowHeight(winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;
}
Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - (0.5f * width * scale),
        static_cast<float>(windowHeight) / 2.0f - (0.5f * height * scale)};
}

void Character::tick(float deltaTime)
{
    if (!getAlive())
        return;
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
    Vector2 offset{};
    float rotation{};

    if (rightLeft > 0.f)
    {
        origin = {0.f, weapon.height * scale};
        offset = {40.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
    }
    else
    {
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
    }

    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

    // for debugging, determine weapon collision rectangle using the values
    DrawRectangleLines(
        getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale, RED);
    DrawRectangleLines(
        weaponCollisionRec.x,
        weaponCollisionRec.y,
        weaponCollisionRec.width,
        weaponCollisionRec.height,
        BLUE);
}

void Character::takeDamage(float damage) {
    health -= damage;
    //std::cout << health << std::endl;
    //printf("float: %f", health);
    if (health <= 0.f)
    {
        setAlive(false);
    }
    
};