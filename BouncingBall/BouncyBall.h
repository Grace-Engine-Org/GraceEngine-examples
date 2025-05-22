#include "../GraceEngine/include/graceEngine.h"

void updatePosition(spriteObject &circle) {
    if (circle.getPosition().x <= 0 || circle.getPosition().x + circle.getSize().x >= 1280) {
        circle.setVelocity({circle.getVelocity().x * -1, circle.getVelocity().y});
    }

    if (circle.getPosition().y <= 0 || circle.getPosition().y + circle.getSize().y >= 720) {
        circle.setVelocity({circle.getVelocity().x, circle.getVelocity().y * -1});
    }
    circle.incrementPosition(circle.getVelocity());
}


void bouncyBall() {
    graceEngine window("Bouncy Ball", 1280, 720);
    sf::Clock clock;

    spriteObject* circle = new spriteObject("circle", "assets/textures/circle.png", {500, 500}, {64, 64});
    circle->setVelocity({4, 7});

    window.pushToQueue(circle);

    while (window.isRunning()) {
        sf::Time elapsedTime = clock.restart();
        window.updateEvents();

        if (window.getEvent(sf::Event::KeyPressed)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.stopRunning();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
                std::cout << "FPS: " << 1 / elapsedTime.asSeconds() << std::endl;
            }
        }

        updatePosition(*circle);

        window.renderObjects();

    }
}