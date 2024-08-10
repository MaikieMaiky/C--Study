#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    string name;
    Pet(const string& name) : name(name) {}

    virtual void show()
    {
        cout << "the pet is " << name << endl;
    }
};

class Cat final : public Pet
{
public:
    Cat(const string& name) : Pet(name) {}
    void show() override final
    {
        cout << "the cat is " << name << endl;
    }
};


int main()
{
    Pet *p;
    Pet pet1("bird");
    pet1.show();
    p = &pet1;
    p->show();

    Cat cat1("miao");
    cat1.show();
    p = &cat1;
    p->show();
    Pet &p2 = cat1;
    p2.show();
}

