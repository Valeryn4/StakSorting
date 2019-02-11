#include <stack> 
#include <iostream>
#include <algorithm>
#include <utility>


template<typename T, typename Comp>
std::stack<T> sortStack(const std::stack<T> &stak, Comp comp)
{
    std::stack<T> input = stak;
    std::stack<T> helperStack;

    while (!input.empty())
    { 
        int tmp = input.top();
        input.pop();

        while (!helperStack.empty() && comp(helperStack.top(), tmp))
        {
            input.push(helperStack.top());
            helperStack.pop();
        }


        helperStack.push(tmp);
    }

    return helperStack;
}

int main()
{
    std::stack<int> noSort;

    for (int i = 0; i < 10; ++i)
    {
        int val = rand() % 100;
        std::cout << val << "\t";

        noSort.push(val);
    }

    std::cout << std::endl;

    auto sorting = sortStack(noSort, [](int a, int b) { return a < b; });

    int size = sorting.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << sorting.top() << "\t";
        sorting.pop();
    }
    std::cout << std::endl;
    system("pause");

    return 0;
}