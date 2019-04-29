#pragma once
#include "Physics.h"
//World
float P_Engine::World::GetWidth() { return m_width; }
float P_Engine::World::GetHeight() { return m_height; }
void P_Engine::World::SetWidth(float value) { m_width = value; }
void P_Engine::World::SetHeight(float value) { m_height = value; }

//Shape
float P_Engine::Shape::GetPivot() { return m_pivot; }
float  P_Engine::Shape::GetDiameter() { return m_diameter; }
void  P_Engine::Shape::SetDiameter(float value) { m_diameter = value; }
void  P_Engine::Shape::SetPivot(float value) { m_pivot = value; }
void P_Engine::Shape::SetPosition(float x, float y) { m_position_x = x; m_position_y = y; }
float P_Engine::Shape::GetPosition(int pos) 
{ 
	switch (pos)
	{
	case x:
		return m_position_x;
	case y:
		return m_position_y;
	default:
		return 0;
	}
}

//Physics
void P_Engine::Physics::SetGravity(float value) { m_gravity = value; }

float P_Engine::Physics::GetGravity() { return m_gravity; }

//Collision
bool P_Engine::Collision::GetCollision() { return m_collision; }
void P_Engine::Collision::SetCollision(bool value) { m_collision = value; }

//Motion
void P_Engine::Motion::Attract(Shape &shape1, Shape &shape2)
{

}
void P_Engine::Motion::Repel(Shape &shape1, Shape &shape2) {}
void P_Engine::Motion::Stop(Physics &physics)
{
	if (m_is_moving)
	{
		m_is_moving = false;
		physics.SetGravity(0.0f);
	}
}
void P_Engine::Motion::Start(Physics &physics)
{
	if (!m_is_moving)
	{
		physics.SetGravity(m_gravity);
		m_is_moving = true;
	}
}
bool P_Engine::Motion::IsMoving()
{
	return m_is_moving;
}