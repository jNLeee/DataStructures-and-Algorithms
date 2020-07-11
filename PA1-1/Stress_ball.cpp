#include "Stress_ball.h"

Stress_ball::Stress_ball()
{
  color = Stress_ball_colors(rand() % 4);
  size = Stress_ball_sizes(rand() % 3);
}

Stress_ball_colors Stress_ball::get_color() const
{
  return color;
}
Stress_ball_sizes Stress_ball::get_size() const
{
  return size;
}

bool Stress_ball::operator==(const Stress_ball &sb)
{
  if (color == sb.color && size == sb.size)
  {
    return true;
  }
  else
  {
    return false;
  }
}

ostream &operator<<(ostream &o, const Stress_ball &sb)
{
  switch (sb.get_color())
  {
  case Stress_ball_colors::red:
    cout << "(red";
    break;
  case Stress_ball_colors::blue:
    cout << "(blue";
    break;
  case Stress_ball_colors::yellow:
    cout << "(yellow";
    break;
  case Stress_ball_colors::green:
    cout << "(green";
    break;
  }
  switch (sb.get_size())
  {
  case Stress_ball_sizes::small:
    cout << ", small)";
    break;
  case Stress_ball_sizes::medium:
    cout << ", medium)";
    break;
  case Stress_ball_sizes::large:
    cout << ", large)";
    break;
  }
  return o;
}