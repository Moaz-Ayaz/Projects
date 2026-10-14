#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <cstring>
using namespace std;
// Structure to represent each node in the menu binary tree
struct TreeNode {
    char name[100];           
    double price;             
    TreeNode* left;           
    TreeNode* right; 
    TreeNode(const char* itemName, double itemPrice = 0.0);         
};
// QUEUE NODE STRUCTURE FOR ORDERS
// Structure to store individual order details
struct OrderItem {
    char itemName[100];       
    char spiceLevel[20];      
    char size[20];            
    double price;             
    int orderNumber;         
    // Constructor
    OrderItem();
};
// Queue node to store orders
struct QueueNode {
    OrderItem order;          
    QueueNode* next;         
    // Constructor
    QueueNode();
};
// BINARY TREE CLASS FOR MENU MANAGEMENT

class MenuTree {
private:
    TreeNode* root;           // Root of the menu binary tree
    
public:
    // Constructor
    MenuTree();
    // Destructor
    ~MenuTree();
    // Function to get root
    TreeNode* getRoot();
    // Function to insert a node (left child or right child)
    void insertLeft(TreeNode* parent, const char* name, double price);
    void insertRight(TreeNode* parent, const char* name, double price);
    // Function to display menu (pre-order traversal)
    void displayMenu(TreeNode* node, int level);
    // Function to search for a node by name
    TreeNode* searchNode(TreeNode* node, const char* name);
    // Function to delete a node
    bool deleteNode(TreeNode* root, const char* name);
    // Function to initialize menu with default items
    void initializeMenu();
    // Function to delete tree recursively
    void deleteTree(TreeNode* node);
    // Function to find parent of a node
    TreeNode* findParent(TreeNode* root, TreeNode* child);
};
// QUEUE CLASS FOR ORDER MANAGEMENT
class OrderQueue {
private:
    QueueNode* front;        
    QueueNode* rear;          
    int orderCounter;         
public:
    // Constructor
    OrderQueue();
    // Destructor
    ~OrderQueue();
    // Function to add order to queue (enqueue)
    void enqueue(const char* itemName, const char* spiceLevel, const char* size, double price);
    // Function to remove order from queue (dequeue)
    bool dequeue();
    // Function to display all orders
    void displayOrders();
    // Function to get total number of orders
    int getTotalOrders();
    // Function to check if queue is empty
    bool isEmpty();
};
// RESTAURANT MANAGEMENT CLASS
class RestaurantSystem {
private:
    MenuTree* menu;           // Menu binary tree
    OrderQueue* orders;       // Order queue
public:
    // Constructor
    RestaurantSystem();
    // Destructor
    ~RestaurantSystem();
    // Function to display main menu
    void displayMainMenu();
    // Function to place an order
    void placeOrder();
    // Function to display order details
    void displayOrderDetails();
    // Function to show total orders
    void showTotalOrders();
    // Function to browse menu
    void browseMenu();
    // Function to get spice level from user
    void getSpiceLevel(char* spiceLevel);
    // Function to get size from user
    void getSize(char* size);
    // Function to calculate price based on size
    double calculatePrice(double basePrice, const char* size);
    // Function to validate numeric input
    int getValidatedIntInput(int min, int max);
};
void OrderTaker(RestaurantSystem &restaurant);
#endif
