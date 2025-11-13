// Library for input/output (cout, cin)
#include <iostream>
// Library for string handling
#include <string>
// Library for string stream operations
#include <sstream>

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
   
   // Get the radius of the shape
   double getRadius()
   {
      return radius;
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
   
   // Variable to store user input
   string input;
   double userRadius;
   
   // Prompt user for radius input
   cout << "Enter the radius of the circle (or press Enter for default 5.0): ";
   
   // Read entire line of input (including empty input)
   getline(cin, input);
   
   // Check if user pressed Enter without typing anything
   if (input.empty())
   {
      // Use default radius value
      Circ.setRadius(5.0);
      cout << "Using default radius: " << Circ.getRadius() << endl;
   }
   else
   {
      // Try to convert input string to a number
      stringstream ss(input);
      
      // Check if conversion is successful and radius is positive
      if (ss >> userRadius && userRadius > 0)
      {
         Circ.setRadius(userRadius);
         cout << "Using radius: " << Circ.getRadius() << endl;
      }
      else
      {
         // Invalid input - use default value
         cout << "Invalid input! Using default radius: 5.0" << endl;
         Circ.setRadius(5.0);
      }
   }
   
   // Calculate and display area
   cout << "Total Circle area: " << Circ.getArea() << endl; 

   return 0;
}
