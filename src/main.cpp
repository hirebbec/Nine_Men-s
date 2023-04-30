#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML and OpenGL");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, 0, 1);
    glMatrixMode(GL_MODELVIEW);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(100, 100);
        glColor3f(0, 1, 0);
        glVertex2f(300, 100);
        glColor3f(0, 0, 1);
        glVertex2f(200, 300);
        glEnd();

        window.display();
    }

    return 0;
}

