#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "Physics.h"
/*
	Playing around with some collision principles using some basic OOP.
*/
void Info(float &distance, P_Engine::Physics &physics, P_Engine::Collision &collision)
{
	std::cout << "distance: " << distance << std::endl;
	std::cout << "gravity: " << physics.GetGravity() << std::endl;
	std::cout << "collision: " << collision.GetCollision() << std::endl;
}
int main()
{
	std::string inp;
	
	float gravity = 5.0f;
	float distance = 250.0f;
	const float width = 500.0f, height = 500.0f;
	const float center_point = width / 2;
	P_Engine::Shape rectangle1(25.0f);
	P_Engine::Shape rectangle2(25.0f);
	P_Engine::World world(width, height);
	P_Engine::Physics physics(gravity);
	P_Engine::Collision collision;
	collision.SetCollision(false);
	P_Engine::Motion motion(physics);

	rectangle1.SetPosition(100.0f, 100.0f);
	rectangle2.SetPosition(200.0f, 200.0f);

	while (true)
	{
		Sleep(50);
		Info(distance, physics, collision);
		distance -= physics.GetGravity();
		if (distance < rectangle1.GetDiameter())
		{
			collision.SetCollision(true);
			std::cout << "Stopped" << std::endl;
			motion.Stop(physics);
			break;
		}
	}
	Info(distance, physics, collision);
	std::cout << "continue ? <y/n>: ";
	std::cin >> inp;
	if (inp == "y" || inp == "Y")
	{
		motion.Start(physics);
		collision.SetCollision(false);
		while (true)
		{
			Sleep(50);
			Info(distance, physics, collision);
			distance += physics.GetGravity();
			if (distance >= width)
			{
				collision.SetCollision(true);
				std::cout << "Stopped again" << std::endl;
				motion.Stop(physics);
				break;
			}
		}
	}
	Info(distance, physics, collision);
	std::system("PAUSE");
}