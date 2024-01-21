# Geometry Tool User Manual

The Geometry Tool is a program that allows you to perform geometric calculations and tasks. Below are the available options with explanations, user input examples, and program output examples for each option:

## 1) Check if a Point Lies on a Line

**Idea:**

- **User Input:** Provide the equation of a line in the form \(ax + by + c = 0\) and the coordinates of a point \((x, y)\).
- **Program Output:** Check if the provided point lies on the given line.

**Example:**

- **User Input:**
  - Line Equation: \(2x - 3y + 6 = 0\)
  - Point Coordinates: \((3, 4)\)
- **Program Output:**
  - The program checks if the point \((3, 4)\) lies on the line \(2x - 3y + 6 = 0\).
- **Result:**
  - Output: The point \((3, 4)\) lies on the line \(2x - 3y + 6 = 0\).

## 2) Find the Equation of a Line Parallel to a Given Line and Passing Through a Point

**Idea:**

- **User Input:** Provide the equation of a line in the form \(ax + by + c = 0\) and the coordinates of a point \((x, y)\).
- **Program Output:** Calculate the equation of a line that is parallel to the provided line and passes through the given point.

**Example:**

- **User Input:**
  - Given Line Equation: \(-x + 2y + 5 = 0\)
  - Point Coordinates: \((3, 2)\)
- **Program Output:**
  - The program calculates the equation of a line parallel to \(-x + 2y + 5 = 0\) and passing through \((3, 2)\).
- **Result:**
  - Output: The equation of the line parallel to \(-x + 2y + 5 = 0\) and passing through \((3, 2)\) is \(-x + 2y - 1 = 0\).

## 3) Find the Equation of a Line Perpendicular to a Given Line and Passing Through a Point

**Idea:**

- **User Input:** Provide the equation of a line in the form \(ax + by + c = 0\) and the coordinates of a point \((x, y)\), lying on this line.
- **Program Output:** Calculate the equation of a line that is perpendicular to the provided line and passes through the given point.

**Example:**

- **User Input:**
  - Given Line Equation: \(2x - 3y + 5 = 0\)
  - Point Coordinates: \((-1, 1)\)
- **Program Output:**
  - The program calculates the equation of a line perpendicular to \(2x - 3y + 5 = 0\) and passing through \((-1, 1)\).
- **Result:**
  - Output: The equation of the line perpendicular to \(2x - 3y + 5 = 0\) and passing through \((-1, 1)\) is \(-3x - 2y - 1 = 0\).

## 4) Calculate the Intersection Point of Two Lines

**Idea:**

- **User Input:** Provide the equations of two lines in the form \(ax + by + c = 0\).
- **Program Output:** Calculate the intersection point, if it exists, between the two provided lines.

**Example:**

- **User Input:**
  - Line 1 Equation: \(3x - y - 5 = 0\)
  - Line 2 Equation: \(-x + 2y + 5 = 0\)
- **Program Output:**
  - The program calculates the intersection point between \(3x - y - 5 = 0\) and \(-x + 2y + 5 = 0\).
- **Result:**
  - Output: The intersection point of \(3x - y - 5 = 0\) and \(-x + 2y + 5 = 0\) is \((1, -2)\).

## 5) Construct Equations for Heights, Medians and Bisectors of a Triangle

**Idea:**

- **User Input:** Provide coordinates of three points defining a triangle.
- **Program Output:** Construct equations for heights, medians and bisectors of the triangle.

**Example:**

- **User Input:**

  - Coordinates of Three Triangle Points: \(A(4, 6)\), \(B(6, 2)\), \(C(8, 8)\)
- **Program Output:**

  - The program constructs equations for heights, medians and bisectors of the triangle formed by points \(A(4, 6)\), \(B(6, 2)\) and \(C(8, 8)\).
- **Result:**

  - Heights:
    -  -2x - 6y + 44 = 0
  
    - -4x - 2y + 28 = 0
  
    - 2x - 4y + 16 = 0
  
  - Medians: 
    - 6x - 2y - 32 = 0
    - 2x - 4y + 16 = 0
    - 4x + 2y - 28 = 0
  - Bisectors: 
    - -2x - 6y + 44 = 0
    - -4x - 2y + 38 = 0
    - 2x - 4y + 6 = 0

## 6) Find Tangent Line to a Parabola at a Given Point

**Idea:**

- **User Input:** Provide the coefficients of a parabola in the form \(ax^2 + bx + c\) and the coordinates of a point \((x, y)\).
- **Program Output:** Calculate the equation of the tangent line to the parabola at the specified point.

**Example:**

- **User Input:**
  - Given Parabola Equation: \(2x^2 - 3x + 1\)
  - Point Coordinates: \((2, 3)\)
- **Program Output:**
  - The program calculates the equation of the tangent line to \(2x^2 - 3x + 1\) at \((2, 3)\).
- **Result:**
  - Output: The equation of the tangent line to \(2x^2 - 3x + 1\) at \((2, 3)\) is \(5x - y - 7 = 0\).

## 7) Determine Intersection Points of a Parabola and a Line

**Idea:**

- **User Input:** Provide the coefficients of a parabola in the form \(ax^2 + bx + c\) and the equation of a line in the form \(ax + by + c = 0\).
- **Program Output:** Calculate the intersection points, if they exist, between the parabola and the line.

**Example:**

- **User Input:**

  ​	***Example 1:***

  - Given Parabola Equation: \(2x^2 + 3x + 1\)

  - Line Equation: \(x - y + 1 = 0\)

    ***Example 2:***

  - Given Parabola Equation: \(2x^2 - 3x + 1\)

  - Line Equation: \(5x - y - 7 = 0\)

- **Result:**

  ​	***Example 1:***

  - Output: The intersection points of \(2x^2 + 3x + 1\) and \(x - y + 1 = 0\) are (0, 1) and (-1, 0).

    ***Example 2:***

  - Output: The intersection point of \(2x^2 - 3x + 1) and \(5x - y - 7 = 0\) is (2, 3).

## 8) Analyze Quadrilaterals Formed by Four Lines

**Idea:**

- **User Input:** Provide the equations of four lines in the form \(ax + by + c = 0\). Ensure that you enter lines that are **adjacent** to each other.
- **Program Output:** Determine the type of quadrilateral formed by the intersection of these lines, which can be a square, rectangle or parallelogram. The program also indicates if the provided lines do not form a quadrilateral.

**Example:**

- **User Input:**

  ​	***Example 1:***

  Equations of Four Adjacent Lines: 

  - Line 1: \(x = 4\)
  - Line 2: \(y = 1\)
  - Line 3: \(x = 2\)
  - Line 4: \(y = 3)

  ​	***Example 2:***

  Equations of Four Adjacent Lines: 

  - Line 1: \(x - y + 1 = 0\)
  - Line 2: \(y = 1\)
  - Line 3: \(x - y - 1 = 0\)
  - Line 4: \(y = 3\)

- **Result:**

  ​	***Example 1:***

  - Output: The given lines form a Square.

    ***Example 2:***

  - Output: The given lines form a Parallelogram.

These examples cover all the options of the Geometry Tool, providing a clear understanding of the user input, program output, and real-world scenarios where the tool can be applied.
