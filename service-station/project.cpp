#include "project.h"
#include <iostream>
using namespace std;

int Serving_queue::size = 0;

customer *node_ready(string vehcile_number) {
  customer *node = new customer;
  node->vehcile_number = vehcile_number;
  node->next = NULL;
  return node;
}

Serving_queue::Serving_queue() {
  head = NULL;
  tail = NULL;
  list = new Served_list;
}

void Serving_queue::enqueue(customer *node) {
  if (size == 10) {
    cout << "Serving queue is full!" << endl;
    return;
  }
  node->next = NULL; 

  if (!head) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
  size++;
  cout << node->vehcile_number << " added in the Serving Queue" << endl;
}

void Serving_queue::dequeue() {
  if (!head) return;
  customer *temp = head;  
  head = head->next;      
  
  if (!head) {            
      tail = NULL;
  }
  
  list->add_node(temp);   
  

  cout << temp->vehcile_number << " added in the Served List" << endl;
  size--;
}

Served_list::Served_list() {
  head = NULL;
  tail = NULL;
}

void Served_list::add_node(customer *node) {
  node->next = NULL; 
  if (!head) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

Waiting_queue::Waiting_queue() {
  head = NULL;
  tail = NULL;
  squeue = new Serving_queue;
}

void Waiting_queue::enqueue(string vehcile_number) {
  customer *node = node_ready(vehcile_number);
  

  
  if (squeue->size < 10) {
      
      squeue->enqueue(node);
  } else {
      
      if (!head) {
        head = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
      cout << node->vehcile_number << " added in the Waiting list" << endl;
  }
}

void Waiting_queue::dequeue() {
  if (!head) {
    return;
  }
  
 
  customer *temp = head;
  head = head->next;
  if (!head) tail = NULL;

  temp->next = NULL; 
  squeue->enqueue(temp);
}

void Served_list::remove_node(string vehcile_number) {
  if (!head) return;

  customer *temp = head;
  
  
  if (temp->vehcile_number == vehcile_number) {
    cout << temp->vehcile_number << " left the station" << endl;
    head = head->next;
    delete temp;
    return;
  }

  customer *lastemp = head;
  
  while (temp != NULL && temp->vehcile_number != vehcile_number) {
    lastemp = temp;
    temp = temp->next;
  }

  if (temp != NULL) {
    cout << temp->vehcile_number << " left the station" << endl;
    lastemp->next = temp->next;
    delete temp;
  }
}

void timeBasedSimulation(string arr[], int size) {
  int counter = 1, number = 0, number2 = 0;
  Waiting_queue *wQueue = new Waiting_queue;
  
  while (counter != 100) {
    
    if (number < size) {
      wQueue->enqueue(arr[number]);
      number++; 
    }

    
    if (counter % 5 == 0) {
      cout << "Time " << counter << " ";
      wQueue->squeue->dequeue(); 
      wQueue->dequeue();         
    }

    if (counter > 40) {
      if (wQueue->squeue->list->gethead() && number2 < size) {
        cout << "Time " << counter << " ";
        wQueue->squeue->list->remove_node(arr[number2]);
        number2++;
      }
    }
    counter++;
  }
}
customer *Served_list::gethead() {
  return head;
}