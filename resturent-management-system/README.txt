========================================
RESTAURANT MENU MANAGEMENT SYSTEM
Using BINARY TREE and QUEUE
========================================

OVERVIEW:
---------
This restaurant management system uses:
1. BINARY TREE data structure for organizing the menu hierarchy
   - Each node has LEFT and RIGHT child pointers only
2. QUEUE data structure for managing customer orders (FIFO)

FILES INCLUDED:
---------------
1. restaurant.h   - Header file with structure definitions
2. restaurant.cpp - Implementation file with all functions
3. main.cpp       - Main program file (only function calls)

HOW TO COMPILE:
---------------
g++ -o restaurant main_binary.cpp restaurant_binary.cpp

HOW TO RUN:
-----------
./restaurant     (Linux/Mac)
restaurant.exe   (Windows)

BINARY TREE STRUCTURE:
----------------------
Unlike a general tree (which can have multiple children), our BINARY TREE
has a strict structure where each node has ONLY:
- ONE left child pointer
- ONE right child pointer

This creates the menu hierarchy:

                    Restaurant Menu (ROOT)
                   /                    \
              Fast Food               Desi Food
              /      \                /        \
         Burger    Pizza          Biryani    Karahi
         /    \      /             /    \     /    \
     Fries  Sandwich Hot Dog  Chicken Beef Chicken Mutton
                              Biryani Biryani Karahi Karahi
                                 |            |      |
                              Mutton       Chicken Seekh
                              Biryani      Tikka   Kabab
                                          /    \
                                      Malai  Nihari
                                      Boti
                                       |
                                    Haleem

FEATURES:
---------
1. Menu organized in BINARY TREE structure
2. Pre-order traversal (Root-Left-Right) for menu display
3. In-order traversal (Left-Root-Right) available
4. Order customization:
   - Spice Level: Mild, Medium, Spicy
   - Size: Small (20% off), Medium (base price), Large (50% extra)
5. Order management using FIFO Queue
6. Input validation for all user inputs

MAIN MENU OPTIONS:
------------------
1. Place Order           - Browse menu, select item, customize, confirm
2. Check Order Details   - View all orders in queue with details
3. Check Number of Orders - Display total count of pending orders
0. Exit                  - Close the program

BINARY TREE OPERATIONS:
-----------------------
1. insertLeft(parent, name, price)
   - Creates new node as left child of parent
   - If parent is NULL, creates root node

2. insertRight(parent, name, price)
   - Creates new node as right child of parent
   - Cannot be used to create root

3. displayMenuPreOrder(node, level)
   - Traversal: Root -> Left -> Right
   - Shows menu in hierarchical order

4. displayMenuInOrder(node, level)
   - Traversal: Left -> Root -> Right
   - Alternative display method

5. searchNode(node, name)
   - Recursively searches for item by name
   - Returns pointer to node if found

6. deleteNode(root, name)
   - Finds and removes node from tree
   - Also deletes all children of that node

7. findParent(root, child)
   - Locates parent node of given child
   - Used for deletion operations

QUEUE OPERATIONS:
-----------------
1. enqueue(item, spice, size, price)
   - Adds order to rear of queue
   - Assigns unique order number
   - Returns confirmation

2. dequeue()
   - Removes order from front of queue
   - FIFO (First In First Out)

3. displayOrders()
   - Shows all pending orders
   - Displays from front to rear

4. getTotalOrders()
   - Counts orders in queue

5. isEmpty()
   - Checks if queue has orders

INPUT VALIDATION:
-----------------
✓ Numeric inputs validated (only accepts valid numbers in range)
✓ Item names checked against menu tree
✓ Only actual food items can be ordered (not categories)
✓ Invalid inputs prompt user to re-enter
✓ Non-numeric input handled gracefully
✓ Out of range values rejected

EDGE CASES HANDLED:
-------------------
✓ Empty queue display
✓ Invalid menu item selection
✓ Selecting category instead of item
✓ Out of range numeric input
✓ Non-numeric input for numbers
✓ Tree traversal on empty tree
✓ Deleting non-existent node
✓ Finding parent of root node

HOW THE BINARY TREE WORKS:
--------------------------
1. Root Node:
   - Created with insertLeft(NULL, "Restaurant Menu", 0.0)
   - Has no parent

2. Adding Categories:
   - insertLeft(root, "Fast Food", 0.0)
   - insertRight(root, "Desi Food", 0.0)

3. Adding Items:
   - Get parent node reference
   - Use insertLeft() or insertRight()
   - Example: insertLeft(fastFood, "Burger", 250.0)

4. Building Hierarchy:
   - Each node can have max 2 children (left & right)
   - Creates balanced or unbalanced tree
   - Items arranged in tree structure

5. Traversing Tree:
   - Pre-order: Process root, then left, then right
   - In-order: Process left, then root, then right
   - Used to display menu or search items

EXAMPLE USAGE:
--------------
1. Run the program
2. Select option 1 (Place Order)
3. View the menu displayed using pre-order traversal
4. Enter item name exactly as shown (e.g., "Burger")
5. Select spice level (1-3)
6. Select size (1-3)
7. View order summary with calculated price
8. Confirm order (1 for Yes)
9. Order added to queue with unique order number

PRICING EXAMPLES:
-----------------
Item: Burger (Base price: Rs. 250)
- Small: Rs. 200 (20% discount → 250 × 0.8)
- Medium: Rs. 250 (base price → 250 × 1.0)
- Large: Rs. 375 (50% extra → 250 × 1.5)

Item: Chicken Biryani (Base price: Rs. 300)
- Small: Rs. 240 (20% discount → 300 × 0.8)
- Medium: Rs. 300 (base price → 300 × 1.0)
- Large: Rs. 450 (50% extra → 300 × 1.5)

WHY BINARY TREE?
----------------
1. Structured Organization:
   - Clear hierarchy (Restaurant → Categories → Items)
   - Easy to navigate

2. Efficient Search:
   - Recursively search left and right subtrees
   - O(n) worst case for unbalanced tree

3. Easy Insertion:
   - Just need parent reference
   - Insert left or right

4. Flexible Deletion:
   - Can remove entire subtrees
   - Maintains tree structure

5. Multiple Traversals:
   - Pre-order for hierarchical view
   - In-order for sorted-like view
   - Post-order for cleanup operations

MEMORY MANAGEMENT:
------------------
✓ Destructors properly clean up tree and queue
✓ No memory leaks
✓ All dynamically allocated nodes deleted
✓ Recursive deletion for tree structure

CODE STRUCTURE:
---------------
HEADER FILE (restaurant_binary.h):
- TreeNode structure (binary tree node)
- OrderItem structure (order details)
- QueueNode structure (queue node)
- MenuTree class (binary tree operations)
- OrderQueue class (queue operations)
- RestaurantSystem class (main system)

IMPLEMENTATION FILE (restaurant_binary.cpp):
- All function definitions
- Binary tree logic
- Queue logic
- User interaction logic

MAIN FILE (main_binary.cpp):
- Only main() function
- Creates RestaurantSystem object
- Calls functions based on user choice
- No other code (as per requirement)

-------------------
This code demonstrates:
1. Custom Binary Tree implementation (no STL)
2. Custom Queue implementation (no STL)
3. Tree traversals (pre-order, in-order)
4. Recursive functions (search, delete, traverse)
5. Dynamic memory allocation (new/delete)
6. Pointer manipulation
7. Input validation techniques
8. Object-oriented design (classes)
9. Modular programming (separate files)
10. Memory management (destructors)

DIFFERENCES FROM GENERAL TREE:
------------------------------
GENERAL TREE:
- Each node can have unlimited children
- Uses firstChild and nextSibling pointers
- More flexible but complex

BINARY TREE:
- Each node has max 2 children (left & right)
- Simpler pointer structure
- More constrained but easier to work with
- Standard data structure in CS courses
