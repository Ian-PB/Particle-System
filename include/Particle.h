#pragma once

#include <raylib.h>
#include <math.h>
#include <memory>

class Particle
{
public: 
    Particle();
    int id = -1; // Keeps track of where it is in the queue if pool used fully

    void update();
    void draw();

    void activate(Vector2 t_pos, float t_size, float t_speed, float t_dir, Color t_color);

    // Get functions
    bool isActive() { return active; }


private:
    void checkBounds();

    bool active = false;

    Vector2 position;
    Vector2 velocity;
    float speed = 0.0f;
    float duration = 0.0f; // Time till scale == 0 <-------------- // Add later

    float size = 0.0f;
    float renderSize = size * 4.0f;
    float scale = 1.0f;

    Color color = WHITE; 
};