#include "Header.h"

int main()
{
    Node* head = NULL;
    FirstAdd(&head, 13.5);
    FirstAdd(&head, 5.5);
    FirstAdd(&head, 333);
    FirstAdd(&head, 2.5);
    FirstAdd(&head, 1.57);
    FirstAdd(&head, 23);
    FirstAdd(&head, 214.5);
    PrintList(head);
    cout << endl;
    double average = Average(head);
    cout << average << endl;
    cout << ElementsLessAverage(head, average) << endl;
    cout << FindMax(&head);
    cout << "\n" << endl;
    DeleteToMax(&head);
    PrintList(head);
}
