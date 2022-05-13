#include <iostream>
#include <vector>
#include <iterator>


template<typename iT, typename Value>
iT stdFind(iT m_begin, iT m_end, const Value &val){
    for(; m_begin != m_end; ++m_begin){
        if(val == (*m_begin)){
            return m_begin;
        }
    }
    return m_end;
}


int main(){
    std::vector<int> vec{0,1,2,3,4};
    auto it = stdFind(vec.begin(),vec.end(),3);
    std::cout << *it;
}