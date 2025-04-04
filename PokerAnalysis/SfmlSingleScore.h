//
// Created by Ben Ho on 4/3/2023.
//

#ifndef POKERANALYSIS_SFMLSINGLESCORE_H
#define POKERANALYSIS_SFMLSINGLESCORE_H
#include "Component.h"
#include "SfmlCard.h"
#include "PokerScore.h"
#include <vector>

class SfmlSingleScore: public Component {
public:
    SfmlSingleScore();
    void setText();
    void setWord(const std::string& obj);
    void setPosition(sf::Vector2f position);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    sf::Text text;
    static sf::Font font;
};


#endif //POKERANALYSIS_SFMLSINGLESCORE_H
