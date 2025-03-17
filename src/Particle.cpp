#include "../include/Particle.h"

Particle::Particle(Texture2D &t_screenTexture)
    : screenTexture(t_screenTexture)
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
}

void Particle::draw()
{
    Rectangle screenSection = { position.x - renderSize / 2.0f, position.y - renderSize / 2.0f, renderSize, renderSize };
    Rectangle dest = {position.x, position.y, renderSize, renderSize};
    Vector2 origin = { renderSize / 2.0f, renderSize / 2.0f };
    DrawTexturePro(screenTexture, screenSection, dest, origin, 0, WHITE);

    DrawCircleV(position, size, color);
}

void Particle::activate(Vector2 t_pos, float t_size, float t_speed, float t_dir, Color t_color)
{
    position = t_pos;
    color = t_color;
    speed = t_speed;
    size = t_size;
    
    velocity.x = sin(t_dir * DEG2RAD) * speed;
    velocity.y = cos(t_dir * DEG2RAD) * -speed;
}
