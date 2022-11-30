#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

enum taste
{
    SWEET,
    SOUR,
    NEUTRAL
};
struct Topping
{
    enum taste taste;
};

class Fruit
{
    string name;
    int size;
    string color;
    enum taste taste;

public:
    Fruit(string name, int size, string color, enum taste taste) : name(name), size(size), color(color), taste(taste) {}
    // getters here
    string getName() { return name; }
    string getSize() { return to_string(size) + " grams"; }
    string getColor() { return color; }
    string getTaste()
    {
        switch (taste)
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
    void setName(string name) { name = name; }
    void setSize(int size) { size = size; }
    void setColor(string color) { color = color; }
    void setTaste(enum taste taste) { taste = taste; }
};

class FruitSalad
{
private:
    vector<Fruit> fruits;
    struct Topping topping;

public:
    FruitSalad(){}

    void setTopping(enum taste taste){topping.taste=taste;}
    void mixIngredients(){
        srand(time(0));
        for(int _=0; _<fruits.size(); _++)
        for(int i=0; i<fruits.size()-1; i++){
            if(rand()%2)
                swap(fruits[i], fruits[i+1]);
        }
    }
    void addFruit(Fruit fruit){fruits.push_back(fruit);}
    void coutFruits(){
        for(int i=0; i<fruits.size(); i++){
            cout << fruits[i].getName() << ", ";
        }
        cout << endl;
    }
};

int main(int argc, char **argv)
{

    Fruit apple = Fruit("apple", 100, "red", SWEET);
    Fruit orange = Fruit("orange", 200, "orange", SWEET);
    FruitSalad salad = FruitSalad(); 

    salad.setTopping(SWEET);
    salad.addFruit(apple);
    salad.addFruit(orange);
    cout<< "\nIngredients before mix:\n";
    salad.coutFruits();
    salad.mixIngredients();
    cout<< "Ingredients after mix:\n";
    salad.coutFruits();

    cout<<"\n";
    return 0;
}