#ifndef project_h
#define project_h
#include <string>
using namespace std;
struct customer {
  string vehcile_number;
  customer *next;
};

class Served_list {
private:
  customer *head;
  customer *tail;

public:
  Served_list();
  void add_node(customer *node);
  void remove_node(string vehcile_number);
  customer *gethead();
};
class Serving_queue {
private:
  customer *head;
  customer *tail;

public:
  static int size;
  Served_list *list;
  Serving_queue();
  void enqueue(customer *node);
  void dequeue();
};

class Waiting_queue {
private:
  customer *head;
  customer *tail;

public:
  Serving_queue *squeue;
  Waiting_queue();
  void enqueue(string vehcile_number);
  void dequeue();
};

customer *node_ready(string vehcile_number);
void timeBasedSimulation(string arr[], int size); 

#endif