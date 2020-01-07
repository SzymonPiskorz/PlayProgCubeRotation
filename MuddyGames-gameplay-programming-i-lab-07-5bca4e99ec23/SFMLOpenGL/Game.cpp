#include <Game.h>

using namespace sf;

bool updatable = false;


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::setupCube()
{
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front bottom
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(m_indexPosition[0].x, m_indexPosition[0].y, m_indexPosition[0].z); //i0
		glVertex3f(m_indexPosition[1].x, m_indexPosition[1].y, m_indexPosition[1].z); //i1
		glVertex3f(m_indexPosition[2].x, m_indexPosition[2].y, m_indexPosition[2].z); //i2

		//Front top
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(m_indexPosition[2].x, m_indexPosition[2].y, m_indexPosition[2].z); //i2
		glVertex3f(m_indexPosition[3].x, m_indexPosition[3].y, m_indexPosition[3].z); //i3
		glVertex3f(m_indexPosition[0].x, m_indexPosition[0].y, m_indexPosition[0].z); //i0

		//Top front
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_indexPosition[2].x, m_indexPosition[2].y, m_indexPosition[2].z); //i2
		glVertex3f(m_indexPosition[6].x, m_indexPosition[6].y, m_indexPosition[6].z); //i6
		glVertex3f(m_indexPosition[3].x, m_indexPosition[3].y, m_indexPosition[3].z); //i3


		//Top back
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_indexPosition[6].x, m_indexPosition[6].y, m_indexPosition[6].z); //i6
		glVertex3f(m_indexPosition[7].x, m_indexPosition[7].y, m_indexPosition[7].z); //i7
		glVertex3f(m_indexPosition[3].x, m_indexPosition[3].y, m_indexPosition[3].z); //i3

		//Back Top
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_indexPosition[7].x, m_indexPosition[7].y, m_indexPosition[7].z); //i7
		glVertex3f(m_indexPosition[6].x, m_indexPosition[6].y, m_indexPosition[6].z); //i6
		glVertex3f(m_indexPosition[5].x, m_indexPosition[5].y, m_indexPosition[5].z); //i5

		//Back bottom
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_indexPosition[5].x, m_indexPosition[5].y, m_indexPosition[5].z); //i5
		glVertex3f(m_indexPosition[4].x, m_indexPosition[4].y, m_indexPosition[4].z); //i4
		glVertex3f(m_indexPosition[7].x, m_indexPosition[7].y, m_indexPosition[7].z); //i7


		//Bottom back
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(m_indexPosition[5].x, m_indexPosition[5].y, m_indexPosition[5].z); //i5
		glVertex3f(m_indexPosition[0].x, m_indexPosition[0].y, m_indexPosition[0].z); //i0
		glVertex3f(m_indexPosition[4].x, m_indexPosition[4].y, m_indexPosition[4].z); //i4


		//Bottom front
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(m_indexPosition[5].x, m_indexPosition[5].y, m_indexPosition[5].z); //i5
		glVertex3f(m_indexPosition[1].x, m_indexPosition[1].y, m_indexPosition[1].z); //i1
		glVertex3f(m_indexPosition[0].x, m_indexPosition[0].y, m_indexPosition[0].z); //i0

		//Right bottom
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(m_indexPosition[1].x, m_indexPosition[1].y, m_indexPosition[1].z); //i1
		glVertex3f(m_indexPosition[5].x, m_indexPosition[5].y, m_indexPosition[5].z); //i5
		glVertex3f(m_indexPosition[6].x, m_indexPosition[6].y, m_indexPosition[6].z); //i6

		//Right top
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(m_indexPosition[6].x, m_indexPosition[6].y, m_indexPosition[6].z); //i6
		glVertex3f(m_indexPosition[2].x, m_indexPosition[2].y, m_indexPosition[2].z); //i2
		glVertex3f(m_indexPosition[1].x, m_indexPosition[1].y, m_indexPosition[1].z); //i1

		//Left bottom
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(m_indexPosition[4].x, m_indexPosition[4].y, m_indexPosition[4].z); //i4
		glVertex3f(m_indexPosition[0].x, m_indexPosition[0].y, m_indexPosition[0].z); //i0
		glVertex3f(m_indexPosition[3].x, m_indexPosition[3].y, m_indexPosition[3].z); //i3

		//Left top
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(m_indexPosition[3].x, m_indexPosition[3].y, m_indexPosition[3].z); //i3
		glVertex3f(m_indexPosition[7].x, m_indexPosition[7].y, m_indexPosition[7].z); //i7
		glVertex3f(m_indexPosition[4].x, m_indexPosition[4].y, m_indexPosition[4].z); //i4


		////Front Face
		//glColor3f(0.0f, 0.0f, 1.0f);
		//glVertex3f(v3.getX(), 1.0f, -5.0f);
		//glVertex3f(-1.0f, 1.0f, -5.0f);
		//glVertex3f(-1.0f, -1.0f, -5.0f);
		//glVertex3f(1.0f, -1.0f, -5.0f);

		////Back Face
		//glColor3f(0.0f, 1.0f, 0.0f);
		//glVertex3f(1.0f, 1.0f, -15.0f);
		//glVertex3f(-1.0f, 1.0f, -15.0f);
		//glVertex3f(-1.0f, -1.0f, -15.0f);
		//glVertex3f(1.0f, -1.0f, -15.0f);

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::initialize()
{
	m_indexPosition[0] = { -1.0f, -1.0f, 1.0f };
	m_indexPosition[1] = { 1.0f, -1.0f, 1.0f };
	m_indexPosition[2] = { 1.0f, 1.0f, 1.0f };
	m_indexPosition[3] = { -1.0f, 1.0f, 1.0f };
	m_indexPosition[4] = { -1.0f, -1.0f, -1.0f };
	m_indexPosition[5] = { 1.0f, -1.0f, -1.0f };
	m_indexPosition[6] = { 1.0f, 1.0f, -1.0f };
	m_indexPosition[7] = { -1.0f, 1.0f, -1.0f };

	rotationAngle.x = 0.0f;
	rotationAngle.y = 0.0f;
	rotationAngle.z = 0.0f;

	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	
	setupCube();
}

void Game::update()
{
	setupCube();
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		rotationAngle.x = 0.5f;

		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.RotationX(rotationAngle.x) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		rotationAngle.y = 0.5f;

		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.RotationY(rotationAngle.y) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		rotationAngle.z = 0.5f;

		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.RotationZ(rotationAngle.z) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.Scale(101, 101) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.Scale(99, 99) * m_indexPosition[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.Translate(0.0f , 0.5f ) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.Translate(-0.5f, 0.0f) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.Translate(0.5f, 0.0f) * m_indexPosition[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 8; i++)
		{
			m_indexPosition[i] = transformMatrix.Translate(0.0f, -0.5f) * m_indexPosition[i];
		}
	}
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -8.0f);
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on X Axis

	
	
	

	glEnable(GL_CULL_FACE);

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

