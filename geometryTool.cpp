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
using namespace std;

constexpr size_t MAX_SIZE = 1024;
const double EPSILON = 0.0001;

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

bool Is_Valid_Name(const char* symbol)
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

void Get_Name_Input(char* name)
{
    cin.ignore();
    cin.getline(name, MAX_SIZE);

    if (!Is_Valid_Name(name))
    {
        cout << "Invalid name! Please enter a new name!" << endl;
        cin.ignore();
        Get_Name_Input(name);
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
    Get_Name_Input(line);
    cout << "Enter the coefficients:" << endl;

    cout << "Coefficient A: ";
    readValidNumber(a);

    cout << "Coefficient B: ";
    readValidNumber(b);

    cout << "Coefficient C: ";
    readValidNumber(c);

}

void Defines_A_Point(char* point, double& x, double& y)
{
    cout << "Enter an appropriate point name: ";
    Get_Name_Input(point);
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

bool Is_Point_On_Line(double x, double y, double a, double b, double c)
{
    double equation = a * x + b * y + c;
    return checkAreEqual(equation, 0);
}

void Print_Line_Equation(double a, double b, double c)
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

    // Print "= 0"
    if (!checkAreEqual(a, 0) || !checkAreEqual(b, 0) || !checkAreEqual(c, 0))
    {
        cout << " = 0";
    }
}

void Equation_Of_Line_Parallel_to_Selected_Line_And_Passing_Through_Selected_Point(double x, double y, double a, double b, double c)
{
    if (!Is_Point_On_Line(x, y, a, b, c))
    {
        c = -a * x - b * y; //line slope coefficient
    }
    Print_Line_Equation(a, b, c);
}

void Equation_Of_Perpendicular_Line_Passsing_Throuh_A_Point(double x, double y, double a, double b, double c)
{
    double newA = b;
    double newB = -a;
    double newC = a * y - b * x;
    Print_Line_Equation(newA, newB, newC);
}

bool Are_Overlapping_Lines(double a1, double b1, double c1, double a2, double b2, double c2)
{
    return checkAreEqual(a1, a2) && checkAreEqual(b1, b2) && checkAreEqual(c1, c2);
}

bool Are_Parallel_Lines(double a1, double b1, double c1, double a2, double b2, double c2)
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

bool Are_Penperdicular(double a1, double b1, double c1, double a2, double b2, double c2)
{
    if (Are_Overlapping_Lines(a1, b1, c1, a2, b2, c2) || Are_Parallel_Lines(a1, b1, c1, a2, b2, c2))
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

void Print_Point_Of_Two_Lines(double x1, double x2, double y1, double y2)
{
    cout << "(" << x1 / x2 << ", " << y1 / y2 << ")";
}

void Interception_Point_Of_Two_Lines(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double x1 = b1 * c2 - b2 * c1;
    double x2 = a1 * b2 - a2 * b1;

    double y1 = a2 * c1 - a1 * c2;
    double y2 = a1 * b2 - a2 * b1;
    Print_Point_Of_Two_Lines(x1, x2, y1, y2);
}

void showOptions() {
    cout << "Available Options in Geometry Tool:" << endl;
    cout << "1. Verify if a specific point is on a defined line." << endl;
    cout << "2. Output a line parallel to a given line through a specific point." << endl;
    cout << "3. Output a line perpendicular to a given line at a specific point." << endl;
    cout << "4. Find intersection point of two lines." << endl;
}

//void Initial_Choice(double& N) {
//    cout << endl << "Enter the number of one of the options above: ";
//    readValidNumber(N);
//    double allOptions = 12;
//    if (N < 1 || N > allOptions) {
//        cout << "Invalid number! Enter a new number!" << endl;
//        Initial_Choice(N);
//    }
//}

void loadUserSelection(double& selection) {
    const unsigned int MaxOptions = 12;
    cout << "\nChoose an option (1-" << MaxOptions << "): ";

    readValidNumber(selection);

    bool isInvalidSelection = selection < 1 || selection > MaxOptions;
    if (isInvalidSelection) {
        cout << "Choice out of range. Please reselect:" << endl;
        loadUserSelection(selection);
    }
}

void Choise_1_Point_On_Line()
{
    double a, b, c;
    char lineName[MAX_SIZE];
    defineLine(lineName, a, b, c);
    getValidCoefficients(lineName, a, b, c);

    double x, y;
    char pointName[MAX_SIZE];
    Defines_A_Point(pointName, x, y);

    if (Is_Point_On_Line(x, y, a, b, c))
    {
        cout << "The point " << pointName << " lies on line " << lineName << endl;
    }
    else {
        cout << "The point " << pointName << " does not lie on line " << lineName << endl;
    }
}

/**
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
    Defines_A_Point(pointName, x, y);
    cout << "The equation of the line is: ";
    Equation_Of_Line_Parallel_to_Selected_Line_And_Passing_Through_Selected_Point(x, y, a, b, c);
    cout << endl;
}

void Choise_3_Equation_Of_Line_Perpendicular_To_Selected_Line_Passsing_Throuh_A_Point()
{
    double a, b, c;
    char lineName[MAX_SIZE];
    defineLine(lineName, a, b, c);
    getValidCoefficients(lineName, a, b, c);

    double x, y;
    char pointName[MAX_SIZE];
    Defines_A_Point(pointName, x, y);
    while (!Is_Point_On_Line(x, y, a, b, c))
    {
        cout << "The point does not lie on line. Plese try again.";
        defineLine(lineName, a, b, c);
    }
    cout << "The equation of the line is: ";
    Equation_Of_Perpendicular_Line_Passsing_Throuh_A_Point(x, y, a, b, c);
    cout << endl;
}

void Choise_4_Find_The_Interception_Point_Of_Two_Lines()
{
    double a1, b1, c1;
    char lineName1[MAX_SIZE];
    defineLine(lineName1, a1, b1, c1);
    getValidCoefficients(lineName1, a1, b1, c1);

    double a2, b2, c2;
    char lineName2[MAX_SIZE];
    defineLine(lineName2, a2, b2, c2);
    getValidCoefficients(lineName2, a2, b2, c2);

    if (Are_Overlapping_Lines(a1, b1, c1, a2, b2, c2))
    {
        cout << "The two lines are overlapping! Please try again! " << endl;
        defineLine(lineName1, a1, b1, c1);
        defineLine(lineName2, a2, b2, c2);
    }
    if (Are_Parallel_Lines(a1, b1, c1, a2, b2, c2))
    {
        cout << "The two lines are parallel! Please try again! " << endl;
        defineLine(lineName1, a1, b1, c1);
        defineLine(lineName2, a2, b2, c2);
    }

    cout << "The intersection point of " << lineName1 << " and " << lineName2 << " is: ";
    Interception_Point_Of_Two_Lines(a1, b1, c1, a2, b2, c2);
    cout << endl;
}

void options(int N, bool& want_to_quit) {

    switch (N) {
    case 1: Choise_1_Point_On_Line();break;
    case 2: getParallelLineEquation();break;
    case 3: Choise_3_Equation_Of_Line_Perpendicular_To_Selected_Line_Passsing_Throuh_A_Point();break;
    case 4: Choise_4_Find_The_Interception_Point_Of_Two_Lines();break;
    case 5:;break;
    case 6:;break;
    case 7:;break;
    case 8:;break;
    default:
        cout << "Incorrect input! Please try again and enter a number between 1 and 12.\n";
        break;
    }
}

void start_Program() {
    bool want_to_quit = true;
    showOptions();

    while (want_to_quit != false) {
        double N;
        loadUserSelection(N);
        options(N, want_to_quit);
    }
}

int main()
{
    start_Program();
}