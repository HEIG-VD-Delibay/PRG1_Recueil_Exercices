#include <algorithm>// for_each
#include <iterator> // distance

using namespace std;


//------------------------------------------------------------
//    avec <algorithm>
//------------------------------------------------------------
template<typename InputIterator>
size_t total_size2(InputIterator first, InputIterator last) {
    size_t size = 0;
    for_each(first, last, [&size](auto p) { size += (size_t) distance(p.first, p.second); });
    return size;
}

//------------------------------------------------------------
//    sans <algorithm>
//------------------------------------------------------------
template<typename InputIterator>
size_t total_size(InputIterator first, InputIterator last) {
    size_t size = 0;
    for (InputIterator it = first; it != last; ++it) {
        size += distance(it->first, it->second);
    }
    return size;
}

template<typename InputIterator>
size_t total_size3(InputIterator first, InputIterator last) {
    size_t size = 0;
    for (InputIterator it = first; it != last; ++it) {
        size += size_t(it->second - it->first);
    }
    return size;
}
