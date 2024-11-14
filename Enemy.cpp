#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    run = run_texture;
    worldPos = pos;
    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::tick(float deltaTime){
    worldPosLastFrame = worldPos;

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.f;
        frame++;
        if (frame > maxFrames)
            frame = 0;
    }

    Rectangle source{width * frame, 0.f, rightLeft * width, height};
    Rectangle dest{worldPos.x, worldPos.y, width * scale, height * scale};
    DrawTexturePro(texture, source, dest, worldPos, 0.f, WHITE);
}