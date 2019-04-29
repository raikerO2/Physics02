namespace P_Engine
{
	class World
	{
	private:
		float m_width, m_height;
	public:
		World() {}
		World(float width, float height) : m_width(width), m_height(height){}
		float GetWidth();
		float GetHeight();
		void SetWidth(float value);
		void SetHeight(float value);
	};
	class Shape
	{
	private:
		float m_pivot;
		float m_diameter;
		float m_position_x, m_position_y;
	public:
		enum position : int {
			x, y
		};
		Shape(){}
		Shape(float diameter) : m_diameter(diameter) { m_pivot = m_diameter / 2; }
		float GetPivot();
		float GetDiameter();
		float GetPosition(int pos);
		void SetDiameter(float value);
		void SetPivot(float value);
		void SetPosition(float x, float y);
	};
	class Physics
	{
	private:
		float m_gravity;
	public:
		Physics() {}
		Physics(float gravity) : m_gravity(gravity){}
		void SetGravity(float value);

		float GetGravity();
	};
	class Collision
	{
	private:
		bool m_collision;
	public:
		Collision() : m_collision(false){}
		bool GetCollision();
		void SetCollision(bool value);
	};
	class Motion
	{
	private:
		bool m_is_moving;
		float m_gravity;
	public:
		Motion(Physics &physics)
		{ 
			m_gravity = physics.GetGravity(); 
		}
		void Attract(Shape &shape1, Shape &shape2);
		void Repel(Shape &shape1, Shape &shape2);
		void Stop(Physics &physics);
		void Start(Physics &physics);
		bool IsMoving();
	};
}
