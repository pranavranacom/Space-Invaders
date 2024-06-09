#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // Game loop to keep the window open
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Cyan);

        // Draw your content here...
        /* A Green circle */
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(10, 10); // Set position
        window->draw(circle);

        // A Red square
        sf::RectangleShape square(sf::Vector2f(100, 100)); // 100x100 pixels
        square.setPosition(150, 10); // Center of the window (approximately)
        square.setFillColor(sf::Color::Red);
        window->draw(square);

        // A Blue Triangle
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        //// points are set as a pendulum: top to bottom left to right
        triangle.setPoint(0, sf::Vector2f(0, 100));
        triangle.setPoint(1, sf::Vector2f(50, 0));
        triangle.setPoint(2, sf::Vector2f(100, 100));
        triangle.setFillColor(sf::Color::Blue);
        triangle.setPosition(300, 10); // Position the origin of the triangle at (400, 300)
        window->draw(triangle);

        // Display what was drawn
        window->display();
    }

    return 0;
}