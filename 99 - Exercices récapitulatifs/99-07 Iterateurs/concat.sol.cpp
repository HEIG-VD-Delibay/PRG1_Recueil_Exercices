#include <algorithm>// for_each

using namespace std;

//------------------------------------------------------------
//    avec <algorithm>
//------------------------------------------------------------
template<typename InputIterator, typename OutputIterator>
OutputIterator concat2(InputIterator first, InputIterator last, OutputIterator result) {
    for (InputIterator itRead = first; itRead != last; ++itRead) {
        result = copy(itRead->first, itRead->second, result);
    }
    return result;
}

//------------------------------------------------------------
//    sans <algorithm>
//------------------------------------------------------------
template<typename InputIterator, typename OutputIterator>
OutputIterator concat(InputIterator first, InputIterator last, OutputIterator result) {
    while (first != last) {
        auto itRead = first->first;
        while (itRead != first->second) {
            *result = *itRead;
            ++result;
            ++itRead;
        }
        ++first;
    }
    return result;
}

//------------------------------------------------------------
template<typename InputIterator, typename OutputIterator>
OutputIterator concat3(InputIterator first, InputIterator last, OutputIterator result) {
    for (; first != last; ++first) {
        for (auto itRead = first->first;
             itRead != first->second;
             ++itRead, ++result) {
            *result = *itRead;
        }
    }
    return result;
}
