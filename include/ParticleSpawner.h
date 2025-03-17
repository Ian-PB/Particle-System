#pragma once

#include "../include/ParticlePool.h"
#include <vector>

class ParticleSpawner
{
public:

    // --------- Spawn Types --------- //
    virtual void spawn(Vector2 t_pos);
    // void spawnTowards(Vector2 t_pos, float t_angleD, float t_leeway);



    // --------- Edit particle settings --------- //
    // Visuals
    // void addShader(Shader& t_shader) { shaders.push_back(t_shader); }
    void addColor(Color t_color) { colors.push_back(t_color); }
    // Attributes
    void setSizeRange(float t_min, float t_max);
    void setSpeedRange(float t_min, float t_max);
    void setParticleAmount(int t_amount) { particleAmount = t_amount; }


private:
    std::vector<std::shared_ptr<Particle>> particles;
    // std::vector<Shader&> shaders;
    std::vector<Color> colors;

    int particleAmount = 10; // Amount spawned per spawn command

    static int minSize;
    static int maxSize;

    static int minSpeed;
    static int maxSpeed;

    // Randomization
    Color randomizeColor();
};