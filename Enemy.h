#include "raylib.h"
#include "Basecharacter.h"

class Enemy : public Basecharacter
{
private:

public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    void tick(float deltaTime);
};
