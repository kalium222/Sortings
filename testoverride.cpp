#include <iostream>
#include <vector>

class Complex {
private:
    int x;
    int y;

public:
    Complex(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }
    ~Complex() {}

    friend Complex operator + (const Complex &o1, const Complex &o2);

    bool operator==(const Complex &z) {
        if (this->x==z.x && this->y==z.y) return true;
        else return false;
    }

    Complex operator+(const Complex &z) {
        Complex w = Complex(this->x+z.x, this->y+z.y);
        std::cout << "Member Version" << std::endl;
        return w;
    }

};

Complex operator + (const Complex &o1, const Complex &o2){
    Complex rst;
    rst.x = o1.x + o2.x; rst.y = o1.y + o2.y;
    std::cout << "Nonmember Version" << std::endl;
    return rst;

}

int main() {
    Complex z1(1,2), z2(3,4);
    z1==z2;
    z1+z2;
    std::equal_to<Complex>();
    std::vector<int> v;
    for (int i=0; i<10; i++) {
        v.push_back(i);
    }
    v.erase(v.begin()+3);
    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}