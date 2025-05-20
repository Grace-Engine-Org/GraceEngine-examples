#include "../GraceEngine/include/graceEngine.h"

void blankWindow() {
    graceEngine window("Test Window", 1280, 720);

    while (window.isRunning()) {
        window.updateEvents();

        if (window.getEvent(sf::Event::KeyPressed)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.stopRunning();
            }
        }

        window.renderObjects();


    }
}