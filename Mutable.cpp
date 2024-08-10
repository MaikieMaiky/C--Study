#include <iostream>
#include <memory>
using namespace std;

// Mutable means that the member variable can be modified in a const member function.
class Entity
{
private:
    string m_Name;
public:
    const std::string& GetName() const
    {
        // m_Name = "Cherno"; // Error: m_Name is const
        return m_Name;
    }
};

int main()
{
    std::unique_ptr<Entity> entity(new Entity());
    const Entity e;
    e.GetName();
    cout << "Hello World!" << endl;    
}