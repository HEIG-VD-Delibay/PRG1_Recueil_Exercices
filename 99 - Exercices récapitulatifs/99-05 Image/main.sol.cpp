#include <iostream>
#include <limits>
#include <vector>

using namespace std;

using Pixel_value = unsigned short;
using Image = vector<vector<Pixel_value>>;

struct Pt {
    int x, y;
};

using Kernel = vector<Pt>;

Image make_image(size_t w, size_t h, Pixel_value v) {
    return Image(h, vector<Pixel_value>(w, v));
}

Image dilate(Image const &im,
             Kernel const &ker,
             Pixel_value default_value = numeric_limits<Pixel_value>::lowest()) {
    Image result(im);
    for (size_t y = 0; y < im.size(); ++y) {
        for (size_t x = 0; x < im[y].size(); ++x) {
            result[y][x] = numeric_limits<Pixel_value>::lowest();
            bool pas_de_voisin = true;
            for (size_t k = 0; k < ker.size(); ++k) {
                size_t nx = x + ker[k].x;
                size_t ny = y + ker[k].y;
                if (nx < im[y].size() and ny < im.size()) {
                    result[y][x] = max(result[y][x], im[ny][nx]);
                    pas_de_voisin = false;
                }
            }
            if (pas_de_voisin)
                result[y][x] = default_value;
        }
    }
    return result;
}


int main() {
    Pixel_value black = 0;
    Image image = make_image(1920, 1080, black);

    for (size_t i = 0; i < 20; ++i)
        image[200 + i][300 - i] = 65535;// dessine une ligne oblique blanche

    Kernel kernel{Pt{0, 0}, Pt{-1, 0}, Pt{1, 0}, Pt{0, 1}, Pt{0, -1}};
    Image dilated = dilate(image, kernel, black);
}
