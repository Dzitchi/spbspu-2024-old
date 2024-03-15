#include "rectangle.hpp"
#include <stdexcept>

volkov::Rectangle::Rectangle(const point_t& pos, double height, double width) :
  center_(pos),
  height_(height),
  width_(width)
{
  if ((height_ <= 0.0) || (width_ <= 0.0))
  {
    throw std::invalid_argument("Invalid radius");
  };
}

double volkov::Rectangle::getArea() const
{
  return (height_ * width_);
}

volkov::rectangle_t volkov::Rectangle::getFrameRect() const
{
  return { center_, height_, width_ };
}

void volkov::Rectangle::move(const point_t& newPos)
{
  center_ = newPos;
}

void volkov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

volkov::point_t volkov::Rectangle::getPos() const
{
  return center_;
}

void volkov::Rectangle::scale(double coef)
{
  if (coef <= 0.0)
  {
    throw std::invalid_argument("Invalid  coefficient");
  }
  else
  {
    height_ *= coef;
    width_ *= coef;
  }
};
