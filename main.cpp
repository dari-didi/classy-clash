#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{
    float windowWidth = 384;
    float windowHeight = 384;

    InitWindow(windowWidth, windowHeight, "Map Window");
    // Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Texture2D map = LoadTexture("nature_tileset/randomMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight(windowWidth, windowHeight);
    //Prop rock(Vector2{200,300}, LoadTexture("nature_tileset/Rock.png"));
    Prop props[2]{
        Prop{Vector2{600,300}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400,500}, LoadTexture("nature_tileset/Sign.png")}
    };

    Enemy goblin(
        Vector2{}, 
        LoadTexture("characters/goblin_idle_spritesheet.png"), 
        LoadTexture("characters/goblin_run_spritesheet.png")
    );
        Enemy slime(
        Vector2{100,300}, 
        LoadTexture("characters/slime_idle_spritesheet.png"), 
        LoadTexture("characters/slime_run_spritesheet.png")
    );

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // draw the map
        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0, mapScale, WHITE);
        knight.tick(GetFrameTime());
        //rock.Render(knight.getWorldPos());
        for (auto prop  : props)
        {
            prop.Render(knight.getWorldPos());
        }
        // check map bounds, undo movement when passed the bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowWidth > map.width * mapScale ||
            knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement();
        }

        for (auto prop : props){
            if(CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec())) knight.undoMovement();
        }

        goblin.tick(GetFrameTime());
        slime.tick(GetFrameTime());
             
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}