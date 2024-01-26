/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Radosveta Shopova
* @idnumber 2MI0600361* @compiler VS
*
*
*
*/

#include <iostream>
#include <cmath>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
const double EPSILON = 0.0001;
const unsigned int MaxOptions = 9;
const double PI = 3.14159265358979323846;

bool checkIsLetter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool checkIsNumber(char ch)
{
	return ch >= '0' && ch <= '9';
}

double calculateAbsolute(double num)
{
	return (num > 0) ? num : -num;
}

bool checkAreEqual(double num1, double num2)
{
	double difference = num1 - num2;
	if (difference < 0)
	{
		difference *= -1;
	}
	if (difference <= EPSILON)
	{
		return true;
	}
	return false;
}

bool checkIsValidName(const char* symbol)
{
	if (!symbol)
	{
		return false;
	}

	while (*symbol)
	{
		bool isSymbolValid = false;
		if (checkIsLetter(*symbol) || checkIsNumber(*symbol) || *symbol == '_')
		{
			isSymbolValid = true;
		}
		if (!isSymbolValid)
		{
			return false;
		}
		symbol++;
	}
	return true;
}

void readValidName(char* name)
{
	cin.ignore();
	cin.getline(name, MAX_SIZE);

	if (!checkIsValidName(name))
	{
		cout << "Invalid name! Please enter a new name!" << endl;
		cin.ignore();
		readValidName(name);
	}

}

void readValidNumber(double& num)
{
	while (true)
	{
		cin >> num;

		// Check if the input operation succeeded
		if (cin.good())
		{
			break;
		}
		else
		{
			cout << "Invalid number! Please enter a new number!" << endl;

			// Clear the error flags on cin to enable further input operations
			cin.clear();

			// Ignore the remaining characters in the input buffer up to the newline character
			// This is to prevent invalid characters from affecting the next input operation
			cin.ignore(100000, '\n');
		}
	}
}

void defineLine(char* line, double& a, double& b, double& c)
{
	cout << "Enter line name: ";
	readValidName(line);
	cout << "Enter the coefficients:" << endl;

	cout << "Coefficient A: ";
	readValidNumber(a);

	cout << "Coefficient B: ";
	readValidNumber(b);

	cout << "Coefficient C: ";
	readValidNumber(c);
}

void definePoint(char* point, double& x, double& y)
{
	cout << "Enter an appropriate point name: ";
	readValidName(point);
	cout << "Enter values for the coordinates (x, y):" << endl;

	cout << "x = ";
	readValidNumber(x);

	cout << "y = ";
	readValidNumber(y);
}

void defineParabola(char* parabola, double& a, double& b, double& c)
{
	cout << "Enter parabola name: ";
	readValidName(parabola);
	cout << "Enter the coefficients:" << endl;

	cout << "Coefficient A: ";
	readValidNumber(a);

	cout << "Coefficient B: ";
	readValidNumber(b);

	cout << "Coefficient C: ";
	readValidNumber(c);
}

/**
 * Validates that at least one of the coefficients A or B is non-zero for a line.
 *
 * @param line Pointer to the line's name.
 * @param a Reference to the coefficient A.
 * @param b Reference to the coefficient B.
 * @param c Reference to the coefficient C.
 */
void getValidCoefficients(char* line, double& a, double& b, double& c)
{
	while (checkAreEqual(a, 0) && checkAreEqual(b, 0))
	{
		cout << "Invalid input: Coefficients A and B cannot both be zero. Enter different values." << endl;
		defineLine(line, a, b, c);
	}
}

bool checkIsPointOnLine(double x, double y, double a, double b, double c)
{
	double equation = a * x + b * y + c;
	return checkAreEqual(equation, 0);
}

void printLineEquation(double a, double b, double c)
{
	if (!checkAreEqual(a, 0))
	{
		cout << a << "x";
	}

	if (!checkAreEqual(b, 0) && !checkAreEqual(a, 0))
	{
		cout << (b > 0 ? " + " : " - ");
	}

	if (!checkAreEqual(b, 0))
	{
		if (!checkAreEqual(calculateAbsolute(b), 1) || checkAreEqual(a, 0))
		{
			cout << calculateAbsolute(b);
		}
		cout << "y";
	}

	if ((!checkAreEqual(a, 0) || !checkAreEqual(b, 0)) && !checkAreEqual(c, 0))
	{
		cout << (c > 0 ? " + " : " - ");
	}

	if (!checkAreEqual(c, 0))
	{
		cout << calculateAbsolute(c);
	}

	if (!checkAreEqual(a, 0) || !checkAreEqual(b, 0) || !checkAreEqual(c, 0))
	{
		cout << " = 0";
	}
}

void calculateParallelLineEquation(double x, double y, double a, double b, double c)
{
	if (!checkIsPointOnLine(x, y, a, b, c))
	{
		c = -a * x - b * y; //line slope coefficient
	}
	printLineEquation(a, b, c);
}

void calculatePerpendicularLineEquationThroughPoint(double x, double y, double a, double b, double c, double& newA, double& newB, double& newC)
{
	newA = b;
	newB = -a;
	newC = a * y - b * x;
}

bool checkAreLinesOverlapping(double a1, double b1, double c1, double a2, double b2, double c2)
{
	return checkAreEqual(a1, a2) && checkAreEqual(b1, b2) && checkAreEqual(c1, c2);
}

bool checkAreParallelLines(double a1, double b1, double c1, double a2, double b2, double c2)
{
	if (checkAreEqual(a1, 0) && checkAreEqual(a2, 0) || checkAreEqual(b1, 0) && checkAreEqual(b2, 0))
	{
		return true;
	}

	double coefficientA = a1 / a2;
	double coefficientB = b1 / b2;
	if (checkAreEqual(coefficientA, coefficientB))
	{
		a2 *= coefficientB;
		b2 *= coefficientB;
		c2 *= coefficientB;
	}
	if (checkAreEqual(a1, a2) && checkAreEqual(b1, b2) && !checkAreEqual(c1, c2))
	{
		return true;
	}
	return false;
}

bool checkArePenperdicular(double a1, double b1, double c1, double a2, double b2, double c2)
{
	if (checkAreLinesOverlapping(a1, b1, c1, a2, b2, c2) || checkAreParallelLines(a1, b1, c1, a2, b2, c2))
	{
		return false;
	}

	double coefficientA = a1 * a2;
	double coefficientB = -b1 * b2;
	if (checkAreEqual(coefficientA, coefficientB))
	{
		return true;
	}
	return false;
}

void printIntersectionPointBetweenLines(double x, double y)
{
	cout << "(" << x << ", " << y << ")";
}

void calculateIntersectionPoint(double a1, double b1, double c1, double a2, double b2, double c2, double& x, double& y)
{
	x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
	y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
}

double calculateDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the angle between three points (in degrees) represented by (x, y) pairs
double calculateAngle(double x1, double y1, double x2, double y2, double x3, double y3) {

	// Calculate the angle in radians using arctangent
	double angleRadians = atan2(y3 - y2, x3 - x2) - atan2(y1 - y2, x1 - x2);

	// Ensure the angle is non-negative
	if (angleRadians < 0) {
		angleRadians += 2 * PI;
	}

	// Convert the angle to degrees
	return angleRadians * 180 / PI;
}

bool checkAreformsTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
	double side1 = calculateDistance(x1, y1, x2, y2);
	double side2 = calculateDistance(x2, y2, x3, y3);
	double side3 = calculateDistance(x3, y3, x1, y1);

	return (side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2);
}

void calculateEquationOfLineThroughTwoPoints(double x1, double y1, double x2, double y2, double& a, double& b, double& c)
{
	a = y1 - y2;
	b = x2 - x1;
	c = (x1 - x2) * y1 + (y2 - y1) * x1;
}

void calculateEquationForHeight(double x1, double y1, double x2, double y2, double x3, double y3, double& coeffAHeight, double& coeffBHeight, double& coeffCHeight)
{
	double a, b, c;
	calculateEquationOfLineThroughTwoPoints(x1, y1, x2, y2, a, b, c);
	calculatePerpendicularLineEquationThroughPoint(x3, y3, a, b, c, coeffAHeight, coeffBHeight, coeffCHeight);
}

void printEquationsForHeights(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double coeffAHeight, coeffBHeight, coeffCHeight;
	cout << "The equations of heights of the triangle are: " << endl;

	calculateEquationForHeight(x3, y3, x2, y2, x1, y1, coeffAHeight, coeffBHeight, coeffCHeight);
	printLineEquation(coeffAHeight, coeffBHeight, coeffCHeight);
	cout << endl;

	calculateEquationForHeight(x3, y3, x1, y1, x2, y2, coeffAHeight, coeffBHeight, coeffCHeight);
	printLineEquation(coeffAHeight, coeffBHeight, coeffCHeight);
	cout << endl;

	calculateEquationForHeight(x1, y1, x2, y2, x3, y3, coeffAHeight, coeffBHeight, coeffCHeight);
	printLineEquation(coeffAHeight, coeffBHeight, coeffCHeight);
	cout << endl;
}

void calculateMidpoint(double x1, double y1, double x2, double y2, double& midX, double& midY) {
	midX = (x1 + x2) / 2.0;
	midY = (y1 + y2) / 2.0;
}

void calculateEquationForMedian(double x1, double y1, double x2, double y2, double x3, double y3, double& coeffAMedian, double& coeffBMedian, double& coeffCMedian)
{
	double middleX, middleY;
	calculateMidpoint(x1, y1, x2, y2, middleX, middleY);
	calculateEquationOfLineThroughTwoPoints(x3, y3, middleX, middleY, coeffAMedian, coeffBMedian, coeffCMedian);
}

void printEquationsForMedians(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double coeffAMedian, coeffBMedian, coeffCMedian;
	cout << "The equations of medians of the triangle are: " << endl;

	calculateEquationForMedian(x3, y3, x2, y2, x1, y1, coeffAMedian, coeffBMedian, coeffCMedian);
	printLineEquation(coeffAMedian, coeffBMedian, coeffCMedian);
	cout << endl;

	calculateEquationForMedian(x1, y1, x3, y3, x2, y2, coeffAMedian, coeffBMedian, coeffCMedian);
	printLineEquation(coeffAMedian, coeffBMedian, coeffCMedian);
	cout << endl;

	calculateEquationForMedian(x1, y1, x2, y2, x3, y3, coeffAMedian, coeffBMedian, coeffCMedian);
	printLineEquation(coeffAMedian, coeffBMedian, coeffCMedian);
	cout << endl;
}

void calculateEquationForBisector(double x1, double y1, double x2, double y2, double x3, double y3, double& coeffABisector, double& coeffBBisector, double& coeffCBisector)
{
	double middleX, middleY;
	calculateMidpoint(x1, y1, x2, y2, middleX, middleY);

	double a, b, c;
	calculateEquationOfLineThroughTwoPoints(x1, y1, x2, y2, a, b, c);
	calculatePerpendicularLineEquationThroughPoint(middleX, middleY, a, b, c, coeffABisector, coeffBBisector, coeffCBisector);
}

void printEquationsForBisectors(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double coeffABisector, coeffBBisector, coeffCBisector;
	cout << "The equations of bisectors of the triangle are: " << endl;

	calculateEquationForBisector(x3, y3, x2, y2, x1, y1, coeffABisector, coeffBBisector, coeffCBisector);
	printLineEquation(coeffABisector, coeffBBisector, coeffCBisector);
	cout << endl;

	calculateEquationForBisector(x3, y3, x1, y1, x2, y2, coeffABisector, coeffBBisector, coeffCBisector);
	printLineEquation(coeffABisector, coeffBBisector, coeffCBisector);
	cout << endl;

	calculateEquationForBisector(x1, y1, x2, y2, x3, y3, coeffABisector, coeffBBisector, coeffCBisector);
	printLineEquation(coeffABisector, coeffBBisector, coeffCBisector);
	cout << endl;
}

void calculateTangentLineEquation(double a, double b, double c, double x, double y, double& coeffATangent, double& coeffBTangent, double& coeffCTangent)
{
	// Calculate the derivative of the parabola at the given point
	double derivative = 2 * a * x + b;

	// Use the point-slope form to construct the equation of the tangent line
	coeffATangent = derivative;
	coeffBTangent = -1.0;
	coeffCTangent = -derivative * x + y;
}

void calculateIntersectionPoints(double parA, double parB, double parC, double lineA, double lineB, double lineC) {
	// Òhe coefficients in front of the new quadratic equation among equating the two equations
	double A = parA;
	double B = parB - lineA;
	double C = parC - lineC;

	// Calculate the discriminant
	double discriminant = B * B - 4 * A * C;

	if (calculateAbsolute(discriminant) > EPSILON) {
		// Two real intersection points
		double x1 = (-B + sqrt(discriminant)) / (2 * A);
		double x2 = (-B - sqrt(discriminant)) / (2 * A);

		double y1 = parA * x1 * x1 + parB * x1 + parC;
		double y2 = parA * x2 * x2 + parB * x2 + parC;

		cout << "Intersection point 1 is: (" << x1 << ", " << y1 << ")" << endl;
		cout << "Intersection point 2 is: (" << x2 << ", " << y2 << ")" << endl;
	}
	else if (checkAreEqual(discriminant, 0)) {
		// One real intersection point
		double x = -B / (2 * A);
		double y = parA * x * x + parB * x + parC;
		cout << "Intersection point is: (" << x << ", " << y << ")" << endl;
	}
	else {
		cout << "No real intersection points." << endl;
	}
}

// Function to determine the type of quadrilateral based on intersection points represented by (x, y) pairs
string classifyQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double sideLengths[6];
	sideLengths[0] = calculateDistance(x1, y1, x2, y2);
	sideLengths[1] = calculateDistance(x2, y2, x3, y3);
	sideLengths[2] = calculateDistance(x3, y3, x4, y4);
	sideLengths[3] = calculateDistance(x4, y4, x1, y1);
	sideLengths[4] = calculateDistance(x1, y1, x3, y3);  // Diagonal 1
	sideLengths[5] = calculateDistance(x2, y2, x4, y4);  // Diagonal 2

	double angles[4];
	angles[0] = calculateAngle(x1, y1, x2, y2, x3, y3);
	angles[1] = calculateAngle(x2, y2, x3, y3, x4, y4);
	angles[2] = calculateAngle(x3, y3, x4, y4, x1, y1);
	angles[3] = calculateAngle(x4, y4, x1, y1, x2, y2);

	if (sideLengths[0] == sideLengths[2] && sideLengths[1] == sideLengths[3] && angles[0] == angles[2] && angles[1] == angles[3]) {
		if (sideLengths[0] == sideLengths[1]) {
			return "Square";
		}
		else {
			return "Rectangle";
		}
	}
	else if (sideLengths[0] == sideLengths[2] && sideLengths[1] == sideLengths[3]) {
		return "Parallelogram";
	}
	else {
		return ""; // Empty string indicates no valid quadrilateral
	}
}

void showOptions() {
	cout << "Available Options in Geometry Tool:" << endl;
	cout << "1. Verify if a specific point is on a defined line." << endl;
	cout << "2. Output a line parallel to a given line through a specific point." << endl;
	cout << "3. Output a line perpendicular to a given line at a specific point." << endl;
	cout << "4. Find intersection point of two lines." << endl;
	cout << "5. Given the coordinates of three points forming a triangle, construct equations for: \n   Heights;\n   Medians;\n   Bisectors;" << endl;
	cout << "6. Output a equation of the tanget line to a given parabola at a specific point." << endl;
	cout << "7. Find intersection point between parabola and line." << endl;
	cout << "8. Given four equations of lines, determine the type of the quadrilateral." << endl;
	cout << "9. Finish." << endl;
}

void loadUserSelection(double& selection) {
	cout << "\nChoose an option (1-" << MaxOptions << "): ";

	readValidNumber(selection);

	if (selection < 1 || selection > MaxOptions) {
		cout << "Choice out of range. Please reselect:" << endl;
		loadUserSelection(selection);
	}
}

/*
 * Checks if a given point lies on a specified line.
 */
void checkPointOnLine()
{
	double a, b, c;
	char lineName[MAX_SIZE];
	defineLine(lineName, a, b, c);
	getValidCoefficients(lineName, a, b, c);

	double x, y;
	char pointName[MAX_SIZE];
	definePoint(pointName, x, y);

	if (checkIsPointOnLine(x, y, a, b, c))
	{
		cout << "The point " << pointName << " lies on the line " << lineName << endl;
	}
	else {
		cout << "The point " << pointName << " does not lie on the line " << lineName << endl;
	}
}

/*
 * Calculates the equation of a line parallel to a given line and passing through a specified point.
 */
void getParallelLineEquation()
{
	double a, b, c;
	char lineName[MAX_SIZE];
	defineLine(lineName, a, b, c);
	getValidCoefficients(lineName, a, b, c);

	double x, y;
	char pointName[MAX_SIZE];
	definePoint(pointName, x, y);
	cout << "The equation of the line is: ";
	calculateParallelLineEquation(x, y, a, b, c);
	cout << endl;
}

/*
 * Calculates the equation of a line that is perpendicular to a given line and passes through a specific point.
 * It then calculates and returns the equation of the perpendicular line.
 */
void getPerpendicularLineEquation()
{
	double a, b, c;
	char lineName[MAX_SIZE];
	defineLine(lineName, a, b, c);
	getValidCoefficients(lineName, a, b, c);

	double x, y;
	char pointName[MAX_SIZE];
	definePoint(pointName, x, y);
	while (!checkIsPointOnLine(x, y, a, b, c))
	{
		cout << "The point does not lie on line. Plese try again." << endl;
		defineLine(lineName, a, b, c);
	}
	cout << "The equation of the line is: ";
	double newA, newB, newC;
	calculatePerpendicularLineEquationThroughPoint(x, y, a, b, c, newA, newB, newC);
	printLineEquation(newA, newB, newC);
	cout << endl;
}

/*
 * Calculates the intersection point of two given lines.
 * It uses these coefficients to compute the point at which the two lines intersect.
 */
void findLinesIntersectionPoint()
{
	double a1, b1, c1;
	char lineName1[MAX_SIZE];
	defineLine(lineName1, a1, b1, c1);
	getValidCoefficients(lineName1, a1, b1, c1);

	double a2, b2, c2;
	char lineName2[MAX_SIZE];
	defineLine(lineName2, a2, b2, c2);
	getValidCoefficients(lineName2, a2, b2, c2);

	if (checkAreLinesOverlapping(a1, b1, c1, a2, b2, c2))
	{
		cout << "The two lines are overlapping! Please try again! " << endl;
		defineLine(lineName1, a1, b1, c1);
		defineLine(lineName2, a2, b2, c2);
	}
	if (checkAreParallelLines(a1, b1, c1, a2, b2, c2))
	{
		cout << "The two lines are parallel! Please try again! " << endl;
		defineLine(lineName1, a1, b1, c1);
		defineLine(lineName2, a2, b2, c2);
	}

	cout << "The intersection point of " << lineName1 << " and " << lineName2 << " is: ";
	double x, y;
	calculateIntersectionPoint(a1, b1, c1, a2, b2, c2, x, y);
	printIntersectionPointBetweenLines(x, y);
	cout << endl;
}

/*
*Defineñ three points as vertices of a triangle.
* Checks if the provided points form a valid triangle.If so, calculates
* and prints equations for heights, medians, and bisectors of the triangle.
*/
void constructEquationsForTriangleElements()
{
	double x1, y1;
	char pointName1[MAX_SIZE];
	definePoint(pointName1, x1, y1);

	double x2, y2;
	char pointName2[MAX_SIZE];
	definePoint(pointName2, x2, y2);

	double x3, y3;
	char pointName3[MAX_SIZE];
	definePoint(pointName3, x3, y3);

	if (checkAreformsTriangle(x1, y1, x2, y2, x3, y3)) {
		printEquationsForHeights(x1, y1, x2, y2, x3, y3);
		printEquationsForMedians(x1, y1, x2, y2, x3, y3);
		printEquationsForBisectors(x1, y1, x2, y2, x3, y3);
	}
	else {
		cout << "The points do not form a triangle. Please try again." << endl;
		definePoint(pointName1, x1, y1);
		definePoint(pointName2, x2, y2);
		definePoint(pointName3, x3, y3);
	}
}
/*
 * Calculates the tangent line equation at a specified point (x, y) on the parabola.
 * Prints the equation of the tangent line.
 */
void getTangentLineEquation()
{
	double a, b, c;
	char parabolaName[MAX_SIZE];
	defineParabola(parabolaName, a, b, c);
	getValidCoefficients(parabolaName, a, b, c);

	double x, y;
	char pointName[MAX_SIZE];
	definePoint(pointName, x, y);

	double coeffATangent, coeffBTangent, coeffCTangent;
	calculateTangentLineEquation(a, b, c, x, y, coeffATangent, coeffBTangent, coeffCTangent);
	cout << "The equation of the tangent line is: ";
	printLineEquation(coeffATangent, coeffBTangent, coeffCTangent);
	cout << endl;
}

/*
 * Calculates and prints the intersection points between the parabola and the line.
*/
void findIntersectionPointBetweenParabolaAndLine()
{
	double parA, parB, parC;
	char parabolaName[MAX_SIZE];
	defineParabola(parabolaName, parA, parB, parC);
	getValidCoefficients(parabolaName, parA, parB, parC);

	double lineA, lineB, lineC;
	char lineName[MAX_SIZE];
	defineLine(lineName, lineA, lineB, lineC);
	getValidCoefficients(lineName, lineA, lineB, lineC);

	calculateIntersectionPoints(parA, parB, parC, lineA, lineB, lineC);
}

/*
 * Calculates the intersection points between the lines and determines the type
 * of quadrilateral formed based on side lengths and angles.
 * Prints the result indicating whether it's a Square, Rectangle, Parallelogram,
 * or also indicates if the provided lines do not form a quadrilateral.
*/
void determineShapeOfQuadrilateral()
{
	double a1, b1, c1;
	char lineName1[MAX_SIZE];
	defineLine(lineName1, a1, b1, c1);
	getValidCoefficients(lineName1, a1, b1, c1);

	double a2, b2, c2;
	char lineName2[MAX_SIZE];
	defineLine(lineName2, a2, b2, c2);
	getValidCoefficients(lineName2, a2, b2, c2);

	double a3, b3, c3;
	char lineName3[MAX_SIZE];
	defineLine(lineName3, a3, b3, c3);
	getValidCoefficients(lineName3, a3, b3, c3);

	double a4, b4, c4;
	char lineName4[MAX_SIZE];
	defineLine(lineName4, a4, b4, c4);
	getValidCoefficients(lineName4, a4, b4, c4);

	double point1X, point1Y, point2X, point2Y, point3X, point3Y, point4X, point4Y;

	calculateIntersectionPoint(a1, b1, c1, a2, b2, c2, point1X, point1Y);
	calculateIntersectionPoint(a2, b2, c2, a3, b3, c3, point2X, point2Y);
	calculateIntersectionPoint(a3, b3, c3, a4, b4, c4, point3X, point3Y);
	calculateIntersectionPoint(a4, b4, c4, a1, b1, c1, point4X, point4Y);

	// Determine the type of quadrilateral
	string typeOfQuadrilateral = classifyQuadrilateral(point1X, point1Y, point2X, point2Y, point3X, point3Y, point4X, point4Y);
	if (typeOfQuadrilateral == "") {
		cout << "No valid quadrilateral can be formed with the given lines." << endl;
	}
	else {
		cout << "The given lines form a " << typeOfQuadrilateral << "." << endl;
	}
}

void finish(bool& quitFlag) {
	quitFlag = false;
}

void selectOption(int num, bool& quitFlag) {

	switch (num) {
	case 1: checkPointOnLine();break;
	case 2: getParallelLineEquation();break;
	case 3: getPerpendicularLineEquation();break;
	case 4: findLinesIntersectionPoint();break;
	case 5: constructEquationsForTriangleElements();break;
	case 6: getTangentLineEquation();break;
	case 7: findIntersectionPointBetweenParabolaAndLine();break;
	case 8: determineShapeOfQuadrilateral();break;
	case 9: finish(quitFlag);break;
	default:
		cout << "Incorrect input! Please try again and enter a number between 1 and 9.\n";
		break;
	}
}

int main()
{
	showOptions();
	bool quitFlag = true;
	while (quitFlag)
	{
		double userSelection;
		loadUserSelection(userSelection);
		selectOption(userSelection, quitFlag);
	}
}