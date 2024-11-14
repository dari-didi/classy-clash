#include "Basecharacter.h"

Basecharacter::Basecharacter(){

}

void Basecharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}
Rectangle Basecharacter::getCollisionRec(){
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}