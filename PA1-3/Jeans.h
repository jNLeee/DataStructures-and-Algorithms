#ifndef Jeans_H
#define Jeans_H
#include <iostream>

using namespace std;

enum class Jeans_colors
{
  white,
  blue,
  brown,
  black
};

enum class Jeans_sizes
{
  small,
  medium,
  large,
  xlarge
};

class Jeans
{
public:
  Jeans();
  Jeans(Jeans_colors c, Jeans_sizes s) : color(c), size(s) {}
  Jeans_colors get_color() const;
  Jeans_sizes get_size() const;
  bool operator==(const Jeans &j);
  bool operator>(const Jeans &j);

private:
  Jeans_colors color;
  Jeans_sizes size;
};

ostream &operator<<(ostream &o, const Jeans &j);

#endif