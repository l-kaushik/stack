#include "Stack.h"

int main()
{
    Stack<int> a(1);
   a.push(2);
   a.push(3);
   a.push(4);
   a.push(5);
   a.push(6);

   while(!a.isEmpty())
   {
        a.peek();
        std::cout<<'\n';
        a.pop();
   }
    return 0;
}