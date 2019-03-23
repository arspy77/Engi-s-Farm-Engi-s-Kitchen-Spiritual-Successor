#include <iostream>
class hehe{
    int a, b; 
    public:
        virtual ~hehe() = 0;
        hehe(int a,int b){
            this->a = a;
            this->b = b;
        }
        int getA(){
            return a;
        }
        int getB(){
            return b;
        }
};

class lel : virtual public hehe{
    public:
    lel(){}
    virtual ~lel() = 0;
};

class lol : virtual public hehe{
    public:
    lol(){}
    virtual ~lol() = 0;
};

class wkwk : public lel, public lol{
    static constexpr int da{5};
    static constexpr int db {121};
    public:
        wkwk();
};

wkwk::wkwk() : hehe(da,db) {}


int main(){
    wkwk *w = new wkwk;
    std::cout << w->getA() << w->getB() << std::endl; 

}