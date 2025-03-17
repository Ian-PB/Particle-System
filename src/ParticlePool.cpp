#include "../include/ParticlePool.h"

std::shared_ptr<Particle> ParticlePool::pool[POOL_SIZE];
int ParticlePool::activeAmount = 0;


ParticlePool::ParticlePool(Texture2D &t_screenTexture)
{
    for (int i = 0; i < POOL_SIZE; i++)
    {
        pool[i] = std::make_shared<Particle>(t_screenTexture);
    }
}

std::shared_ptr<Particle> ParticlePool::requestParticle()
{
    if (activeAmount < POOL_SIZE)
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            if (pool[i]->isActive()) // If active
            {
                
            }
            else // If not active
            {
                pool[i]->id = activeAmount;
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
                return pool[i];
            }
        }
    }

    // Shouldn't be called but just incase
    return nullptr;
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