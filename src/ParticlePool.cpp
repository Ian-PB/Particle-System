#include "../include/ParticlePool.h"
#include "stdio.h"

std::shared_ptr<Particle> ParticlePool::pool[POOL_SIZE];
int ParticlePool::activeAmount = 0;


ParticlePool::ParticlePool(Texture2D &t_screenTexture)
    : screenTexture(t_screenTexture)
{
    for (int i = 0; i < POOL_SIZE; i++)
    {
        pool[i] = std::make_shared<Particle>();
    }
}

// By giving the particle the needed details it will return a particle with those details
std::shared_ptr<Particle> ParticlePool::requestParticle(Vector2 t_pos, float t_size, float t_speed, float t_dir, Color t_color)
{
    if (activeAmount < POOL_SIZE)
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            if (!pool[i]->isActive()) // If not active
            {
                pool[i]->id = activeAmount;
                activeAmount++;

                pool[i]->activate(t_pos, t_size, t_speed, t_dir, t_color);
                return pool[i]; // Now in use
            }
        }
    }
    // Remove the oldest active particle
    else 
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            pool[i]->id--;

            if (pool[i]->id < 0)
            {
                pool[i]->id = activeAmount;

                pool[i]->activate(t_pos, t_size, t_speed, t_dir, t_color);
                return pool[i];
            }
        }
    }

    // Return the first in the array if anything goes wrong
    return pool[0];
}


void ParticlePool::update()
{
    for (int i = 0; i < POOL_SIZE; i++)
    {
        if (pool[i]->isActive())
        {
            pool[i]->update();
        }
    }
}

void ParticlePool::draw()
{
    for (int i = 0; i < POOL_SIZE; i++)
    {
        if (pool[i]->isActive())
        {
            pool[i]->draw();
        }
    }
}