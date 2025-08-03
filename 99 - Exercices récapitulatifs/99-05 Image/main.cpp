#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    Pixel_value black = 0;
    Image image = make_image(1920, 1080, black);

    for (size_t i = 0; i < 20; ++i)
        image[200 + i][300 - i] = 65535;// dessine une ligne oblique blanche

    Kernel kernel{Pt{0, 0}, Pt{-1, 0}, Pt{1, 0}, Pt{0, 1}, Pt{0, -1}};
    Image dilated = dilate(image, kernel, black);
}
