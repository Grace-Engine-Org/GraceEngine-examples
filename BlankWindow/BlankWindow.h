#include "../GraceEngine/include/graceEngine.h"

void blankWindow() {
    graceEngine window("Blank Window", 1280, 720);
    sf::Clock clock;

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

        window.renderObjects();


    }
}