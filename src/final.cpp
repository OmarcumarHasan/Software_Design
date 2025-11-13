// Library for input/output (cout, cin)
#include <iostream>

// Allows using cout, cin, endl without std::
using namespace std;

// Abstract base class - cannot create Shape objects directly
// Provides a blueprint for all shape types
class Shape 
{
public:
   // Pure virtual function (= 0) - child classes MUST implement this
   // This creates a common interface for all shapes
   virtual double getArea() = 0;
   
   // Set the radius of the shape
   void setRadius(double r)
   {
      radius = r;
   }
   
   // Virtual destructor - good practice for base classes
   virtual ~Shape() {}

protected:
   // Protected variable - accessible by Shape and its child classes
   double radius;
};

// Circle class inherits from Shape
// Inherits radius and setRadius() from Shape
class Circle: public Shape
{
public:
   // Implements getArea() for Circle
   // Formula: Area = π × radius²
   // Using 3.14159 as approximation for π
   double getArea()
   { 
      return 3.14159 * radius * radius; 
   }
};

// Main function - program starts here
int main(void)
{
   // Create a Circle object
   Circle Circ;

   // Set radius = 5
   Circ.setRadius(5.0);
   
   // Calculate and display area: π × 5² = 78.54
   cout << "Total Circle area: " << Circ.getArea() << endl; 

   return 0;
}
