#include "Jeans.h"

Jeans::Jeans()
{
  color = Jeans_colors(rand() % 4);
  size = Jeans_sizes(rand() % 4);
}

Jeans_colors Jeans::get_color() const
{
  return color;
}
Jeans_sizes Jeans::get_size() const
{
  return size;
}

bool Jeans::operator==(const Jeans &j)
{
  if (color == j.color && size == j.size)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Jeans::operator>(const Jeans &j)
{
  if (get_size() > j.get_size())
  {
    return true;
  }
  return false;
}

ostream &operator<<(ostream &o, const Jeans &j)
{
  switch (j.get_color())
  {
  case Jeans_colors::white:
    cout << "(white";
    break;
  case Jeans_colors::blue:
    cout << "(blue";
    break;
  case Jeans_colors::brown:
    cout << "(brown";
    break;
  case Jeans_colors::black:
    cout << "(black";
    break;
  }
  switch (j.get_size())
  {
  case Jeans_sizes::small:
    cout << ", small)";
    break;
  case Jeans_sizes::medium:
    cout << ", medium)";
    break;
  case Jeans_sizes::large:
    cout << ", large)";
    break;
  case Jeans_sizes::xlarge:
    cout << ", xlarge)";
    break;
  }
  return o;
}