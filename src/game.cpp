#include "../include/game.h"

void Game::init()
{
    screenTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    particlePool = std::make_unique<ParticlePool>(screenTexture.texture);
}

void Game::update()
{
    particlePool->update();
}

void Game::draw()
{
    BeginTextureMode(screenTexture);

        // Draw all particles
        particlePool->draw();

        // Draw everything in here
        DrawRectangle(100, 100, 100, 100, RED);

    EndTextureMode();

    // Draw render texture
    DrawTexture(screenTexture.texture, 0, 0, WHITE);
}
