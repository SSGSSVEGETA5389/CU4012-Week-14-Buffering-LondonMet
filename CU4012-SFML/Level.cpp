#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);
	speed = 200; 

	Player.setSize(sf::Vector2f(50, 50));
	Player.setFillColor(sf::Color::Red);
	Player.setOutlineThickness(5.f);
	Player.setPosition(100, 00);
	speed = 200.f; 

	bouncingShape.setRadius(20);
	bouncingShape.setPosition(150, 150); 
	bouncingShape.setFillColor(sf::Color::Blue); 
	bouncingShape.setOutlineThickness(5.0f); 

}

Level::~Level()
{
	

	}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		Player.move(0, speed * dt); 

	}

	if (input->isKeyDown(sf::Keyboard::A))
	{
		Player.move( -speed * dt, 0);

	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		Player.move(0, -speed * dt);

	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		Player.move (speed * dt, 0);

	}

	if (input->isKeyDown(sf::Keyboard::H))
	{
		bouncingShape.move(speed * dt, 0);

	}

	//Increase speed

	if (input->isKeyDown(sf::Keyboard::Add)) {

		input->setKeyUp(sf::Keyboard::Add); 
		bouncingSpeedX += 100.f;
		bouncingSpeedY += 100.f; 

		//Decrease Speed

		
	}

}

// Update game objects
void Level::update(float dt)
{

	circle.move(speed * dt, 0);


	if (circle.getPosition().x <= window->getSize().x - circle.getRadius())
	{
		speed = speed;

	}
	else
		speed = -speed; 
	if(circle.getPosition().x <=0)
	{
		speed = -speed;
	}

	//Boundary checks for player.

	sf::Vector2f pos = Player.getPosition();
	sf::Vector2f size = Player.getSize(); 

	//Right

	if (pos.x > window->getSize().x - size.x) {



	}
	//Left boundary

	if (pos.x < 0) {

		pos.x = 0;
			}

	//Bottom boundary 

	if (pos.y < 0)
	{
		pos.y = 0; 

	}

	//Apply corrected position 
	Player.setPosition(pos); 

	//Bouncing 

	bouncingShape.move(bouncingSpeedX * dt, bouncingSpeedY * dt);

	if (bouncingShape.getPosition().x <= 0 ||
		bouncingShape.getPosition().x >= window->getSize().x - bouncingShape.getRadius() * 2) {

		bouncingSpeedX = -bouncingSpeedX;

	}
	if (bouncingShape.getPosition().y <= 0 ||
		bouncingShape.getPosition().y >= window->getSize().y - bouncingShape.getRadius() * 2) {

		bouncingSpeedY = -bouncingSpeedY;

	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(Player);
	window->draw(bouncingShape);
	endDraw();
}

