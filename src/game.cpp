#include "../include/game.h"

void Game::init()
{
    screenTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    particlePool = std::make_unique<ParticlePool>(screenTexture.texture);
    spawner = std::make_unique<ParticleSpawner>();

    // Spawner's settings
    spawner->addColor(GREEN);
    spawner->addColor(ORANGE);
    spawner->addColor(YELLOW);

    spawner->setParticleAmount(100);
    spawner->setSizeRange(10, 20);
    spawner->setSpeedRange(1, 2);
}

void Game::update()
{
    particlePool->update();

    if (IsMouseButtonDown(0))
    {
        spawner->spawn(GetMousePosition());
    }
}

void Game::draw()
{
    BeginTextureMode(screenTexture);
        ClearBackground(RAYWHITE);

        // Draw everything in here
        DrawRectangle(100, 100, 100, 100, RED);

        // Draw all particles
        particlePool->draw();


    EndTextureMode();

    Rectangle sourceRec = { 
        0.0f, 
        0.0f, 
        (float)screenTexture.texture.width, 
        (float)screenTexture.texture.height 
    };
    Rectangle destRec = {
        0.0f,
        0.0f,
        (float)screenTexture.texture.width,
        (float)screenTexture.texture.height
    };
    
    // Flip horizontally by making the source width negative
    sourceRec.height = -sourceRec.height;
    
    DrawTexturePro(screenTexture.texture, sourceRec, destRec, {0, 0}, 0, WHITE);
}
