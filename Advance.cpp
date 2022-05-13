#include <iostream>
#include <iterator>
#include <vector>


template <typename iT>
void stdadvance(iT &it, typename std::iterator_traits<iT>::difference_type count, std::input_iterator_tag){
    while(count > 0){
        --count;
        ++it;
    }
}

template <typename iT>
void stdadvance(iT &it, typename std::iterator_traits<iT>::difference_type count, std::bidirectional_iterator_tag){
    while(count > 0){
        --count;
        ++it;
    }
    while(count < 0){
        ++count;
        --it;
    }
}


template <typename iT>
void stdadvance(iT &it, typename std::iterator_traits<iT>::difference_type count, std::random_access_iterator_tag){
    it += count; 
}


template<typename iT, typename Count>
void stdAdvance(iT &it, Count count)
{
    stdadvance(it, typename std::iterator_traits<iT>::difference_type(count), typename std::iterator_traits<iT>::iterator_category());
}


int main(){

    std::vector<int> vec {0,1,2,3};
    std::vector<int>::iterator it = vec.begin();
    stdAdvance(it,2);
    std::cout << *it << " ";

}