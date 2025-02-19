#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << "size of mstack " <<mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);

std::cout << "\nComparing with std::list:" << std::endl;
std::list<int> lst(mstack.begin(), mstack.end());
for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << std::endl;
}
return 0 ;
}