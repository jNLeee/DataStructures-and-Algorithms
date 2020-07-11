#ifndef Stress_ball_H
#define Stress_ball_H
#include <iostream>

using namespace std;

enum class Stress_ball_colors
{
  red,
  blue,
  yellow,
  green
};

enum class Stress_ball_sizes
{
  small,
  medium,
  large
};

class Stress_ball
{
public:
  Stress_ball();
  Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) : color(c), size(s) {}
  Stress_ball_colors get_color() const;
  Stress_ball_sizes get_size() const;
  bool operator==(const Stress_ball &sb);
  bool operator>(const Stress_ball &sb);

private:
  Stress_ball_colors color;
  Stress_ball_sizes size;
};

ostream &operator<<(ostream &o, const Stress_ball &sb);

#endif