#include "../include/ParticleSpawner.h"

int ParticleSpawner::minSize = 1;
int ParticleSpawner::maxSize = 10;
int ParticleSpawner::minSpeed = 1;
int ParticleSpawner::maxSpeed = 10;


void ParticleSpawner::spawn(Vector2 t_pos)
{
    for (int i = 0; i < particleAmount; i++)
    {
        float randDir = rand() % 360;
        int randSpeed = rand() % (maxSpeed - minSpeed + 1) + minSpeed;
        int randSize = rand() % (maxSize - minSize + 1) + minSize;
        Color randColor = randomizeColor();

        particles.push_back(ParticlePool::requestParticle(t_pos, randSize, randSpeed, randDir, randColor));
    }
}

// void ParticleSpawner::spawnTowards(Vector2 t_pos, float t_angleD, float t_leeway)
// {
// }



Color ParticleSpawner::randomizeColor()
{
    int randColor = rand() % colors.size();

    return colors[randColor];
}




void ParticleSpawner::setSizeRange(float t_min, float t_max)
{
    minSize = t_min;
    maxSize = t_max;
}

void ParticleSpawner::setSpeedRange(float t_min, float t_max)
{
    minSpeed = t_min;
    maxSpeed = t_max;
}