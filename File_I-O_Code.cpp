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
	int a = 0; //variables a-c, in accordance to count, will be used for the terms/elements of the equation when read
	int b = 0;
	int c = 0;
	int count = 0; //count, used in the while loop for reading
	double solution1, solution2; //solutions 1 and 2

	array<int, 4> numbers; // array of 'numbers'

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
		count = 0;
		cout << equation << endl;
		ss << equation;


		while (!ss.eof()) {
			ss >> temp; //temp variable used as a feedback center or "middle man" in the sense and equation put into temp
			if (temp == "+" || temp == "=" || temp == "-") continue; // looks for operators in accordance to the temp and the continue keyword breaks up the while loop 
			stringstream(temp) >> number;
			numbers[count] = number;
			if (count == 0) a = numbers[count]; // If-statements 1-3 check for the numbers or elements of the equations, and assigns them to 'a', 'b', or 'c'
			if (count == 1) b = numbers[count];
			if (count == 2) c = numbers[count]; 
			temp = ""; // "resets" the variables and restarts the process of analyzing the file
			count++;
		}
		solution1 = ((-b + (sqrt((pow(b,2)) - 4 * a * c))) / 2*a); // solutions 1 & 2 have the quadratic formulas for calculation
		solution2 = ((-b - (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
		cout << "Numbers\n";
		cout << "a: " << a << endl; // for the following lines, numbers associated with the parameters of the code, are placed in a, b, or c
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
		cout << "Solutions\n";
		cout << "x: " << solution1 << endl;
		cout << "x: " << solution2 << endl;
		cout << endl;

	}


	inputFile.close(); // ends the file
	return 0;
}
