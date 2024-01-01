#include "Stack.h"
#include "vector"

int main()
{
    Stack<int> a({5,6,7,8,9});

   while(!a.isEmpty())
   {
        a.peek();
        std::cout<<'\n';
        a.pop();
   }
    return 0;
}