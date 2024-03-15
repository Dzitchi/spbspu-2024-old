#include "circle.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <math.h>

volkov::Circle::Circle(const point_t& pos, double radius) :
  center_(pos),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double volkov::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

volkov::rectangle_t volkov::Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

void volkov::Circle::move(const point_t& newPos)
{
  center_ = newPos;
}

void volkov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

volkov::point_t volkov::Circle::getPos() const
{
  return center_;
}

void volkov::Circle::scale(double coef)
{
  if (coef <= 0.0)
  {
    throw std::invalid_argument("Invalid  coefficient");
  }
  else
  {
    radius_ *= coef;
  }
};
