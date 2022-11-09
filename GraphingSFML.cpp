#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;
int main()
{
	float points_counter = 21.0f;
	sf::RenderWindow window(sf::VideoMode(300, 300), "Quadratic Calculator");
	sf::View view = window.getDefaultView();
	sf::VertexArray points(sf::LinesStrip, points_counter);
	sf::VertexArray graph(sf::Lines, 4);
	sf::VertexArray graphlinesX(sf::Lines, 301);
	sf::VertexArray graphlinesX2(sf::Lines, 301);
	sf::VertexArray graphlinesY(sf::Lines, 301);
	sf::VertexArray graphlinesY2(sf::Lines, 301);
	float x = 0;
	float y = 0;
	float a = 1;
	float b = 0;
	float c = 0;

	graph[0].position = sf::Vector2f(0, 150); //-600, 150 //These are the cordinates for stuff that can be zoomed out
	graph[1].position = sf::Vector2f(300, 150); //900, 150
	graph[2].position = sf::Vector2f(150, 0); //150, -600
	graph[3].position = sf::Vector2f(150, 300); //150, 900
	graph[0].color = sf::Color::Red;
	graph[1].color = sf::Color::Red;
	graph[2].color = sf::Color::Red;
	graph[3].color = sf::Color::Red;

	/*
	graphlinesY[0].position = sf::Vector2f(151.0f, 0.0f);
	graphlinesY[0].color = sf::Color::Black;
	graphlinesY[1].position = sf::Vector2f(151.0f, 300.0f);
	graphlinesY[1].color = sf::Color::Black;
	*/

	cout << "input points:";
	//cin >> points_counter;

    window.setKeyRepeatEnabled(false);

    cout << "Input a, b, and c" << std::endl;
    //cin >> a >> b >> c;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
            	if (event.key.code == sf::Keyboard::Up)
            		view.zoom(1.5);
            	else if (event.key.code == sf::Keyboard::Down)
            		view.zoom(0.5);
            }
        }


        for (int counterY = 0; counterY < 301; counterY++)
        {
        	x = static_cast<float>(counterY) + 1;
        	//if (counterY == 150) continue;
        	if (counterY % 2 == 0)
        		y = 149.0f; //0.0f is the grid format
        	else
        	{
        		x--;
        		y = 151.0f; //300.0f is the grid format
        	}


        	graphlinesY[counterY].position = sf::Vector2f(x, y);
        	graphlinesY[counterY].color = sf::Color::Black;

        }

        for (int counterY = 0; counterY < 301; counterY++)
        {
        	x = static_cast<float>(counterY);
        	if (counterY == 150)
        	{
        		graphlinesX2[counterY].color = sf::Color::Red;
        	}
        	else if (counterY % 2 == 0)
        		y = 149.0f;
        	else
        	{
        		x--;
        		y = 151.0f;
        	}


        	graphlinesY2[counterY].position = sf::Vector2f(x, y);
        	graphlinesY2[counterY].color = sf::Color::Black;

        }


        for (int counterX = 0; counterX < 301; counterX++)
        {
        	y = static_cast<float>(counterX) + 1;
        	//if (counterX == 150) continue;
        	if (counterX % 2 == 0)
        		x = 149.0f;
        	else
        	{
        		y--;
        		x = 151.0f;
        	}


        	graphlinesX[counterX].position = sf::Vector2f(x, y);
        	graphlinesX[counterX].color = sf::Color::Black;

        }

        for (int counterX = 0; counterX < 301; counterX++)
        {
        	y = static_cast<float>(counterX);
        	if (counterX == 150)
        	{
        		graphlinesX2[counterX].color = sf::Color::Red;
        	}
        	else if (counterX % 2 == 0)
        		x = 149.0f;
        	else
        	{
        		y--;
        		x = 151.0f;
        	}


        	graphlinesX2[counterX].position = sf::Vector2f(x, y);
        	graphlinesX2[counterX].color = sf::Color::Black;

        }

        for (int counter = 0; counter < points_counter; counter++)
        {
        	x = static_cast<float>(counter) - ((points_counter-1)/2);
        	y = -(a * pow(x, 2)) + (b*x)+ c;
        	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
        	points[counter].color = sf::Color::Black;
        }

        window.setView(view);
        window.clear(sf::Color::White);
        window.draw(graph);
        window.draw(points);
        window.draw(graphlinesX);
        window.draw(graphlinesX2);
        window.draw(graphlinesY);
        window.draw(graphlinesY2);
        window.display();
    }
    return 0;
}
