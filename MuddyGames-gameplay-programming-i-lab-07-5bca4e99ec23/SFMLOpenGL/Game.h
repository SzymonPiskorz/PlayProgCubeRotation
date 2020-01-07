#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>


using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
	void setupCube();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;

	Vector3 rotationAngle;

	Vector3 m_indexPosition[8];
	Matrix3 transformMatrix;
	float zValue;
};