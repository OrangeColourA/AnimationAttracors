#include "Ball.h"
#include <cmath>

Ball::Ball(Graphics& g, const Vec2f& p)
	:
	gfx(g),
	center_pos(p)
{}

void Ball::Draw() const
{
	gfx.DrawRect(center_pos - Vec2f(radius, radius), center_pos + Vec2f(radius, radius), color);
}

void Ball::Move(float dt)
{
	center_pos += velocity * dt;
}

bool Ball::Do_wall_collide(const Rectangle_f& wall, bool& game_over)
{
	Rectangle_f rect = Rectangle_f::GetRect(center_pos - Vec2f(radius, radius), center_pos + Vec2f(radius, radius));
	bool colided = false;

	if (rect.left < wall.left)
	{
		Bounce_x();
		center_pos.x += wall.left - rect.left;
		
		colided = true;
	}
	else if (rect.right > wall.right)
	{
		Bounce_x();
		center_pos.x -= rect.right - wall.right;
		
		colided = true;
	}

	if (rect.top < wall.top)
	{
		Bounce_y();
		center_pos.y += wall.top - rect.top;
		
		colided = true;
	}
	else if (rect.bottom > wall.bottom)
	{
		//Bounce_y();
		game_over = true;
		center_pos.y -= rect.bottom - wall.bottom;
		//center_pos.y = wall.bottom - 1.f;
		colided = true;
	}

	return colided;
}

bool Ball::Detect_brick_collioson(Brick& br)
{
	Rectangle_f ball_rect = Rectangle_f::GetRect(center_pos - Vec2f(radius, radius), center_pos + Vec2f(radius, radius));
	return !br.is_destroyed() && ball_rect.is_intersect(br.GetRect());
}

void Ball::Handle_brick_collision(Brick& br)
{
	// calling only if collision detected Detect_brick_collioson function

	Rectangle_f brick = br.GetRect();

	if (std::signbit(velocity.x) == std::signbit((center_pos - br.GetCenter()).x))
	{
		Bounce_y();
	}
	else if (center_pos.x < brick.left || center_pos.x > brick.right)
	{
		Bounce_x();
	}
	else
	{
		Bounce_y();
	}

	br.Destroy();
}

bool Ball::Hit_paddle(Paddle& p)
{
	if (!p.isCooldown())
	{
		Rectangle_f ball_rect = Rectangle_f::GetRect(center_pos - Vec2f(radius, radius), center_pos + Vec2f(radius, radius));
		Rectangle_f pad = p.GetRect();
		if (ball_rect.is_intersect(pad))
		{
			if (std::signbit(velocity.x) == std::signbit((center_pos - pad.GetCenter()).x))
			{
				Bounce_y_paddle(pad.GetCenter(), p.GetWidth());
				//Bounce_y();
			}
			else if (center_pos.x < pad.left || center_pos.x > pad.right)
			{
				Bounce_x();
			}
			else
			{
				Bounce_y_paddle(pad.GetCenter(), p.GetWidth());
				//Bounce_y();
			}

			p.SetOnCooldown();

			return true;
		}
	}
	return false;
}

void Ball::Bounce_x()
{
	velocity.x = -velocity.x;
}

void Ball::Bounce_y()
{
	velocity.y = -velocity.y;
}

void Ball::Bounce_y_paddle(const Vec2f& center_pad, int width_pad)
{
	// now we now pos of ball center and paddle center

	//calculating diff vector
	/*Vec2f pad_to_ball = center_pad - center_pos;

	velocity.x = initial_velocity.x * 2.f * pad_to_ball.x / width_pad;
	velocity.y = initial_velocity.y * (1.f - 2.f * pad_to_ball.x / width_pad);*/

	velocity.y = -dv;

	if (center_pos.x > center_pad.x)
	{
		velocity.x = dv;
	}
	else
	{
		velocity.x = -dv;
	}

}


Vec2f Ball::Get_pos() const
{
	return center_pos;
}
