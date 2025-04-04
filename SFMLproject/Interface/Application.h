//
// Created by hoben on 10/31/2023.
//

#ifndef TYPING_APPLICATION_H
#define TYPING_APPLICATION_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "../History/History.h"
#include "ScreenType.h"

class Application {
public:
    static void addComponent(GUIComponent& components);
    static void run();
    static void switchScreen(ScreenType newScreen);

private:
    static ScreenType currentScreen;
    static std::vector<GUIComponent*> component;
};


#endif //TYPING_APPLICATION_H
