#include "raylib.h"
#include "Basecharacter.h"

class Character : public Basecharacter
{
private:

public:
    Character(int winWidth, int winHeight);
    void tick(float deltaTime);
};