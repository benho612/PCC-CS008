#include "Application.h"
#include "AnimatedSprite.h"
#include "Images.h"
int main() {
    AnimatedSprite phaser{Images::getImage(PHASER),4,12};
    phaser.setSpeed(5);
    phaser.setTime(60);
    Application::addComponents(phaser);
    Application::run();

    return 0;
}
