#include "Node.h"

int main()
{
    Node<int> c(6);
    Node<int> a(5,c);
    Node<int> b(4,a);

    a.setValue(56);
    // b.getNextNode()->setNextNode(&a);
    
    b.display();
    b.getNextNode()->display();
    b.getNextNode()->getNextNode()->display();

    return 0;
}