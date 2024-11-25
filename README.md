# Game Project

This repository is a game project using the Raylib library. The game involves characters, enemies, and props, with a main character (knight) that can move around, interact with props, and engage with enemies. The game logic includes character movement, collision detection, health management, and rendering of game elements.

## Key Components

- **Character**: Defined in [`Character.cpp`](Character.cpp) and [`Character.h`](Character.h), handles the main character's properties and behaviors.
- **Enemy**: Defined in [`Enemy.cpp`](Enemy.cpp) and [`Enemy.h`](Enemy.h), handles enemy behaviors and interactions with the main character.
- **Props**: Defined in [`Prop.cpp`](Prop.cpp) and [`Prop.h`](Prop.h), handles static objects in the game world.
- **Basecharacter**: Defined in [`Basecharacter.cpp`](Basecharacter.cpp) and [`Basecharacter.h`](Basecharacter.h), serves as a base class for characters and enemies.

## Game Loop

The game loop is managed in [`main.cpp`](main.cpp), where the game window is initialized, and the main character, enemies, and props are updated and rendered each frame. The `tick` function is used to update the state of characters and enemies each frame.


## How to Build

To build this project, you can use the provided `Makefile`. For example, to build in debug mode, run:

```sh
make PLATFORM=PLATFORM_DESKTOP BUILD_MODE=DEBUG

## How to Run
## After building the project, you can run the executable generated in the project directory. For example, on Windows:

[main.exe](http://_vscodecontentref_/21)