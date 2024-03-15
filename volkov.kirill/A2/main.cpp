#include <iostream>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printArea(const volkov::Shape &shape)
{
  std::cout << "Area is " << shape.getArea() << "\n";
}

void printFrameRect(const volkov::Shape &shape)
{
  volkov::rectangle_t frameRect = shape.getFrameRect();
  std::cout <<  "Center is " << '(' 
      << frameRect.pos.x << ", " << frameRect.pos.y << ')' 
      << ", Height is " << frameRect.height 
      << ", Width is " << frameRect.width << "\n\n";
}

int main()
{
  std::cout << "In rectangle with center (1, 2), height = 3, width = 4\n";
  volkov::Rectangle rectangle({ {1, 2}, 3, 4 });
  printArea(rectangle);
  printFrameRect(rectangle);

  std::cout << "In circle with center (5, 6), radius = 7\n";
  volkov::Circle circle({ 5, 6 }, 7);
  printArea(circle);
  printFrameRect(circle);

  std::cout << "Move circle by (dx = 8 and dy = 9)\n";
  circle.move(8, 9);
  printArea(circle);
  printFrameRect(circle);

  std::cout << "Move rectangle to the point (10, 11)\n";
  rectangle.move({ 10, 11 });
  printArea(rectangle);
  printFrameRect(rectangle);

  std::cout << "Scaling circle by 2\n";
  circle.scale(2);
  printArea(circle);
  printFrameRect(circle);

  std::cout << "Scaling rectangle by 3\n";
  rectangle.scale(3);
  printArea(rectangle);
  printFrameRect(rectangle);
  return 0;
}
