#include <iostream>
#include <vector>
#include <random>
#include <time.h>

enum taste
{
    SWEET,
    SOUR,
    NEUTRAL
};
struct Topping
{
    enum taste topping_taste;
};

class Fruit
{
    string name;
    int size;
    string color;
    enum taste fruit_taste;

public:
    Fruit(string name, int size, string color, enum taste fruit_taste) : name(name), size(size), color(color), fruit_taste(fruit_taste) {}
    // getters here
    string get_name()
    {
        return name;
    }
    string get_size()
    {
        return to_string(size) + " grams";
    }
    string get_color()
    {
        return color;
    }
    string get_taste()
    {
        switch (fruit_taste)
        {
        case SWEET:
            return "SWEET";
            break;
        case NEUTRAL:
            return "NEUTRAL";
            break;
        case SOUR:
            return "SOUR";
            break;
        default:
            return "NO TASTE";
        }
    }
    // setters here
    void set_name(string name)
    {
        name = name;
    }
    void set_size(int size)
    {
        size = size;
    }
    void set_color(string color)
    {
        color = color;
    }
    void set_taste(enum taste fruit_taste)
    {
        fruit_taste = fruit_taste;
    }
};

class FruitSalad
{
private:
    vector<Fruit> fruits;
    struct Topping topping;

public:
    FruitSalad() {}

    void set_topping(enum taste taste) { topping.topping_taste = taste; }
    void mix_ingredients()
    {
        srand(time(0));
        for (int repeater = 0; repeater < fruits.size(); repeater++)
            for (int i = 0; i < fruits.size() - 1; i++)
            {
                if (rand() % 2)
                    swap(fruits[i], fruits[i + 1]);
            }
    }
    void add_fruit(Fruit fruit) { fruits.push_back(fruit); }
    void cout_fruits()
    {
        for (int i = 0; i < fruits.size(); i++)
        {
            cout << fruits[i].get_name() << ", ";
        }
        cout << endl;
    }
};