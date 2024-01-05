//
// Created by Beaver on 04/01/2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
class Button{
public:
    sf::Sprite sprite;
    Button()= default;
    Button(const std::string& t,const sf::Texture& img, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, bool blank){
        text.setString(t);
        text.setFillColor(textColor);
        text.setCharacterSize(charSize);

        button.setSize(size);
        button.setFillColor(bgColor);
        sprite.setTexture(img);
        if (blank){
            w = 2;
        }


    }
    void setFont(sf::Font &font){
        text.setFont(font);

    }
    void setBackColor(sf::Color color){
        button.setFillColor(color);
    }
    void setTextColor(sf::Color color){
        text.setFillColor(color);
    }
    void setPosition(sf::Vector2f pos){
        button.setPosition(pos);

        float xPos = (pos.x + button.getLocalBounds().width/w) - (text.getLocalBounds().width/2);
        float yPos = (pos.y + button.getLocalBounds().height/2) - (text.getLocalBounds().height/2);

        float spritexPos = (pos.x + button.getLocalBounds().width/1.3) - (sprite.getLocalBounds().width/2);
        float spriteyPos = (pos.y + button.getLocalBounds().height/1.7) - (sprite.getLocalBounds().height/2);
        text.setPosition({xPos,yPos});
        sprite.setPosition({spritexPos,spriteyPos});

    }


    void drawTo(sf::RenderWindow &window){
        window.draw(button);
        window.draw(text);
        window.draw(sprite);
    }
    bool isMouseOver(sf:: RenderWindow &window){
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY <btnyPosHeight && mouseY > btnPosY){
            return true;
        }
        return false;
    }

private:
    sf::RectangleShape button;
    sf::Text text;

    float w = 4;
};
