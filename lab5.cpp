#include "lab5.h"
using namespace std;

int main(int argc, char **argv)
{

    Fruit apple = Fruit("apple", 100, "red", SWEET);
    Fruit orange = Fruit("orange", 200, "orange", SWEET);
    FruitSalad salad = FruitSalad();

    salad.set_topping(SWEET);
    salad.add_fruit(apple);
    salad.add_fruit(orange);
    cout << "\nIngredients before mix:\n";
    salad.cout_fruits();
    salad.mix_ingredients();
    cout << "Ingredients after mix:\n";
    salad.cout_fruits();

    cout << "\n";
    return 0;
}