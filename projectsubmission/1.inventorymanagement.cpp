// Array:
// 1. Inventory Management System:
// - Design an inventory management system for a any small business. Use
// an array to store the quantity of different products in stock. Implement
// functionalities to add products (quantity of product), update quantities,
// display the current inventory.
// - Perform inventory management functionalities and alert when a product
// is running low on stock.
// Note:
// - Each element in the array represents a different product.
// - Allow the addition and removal of products dynamically.
#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;

struct Product {
    string name;
    int quantity;
};

void addProduct(Product inventory[], int& numProducts);
void updateProduct(Product inventory[], int numProducts);
void displayInventory(const Product inventory[], int numProducts);
void checkLowStock(const Product inventory[], int numProducts);

int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0;
    char choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Display Inventory\n";
        cout << "4. Check Low Stock\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                addProduct(inventory, numProducts);
                break;
            case '2':
                updateProduct(inventory, numProducts);
                break;
            case '3':
                displayInventory(inventory, numProducts);
                break;
            case '4':
                checkLowStock(inventory, numProducts);
                break;
            case '5':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}

void addProduct(Product inventory[], int& numProducts) {
    if (numProducts >= MAX_PRODUCTS) {
        cout << "Inventory is full. Cannot add more products.\n";
        return;
    }

    cout << "Enter product name: ";
    cin >> inventory[numProducts].name;
    cout << "Enter quantity: ";
    cin >> inventory[numProducts].quantity;
    numProducts++;
}

void updateProduct(Product inventory[], int numProducts) {
    if (numProducts == 0) {
        cout << "Inventory is empty. Cannot update products.\n";
        return;
    }

    string productName;
    cout << "Enter the name of the product to update: ";
    cin >> productName;

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].name == productName) {
            cout << "Enter new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Quantity updated successfully.\n";
            return;
        }
    }

    cout << "Product not found in inventory.\n";
}

void displayInventory(const Product inventory[], int numProducts) {
    if (numProducts == 0) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "Current Inventory:\n";
    cout << "-----------------\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "Product: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << endl;
    }
}

void checkLowStock(const Product inventory[], int numProducts) {
    if (numProducts == 0) {
        cout << "Inventory is empty.\n";
        return;
    }

    const int LOW_STOCK_THRESHOLD = 10; 
    bool lowStock = false;

    cout << "Low Stock Items:\n";
    cout << "----------------\n";
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].quantity < LOW_STOCK_THRESHOLD) {
            cout << "Product: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << endl;
            lowStock = true;
        }
    }

    if (!lowStock) {
        cout << "No low stock items.\n";
    }
}
