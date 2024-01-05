//
// Created by Beaver on 12/4/2023.
//

#include <SFML/Graphics.hpp>
#include "button.h"
#include <thread>
#include "../headers/diodeFactory.h"
#include "../headers/PcbStrategy.h"
#include "../headers/power_in.h"
#include <string>

#include "graphics.h"
void OpenWindow(){
    bool mousebut = false;
    std::string sizepcb;
    sf::Font arial;
    arial.loadFromFile("../sfml/Arial.ttf");
    sf::Texture diode_img;
    sf::Texture blanktext;
    diode_img.loadFromFile("../sfml/diode.png");
    sf::Texture zerner_img;
    zerner_img.loadFromFile("../sfml/zerner_diode.png");
    sf::Texture LED_img;
    LED_img.loadFromFile("../sfml/LED.png");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    //sf::CircleShape shape(50.f);

    sf::Sprite zerner_ent;
    zerner_ent.setTexture(zerner_img);


    Button btn("diode",diode_img, {200,50}, 18, sf::Color::Green, sf::Color::Black, false);
    btn.setFont(arial);
    btn.setPosition({50,100});

    Button btn1("LED",LED_img, {200,50}, 18, sf::Color::Green, sf::Color::Black,false);
    btn1.setFont(arial);
    btn1.setPosition({50,200});

    Button btn2("Zerner Diode",zerner_img, {200,50}, 18, sf::Color::Green, sf::Color::Black,false);
    btn2.setFont(arial);
    btn2.setPosition({50,300});

    Button btn3("Port Select",zerner_img, {200,50}, 18, sf::Color::Green, sf::Color::Black,false);
    btn3.setFont(arial);
    btn3.setPosition({50,400});

    Button pcbBig("bigPcbRed",blanktext, {100,50}, 16, sf::Color::Red, sf::Color::Black,true);
    pcbBig.setFont(arial);
    pcbBig.setPosition({300,50});

    Button pcbMed("MediumPcbGreen",blanktext, {100,50}, 16, sf::Color::Green, sf::Color::Black,true);
    pcbMed.setFont(arial);
    pcbMed.setPosition({500,50});

    Button pcbSmall("smallPcbBlue",blanktext, {100,50}, 16, sf::Color::Blue, sf::Color::Black,true);
    pcbSmall.setFont(arial);
    pcbSmall.setPosition({700,50});

    sf::RectangleShape pcbBigBoard;
    pcbBigBoard.setSize({400,400});
    pcbBigBoard.setFillColor(sf::Color::Red);
    pcbBigBoard.setPosition({300,150});

    sf::RectangleShape pcbMedBoard;
    pcbMedBoard.setSize({300,300});
    pcbMedBoard.setFillColor(sf::Color::Green);
    pcbMedBoard.setPosition({300,150});

    sf::RectangleShape pcbSmallBoard;
    pcbSmallBoard.setSize({200,200});
    pcbSmallBoard.setFillColor(sf::Color::Blue);
    pcbSmallBoard.setPosition({300,150});

    window.setFramerateLimit(60);

    PCBFactory factory{};






// set the shape color to green
    //shape.setFillColor(sf::Color(100, 250, 50));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
            switch (event.type) {
                case sf::Event::Closed:
                 window.close();
                 [[fallthrough]];
            case sf::Event::MouseMoved:
                if(btn.isMouseOver(window)){
                    btn.setBackColor(sf::Color::White);
                }
                else if(btn1.isMouseOver(window)){
                        btn1.setBackColor(sf::Color::White);
                }else if(btn2.isMouseOver(window)){
                    btn2.setBackColor(sf::Color::White);
                }else if(btn3.isMouseOver(window)){
                    btn3.setBackColor(sf::Color::White);
                }else if(pcbBig.isMouseOver(window)){
                    pcbBig.setBackColor(sf::Color::White);
                }else if(pcbMed.isMouseOver(window)){
                    pcbMed.setBackColor(sf::Color::White);
                }else if(pcbSmall.isMouseOver(window)){
                    pcbSmall.setBackColor(sf::Color::White);
                }else{
                    btn.setBackColor(sf::Color::Green);
                    btn1.setBackColor(sf::Color::Green);
                    btn2.setBackColor(sf::Color::Green);
                    btn3.setBackColor(sf::Color::Green);
                    pcbBig.setBackColor(sf::Color::Red);
                    pcbMed.setBackColor(sf::Color::Green);
                    pcbSmall.setBackColor(sf::Color::Blue);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if(btn.isMouseOver(window)){
                    diode* simpleDiode = DiodeFactory::createDiode(D_DIODE, "SMD-123");
                    std::cout << *simpleDiode << std::endl;
                }else if(btn1.isMouseOver(window)){
                    diode* simpleDiode = DiodeFactory::createDiode(D_LED, "SMD-123");
                    std::cout << *simpleDiode << std::endl;
                }else if(btn2.isMouseOver(window)){
                    diode* simpleDiode = DiodeFactory::createDiode(D_ZENER, "SMD-123");
                    std::cout << *simpleDiode << std::endl;
                    mousebut = true;


                }else if(btn3.isMouseOver(window)){
                    power_in<double> usb2 ("usb_c", 5, 1.2);
                    usb2.port_select();

                }else if(pcbBig.isMouseOver(window)){
                    sizepcb = "30x30";
                    LargePCB largePCBStrategy;
                    factory.setPCBStrategy(&largePCBStrategy);
                    factory.manufacture(sizepcb, "Red");

                }else if(pcbMed.isMouseOver(window)){
                    sizepcb = "20x20";
                    MediumPCB mediumPCBStrategy;
                    factory.setPCBStrategy(&mediumPCBStrategy);
                    factory.manufacture(sizepcb, "Green");

                }else if(pcbSmall.isMouseOver(window)){
                    sizepcb = "10x10";
                    SmallPCB smallPCBStrategy;
                    factory.setPCBStrategy(&smallPCBStrategy);
                    factory.manufacture(sizepcb, "Blue");

                }else if(mousebut == 1){
                    int xpos = sf::Mouse::getPosition(window).x;
                    int ypos = sf::Mouse::getPosition(window).y;
                    mousebut = false;
                    zerner_ent.setPosition({static_cast<float>(xpos), static_cast<float>(ypos)});

                }

                case sf::Event::Resized:
                    break;
                case sf::Event::LostFocus:
                    break;
                case sf::Event::GainedFocus:
                    break;
                case sf::Event::TextEntered:
                    break;
                case sf::Event::KeyPressed:
                    break;
                case sf::Event::KeyReleased:
                    break;
                case sf::Event::MouseWheelMoved:
                    break;
                case sf::Event::MouseWheelScrolled:
                    break;
                case sf::Event::MouseButtonReleased:
                    break;
                case sf::Event::MouseEntered:
                    break;
                case sf::Event::MouseLeft:
                    break;
                case sf::Event::JoystickButtonPressed:
                    break;
                case sf::Event::JoystickButtonReleased:
                    break;
                case sf::Event::JoystickMoved:
                    break;
                case sf::Event::JoystickConnected:
                    break;
                case sf::Event::JoystickDisconnected:
                    break;
                case sf::Event::TouchBegan:
                    break;
                case sf::Event::TouchMoved:
                    break;
                case sf::Event::TouchEnded:
                    break;
                case sf::Event::SensorChanged:
                    break;
                case sf::Event::Count:
                    break;
            }
        if(mousebut == 1){
            zerner_ent.setPosition({static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)});
        }





        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
         //window.draw(shape);
         btn.drawTo(window);
         btn1.drawTo(window);
        btn2.drawTo(window);
        btn3.drawTo(window);
        pcbBig.drawTo(window);
        pcbMed.drawTo(window);
        pcbSmall.drawTo(window);
        if(sizepcb == "30x30"){
            window.draw(pcbBigBoard);
        }else if(sizepcb == "20x20"){
            window.draw(pcbMedBoard);
        }else if(sizepcb == "10x10"){
            window.draw(pcbSmallBoard);

        }
        window.draw(zerner_ent);


        // end the current frame
        window.display();
    }
}