#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefixProducts;  // Stores prefix products

public:
    // Constructor
    ProductOfNumbers() {
        prefixProducts.push_back(1); // Initialize with 1
    }

    // Adds a number to the list
    void add(int num) {
        if (num == 0) {
            // If 0 is added, reset prefix products
            prefixProducts.clear();
            prefixProducts.push_back(1);
        } else {
            // Multiply with the last prefix product
            int last = prefixProducts.back();
            prefixProducts.push_back(last * num);
        }
    }

    // Returns the product of the last k numbers
    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) {
            // It means 0 was within the last k numbers
            return 0;
        }
        return prefixProducts[n - 1] / prefixProducts[n - 1 - k];
    }
};

// Main function to test
int main() {
    ProductOfNumbers p;

    p.add(3);           // [3]
    p.add(0);           // [0] → reset
    p.add(2);           // [2]
    p.add(5);           // [2, 5]
    p.add(4);           // [2, 5, 4]

    cout << "Product of last 2: " << p.getProduct(2) << endl; // 5*4 = 20
    cout << "Product of last 3: " << p.getProduct(3) << endl; // 2*5*4 = 40
    cout << "Product of last 4: " << p.getProduct(4) << endl; // includes 0 → 0

    return 0;
}
