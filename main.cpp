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

double calculatorPlus(double, double, double); //Quadratic calculator
double calculatorMinus(double, double, double); //Quadratic calculator
double calculateY(double, double, double, double); //Used to calculate the y coordinate for graphing
sf::VertexArray setPoints(const array<double, 5>&, const array<double, 5>&, const array<double, 5>&, const array<double, 5>&, const array<double, 5>&, int);
sf::VertexArray setPoints(int); //Sets up vertex arrays to graph (This one's for the grid)
bool readFile(string, array<double, 5>&, array<double, 5>&, array<double, 5>&, array<double, 5>&, array<double, 5>&);



int main() {
    array<double, 5> a_array = {0, 0, 0, 0, 0};
    array<double, 5> b_array = {0, 0, 0, 0, 0};
    array<double, 5> c_array = {0, 0, 0, 0, 0};
    array<double, 5> b_domain_array = {0, 0, 0, 0, 0};
    array<double, 5> e_domain_array = {0, 0, 0, 0, 0};
    string filename("");

    if (!readFile(filename, a_array, b_array, c_array, b_domain_array, e_domain_array))
    {
        system("pause");
        return 1;
    }



    sf::VertexArray equation1 = setPoints(a_array, b_array, c_array, b_domain_array, e_domain_array, 0);
    sf::VertexArray equation2 = setPoints(a_array, b_array, c_array, b_domain_array, e_domain_array, 1);
    sf::VertexArray equation3 = setPoints(a_array, b_array, c_array, b_domain_array, e_domain_array, 2);
    sf::VertexArray equation4 = setPoints(a_array, b_array, c_array, b_domain_array, e_domain_array, 3);
    sf::VertexArray equation5 = setPoints(a_array, b_array, c_array, b_domain_array, e_domain_array, 4);

    sf::VertexArray graph = setPoints(0);
    sf::VertexArray graphlinesX = setPoints(1);
    sf::VertexArray graphlinesX2 = setPoints(2);
    sf::VertexArray graphlinesY = setPoints(3);
    sf::VertexArray graphlinesY2 = setPoints(4);
    sf::RenderWindow window(sf::VideoMode(300, 300), "Quadratic Calculator");
    run(window, equation1, equation2, equation3, equation4, equation5, graph, graphlinesX, graphlinesX2, graphlinesY, graphlinesY2);
    return 0;
}

//The main window loop
//Takes the window object and vertex arrays of the equations and graph to create the window and render the graph and equations
void run(sf::RenderWindow& mWindow, const sf::VertexArray& equation1, const sf::VertexArray& equation2, const sf::VertexArray& equation3, const sf::VertexArray& equation4, const sf::VertexArray& equation5, const sf::VertexArray& graph, const sf::VertexArray& graphlinesX, const sf::VertexArray& graphlinesX2, const sf::VertexArray& graphlinesY, const sf::VertexArray& graphlinesY2)
{
    sf::Event event; //Event object to handle things such as keyboard input and window closing
    sf::View view = mWindow.getDefaultView(); //The view that gets zoomed in and out
    mWindow.setKeyRepeatEnabled(false); //Set so the user has to press the key to zoom in/out repeatedly and can't hold it down
    while (mWindow.isOpen()) //Window loop
    {
        while (mWindow.pollEvent(event)) //Event handling
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Up)
                    view.zoom(1.5);    //zoom in
                else if (event.key.code == sf::Keyboard::Down)
                    view.zoom(0.5);    //zoom out
            }
            }
        }
        //Rendering
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

//Debug function to see if the grid even renders. Grid rendering was done first before even trying to graph equations
//Comments from the above function apply here
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

//Quadratic formula
double calculatorPlus(double a, double b, double c)
{
      double total;

      total = (-b + sqrt((pow(b,2)) - (4 * a * c))) / (2*a);

      return total;
}

//Quadratic formula
double calculatorMinus(double a, double b, double c)
{
      double total;

      total = (-b - sqrt((pow(b,2)) - (4 * a * c))) / (2*a);

      return total;
}

//Calculates the y cordinate for the graphing
double calculateY(double a, double b, double c, double x)
{
    return -((a * pow(x, 2)) + (b*x)+ c);
}

//Creates the grid then returns the vertex array
//The integers representing the type of vertex array refer to grid creation
//0 is the initial cross of the grid
//1 and 2 are the small lines on the x axis to serve as units
//3 and 4 are the small lines on the y axis to serve as uits
sf::VertexArray setPoints(int type) //0 is the red graph lines, 1 is linesx, 2 is linesx2, 3 is linesy, 4 is linesy2
{
    double x = 0, y = 0;
    switch(type)
    {
    case 0:
    {
        sf::VertexArray graph(sf::Lines, 4);
        //These position values set the location of the cross
        graph[0].position = sf::Vector2f(0, 150);
        graph[1].position = sf::Vector2f(300, 150);
        graph[2].position = sf::Vector2f(150, 0);
        graph[3].position = sf::Vector2f(150, 300);
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
            y = static_cast<double>(counterX) + 1;
            //This loop is resposible for setting correct x cordinates for the lines on the x axis
            //I used a loop to automate setting the x cordinates because theres no way I'm going to manually map out 300 x values
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
        //Same as above. Used a loop to set the cordinates for the lines for the x axis
        sf::VertexArray graphlinesX2(sf::Lines, 301);
        for (int counterX = 0; counterX < 301; counterX++)
        {
            y = static_cast<double>(counterX);
            if (counterX == 150)
            {
                graphlinesX2[counterX].color = sf::Color::Red; //this is so the lines don't replace the red cross set
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
        //Sets the y coordinates for the lines on the y axis
        //Once again using a loop to automate mapping 300 y coordinates
        sf::VertexArray graphlinesY(sf::Lines, 301);
        for (int counterY = 0; counterY < 301; counterY++)
        {
            x = static_cast<double>(counterY) + 1;

            if (counterY % 2 == 0)
                y = 149.0f;
            else
            {
                x--;
                y = 151.0f;
            }


            graphlinesY[counterY].position = sf::Vector2f(x, y);
            graphlinesY[counterY].color = sf::Color::Black;

        }
        return graphlinesY;
        break;
    }
    case 4:
    {
        //Same as above
        sf::VertexArray graphlinesY2(sf::Lines, 301);
        for (int counterY = 0; counterY < 301; counterY++)
        {
            x = static_cast<double>(counterY);
            if (counterY == 150)
            {
                graphlinesY2[counterY].color = sf::Color::Red; //same as earlier don't want the red lines to become black
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

//Responsible for creating the equation graphs
//Count variable is used as an index for the arrays
//Function takes the numbers from the arrays to graph
//Range is used to determine how many points should be plotted on the graphs
sf::VertexArray setPoints(const array<double, 5>& a_array, const array<double, 5>& b_array, const array<double, 5>& c_array, const array<double, 5>& b_domain_array, const array<double, 5>& e_domain_array, int count)
{
    double a = 0, b = 0, c = 0;
    double start_x = 0.0f;
    double end_x = 0.0f;
    double domain = 0.0f;
    start_x = b_domain_array[count];
    end_x = e_domain_array[count];
    domain = abs(end_x-start_x);
    sf::VertexArray points(sf::LineStrip, (domain*10)+1);
    a = a_array[count];
    b = b_array[count];
    c = c_array[count];
    switch (count)
    {
    case 0:
    {
        for (double counter = 0; counter <= (domain*10); counter++)    //I multiplied the amount of plotted points by 10 to increase accuracy on the graphs
        {
            double x = 0, y = 0;
            x = static_cast<double>(start_x + (counter/10));
            y = calculateY(a, b, c, x);
            points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
            points[counter].color = sf::Color::Black;
        }
        return points;
        break;
    }
    case 1:
    {
        for (double counter = 0; counter <= (domain*10); counter++)
        {
            double x = 0, y = 0;
            x = static_cast<double>(start_x + (counter/10));
            y = calculateY(a, b, c, x);
            points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
            points[counter].color = sf::Color::Red;
        }
        return points;
        break;
    }
    case 2:
    {
        for (double counter = 0; counter <= (domain*10); counter++)
        {
            double x = 0, y = 0;
            x = static_cast<double>(start_x + (counter/10));
            y = calculateY(a, b, c, x);
            points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
            points[counter].color = sf::Color::Blue;
        }
        return points;
        break;
    }
    case 3:
    {
        for (double counter = 0; counter <= (domain*10); counter++)
        {
            double x = 0, y = 0;
            x = static_cast<double>(start_x + (counter/10));
            y = calculateY(a, b, c, x);
            points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
            points[counter].color = sf::Color::Green;
        }
        return points;
        break;
    }
    case 4:
    {
        for (double counter = 0; counter <= (domain*10); counter++)
        {
            double x = 0, y = 0;
            x = static_cast<double>(start_x + (counter/10));
            y = calculateY(a, b, c, x);
            points[counter].position = sf::Vector2f(x+150.0f, y+150.0f);
            points[counter].color = sf::Color::Magenta;
        }
        return points;
        break;
    }
    }

}
//Function for reading the file and format
//Is a bool function that returns true if a file is read, false if there is no file (which then promptly closes the program)
//Passes arrays by reference to directly add numbers from the equation into the array
//Takes a domain for purposes of graphing
bool readFile(string filename, array<double, 5>& a_array, array<double, 5>& b_array, array<double, 5>& c_array, array<double, 5>& b_domain_array, array<double, 5>& e_domain_array)
{
    ifstream inputFile;
    ofstream outputFile;
    string equation, temp; //string to store the equation, I think temp is a useless variable but i don't feel like changing it to find out
    int count = 0;

    string terms1, terms2, terms3, terms4, terms5, terms6, terms7, terms8; //Tbh terms 1 is the only variable that needs to be a string as it is used to check x^2
    //the rest could be chars but I'm too lazy to change it at this point
    double tempa, tempb, tempc, temp0, b_domain, e_domain; //Variables to dump into arrays, I think I could get rid of these but I'm pretty much done with this project at this point

    stringstream ss; //Stringstream to break down the equation string into terms to dump into the arrays and check for file format
    double a = 0;
    double b = 0;
    double c = 0;
    double solution1, solution2;

    cout << "Enter filename:";
    cin >> filename;
    inputFile.open(filename);
    outputFile.open("output.txt");
    if (!inputFile)
    {
        cout << "Error no file shutting down...\n";
        return false;
    }
    while(getline(inputFile, equation)) //While loop to read each line(equation)
    {
        if (count > 4) //Check in place so arrays don't go out of range
        {
            cout << "Not reading more than 5 equations...\n";
            break;
        }
        ss.str(string());
        ss.clear();
        cout << equation << endl;
        outputFile << equation << endl;
        ss << equation;


        while (ss) { //Loops through the stringstream to break it down into seperate terms to put into variables, also serves as file format checking
            //the continues are there to skip the equation (break might work better but two lazy to change now)
            ss >> tempa >> terms1 >> terms2 >> tempb >> terms3 >> terms4 >> tempc >> terms5 >> temp0 >> terms6 >> b_domain >> terms7 >> e_domain >> terms8;

            if (terms2 != "+" && terms2 != "-")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms4 != "+" && terms4 != "-")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms5 != "=")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms1 != "x^2")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms3 != "x")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (temp0 != 0)
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms6 != "(")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms7 != ",")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            if (terms8 != ")")
            {
                cout << "Error! Refusing to read equation due to incorrect format...\n";
                outputFile << "Error! Refusing to read equation due to incorrect format...\n";
                continue;
            }
            //Terms are used here to convert numbers to negative if needed say example: - 5x would convert the pos 5 to a negative
            if (terms2 == "-")
            {
                //cout << "Converting b to negative b\n";
                b = -tempb;
            }
            if (terms2 == "+")
            {
                //cout << "Converting b to pos b\n";
                b = tempb;
            }
            if (terms4 == "-")
            {
                //cout << "Converting c to negative c\n";
                c = -tempc;
            }
            if (terms4 == "+")
            {
                //cout << "Converting c to pos c\n";
                c = tempc;
            }
            //Dumps the variables into the array for graphing
            a = tempa;


            a_array[count] = a;
            b_array[count] = b;
            c_array[count] = c;
            b_domain_array[count] = b_domain;
            e_domain_array[count] = e_domain;

        }

        //Outputs the equation and solutions into the console and writes onto an output file as well
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

        outputFile << "Numbers\n";
        outputFile << "a: " << a << endl;
        outputFile << "b: " << b << endl;
        outputFile << "c: " << c << endl;
        outputFile << "Solutions\n";
        outputFile << "x: " << solution1 << endl;
        outputFile << "x: " << solution2 << endl;
        outputFile << endl;
        count++;

    }


    inputFile.close();
    return true;


}




