#include <iostream>
using namespace std;
// Base Class 
class MenuItem {
protected:
 string name;
 double price;
public:
 //constructor 
 MenuItem(string n, double p) {
 name = n;
 price = p;
 }
 virtual void prepareItem() = 0;
 // getter for name 
 string getName() {
 return name;
 }
 // getter for price 
 double getPrice() {
 return price;
 }
 // destructor 
 virtual ~MenuItem() {}
};
// Food Class (child class) 
class Food : public MenuItem {
public: // constructor 
 Food(string n, double p) : MenuItem(n, p) {}
 // override function 
 void prepareItem() override {
 cout << "Preparing food: " << name << endl;
 }
};
// Drink Class (child class) 
class Drink : public MenuItem {
public:
 Drink(string n, double p) : MenuItem(n, p) {} // constructor 
 void prepareItem() override {
 cout << "Preparing drink: " << name << endl;
 }
};
// Order Class 
class Order {
private:
 MenuItem* items[100]; // array to store items 
 int count;
 string status;
public: //constructor 
 Order() {
 count = 0;
 status = "Pending";
 }
 // add item function 
 void addItem(MenuItem* item) {
 if (count >= 100) {
 cout << "Order is full!\n";
 return;
 }
 items[count] = item;
 count++;
 item->prepareItem(); //polymorphism 
 cout << item->getName() << " added successfully.\n";
 }
 // show order function 
 void showOrder() {
 if (count == 0) {
 cout << "\nNo items in your order.\n";
 return;
 }
 cout << "\n======= YOUR ORDER =======\n";
 for (int i = 0; i < count; i++) {
 cout << i + 1 << ". "
 << items[i]->getName()
 << " - $" << items[i]->getPrice() << endl;
 }
 cout << "Order Status: " << status << endl;
 }
 
 // calculate bill 
 double calculateBill() {
 double total = 0;
 for (int i = 0; i < count; i++) {
 total += items[i]->getPrice();
 }
 return total;
 }
 // update status 
 void updateStatus(string s) {
 status = s;
 }
 // destructor 
 ~Order() {
 for (int i = 0; i < count; i++) {
 delete items[i];
 }
 }
};
// Restaurant Class
class Restaurant {
private:
 string restaurantName;
 Order* currentOrder;
public:
 Restaurant(string n) {
 restaurantName = n;
 currentOrder = nullptr;
 }
 void setOrder(Order* o) {
 currentOrder = o;
 }
 void showRestaurantInfo() {
 cout << "\nWelcome to " << restaurantName << "!\n";
 if (currentOrder != nullptr)
 cout << "Current order is active.\n";
 else
 cout << "No active order.\n";
 }
 ~Restaurant() {
 cout << "Restaurant Closed.\n";
 }
};
// Main 
int main() {
 Order order;
 Restaurant restaurant("CODERS Restaurant");
 restaurant.setOrder(&order);
 restaurant.showRestaurantInfo();
 int choice;
 int option;
 // menue input loop 
 // Add multiple items in one input line 
 while (true) {
 cout << "\n========== MENU ==========\n";
 cout << "1. Burger ($5)\n";
 cout << "2. Pizza ($8)\n";
 cout << "3. Cola ($2)\n";
 cout << "4. Finish Order\n";
 cout << "Choose items (example: 1 3): ";
 cin >> choice;
 if (cin.fail() || choice < 1 || choice > 4) {
 cin.clear();
 cin.ignore(1000, '\n');
 cout << "Invalid input!\n";
 continue;
 }
 if (choice == 4) {
 break;
 }
 switch (choice) {
 case 1:
 order.addItem(new Food("Burger", 5));
 break;
 case 2:
 order.addItem(new Food("Pizza", 8));
 break;
 case 3:
 order.addItem(new Drink("Cola", 2));
 break;
 }
 }
 // Order options loop 
 while (true) {
 cout << "\n====== ORDER OPTIONS ======\n";
 cout << "1. View Order\n";
 cout << "2. Calculate Bill\n";
 cout << "3. Update Status to Ready\n";
 cout << "4. Exit\n";
 cout << "Enter choice (1-4): ";
 cin >> option;
 if (cin.fail() || option < 1 || option > 4) {
 cin.clear();
 cin.ignore(1000, '\n');
 cout << "Invalid input!\n";
 continue;
 }
 switch (option) {
 case 1:
 order.showOrder();
 break;
 case 2:
 cout << "Total Bill: $" << order.calculateBill() << endl;
 break;
 case 3:
 order.updateStatus("Ready");
 cout << "Order status updated successfully.\n";
 break;
 case 4:
 cout << "Thank you for using Restaurant Ordering System!\n";
 return 0;
 }
 }
 return 0;
}