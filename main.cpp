#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;

//Function prototypes
void run(sf::RenderWindow&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&); //Window handling and rendering stuff onto the window
//this run function below is an overloaded debug function to see if the grid even renders
void run(sf::RenderWindow&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&);

double calculatorPlus(int, int, int); //Quadratic calculator
double calculatorMinus(int, int, int); //Quadratic calculator
double calculateY(int, int, int, int); //Used to calculate the y coordinate for graphing
sf::VertexArray setPoints(int); //Sets up vertex arrays to graph (This one's for the grid)
array<int, 5> getInputs(string); //Function to get numbers for a, b, and c

int main() {
	sf::VertexArray graph = setPoints(1);
	sf::VertexArray graphlinesX = setPoints(2);
	sf::VertexArray graphlinesX2 = setPoints(3);
	sf::VertexArray graphlinesY = setPoints(4);
	sf::VertexArray graphlinesY2 = setPoints(5);
	sf::RenderWindow window(sf::VideoMode(300, 300), "Quadratic Calculator");
	run(window, graph, graphlinesX, graphlinesX2, graphlinesY, graphlinesY2);
	return 0;
}

void run(sf::RenderWindow& mWindow, const sf::VertexArray& graph, const sf::VertexArray& points, const sf::VertexArray& graphlinesX, const sf::VertexArray& graphlinesX2, const sf::VertexArray& graphlinesY, const sf::VertexArray& graphlinesY2)
{
	sf::Event event;
	sf::View view = mWindow.getDefaultView();
	mWindow.setKeyRepeatEnabled(false);
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
		mWindow.draw(graph);
		mWindow.draw(graphlinesX);
		mWindow.draw(graphlinesX2);
		mWindow.draw(graphlinesY);
		mWindow.draw(graphlinesY2);
		mWindow.display();
	}
}

void run(sf::RenderWindow& mWindow, const sf::VertexArray& graph, const sf::VertexArray& graphlinesX, const sf::VertexArray& graphlinesX2, const sf::VertexArray& graphlinesY, const sf::VertexArray& graphlinesY2)
{
	sf::Event event;
	sf::View view = mWindow.getDefaultView();
	mWindow.setKeyRepeatEnabled(false);
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
		mWindow.draw(graph);
		mWindow.draw(graphlinesX);
		mWindow.draw(graphlinesX2);
		mWindow.draw(graphlinesY);
		mWindow.draw(graphlinesY2);
		mWindow.display();
	}
}

double calculatorPlus(int a, int b, int c)
{
	  double total;

	  total = ((-b + (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
	  cout << "x = " << total << endl;
	  return total;
}

double calculatorMinus(int a, int b, int c)
{
	  double total;

	  total = ((-b - (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
	  cout << "x = " << total << endl;
	  return total;
}

double calculateY(int a, int b, int c, int x)
{
	return -(a * pow(x, 2)) + (b*x)+ c;
}

sf::VertexArray setPoints(int type) //0 is the quadratic equation, 1 is the red graph lines, 2 is linesx, 3 is linesx2, 4 is linesy, 5 is linesy2
{
	double x = 0, y = 0;
	switch(type)
	{
	case 0:
	{
		/*
		sf::VertexArray points(sf::LinesStrip, 21.0f);
        for (int counter = 0; counter < 21; counter++)
        {
        	x = static_cast<float>(counter) - ((21-1)/2);
        	y = -(a * pow(x, 2)) + (b*x)+ c;
        	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
        	points[counter].color = sf::Color::Black;
        }

		*/
		break;
	}
	case 1:
	{
		sf::VertexArray graph(sf::Lines, 4);
		graph[0].position = sf::Vector2f(0, 150); //-600, 150 //These are the cordinates for stuff that can be zoomed out
		graph[1].position = sf::Vector2f(300, 150); //900, 150
		graph[2].position = sf::Vector2f(150, 0); //150, -600
		graph[3].position = sf::Vector2f(150, 300); //150, 900
		graph[0].color = sf::Color::Red;
		graph[1].color = sf::Color::Red;
		graph[2].color = sf::Color::Red;
		graph[3].color = sf::Color::Red;
		return graph;
		break;
	}

	case 2:
	{
		sf::VertexArray graphlinesX(sf::Lines, 301);
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
        return graphlinesX;
		break;
	}
	case 3:
	{
		sf::VertexArray graphlinesX2(sf::Lines, 301);
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
        return graphlinesX2;
        break;
	}
	case 4:
	{
		sf::VertexArray graphlinesY(sf::Lines, 301);
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
        return graphlinesY;
        break;
	}
	case 5:
	{
		sf::VertexArray graphlinesY2(sf::Lines, 301);
        for (int counterY = 0; counterY < 301; counterY++)
        {
        	x = static_cast<float>(counterY);
        	if (counterY == 150)
        	{
        		graphlinesY2[counterY].color = sf::Color::Red;
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
        return graphlinesY2;
        break;
	}
	}
}

