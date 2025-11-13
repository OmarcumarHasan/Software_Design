// Include the iostream library to use input/output operations (cout, cin)
#include <iostream>

// This allows us to use cout, cin, endl without writing std:: before them
using namespace std;

/*
 * Shape Class - This is an ABSTRACT BASE CLASS
 * ============================================
 * An abstract class is a blueprint for other classes.
 * It cannot be instantiated directly (you can't create Shape objects).
 * It's meant to be inherited by other classes (like Triangle, Rectangle, etc.)
 * 
 * Key Concept: Polymorphism - Different shapes can have different ways to calculate area,
 * but they all share the same interface (getArea function).
 */
class Shape 
{
public:
   /*
    * Pure Virtual Function: virtual int getArea() = 0;
    * ================================================
    * The "= 0" makes this a pure virtual function.
    * This means:
    * 1. Every class that inherits from Shape MUST implement getArea()
    * 2. You cannot create Shape objects directly
    * 3. This provides a common interface for all shapes
    * 
    * "virtual" keyword allows derived classes to override this function
    */
   virtual int getArea() = 0;
   
   /*
    * setWidth Function
    * =================
    * Sets the width of the shape
    * Parameter: w - the width value to set
    */
   void setWidth(int w)
   {
      width = w;  // Store the width in the protected member variable
   }
   
   /*
    * setHeight Function
    * ==================
    * Sets the height of the shape
    * Parameter: h - the height value to set
    */
   void setHeight(int h)
   {
      height = h;  // Store the height in the protected member variable
   }
   
   /*
    * Virtual Destructor
    * ==================
    * Good practice: Always add a virtual destructor to base classes
    * This ensures proper cleanup when deleting derived class objects
    * through base class pointers
    */
   virtual ~Shape() {}

protected:
   /*
    * Protected Member Variables
    * ==========================
    * "protected" means these variables can be accessed by:
    * - This class (Shape)
    * - Any class that inherits from Shape (like Triangle)
    * But NOT by code outside these classes
    * 
    * These store the dimensions of the shape
    */
   int width;
   int height;
};

/*
 * Triangle Class - Inherits from Shape
 * =====================================
 * "public Shape" means Triangle IS-A Shape (inheritance relationship)
 * Triangle inherits all the members of Shape (width, height, setWidth, setHeight)
 * and MUST implement the pure virtual function getArea()
 */
class Triangle: public Shape
{
public:
   /*
    * getArea Function - Implementation for Triangle
    * ==============================================
    * Overrides the pure virtual function from Shape
    * Formula: Area of triangle = (base × height) / 2
    * Returns: The calculated area as an integer
    */
   int getArea()
   { 
      // Calculate area using the formula: (width * height) / 2
      // width serves as the base, height is the perpendicular height
      return (width * height) / 2; 
   }
};

/*
 * Main Function
 * =============
 * This is where program execution begins
 * Returns: 0 to indicate successful program completion
 */
int main(void)
{
   /*
    * Create a Triangle Object
    * ========================
    * "Tri" is an instance (object) of the Triangle class
    * This object has access to:
    * - setWidth() and setHeight() (inherited from Shape)
    * - getArea() (implemented in Triangle)
    */
   Triangle Tri;

   /*
    * Set Triangle Dimensions
    * =======================
    * Setting width to 5 units (this is the base of the triangle)
    */
   Tri.setWidth(5);
   
   /*
    * Setting height to 7 units (this is the perpendicular height)
    */
   Tri.setHeight(7);
   
   /*
    * Calculate and Display the Area
    * ==============================
    * Tri.getArea() calculates: (5 * 7) / 2 = 35 / 2 = 17 square units
    * cout prints the result to the console
    * endl creates a new line after printing
    */
   cout << "Total Triangle area: " << Tri.getArea() << endl; 

 
   return 0;
}
