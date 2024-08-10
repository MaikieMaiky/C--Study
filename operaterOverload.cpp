#include <iostream>
using namespace std;

class Entity
{
public:
    int x;
    int y;

    explicit Entity(int x, int y) : x(x) , y(y) {}

    Entity Add(const Entity& other) const
    {
        return Entity(x + other.x, y + other.y);
    }

    Entity operator+(const Entity& other) const
    {
        return Add(other);
    }

    Entity Multiple(const Entity& other) const
    {
        return Entity(x * other.x, y * other.y);
    }

    Entity operator*(const Entity& other) const
    {
        return Multiple(other);
    }

    void Print() const
    {
        cout << x << ", " << y << endl;
    }

    
};


int main()
{
    Entity e1(1, 2);
    Entity e2(2, 3);
    Entity e3 = e1 * e2;
    e3.Print();
}