#include "image.sol.h"

const Coord Coord::origin{};

Image Image::subImage(Coord p1, size_t w, size_t h) const {
    // validate input
    idx(p1);
    idx(Coord{p1.x + w - 1, p1.y + h - 1});

    Image out(w, h, Color{});
    for (Coord p{0, 0}, pi{p1}; p.y < h; ++p.y, ++pi.y)
        for (p.x = 0, pi.x = p1.x; p.x < w; ++p.x, ++pi.x)
            out[p] = (*this)[pi];
    return out;
}
