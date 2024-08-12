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

# 继承和派生
1. 继承和派生的概念
    1. 继承：在定义一个新的类B时，如果该类与某个已有的类A相似（指的是B拥有A的全部特点），那么就可以把A作为一个基类，而把B作为基类的一个派生类（椰城子类）。
        1. 派生类是通过对基类进行修改和扩充得到的。在派生类中，可以扩充新的成员变量和成员函数。
        2. 派生类一经定义后，可以单独使用，不依赖于基类。
    2. 派生类拥有基类的全部成员函数和成员变量，不论是private、protected、public.
        1. 在派生类的各个成员函数中，不能访问基类中的private成员。
        ```c
        class CStudent {
            private:
                string sName;
                int nAge;
            public:
            bool IsThreeGood() { };
            void SetName(const string & name) {
                sName = name;
            }
        };
        class CUndergraduateStudent:public CStudent {
            private:
                int nDepartment;
            public:
                bool IsThreeGood() {...};
                bool CanBaoYan() {...};
        };
        class CGranduatedStudent:public CStudent {
            private:
                int nDepartment:
                char szMentorName[20];
            public:
                int CountSalary() {...};
        };
        ```
2. 派生类对象的内存空间
    派生类对象的体积，等于基类对象的体积，在加上派生类对象自己的成员变量的体积。在派生类对象中，包含着基类对象，而且基类对象的存储位置位语派生类对象新增的成员变量之前。
    ```c
    class CBase {
        int v1, v2;
    };
    class CDerived:public CBase {
        int v3;
    };
    ```

# 复合关系和继承关系
1. 继承：“是”关系
    1. 基类A，B是 基类A的派生类
    2. 逻辑上要求：“一个B对象也是一个A对象：。
2. 复合关系：“有”关系。
    1. 类C中“有”成员变量K，K是类D的对象，则C和D是复合关系
    2. 一般逻辑上要求：“D对象是C对象的固有属性或组成部分”

复合关系的使用
1. 几何形体程序中，需要写“点”类，也需要写“圆”类
2. 几何形体程序中，需要写“点“类，也需要写”圆“类，两者关系就复合关系就是复合关系——每一个“圆”对象里都包含（有）一个”点“对象，这个”点“对象就是圆心
    ```c
    class CPoint {
        double x, y;
        friend class CCircle;
    };
    class CCircle {
        double r;
        CPoint center;
    };
    ```

# 基类/派生类同名成员和protected访问范围说明符
基类和派生类有同名成员的情况
    ```c
    class base {
            int j;
        public:
            int i;
            void func();
    };
    class dericed:public base {
        public:
            int i;
            void access();
            void func();
    };
    void derived::access() {
        j = 5;
        i = 5;
        base::i = 5;
        func();
        base::func();
    }
    derived obj;
    obj.i = 1;
    obj.base::i = 1;
    ```

访问范围说明符
1. 基类的private成员：可以被下列函数访问
    1. 基类的成员函数
    2. 基类的友元函数
2. 基类的public成员：可以被下列函数访问
    1. 基类的成员函数
    2. 基类的友元函数
    3. 派生类的成员函数
    4. 派生类的友元函数
    5. 其他函数
3. 基类的protected成员：可以被下列函数访问
    1. 基类的成员函数
    2. 基类的友元函数
    3. 派生类的成员函数可以访问当前对象的基类的保护成员

```c
#include <iostream>
using namespace std;
class Father {
    private: int nPrivate;
    public: int nPublic;
    protected: int nProtected;
};
class Son:public Father {
    void AccessFather () {
        nPublic = 1;
        nPrivate = 1;
        nProtected = 1;
        Son f;
        f.nProtected = 1;
    }
};
int main() {
    Father f;
    Son s;
    f.nPublic = 1;
    s.nPublic = 1;
    f.nProtected = 1;
    f.Private = 1;
    s.nProtected = 1;
    s.nPrivate = 1;
    return 0;
}
```

# 派生类的构造函数
1. 派生类对象包含基类对象
2. 执行派生类构造函数之前，先执行基类的构造函数
3. 派生类交代基类初始化，具体形式：
    构造函数名（形参表）：基类名（基类构造函数实参表）{}
4. 在创建派生类的对象时，
    1. 需要调用基类的构造函数：
        初始化派生类对象中从基类继承的成员
    2. 在执行一个派生类的构造函数构造函数之前，总是先执行基类的构造函数
5. 调用基类构造函数的两种方式
    1. 显示方式：
        派生类的构造函数中-基类的构造函数提供参数
        ```c
        derived::derived(arg_derived-list):base(arg_base-list)
        ```
    2. 隐藏方式：
        派生类的构造函数中，省略基类构造函数时
        派生类的构造函数，自动调用基类的默认构造函数
6. 派生类的析构函数被执行时，执行完派生类的析构函数后，自动调用基类的析构函数
7. 创建派生类的对象时，执行派生类的构造函数之前：
    1. 调用基类的构造函数-初始化派生类对象中从基类继承的成员
    2. 调用成员对象类的构造函数-初始化派生类对象中成员对象
8. 执行完派生类的析构函数后：
    1. 调用成员对类的析构函数
    2. 调用基类的析构函数
9. 析构函数的调用顺序于构造函数的调用顺序相反

# public继承的赋值兼容规则
    ```c
    class base{ };
    class derived:public base{ };
    base b;
    derived d;
    ```
1. 派生类的对象可以复制给基类
    ```c
    b = d;
    ```
2. 派生类对象可以初始化基类引用
    ```c
    base & br = d;
    ```
3. 派生类对象的地址可以赋值给基类指针
    ```c
    base * pb = & d;
    ```

4. 如果派生方式是private或protected,则上述三条不可行

直接基类和间接基类

1. 类A派生类B， 类B派生类C， 类C派生类D，……
    1. 类A是类B的直接基类
    2. 类B是类C的直接基类， 类A是类C的间接基类
    3. 类C是类D的直接基类，类A、B是类D的间接基类
2. 在声明派生类时，只需要列出它的间接基类
    1. 派生类沿着类的层次自动向上继承它的间接基类
    2. 派生类的成员包括
        1. 派生类自己定义的成员
        2. 直接基类中的所有成员
        3. 所有间接基类的全部成员

# 多态和虚函数的基本概念
虚函数
1. 在类的定义中，前面有virtual关键字的成员函数就是虚函数
    ```c
    class base {
        virtual int get();
    };
    int base::get() {}
    ```
2. virtual关键字只用在类定义里的函数声明中，写函数体时不用
3. 构造函数和静态成员函数不能是虚函数

多态的表现形式一
1. 派生类的指针函数可以赋值给基类指针
2. 通过基类指针调用基类和派生类中的同名虚函数时：
    1. 若该指针指向一个基类的对象，那么被调用的基类的虚函数；
    2. 若该指针指向一个派生类的对象，那么被调用的是派生类的虚函数。
    这种机制就叫做“多态”。
多态的表现形式二
1. 派生类的对象可以赋值给 基类引用
2. 通过基类引用调用基类和派生类中的同名虚函数时：
    1. 若该引用引用的是一个基类的对象，那么被调用是基类的虚函数
    2. 若该引用引用的是一个派生类的对象，那么被调用的是派生类的虚函数。
    这种机制也叫做“多态”。

多态的作用

    在面向对象的程序设计中使用多态，能够增强程序的可扩充性，即程序需要修改或增加功能的时候，需要改动和增加的代码较少
# 使用多态的游戏程序实例
# 更多多态程序实例
# 多态实现原理

多态实现的关键字——虚函数表

每一个有虚函数的类（或有虚函数的类的派生类）都有一个虚函数表，该类的任何对象中都放着虚函数表的指针。虚函数表中列出了该类的虚函数地址。多出来的4个字节就是用来放虚函数表的地址的。

多态的函数调用语句被编译成一系列根据基类指针所指向的（或基类引用所引用的）对象中存放的虚函数的地址，在虚函数表中查找虚函数地址，并调用虚函数的指令。

# 虚析构函数
1. 通过基类的指针删除派生类对象时-只调用基类的析构函数
2. 删除一个派生类的对象时-先调用派生类的析构函数-再调用基类的虚构函数
3. 解决方法：把基类的析构函数声明为virtual
    1. 派生类的析构函数virtual可以不进行声明
    2. 通过基类的指针删除派生类对象时
        首先调用派生类的析构函数-然后调用基类的析构函数
4. 类如果定义类虚函数，则最好将析构函数也定义成虚函数
5. 不允许虚函数作为构造函数
# 纯虚函数和抽象类
纯虚函数
1. 纯虚函数：没有函数体的虚函数
    ```c
    class A{
        private:
            int a;
        public:
            virtual void Print() = 0;
            void func() {cout << "fun";}
    };
    ```
抽象类
1. 抽象类：包含纯虚函数的类
    1. 只能作为基类来派生新类使用
    2. 不能创建抽象类的对象
    3. 抽象类的指针和引用-有抽象类派生出来类的对象
        ```c
        A a; //err
        A * pa;
        pa = new A; //err
        ```
纯虚函数和抽象类
1. 在抽象类中
    1. 在成员函数内可以调用纯虚函数
    2. 在构造函数/析构函数内部不能调用纯虚函数
2. 如果一个类从抽象派生而来-它实现了基类中的所有纯虚函数，才能成为非抽象函数

#  文件操作

数据的层次
1. 位 bit
2. 字节 byte
3. 域/记录
4. 将所有记录顺序地倒入一个文件-顺序文件

文件和流
1. 顺序文件-一个有限字符构成的顺序字符流
2. C++标准库中：ifstream,oftream,fstream共三个类-用于文件操作-统称为文件流类

文件操作
1. 使用/创建文件的基本流程
    1. 打开文件：
        1. 通过指定文件名，建立文件和文件流对象的关联；
        2. 指明文件的使用方式
    2. 读/写文件：
        利用读/写指针进行相应位置的操作
    3. 关闭文件

建立顺序文件
    ```c
    #include <fstream>
    ofstream outFile("cline.dat", ios::out|ios::binary);
    ```
1. 也可以先创建ofstream对象，再用open函数打开
    ```c
    ofstream fout;
    fout.open("test.out",ios::out|ios::binary);
    ```
2. 判断打开是否成功：
    ```c
    if(!out) {cerr << "File open error" << endl;}
    ```
3. 文件名可以给出绝对路径，也可以给出相对路径
4. 没有交代路径信息，就是在当前文件夹下找文件

文件的读写指针
1. 对于输入文件，有一个读指针
2. 对于输入文件，有一个写指针
3. 对于输入输出文件，有一个读写指针
4. 标识文件操作的当前位置，该指针在哪里-读写操作就在哪里进行

二进制文件读写

    ``c
    int x = 10;
    fout.seekp(20,ios::beg);
    fout.write((const char*)(&x), sizeof(int));

    fin.seekg(0,ios::beg);
    fin.read((char*)(&x),sizeof(int));
    ```

二进制文件读写，直接写阿二进制数据，记事本看未必正确

显示关闭文件

1. fin.close();

2. fout.close();

# 类
## 引言
一个类型就是 一个概念(一个思想， 一个观念，等等)的具体表示。例如，C++内置 类型float 及其运算+、一、*等等一起提供了数学概念“ 实数” 的一种近似表示。类是用户 自定义类型。如果一个概念没有与之直接对应的内置类型，我们就定义 一个新类型来表示 它。

定义新类型的基本思想是将实现的细节(例如，某种类型对象的数据存储布局)与正确 使用它的必要属性(例如，可访问数据的函数的完整列表)分离。这种分离的最佳表达方式 是:通过一个专用接又引导数据结构及其内部辅助例程的使用。
## 类的基础
下面是类的简要概括:

• 一个类就是 一个用户自定义类型。

• 一个类由 一组成员构成。最常见的成员类别是数据成员和成员函数。

• 成员函数可定义初始化(创建)、拷贝、移动和清理(析构)等语义。

• 对对象使用. (点)访问成员，对指针使用- >(箭头)访问成员。

• 可以为类定义运算符，如+、!和又。

• 一个类就是 一个包含其成员的名字空间。

• public成员提供类的接又，private成员提供实现细节。

• struct是成员默认为public的class。

### 成员函数
考虑用struct(见2.3.1节和8.2节)实现日期的概念— 定义Date的表示方式和操作 这种类型的变量的一组函数:
    ```c
    struct Date {
        int d, m, y;
    };
    void init_date(Date& d, int ,int, int);
    void add_year(Date& d,int n);
    void add_month(Date& d, int n);
    void add_day(Date& d, int n);
    ```
数据类型、Date 和这些函数之间并无显式关联。我们可以通过将函数声明为成员来建立这 种关联:
    ```c
    struct Date {
        int d, m, y;
        void init(int dd, int mm, int yy);
        void add_year(int n);
        void add_month(int n);
        void add_day(int n);
    };
    ```
声明于类定义(struct 也是 一种类，见16.2.4 节)内的函数称为成员函数(member function)，对恰当类型的特定变量使用结构成员访问语法(见8.2 节)才能调用这种函数。 例如:
    ```c
    Date my_birthday;
    void f() {
        Date today;
        today.init(16,10,1996);
        my_birthday.init(30, 12, 1950);
        Date tomorrow = today;
        tomorrow_day(1);
    }
    ```
由于不同结构可能有同名成员函数，在定义成员函数时必须指定结构名
    ```c
    void Date::init(int dd, int mm, int y) {
        d = dd;
        m =mm;
        y=y;
    }
    ```
在成员函数中，不必显式引用对象即可使用成员的名字。在此情况下，名字所引用的是调 用 函 数 的 对 象 的 成 员.

### 默认拷贝
默认情况下，对象是可以拷贝的 。特别是，一个类对象可以用同类的另一个对象的副本 来进行初始化。

默认情况下， 一个类对象的副本是对每个成员逐个拷贝得到的。如果类X的这种默认拷贝 行为不是我们所希望的，可以提供更恰当的行为

类似地，类对象默认也可以通过赋值操作拷贝

再重复 一遍，默认的拷贝语义是逐成员复制。如果对于类X这不是正确的选择，用户可以 定 义 一个 恰 当 的 赋 值 运 算 符

### 访问控制

标签public 将类的主体分为两部分。第一部分中的名字是私有的(private)，它们只能被成 员函数使用。第二部分是公有的(public)，构成类对象的公共接又。struct 就是一个成员默 认为公有的class (见16.2.4节)，成员函数的声明和使用是一样的。

私有数据的保护依赖于对类成员名的使用限制。因此通过地址操作(见7.4.1 节)和显 式类型转换(见11.5 节)可以绕过私有保护，当然这是一种欺骗

### class和struct
下面的语法结构：
    ```c
    class x{……}；
    ```
称为类定义,它定义了一个名为×的类型。由于历史原因，类定义常常被称。这样叫它的另 一个原因是，与其他并非定义的C++声明类似， 我们可以在不同源文件中使用#include 重复类定义而不会违反单一定义规则

根 据 定 义 ， s t r u c t 就 是 一个 成 员 默 认 为 公 有 的 类 ， 即
    ```c
    struct{/*...*/};
    ```
就 是 下面 定 义 的 简 写
    ```c
    class S{public:/*...*/};
    ````
S 的这两个定义是可以互换的，当然坚持一种风格通常更明智。你到底使用哪种风格依赖 于 具 体 环 境 和 你 的 偏 好 。 如 果 我 认 为 一个 类 是 “ 简 单 数 据 结 构 ” ， 更 喜 欢 使 用 s t r u c t 。 如 果我认为一个类是“ 具有不变式的真正类型”，会使用class。即使是对struct 而言，构造 函数和访问函数也是非常有用的，但它们只是 一种简写而非不变式的保证

class的成员默认是私有的.

但是，我们也可以使用访问说明符private:来指明接下来的成员是私有的，就像用public: 说明接下来的成员是公有的 一样:
```c
struct Date2 {
    private:
        int d, m, y;
    public:
        Date 2(int dd, int mm, int yy);
        void add_year(int n);
};
```

C++并不要求在类定义中首先声明数据。实际上，将数据成员放在最后以强调提供公 共用户接又的函数(位置在前)通常是很有意义的

### 构造函数
使用像init()这样的函数为类对象提供初始化功能既不优雅也容易出错。因为这种方式 没 有 规 定 一个 对 象 必 须 进 行 初 始 化 ， 程 序 员 可 能 忘 记 初 始 化 ， 或 初 始 化 两 次 (两 种 情 况 通 常 都会带来灾难性后果)。一种更好的方法是允许程序员声明一个函数，它显式表明自己是专 门完成对象初始化任务的。由于这种函数的本质是构造 一个给定类型的值，因此被称为构造 函 数 (c o n s t r u c t o r )。 构 造 函 数 的 显 著 特 征 是 与 类 具 有 相 同 的 名 字

    ```c
    class Date {
        int d, m, y;
    public:
        Date(int dd, int mm, int yy);
    };
    ```
如果一个类有一个构造函数，其所有对象都会通过调用构造函数完成初始化。如果构造函数 需要参数，在初始化时就要提供这些参数:
    ```c
    Date today = Date(23, 6, 1983);
    ```
由于构造函数定义了类的初始化方式，因此我们可以使用{}初始化记法

构造函数的重载规则与普通函数相同。只要构造函数的参数类型明显不同，编 译器就能选择正确的版本使用
    ```c
    Date today{4};
    Date july4{"July 4, 1983"};
    Date guy {5, 11};
    Date now;
    Date start{};
    ```
在Date 这个例子中，构造函数的扩展是很典型的。当定义一个类时，程序员总是忍不住增 加新的特性，而原因仅仅是可能有人需要。确定哪些特性是真正需要的并在设计中只包含这 些特性需要更仔细思考，但这些额外的思考通常会带来更简洁也更容易理解的程序

当一个参数值用来表示“选择默认值” 时，此值必须在参数的可能值集合之外。对于day和 month，很明显零就可以，但对year就不是这样了。

通过确保对象的正确初始化，构造函数极大地简化了成员函数的实现。有了构造 函数，其他成员函数就不再需要处理未初始化数据的情况

### explicit构造函数
默认情况下，用单 一参数调用一个构造函数，其行为类似于从参数类型到类自身类型的 转换。例如
    ```c
    complex<double> d{1};
    ```
这种隐式转换可能非常有用。复数是一个典型的例子，如果忽略虚部 ，我们就会得到实数轴 上的一个复数，这正是数学家所要求的。但在很多情况下，这种转换可能是混乱和错误的主 要来源。

幸运的是，我们可以指明构造函数不能用作隐式类型转换。如果构造函数的声明带有关 键字explicit，则它只能用于初始化和显式类型转换。
    ```c
    class Date {
        int d, m, y;
    public:
        explicit Date(int dd = 0, int mm = 0; int yy = 0);
    };
    Date d1{15};
    Date d2 = Date{15};

    void f{
        my_fct(Date{15});
    }
    ```
用 = 进 行 初 始 化 可 看 作 拷 贝 初 始 化 ( c o p y i n i t i a l i z a t i o n )。 一般 来 说 ， 初 始 化 器 的 副 本 会 被 放 入 待 初 始 化 的 对 象 。 但 是 ， 如 果 初 始 化 器 是 一 个 右 值 (见 6 . 4 . 1 节 )， 这 种 拷 贝 可 能 被 优 化 掉 (取消)，而采用移动操作。省略= 会将初始化变为显式初始化。显 式初始化也称 直接初始化 。 默认情况下，应该将单参数的构造函数声明为e xplicit。除非你有很好的理由，否则的 话应该按这种默认方式做(例如complex)。如果定义隐式构造函数，最好写下原因，否则 代 码 的 维 护 者 可 能 怀 疑 你 疏 忽 了 ， 或 是 不 懂 这 一原 则 。

如果 一个构造函数声明为explicit 且定义在类外，则在定义中不能重复explicit

大多数explicit起很重要作用的构造函数都接受单一参数。但是，explicit 也可用于无参或多 个参数的构造函数。
### 类内初始化器
当使用多个构造函数时，成员初始化可以是重复的
    ```c
    class Date {
        int d, m, y;
    public:
        Date(int, int, int);
        Date(int, int);
        Date(int);
        Date();
        Date(const char*);
    }
    ```
通过引入默认参数，我们就可以减少构造函数的数量(见16.2.5 节)来解决此问题。另一种 方法是为数据成员添加初始化器
    ```c
    class Date {
        int d{today.d};
        int m{today.m};
        int y{today.y};
    public:
        Date(int, int, int);
        Date(int, int);
        Date(int);
        Date();
        Date(connst char*);
    }
    ```
### 类内函数定义
如果一个函数不仅在类中声明，还在类中定义，那么它就被当作内联函数处理(见 12. 1.5 节)，即很少修改且频繁使用的小函数适合类内定义。类似所属类的定义，可在多个编译单元中使用#include 重复类内定义的成员函数，无论在哪里使用#include，其含义都 应 保 持 一致

类 成 员 可 以 访 问 同 类 的 其 他 成 员 ， 而 不 管 成 员 是 在 哪 里 定 义 的 ( 见 6 . 3 . 4 节 )。 考 虑 下 面 的代码:
    ```c
    class Date {
        public:
            void add_month(int n) {m += n;}
        private:
            int d, m, y;
    };
    ```
即函数和数据成员的声明是不依赖于顺序的。可以编写等价代码如下:
    ```c
    class Date {
    public:
        void add_month(int n) {m += n;}
    ptivate:
        int d, m, y;
    };
    inline void Date::add_month(int) {
        m += n;
    }
    ```
### 可变性
我们可以定义具名的常量对象或变量对象 。换句话说，一个名字指向的既可以是一个 保存不可变值的对象，也可以是 一个保存可变值的对象。由于精确术语可能有些笨拙，我们 最终采用的描述方式是:称某些变量是常量，或者更简单地称之为c onst 变量 。无论这种描 述对一个以英语为母语的人来说有多么奇 ，概念本身还是非常有用的，而且已深深植入了 C++类型系统中。系统地使用不可变对象有利于产生更易理解的代码，有利于尽早发现更多 错误，而且有时会提高性能。特别是，不可变性在多线程编程中是一个非常有用的特性

为了使不可变性不局限 于内置类型的简单常量的定义，我们必须能定义可操作用户自 定义c onst 对象的函数。对独立函数而言，这意味着函数可接受c onst T&参数。对类而言， 这意味着我们必须能定义操作const 对象的成员函数。
### 常量成员函数
到 目 前 止 我 们 所 定 义 的 D a t e 提 供 了 一些 能 D a t e 赋 值 的 函 数 。 不 幸 的 是 ， 我 们 没 有提供检查Date 值的方法。通过增加读取天、月和年的函数，可以很容易地弥补此不足
    ```c
    class Date{
        int d, m, y;
    public:
        int day() const{return d;}
        int month() const {return m;}
        int year() const;
        void add_year(int n);
    };
    ```
函 数 声 明 中 (空 ) 参 数 列 表 后 的 c o n s t 指 出 这 些 函 数 不 会 修 改 D a t e 的 状 态 。 自然地，编译器会捕获试图违反此承诺的代码。

当c onst 成员函数定义在类外时，必须使用const 后缀

### 物理常量性和逻辑常量性
物理常量性和逻辑常 量性
有时，一个成员函数逻辑上是c onst，但它仍然需要改变成员的值。即对 一个用户而 言，函数看起来不会改变其对象的状态，但它更新了用户不能直接观察的某些细节。这通常 被 称 为 逻 辑 常 量 性 ( l o g i c a l c o n s t n e s s )。 例 如 ， 类 D a t e 可 能 有 一 个 返 回 字 符 串 表 示 的 函 数 。 构造这个字符串表示非常耗时，因此，保存一个拷贝，在反复要求获取字符串表示时可以简 单 地 返 回 此 拷 贝 (除 非 D a t e 的 值 已 被 改 变 )， 这 就 很 有 意 义 了 。 更 复 杂 的 数 据 结 构 常 使 用 这 种缓存值的技术，但我们现在只讨论对Dat e 如何使用这种技术
### mutable
我们可以将 一个类成员定义为mutable，表示即使是在const 对象中，也可以修改此 成员
    ```c
    class Date{
    public:
        string string_rep() const;
    private:
        mutable bool cache_valid;
        mutable string cache;
        void compute_cache_value() const;
    };
    ```
### 间接访问实现可变性
对于小对象的表示形式只有 一小部分允许改变的情形，将成员声明为mutable 是最适 合的。但在更复杂的情况下，通常更好的方式是将需要改变的数据放在 一个独立对象中，间 接地访问它们。如果采用这种技术，字符串缓存例程会变为
    ```c
    srtuct cache {
        bool vaild;
        string rep;
    };
    class Date {
    public:
        string string_rep() const;
    private:
        cache* c;
        void computer_cache_value() const;
    };
    string Date::string_rep() const {
        if(!c->valid) {
            computer_cache_value();
            c->valid = ture;
        }
        return c->rep;
    }
    ```
### 自引用
我们定义的状态更新函数add_year()、add_month()和add_day()(见16.2.3 节)是不 返回值的 。对这样一组相关的更新函数，一种通常很有用的技术是令它们返回已更新对象的 引用，这样这些操作就可以串接起来。

为此，必须将每个函数都声明为返回 一个Date引用

每个(非static)成员函数都知道是哪个对象调用的它，并能显式引用这个对象

在非static成员函数中，关键字this 是指向调用它的对象的指针。在类X的非const 成员函数中，this 的类型是X* 。但是，this 被当作 一个右值，因此我们无法获得this 的地 址或给它赋值。在类× 的const 成员函数中，this 的类型是const X*，以防止修改对象

this 的使用大多数是隐式的。特别是，每当我们引用类内的一个非static 成员时，都是 依 赖 于 一次 t h i s 的 隐 式 使 用 来 获 得 恰 当 对 象 的 该 成 员

this 的 一种常见的显式应用是用于链表操作。

### 成员访问
我们可以通过对类×的对象使用，(点)运算符或对X的对象的指针使用 ->(箭头)运 算符来访问× 的成员
    ```c
    struct X{
        void f();
        int m;
    };
    void user(X x, X* px) {
        m = 1;
        x.m = 1;
        x->m = 1;
        px->m = 1;
        px.m = 1;
    }
    ```
显然这种语法有些冗余:编译器了解一个名字是指向X还是X*，因此单一的运算符就足 够了。但是，程序员可能会感到迷惑，因此从最早期的C语言开始就使用两个独立的运 算符。

在类的内部访问成员则不需要任何运算符。

即一个不带限定的名字就像加了前缀this- >一样。注意，成员函数可以在一个成员声明前 就引用它:

如果我们希望引用类的 一个公共成员，而不是某个特定对象的成员，应该使用类名后接:的 限定方式
### static成员
为Date 设定默认值的确非常方便，但会带来严重的潜在问题，因 Date 类会依赖 全局变量today。这样的Date 类只能用于定义和正确使用today的上下文中。这就限制 一个 类 只 有 在 最 初 编 写 它 的 上 下 文 中 才 有 用 。 尝 试 使 用 这 种 上 下 文 依 赖 的 类 会 给 用 户 带 来很多意料之外的不快，代码维护也会变得很混乱。可能“ 只是一个小小的全局变量” 不是那么难以管理，但这种风格所产生的代码对其编写者之外的人几无用处，因此应该 避免。

幸运的是，我们获得这种便利性其实并不需要承担使用可公开访问的全局变量的负担。 是类的 一部分但不是某个类对象 一部分的变量称为static成员。static成员只有唯 一副本， 而 不 是 像 普 通 非 s t a t i c 成 员 那 样 每 个 对 象 都 有 其 副 本 ( 见 6 . 4 . 2 节 )。 类 似 地 ， 需 要 访 问 类 成 员而不需要通过特定对象调用的函数称为st ati c成员函数。

保留了Date 默认构造函数值的语义，又没有依赖全局变量 所 带 来的 问 题 :
    ```c
    class Date {
        int d, m, y;
        static Date default_date;
    public:
        Date(int dd = 0, int mm = 0, int yy = 0);
        static void set_default(int dd, int mm, int yy);
    };
    ```
如果使用了static 函数或数据成员，我们就必须在某处定义它们。在static 成员的定义中不 要重复关键字static

 s t a t i c 数 据 成 员 需 要 某 种 锁 机 制 或 访 问 规 则 来 避 免 竞 争 条 件 。多线程现在已经非常常见了，不幸的是旧代码中static 数据成员的使用非常普遍，而且使用方式隐含着竞争条件。

 ### 成员类型
 类型和类型别名也可以作为类的成员

 成员类(member class，常称为嵌套类，nested class)可以引用其所属类的类型和static成 员。当给定所属类的一个对象时，只能引用非static成员。为了避免陷人复杂的 二叉树结 构，我只使用“f（）” 和“g（）” 风格的例子。 嵌套类可以访问其所属类的成员(甚至是private 成员，这方面与成员函数类似)，但它 没有当前类对象的概念

 一个类并没有任何特殊权限能访问其嵌入类的成员

 成员类更多的是提供了一种符号表示上的便利，而非一种重要的语言特性。另 一方面，成员 别名非常重要，它是依赖于关联类型(见28.2.4 节和33.1.3 节)的泛型编程技术的基础。成 员 e n u m 通 常 作 为 e n u m c l a s s 的 替 代 ， 以 避 免 与外 围 作 用 域 中 和 枚 举 值 同 名的 实 体 产 生 冲 突

## 具体类
如果 一个类的表示是其定义的一部分，我们就称它是具体的(concrete，或称它是一个 具体类)。这将它与抽象类(见3.2.2 节和20.4 节)区分开来，后者为多种实现提供一个公共 接又。在定义中明确类的表示方式令我们能:

• 将对象置于栈、静态分配的内存以及其他对象中;

• 拷 贝 和 移 动 对 象 ;

• 直接引用具名对象(与通过指针和引用访问不同)。 这令具体类易于推断，编译器也容易为之生成优化的代码。因此，我们倾向于对频繁使用且 性能攸关的小类型使用具体类，例如复数、智能指针和容器。

这组操作对一个用户自定义类型而言是非常典型的:

[1] 一个构造函数指出此类型的对象/ 变量如何初始化。

[2 ]一组允许用户检查Date 的函数。这些函数标记为const，表明它们不会修改调用 它们的对象/ 变量的状态。

[ 3 ] 一组 允 许 用 户 无 须 了 解 表 示 细 节 也 无 须 摆 弄 复 杂 语 法 即 可 修 改 D a t e 的 函 数 。

[ 4 ] 隐 式 定 义 操 作 ， 允 许 D a t e 自 由 拷 贝

[5 ] 类Bad _date，用来报告错误、抛出异常。

[6 ] 一组有用的辅助函数。这些函数不是类成员，不能直接访问Date的表示，但我 们认为它们与名字空间Chr ono 的使用是相关的。
### 成员函数
自然地，对每个成员函数我们都必须在某处给出它的实现。例如:
    ```c
    Date::Date(int dd, Month mm, int yy):d{dd}, m{mm}, y{yy} {
        if (y == 0) y = default_date().year();
        if (m == Month{})m = default_date().month();
        if (d == 0) d = default_date().day();
        if (!is_valid())throw Bad_date;
    }
    ```
这个构造函数检查提供的数据是否表示一 个合法的Date。如果日期不合法，如 {3 0 , M o n t h : :f e b , 1 9 9 4 }， 它 会 抛 出 一 个 异 常， 表 示 产 生 了 错 误 。 如 果提供的数据是合法的，就进行相应的初始化。初始化操作相对复杂，因为它包含了数据验 证步骤。本例是初始化操作 一个很典型的实现。另一方面， 一旦Date已创建，即可使用和 拷贝而无须再进行检查。换句话说，构造函数建立了类的不变式(在本例中，不变式就是一 个 合 法 日 期 )。 其 他 成 员 函 数 可 依 赖 于 不 变 式 且 必 须 保 持 不 变 式 。 这 种 设 计 技 术 可 以 极 大 地 简 化 代 码

### 辅助函数
一般而言， 一个类都会有一些无须定义在类内的关联函数，因为它们不需要直接访问类 的表示。
    ```c
    int diff(Date a, Date b);
    bool is_leapyeear(int y);
    bool is_date(int d, Month m, int y);
    const Date& default_date();
    Date next_weekday(Date d);
    Date next_saturday(Date d);
    ```
还有一种替代方法是将类及其辅助函数放在一个名字空间中来显式表明两者的关联
### 重载运算符
添加一些函数使得用户自定义类型能使用人们 习惯的符号通常是很有用的。例如， o p e r a t o r = = ()定 义 了 D a t e 的 相 等 判 定 运 算 符 = = :
    ```c
    inline bool operator == (Date a, Date b) {
        return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
    }
    ```
其他可能的运算符包括:
    ```c
    bool operator!=(Date, Date); //不等
    bool operator<(Date, Date); // 小于
    bool operator> (Date, Date); //大于

    Date& operator++(Date& d) {return d.add_day(1); } //增加一天
    Daet& operator--(Date& d) (return d.add_day(-1);) //减少一天
    Date& operator+=(Date& d, int n) {return d.add_ day(n); } //增加n天
    Daet& operator-=(Date& d, int n) (return da.d_ day(-n); //减少n天
    Date operator+(Date d, int n) {return d+=n; } //加n天
    Date operator-(Date d, int n) {return d+=n;} //减n天
    ostream& operator<<(ostream&, Date d); //输出d
    istream& operator>>(istream&, Date& d); //读入d

### 具体类的重要性
 称 D a t e 这 样 的 简 单 用 户 自 定 义 类 型 为 具 体 类 型 ( c o n c r e t e t y p e )， 以 区 别 于 抽 象 类和 类 层 次， 并 强 调 它 们 与 i n t 和 c h a r 这 样 的 内 置 类 型 相 似 。 具 体 类的使用就像内置类型 一样。具体类型也称为值类型(valuetype)，使用它们编程称为面向 值的程序设计(value-orientedprogramming)。它们的使用模型和设计背后的 “哲学” 与常见的面向对象编程。

  一个具体类型的目标是高效地做好一件相对简单的事情，为用户提供修改其行为的特性 通 常 不 是 其 目 标 。 特 别 是 ， 展 现 运 行 时 多 态 行 为 也 不 是 其 意 图 。

  如果不喜欢一个具体类型的某些细节，你可以构建一个新的类型，只要实现所需行 为即可。如果希望“重用” 一个具体类型，你可以用它实现新类型，就像使用int一样。 例如:
    ```c
    class Date_and_time {
    private:
        Date d;
        Time t;
    public:
        Date_and_time(Date d, Time t);
        Date_and_Time(int d, Date::Month m, int y, Time t);
    };
    ```

    一种替代方法是派生类机制，可用来从具体类派生新类型，只要描述两者的差异即可，我将 在第20章介绍派生类。从vector定义Vec就是这种技术的一个例子。但是， 我们极少从 一个具体类派生新类，即使这样做的话也要特别小心，原因是具体类型缺少虚函 数 和 运 行 时 类 型 信 息

    如果有一个很好的编译器，Date这样的具体类不会有隐含的时空开销 。特别是，无须 通过指针间接访问具体类对象，也无须在具体类对象中保存“簿记” 数据。具体类型的大小 在编译时就已知，从而可在运行时栈中分配对象(即，无须自由存储空间操作)。对象的内 存布局也在编译时就已知道，从而内联操作很容易实现。类似地，无须特殊努力即可实现与 其他语言，如C 和Fortran 在内存布局上的兼容。

    一组好的具体类型能构成应用程序的基础 。特别是，使用它们可令接又更为具体、更不 容易出错。

    如果程序员编写代码时不是使用具体类型，而是简单聚合内置类型来表示“简单且频繁使用 的” 数据结构，并直接操作这种数据结构，就会产生含混的程序、浪费时间。另一方面，在 应用程序中不使用“小而高效的类型”，而是使用过分通用且代价高昂的类，会导致明显的 运行时间和空间上的低效。

## 建议
[1 ] 将 概 念 表 示 为 类 ;

[ 2 ] 将 类 的 接 又 与 实 现 分 离 ;

[3 ]仅当数据真的仅仅是数据且数据成员不存在有意义的不变式时才使用公有数据 (s t r u c t );

[4 ]定义构造函数来处理对象初始化;

[5]默认将单参数构造函数声明为explicit；

[6]将不修改其对象状态的成员函数声明为const;

[7] 具体类型是最简单的类。只要适用，就应该优先选择具体类型而不是更复杂的类或普通数据结构;16.3 节。

[8 ]仅当函数需要直接访问类的表示时才将其实现为成员函数;16.3.2 节。

[9 ]使用名字空间建立类与其辅助函数间的显式关联;16.3.2 节。

[10 ]将不修改对象值的成员函数定义为const 成员函数;16.3.2 节。

[ 1 1 ] 若 一个 函 数 需 要 访 问 类 的 表 示 ， 但 并 不 需 要 用 某 个 具 体 对 象 来 调 用 ， 建 议 将 其 实现 为 s t a t i c 成 员 函 数 ; 1 6 . 2 . 1 2 节。

# 函数模版

泛型程序设计
1. Generic Programming
2. 算法实现时不指定具体要操作的数据的类型
3. 泛型-算法实现一遍-适用于多种数据结构
4. 优势：减少重复代码的编写
5. 大量编写模版，使用模版的程序设计
    1. 函数模版
    2. 类模版

函数模版
1. 为了交换两个double型变量的值，还需要编写如下Swap函数：
    ```c
    void Swap(double & x, double & y) {
        double tmp = x;
        x = y;
        y = tmp;
    }
    ```
2. 用函数模版解决
    template<class类型参数1，class类型参数2，……>
    返回值类型 模版名（形参表）{
        函数体
    }
3. 交换两个变量值的函数模版
    ```c
    template <class T>
    void Swap(T & x, T & y) {
        T tmp = x;
        x = y;
        y = tmp;
    }
    int main() {
        int n = 1, m = 2;
        Swap(n, m);
        doublr f = 1.2, g = 2.3;
        Swap(f, g);
        return 0;
    }
    ```
4. 函数模版中可以有不止一个类型参数
    ```c
    template <class T1, class T2>
    T2 print(T1 arg1, T2 arg2) {
        cout << aeg1 << ""<< arg2 << endl;
        return arg2;
    }
    ```
5. 求数组最大元素的Max Element函数模版
    ```c
    template <class T>
    T MaxElement(T a[], int size) {
        T tmpMax = a[0];
        for (int i = 1; i < size; ++i)
            if (tmpMax < a[i])
        tmpMax = a[i];
        return tmpMax;
    }
    ```
6. 函数模版可以重载，只要他们的形参表不同即可
    例，下面两个模版可以同时存在
    ```c
    template <class T1, class T2>
    void print(T1 arg1, T2 arg2) {
        cout << arg1 << "" << arg2 << endl;
    }
    template <class T>
    void print(T arg1, T arg2) {
        cout << arg1 << "" << arg2 << endl;
    }
    ```
7. C++编译器遵循以下优先顺序：
    1. 先找参数完全匹配的普通函数（非由模版实例化而得的函数）
    2. 再找参数完全匹配的模版函数
    3. 再找实参经过自动类型转换后能够匹配的普通函数
    4. 上面的都找不到，则报错
    例：函数模版调用顺序
        ```c
        template <class T>
        T Max(T a, T b) {
            cout << "Template Max 1" << endl;
            return 0;
        }
        template <class T, class T2>
        T Max(T a, T2 b) {
            cout << "Template Max 2" << endl;
            return 0;
        }
        double Max(double a, double b) {
            cout << "MyMax" << endl;
            return 0;
        }
        int main() {
            int i = 4, i = 5;
            Max(1.2, 3.4);
            Max(i,j);
            Max(1.2,3);
            return 0;
        }
        ```
8. 赋值兼容原则引起函数模版中类型参数的二义性
    ```c
    template <class T1, class T2>
    T1 myFunction(T1 arg1, T2 arg2) {
        cout << arg1 << " " << arg2 << "\n";
        return arg1;
    }
    myFunction(5, 7);
    myFunction(5.8, 8.4);
    myFunction(5, 8.4);

# 类模版
1. 数组 一种常见的数据类型
    元素可以是：
        1. 整数
        2. 学生
        3. 字符串
2. 考虑一个数组类
    需要提供的基本操作：
        1. len()：查看数组的长度
        2. getElement(int index):获取其中一个元素
        3. setElement(int index):对其中的一个元素进行赋值
3. 类模版
    1. 在定义的时候给它一个/多个参数
    2. 这个/些参数表示不同的数据类型
4. 在调用类模版时，指定参数，由编译系统根据参数提供的数据类型自动产生相应的模版类
类模版的定义
1. C++的类模版的写法如下：
    template <类型参数表>
    class 类模版名 {
        成员函数和成员变量
    }；
2. 类型参数表的写法就是：
    class类型参数1，class类型参数2，
3. 类模版里的成员函数，如在类模版外面定义时，
    temp <型参数表>
    返回值类型 模版名<类型参宿名列表>::成员函数名（参数表） { }
4. 用类模版定义对象的写法如下：
    类模版名<真实类型参数表> 对象名（构造函数实际参数表）；
5. 如果类模版有无参构造函数，那么也可以只写：
    类模版名<真实类型参数表> 对象名；
6. Pair类模版：
    ```c
    template <class T1, class T2>
    class Pair {
        public:
            T1 key;
            T2 value;
            Pair(T1 k, T2 v):key(k),value(v) {};
            bool operator <(const Pair<T1, T2> & p) const;
    };
    template<class T1,class T2>
    bool Pair<T1, T2>::operator<(const Pair <T1, T2> & p)const {
        return key<p.key;
    }
    int main() {
        Pair<string, int> student("Tom",19);
        cout << student.key << "" << student.value;
        return 0;
    }
    ```
7. 使用类模版声明对象
    1. 编译器由类模版生成类的过程叫类模版的实例化
        编译器自动用具体的数据类型-替换类模版中的类型参数，生成模版类的代码
    2. 由类模版实例化得到的类叫模版类
        为类型参数指定的数据类型不同，得到的模版类不同
8. 同一个类模版的两个模版类时不兼容的
    ```c
    Pair <string, int> *p;
    Pair <string, double> a;
    p = &a;
    ```
函数模版作为类模版成员
    ```c
    #include <iostream>
    using namespace std;
    template <class T>
    class A {
        public:
            template <class T2>
            void Func(T2 t) {
                cout << t;
            }
    };
    int main() {
        A <int> a;
        a.Func('K');
        return 0;
    }
    ```

类模版与非类型参数
1. 类模版的参数声明可以包括非类型参数
    template<class T,int elementNimber>
    1. 非类型参数：用来说明类模版中的属性
    2. 类型参数：用来说明类模版中的属性类型，成员操作的参数类型和返回值类型
2. 类模版的“<类型参数表>“中可以出现非类型参数：
    ```c
    template <class T, int size>
    class CArray {
        T array[size];
    public:
        void Print() {
            for (int i = 0; i < size; ++i)
                cout << array[i] << endl;
        }
    };

类模版与继承
1. 类模版派生出类模版
    ```c
    template <class T1, class T2>
    class A {
        T1 v1; T2 v2;
    };
    template <class T1, class T2>
    class B:public A < T2, T1> {
        T1 v3; T2 v4;
    };
    template <class T>
    class C:public B<T,T> {
        T v5;
    };
    int main() {
        B<int,double> obj1;
        C<int> obj2;
        return 0;
    }
    ```
2. 模版类（基类模版中类型/非类型参数实例化后的类）派生出类模版
    ```c
    template <class T1, class T2>
    class A{T1 v1; T2 v2;};
    template <class T>
    class B:public A<int,double>{T v;};
    int main() {B <char> obj1; return 0;}
    ```
    自动生成两个模版类A<int,double> 和B<char>
3. 普通类派生出类模版
    ```c
    class A{int v1;};
    template <class T>
    class B:public A{ T v;};
    int main() {
        B<char>obj1;
        return 0;
    }
    ```
4. 模版类派生出普通类
    ```c
    template <class T>
    class A {T v1; int n;};
    class B:public A<int> {double v;};
    int main() {
        B obj1;
        return 0;
    }

# 构造、清理、拷贝和移动
## 引言
```c
    string ident(string arg) {
        return arg;
    }
    int main() {
        string s1{"Adams"};
        s1 =  idet(s1);
        string s2 {"Pratchett"};
    }
```
 调 用 i d e n t ()后 ， S 1 的 值 应 该 为 “ A d a m s ” 。 我 们 将 s 1 的 值 拷 贝 到 参 数 a r g 中 ， 然 后 将 a r g 的 值 移 出 函 数 ， 移 回 s 1 中 。 接 下来 ， 我 们 构 造 S 2 ， 将 其 初 始 化 为 “ P r a t c h e t t ”并将其拷贝到s 1 中。最后，在main()退出时我们销毁变量s 1 和s 2。移动(m ove )和拷贝 (copy )的区别在于，拷贝操作后两个对象具有相同的值，而移动操作后移动源不一定具有 其原始值。如果源对象在操作后不再使用，我们就可以使用移动操作。在实现资源移动概念 (见 3 . 2 . 1 . 2 节 和 5 . 2 节 )时 ， 移 动 操 作 特 别 有 用 。

这个例子中使用了多个函数:

• 用字符串字面值常量初始化string的构造函数(用于s1和s2)

• 拷贝string的拷贝构造函数(拷贝到函数参数arg中)

• 移动string值的移动构造函数(将arg的值移出ident()，移动到保存ident(s1)结果 的临时 变量中)

• 移 动 s t r i n g 值 的 移 动 赋 值 操 作 (从 保存 i d e n t (s 1 )结 果 的 临 时 变 量 移 动 到 s 1 )

• 拷贝string 值的拷贝赋值操作 (从s2 拷贝到s 1)

• 析构函数释放s1、S2和保存ident(s1)结果的临时变量所拥有的资源，对移动源 — 函数参数arg 不做任何事情。