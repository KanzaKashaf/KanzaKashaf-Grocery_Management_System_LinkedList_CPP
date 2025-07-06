
# Grocery Management System

A console-based Grocery Management System developed in C++ for effective inventory, billing, and receipt handling in a retail grocery store.

---

## Project Overview

This system provides a digital solution for managing a grocery mart, supporting both **manager** and **cashier** operations. It includes:

- Inventory management
- Customer billing and receipt generation
- Sales tracking
- Loyalty program
- Role-based login system

Developed as a semester project for the **Data Structures and Algorithms** course at **National Textile University, Faisalabad**.

---

## Group Members

- **Kanza Kashaf** (22-NTU-CS-1350)  
- **Muhammad Hassaan Raza** (22-NTU-CS-1362)

---

## Features

### Manager Portal

- **Stock Management**  
  - Add, update, delete, and view products.

- **Customer and Receipt Management**  
  - View all receipts
  - Filter receipts by customer name or ID
  - View customer purchase history

- **Sales Overview**  
  - Date-wise receipt listing

### Cashier Portal

- **Order Handling**  
  - Take orders and generate receipts

- **Receipt Retrieval**  
  - View all receipts
  - Search by ID

---

## Data Structures Used

- **Doubly Linked Lists**: Used for managing products, receipts, and items in each receipt for efficient dynamic operations.

---

## File Handling

Data is persistently stored using file-based I/O in the following text files:
- `products.txt`
- `receipts.txt`
- `customers.txt`

All data is loaded into linked lists at runtime and saved back on updates.

---

## Authentication

- **Manager Login:**  
  - Username: `manager@kkmart.com`  
  - Password: `manager`

- **Cashier Login:**  
  - Username: `cashier@kkmart.com`  
  - Password: `cashier`

---

## Receipt Generation

Receipts include:
- Customer details
- List of purchased products
- Automatic loyalty discount (10%) for frequent buyers
- Timestamp

---

## How to Run

1. Clone this repository.
2. Compile all `.cpp` files with a C++17 compatible compiler (e.g., `g++`).
3. Run the compiled executable in a terminal that supports `conio.h` and `windows.h` (e.g., Windows Command Prompt or Dev-C++).
4. Navigate through the menu to login as manager or cashier.

---

## File Structure

```
--> GroceryManagementSystem
--> ProductLinkedList.h
--> ReceiptLinkedList.h
--> BUYINGPRODUCTLINKEDLIST.h
--> main.cpp
--> products.txt
--> receipts.txt
--> README.md
--> Documentation
    --> Grocery Management System Proposal
    --> Grocery Management System Documentation
    --> Grocery Management System PPT
```

---

## License

This project is for academic and educational use. No commercial use is allowed without permission.

---

## Contact

For queries or contributions:
- Kanza Kashaf: [LinkedIn](https://www.linkedin.com/in/kanza-kashaf/)
- Muhammad Hassaan Raza: [LinkedIn](https://www.linkedin.com/in/muhammad-hassaan-raza/)

---
