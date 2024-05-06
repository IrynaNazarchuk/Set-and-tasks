#include <iostream>
#include "Set.h" 

//Iryna Nazarchuk
enum class Product { Bread, Butter, Milk, Cheese, Meat, Fish, Salt, Sugar, Tea, Water };
void print(int a) {
    switch (a)
    {
    case 0:
        std::cout << "Bread\n";
        break;
    case 1:
        std::cout << "Butter\n";
        break;
    case 2:
        std::cout << "Milk\n";
        break;
    case 3:
        std::cout << "Cheese\n";
        break;
    case 4:
        std::cout << "Meat\n";
        break;
    case 5:
        std::cout << "Fish\n";
        break;
    case 6:
        std::cout << "Salt\n";
        break;
    case 7:
        std::cout << "Sugar\n";
        break;
    case 8:
        std::cout << "Tea\n";
        break;
    case 9:
        std::cout << "Water\n";
        break;
    default:
        break;
    }
}
int main() {
    Set<Product> Assortment;
    Assortment.add(Product::Bread);
    Assortment.add(Product::Butter);
    Assortment.add(Product::Cheese);
    Assortment.add(Product::Fish);
    Assortment.add(Product::Meat);
    Assortment.add(Product::Milk);
    Assortment.add(Product::Salt);
    Assortment.add(Product::Sugar);
    Assortment.add(Product::Water);
    Assortment.add(Product::Tea);
    // Initialize Assortment with some products

    Set<Product> stores[3];
    stores[0].add(Product::Bread);
    stores[0].add(Product::Milk);
    stores[0].add(Product::Cheese);
    stores[0].add(Product::Meat);

    stores[1].add(Product::Bread);
    stores[1].add(Product::Butter);
    stores[1].add(Product::Cheese);
    stores[1].add(Product::Fish);
    stores[1].add(Product::Salt);
    stores[1].add(Product::Water);

    stores[2].add(Product::Bread);
    stores[2].add(Product::Salt);

    // Find products present in every store
    Set<Product> commonProducts = stores[0];
    for (int i = 1; i < 3; ++i) {
        commonProducts = commonProducts.intersectionWith(stores[i]);
    }

    // Find products present in at least one store
    Set<Product> unionProducts = stores[0];
    for (int i = 1; i < 3; ++i) {
        unionProducts = unionProducts.unionWith(stores[i]);
    }

    // Find products absent in all stores
    Set<Product> absentProducts = Assortment.differenceWith(unionProducts);

    std::cout << "Common Products:" << std::endl;
    for (int i = 0; i < commonProducts.getSize(); i++) {
        print((int)commonProducts[i]);
    }

    std::cout << "\nUnion Products:" << std::endl;
    for (int i = 0; i < unionProducts.getSize(); i++) {
        print((int)unionProducts[i]);
    }

    std::cout << "\nAbsent Products:" << std::endl;
    for (int i = 0; i < absentProducts.getSize(); i++) {
        print((int)absentProducts[i]);
    }

    return 0;
}

