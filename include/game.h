#pragma once

#include "raylib.h"
#include "stdio.h"
#include "../include/ParticleSpawner.h"

class Game
{
public:
    void init();
    void update();
    void draw();

private:
    RenderTexture2D screenTexture;

    std::unique_ptr<ParticlePool> particlePool;

    std::unique_ptr<ParticleSpawner> spawner;
};
