#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "Basecharacter.h"

class Character : public Basecharacter
{
private:
    float windowWidth{};
    float windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.f};

public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisionRec(){ return weaponCollisionRec; };
    float getHealth(){return health; };
    void takeDamage(float damage);
};

#endif