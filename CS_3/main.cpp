#include <iostream>
#include <memory>
#include <cassert>
#include <fstream>
enum Color {BLACK, RED, GREEN, YELLOW, WHITE};
template <typename Itemtype>
class Box{
public:
    Box(){};
protected:
    Itemtype value;
};

template <typename Itemtype>
class ToyBox : public Box<Itemtype>
{
public:
    typedef std::shared_ptr<ToyBox> Ptr;

    ToyBox(){};

    ToyBox(const Itemtype in_type, const Color in_color)
            : Box<Itemtype>(), item_(in_type), boxcolor(in_color){};

    void setItem(Itemtype in_item) {
        item_ = in_item;
        Box<Itemtype>::value = 200;
    };

    Itemtype getItem(){
        return item_;
    }

    ToyBox<Itemtype>& operator = (const ToyBox<Itemtype>& entry) {
        this->item_ = entry.item_;
        this->value = entry.value;
        this->boxcolor = entry.boxcolor;
        return *this;
    }

    Color& getColor(){
        return boxcolor;
    }

    Itemtype item_;

private:

    Color boxcolor;
};
template<typename Itemtype>
Itemtype showbox(std::unique_ptr<ToyBox<int>>& inBox){
    std::cout<< inBox->item_ <<std::endl;
}

template<typename Itemtype>
void setupbox(std::unique_ptr<ToyBox<int>>& inBox, Itemtype value){
    inBox->setItem(value);
}

#include "test_friend.h"

class B {
private:
    int number;
public:
    B(): numB(1) { }
    // friend function declaration
    friend void cleanB(B& bclass);
    friend void cleanA(A& aclass);
    int numB;
};

void cleanB(B& bclass){
    bclass.number = 0;
}

void cleanA(A& aclass){
    aclass.numA = 0;
}

int main() {
    //std::shared_ptr<ToyBox<int>> mybox = std::make_shared<ToyBox<int>>(10, Color::BLACK);
    //std::shared_ptr<ToyBox<int>> myFancy(new ToyBox<int>());

    //ToyBox<int>* mybox = new ToyBox<int>(10, Color::BLACK);
    //ToyBox<int>* newBox;

    ToyBox<int> mybox = ToyBox<int>(10, Color::BLACK);
    ToyBox<int> newBox;
    newBox = mybox;
    auto color = newBox.getColor();

    B* bc = new B();
    A* ac = new A();
    cleanA(*ac);

    Point::Ptr pptr  = std::make_shared<Point>(1,2);
    ofstream fout("/home/sean/Desktop/out.txt");
    fout << pptr << endl;

    maintemp<int>::Ptr mpr = std::make_shared<maintemp<int>>();
    auto basetype = mpr->func(1,2);

    temp<int>::Ptr basetemp = std::make_shared<temp<int>>();
    setupBoth(basetemp, 1, 2);

    Base b1(10);
    Base b2, b3, b4;
    (b2 = b3) = b1;

    Integer i(10);
    Integer i1 = (i++);
    Integer i2 = (++i);
    cout << "Pre Increment Operator" << endl;
    cout << "++Integer : " << (++i).getValue() << endl;
    return 0;
}