// usedmaabc.cpp

#include <iostream>
#include "dmaabc.h"

int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portrabelly", 8);
    lacksDMA balloon("red", "Blumpo", 4);
    hasDMA map("Mercator", "Buffalo Kyes", 5);
    shirt.View();
    balloon.View();
    map.View();
    lacksDMA balloon2(balloon);
    hasDMA map2;
    map2 = map;
    balloon2.View();
    map2.View();

    ABC* pts[3];
    pts[0] = &shirt;
    pts[1] = &balloon;
    pts[2] = &map;

    for (int i = 0; i < 3; ++i)
        pts[i]->View();

    return 0;
}
