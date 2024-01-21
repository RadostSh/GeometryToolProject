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
const unsigned int MaxOptions = 8;

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

/**
 * Validates that at least one of the coefficients A or B is non-zero for a line.
 * Prompts for re-entry of coefficients if both A and B are zero.
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

void printIntersectionPointBetweenLines(double x1, double x2, double y1, double y2)
{
    cout << "(" << x1 / x2 << ", " << y1 / y2 << ")";
}

void calculateIntersectionPoint(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double x1 = b1 * c2 - b2 * c1;
    double x2 = a1 * b2 - a2 * b1;

    double y1 = a2 * c1 - a1 * c2;
    double y2 = a1 * b2 - a2 * b1;
    printIntersectionPointBetweenLines(x1, x2, y1, y2);
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool checkAreformsTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double side1 = distance(x1, y1, x2, y2);
    double side2 = distance(x2, y2, x3, y3);
    double side3 = distance(x3, y3, x1, y1);

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
    calculateEquationOfLineThroughTwoPoints(x1, y1, x2, y2, coeffAMedian, coeffBMedian, coeffCMedian);
}

void printEquationsForMedians(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double coeffAMedian, coeffBMedian, coeffCMedian;
    cout << "The equations of medians of the triangle are: " << endl;

    calculateEquationForMedian(x3, y3, x2, y2, x1, y1, coeffAMedian, coeffBMedian, coeffCMedian);
    printLineEquation(coeffAMedian, coeffBMedian, coeffCMedian);
    cout << endl;

    calculateEquationForMedian(x3, y3, x1, y1, x2, y2, coeffAMedian, coeffBMedian, coeffCMedian);
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

void showOptions() {
    cout << "Available Options in Geometry Tool:" << endl;
    cout << "1. Verify if a specific point is on a defined line." << endl;
    cout << "2. Output a line parallel to a given line through a specific point." << endl;
    cout << "3. Output a line perpendicular to a given line at a specific point." << endl;
    cout << "4. Find intersection point of two lines." << endl;
    cout << "5. Given the coordinates of three points forming a triangle, construct equations for: \n   Heights;\n   Medians;\n   Bisectors;" << endl;

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
        cout << "The point " << pointName << " lies on line " << lineName << endl;
    }
    else {
        cout << "The point " << pointName << " does not lie on line " << lineName << endl;
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
        cout << "The point does not lie on line. Plese try again.";
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
    calculateIntersectionPoint(a1, b1, c1, a2, b2, c2);
    cout << endl;
}

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

void selectOption(int num) {

    switch (num) {
    case 1: checkPointOnLine();break;
    case 2: getParallelLineEquation();break;
    case 3: getPerpendicularLineEquation();break;
    case 4: findLinesIntersectionPoint();break;
    case 5: constructEquationsForTriangleElements();break;
    case 6:break;
    case 7:break;
    case 8:break;
    default:
        cout << "Incorrect input! Please try again and enter a number between 1 and 8.\n";
        break;
    }
}

int main()
{
    showOptions();
    double userSelection;
    loadUserSelection(userSelection);
    selectOption(userSelection);
}