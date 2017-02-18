#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "include/test.hpp"

using namespace std;

int main()
{
    /*
    sf::TcpSocket socket;
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("snd_test.wav")) return -1;
    sf::Sound snd;
    snd.setBuffer(buffer);
    snd.setPitch(1.5);
    snd.play();
    */
    int a = add(5, 10);
    cout << "a: " << a << endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); //
        window.draw(shape);
        window.display();
    }

    return 0;
}
