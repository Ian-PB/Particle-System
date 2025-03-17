#pragma once

#include "../include/Particle.h"
#include <memory>

class Particle; // Forward declaration

class ParticlePool
{
public:
    ParticlePool(Texture2D& t_screenTexture);

    static std::shared_ptr<Particle> requestParticle();

    void update();
    void draw();

private:
    static const int POOL_SIZE = 400;
    static std::shared_ptr<Particle> pool[POOL_SIZE];

    static int activeAmount;

};