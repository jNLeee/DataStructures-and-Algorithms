#include "Collection.h"

Collection::Collection()
{
    array = nullptr;
    size = 0;
    capacity = 0;
}
Collection::Collection(int sz)
{
    size = 0;
    capacity = sz;
    array = new Stress_ball[capacity];
}
Collection::Collection(const Collection &c) //copy constructor
{
    size = c.size;
    capacity = c.capacity;
    array = new Stress_ball[capacity];
    for (int i = 0; i < size; i++)
    {
        array[i] = c.array[i];
    }
}
Collection::Collection(Collection &&c) //move constructor
{
    size = c.size;
    capacity = c.capacity;
    array = c.array;
    c.size = 0;
    c.capacity = 0;
    c.array = nullptr;
}
Collection &Collection::operator=(const Collection &c) //copy assignment constructor
{
    if (this != &c)
    {
        if (array != nullptr && size != 0)
        {
            delete[] array;
        }
        size = c.size;
        capacity = c.capacity;
        array = new Stress_ball[capacity];
        for (int i = 0; i < size; i++)
        {
            array[i] = c.array[i];
        }
    }
    return *this;
}
Collection &Collection::operator=(Collection &&c) //move assignment
{
    if (this != &c)
    {
        if (array != nullptr)
        {
            delete[] array;
        }
        size = c.size;
        capacity = c.capacity;
        array = c.array;
        c.size = 0;
        c.capacity = 0;
        c.array = nullptr;
    }
    return *this;
}
Collection::~Collection()
{
    make_empty();
}

void Collection::insert_item(const Stress_ball &sb)
{
    if (size == capacity)
    {
        resize();
    }
    array[size] = sb;
    size++;
}

bool Collection::contains(const Stress_ball &sb) const
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == sb)
        {
            return true;
        }
    }
    return false;
}

Stress_ball Collection::remove_any_item()
{
    if (size == 0)
    {
        throw "collection is empty";
    }
    int idx = rand() % size;
    Stress_ball sb = array[idx];
    for (int i = idx; i < size - 1; i++)
    {
        array[idx] = array[idx + 1];
    }
    size -= 1;
    return sb;
}

void Collection::remove_this_item(const Stress_ball &sb)
{
    if (size == 0)
    {
        throw "collection is empty";
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] == sb)
        {
            for (int j = i + 1; i < size; i++)
            {
                array[i - 1] = array[i];
            }
        }
    }
    size -= 1;
}

void Collection::make_empty()
{
    if (array != nullptr)
    {
        delete[] array;
        size = 0;
        capacity = 0;
        array = nullptr;
    }
}

bool Collection::is_empty() const
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

int Collection::total_items() const
{
    return size;
}

int Collection::total_items(Stress_ball_sizes s) const
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i].get_size() == s)
        {
            counter++;
        }
    }
    return counter;
}

int Collection::total_items(Stress_ball_colors t) const
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i].get_color() == t)
        {
            counter++;
        }
    }
    return counter;
}

void Collection::print_items() const
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\n";
    }
}

Stress_ball &Collection::operator[](int i)
{
    return array[i];
}

const Stress_ball &Collection::operator[](int i) const
{
    return array[i];
}

void Collection::resize()
{
    capacity *= 2;
    if (capacity == 0)
    {
        capacity = 2;
    }
    Stress_ball *tmp = new Stress_ball[capacity];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = array[i];
    }
    if (array != nullptr)
    {
        delete[] array;
    }
    array = tmp;
}

istream &operator>>(istream &is, Collection &c)
{
    string color;
    string size;
    Stress_ball_colors tmpColor;
    Stress_ball_sizes tmpSizes;

    is >> color >> size;

    if (color == "red")
    {
        tmpColor = Stress_ball_colors::red;
    }
    else if (color == "blue")
    {
        tmpColor = Stress_ball_colors::blue;
    }
    else if (color == "yellow")
    {
        tmpColor = Stress_ball_colors::yellow;
    }
    else
    {
        tmpColor = Stress_ball_colors::green;
    }

    if (size == "small")
    {
        tmpSizes = Stress_ball_sizes::small;
    }
    else if (size == "medium")
    {
        tmpSizes = Stress_ball_sizes::medium;
    }
    else
    {
        tmpSizes = Stress_ball_sizes::large;
    }

    c.insert_item(Stress_ball(tmpColor, tmpSizes));

    return is;
}

ostream &operator<<(ostream &os, const Collection &c)
{
    for (int i = 0; i < c.total_items(); i++)
    {
        os << c[i];
        os << std::endl;
    }
    return os;
}

Collection make_union(const Collection &c1, const Collection &c2)
{
    int c1_sz = c1.total_items();
    int c2_sz = c2.total_items();
    Collection c3(c1_sz + c2_sz);

    for (int i = 0; i < c1_sz; i++)
    {
        c3.insert_item(c1[i]);
    }

    for (int j = 0; j < c2_sz; j++)
    {
        c3.insert_item(c2[j]);
    }

    return c3;
}

void swap(Collection &c1, Collection &c2)
{
    Collection c3(c1);
    c1 = move(c2);
    c2 = move(c3);
    //c3.make_empty();
}

void sort_by_size(Collection &c, Sort_choice sort)
{
    switch (sort)
    {
    case Sort_choice::bubble_sort:
    {
        bool swapped = false;
        while (!swapped)
        {
                swapped = true;
                for (int j = 0; (c.total_items()- 1) > j; j++)
                {
                    if (c[j] > c[j + 1])
                    {
                        Stress_ball tmp = c[j]; // swap c[j] and c[j+1]
                        c[j] = c[j + 1];
                        c[j + 1] = tmp;
                        swapped = false;
                    }
                }
        }
        break;
    }
    case Sort_choice::insertion_sort:
        for (int k = 1; c.total_items() > k; k++)
        {
            Stress_ball tmp = c[k];
            int j = k;
            for (; j > 0 && c[j - 1] > tmp; j--)
            {
                c[j] = c[j - 1];
            }
            c[j] = tmp;
        }
        break;
    case Sort_choice::selection_sort:
        for (int k = 0; (c.total_items() - 1) > k; k++)
        {
            int idx = k;
            for (int i = k + 1; c.total_items() > i; i++)
            {
                if (c[idx] > c[i])
                {
                    idx = i;
                }
            }
            Stress_ball tmp = c[k]; // swap c[k] and c[idx]
            c[k] = c[idx];
            c[idx] = tmp;
        }
        break;
    }
}
