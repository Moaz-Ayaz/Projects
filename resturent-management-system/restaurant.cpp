#include "restaurant.h"
#include <execution>
// Constructor to initialize the node
TreeNode::TreeNode(const char *itemName, double itemPrice) {
  strcpy(name, itemName);
  price = itemPrice;
  left = NULL;
  right = NULL;
}
// Constructor Initialize with dummy data.
OrderItem::OrderItem() {
  strcpy(itemName, "");
  strcpy(spiceLevel, "");
  strcpy(size, "");
  price = 0.0;
  orderNumber = 0;
}
// Constrctor - Initialize next with null.
QueueNode::QueueNode() { next = NULL; }
// BINARY TREE MENU IMPLEMENTATION
// Constructor - Initialize empty binary tree
MenuTree::MenuTree() { root = NULL; }
// Destructor - Clean up memory
MenuTree::~MenuTree() { deleteTree(root); }
// Get root node
TreeNode *MenuTree::getRoot() { return root; }
// Function to insert left child
void MenuTree::insertLeft(TreeNode *parent, const char *name, double price) {
  // Create new node
  TreeNode *newNode = new TreeNode(name, price);
  // If parent is NULL, this becomes the root
  if (parent == NULL) {
    root = newNode;
    return;
  }
  // Insert as left child
  if (parent->left == NULL) {
    parent->left = newNode;
  } else {
    cout << "Left child already exists for " << parent->name << endl;
  }
}
// Function to insert right child
void MenuTree::insertRight(TreeNode *parent, const char *name, double price) {
  // If parent is NULL, cannot insert
  if (parent == NULL) {
    cout << "Cannot insert right child without parent!\n";
    return;
  }
  // Create new node
  TreeNode *newNode = new TreeNode(name, price);
  // Insert as right child
  if (parent->right == NULL) {
    parent->right = newNode;
  } else {
    cout << "Right child already exists for " << parent->name << endl;
  }
}
// Function to display menu using pre-order traversal (root-left-right)
void MenuTree::displayMenu(TreeNode *node, int level) {
  if (node == NULL) {
    return;
  }
  // Print current node with indentation
  for (int i = 0; i < level; i++) {
    cout << "  ";
  }
  cout << "- " << node->name;
  if (node->price > 0) {
    cout << " (Rs. " << node->price << ")";
  }
  cout << endl;
  // Visit left subtree
  displayMenu(node->left, level + 1);
  // Visit right subtree
  displayMenu(node->right, level + 1);
}
// Function to search for a node by name
TreeNode *MenuTree::searchNode(TreeNode *node, const char *name) {
  if (node == NULL) {
    return NULL;
  }
  // Check if current node matches
  if (strcmp(node->name, name) == 0) {
    return node;
  }
  // Search in left subtree
  TreeNode *found = searchNode(node->left, name);
  if (found != NULL) {
    return found;
  }
  // Search in right subtree
  return searchNode(node->right, name);
}
// Function to find parent of a node
TreeNode *MenuTree::findParent(TreeNode *root, TreeNode *child) {
  if (root == NULL || child == NULL) {
    return NULL;
  }
  // Check if current node is parent
  if (root->left == child || root->right == child) {
    return root;
  }
  // Search in left subtree
  TreeNode *parent = findParent(root->left, child);
  if (parent != NULL) {
    return parent;
  }
  // Search in right subtree
  return findParent(root->right, child);
}
// Function to delete a node
bool MenuTree::deleteNode(TreeNode *node, const char *name) {
  // Search for the node to delete
  TreeNode *toDelete = searchNode(node, name);
  if (toDelete == NULL) {
    return false;
  }
  // If it's the root
  if (toDelete == root) {
    deleteTree(root);
    root = NULL;
    return true;
  }
  // Find parent of node to delete
  TreeNode *parent = findParent(root, toDelete);
  if (parent == NULL) {
    return false;
  }
  // Delete the node and update parent's pointer
  if (parent->left == toDelete) {
    parent->left = NULL;
  } else {
    parent->right = NULL;
  }
  deleteTree(toDelete);
  return true;
}
// Function to delete entire tree
void MenuTree::deleteTree(TreeNode *node) {
  if (node == NULL) {
    return;
  }
  // Delete left subtree
  deleteTree(node->left);
  // Delete right subtree
  deleteTree(node->right);
  // Delete current node
  delete node;
}
// Function to initialize menu with default items using binary tree
void MenuTree::initializeMenu() {
  // Create root - Restaurant Menu
  insertLeft(NULL, "Restaurant Menu", 0.0);
  TreeNode *restaurantRoot = getRoot();
  // Level 1: Main categories
  insertLeft(restaurantRoot, "Fast Food", 0.0);
  insertRight(restaurantRoot, "Desi Food", 0.0);
  // Get references to categories
  TreeNode *fastFood = restaurantRoot->left;
  TreeNode *desiFood = restaurantRoot->right;
  // Level 2: Fast Food subcategories
  insertLeft(fastFood, "Burger", 250.0);
  insertRight(fastFood, "Pizza", 800.0);
  TreeNode *burger = fastFood->left;
  TreeNode *pizza = fastFood->right;
  // Level 3: Fast Food items
  insertLeft(burger, "Fries", 150.0);
  insertRight(burger, "Sandwich", 200.0);
  insertLeft(pizza, "Hot Dog", 180.0);
  // pizza->right is empty (can be used for future items)
  // Level 2: Desi Food subcategories
  insertLeft(desiFood, "Biryani", 0.0);
  insertRight(desiFood, "Karahi", 0.0);
  TreeNode *biryani = desiFood->left;
  TreeNode *karahi = desiFood->right;
  // Level 3: Biryani items
  insertLeft(biryani, "Chicken Biryani", 300.0);
  insertRight(biryani, "Beef Biryani", 350.0);
  TreeNode *chickenBiryani = biryani->left;
  // Level 4: More Biryani options
  insertLeft(chickenBiryani, "Mutton Biryani", 400.0);
  // Level 3: Karahi items
  insertLeft(karahi, "Chicken Karahi", 500.0);
  insertRight(karahi, "Mutton Karahi", 600.0);
  TreeNode *chickenKarahi = karahi->left;
  // Level 4: BBQ items under Chicken Karahi
  insertLeft(chickenKarahi, "Chicken Tikka", 250.0);
  insertRight(chickenKarahi, "Seekh Kabab", 200.0);
  TreeNode *chickenTikka = chickenKarahi->left;
  // Level 5: More items
  insertLeft(chickenTikka, "Malai Boti", 280.0);
  insertRight(chickenTikka, "Nihari", 450.0);
  TreeNode *malaiBoti = chickenTikka->left;
  // Level 6: Final items
  insertLeft(malaiBoti, "Haleem", 300.0);
}
// ORDER QUEUE IMPLEMENTATION
// Constructor - Initialize empty queue
OrderQueue::OrderQueue() {
  front = NULL;
  rear = NULL;
  orderCounter = 1; // Start order numbers from 1
}
// Destructor - Clean up memory
OrderQueue::~OrderQueue() {
  while (!isEmpty()) {
    dequeue();
  }
}
// Function to add order to queue
void OrderQueue::enqueue(const char *itemName, const char *spiceLevel,
                         const char *size, double price) {
  // Create new queue node
  QueueNode *newNode = new QueueNode();
  // Fill order details
  strcpy(newNode->order.itemName, itemName);
  strcpy(newNode->order.spiceLevel, spiceLevel);
  strcpy(newNode->order.size, size);
  newNode->order.price = price;
  newNode->order.orderNumber = orderCounter;
  orderCounter++;
  // If queue is empty
  if (rear == NULL) {
    front = rear = newNode;
    cout << "\n*** Order #" << newNode->order.orderNumber
         << " placed successfully! ***\n";
    return;
  }
  // Add to rear of queue
  rear->next = newNode;
  rear = newNode;
  cout << "\n*** Order #" << newNode->order.orderNumber
       << " placed successfully! ***\n";
}
// Function to remove order from queue
bool OrderQueue::dequeue() {
  // Check if queue is empty
  if (isEmpty()) {
    return false;
  }
  // Store front node
  QueueNode *temp = front;
  // Move front pointer
  front = front->next;
  // If queue becomes empty
  if (front == NULL) {
    rear = NULL;
  }
  // Delete the node
  delete temp;
  return true;
}
// Function to display all orders in queue
void OrderQueue::displayOrders() {
  if (isEmpty()) {
    cout << "\nNo orders in queue!\n";
    return;
  }
  cout << "         CURRENT ORDERS QUEUE\n";
  QueueNode *temp = front;
  int count = 1;
  while (temp != NULL) {
    cout << "\nOrder #" << temp->order.orderNumber << ":\n";
    cout << "  Item: " << temp->order.itemName << endl;
    cout << "  Spice Level: " << temp->order.spiceLevel << endl;
    cout << "  Size: " << temp->order.size << endl;
    cout << "  Price: Rs. " << temp->order.price << endl;
    temp = temp->next;
    count++;
  }
}
// Function to get total number of orders
int OrderQueue::getTotalOrders() {
  int count = 0;
  QueueNode *temp = front;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}
// Function to check if queue is empty
bool OrderQueue::isEmpty() { return (front == NULL); }
// RESTAURANT SYSTEM IMPLEMENTATION
// Constructor
RestaurantSystem::RestaurantSystem() {
  menu = new MenuTree();
  orders = new OrderQueue();

  // Initialize menu with default items
  menu->initializeMenu();
}
// Destructor
RestaurantSystem::~RestaurantSystem() {
  delete menu;
  delete orders;
}
// Function to display main menu
void RestaurantSystem::displayMainMenu() {
  cout << "    WELCOME TO SMN RESTAURANT\n";
  cout << "1. Place Order\n";
  cout << "2. Check Order Details\n";
  cout << "3. Check Number of Orders\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
}
// Function to place an order
void RestaurantSystem::placeOrder() {
  cout << "           RESTAURANT MENU\n";
  cout << "         (Binary Tree Structure)\n";
  // Display the menu using pre-order traversal
  menu->displayMenu(menu->getRoot(), 0);
  // Get item name from user
  char itemName[100];
  cout << "\n\n\n";
  cout << "=========================================================\n";
  cout << "Assalam-o-Alaikum Sir, My name is Sameer Ahmed I am your \norder "
          "taker Decide your order i will be back in 2 mins.\n";
  cout << "=========================================================\n";
  cout << "\n\n\n";
  cout << "Enter the name of the item you want to order: ";
  cin.ignore();
  cin.getline(itemName, 100);
  // Search for the item in menu
  TreeNode *item = menu->searchNode(menu->getRoot(), itemName);
  // Check if item exists and has a price (is an actual food item)
  if (item == NULL) {
    cout << "\nSorry, item not found in menu!\n";
    return;
  }
  if (item->price <= 0) {
    cout << "\nThis is a category, not an item. Please select an actual food "
            "item.\n";
    return;
  }
  // Get spice level
  char spiceLevel[20];
  getSpiceLevel(spiceLevel);
  // Get size
  char size[20];
  getSize(size);
  // Calculate final price based on size
  double finalPrice = calculatePrice(item->price, size);
  // Display order summary
  cout << "         ORDER SUMMARY\n";
  cout << "Item: " << itemName << endl;
  cout << "Spice Level: " << spiceLevel << endl;
  cout << "Size: " << size << endl;
  cout << "Total Price: Rs. " << finalPrice << endl;
  // Confirm order
  cout << "\nConfirm order? (1 for Yes, 0 for No): ";
  int confirm = getValidatedIntInput(0, 1);
  if (confirm == 1) {
    // Add order to queue
    orders->enqueue(itemName, spiceLevel, size, finalPrice);
  } else {
    cout << "\nOrder cancelled!\n";
  }
}
// Function to display order details
void RestaurantSystem::displayOrderDetails() { orders->displayOrders(); }
// Function to show total orders
void RestaurantSystem::showTotalOrders() {
  int total = orders->getTotalOrders();
  cout << "Total number of orders in queue: " << total << endl;
}
// Function to browse menu
void RestaurantSystem::browseMenu() {
  cout << "           RESTAURANT MENU\n";
  menu->displayMenu(menu->getRoot(), 0);
}
// Function to get spice level from user
void RestaurantSystem::getSpiceLevel(char *spiceLevel) {
  cout << "\nSelect Spice Level:\n";
  cout << "1. Mild\n";
  cout << "2. Medium\n";
  cout << "3. Spicy\n";
  cout << "Enter choice: ";
  int choice = getValidatedIntInput(1, 3);
  if (choice == 1) {
    strcpy(spiceLevel, "Mild");
  } else if (choice == 2) {
    strcpy(spiceLevel, "Medium");
  } else {
    strcpy(spiceLevel, "Spicy");
  }
}
// Function to get size from user
void RestaurantSystem::getSize(char *size) {
  cout << "\nSelect Size:\n";
  cout << "1. Small\n";
  cout << "2. Medium\n";
  cout << "3. Large\n";
  cout << "Enter choice: ";
  int choice = getValidatedIntInput(1, 3);
  if (choice == 1) {
    strcpy(size, "Small");
  } else if (choice == 2) {
    strcpy(size, "Medium");
  } else {
    strcpy(size, "Large");
  }
}
// Function to calculate price based on size
double RestaurantSystem::calculatePrice(double basePrice, const char *size) {
  if (strcmp(size, "Small") == 0) {
    return basePrice * 0.8; // 20% discount for small
  } else if (strcmp(size, "Medium") == 0) {
    return basePrice;       // Base price for medium
  } else {                  // Large
    return basePrice * 1.5; // 50% extra for large
  }
}
// Function to validate numeric input
int RestaurantSystem::getValidatedIntInput(int min, int max) {
  int input;
  while (true) {
    cin >> input;

    // Check if input is valid
    if (cin.fail()) {
      // Clear error flag
      cin.clear();
      // Discard invalid input
      cin.ignore(1000, '\n');
      cout << "Invalid input! Please enter a number between " << min << " and "
           << max << ": ";
    } else if (input < min || input > max) {
      cout << "Out of range! Please enter a number between " << min << " and "
           << max << ": ";
    } else {
      // Valid input
      return input;
    }
  }
}
void OrderTaker(RestaurantSystem &restaurant) {
  int choice;
  bool flag = false;
  while (!flag) {
    // Display main menu
    restaurant.displayMainMenu();
    // Get user choice with validation
    choice = restaurant.getValidatedIntInput(0, 3);
    // Process user choice
    if (choice == 1) {
      // Place order
      restaurant.placeOrder();
    } else if (choice == 2) {
      // Check order details
      restaurant.displayOrderDetails();
    } else if (choice == 3) {
      // Check number of orders
      restaurant.showTotalOrders();
    } else if (choice == 0) {
      // Exit
      cout << " Thank you for visiting SMN restaurant!\n";
      cout << "        Have a great day!\n";
      flag = true;
    }
  }
}
