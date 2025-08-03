#ifndef PRG1_EXAMEN_IMAGE_H
#define PRG1_EXAMEN_IMAGE_H

#include <cstdint>
#include <exception>
#include <ostream>
#include <vector>

struct Color {
    uint8_t R, G, B;
};

struct Coord {
    size_t x, y;
    static const Coord origin;
};

class Image {
    size_t w, h;
    std::vector<Color> data;

public:
    Image(size_t w, size_t h, Color c) : w(w), h(h), data(w * h, c) {}

    size_t getw() const { return w; }
    size_t geth() const { return h; }

    Color const &operator[](Coord const &p) const { return data[idx(p)]; }
    Color &operator[](Coord const &p) { return data[idx(p)]; }

    Image subImage(Coord p1, size_t w, size_t h) const;

private:
    size_t idx(Coord const &p) const {
        if (p.x >= w or p.y >= h) throw std::out_of_range("Image");
        return p.x + w * p.y;
    }
};

#endif//PRG1_EXAMEN_IMAGE_H
