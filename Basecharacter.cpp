#include "Basecharacter.h"
#include "raymath.h"

Basecharacter::Basecharacter(){

}

void Basecharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}
Rectangle Basecharacter::getCollisionRec(){
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void Basecharacter::tick(float deltaTime){

    worldPosLastFrame = worldPos;

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.f;
        frame++;
        if (frame > maxFrames)
            frame = 0;
    }
    
    if (Vector2Length(velocity) != 0.0)
    {
        // set mapPos = mapPos - direction
        // set worlPos = worlPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};
        // draw the character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);

}