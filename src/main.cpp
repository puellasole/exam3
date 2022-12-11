#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "game_logic.h"
using namespace sf;
using namespace game_logic;

int main()
{
    const unsigned WINDOW_WIDTH = 600;
    const unsigned WINDOW_HEIGHT = 400;

    float dt;
    Clock dt_clock;

    int bit1Y = 150, bit2Y = 150;
    double ballPX = 290, ballPY = 200;
    float dx = 1.5f, dy = 1.5f;

    float radius = 10.f;
    sf::RectangleShape line;
    sf::CircleShape shape;
    sf::RectangleShape rectangle;
    sf::RectangleShape rectangle2;

    Game game(line, shape, rectangle, rectangle2, bit1Y, bit2Y, ballPX, ballPY, dx, dy, radius);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong game");

    line.setSize(sf::Vector2f(0.4, 400));
    line.setPosition(300, 0);
    line.setOutlineThickness(0.4);
    line.setFillColor(sf::Color::White);

    shape.setRadius(radius);
    shape.setPosition(ballPX, ballPY);
    shape.setFillColor(sf::Color::White);
    //1 player
    //sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(10, 90));
    rectangle.setPosition(0, bit1Y);
    rectangle.setOutlineThickness(0.4);
    rectangle.setFillColor(sf::Color::White);
    //2 player
    //sf::RectangleShape rectangle2;
    rectangle2.setSize(sf::Vector2f(10, 90));
    rectangle2.setPosition(590, bit2Y);
    rectangle2.setOutlineThickness(0.4);
    rectangle2.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        dt = dt_clock.restart().asSeconds();
        dx = game.collisionx(shape, rectangle, rectangle2, dx, dy);
        dy = game.collisiony(shape, rectangle, rectangle2, dx, dy);

        shape.move(dx, dy);


        //keyboards logic movement of players
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // left key is pressed: move our character
            rectangle.move(0, 5);
            if (rectangle.getPosition().y >= 310) {
                rectangle.setPosition(0, 310);
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // left key is pressed: move our character
            rectangle.move(0, -5);
            if (rectangle.getPosition().y <= 0) {
                rectangle.setPosition(0, 0);
            }

        }
        //p2 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            rectangle2.move(0, 5);
            if (rectangle2.getPosition().y >= 310) {
                rectangle2.setPosition(590, 310);
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            rectangle2.move(0, -5);
            if (rectangle2.getPosition().y <= 0) {
                rectangle2.setPosition(590, 0);
            }

        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        game.drawLine(line, &window);
        game.drawBall(shape, &window);
        game.drawFirstPlayer(rectangle, &window);
        game.drawSecondPlayer(rectangle2, &window);
        window.display();

        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }

    return 0;
}