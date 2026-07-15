//
// SFML 3 Test By AHD  1405.04.08
//

#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Text.hpp>
#include <iostream>

#include "delay.h"

using namespace std;

unsigned int window_x = 1200, window_y = 700;
int x = 0;
float_t dx1 = 0.0;
float_t dx2 = 0.0;
int8_t shap_speed = 5;
int8_t shap3_move_direction_tag_x = shap_speed, shap3_move_direction_tag_y = shap_speed;
int8_t shap4_move_direction_tag_x = shap_speed, shap4_move_direction_tag_y = shap_speed;

const sf::Font font("C:\\Windows\\Fonts\\arial.ttf");


void cross_detector(){
    cout << "Crossing Now ........................" << "\n";
}


int main()
{

    sf::RenderWindow window(sf::VideoMode({window_x, window_y}), "MySFML 3.1 Test");
    window.setFramerateLimit(60);

    sf::RectangleShape shap1({200, 2});
    shap1.setFillColor(sf::Color::Green);
    shap1.setPosition({400, 350});
    shap1.setRotation(sf::degrees(dx1));

    sf::RectangleShape shap2({200, 2});
    shap2.setFillColor(sf::Color::Red);
    shap2.setPosition({800, 350});
    shap2.setRotation(sf::degrees(dx2));  
    
    sf::CircleShape shap3({25});
    shap3.setFillColor(sf::Color::Red);
    shap3.setPosition({10.0,10.0});

    sf::CircleShape shap4({35});
    shap3.setFillColor(sf::Color::Blue);
    shap3.setPosition({900.0,600.0});    

    sf::Text text(font, "Hi AHD");
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition({200,300});
    

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                    window.close();
            }
        }


        dx1++;dx1++;
        dx2++;dx2++;dx2++;dx2++;dx2++;dx2++;

        sf::Vector2f shap1_pos_center = shap1.getPosition();
        sf::Vector2f shap2_pos_center = shap2.getPosition();
        sf::Vector2f shap3_pos_center = shap3.getPosition();   
        sf::Vector2f shap4_pos_center = shap4.getPosition();   

        sf::FloatRect shap1_pos_bound = shap1.getLocalBounds();  
        sf::FloatRect shap2_pos_bound = shap2.getLocalBounds();
        sf::FloatRect shap3_pos_bound = shap3.getLocalBounds();
        sf::FloatRect shap4_pos_bound = shap4.getLocalBounds();        


        if(shap3_pos_center.x < 0 || shap3_pos_center.x + shap3_pos_bound.size.x > window_x ){
            shap3_move_direction_tag_x = - shap3_move_direction_tag_x;
        }
        if(shap3_pos_center.y < 0 || shap3_pos_center.y + shap3_pos_bound.size.y > window_y){
            shap3_move_direction_tag_y = - shap3_move_direction_tag_y;
        }

        if(shap4_pos_center.x < 0 || shap4_pos_center.x + shap4_pos_bound.size.x > window_x ){
            shap4_move_direction_tag_x = - shap4_move_direction_tag_x;
        }
        if(shap4_pos_center.y < 0 || shap4_pos_center.y + shap4_pos_bound.size.y > window_y){
            shap4_move_direction_tag_y = - shap4_move_direction_tag_y;
        }        

        if(shap3_pos_center.x == shap1_pos_center.x || shap3_pos_center == shap2_pos_center) cross_detector();
        if(shap4_pos_center.x == shap1_pos_center.x || shap4_pos_center == shap2_pos_center) cross_detector();        


        shap1.setRotation(sf::degrees(dx1));
        shap2.setRotation(sf::degrees(dx2));

        shap3.move(sf::Vector2f(shap3_move_direction_tag_x, shap3_move_direction_tag_y));   
        shap4.move(sf::Vector2f(shap4_move_direction_tag_x, shap4_move_direction_tag_y));         
        
        window.clear(sf::Color::Black);
        window.draw(shap1);
        window.draw(shap2);
        window.draw(shap3);
        window.draw(shap4);
        window.draw(text);
        window.display();


    } 

    return 0;

}
