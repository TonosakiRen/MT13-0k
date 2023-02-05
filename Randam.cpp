#include "Randam.h"
int Randam::RAND(int min, int max) {
    if (min == 0 && max == 0) {
        return 0;
    }
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
float Randam::RAND(float min, float max) {
    if (min == 0 && max == 0) {
        return 0;
    }
    int kmin = min * 1000;
    int kmax = max * 1000;

    float result = (kmin + (int)(rand() * (kmax - kmin + 1.0) / (1.0 + RAND_MAX))) / 1000.0f ;
    return result;
}

unsigned int Randam::ColorRAND() {
    unsigned int tmpR = static_cast<unsigned int>( Randam::RAND(0, 255));
    unsigned int tmpG = static_cast<unsigned int>(Randam::RAND(0, 255));
    unsigned int tmpB = static_cast<unsigned int>(Randam::RAND(0, 255));
    unsigned int tmp = tmpR << 4 * 6;
    tmp = tmp + (tmpG << 4 * 4);
    tmp = tmp + (tmpB << 4 * 2);
    tmp = tmp + 0xFF;
    return tmp;
}

void Randam::SRAND() {
    srand((unsigned)time(NULL));
}