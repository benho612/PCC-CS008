//
// Created by hoben on 11/6/2023.
//

#include "KeyboardShortcut.h"


bool KeyboardShortcut::isUndo() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
        && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return true;
  else
        return false;
}
