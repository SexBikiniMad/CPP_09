
#include "PmergeMe.hpp"

int main(int av, char **ac)
{
    PmergeMe Pmerge;
    int number = 0;
    
    if(av < 2) {
        std::cout << "Usage : ./PmergeMe Numbers" << std::endl;
        return (1);
    }
    for(int i = 1; i < av; i++) {
        if(Pmerge.checkElement(ac[i]) == 1)
            return (1);
        number = atoi(ac[i]);
        Pmerge.setDeque(number);
        Pmerge.setList(number);
    }
    {
        struct timeval timeBeforeSort, timeAfterSort;
        std::deque<int> deque = Pmerge.getDeque();
        std::cout << "Before: (deque) ";
        Pmerge.printArray(deque);
        gettimeofday(&timeBeforeSort, NULL);
        deque = Pmerge.sortDeque(deque);
        gettimeofday(&timeAfterSort, NULL);
        std::cout << "After: (deque) ";
        Pmerge.printArray(deque);
        long microseconds = timeAfterSort.tv_usec - timeBeforeSort.tv_usec;
        std::cout <<  "Time to process a range of " << deque.size() << " elements with std::deque : " << microseconds << " us" << std::endl;
        std::cout << std::endl;
    }
    {
        struct timeval timeBeforeSort, timeAfterSort;
        std::list<int> list = Pmerge.getList();
        std::cout <<  "Before: (list) ";
        Pmerge.printArray(list);
        gettimeofday(&timeBeforeSort, NULL);
        list = Pmerge.sortList(list);
        gettimeofday(&timeAfterSort, NULL);
        std::cout <<  "After: (list) ";
        Pmerge.printArray(list);
        long microseconds = timeAfterSort.tv_usec - timeBeforeSort.tv_usec;
        std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << microseconds << " us" << std::endl;
    }
    return (0);
}