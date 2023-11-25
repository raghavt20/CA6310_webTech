#include <stdio.h>
#include <math.h>

int main() {
   float length, breadth, area, perimeter;

   printf("Enter length of rectangle: ");
   scanf("%f", &length);

   printf("Enter breadth of rectangle: ");
   scanf("%f", &breadth);

   area = length * breadth;
   perimeter = 2 * (length + breadth);

   printf("Area of rectangle = %.2f\n", area);
   printf("Perimeter of rectangle = %.2f\n", perimeter);

   float side, area_square, perimeter_square;

   printf("Enter side length of square: ");
   scanf("%f", &side);

   area_square = side * side;
   perimeter_square = 4 * side;

   printf("Area of square = %.2f\n", area_square);
   printf("Perimeter of square = %.2f\n", perimeter_square);

   float radius, area_circle, circumference_circle;

   printf("Enter radius of circle: ");
   scanf("%f", &radius);

   area_circle = M_PI * radius * radius;
   circumference_circle = 2 * M_PI * radius;

   printf("Area of circle = %.2f\n", area_circle);
   printf("Circumference of circle = %.2f\n", circumference_circle);

   return 0;
}
