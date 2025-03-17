#include "../include/Particle.h"

Particle::Particle()
{
}

void Particle::update()
{
    // Decrease size as it moves
	if (scale > 0.0f)
	{
		scale -= 0.01f;
	}
	else
	{
		active = false;
	}
	// Decease Speed as it moves
	if (speed > 0.0f)
	{
		speed -= 0.2f;
	}
	else
	{
		if (scale > 0.0f)
		{
			scale -= 0.1f;
		}
		else
		{
			active = false;
		}
	}

	position.x += velocity.x;
	position.y += velocity.y;

	checkBounds();
}

void Particle::draw()
{
    DrawCircleV(position, size * scale, color);
}

void Particle::activate(Vector2 t_pos, float t_size, float t_speed, float t_dir, Color t_color)
{
	scale = 1.0f;
	
    position = t_pos;
    color = t_color;
    speed = t_speed;

    size = t_size;
	renderSize = size * 4.0f;
    
    velocity.x = sin(t_dir * DEG2RAD) * speed;
    velocity.y = cos(t_dir * DEG2RAD) * -speed;

	active = true;
}

void Particle::checkBounds()
{
	if (position.x < -100) // Give leeway so that if the camera moves it can still see it
	{
		active = false;
	}
	else if (position.x > GetScreenWidth() + 100)
	{
		active = false;
	}

	if (position.y < -100) // Give leeway so that if the camera moves it can still see it
	{
		active = false;
	}
	else if (position.y > GetScreenHeight() + 100)
	{
		active = false;
	}
}