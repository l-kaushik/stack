#include "Stack.h"
#include <string>

int main()
{
    Stack<std::string> a({"Hello","how","are","you","?"});
    Stack<std::string> b(a);
// TODO : implement clear();

   while(!b.isEmpty())
   {
        b.peek();
        std::cout<<'\n';
        b.pop();
   }
    return 0;
}