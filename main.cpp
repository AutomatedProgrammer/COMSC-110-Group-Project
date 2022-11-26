#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

//Function prototypes
void run(sf::RenderWindow&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&); //Window handling and rendering stuff onto the window
//this run function below is an overloaded debug function to see if the grid even renders
void run(sf::RenderWindow&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&, const sf::VertexArray&);

double calculatorPlus(int, int, int); //Quadratic calculator
double calculatorMinus(int, int, int); //Quadratic calculator
double calculateY(int, int, int, int); //Used to calculate the y coordinate for graphing
sf::VertexArray setPoints(const array<int, 5>&, const array<int, 5>&, const array<int, 5>&, int);
sf::VertexArray setPoints(int); //Sets up vertex arrays to graph (This one's for the grid)
bool readFile(string, array<int, 5>&, array<int, 5>&, array<int, 5>&);



int main() {
	array<int, 5> a_array = {0, 0, 0, 0, 0};
	array<int, 5> b_array = {0, 0, 0, 0, 0};
	array<int, 5> c_array = {0, 0, 0, 0, 0};
	string filename("");

	if (!readFile(filename, a_array, b_array, c_array))
		return 1;


	sf::VertexArray equation1 = setPoints(a_array, b_array, c_array, 0);
	sf::VertexArray equation2 = setPoints(a_array, b_array, c_array, 1);
	sf::VertexArray equation3 = setPoints(a_array, b_array, c_array, 2);
	sf::VertexArray equation4 = setPoints(a_array, b_array, c_array, 3);
	sf::VertexArray equation5 = setPoints(a_array, b_array, c_array, 4);

	sf::VertexArray graph = setPoints(0);
	sf::VertexArray graphlinesX = setPoints(1);
	sf::VertexArray graphlinesX2 = setPoints(2);
	sf::VertexArray graphlinesY = setPoints(3);
	sf::VertexArray graphlinesY2 = setPoints(4);
	sf::RenderWindow window(sf::VideoMode(300, 300), "Quadratic Calculator");
	run(window, equation1, equation2, equation3, equation4, equation5, graph, graphlinesX, graphlinesX2, graphlinesY, graphlinesY2);
	return 0;
}

void run(sf::RenderWindow& mWindow, const sf::VertexArray& equation1, const sf::VertexArray& equation2, const sf::VertexArray& equation3, const sf::VertexArray& equation4, const sf::VertexArray& equation5, const sf::VertexArray& graph, const sf::VertexArray& graphlinesX, const sf::VertexArray& graphlinesX2, const sf::VertexArray& graphlinesY, const sf::VertexArray& graphlinesY2)
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
		mWindow.draw(equation1);
		mWindow.draw(equation2);
		mWindow.draw(equation3);
		mWindow.draw(equation4);
		mWindow.draw(equation5);
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

	  total = (-b + sqrt((pow(b,2)) - (4 * a * c))) / (2*a);
	  cout << "x = " << total << endl;
	  return total;
}

double calculatorMinus(int a, int b, int c)
{
	  double total;

	  total = (-b - sqrt((pow(b,2)) - (4 * a * c))) / (2*a);
	  cout << "x = " << total << endl;
	  return total;
}

double calculateY(int a, int b, int c, int x)
{
	return -(a * pow(x, 2)) + (b*x)+ c;
}

sf::VertexArray setPoints(int type) //0 is the red graph lines, 1 is linesx, 2 is linesx2, 3 is linesy, 4 is linesy2
{
	double x = 0, y = 0;
	switch(type)
	{
	case 0:
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

	case 1:
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
	case 2:
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
	case 3:
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
	case 4:
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

sf::VertexArray setPoints(const array<int, 5>& a_array, const array<int, 5>& b_array, const array<int, 5>& c_array, int count)
{
	int a = 0, b = 0, c = 0;
	sf::VertexArray points(sf::LineStrip, 21.0f);
	a = a_array[count];
	b = b_array[count];
	c = c_array[count];
	switch (count)
	{
	case 0:
	{
	    for (int counter = 0; counter < 21; counter++)
	    {
	    	double x = 0, y = 0;
	    	x = static_cast<double>(counter) - ((21-1)/2);
	    	y = calculateY(a, b, c, x);
	    	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
	    	points[counter].color = sf::Color::Black;
	    }
	    return points;
		break;
	}
	case 1:
	{
	    for (int counter = 0; counter < 21; counter++)
	    {
	    	double x = 0, y = 0;
	    	x = static_cast<double>(counter) - ((21-1)/2);
	    	y = calculateY(a, b, c, x);
	    	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
	    	points[counter].color = sf::Color::Red;
	    }
	    return points;
		break;
	}
	case 2:
	{
	    for (int counter = 0; counter < 21; counter++)
	    {
	    	double x = 0, y = 0;
	    	x = static_cast<double>(counter) - ((21-1)/2);
	    	y = calculateY(a, b, c, x);
	    	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
	    	points[counter].color = sf::Color::Blue;
	    }
	    return points;
		break;
	}
	case 3:
	{
	    for (int counter = 0; counter < 21; counter++)
	    {
	    	double x = 0, y = 0;
	    	x = static_cast<double>(counter) - ((21-1)/2);
	    	y = calculateY(a, b, c, x);
	    	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
	    	points[counter].color = sf::Color::Green;
	    }
	    return points;
		break;
	}
	case 4:
	{
	    for (int counter = 0; counter < 21; counter++)
	    {
	    	double x = 0, y = 0;
	    	x = static_cast<double>(counter) - ((21-1)/2);
	    	y = calculateY(a, b, c, x);
	    	points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
	    	points[counter].color = sf::Color::Magenta;
	    }
	    return points;
		break;
	}
	}

}

bool readFile(string filename, array<int, 5>& a_array, array<int, 5>& b_array, array<int, 5>& c_array)
{
	ifstream inputFile;
	ofstream outputFile;
	string equation, temp;
	int count = 0;

	string terms1, terms2, terms3, terms4, terms5;
	int tempa, tempb, tempc, temp0;

	stringstream ss;
	int a = 0;
	int b = 0;
	int c = 0;
	double solution1, solution2;

	cout << "Enter filename:";
	cin >> filename;
	inputFile.open(filename);
	if (!inputFile)
	{
		cout << "Error no file shutting down...";
		return false;
	}
	while(getline(inputFile, equation))
	{
		ss.str(string());
		ss.clear();
		cout << equation << endl;
		ss << equation;


		while (ss) {

			ss >> tempa >> terms1 >> terms2 >> tempb >> terms3 >> terms4 >> tempc >> terms5 >> temp0;

			if (terms2 != "+" && terms2 != "-")
			{
				cout << "Error! Refusing to read equation due to incorrect format...\n";
				continue;
			}
			if (terms4 != "+" && terms4 != "-")
			{
				cout << "Error! Refusing to read equation due to incorrect format...\n";
				continue;
			}
			if (terms5 != "=")
			{
				cout << "Error! Refusing to read equation due to incorrect format...\n";
				continue;
			}
			if (terms1 != "x^2")
			{
				cout << "Error! Refusing to read equation due to incorrect format...\n";
				continue;
			}
			if (terms3 != "x")
			{
				cout << "Error! Refusing to read equation due to incorrect format...\n";
				continue;
			}
			if (temp0 != 0)
			{
				cout << "Error! Refusing to read equation due to incorrect format...\n";
				continue;
			}

			a = tempa;
			b = tempb;
			c = tempc;

			a_array[count] = a;
			b_array[count] = b;
			c_array[count] = c;


		}
		count++;
		solution1 = calculatorPlus(a,b,c);
		solution2 = calculatorMinus(a,b,c);
		cout << "Numbers\n";
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
		cout << "Solutions\n";
		cout << "x: " << solution1 << endl;
		cout << "x: " << solution2 << endl;
		cout << endl;

	}


	inputFile.close();
	return true;


}


