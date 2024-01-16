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

double abs_Value(double num)
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

bool is_Point_On_Line(double x, double y, double a, double b, double c)
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
        if (!Are_Equal(abs_Value(b), 1) || Are_Equal(a, 0))
        {
            std::cout << abs_Value(b);
        }
        std::cout << "y";
    }

    if ((!Are_Equal(a, 0) || !Are_Equal(b, 0)) && !Are_Equal(c, 0))
    {
        std::cout << (c > 0 ? " + " : " - ");
    }

    if (!Are_Equal(c, 0))
    {
        std::cout << abs_Value(c);
        ;
    }

    // Print "= 0"
    if (!Are_Equal(a, 0) || !Are_Equal(b, 0) || !Are_Equal(c, 0))
    {
        std::cout << " = 0";
    }
}

void Åquation_Of_Line_Parallel_to_Selected_Line_And_Passing_Through_Selected_Point(double x, double y, double a, double b, double c)
{
    if (!is_Point_On_Line(x, y, a, b, c))
    {
        c = -a * x - b * y; //line slope coefficient
    }
    Print_Line_Equation(a, b, c);
}

void Choise_1_Point_On_Line()
{
    double a, b, c;
    char lineName[MAX_SIZE];
    Defines_A_Line(lineName, a, b, c);
    while (Are_Equal(a, 0) && Are_Equal(b, 0))
    {
        std::cout << "At least one of the coefficients A and B must be non-zero. Please try again.";
        Defines_A_Line(lineName, a, b, c);
    }

    double x, y;
    char pointName[MAX_SIZE];
    Defines_A_Point(pointName, x, y);

    if (is_Point_On_Line(x, y, a, b, c))
    {
        std::cout << "The point " << pointName << " is on the line " << lineName << std::endl;
    }
    else {
        std::cout << "The point " << pointName << " is not on the line " << lineName << std::endl;
    }
}

void Choise_2_Åquation_Of_Line_Parallel_to_Selected_Line_And_Passing_Through_Selected_Point()
{
    double a, b, c;
    char lineName[MAX_SIZE];
    Defines_A_Line(lineName, a, b, c);
    while (Are_Equal(a, 0) && Are_Equal(b, 0))
    {
        std::cout << "At least one of the coefficients A and B must be non-zero. Please try again."; // Invalid input!
        Defines_A_Line(lineName, a, b, c);
    }

    double x, y;
    char pointName[MAX_SIZE];
    Defines_A_Point(pointName, x, y);
    cout << "The equation of the line is: ";
    Åquation_Of_Line_Parallel_to_Selected_Line_And_Passing_Through_Selected_Point(x, y, a, b, c);
    cout << endl;
}

int main()
{

}