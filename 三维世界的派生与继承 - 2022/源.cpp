#include  <iostream>
#include  <cmath>
using  std::cin;
using  std::cout;
using  std::endl;
using  std::istream;
const  float  PI = 3.1415926;
class  Shape {
public:
    virtual  Shape& Input() = 0;
    virtual  float  SurfaceAera()    const = 0;
    virtual  float  Volume()    const = 0;
};

class  Cuboid : public  Shape {
protected:
    float  m_a;
    float  m_b;
    float  m_c;
public:
    Shape& Input() {
        //Çë²¹³äInputº¯Êı
        cin >> m_a >> m_b >> m_c;
        return *this;
    }
    float  SurfaceAera()  const {
        //Çë²¹³äSurfaceAreaº¯Êı
        return  2 * (m_a * m_b + m_a * m_c + m_b * m_c);

    }
    float  Volume()  const {
        //Çë²¹³äVolumeº¯Êı
        return m_a * m_b * m_c;

    }
};

class  Cube : public  Cuboid {
    //Çë²¹³äCubeÅÉÉúÀà´úÂë
private:
    float a;
public:
    Shape& Input() {
        cin >> a;
        return *this;
    }
    float  SurfaceAera()  const {
        return 6 * a * a;
    }
    float  Volume()  const {
        return a * a * a;
    }
};
class Prism :public Shape {
public:
    virtual  Shape& Input() = 0;
    virtual  float  SurfaceAera()    const = 0;
    virtual  float  Volume()    const = 0;
};
class RTPrism :public Prism {
private:
    float a; float h;
public:
    Shape& Input() {
        cin >> a >> h;
        return *this;
    }
    float  SurfaceAera()  const {
        return (sqrt(3) / 4) * a * a + (2 / 3) * a * (sqrt(a * a / 12 + h * h));
    }
    float  Volume()  const {
        return (sqrt(3) / 12) * a * a * h;
    }
};
class RCone :public Prism {
private:
    float r; float h;
public:
    Shape& Input() {
        cin >> r >> h;
        return *this;
    }
    float  SurfaceAera()  const {
        return PI * r * r + PI * r * sqrt(r * r + h * h);
    }
    float  Volume()  const {
        return PI * r * r * h / 3;
    }
};

class Sphere :public Shape {
    float r;
public:
    Shape& Input() {
        cin >> r;
        return *this;
    }
    float  SurfaceAera()  const {
        return 4 * PI * r * r;
    }
    float  Volume()  const {
        return 4 * PI * r * r * r / 3;
    }
};
//Çë²¹È«Ê£ÓàÅÉÉúÀà´úÂë


void  Display(const  Shape& sp) {
    std::cout << "SurfaceAera  =  " << sp.SurfaceAera() << std::endl
        << "Volume  =  " << sp.Volume() << std::endl;
}
void  DisplayCategory() {
    std::cout << "==================================================" <<
        std::endl;
    std::cout << "Please  input  one  of  the  following  choice:" << std::endl;
    std::cout << "\tCUBOID:    1" << std::endl;
    std::cout << "\tCUBE:        2" << std::endl;
    std::cout << "\tRTPRISM:  3" << std::endl;
    std::cout << "\tRCONE:      4" << std::endl;
    std::cout << "\tSPHERE:    5" << std::endl;
}
enum  CATEGORY { CUBOID = 1, CUBE, RTPRISM, RCONE, SPHERE }  category;
istream& operator  >>  (istream& in, CATEGORY& cat) {
    int  n = 0;
    in >> n;
    cat = static_cast<CATEGORY>(n);
    return  in;
}

int  main() {
    Cuboid  cuboid;
    Cube  cube;
    RTPrism  rtprism;
    RCone  rcone;
    Sphere  sphere;
    DisplayCategory();
    cin >> category;
    switch (category) {
    case  CUBOID:
        cout << "Please  input  (a,  b,  c)  in  order:" << endl;
        Display(cuboid.Input());
        break;
    case  CUBE:
        cout << "Please  input  (a):" << endl;
        Display(cube.Input());
        break;
    case  RTPRISM:
        cout << "Please  input  (a,  h)  in  order:" << endl;
        Display(rtprism.Input());
        break;
    case  RCONE:
        cout << "Please  input  (r,  h)  in  order:" << endl;
        Display(rcone.Input());
        break;
    case  SPHERE:
        cout << "Please  input  (r):" << endl;
        Display(sphere.Input());
        break;
    default:
        break;
    }
    return  0;
}