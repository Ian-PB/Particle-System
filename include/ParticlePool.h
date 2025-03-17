#pragma once

#include "../include/Particle.h"
#include <memory>

class Particle; // Forward declaration

class ParticlePool
{
public:
    ParticlePool(Texture2D& t_screenTexture);

    static std::shared_ptr<Particle> requestParticle(Vector2 t_pos, float t_size, float t_speed, float t_dir, Color t_color);

    void update();
    void draw();

private:
    Texture2D& screenTexture;
    static const int POOL_SIZE = 1000;
    static std::shared_ptr<Particle> pool[POOL_SIZE];

    static int activeAmount;

};