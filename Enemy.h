#include "raylib.h"
#include "Basecharacter.h"
#include  "Character.h"


class Enemy : public Basecharacter
{
private:
    Character* target;

public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float deltaTime) override;
    void setTarget(Character* character){ target = character;};
    virtual Vector2 getScreenPos() override;
};

