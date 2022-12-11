#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace game_logic
{
    class Game
    {
    private:
        int bit1Y = 0, bit2Y = 0;
        double ballPX = 0.f, ballPY = 0.f;
        float dx = 0.f, dy = 0.f;
        float radius = 0.f;
        sf::RectangleShape line;
        sf::CircleShape shape;
        sf::RectangleShape rectangle;
        sf::RectangleShape rectangle2;
    public:
        Game(sf::RectangleShape line, sf::CircleShape shape, sf::RectangleShape rectangle, sf::RectangleShape rectangle2, int bit1Y, int bit2Y, double ballPX, double ballPY, float dx, float dy, float radius);
        void drawLine(sf::RectangleShape line, sf::RenderWindow* window);
        void drawBall(sf::CircleShape shape, sf::RenderWindow* window);
        void drawFirstPlayer(sf::RectangleShape rectangle, sf::RenderWindow* window);
        void drawSecondPlayer(sf::RectangleShape rectangle2, sf::RenderWindow* window);
        double collisionx(sf::CircleShape shape, sf::RectangleShape rectangle, sf::RectangleShape rectangle2, float dx, float  dy);
        double collisiony(sf::CircleShape shape, sf::RectangleShape rectangle, sf::RectangleShape rectangle2, float dx, float  dy);
    };
}

