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
   virtual int getArea() = 0;
   
   // Set the width of the shape
   void setWidth(int w)
   {
      width = w;
   }
   
   // Set the height of the shape
   void setHeight(int h)
   {
      height = h;
   }
   
   // Virtual destructor - good practice for base classes
   virtual ~Shape() {}

protected:
   // Protected variables - accessible by Shape and its child classes
   int width;
   int height;
};

// Triangle class inherits from Shape
// Inherits width, height, setWidth(), setHeight() from Shape
class Triangle: public Shape
{
public:
   // Implements getArea() for Triangle
   // Formula: Area = (base × height) / 2
   int getArea()
   { 
      return (width * height) / 2; 
   }
};

// Main function - program starts here
int main(void)
{
   // Create a Triangle object
   Triangle Tri;

   // Set dimensions: base = 5, height = 7
   Tri.setWidth(5);
   Tri.setHeight(7);
   
   // Calculate and display area: (5 × 7) / 2 = 17
   cout << "Total Triangle area: " << Tri.getArea() << endl; 

   return 0;
}
