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

bool Is_Letter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool Is_Number(char ch)
{
    return ch >= '0' && ch <= '9';
}

double Abs_Value(double num)
{
    return (num > 0) ? num : -num;
}

bool Are_Equal(double num1, double num2)
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
        if (!Is_Letter(*symbol) || !Is_Number(*symbol) || *symbol == '_')
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

void Enter_A_Number(double& num)
{
    while (true)
    {
        cin >> num;
        if (cin.good())
        {
            break;
        }
        else
        {
            cout << "Invalid number! Please enter a new number!" << endl;
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }
}

void Defines_A_Line(char* line, double& a, double& b, double& c)
{
    cout << "Enter an appropriate line name: ";
    Get_Name_Input(line);
    cout << "Enter values for the coefficients of A, B and C on the line:";

    cout << "A = ";
    Enter_A_Number(a);

    cout << "B = ";
    Enter_A_Number(b);

    cout << "C = ";
    Enter_A_Number(c);

}

void Defines_A_Point(char* point, double& x, double& y)
{
    cout << "Enter an appropriate point name: ";
    Get_Name_Input(point);
    cout << "Enter values for the coordinates (x, y):";

    cout << "x = ";
    Enter_A_Number(x);

    cout << "y = ";
    Enter_A_Number(y);
}

void Get_Valid_Coefficient(char* line, double& a, double& b, double& c)
{
    while (Are_Equal(a, 0) && Are_Equal(b, 0))
    {
        std::cout << "At least one of the coefficients A and B must be non-zero. Please try again."; // Invalid input!
        Defines_A_Line(line, a, b, c);
    }
}

bool Is_Point_On_Line(double x, double y, double a, double b, double c)
{
    double equation = a * x + b * y + c;
    return Are_Equal(equation, 0);
}

void Print_Line_Equation(double a, double b, double c)
{
    if (!Are_Equal(a, 0))
    {
        std::cout << a << "x";
    }

    if (!Are_Equal(b, 0) && !Are_Equal(a, 0))
    {
        std::cout << (b > 0 ? " + " : " - ");
    }

    if (!Are_Equal(b, 0))
    {
        if (!Are_Equal(Abs_Value(b), 1) || Are_Equal(a, 0))
        {
            std::cout << Abs_Value(b);
        }
        std::cout << "y";
    }

    if ((!Are_Equal(a, 0) || !Are_Equal(b, 0)) && !Are_Equal(c, 0))
    {
        std::cout << (c > 0 ? " + " : " - ");
    }

    if (!Are_Equal(c, 0))
    {
        std::cout << Abs_Value(c);
        ;
    }

    // Print "= 0"
    if (!Are_Equal(a, 0) || !Are_Equal(b, 0) || !Are_Equal(c, 0))
    {
        std::cout << " = 0";
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
    return Are_Equal(a1, a2) && Are_Equal(b1, b2) && Are_Equal(c1, c2);
}

bool Are_Parallel_Lines(double a1, double b1, double c1, double a2, double b2, double c2)
{
    if (Are_Equal(a1, 0) && Are_Equal(a2, 0) || Are_Equal(b1, 0) && Are_Equal(b2, 0))
    {
        return true;
    }

    double coefficientA = a1 / a2;
    double coefficientB = b1 / b2;
    if (Are_Equal(coefficientA, coefficientB))
    {
        a2 *= coefficientB;
        b2 *= coefficientB;
        c2 *= coefficientB;
    }
    if (Are_Equal(a1, a2) && Are_Equal(b1, b2) && !Are_Equal(c1, c2))
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
    if (Are_Equal(coefficientA, coefficientB))
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

void Choise_1_Point_On_Line()
{
    double a, b, c;
    char lineName[MAX_SIZE];
    Defines_A_Line(lineName, a, b, c);
    Get_Valid_Coefficient(lineName, a, b, c);

    double x, y;
    char pointName[MAX_SIZE];
    Defines_A_Point(pointName, x, y);

    if (Is_Point_On_Line(x, y, a, b, c))
    {
        std::cout << "The point " << pointName << " lies on line " << lineName << std::endl;
    }
    else {
        std::cout << "The point " << pointName << " does not lie on line " << lineName << std::endl;
    }
}

void Choise_2_Equation_Of_Line_Parallel_to_Selected_Line_And_Passing_Through_Selected_Point()
{
    double a, b, c;
    char lineName[MAX_SIZE];
    Defines_A_Line(lineName, a, b, c);
    Get_Valid_Coefficient(lineName, a, b, c);

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
    Defines_A_Line(lineName, a, b, c);
    Get_Valid_Coefficient(lineName, a, b, c);

    double x, y;
    char pointName[MAX_SIZE];
    Defines_A_Point(pointName, x, y);
    while (!Is_Point_On_Line(x, y, a, b, c))
    {
        std::cout << "The point does not lie on line. Plese try again.";
        Defines_A_Line(lineName, a, b, c);
    }
    cout << "The equation of the line is: ";
    Equation_Of_Perpendicular_Line_Passsing_Throuh_A_Point(x, y, a, b, c);
    cout << endl;
}

void Choise_4_Find_The_Interception_Point_Of_Two_Lines()
{
    double a1, b1, c1;
    char lineName1[MAX_SIZE];
    Defines_A_Line(lineName1, a1, b1, c1);
    Get_Valid_Coefficient(lineName1, a1, b1, c1);

    double a2, b2, c2;
    char lineName2[MAX_SIZE];
    Defines_A_Line(lineName2, a2, b2, c2);
    Get_Valid_Coefficient(lineName2, a2, b2, c2);

    if (Are_Overlapping_Lines(a1, b1, c1, a2, b2, c2))
    {
        cout << "The two lines are overlapping! Please try again! " << endl;
        Defines_A_Line(lineName1, a1, b1, c1);
        Defines_A_Line(lineName2, a2, b2, c2);
    }
    if (Are_Parallel_Lines(a1, b1, c1, a2, b2, c2))
    {
        cout << "The two lines are parallel! Please try again! " << endl;
        Defines_A_Line(lineName1, a1, b1, c1);
        Defines_A_Line(lineName2, a2, b2, c2);
    }

    cout << "The intersection point of " << lineName1 << " and " << lineName2 << " is: ";
    Interception_Point_Of_Two_Lines(a1, b1, c1, a2, b2, c2);
    cout << endl;
}

int main()
{

}