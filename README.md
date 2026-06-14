# Restaurant Ordering System (C++)

A simple restaurant ordering application developed in C++ using Object-Oriented Programming (OOP) principles.

## Overview

The Restaurant Ordering System is a console-based C++ application that simulates a restaurant ordering process. Customers can select food and drink items from a menu, add items to an order, view their order, calculate the total bill, and update the order status.

This project was developed to demonstrate the practical implementation of Object-Oriented Programming concepts in C++.

---

## Objectives

* Create a menu-driven restaurant ordering system.
* Allow customers to add food and drink items to an order.
* Calculate the total bill automatically.
* Manage and update order status.
* Demonstrate core OOP principles in C++.

---

## Features

* Interactive menu system
* Food and drink item management
* Order creation and tracking
* Automatic bill calculation
* Order status updates
* Dynamic memory management
* Object-Oriented design

---

## OOP Concepts Used

### Encapsulation

Data members are stored inside classes and accessed through public methods.

### Inheritance

The `Food` and `Drink` classes inherit from the `MenuItem` base class.

### Polymorphism

Virtual functions and method overriding are used to prepare different menu items.

### Abstraction

`MenuItem` is implemented as an abstract class using a pure virtual function.

### Constructors and Destructors

Constructors initialize object data, while destructors clean up dynamically allocated memory.

---

## Class Structure

### MenuItem

Abstract base class representing a general menu item.

**Attributes**

* Name
* Price

**Functions**

* `getName()`
* `getPrice()`
* `prepareItem()`

### Food

Derived class representing food items.

### Drink

Derived class representing drink items.

### Order

Handles:

* Adding items
* Displaying orders
* Calculating bills
* Updating order status

### Restaurant

Stores restaurant information and manages active orders.

---

## Program Workflow

1. Create a restaurant and order object.
2. Display restaurant information.
3. Show menu options.
4. Allow customers to select items.
5. Add selected items to the order.
6. Display order management options.
7. View order details or calculate the bill.
8. Update order status.
9. Exit the program.

---

## Sample Menu

```text
1. Burger ($5)
2. Pizza ($8)
3. Cola ($2)
4. Finish Order
```

---

## Sample Output

```text
Welcome to CODERS Restaurant!

Preparing food: Burger
Burger added successfully.

Preparing drink: Cola
Cola added successfully.

======= YOUR ORDER =======

1. Burger - $5
2. Cola - $2

Order Status: Pending

Total Bill: $7

Order status updated successfully.
```

---

## Advantages

* Easy to understand and use
* Demonstrates major OOP concepts
* Modular design
* Dynamic memory management
* Easy to extend with additional features

---

## Future Enhancements

* Save orders to files
* Add customer accounts
* Add item quantities
* Add payment processing
* Use STL vectors instead of fixed arrays
* Database integration
* Graphical User Interface (GUI)
* Automatic receipt generation

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Dynamic Memory Allocation

---

## Author

**Mustafa Khalid**

Computer Science Student : SoftWare Enginner.

Developed as an academic project to demonstrate Object-Oriented Programming concepts in C++.
