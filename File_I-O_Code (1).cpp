#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <array>

using namespace std;

int main() {
	ifstream inputFile; //standard input and output file reading components
	ofstream outputFile;
	string filename, equation, temp;
	stringstream ss;
	int number;
  int xVariables;
	int a = 0; //variables a-c, in accordance to count, will be used for the terms/elements of the equation when read
	int b = 0;
	int c = 0;
  int d = 0;
  string e = "x^2", f = "x";

	
  int count1 = 0; //count, used in the while loop for reading
  int count2 = 0;
	double solution1, solution2; //solutions 1 and 2

	array<int, 4> numbers; // array of 'numbers'
  array<int, 3> xVariables; // array of 'x-variables'

	cout << "Enter filename:"; /*usual reading and opening for the file */
	cin >> filename;
	inputFile.open(filename);
	if (!inputFile)
	{
		cout << "Error no file shutting down...";
		return 1;
	}

	//cout << "Equations" << endl;
	while(getline(inputFile, equation))
	{
		ss.str(string());
		ss.clear(); //numbers.clear();
		numbers.fill(0); // start with no numbers
		count1 = 0;
		cout << equation << endl;
		ss << equation;

    ss.str(string());
		ss.clear(); //numbers.clear();
		xVariables.fill(0); // start with no numbers
		count2 = 0;
		cout << equation << endl;
		ss << equation;

		while (!ss.eof()) {
			ss >> temp; //temp variable used as a feedback center or "middle man" in the sense and equation put into temp
			if (temp == "+" || temp == "=" || temp == "-") continue; // looks for operators in accordance to the temp and the continue keyword breaks up the while loop 
			stringstream(temp) >> number;
			numbers[count1] = number;
			if (count1 == 0) a = numbers[count1]; // If-statements 1-3 check for the numbers or elements of the equations, and assigns them to 'a', 'b', or 'c'
			if (count1 == 1) b = numbers[count1];
			if (count1 == 2) c = numbers[count1]; 
      if (count1 == 3) d = numbers[count1];    
			temp = " "; // "resets" the variables and restarts the process of analyzing the file
			count1++;
		}
    
    	while (!ss.eof()) {
			ss >> temp; //temp variable used as a feedback center or "middle man" in the sense and equation put into temp
			if (temp == "x^2" ||  temp == "x") continue; // looks for operators in accordance to the temp and the continue keyword breaks up the while loop 
			stringstream(temp) >> xVariable;
			xVariables[count2] = xVariable;
			if (count2 == 0) e = xVariables[count2]; // If-statements 1-3 check for the numbers or elements of the equations, and assigns them to 'a', 'b', or 'c'
      if (count2 == 1) f = xVariables[count2];
			temp = " "; // "resets" the variables and restarts the process of analyzing the file
			count1++;
		}

		solution1 = ((-b + (sqrt((pow(b,2)) - 4 * a * c))) / 2*a); // solutions 1 & 2 have the quadratic formulas for calculation
		solution2 = ((-b - (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
		cout << "Numbers\n";
		cout << "ax^2: " << a << endl; // for the following lines, numbers associated with the parameters of the code, are placed in a, b, or c
		cout << "bx: " << b << endl;
		cout << "c: " << c << endl;
		cout << "Solutions\n";
    cout << "e: " << e << endl;
    cout << "f: " << f << endl; 
		cout << "x: " << solution1 << endl;
		cout << "x: " << solution2 << endl;
		cout << endl; 



      for (int equation = 0; equation <= 2; equation++) 
          if (d > 0) 
          { 
            cout << "[SHUTTING THE PROGRAM DOWN NOW UNTIL RECTIFICATION IS MADE TO THIS EQUATION or EQUATIONS]" << endl; 
            cout << "Errors! Cannot have any number greater than 0 in equation format: ax^2 + bx + c" << endl;
            inputFile.close();
            break;
            }
              else
              {
                cout << "All is good with the formatting, order, etc" << endl;
                break;
              }
	}

	inputFile.close(); // ends the file
	return 0;
}