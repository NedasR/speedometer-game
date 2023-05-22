#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#define CirCle_size 120
#define CENTER 400
#define pi 3.14159
#define text_size 16
#define blockerbox 240

int main()
{
    float energy=0, speednum=0;
    bool spaceP = false;
    float speed = 0;
    float Urot = 0;
    float U2rot = 0;

    sf::RenderWindow window(sf::VideoMode(800, 800), "speedometer game");
    window.setFramerateLimit(60);
    sf::CircleShape Circle(CirCle_size);
    Circle.setPosition(CENTER, CENTER);
    Circle.setFillColor(sf::Color::Color(255, 165, 0));
    Circle.setOrigin(CirCle_size, CirCle_size);
    sf::RectangleShape line(sf::Vector2f((CirCle_size-20), 3));
    sf::CircleShape midcir(6);
    midcir.setPosition(CENTER, CENTER);
    midcir.setOrigin(6, 6);
    line.setPosition(sf::Vector2f(CENTER,CENTER));
    line.setOrigin(sf::Vector2f((CirCle_size-20), 2));
    line.setRotation(180);
    sf::RectangleShape Uline(sf::Vector2f(-15, 3));
    Uline.setPosition(sf::Vector2f(CENTER, CENTER));
    Uline.setOrigin(sf::Vector2f((CirCle_size - 20), 2));
    sf::RectangleShape U2line(sf::Vector2f(-8, 3));
    U2line.setPosition(sf::Vector2f(CENTER, CENTER));
    U2line.setOrigin(sf::Vector2f((CirCle_size - 17), 2));
    sf::RectangleShape blackbox(sf::Vector2f(blockerbox, blockerbox));
    blackbox.setOrigin(blockerbox/2, 0);
    blackbox.setPosition(CENTER, CENTER+4);
    blackbox.setFillColor(sf::Color::Black);
    sf::Text text,num2,num3, num4,num5;
    sf::Font myfont;
    myfont.loadFromFile("Arial.ttf");
    num2.setCharacterSize(text_size);
    num3.setCharacterSize(text_size);
    num4.setCharacterSize(text_size);
    num5.setCharacterSize(text_size);
    text.setCharacterSize(text_size);
    text.setString("0                                       180");
    num2.setString("20                                  160");
    num3.setString("40                          140");
    num4.setString("60              120");
    num5.setString("80  100");
    text.setFont(myfont);
    num2.setFont(myfont);
    num3.setFont(myfont);
    num4.setFont(myfont);
    num5.setFont(myfont);
    text.setPosition(306,382);
    num2.setPosition(310, 354);
    num3.setPosition(326, 328);
    num4.setPosition(352, 312);
    num5.setPosition(374, 300);

    if (!myfont.loadFromFile("Arial.ttf")) {
        std::cout << "failed to load font";
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == event.Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                spaceP = true;
            }
            else {
                spaceP = false;
            }
       
        }
        if (speed < 10) {
            speednum = 10.0f;
        }
        else if (speed > 90) {
            speednum = 6.0f;
        }
        


        if (spaceP) {
            energy += speednum;
        } else if (energy > 0) {
            
            energy -= 0.80f;
        }
        
        speed = sqrtf(energy);
        line.setRotation(speed);

            if (speed >= 180) {
                speed = 180;
            }
            else if (speed < 0) {
                speed = 0; 
            }
        window.clear();
        window.draw(Circle);
        window.draw(line);
        while (Urot <= 180) {
            Uline.setRotation(Urot);
            window.draw(Uline);
            Urot += 20;
        }
        if (Urot >= 180) {
            Urot = 0;
        }
        while (U2rot <= 178) {
            U2line.setRotation(U2rot);
            window.draw(U2line);
            U2rot += 4;
        }
        if (U2rot >= 178) {
            U2rot = 0;
        }
        window.draw(text);
        window.draw(num2);
        window.draw(num3);
        window.draw(num4);
        window.draw(num5);
        window.draw(midcir);
        window.draw(blackbox);
        window.display();
        
    }

    return 0;
}


// bool hello;
// game loop {
//   
//   input -> set hello to something;
//   game logic / physics -> i can move the sprite according to hello
//   rendering -> render no
