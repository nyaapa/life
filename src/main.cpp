#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "include/test.hpp"
#include <thread>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    Field<50, 50> field{window.getSize()};

    field.at(1,1) = true;
    field.at(1,2) = true;
    field.at(1,3) = true;


    field.at(10,5) = true;
    field.at(11,5) = true;
    field.at(12,5) = true;
    field.at(12,4) = true;
    field.at(11,3) = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //
            if (event.type == sf::Event::Closed)
                window.close();
        }
        field.step();
        window.clear(); //
        field.draw(window);
        window.display();
        std::this_thread::sleep_for(350ms);
    }

    return 0;
}
