#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;

//Function prototypes
void run(sf::RenderWindow&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&); //Window handling and rendering stuff onto the window
int calculatorPlus(int, int, int); //Quadratic calculator
int calculatorMinus(int, int, int); //Quadratic calculator
double calculateY(int, int, int, int); //Used to calculate the y coordinate for graphing
sf::VertexArray setPoints(sf::PrimitiveType, int); //Sets up vertex arrays to graph (This one's for the grid)
array<int, 5> getInputs(string); //Function to get numbers for a, b, and c

int main() {
	cout << "Does this work?" << endl; // prints Does this work?
	return 0;
}

void run(sf::RenderWindow& mWindow, const sf::VertexArray& graph, const sf::VertexArray& points, const sf::VertexArray& graphlinesX, const sf::VertexArray& graphlinesX2, const sf::VertexArray& graphlinesY, const sf::VertexArray& graphlinesY2)
{
	sf::Event event;
	sf::View view = mWindow.getDefaultView();
	while (mWindow.isOpen())
	{
		while (mWindow.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				mWindow.close();
				break;
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Up)
					view.zoom(1.5);
				else if (event.key.code == sf::Keyboard::Down)
					view.zoom(0.5);
			}
			}
		}
		mWindow.setView(view);
		mWindow.clear(sf::Color::White);
		mWindow.draw(points);
		mWindow.draw(graphlinesX);
		mWindow.draw(graphlinesX2);
		mWindow.draw(graphlinesY);
		mWindow.draw(graphlinesY2);
		mWindow.display();
	}
}

int calculatorPlus(int a, int b, int c)
{
	  double total;

	  total = ((-b + (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
	  cout << "x = " << total << endl;
	  return total;
}

double calculateY(int a, int b, int c, int x)
{
	return -(a * pow(x, 2)) + (b*x)+ c;;
}


