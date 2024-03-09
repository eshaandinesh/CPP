#include <iostream>
#include <cmath>

using namespace std;

class Coords
{
    int x, y;

public:
    Coords()
    {
        x = 0;
        y = 0;
    }
    Coords(int x)
    {
        this->x = x;
        y = 0;
    }
    Coords(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    float dist(Coords c1, Coords c2)
    {
        return (sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2)));
    }
};

int main()
{
    int x, y;
    cout << "Enter the first points coordinates: " << endl;
    cin >> x >> y;
    Coords c1(x, y);
    Coords c2(10);
    float d = c1.dist(c1, c2);
    cout << "The distance between them is: " << d << endl;

    return 0;
}
