//
// Created by hoben on 10/31/2023.
//
#include <thread>
#include "Application.h"
#include "../MainMenu/MainMenu.h"
#include "../PausingScreen/PausingScreen.h"
#include "../Online/Multiplayer.h"
#include "../Testing/SinglePlayer.h"
#include "../Option/OptionScreen.h"

std::vector<GUIComponent*> Application::component;

ScreenType Application::currentScreen;

void Application::addComponent(GUIComponent &components) {
    component.push_back(&components);
}

void Application::run() {

    sf::RenderWindow window({1024,768,32}, "Window");

    ///Here to add
    MainMenu menu;
    Player player;
    PausingScreen pausingScreen;
    Multiplayer multiplayer1;
    SinglePlayer gameTest;
    Server server;
    Client client;
    OptionScreen optionScreen;
    addComponent(pausingScreen);
    addComponent(menu);
    addComponent(player);
    addComponent(gameTest);
    addComponent(multiplayer1);
    addComponent(optionScreen);

    currentScreen = ScreenType::mainMenu;


    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Let each component handle its own events if it's part of the current screen
            for (GUIComponent*& g : component) {
                if (g->isActive(currentScreen)) {
                    g->eventHandler(window, event);
                }
            }
        }


        // Let each component update itself if it's part of the current screen
    for (GUIComponent*& g : component) {
        if (g->isActive(currentScreen)) {
            g->update();
        }
    }

    window.clear(sf::Color::White);

    // Draw each component if it's part of the current screen
    for (GUIComponent*& g : component) {
        if (g->isActive(currentScreen)) {
            window.draw(*g);
        }
    }

    window.display();
    }
}


void Application::switchScreen(ScreenType newScreen) {
    currentScreen = newScreen;

}
