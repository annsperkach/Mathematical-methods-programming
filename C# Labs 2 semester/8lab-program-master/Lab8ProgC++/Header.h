#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node
{
public:
    Node* next;
    Node* previous;
    double data;
};

void FirstAdd(Node** head, double NewElement) {

    Node* new_node = new Node();
    new_node->data = NewElement;

    new_node->next = (*head);
    new_node->previous = NULL;

    if ((*head) != NULL)
        (*head)->previous = new_node;
    (*head) = new_node;
}

int Size(Node* node) {
    int res = 0;
    while (node != NULL) {
        res++;
        node = node->next;
    }
    return res;
}
double Average(Node* node) {
    double average = 0;
    int size = Size(node);
    while (node != NULL) {
        average += node->data;
        node = node->next;
    }
    average = average / size;
    return average;
}

int  ElementsLessAverage(Node* node, double average) {
    int count = 0;
    while (node != NULL) {
        if (node->data < average)
            count++;
        node = node->next;
    }
    return count;
}

void Delete(class Node** head, Node* del) {
    if (*head == NULL || del == NULL)
        return;

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->previous = del->previous;

    if (del->previous != NULL)
        del->previous->next = del->next;
    free(del);
    return;
}

double FindMax(Node** head) {
    class Node* max, * temp;
    temp = max = *head;
    while (temp != NULL) {
        if (temp->data > max->data)
            max = temp;
        temp = temp->next;
    }
    return max->data;
}
void DeleteToMax(Node** head)
{
    double max = FindMax(head);
    Node* ptr = *head;
    Node* previous;
    while (ptr->data != max) 
    {
        previous = ptr->next;
        ptr = previous;
    }
    previous = ptr->previous;
    ptr = previous;
    while (ptr != NULL)
    {
        previous = ptr->previous;
        Delete(head, ptr);
        ptr = previous;
    }
}

void PrintList(Node* node)
{
    Node* last = new Node();
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
}