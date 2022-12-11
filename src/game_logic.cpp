#include "game_logic.h"
#include <SFML/Graphics.hpp>
using namespace sf;

namespace game_logic {
    Game::Game(sf::RectangleShape line1, sf::CircleShape shape1, sf::RectangleShape rectangle1, sf::RectangleShape rectangle21, int bit1Y1, int bit2Y1, double ballPX1, double ballPY1, float dx1, float dy1, float radius1) {
        line = line1;
        shape = shape1;
        rectangle = rectangle1;
        rectangle2 = rectangle21;
        bit1Y = bit1Y1;
        bit2Y = bit2Y1;
        ballPX = ballPX1;
        ballPY = ballPY1;
        dx = dx1;
        dy = dy1;
        radius = radius1;
    };

    void Game::drawLine(sf::RectangleShape line, sf::RenderWindow* window) {
        window->draw(line);
    }

    void Game::drawBall(sf::CircleShape shape, sf::RenderWindow* window) {
        window->draw(shape);
    }

    void Game::drawFirstPlayer(sf::RectangleShape rectangle, sf::RenderWindow* window) {
        window->draw(rectangle);
    }

    void Game::drawSecondPlayer(sf::RectangleShape rectangle2, sf::RenderWindow* window) {
        window->draw(rectangle2);
    }

    double Game::collisionx(sf::CircleShape shape, sf::RectangleShape rectangle, sf::RectangleShape rectangle2, float dx, float  dy) {
        if (shape.getPosition().x > 600 - 20) dx = 0, dy = 0;
        if (shape.getPosition().y > 400 - 20) dy = -dy;
        if (shape.getPosition().x < 0) dx = 0, dy = 0;
        if (shape.getPosition().y < 0) dy = -dy;
        //bit-s collision 
        if ((shape.getPosition().x < rectangle.getPosition().x + 10) && (shape.getGlobalBounds().intersects(rectangle.getGlobalBounds()))) dx = -dx;
        if ((shape.getPosition().x >= rectangle2.getPosition().x - 20) && (shape.getGlobalBounds().intersects(rectangle2.getGlobalBounds()))) dx = -dx;
        return dx;
    }

    double Game::collisiony(sf::CircleShape shape, sf::RectangleShape rectangle, sf::RectangleShape rectangle2, float dx, float  dy) {
        if (shape.getPosition().x > 600 - 20) dx = 0, dy = 0;
        if (shape.getPosition().y > 400 - 20) dy = -dy;
        if (shape.getPosition().x < 0) dx = 0, dy = 0;
        if (shape.getPosition().y < 0) dy = -dy;
        //bit-s collision 
        if ((shape.getPosition().x < rectangle.getPosition().x + 10) && (shape.getGlobalBounds().intersects(rectangle.getGlobalBounds()))) dx = -dx;
        if ((shape.getPosition().x >= rectangle2.getPosition().x - 20) && (shape.getGlobalBounds().intersects(rectangle2.getGlobalBounds()))) dx = -dx;
        return dy;
    }
}