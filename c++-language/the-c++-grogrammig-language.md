# 函数指针
1. 1. 定义形式
    类型名（*指针变量名）（蚕食类型1，参数类型2，···）；

    例如：
    ```c
    int (*pf)(int ,char);
    ```
    表示pf是一个函数指针，它所指向的函数，返回值类型应是int，该函数应有两个参数，第一个是int类型，第二个是char类型。

    2. 使用方法

    可以用一个原型匹配的函数的名字给一个函数指针赋值。

    要通过函数指针调用它所指向的函数，写法为：

    函数指针名（实参表）；

    例题1；

2. 函数指针和qaort库函数

    c语言快速排序库函数：

        ```c
        void qsort(void*base,int nelem,unsigned int width, int (* pfCompare)(const void*,const void*));
        ```
    base：待排序数组的起始地址
    nelem：待排序数组的元素个数
    width：待排序数组的每个元素的大小（以字节为单位）
    pfCompare：比较函数的地址

    可以对任意类型的数组进行排序

    对数组排序，需知道：

        1. 数组起始地址
        2. 数组元素的个数
        3. 没个元素的大小（由此可以计算出每个元素的地址）
        4. 元素谁在前谁在后的规则

    ```c
    int pfCompare(const void * elem1,const void * elem2);
    ```

    比较函数编写规则：
        1. 如果* elem1 应该排在* elem2前面，则函数返回值是负整数
        2. 如果 * elem1和 * elem2哪个排在前面都行，那么函数返回0
        3. 如果 * elem1 应该排在* elem2后面，则函数返回值是正整数

    例题2；
# 命令行参数

将用户在CMD窗口输入可执行文件名的方式启动程序是，跟在可执行文件名后面的那些字符串，称为“命令行参数”。命令行参数可以有多个，以空格分隔。
例：
```c
copy  file.txt file2.txt
int main(int argc, char * argv[]){
    ...
}
```

argc：代表启动程序时，命令行参数的个数，argc的值至少是1.
argv：指针数组，其中的每个元素都是一个char*类型的指针，该指针指向一个字符串，这个字符串里就存放着命令行参数。
# 位运算
位运算：用于对整数类型变量中的某一位，或若干位进行操作：

 1. 判断某一位是否为1
 2. 只改变其中某一位，而保持其他位都不变。

六种位运算符来进行操作运算操作：
    &:按位与（双目）

    |：按位或（双目）

    ~：按位非（取反）（单目）

    ^：按位异或（双目）

    <<：左移（双目）

    >>：右移（双目）

 1. 按位与"&"
    将参与运算额度两操作数各对应的二进制位进行与操作，只有对应的两个二进位均为1时，结果的对应二进制位才为1，否则为0.

    通常用来将某变量中的某些位清0且同时保留其他位不变。也可以用来获取变量中的某一位。

2. 按位或"|"

   将参与运算的两操作数对应的二进制位进行或操作，只有对应的两个二进制位都为0时，结果的对应二进制位才是0，否则都为1

    将位或运算通常用来将某些变量中的某些位置1且保留其他位不变。

3. 按位异或"^"

    将参与运算的两操作数各对应的二进制位进行异或操作，即只有对应的两个二进位不同时，结果的对应二进制位才是1，否则位0。

    按位异或运算通常用来将某些变量中的某些位取反，且保留其他位不变。

    如果a^b=c,那么就有c^b=a 以及c^a=b。

    另外异或运算还能实现不通过临时变量，就能交换两个变量的值

4. 按位非"~"

    按位非运算符"~"是单目运算符。其功能是将操作数中的二进制位0变成1，1变成0.

5. 左移运算符"<<"

    表达式：
    a << b
    的值是：将a各二进位全部左移 b 位后得到的值。左移是，高位丢弃，低位补0.a的值不因运算而改变

6. 右移运算符">>"
    表达式：
    a>>b
    的值是：将 a各二进位全部右移b位后得到的值。右移时，移出最右边的位就被丢弃。a的值不因运算而改变。

    如果原符号位为1，则右移时高位就补充1，原符号位为0，则右移时高位就补充0.

    实际上，右移n位，就相当于左操作数除以2的n次方，并且将结果往小里取整
# 引用
引用的概念

    下面的写法定义了一个引用，并将其初始化为引用某个变量。

    类型名 & 引用名 = 某变量名；

    ```c
    int n = 4;
    int &r = n; //r引用了n，r的类型是int &
    ```

 某个变量的引用，等价于这个变量，相当于该变量的一个别名。

 注意：
 1. 定义引用是一定要将其初始化成引用某个变量
 2. 初始化后，它就一直引用改变量，不会再引用别的变量了。
 3. 引用只能引用变量，不能引用常量和表达式。

常引用

定义引用时，前面加const关键字，即为“常引用”

```c
int n;
const int & r = n;
```

r 的类型是const int &

常引用和非常引用的转换

const T & 和T & 是不同的类型

T & 类型的引用或T类型的变量可以用来初始化const T & 类型的引用。

const T 类型的常变量和const T & 类型的引用则不能用来初始化T &类型的引用，除非进行强制类型转换。

# const 关键字的用法

1. 常量的定义
```c
    const int max_val = 23;
    const double pi = 3.14;
    const char * school_name = "peking university";
```
2. 定义常量指针

    1. 不可通过常量指针修改其指向的内容
    2. 不能把常量指针赋值给非常量指针，反过来可以
    3. 函数参数为常量指针式，可避免函数内部不小心改变参数指针所致地方的内容
    4. 不能通过常引用修改其引用的变量

# 动态内存分配

用new运算符实现动态内存分配

 1. 第一种用法，分配一个变量：

  ```c
    p = new t;
  ```

  t 是任意类型名，p是类型为t * 的指针。

  动态分配出一片大小为sizeof(t)字节的内存空间，并且将该内存空间的起始地址赋值给p。
  ```c
    int * pn;
    pn = new int;
    * pn = 5;
  ```
 2. 第二种用法，分配一个数组：
    ```c
    p = new t[n];
    ```

  t：任意类型名
  p：类型t * 的指针
  n：要分配的数组元素的个数，可以是整型表达式

  动态分配出一片大小为 n * sizeof(t)字节的内存空间，并且将该内存空间的起始地址赋值给p。

new 运算符的返回值类型：

```c
new t;
new t[n];
```

这两个表达式返回值类型都是t *

用delete 运算符释放动态分配的内存

    用"new"动态分配的内存空间，一定要用"delete"运算符进行释放

    delete 指针；该指针必须指向new出来的空间

    ```c
    int *p = new int;
    * p = 5;
    delete p;
    ```

    用"delete"释放动态分配的数组，要加"[]"

    delete []指针;// 该指针必须指向new出来的数组

    ```c
    int * p = new int [20];
    p[0] = 1;
    delete [] p;
    ```
# 内联函数和重载函数

内联函数：

 1. 函数调用是有时间开销的。如果函数本身只有几条语句，执行非常快，而且函数被反复执行很多次，相比之下调用函数所产生的这个开销就会显得比较大。

 2. 为了减少函数调用的开销，引入了内联函数机制。编译器处理对内联函数的调用语句时，是将整个函数的代码插入到调用语句处，而不会产生调用函数的语句

 3. 在函数定义前面加"inline"关键字，即可定义内联函数
 ```c
 inline int max(int a, int b) {
    if(a > b) return a;
    return b;
 }
 ```

 函数重载：

 1. 一个或多个函数，名字相同，然而参数个数或参数类型不相同，这就叫做函数的重载

 2. 函数重载使得函数命名变得简单

 3. 编译器根据调用语句的中的实参的个数和类型判断应该调用哪个函数

# 函数的缺省参数

定义函数的时候可以让最右边的连续若干个参数有缺省值，那么调用函数的时候，若相应位置不写参数，参数就是缺省值

```c
void func(int x1, int x2 = 2, int x3 = 3){}
func(10);
func(10, 8);
func(10, , 8);//只能是最右边的函数缺省
```

1. 函数参数可缺省的目的在于提高程序的可扩充性

2. 即如果某个写好的函数添加新的参数，而原先那些调用该函数的语句，未必需要使用新增的参数，那么为了避免对原先那些函数调用语句的修改，就可以使用缺省参数。

# 面向对象程序设计方法

结构化程序设计
  1. 复杂的大问题-层层分解/模块化-若干个子问题
  2. 程序=数据结构+算法

类的定义

class类名 {
    访问范围说明符：
        成员变量1
        成员变量2
        ···
}

# 从客观事物抽象出类的例子
对象的内存分配

1. 对象的内存空间
  对象的大小=所有成员变量的大小之和
2. 每个对象个字有自己的存储空间
  一个对象的某个成员变量被改变，不会影响到其他的对象

对象间的运算

1. 对象间可以用=进行赋值
2. 不能用'=='，'！='，'>','<','>=','<=',进行比较
    除非这些运算符进过了“重载”

访问类的成员变量和成员函数
1. 用法1:对象名.成员名
    ```c
    CRectangle r1, r2;
    r1.w = 5;
    r2.init(3,4);
    ```
2. 用法二：指针->成员名
    ```c
    CRectangle r1, r2;
    CRectangle * p1 = & r1;
    CRectangle * p2 = & r2;
    p1->w = 5;
    p2->init(3,4);
    ```
3. 用法三：引用名.成员名
    ```c
    CRectangle r2;
    CRectangle & rr = r2;
    rr.w = 5;
    rr.init(3,4);

类成员函数的另一种写法

    成员函数分开写

# 类成员的可访问范围
关键字——类成员可被访问的范围
1. private：指定私有成员，只能在成员函数内被访问
2. public：指定公有成员，可以在任何地方被访问
3. protected：指定保护成员

对象成员的访问权限
1. 定义一个类
    ```c
    class className{
        private:
            私有属性和函数
        public:
            共有属性和函数
        protected:
            保护属性和函数
    }；
    ```
2. 缺省为私有成员
    ```c
    class Man {
        int nAge;
        char szName[20];
      public:
        void SetName(char * Name) {
            strcpy(szName,Name);
        }
    };
    ```
3. 类的成员函数内部，可以访问
    1. 当前对象的全部属性，函数
    2. 同类其他对象的全部属性，函数

4. 类的成员函数以外的地方
    只能够访问该类对象的公有成员

设置私有成员的目的

    强制对成员变量的访问一定要通过成员函数进行

设置私有成员的机制——隐藏

# 内联成员函数和重载成员函数

1. 内联成员函数
    1. inline + 成员函数
    2. 整个函数体出现在类定义内部
    ```c
    class b{
        inline void func();
        void func2()
        {
        };
    };
    void b::func1() {}
    ```
2. 使用缺省参数要避免有函数重载时的二义性
    ```c
    class Location {
        private:
            int x, y;
        public:
            void init(int x = 0,int y = 0);
            void valueX(int val = 0) {x = val;}
            int valueX() {return x;}
    };

    Location A;
    A.valueX(); //错误，编译器无法判断调用哪个value
    ```
# 构造函数
基本概念
  1. 成员函数的一种
    1. 名字与类名相同，可以有参数，不能有返回值（void也不行）
    2. 作用是对对象进行初始化，如给成员变量赋初值
    3. 如果定义类时没写构造函数，则编译器生成一个默认的无参数的构造函数
        1. 默认构造函数无参数，不做任何操作
  2. 如果定义了构造函数，则编译器不生成默认的无参数的构造函数
  3. 对象生产时构造函数自动被调用。对象一旦生成，就再也不能在其上执行构造函数
  4. 一个类可以有多个构造函数
  5. 为什么需要构造函数：
    1. 构造函数执行必须要的初始化工作，有了构造函数，就不必专门再写初始化函数，也不用担心忘记调用初始化函数
    2. 有时对象没被初始化就使用，会导致程序出错
# 复制构造函数
基本概念
1. 只有一个参数，即对同类对象的引用
2. 形如 X::X(X&)或X::X(const X &),二者选一后者能以常量对象作为参数
3. 如果没有定义复制构造函数，那么编译器生成默认复制构造函数。默认的复制构造函数完成复制功能。
```c
class Complex {
    private:
        double real,image;
};
Complex c1; //调用缺省无参构造函数
Complex c2(c1); //调用缺省的复制构造函数，将c2初始化成和c1一样
```
4. 如果定义的自己的复制构造函数，则默认的复制构造函数不存在。
5. 不允许有形如X::X(X)的构造函数
```c
class CSample {
    CSample(CSample c) {} //错误，不允许这样的构造函数
};
```

复制构造函数起作用的三种情况
1. 当用一个对象去初始化同类的另一个对象时。
    ```c
    complex c2(c1);
    Complex c2 = c1; //初始化语句，非赋值语句
    ```
2. 如果某函数有一个参数是类A的对象，那么该函数被调用时，类A的复制构造函数将被调用。
    ```c
    class A {
        public:
        A() {};
        A(A & a){
            cout << "Coupy constructor called " << endl;
        }
    };

    void Func(A a1) {}
    int main() {
        A a2;
        Func(a2);
        return 0;
    }
    ```
3. 如果函数的返回值是类A的对象时，则函数返回时，A的复制构造函数被调用：
    ```c
    calss A {
      public:
        int v;
        A(int n) {v = n;};
        A(const A & a) {
            v = a.v;
            cout <<"Copy constructor called" << endl;
        }
    };

    A Func() {
        A b(4);
        return b;
    }

    int main() {
        cout << Func().v << endl;
        return 0;
    }
    ```

# 类型转换构造函数
目的

    实现类型的自动转换

特点

    只有一个参数

    不是复制构造函数

编译系统会自动调用-转换构造函数

    建立一个临时对象/临时变量

```c
class Complex {
    public:
        double real, imag;
        Complex(int i) {
            cout << "IntCinstructor called" << endl;
            real = i; imag = 0;
        }

        Complex(double r, double i) {
            real = r; imag = i;
        }
};

int main() {
    Complex c1(7, 8);
    Complex c2 = 12;
    c1 = 9;
    cout << c1.real << "," << c1.imag << endl;
    return 0;
}
```

# 析构函数
1. 成员函数的一种
    1. 名字与类相同
    2. 在前面加‘～’
    3. 没有参数和返回值
    4. 一个类最多只有一个析构函数
2. 对象消亡时-自动被调用
    1. 在对象消亡前做善后工作
        1. 释放分配的空间等
3. 定义类时没写析构函数，则编译器生成缺省析构函数
    1. 不涉及释放用户申请的内存释放等清理工作
4. 定义了析构函数，则编译器不生成缺省析构函数

```c
class String {
    private:
        char * p;
    public:
        String () {
            p = new char[10];
        }
        ~String();
};

String::~ String() {
    delete[] p;
}
```

析构函数和数组
 1. 对象数组生命期结束时-对象数组的每个元素的析构函数都会被调用
    ```c
    class Ctest {
        public:
            ~Ctest() {cout << "destructor called" << endl;}
    };

    int main() {
        Ctest array[2];
        cout << "End Main" << endl;
        return 0;
    }
    ```
 2. delete运算导致析构函数调用
    ```c
    Ctest * p Test;
    p Test = new Ctest;
    delete p Test;
    p Test = new Ctest[3];
    delete [] p Test;

构造函数和析构函数在不同编译器中的表现
1. 个别调用情况不一致
    1. 编译器有bug
    2. 代码优化措施
2. 前面讨论的是C++标准

# 静态成员变量和静态成员函数
基本概念
1. 静态成员：在定义前面加了static关键字的成员
    ```c
    class CRectangle {
        private:
            int w, h;
            static int nTotalArea;
            static int nTotalNumber;
        public:
            CRectangle(int w_, int h_);
            ~CRectangle();
            static void PrintTotal();
    };
    ```
2. 普通成员变量每个对象有各自的一份，而静态成员变量一共就一份，为所有对象共享。、

    sizeof 运算符不会计算静态成员变量
    ```c
    class CMyclass {
        int n;
        static int s;
    };
    ```
3. 普通成员函数必须具体作用于某个对象，而静态成员函数并不具体作用于某个对象

4. 因此静态成员不需要通过对象就能访问

5. 静态成员变量本质上是全局变量，哪怕一个对象都不存在，类的静态成员变量也存在。

6. 静态成员函数本质上是全局函数

7. 设置静态成员这种机制的目的是将和某些类紧密相关的全局变量和函数写到类里面，看上去像一个整体，易于维护和理解

8. 在静态成员函数函数中，不能访问非静态成员变量，也不能调用非静态成员函数。
如何访问静态成员

1. 类名：：成员名
    ```c
    CRectangle::PrintTotal();
    ```
2. 对象名.成员名
    ```c
    CRectangle r; r.PrintTotal();
    ```
3. 指针->成员名
    ```c
    CRectangle * p = &r;
    p->PrintTotal();
    ```
4. 引用.成员名
    ```c
    CRectangle & ref = r;
    int n = ref.nTotalNumber;
    ```
# 成员对象和封闭类
1. 成员对象：一个类的成员变量是另一个类的对象
2. 包含成员对象的类叫封闭类
    ```c
    class CTyre {
        private:
            int radius;
            int width;
        public:
            CTyre(int r, int w):radius(r), width(w) { }
    };
    class CEngine {
    };
    class CCar {
        private:
            int price;
            CTyre tyre;
            CEngine engine;
        public:
            CCar(int p, int tr, int tw);
    };
    CCar::CCar(int p, int tr, int w)::price(p), tyre(tr, w){};
    int main() {
        CCar car(20000, 17, 225);
        return 0;
    }
    ```
3. 生成封闭类对象的语句-明确“对象中的成员对象”-如何初始化

封闭类构造函数的初始化列表
1. 定义封闭类的构造函数时，添加初始化列表：
    类名：：构造函数（参数表）：成员变量1（参数表），成员变量2（参数表），···{
        ...
    }
2. 成员对象初始化列表中的参数
    1. 任意复杂的表达式
    2. 函数/变量/表达式中的函数，变量有定义

调用顺序
1. 当封闭类对象生成时，
    1. s1：执行所有成员对象的构造函数
    2. s2:执行封闭类的构造函数
2. 成员对象的构造函数调用顺序
    1. 和成员对象在类中的说明顺序一致
    2. 与在成员初始化列表中出现的顺序无关
3. 当封闭类对象消亡时，
    1. s1:先执行封闭类的析构函数
    2. s2:执行成员对象的析构函数
4. 析构函数顺序和构造函数的调用顺序相反

# 友元函数friend
1. 友元函数
    1. 一个类的友元函数可以访问该类的私有成员
        ```c
        class CCar;
        class CDriver {
            public:
                void ModifyCar(CCar * pCar);
        };
        class CCar {
            private:
                int price;
            friend int MostExpensiveCar(CCar cars[], int tatal);
            friend void CDriver::ModifyCar(CCar * pCar);
        };

        void CDriver:: ModifyCar(CCar * pCar) {
            pCar->price += 1000;
        }
        int MostExpensiveCar(CCar cars[], int tatal) {
            int tmpMax = -1;
            for(int i = 0; i < tatal; ++i)
                if(cars[i].price > tmpMax)
                    tmpMax = cars[i].price;
            return tmpMax;
        }

        int main() {
            return 0;
        }
        ```
    2. 将一个类的成员函数（包括构造，析构函数）-另一个类的友元
        ```c
        class B {
            public:
                void function();
        };
        class A {
            friend void B::function();
        };
2. 友元类
    1. A是B的友元类- A的成员函数可以访问B的私有成员
        ```c
        class CCar {
            private:
                int price;
            frienf class CDriver;
        };
        class CDriver {
            public:
                CCar myCar;
                void ModifyCar() {
                    myCar.price += 1000;
                }
        };
        int main() {return 0;}
        ```

# this指针
1. 其作用就是指向成员函数所作用的对象
2. 非静态成员函数中可以直接使用this来代表该函数作用的对象的指针
    ```c
    class Complex {
        public:
            double real, imag;
            void Print() {cout << real << "," << imag;}
            Complex(double r, double i):real(r), imag(i) { }
            Complex AddOne() {
                this->real ++; //real++
                this->Print(); //Print
                return * this;
            }
    };

    int main() {
        Complex c1(1, 1), c2(0, 0);
        c2 = c1.AddOne();
        retuen 0;
       }
    ```
this指针和静态成员函数
1. 静态成员函数中不能使用this指针
2. 因为静态成员函数并不具体作用与某个对象
3. 因此，静态成员函数的真实的参数的个数，就是程序中写出的参数个数
# 常量对象、常量成员函数和常引用

常量对象
1. 如果不希望某个对象的值被改变，则定义该对象的时候可以在前面加const关键字
    ```c
    class Demo {
        private:
            int value;
        public:
            void SetValue() {}
    };
    const Demo Obj;
    ```
2. 在该类成员函数说明后面可以加const关键字，则该成员函数成为常量成员函数
3. 常量成员函数执行期间不应该修改其所作用的对象。因此，在常量成员函数中不能修改成员变量的值（静态成员变量除外），也不能调用同类的非常量成员函数（静态成员函数除外）。

常量成员函数的重载
1. 两个成员函数，名字和参数表都一样，但是一个是const，一个不是，算重载
    ```c
    class CTest {
        private:
            int n;
        public:
            CTest() {n = 1;}
            int GetValue() const {return n;}
            int GetValue() {return 2 * n;}
    };
    int main() {
        const CTest objTest1;
        CTest objTest2;
        cout << objTest1.GetValue() << "," << objTest2.GetValue();
        return 0;
    }
    ```

常引用
1. 引用前面可以加const关键字，成为常引用。不能通过常引用，修改其引用的变量
    ```c
    const int &r = n;
    r = 5;//err
    n = 4;//ok
    ```
2. 可以用对象的常引用作为参数

# 运算符重载的基本概念
运算符

1. C++预定义表示对数据的运算
    1. +，-，*，/，%，^，&，～，！，｜，=，<<,>>,!=……
    2. 只能用于基本的数据类型
        1. 整型，实型，字符型，逻辑型……

自定义数据类型与运算符重载
1. C++提供了数据抽象的手段
    用户自己定义数据类型——类
    1. 调用类的成员函数-操作它的对象
2. 类的成员函数-操作对象时，很不方便
    1. 在数学上，两个复数可以直接进行+/-等运算
    VS.在C++中，直接将+或-用于复数是不允许的

运算符重载
1. 对抽象数据类型也能够直接使用C++提供的运算符
    1. 程序更简洁
    2. 代码更容易理解
2. 例如：
    1. complex_a和complex_b是两个复数对象
    2. 求两个复数的和，希望能直接写：
        complex_a + complex_b

3. 运算符重载
    1. 对已有的运算符赋予多重的含义
    2. 使同一运算符作用于不同类型的数据时-不同类型的行为
4. 目的
    扩展C++中提供的运算符的适用范围，以用于类所表示的抽象数据类型
5. 同一个运算符，对不同类型的操作数，所发生的行为不同
    1. (5, 10i) + (4, 8i) = (9, 18i)
    2. 5 + 4 = 9
6. 运算符重载的实质是函数重载
    返回值类型 operator 运算符（形参表）{ ……}
7. 在程序编译时：
    1. 把含运算符的表达式-对运算符函数的调用
    2. 把运算符的操作数-运算符的参数
    3. 运算符被多次重载时，根据实参的类型决定调用哪个运算符函数
    4. 运算符可以被重载成普通函数时，参数个数为运算符目数
    ```c
    class Complex {
        public:
            Complex(double r = 0.0, double i = 0.0) {
                real = r;
                imaginary = i;
            }
            double real; //real part
            double imaginary; // imaginary part
         };
    Complex operator+ (const Complex & a, const Complex & b) {
        return Complex(a.real + b.real, a.imaginary + b.imaginary);
    }
    Complex a(1,2), b(2,3), c;
    c = a + b;
    ```
    5. 也可以被重载成类的成员函数，参数个数为运算符目数减一
    ```c
    class Complex {
        public:
            Complex(double r = 0.0, double m = 0.0):
                real(r), imaginary(m) { }
            Complex operator+(const Complex &);
            Complex operator-(const Complex &);
        private:
            double real:
            double imaginary;
    };
    Complex Complex::operator+(const Complex & operand2) {
        return Complex(real + operand.real, imaginary + operand2.imaginary);
    }
    Complex Complex::operator-(const Complex & operand2) {
        return Complex(real - operand2.real, imagined - operand2.imaginary);
    }
    int main() {
        Complex x, y(4.3, 8.2), z(3.3, 1.1);
        x = y + z;
        x = y - z;
        return 0;
    }
    ```
# 赋值运算符的重载
赋值运算符‘=’重载
1. 赋值运算符两边的类型可以不匹配
    1. 把一个int 类型变量赋值给一个complex对象
    2. 把一个char*类型的字符串赋值给一个字符串对象
2. 需要重载赋值运算符‘=’
3. 赋值运算符‘=’只能重载为成员函数

重载赋值运算符的意义-浅复制和深复制
1. S1 = S2;
2. 浅复制/拷贝-指向地址改变
    1. 执行逐个字节的复制工作
        ```c
        MyString S1, S2;
        S1 = "this";
        S2 = "that";
        S1 = S2;
        ```
3. 深复制/深拷贝-指向值改变
    1. 将一个对象中指针变量指向的内容-复制到另一个对象中指针成员对象指向的地方
        ```c
        MyString S1, S2;
        S1 = "this";
        S2 = "that";
        S1 = S2;
        ```

# 运算符重载为友元函数
1. 通常，将运算符重载为类的成员函数
2. 重载为友元函数的情况：
    1. 成员函数不能满足使用要求
    2. 普通函数，又不能访问类的私有成员
        ```c
        class Complex {
            double real, imag;
        public:
            Complex(double r, double i)::real(r), image(i) {};
            Complex operator+(double r);
        };
        Complex Complex::operator+(double r) {
            return Complex(real + r, image);
        }
        ```
    3. 普通函数不能访问私有成员-将运算符+重载为友元函数
# 实例-长度可变的整形数组类
# 流插入运算符和提取运算符的重载
流插入运算符的重载
1. cout是在iostream中定义的，ostream类的对象
2. "<<"能用在cout上因为，在iostream里对"<<"进行了重载
## 自加/自减运算符的重载
1. 自加++/自减--运算符有前置/后置之分
2. 前置运算符作为一元运算符重载
    1. 重载为成员函数：
        T operator++();
        T operator--();
    2. 重载为全局函数：
        T operator++(T);
        T operator--(T);
    3. ++obj, obj.operator++(), operator++(obj)都调用上述函数
3. 后置运算符作为二院运算符重载
    1. 多写一个参数，具体无意义
    2. 重载为成员函数
        T operator++(int);
        T operator--(int);
    3. 重载为全局变量
        T operator++(T,int);
        T operator--(T,int);
    4. obj++,obj.operator++(0),operator++(obj,0)都调用上函数
4. int作为一个类型强制转换运算符被重载，
    ```c
    Demo s;
    (int) s;
5. 类型强制转换运算符时，
    1. 不能写返回值类型
    2. 实际上其返回值类型-类型强制转换运算符代表的类型

运算符重载的注意事项
1. C++不允许定义新的运算符
2. 重载后运算符的含义应该符合日常习惯
    1. complex_a + complex_b
    2. word_a > word_b
    3.date_b = date_a + n
3. 运算符重载不改变运算符的优先级
4. 以下运算符不能被重载：".", ".*", "::", "?:", sizeof
5. 重载运算符（），[], ->或者赋值运算符=时，重载函数必须声明为类的成员函数