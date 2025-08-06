# 函数指针
1. 定义形式
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
```c
&:按位与（双目）

|：按位或（双目）

~：按位非（取反）（单目）

^：按位异或（双目）

<<：左移（双目）

>>：右移（双目）
```
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

定义：引用是一个变量的别名，它允许我们用不同的名字访问同一个内存位置

下面的写法定义了一个引用，并将其初始化为引用某个变量。

类型名& 引用名 = 某变量名；

```c
int n = 4;
int &r = n; //r引用了n，r的类型是int &
```

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

```c
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

# 函数
## 函数签名
函数签名(Function Signature)是函数的唯一标识，包含以下要素：

1. 基本组成
    - 函数名
    - 参数列表(参数类型和顺序)
    - 所在的命名空间/类

2. 不包含的要素
    - 返回值类型
    - 参数名称
    - 函数体

3. 示例:
    ```cpp
    // 以下是不同的函数签名
    void func(int a, double b);
    void func(double a, int b);    // 参数类型顺序不同
    void func(int a);              // 参数数量不同
    void func(char a, char b);     // 参数类型不同

    // 以下不构成不同的签名
    int func(int a, double b);     // 仅返回值不同
    void func(int x, double y);    // 仅参数名不同
    ```

4. 重要用途
    - 函数重载的区分依据
    - 链接器识别函数的依据
    - 编译器进行函数调用匹配

5. 在C++中的特殊情况
    - 类成员函数的签名包含this指针
    - 模板函数的签名包含模板参数
    - const成员函数有不同的签名

## 函数重载
函数重载(Function Overloading)是C++中的一个重要特性,允许在同一作用域中定义多个同名但参数列表不同的函数。主要特点:

1. 重载条件
    - 函数名相同
    - 参数列表不同(参数类型、参数个数、参数顺序)
    - 返回值类型不同不足以构成重载

2. 简单示例:
    ```cpp
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
    ```

3. 重载函数的调用
    编译器根据调用时的参数类型和数量自动选择匹配的函数:
    ```cpp
    int main() {
        add(1, 2);       // 调用int版本
        add(1.5, 2.5);   // 调用double版本
        add(1, 2, 3);    // 调用三参数版本
    }
    ```

4. 注意事项:
    - 避免参数类型过于相近,可能导致二义性
    - 使用默认参数时要小心避免重载冲突
    - 类成员函数也可以重载

# 类

## 引言
一个类型就是 一个概念(一个思想， 一个观念，等等)的具体表示。例如，C++内置 类型float 及其运算+、一、*等等一起提供了数学概念“ 实数” 的一种近似表示。类是用户 自定义类型。如果一个概念没有与之直接对应的内置类型，我们就定义 一个新类型来表示 它。

定义新类型的基本思想是将实现的细节(例如，某种类型对象的数据存储布局)与正确 使用它的必要属性(例如，可访问数据的函数的完整列表)分离。这种分离的最佳表达方式 是:通过一个专用接又引导数据结构及其内部辅助例程的使用。

## 类的基础
下面是类的简要概括:

* 一个类就是 一个用户自定义类型。

* 一个类由 一组成员构成。最常见的成员类别是数据成员和成员函数。

* 成员函数可定义初始化(创建)、拷贝、移动和清理(析构)等语义。

* 对对象使用. (点)访问成员，对指针使用->(箭头)访问成员。

* 可以为类定义运算符，如+、!和又。

* 一个类就是 一个包含其成员的名字空间。

* public成员提供类的接又，private成员提供实现细节。

* struct是成员默认为public的class。

## 成员函数
考虑用struct(见2.3.1节和8.2节)实现日期的概念— 定义Date的表示方式和操作 这种类型的变量的一组函数:

```cpp
struct Date {
    int d, m, y;
};
void init_date(Date& d, int ,int, int);
void add_year(Date& d,int n);
void add_month(Date& d, int n);
void add_day(Date& d, int n);
```

数据类型、Date 和这些函数之间并无显式关联。我们可以通过将函数声明为成员来建立这 种关联:

```cpp
struct Date {
    int d, m, y;
    void init(int dd, int mm, int yy);
    void add_year(int n);
    void add_month(int n);
    void add_day(int n);
};
```

声明于类定义(struct 也是 一种类，见16.2.4 节)内的函数称为成员函数(member function)，对恰当类型的特定变量使用结构成员访问语法(见8.2 节)才能调用这种函数。 例如:

```cpp
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

```cpp
void Date::init(int dd, int mm, int y) {
    d = dd;
    m = mm;
    y = y;
}
```

在成员函数中，不必显式引用对象即可使用成员的名字。在此情况下，名字所引用的是调 用 函 数 的 对 象 的 成 员.

2. 内联成员函数
    类的成员函数可以指定为inline，即内联函数。
    默认情况下，在类体中定义的成员函数若不包括循环等控制结构，符合内联函数要求时，C++会自动将它们作为内联函数处理（隐式inline）。

    判断成员函数是否是内联的，有以下几条：
    1. 符合内联函数要求；
    2. 符合1的条件，并且在类体中定义，自动成为内联的；
    3. 符合1的条件，在类体显式指明inline，或在外部定义时显式指明inline，或者同时显式指明，则函数是内联的；
    4. 在类外部定义，并且既没有在类体，也没有在外部定义时显式指明inline，则函数不是内联的。

3. 成员函数重载及默认参数
    可以对成员函数重载或使用默认参数。例如：
    ```cpp
    class MAX {
        int Max(int X, int y) { return x>y?Х:y; }
        int Max() {
            return Max(Max(a, b), Max(c,d));
        } //重载Max
        int Set(int i=1, int j=2, int k=3, int 1=4) {
            a=i, b=j,c=k, d=1;
        } //默认参数
        int a,b,c, d;
    }；
    ```

4. 成员函数的存储方式
    1. 用类实例化一个对象时，系统会为每一个对象分配存储空问。如果一个类包括了数据成员和成员函数，则要分别为数据和函数的代码分配存储空间。
    2. 通常，C++会为每个对象的数据成员分配各自独立的存储空间，像结构体成员那样。

    ```cpp
    class Point;//Point类声明，非Point类定义，因为没有类体
    class Line {
        Point a; 1/错误，不能使用仅有类声明而没有类定义的类定义数据对象
        Point *pp，&rp;/1正确，只有类声明，即可用它定义该类的指针或引用
        Line b;//错误，类不能具有自身类型的数据成员
        Line *p1，&r1；/1正确，类可以有指向自身类型的指针或引用的数据成员
    };
    ```

## 访问控制
访问控制的主要特点：
1. public（公有）：
    - 类外部可以访问
    - 继承类可以访问
    - 通常用于接口

2. protected（保护）：
    - 类外部不能访问
    - 继承类可以访问
    - 用于继承层次中的共享

3. private（私有）：
    - 类外部不能访问
    - 继承类不能访问
    - 用于实现细节

继承访问控制：

1. public继承：
    ```cpp
    class Derived : public Base {
        // 基类public成员仍然是public
        // 基类protected成员仍然是protected
        // 基类private成员不可访问
    };
    ```

2. protected继承：
    ```cpp
    class Derived : protected Base {
        // 基类public成员变成protected
        // 基类protected成员仍然是protected
        // 基类private成员不可访问
    };
    ```

3. private继承：
    ```cpp
    class Derived : private Base {
        // 基类public成员变成private
        // 基类protected成员变成private
        // 基类private成员不可访问
    };
    ```

友元：

1. 友元类：
    ```cpp
    class MyClass {
    private:
        friend class Friend;  // Friend类可以访问MyClass的私有成员
    };
    ```

2. 友元函数：
    ```cpp
    class MyClass {
    private:
        friend void friendFunction();  // friendFunction可以访问私有成员
    };
    ```

封装的最佳实践：

1. 数据隐藏：
    ```cpp
    class Person {
    private:
        string name;
    public:
        string getName() const { return name; }
        void setName(const string& n) { name = n; }
    };
    ```

2. 接口设计：
    ```cpp
    class Interface {
    public:
        virtual void publicAPI() = 0;  // 公有接口
    protected:
        virtual void helperMethod() = 0;  // protected帮助方法
    private:
        void implementation();  // 私有实现
    };
    ```

3. 访问控制的选择：
    - 默认使用private
    - 只有需要外部访问时才使用public
    - protected用于需要在继承层次中共享的成员


```cpp
#include <iostream>
using namespace std;

// 基类
class Base {
public:
    int publicVar;      // 公有成员
protected:
    int protectedVar;   // 保护成员
private:
    int privateVar;     // 私有成员

public:
    Base() : publicVar(1), protectedVar(2), privateVar(3) {}

    // 公有方法
    void publicMethod() {
        cout << "Public method" << endl;
        privateMethod();  // 可以访问私有方法
    }

protected:
    // 保护方法
    void protectedMethod() {
        cout << "Protected method" << endl;
    }

private:
    // 私有方法
    void privateMethod() {
        cout << "Private method" << endl;
    }
};

// 公有继承
class PublicDerived : public Base {
public:
    void accessTest() {
        publicVar = 10;      // 可以访问公有成员
        protectedVar = 20;   // 可以访问保护成员
        // privateVar = 30;  // 错误：不能访问私有成员

        publicMethod();      // 可以访问公有方法
        protectedMethod();   // 可以访问保护方法
        // privateMethod();  // 错误：不能访问私有方法
    }
};

// 保护继承
class ProtectedDerived : protected Base {
public:
    void accessTest() {
        publicVar = 10;      // 变成了保护成员
        protectedVar = 20;   // 仍然是保护成员
        // privateVar = 30;  // 错误：不能访问私有成员
    }
};

// 私有继承
class PrivateDerived : private Base {
public:
    void accessTest() {
        publicVar = 10;      // 变成了私有成员
        protectedVar = 20;   // 变成了私有成员
        // privateVar = 30;  // 错误：不能访问私有成员
    }
};

// 友元类示例
class Friend {
private:
    int privateData;
    friend class FriendClass;    // 声明友元类
    friend void friendFunction(); // 声明友元函数

public:
    Friend() : privateData(100) {}
};

class FriendClass {
public:
    void accessFriendPrivate(Friend& f) {
        cout << "Friend's private data: " << f.privateData << endl;
    }
};

void friendFunction() {
    Friend f;
    cout << "Accessing private data through friend function: " << f.privateData << endl;
}

// 嵌套类的访问控制
class Outer {
private:
    int privateOuterVar;

public:
    Outer() : privateOuterVar(1) {}

    class Inner {
    public:
        void accessOuter(Outer& outer) {
            cout << outer.privateOuterVar << endl; // 可以访问外部类的私有成员
        }
    };
};

// 演示类的访问控制
class AccessDemo {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    int publicVar;

    // 构造函数
    AccessDemo() : privateVar(1), protectedVar(2), publicVar(3) {}

    // 公有方法访问私有成员
    void accessPrivate() {
        cout << "Accessing private var: " << privateVar << endl;
    }

    // getter和setter方法
    int getPrivateVar() const { return privateVar; }
    void setPrivateVar(int value) { privateVar = value; }
};

int main() {
    // 测试基本访问控制
    cout << "===测试基本访问控制===" << endl;
    Base base;
    base.publicMethod();     // 可以访问公有方法
    // base.protectedMethod(); // 错误：不能访问保护方法
    // base.privateMethod();   // 错误：不能访问私有方法

    // 测试继承访问控制
    cout << "\n===测试继承访问控制===" << endl;
    PublicDerived pub;
    pub.publicMethod();      // 可以访问公有方法

    // 测试友元
    cout << "\n===测试友元===" << endl;
    Friend f;
    FriendClass fc;
    fc.accessFriendPrivate(f);
    friendFunction();

    // 测试嵌套类
    cout << "\n===测试嵌套类===" << endl;
    Outer outer;
    Outer::Inner inner;
    inner.accessOuter(outer);

    // 测试访问控制演示类
    cout << "\n===测试访问控制演示类===" << endl;
    AccessDemo demo;
    cout << "Public var: " << demo.publicVar << endl;
    // cout << demo.privateVar << endl;    // 错误：不能直接访问私有成员
    cout << "Private var through getter: " << demo.getPrivateVar() << endl;

    return 0;
}
```


#### public继承的赋值兼容规则
```cpp
class base{ };
class derived:public base{ };
base b;
derived d;
```
1. 派生类的对象可以复制给基类
    ```cpp
    b = d;
    ```
2. 派生类对象可以初始化基类引用
    ```cpp
    base & br = d;
    ```
3. 派生类对象的地址可以赋值给基类指针
    ```cpp
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

## class和struct
下面的语法结构：

```cpp
class x{}；
```

称为类定义,它定义了一个名为×的类型。由于历史原因，类定义常常被称。这样叫它的另 一个原因是，与其他并非定义的C++声明类似， 我们可以在不同源文件中使用#include 重复类定义而不会违反单一定义规则

根 据 定 义 ， s t r u c t 就 是 一个 成 员 默 认 为 公 有 的 类 ， 即

```cpp
struct{/*...*/};
```

就 是 下面 定 义 的 简 写

```cpp
class S{public:/*...*/};
````

S 的这两个定义是可以互换的，当然坚持一种风格通常更明智。你到底使用哪种风格依赖 于 具 体 环 境 和 你 的 偏 好 。 如 果 我 认 为 一个 类 是 “ 简 单 数 据 结 构 ” ， 更 喜 欢 使 用 s t r u c t 。 如 果我认为一个类是“ 具有不变式的真正类型”，会使用class。即使是对struct 而言，构造 函数和访问函数也是非常有用的，但它们只是 一种简写而非不变式的保证

class的成员默认是私有的.

但是，我们也可以使用访问说明符private:来指明接下来的成员是私有的，就像用public: 说明接下来的成员是公有的 一样:

```cpp
struct Date2 {
private:
    int d, m, y;
public:
    Date2(int dd, int mm, int yy);
    void add_year(int n);
};
```

C++并不要求在类定义中首先声明数据。实际上，将数据成员放在最后以强调提供公 共用户接又的函数(位置在前)通常是很有意义的

## 特殊成员函数
### 构造函数

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

---

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
        ```cpp
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
10. 注意事项：
    1. 构造函数的函数名必须与类名相同
    2. 构造函数没有返回值
    3. 其功能是将对象中的所有数据成员进行初始化，一般由一系列赋值语包构成
    4. 由系统在声明对象时自动调用

抽象类
1. 抽象类不能实例化，即不申明对象
2. 抽象类只作为基类被继承
3. 可以定义抽象类的指针或引用

```cpp
class Date {
    int d, m, y;
public:
    Date(int dd, int mm, int yy);
};
```

如果一个类有一个构造函数，其所有对象都会通过调用构造函数完成初始化。如果构造函数 需要参数，在初始化时就要提供这些参数:

```cpp
Date today = Date(23, 6, 1983);
```

由于构造函数定义了类的初始化方式，因此我们可以使用{}初始化记法

构造函数的重载规则与普通函数相同。只要构造函数的参数类型明显不同，编 译器就能选择正确的版本使用

```cpp
Date today{4};
Date july4{"July 4, 1983"};
Date guy {5, 11};
Date now;
Date start{};
```

在Date 这个例子中，构造函数的扩展是很典型的。当定义一个类时，程序员总是忍不住增 加新的特性，而原因仅仅是可能有人需要。确定哪些特性是真正需要的并在设计中只包含这 些特性需要更仔细思考，但这些额外的思考通常会带来更简洁也更容易理解的程序

当一个参数值用来表示“选择默认值” 时，此值必须在参数的可能值集合之外。对于day和 month，很明显零就可以，但对year就不是这样了。

通过确保对象的正确初始化，构造函数极大地简化了成员函数的实现。有了构造 函数，其他成员函数就不再需要处理未初始化数据的情况

构造函数执行顺序：
1. 虚基类
2. 非虚基类，按照继承顺序构造
3. 设置每个虚函数表的指针
4. 成员初始化列表
5. 构造函数体内的代码

虚基类的构造函数只会被最后一个派生类调用

#### explicit构造函数

默认情况下，用单一参数调用一个构造函数，其行为类似于从参数类型到类自身类型的 转换。例如

```cpp
complex<double> d{1};
```

这种隐式转换可能非常有用。复数是一个典型的例子，如果忽略虚部 ，我们就会得到实数轴 上的一个复数，这正是数学家所要求的。但在很多情况下，这种转换可能是混乱和错误的主 要来源。

幸运的是，我们可以指明构造函数不能用作隐式类型转换。如果构造函数的声明带有关 键字explicit，则它只能用于初始化和显式类型转换。

```cpp
class Date {
    int d, m, y;
public:
    explicit Date(int dd = 0, int mm = 0; int yy = 0);
};
Date d1{15};
Date d2 = Date{15};

void f() {
    my_fct(Date{15});
}
```

用 = 进 行 初 始 化 可 看 作 拷 贝 初 始 化 ( c o p y i n i t i a l i z a t i o n )。 一般 来 说 ， 初 始 化 器 的 副 本 会 被 放 入 待 初 始 化 的 对 象 。 但 是 ， 如 果 初 始 化 器 是 一 个 右 值 (见 6 . 4 . 1 节 )， 这 种 拷 贝 可 能 被 优 化 掉 (取消)，而采用移动操作。省略= 会将初始化变为显式初始化。显 式初始化也称 直接初始化 。 默认情况下，应该将单参数的构造函数声明为e xplicit。除非你有很好的理由，否则的 话应该按这种默认方式做(例如complex)。如果定义隐式构造函数，最好写下原因，否则 代 码 的 维 护 者 可 能 怀 疑 你 疏 忽 了 ， 或 是 不 懂 这 一原 则 。

如果 一个构造函数声明为explicit 且定义在类外，则在定义中不能重复explicit

大多数explicit起很重要作用的构造函数都接受单一参数。但是，explicit 也可用于无参或多 个参数的构造函数。

#### 类型转换构造函数
目的：实现类型的自动转换

特点：只有一个参数，不是复制构造函数

编译系统会自动调用-转换构造函数

    建立一个临时对象/临时变量

```cpp
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

### 复制构造函数

基本概念
1. 只有一个参数，即对同类对象的引用
2. 形如 X::X(X&)或X::X(const X &),二者选一后者能以常量对象作为参数
3. 如果没有定义复制构造函数，那么编译器生成默认复制构造函数。默认的复制构造函数完成复制功能。

    ```cpp
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
    ```cpp
    complex c2(c1);
    Complex c2 = c1; //初始化语句，非赋值语句
    ```
2. 如果某函数有一个参数是类A的对象，那么该函数被调用时，类A的复制构造函数将被调用。
    ```cpp
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
    ```cpp
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

### 移动构造函数

### 拷贝移动运算符

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
 调用ident()后，S1的值应该为“Adams”。我们将s1的值拷贝到参数arg中，然后将arg的值移出函数，移回s1中。接下来，我们构造S2，将其初始化为“Pratchett”并将其拷贝到s1中。最后，在main()退出时我们销毁变量s1和s2。

 移动(move)和拷贝(copy)的区别在于，拷贝操作后两个对象具有相同的值，而移动操作后移动源不一定具有其原始值。如果源对象在操作后不再使用，我们就可以使用移动操作。在实现资源移动概念(见3.2.1.2节和5.2节)时，移动操作特别有用。

这个例子中使用了多个函数:

* 用字符串字面值常量初始化string的构造函数(用于s1和s2)

* 拷贝string的拷贝构造函数(拷贝到函数参数arg中)

* 移动string值的移动构造函数(将arg的值移出ident()，移动到保存ident(s1)结果 的临时 变量中)

* 移 动 s t r i n g 值 的 移 动 赋 值 操 作 (从 保存 i d e n t (s 1 )结 果 的 临 时 变 量 移 动 到 s 1 )

* 拷贝string 值的拷贝赋值操作 (从s2 拷贝到s 1)

* 析构函数释放s1、S2和保存ident(s1)结果的临时变量所拥有的资源，对移动源 — 函数参数arg 不做任何事情。

### 析构函数

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

```cpp
class String {
private:
    char * p;
public:
    String () {
        p = new char[10];
    }
    ~String();
};

String::~String() {
    delete[] p;
}
```

析构函数和数组
1. 对象数组生命期结束时-对象数组的每个元素的析构函数都会被调用
    ```cpp
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
    ```cpp
    Ctest * p Test;
    p Test = new Ctest;
    delete p Test;
    p Test = new Ctest[3];
    delete [] p Test;
    ```
    构造函数和析构函数在不同编译器中的表现
1. 个别调用情况不一致
    1. 编译器有bug
    2. 代码优化措施
2. 前面讨论的是C++标准

父类的析构函数为什么是虚函数的主要原因：
1. 如果析构函数不是虚函数，delete基类指针时只会调用基类的析构函数
2. 这样会导致派生类的析构函数不会被调用，造成派生类中分配的资源无法释放
3. 设置为虚函数后，delete基类指针时会先调用派生类析构函数，再调用基类析构函数
4. 这样能确保派生类和基类的资源都被正确释放
#### 虚析构函数
1. 通过基类的指针删除派生类对象时-只调用基类的析构函数
2. 删除一个派生类的对象时-先调用派生类的析构函数-再调用基类的虚构函数
3. 解决方法：把基类的析构函数声明为virtual
    1. 派生类的析构函数virtual可以不进行声明
    2. 通过基类的指针删除派生类对象时
        首先调用派生类的析构函数-然后调用基类的析构函数
4. 类如果定义类虚函数，则最好将析构函数也定义成虚函数
5. 不允许虚函数作为构造函数

## 面向对象的特性
1. 封装（Encapsulation）
   - 将数据和操作数据的方法绑定在一起，形成一个独立的对象
   - 隐藏对象的内部细节，只暴露必要的接口
   - 提高代码的安全性和可维护性

2. 继承（Inheritance）
   - 允许新类基于现有类创建，继承其属性和方法
   - 支持代码重用，减少重复编码
   - 建立类的层次结构，支持多层继承

3. 多态（Polymorphism）
   - 允许使用一个接口来引用不同类型的对象
   - 包括编译时多态（函数重载）和运行时多态（虚函数）
   - 增加代码的灵活性和可扩展性

4. 抽象（Abstraction）
   - 将复杂系统简化为更容易理解的形式
   - 只关注对象的本质特征，忽略非本质的细节
   - 通过抽象类和接口实现

### 多态
多态：多态性是指具有不同功能的函数可以使用相同的函数名，这样就可以用一个函数名调用不同内容的函数。在面向对象方法中一般是这样表述多态性：向不同的对象发送同一条消息，不同的对象在接收时会产生不同的行为（即方法）。也就是说，每个对象可以用自己的方式去响应共同的消息。所谓消息，就是调用函数，不同的行为就是指不同的实现，即执行不同的函数。

多态是面向对象的重要特性,简单点说:“一个接口，多种实现”，指一个基类中派生出了不同的子类，且每个子类在继承了同样的方法名的同时又对父类的方法做了不同的实现，这就是同一种事物表现出的多种形态。

多态性：是指一段程序能够处理多种类型对象的能力

形式：重载多态（函数和运算符重载）， 强制多态（强制类型转换）， 类型参数化多态（模版）， 包含多态（继承及虚函数）

1. 重载多态
    1. 重载是多态性的最简单形式，分为函数重载和运算符重载。
    2. 重定义已有的函数称为函数重载。在C++中既允许重载一般函数，也允许重载类的成员函数。如对构造函数进行重载定义，可使程序有几种不同的途径对类对象进行初始化。
    3. C++允许为类重定义已有运算符的语义，使系统预定义的运算符可操作于类对象。如流插入（＜<）运算符和流提取（>>）运算符（原先语义是位移运算）。

2. 强制多态
    1. 强制多态也称类型转换。
    2. 如C++定义了基本数据类型之间的转换规则，即：
        char→short→ int→unsigned→long→unsigned
        long→ float→ double→long double.
    3. 同时，可以在表达式中使用3种强制类型转换表达式：
        ①static_cast<T>（E）；②T（E）；③（T）E，其中E代表运算表达式，T代表一个类型表达式。上述任意一种都可改变编译器所使用的规则，以便按自己的意愿进行所需的类型强制。
        但是强制多态使类型检查复杂化，尤其在允许重载的情况下，导致无法消解的二义性。

3. 类型参数化多态
    1. 参数化多态即：将类型作为函数或类的参数，避免了为各种不同的数据类型编写不同的函数或类，减轻了设计者负担，提高了程序设计的灵活性。
    2. 模板是C++实现参数化多态性的工具，分为函数模板和类模板。类模板中的成员函数均为函数模板，因此函数模板是为类模板服务的。

4. 包含多态
    1. C++中采用虚函数实现包含多态。虚函数为C++提供了更为灵活的多态机制，这种多态性在程序运行时才能确定，因此虚函数是多态性的精华，至少含有一个虚函数的类称为多态类。包含多态在面向对象程序设计中使用十分频繁。
    2. 派生类继承基类的所有操作，或者说，基类的操作能被用于操作派生类的对象。当基类的操作不能适应派生类时，派生类就需要重载基类的操作。

静态联编（编译时多态）

    联编 （binding）又称绑定，就是将模块或者函数合并在一起生成可执行代码的处理过程，同时对每个模块或者函数分配内存地址，并且对外部访问也分配正确的内存地址。

    在编译阶段就将函数实现和函数调用绑定起来称静态联编（static binding）。静态联编在编译阶段就必须了解所有的函数或模块执行所需要的信息，它对函数的选择是基于指向对象的指针（或者引用）的类型。C语言中，所有的联编都是静态联编，C++中一般情况下联编也是静态联编。

动态联编（运行时多态）

    在程序运行的时候才进行函数实现和函数调用的绑定称为动态联编(dynamic binding) .

    如果在编译“Point *pc=&c”时，只根据兼容性规则检查它的合理性，即检查它是否符合派生类对象的地址可以赋给基类的指针的条件。至于 “pc->area0"调用哪个函数，等到程序运行到这里再决定。

    如果希望 “pc->area（"调用Circle:area（），也就是使类Point的指针PC指向派生类函数area的地址，则需要将Point类的area函数设置成虚函数。

## 内存布局

C++类对象的内存布局受多个因素影响，以下是主要规则：

1. 基本内存布局：
    ```cpp
    class Simple {
        int a;      // 4字节
        char b;     // 1字节
        double c;   // 8字节
        char d;     // 1字节
    };
    // 实际大小：24字节（考虑对齐）

    // 内存布局：
    // a    : 0-3   (4字节)
    // b    : 4     (1字节)
    // pad  : 5-7   (3字节填充)
    // c    : 8-15  (8字节)
    // d    : 16    (1字节)
    // pad  : 17-23 (7字节填充)
    ```

2. 虚函数的影响：
    ```cpp
    class WithVirtual {
        int a;
        virtual void func() {}
        virtual void func2() {}
    };
    // vptr(虚函数表指针) + 成员变量

    // 内存布局：
    // vptr  : 0-7   (8字节，64位系统)
    // a     : 8-11  (4字节)
    // pad   : 12-15 (4字节填充)
    ```

3. 继承关系下的布局：
    ```cpp
    class Base {
        int a;
        virtual void func() {}
    };

    class Derived : public Base {
        int b;
        virtual void func() override {}
    };

    // 内存布局：
    // Base部分：
    //   vptr  : 0-7
    //   a     : 8-11
    // Derived部分：
    //   b     : 12-15
    ```

4. 多重继承：
    ```cpp
    class Base1 {
        int a;
        virtual void func1() {}
    };

    class Base2 {
        int b;
        virtual void func2() {}
    };

    class Derived : public Base1, public Base2 {
        int c;
    };

    // 内存布局：
    // Base1部分：
    //   vptr1 : 0-7
    //   a     : 8-11
    // Base2部分：
    //   vptr2 : 12-19
    //   b     : 20-23
    // Derived部分：
    //   c     : 24-27
    ```

5. 虚继承：
    ```cpp
    class Base {
        int a;
    };

    class Derived1 : virtual public Base {
        int b;
    };

    class Derived2 : virtual public Base {
        int c;
    };

    class Final : public Derived1, public Derived2 {
        int d;
    };
    // Derived1
    //   vptr1 : 0-7
    //   b     : 8-11
    //   pad   : 12-14
    // Derived2
    //   vptr2 : 15-23
    //   c     : 24-28
    //   pad   : 29-30
    // Base部分：
    //   vbptr : 31-39
    //   a     : 40-44
    ```
    * 虚继承会引入额外的虚基类指针(vbptr)
    * virtual base虚基类的内存位于最后一个继承的类的内存之后
    * 最后一个类和它继承的第一个类共享一个虚函数表

    内存分布说明:
    1. vbptr (virtual base pointer): 指向虚基类表
    2. 每个通过虚继承继承Base的类都有自己的vbptr
    3. 虚基类Base的成员被放在对象的末尾
    4. 所有派生类共享同一个Base实例


6. 空类与空基类优化：
    ```cpp
    class Empty {};  // 大小为1字节

    class Derived : public Empty {
        int x;      // 4字节
    };  // 大小为4字节（空基类优化）

    class NonOptimized {
        Empty e;    // 1字节
        int x;      // 4字节
    };  // 大小为8字节（包含填充）
    ```

7. 成员对齐规则：
    ```cpp
    #pragma pack(push, 1)  // 设置1字节对齐
    class Packed {
        char a;    // 1字节
        int b;     // 4字节
        char c;    // 1字节
    };  // 大小为6字节
    #pragma pack(pop)

    class Normal {
        char a;    // 1字节
        int b;     // 4字节
        char c;    // 1字节
    };  // 大小为12字节（默认对齐）
    ```

8. 位字段：
    ```cpp
    class Bitfields {
        unsigned int a : 1;  // 1位
        unsigned int b : 2;  // 2位
        unsigned int c : 29; // 29位
    };  // 通常占用4字节
    ```

关键规则：
1. 对齐规则
2. 虚函数表指针位置
3. 继承关系影响
4. 空基类优化
5. 成员变量顺序
6. 虚继承的特殊处理

影响因素：
1. 编译器实现
2. 平台架构
3. 对齐要求
4. 继承方式
5. 成员访问控制
6. 虚函数的存在

性能考虑：
1. 缓存对齐
2. 内存访问效率
3. 对象大小
4. 虚函数调用开销
5. 多重继承开销

最佳实践：
1. 合理排列成员变量顺序
2. 注意对齐要求
3. 慎用多重继承
4. 利用空基类优化
5. 考虑内存布局对性能的影响

调试技巧：
```cpp
// 查看对象大小
cout << sizeof(MyClass) << endl;

// 查看成员偏移
cout << offsetof(MyClass, member) << endl;

// 使用调试器查看内存布局
// 使用sizeof运算符
// 使用编译器特定的工具
```

注意事项：
1. 不同编译器可能有差异
2. 平台相关性
3. 对齐要求的影响
4. 继承关系的复杂性
5. 虚函数的开销

## 虚函数

当调用虚函数时，先通过vptr找到虚函数表，指向thunk代码段
1. thunk代码段对 this 指针进行调整
2. 跳转到虚函数的真正地址执行

派生类能继承基类的虚函数表，而且只要是和基类同名（参数也相同）的成员函数，无论是否使用virtual声明，它们都自动成为虚函数。如果派生类没有改写继承基类的虚函数，则函数指针调用基类的虚函数。如果派生类改写了基类的虚函数，编译器将重新为派生类的虚函数建立地址，函数指针会调用改写以后的虚函数。

虚函数的调用规则是：根据当前对象，优先调用对象本身的虚成员函数。这和名字支配规律类似，不过虚函数是动态联编的，是在运行时（通过虚函数表中的函数地址）“间接”调用实际上欲联编的函数。


1. 虚函数的定义
    1. 虚函数只能是类中成员函数，且不能是静态的。在成员函数定义或声明前面加上关键字virtual，即定义了虚函数：
        ```cpp
        class 类名｛//类体
            virtua1 返回类型 函数名（形式参数列表）;//虚函数
        ｝；
        Class Point ｛ //Point类表示平面上的点
            virtual double area（）;//虚函数声明
            virtual double volumn（） ｛ return 0;｝//虚函数定义
        ｝；
        ```

    2. 需要注意，virtual只在类体中使用。
    3. 当在派生类中定义了一个同名的成员函数时，只要该成员函数的参数个数、参数类型以及返回类型与基类中同名的虚函数完全一样，则派生类的这个成员函数无论是否使用virtual，它都将成为一个虚函数。
    4. 程序员习惯给派生类的同名函数也加上virtual，便于阅读理解。
    5. 利用虚函数，可在基类和派生类中使用相同的函数名定义函数的不同实现，从而实现“一个接口，多种方式”。当用基类指针或引用对虚函数进行访问时，系统将根据运行时指针或引用所指向或引用的实际对象来确定调用对象所在类的虚函数版本。
    6. 关键字virtual指示C++编译器在调用虚函数时进行动态联编。这种多态性是程序运行到相应的语句时才动态确定的，所以称为运行时的多态性。
    7. 不过，使用虚函数并不一定产生多态性，也不一定使用动态联编。
        例如，在调用中对虚函数使用成员名限定，可以强制C++对该函数的调用使用静态联编。

2. 虚函数实现多态的条件
    1. 类之间的继承关系满足赋值兼容性规则；
    2. 改写了同名的虚函数；
    3. 根据赋值兼容性规则使用指针（或引用）。

    满足前两条并不一定产生动态联编，必须同时满足第3条才能保证实现动态联编。

    第3条分为两种情况：
    1. 使用基类指针（或引用）访问虚函数。例如：
        ```cpp
        Point *p=new Circle；//基类指针指向派生类cout<<p->area（）；//动态联编
        ```
    2. 把指针（或引用）作为函数参数，这个函数不一定是类的成员函数，可以是普通函数，而且可以重载。例如：
        ```cpp
        void fun(Point *p)
        ｛ cout<<p->area（）；｝//动态联编
        ```
3. 虚函数表
    1. 在多继承情况下，编译器会为每一个类生成唯一的虚函数表，存放在rodata只读数据段，所有类的实例共享该虚函数表

    2. 子类对一个虚函数的重写，会重写所有基类虚函数表中该虚函数的地址

    3. 每个子类的虚函数表都包含基类子对象的虚函数表


何时需要虚函数？
1. 首先看成员函数所在的类是否会作基类。然后看成员函数在类的继承后有无可能被更改功能，如果希望派生类更改其功能的，一般应该将它声明为虚函数。
2. 如果成员函数在类被继承后功能不需修改，或派生类用不到该函数，则不要把它声明为虚函数。不要仅仅考虑到要作为基类而把类中的所有成员函数都声明为虚函数。
3. 应考虑对成员函数的调用是通过对象名还是通过基类指针或引用去访间，如果是通过基类指针或引用去访问的，则应当声明为虚函数。
4. 使用虚函数，系统要增加一定的空间开销用来存储虚函数表，但系统在进行动态联编时的时间开销是很少的，因此，多态性是高效的。


1. 纯虚函数
    在许多情况下，不能在基类中为虚函数给出一个有意义的定义，这时可以将它说明为纯虚函数（pure virtual function），将具体定义留给派生类去做。纯虚函数的定义形式为：
    ```cpp
    virtual 返回类型 函数名（形式参数列表）=0；
    ```
    即在虚函数的原型声明后加上 “=0”，表示純虚函数根本就没有函数体。

    纯虛函数的作用是在基类中为其派生类保留一个函数的名字，以便派生类根据需要对它进行定义。如果在一个类中声明了纯虚函数，而在其派生类中没有对该函数定义，则该虚函数在派生类中仍然为纯虚函数。

    包含有纯虚函数的类称为抽象类（abstract class）。一个抽象类只能作基类来派生新类，所以又称为抽象基类（abstract baseclass）。抽象类不能定义对象。

    如果在派生类中给出了抽象类的纯虚函数的实现，则该派生类不再是抽象类。否则只要派生类仍然有纯虚函数，则派生类依然是抽象类。抽象类至少含有一个虚函数，而且至少有一个虚函数是纯虚函数。

虚函数执行步骤：
1. 对this指针进行调整
2. 执行真正的虚函数

## 继承和派生
1. 继承和派生的概念
    1. 继承：在定义一个新的类B时，如果该类与某个已有的类A相似（指的是B拥有A的全部特点），那么就可以把A作为一个基类，而把B作为基类的一个派生类（椰城子类）。
        1. 派生类是通过对基类进行修改和扩充得到的。在派生类中，可以扩充新的成员变量和成员函数。
        2. 派生类一经定义后，可以单独使用，不依赖于基类。
    2. 派生类拥有基类的全部成员函数和成员变量，不论是private、protected、public.
        1. 在派生类的各个成员函数中，不能访问基类中的private成员。
        ```cpp
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
    ```cpp
    class CBase {
        int v1, v2;
    };
    class CDerived:public CBase {
        int v3;
    };
    ```

## 复合关系和继承关系
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

## 类内初始化器
当使用多个构造函数时，成员初始化可以是重复的
```cpp
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
```cpp
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
## 类内函数定义
如果一个函数不仅在类中声明，还在类中定义，那么它就被当作内联函数处理(见 12. 1.5 节)，即很少修改且频繁使用的小函数适合类内定义。类似所属类的定义，可在多个编译单元中使用#include 重复类内定义的成员函数，无论在哪里使用#include，其含义都 应 保 持 一致

类 成 员 可 以 访 问 同 类 的 其 他 成 员 ， 而 不 管 成 员 是 在 哪 里 定 义 的 ( 见 6 . 3 . 4 节 )。 考 虑 下 面 的代码:
```cpp
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
## 可变性
我们可以定义具名的常量对象或变量对象 。换句话说，一个名字指向的既可以是一个 保存不可变值的对象，也可以是 一个保存可变值的对象。由于精确术语可能有些笨拙，我们 最终采用的描述方式是:称某些变量是常量，或者更简单地称之为c onst 变量 。无论这种描 述对一个以英语为母语的人来说有多么奇 ，概念本身还是非常有用的，而且已深深植入了 C++类型系统中。系统地使用不可变对象有利于产生更易理解的代码，有利于尽早发现更多 错误，而且有时会提高性能。特别是，不可变性在多线程编程中是一个非常有用的特性

为了使不可变性不局限 于内置类型的简单常量的定义，我们必须能定义可操作用户自 定义c onst 对象的函数。对独立函数而言，这意味着函数可接受c onst T&参数。对类而言， 这意味着我们必须能定义操作const 对象的成员函数。

## 常量成员函数
到 目 前 止 我 们 所 定 义 的 D a t e 提 供 了 一些 能 D a t e 赋 值 的 函 数 。 不 幸 的 是 ， 我 们 没 有提供检查Date 值的方法。通过增加读取天、月和年的函数，可以很容易地弥补此不足
```cpp
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

## 物理常量性和逻辑常量性

物理常量性和逻辑常量性

有时，一个成员函数逻辑上是c onst，但它仍然需要改变成员的值。即对 一个用户而 言，函数看起来不会改变其对象的状态，但它更新了用户不能直接观察的某些细节。这通常 被 称 为 逻 辑 常 量 性 ( l o g i c a l c o n s t n e s s )。 例 如 ， 类 D a t e 可 能 有 一 个 返 回 字 符 串 表 示 的 函 数 。 构造这个字符串表示非常耗时，因此，保存一个拷贝，在反复要求获取字符串表示时可以简 单 地 返 回 此 拷 贝 (除 非 D a t e 的 值 已 被 改 变 )， 这 就 很 有 意 义 了 。 更 复 杂 的 数 据 结 构 常 使 用 这 种缓存值的技术，但我们现在只讨论对Dat e 如何使用这种技术
## 间接访问实现可变性
对于小对象的表示形式只有 一小部分允许改变的情形，将成员声明为mutable 是最适 合的。但在更复杂的情况下，通常更好的方式是将需要改变的数据放在 一个独立对象中，间 接地访问它们。如果采用这种技术，字符串缓存例程会变为
```cpp
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
## 自引用
我们定义的状态更新函数add_year()、add_month()和add_day()(见16.2.3 节)是不 返回值的 。对这样一组相关的更新函数，一种通常很有用的技术是令它们返回已更新对象的 引用，这样这些操作就可以串接起来。

为此，必须将每个函数都声明为返回 一个Date引用

每个(非static)成员函数都知道是哪个对象调用的它，并能显式引用这个对象

在非static成员函数中，关键字this 是指向调用它的对象的指针。在类X的非const 成员函数中，this 的类型是X* 。但是，this 被当作 一个右值，因此我们无法获得this 的地 址或给它赋值。在类× 的const 成员函数中，this 的类型是const X*，以防止修改对象

this 的使用大多数是隐式的。特别是，每当我们引用类内的一个非static 成员时，都是 依 赖 于 一次 t h i s 的 隐 式 使 用 来 获 得 恰 当 对 象 的 该 成 员

this 的 一种常见的显式应用是用于链表操作。

## 成员访问
我们可以通过对类×的对象使用，(点)运算符或对X的对象的指针使用 ->(箭头)运 算符来访问× 的成员
```cpp
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

## static成员

1. 静态成员：在定义前面加了static关键字的成员
    ```cpp
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
    ```cpp
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
    ```cpp
    CRectangle::PrintTotal();
    ```

2. 对象名.成员名
    ```cpp
    CRectangle r; r.PrintTotal();
    ```

3. 指针->成员名
    ```cpp
    CRectangle * p = &r;
    p->PrintTotal();
    ```

4. 引用.成员名
    ```cpp
    CRectangle & ref = r;
    int n = ref.nTotalNumber;
    ```

## 具体类
如果 一个类的表示是其定义的一部分，我们就称它是具体的(concrete，或称它是一个 具体类)。这将它与抽象类(见3.2.2 节和20.4 节)区分开来，后者为多种实现提供一个公共 接又。在定义中明确类的表示方式令我们能:

* 将对象置于栈、静态分配的内存以及其他对象中;

* 拷 贝 和 移 动 对 象 ;

* 直接引用具名对象(与通过指针和引用访问不同)。 这令具体类易于推断，编译器也容易为之生成优化的代码。因此，我们倾向于对频繁使用且 性能攸关的小类型使用具体类，例如复数、智能指针和容器。

这组操作对一个用户自定义类型而言是非常典型的:

[1] 一个构造函数指出此类型的对象/ 变量如何初始化。

[2]一组允许用户检查Date 的函数。这些函数标记为const，表明它们不会修改调用 它们的对象/ 变量的状态。

[3] 一组 允 许 用 户 无 须 了 解 表 示 细 节 也 无 须 摆 弄 复 杂 语 法 即 可 修 改 D a t e 的 函 数 。

[4] 隐 式 定 义 操 作 ， 允 许 D a t e 自 由 拷 贝

[5] 类Bad _date，用来报告错误、抛出异常。

[6] 一组有用的辅助函数。这些函数不是类成员，不能直接访问Date的表示，但我 们认为它们与名字空间Chr ono 的使用是相关的。

### 具体类的重要性

称Date这样的简单用户自定义类型为具体类型(concretetype)，以区别于抽象类和类层次，并强调它们与int和char这样的内置类型相似。具体类的使用就像内置类型一样。具体类型也称为值类型(valuetype)，使用它们编程称为面向值的程序设计(value-orientedprogramming)。它们的使用模型和设计背后的“哲学”与常见的面向对象编程。

一个具体类型的目标是高效地做好一件相对简单的事情，为用户提供修改其行为的特性 通 常 不 是 其 目 标 。 特 别 是 ， 展 现 运 行 时 多 态 行 为 也 不 是 其 意 图 。

如果不喜欢一个具体类型的某些细节，你可以构建一个新的类型，只要实现所需行 为即可。如果希望“重用” 一个具体类型，你可以用它实现新类型，就像使用int一样。 例如:
```cpp
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


## 辅助函数
一般而言， 一个类都会有一些无须定义在类内的关联函数，因为它们不需要直接访问类 的表示。
```cpp
int diff(Date a, Date b);
bool is_leapyeear(int y);
bool is_date(int d, Month m, int y);
const Date& default_date();
Date next_weekday(Date d);
Date next_saturday(Date d);
```
还有一种替代方法是将类及其辅助函数放在一个名字空间中来显式表明两者的关联

## 重载运算符

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
        ```cpp
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
        ```cpp
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

### 赋值运算符的重载
赋值运算符‘=’重载
1. 赋值运算符两边的类型可以不匹配
    1. 把一个int 类型变量赋值给一个complex对象
    2. 把一个char*类型的字符串赋值给一个字符串对象
2. 需要重载赋值运算符‘=’
3. 赋值运算符‘=’只能重载为成员函数

重载赋值运算符的意义：
1. **浅拷贝**：只复制指针或引用，复制后两个对象共享同一块内存，可能导致双重释放问题，一个对象的修改会影响另一个对象
    ```cpp
    char* S1 = "this";
    char* S2 = S1;
    ```

2. **深拷贝**：创建新的内存空间，复制实际的数据内容，两个对象完全独立，需要正确实现拷贝构造函数和赋值运算符
    ```cpp
    std::string S1 = "this";
    std::string S2 = "that";
    S1 = S2;
    ```

### 自加自减运算符的重载
1. 自加++/自减--运算符有前置/后置之分
2. 前置运算符作为一元运算符重载
    1. 重载为成员函数：
        ```cpp
        T operator++();
        T operator--();
        ```
    2. 重载为全局函数：
        ```cpp
        T operator++(T);
        T operator--(T);
        ```
    3. ++obj, obj.operator++(), operator++(obj)都调用上述函数
3. 后置运算符作为二元运算符重载
    1. 多写一个参数，具体无意义
    2. 重载为成员函数
        ```cpp
        T operator++(int);
        T operator--(int);
        ```
    3. 重载为全局变量
        ```cpp
        T operator++(T,int);
        T operator--(T,int);
        ```
    4. obj++,obj.operator++(0),operator++(obj,0)都调用上函数
4. int作为一个类型强制转换运算符被重载，
    ```cpp
    Demo s;
    (int) s;
    ```

5. 类型强制转换运算符时，
    1. 不能写返回值类型
    2. 实际上其返回值类型-类型强制转换运算符代表的类型

运算符重载的注意事项
1. C++不允许定义新的运算符
2. 重载后运算符的含义应该符合日常习惯
    1. complex_a + complex_b
    2. word_a > word_b
    3. date_b = date_a + n
3. 运算符重载不改变运算符的优先级
4. 以下运算符不能被重载：".", ".*", "::", "?:", sizeof
5. 重载运算符（），[], ->或者赋值运算符=时，重载函数必须声明为类的成员函数

### 运算符重载为友元函数
1. 通常，将运算符重载为类的成员函数
2. 重载为友元函数的情况：
    1. 成员函数不能满足使用要求
    2. 普通函数，又不能访问类的私有成员
        ```cpp
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

## 从客观事物抽象出类的例子
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
    ```cpp
    CRectangle r1, r2;
    r1.w = 5;
    r2.init(3,4);
    ```
2. 用法二：指针->成员名
    ```cpp
    CRectangle r1, r2;
    CRectangle * p1 = & r1;
    CRectangle * p2 = & r2;
    p1->w = 5;
    p2->init(3,4);
    ```
3. 用法三：引用名.成员名
    ```cpp
    CRectangle r2;
    CRectangle & rr = r2;
    rr.w = 5;
    rr.init(3,4);

类成员函数的另一种写法

    成员函数分开写

## 内联成员函数和重载成员函数

1. 内联成员函数
    1. inline + 成员函数
    2. 整个函数体出现在类定义内部
    ```cpp
    class b{
        inline void func();
        void func2()
        {
        };
    };
    void b::func1() {}
    ```
2. 使用缺省参数要避免有函数重载时的二义性
    ```cpp
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

## 成员对象和封闭类
1. 成员对象：一个类的成员变量是另一个类的对象
2. 包含成员对象的类叫封闭类
    ```cpp
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

## 友元函数friend
0. 基本定义：
    1. 友元函数是一个可以访问类的私有成员和保护成员的非成员函数
    2. 它不属于类的成员函数，但拥有访问类私有成员的权限
    3. 在类中使用friend关键字声明

1. 友元函数
    1. 一个类的友元函数可以访问该类的私有成员
        ```cpp
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
        ```cpp
        class B {
        public:
            void function();
        };
        class A {
            friend void B::function();
        };
        ```

2. 友元类
    1. A是B的友元类- A的成员函数可以访问B的私有成员
        ```cpp
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

## this指针
1. 其作用就是指向成员函数所作用的对象
2. 非静态成员函数中可以直接使用this来代表该函数作用的对象的指针
    ```cpp
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

## 纯虚函数和抽象类

1. 纯虚函数：没有函数体的虚函数
    ```cpp
    class A{
    private:
        int a;
    public:
        virtual void Print() = 0;
        void func() {cout << "fun";}
    };
    ```
2. 抽象类：包含纯虚函数的类
    1. 只能作为基类来派生新类使用
    2. 不能创建抽象类的对象
    3. 抽象类的指针和引用-有抽象类派生出来类的对象
        ```cpp
        A a; //err
        A * pa;
        pa = new A; //err
        ```

纯虚函数和抽象类
1. 在抽象类中
    1. 在成员函数内可以调用纯虚函数
    2. 在构造函数/析构函数内部不能调用纯虚函数
2. 如果一个类从抽象派生而来-它实现了基类中的所有纯虚函数，才能成为非抽象函数


## 建议
[1] 将 概 念 表 示 为 类 ;

[2] 将 类 的 接 又 与 实 现 分 离 ;

[3]仅当数据真的仅仅是数据且数据成员不存在有意义的不变式时才使用公有数据 (s t r u c t );

[4]定义构造函数来处理对象初始化;

[5]默认将单参数构造函数声明为explicit；

[6]将不修改其对象状态的成员函数声明为const;

[7] 具体类型是最简单的类。只要适用，就应该优先选择具体类型而不是更复杂的类或普通数据结构;16.3 节。

[8]仅当函数需要直接访问类的表示时才将其实现为成员函数;16.3.2 节。

[9]使用名字空间建立类与其辅助函数间的显式关联;16.3.2 节。

[10]将不修改对象值的成员函数定义为const 成员函数;16.3.2 节。

[11] 若 一个 函 数 需 要 访 问 类 的 表 示 ， 但 并 不 需 要 用 某 个 具 体 对 象 来 调 用 ， 建 议 将 其 实现 为 s t a t i c 成 员 函 数 ; 1 6 . 2 . 1 2 节。

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
    ```cpp
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
    ```cpp
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
    ```cpp
    template <class T1, class T2>
    T2 print(T1 arg1, T2 arg2) {
        cout << aeg1 << ""<< arg2 << endl;
        return arg2;
    }
    ```
5. 求数组最大元素的Max Element函数模版
    ```cpp
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
    ```cpp
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
        ```cpp
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
    ```cpp
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
    ```cpp
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
    ```cpp
    Pair <string, int> *p;
    Pair <string, double> a;
    p = &a;
    ```
    函数模版作为类模版成员
```cpp
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
    ```cpp
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
    ```cpp
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
    ```cpp
    template <class T1, class T2>
    class A{T1 v1; T2 v2;};
    template <class T>
    class B:public A<int,double>{T v;};
    int main() {B <char> obj1; return 0;}
    ```
    自动生成两个模版类A<int,double> 和B<char>
3. 普通类派生出类模版
    ```cpp
    class A{int v1;};
    template <class T>
    class B:public A{ T v;};
    int main() {
        B<char>obj1;
        return 0;
    }
    ```
4. 模版类派生出普通类
    ```cpp
    template <class T>
    class A {T v1; int n;};
    class B:public A<int> {double v;};
    int main() {
        B obj1;
        return 0;
    }

# 关键字

## const

1. 常量定义：
    ```cpp
    const int MAX_SIZE = 100;  // 常量值
    const double PI = 3.14159;
    ```

2. 常量指针：
    ```cpp
    // 指向常量的指针 - 不能通过指针修改值
    const int* ptr1 = &value;
    // 等价写法
    int const* ptr2 = &value;

    // 常量指针 - 指针本身不能改变指向
    int* const ptr3 = &value;

    // 指向常量的常量指针 - 两者都不能改变
    const int* const ptr4 = &value;
    ```

    1. 不可通过常量指针修改其指向的内容
    2. 不能把常量指针赋值给非常量指针，反过来可以
    3. 函数参数为常量指针式，可避免函数内部不小心改变参数指针所致地方的内容
    4. 不能通过常引用修改其引用的变量


3. 常量引用：
    ```cpp
    const int& ref = value;  // 不能通过引用修改值
    ```

4. 类中的const成员函数：
    ```cpp
    class MyClass {
    public:
        int getValue() const {  // 承诺不修改类成员
            return value;
        }

    private:
        int value;
    };
    ```

5. 函数参数：
    ```cpp
    // 传递大型对象时避免拷贝
    void printData(const std::vector<int>& data);

    // 防止参数被修改
    void processValue(const int value);
    ```

6. 函数返回值：
    ```cpp
    const std::string& getName() const;  // 返回常量引用
    const int getValue() const;          // 返回常量值
    ```

7. 类的const成员变量：
    ```cpp
    class Config {
        const int MAX_CONNECTIONS = 100;  // 常量成员
        static const int TIMEOUT = 30;    // 静态常量成员
    };
    ```

8. const_cast示例：
    ```cpp
    const int constant = 21;
    const int* const_ptr = &constant;
    int* modifiable = const_cast<int*>(const_ptr);
    ```

9. mutable与const：
    ```cpp
    class Cache {
        mutable int accessCount = 0;  // 即使在const函数中也可修改

    public:
        void access() const {
            ++accessCount;  // 合法
        }
    };
    ```
## static

主要用途：
1. 静态存储期管理
2. 限制作用域
3. 共享数据
4. 内存优化
5. 实现单例模式
6. 计数器实现
7. 缓存管理
8. 全局状态管理

注意事项：
1. 静态成员变量必须在类外定义
2. 静态成员函数不能访问非静态成员
3. 静态局部变量只初始化一次
4. 静态全局变量和函数具有文件作用域
5. 多线程环境下需要考虑线程安全
6. 静态成员属于类而不是对象
7. 合理使用可以优化内存使用
8. 过度使用会增加代码耦合度

C++中static的主要用法：

1. 静态局部变量：
    ```cpp
    void counter() {
        static int count = 0;  // 只初始化一次，生命周期持续到程序结束
        count++;
        cout << count << endl;
    }
    ```

2. 静态成员变量：
    ```cpp
    class MyClass {
    private:
        static int count;      // 声明
        static const int MAX = 100;  // const静态成员可以在类内初始化

    public:
        static void printCount() {
            cout << count << endl;
        }
    };

    int MyClass::count = 0;    // 定义，必须在类外初始化
    ```

3. 静态成员函数：
    ```cpp
    class MyClass {
    public:
        static void staticMethod() {
            // 只能访问静态成员
            cout << "Static method" << endl;
        }

        static int getCount() {
            return count;
        }

    private:
        static int count;
    };

    // 调用
    MyClass::staticMethod();
    ```

4. 静态全局变量：
    ```cpp
    // 文件1.cpp
    static int globalVar = 10;  // 只在当前文件可见

    // 文件2.cpp
    static int globalVar = 20;  // 不会冲突，是不同变量
    ```

5. 静态函数：
    ```cpp
    // 只在当前文件可见的函数
    static void helperFunction() {
        // 实现细节
    }
    ```

6. 单例模式：
    ```cpp
    class Singleton {
    private:
        static Singleton* instance;
        Singleton() {}

    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton();
            }
            return instance;
        }
    };

    Singleton* Singleton::instance = nullptr;
    ```
## constexpr
constexpr 是 C++11 引入的关键字，表示"常量表达式"，用于指示表达式或函数可以在编译时求值。
1. constexpr变量
    ```cpp
    #include <iostream>
    #include <array>

    int main() {
        // 基本类型的 constexpr
        constexpr int x = 10;
        constexpr double pi = 3.14159;
        constexpr char letter = 'A';
        constexpr bool flag = true;

        // 基于其他 constexpr 的计算
        constexpr int y = x * 2;           // 20
        constexpr double area = pi * 5 * 5; // 78.5...

        // 用作数组大小
        constexpr int size = 5;
        int static_array[size];            // 编译时确定大小
        std::array<int, size> std_array;   // 编译时确定大小

        std::cout << "x = " << x << ", y = " << y << std::endl;
        std::cout << "Area = " << area << std::endl;

        return 0;
    }
    ```
2. constexpr函数
    ```cpp
    #include <iostream>

    // C++14 允许多个语句、局部变量、循环等
    constexpr int fibonacci(int n) {
        if (n <= 1) return n;

        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    constexpr int sum_range(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; ++i) {
            sum += i;
        }
        return sum;
    }

    // 可以修改局部变量
    constexpr int complex_calculation(int x) {
        int result = x;
        result *= 2;
        result += 10;
        if (result > 100) {
            result /= 2;
        }
        return result;
    }

    int main() {
        constexpr int fib10 = fibonacci(10);      // 55
        constexpr int sum = sum_range(1, 10);     // 55
        constexpr int calc = complex_calculation(50); // 60

        std::cout << "Fibonacci(10): " << fib10 << std::endl;
        std::cout << "Sum 1-10: " << sum << std::endl;
        std::cout << "Complex calc: " << calc << std::endl;

        return 0;
    }
    ```
3. constexpr if

4. constexpr构造函数
    ```cpp
    class Point {
    private:
        double x_, y_;

    public:
        //  constexpr 构造函数允许在编译时创建对象
        // 所有成员必须也是 constexpr 可计算的
        // 可以在编译时进行对象操作和计算
        constexpr Point(double x = 0.0, double y = 0.0)
            : x_(x), y_(y) {}
    }
    ```
## class_template
类模板是一个蓝图，用于生成一系列相似的类,实现代码复用，避免为不同类型编写几乎相同的类,编译器根据模板参数在编译时生成具体的类
主要用法
```cpp
template <typename T>  // 或 template <class T>
class ClassName {
    // 类定义
    // 可以使用T作为类型
};
```

成员函数定义
1. 类内定义
```cpp
template <typename T>
class Box {
public:
    void set(const T& value) { data = value; }
private:
    T data;
};
```

2. 类外定义
```cpp
template <typename T>
void Box<T>::set(const T& value) {
    data = value;
}
```

全特化
```cpp
template <>
class Box<bool> {
    // 针对bool类型的特殊实现
};
```

偏特化
```cpp
template <typename T>
class Box<T*> {
    // 针对指针类型的特殊实现
};
```

## mutable
mutable关键字用于在const成员函数中修改类的某些成员变量。主要用途：
```cpp
class Example {
    mutable int counter;

public:
    void increment() const {
        counter++; // 允许在const成员函数中修改
    }
};

```
## runtime_data_type
Runtime datatype（运行时数据类型）是指在程序运行时而非编译时确定的数据类型信息。这与C++等静态类型语言中编译时已知的类型形成对比。

1. 标签联合
```cpp
enum class Type { Int, Float, String };
struct Value {
    Type type;
    union {
        int i;
        float f;
        const char* s;
    };
};
```
2. 对象包装
```cpp
class Object {
public:
    virtual ~Object() = default;
    virtual Type type() const = 0;
};
```
3. 实体类型
```cpp
using Value = std::variant<int, float, std::string>;
```

## template_const
1. 模板非类型参数中的 const

```cpp
template <const int N>  // N 是编译时常量
class FixedArray {
    int data[N];
public:
    int size() const { return N; }
};
```
2. 模板类型参数中的 const 限定

```cpp
template <typename T>
void print(const T& value) {  // 传递常量引用
    std::cout << value;
}
```

3. 模板类中的 const 成员函数

```cpp
template <typename T>
class Container {
    T* data;
public:
    T get(int index) const {  // 不修改对象状态的成员函数
        return data[index];
    }
};
```

## std::array
固定大小：编译时确定大小，不可改变

栈分配：所有元素存储在对象内部（不像 std::vector 需要堆分配）

零开销抽象：性能与 C 风格数组相当

容器接口：提供迭代器、size() 等方法

1. 声明和初始化
```cpp
#include <array>
#include <iostream>

int main() {
    // 声明并初始化
    std::array<int, 5> arr1{1, 2, 3, 4, 5};  // C++11起可以省略内层花括号

    // 统一初始化
    std::array<int, 3> arr2 = {7, 8, 9};

    // 部分初始化（剩余元素值初始化）
    std::array<double, 4> arr3{1.1, 2.2};  // arr3[2]和arr3[3]为0.0

    // 聚合初始化
    std::array<std::string, 2> arr4 = {"Hello", "World"};
}
```

2. 元素访问
```cpp
std::array<int, 5> arr{10, 20, 30, 40, 50};

// 使用operator[]
int first = arr[0];  // 10
arr[1] = 25;         // 修改第二个元素

// 使用at()（带边界检查）
try {
    int val = arr.at(5);  // 抛出std::out_of_range异常
} catch(const std::out_of_range& e) {
    std::cerr << e.what() << '\n';
}

// 使用front()和back()
int front = arr.front();  // 10
int back = arr.back();    // 50

// 使用data()获取原始指针
int* ptr = arr.data();    // 指向第一个元素的指针
```

3. 容量操作
```cpp
std::array<char, 100> buffer;

// 获取大小
size_t size = buffer.size();      // 100
bool empty = buffer.empty();      // false（因为size != 0）
size_t max_size = buffer.max_size();  // 100（与size()相同）
```

4. 迭代器支持
```cpp
std::array<int, 4> nums{1, 2, 3, 4};

// 使用迭代器遍历
for(auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << " ";
}

// 使用范围for循环（C++11）
for(int num : nums) {
    std::cout << num << " ";
}

// 反向迭代器
for(auto rit = nums.rbegin(); rit != nums.rend(); ++rit) {
    std::cout << *rit << " ";  // 输出: 4 3 2 1
}
```

5. 填充和交换
```cpp
std::array<int, 5> arr;

// 填充相同值
arr.fill(42);  // 所有元素变为42

// 交换两个array（必须是相同类型和大小）
std::array<int, 5> other{1, 2, 3, 4, 5};
arr.swap(other);  // 交换内容
```

## vector
动态数组：在堆上分配连续内存空间存储元素
自动扩容：当容量不足时自动重新分配更大内存
随机访问：支持通过索引直接访问元素（O(1) 时间复杂度）
类型安全：模板化的容器，编译时类型检查
1. 创建和初始化

```cpp
#include <vector>
#include <iostream>

int main() {
    // 空vector
    std::vector<int> vec1;

    // 指定初始大小和值
    std::vector<double> vec2(5, 3.14);  // 5个3.14

    // 使用初始化列表
    std::vector<std::string> vec3{"apple", "banana", "orange"};

    // 从数组构造
    int arr[] = {1, 3, 5, 7, 9};
    std::vector<int> vec4(arr, arr + sizeof(arr)/sizeof(arr[0]));

    // 复制构造
    std::vector<int> vec5(vec4);
}
```

2. 元素访问

```cpp
std::vector<int> nums{10, 20, 30, 40, 50};

// 使用operator[]（无边界检查）
int first = nums[0];  // 10
nums[1] = 25;         // 修改第二个元素

// 使用at()（带边界检查）
try {
    int val = nums.at(5);  // 抛出std::out_of_range异常
} catch(const std::out_of_range& e) {
    std::cerr << e.what() << '\n';
}

// 使用front()和back()
int front = nums.front();  // 10
int back = nums.back();    // 50

// 使用data()获取原始指针
int* ptr = nums.data();    // 指向第一个元素的指针
```

3. 容量管理

```cpp
std::vector<int> vec;

// 获取大小信息
size_t size = vec.size();      // 当前元素数量
bool empty = vec.empty();      // 是否为空
size_t capacity = vec.capacity();  // 当前分配的存储空间

// 改变容量
vec.reserve(100);  // 预分配至少100个元素的空间
vec.shrink_to_fit();  // 减少capacity到匹配size

// 改变大小
vec.resize(10);     // 调整为10个元素，新增元素值初始化
vec.resize(15, 42); // 调整为15个元素，新增元素初始化为42
```

4. 修改操作

```cpp
std::vector<int> vec{1, 2, 3};

// 添加元素
vec.push_back(4);   // 末尾添加4
vec.emplace_back(5); // 直接在末尾构造元素（更高效）

// 插入元素
vec.insert(vec.begin() + 1, 10);  // 在位置1插入10
vec.emplace(vec.begin() + 2, 20); // 在位置2构造插入20

// 删除元素
vec.pop_back();     // 删除末尾元素
vec.erase(vec.begin() + 1);  // 删除位置1的元素
vec.erase(vec.begin() + 1, vec.begin() + 3); // 删除范围[1,3)
vec.clear();        // 清空所有元素
```

5. 迭代器支持

```cpp
std::vector<int> nums{1, 2, 3, 4, 5};

// 使用迭代器遍历
for(auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << " ";
}

// 使用范围for循环（C++11）
for(int num : nums) {
    std::cout << num << " ";
}

// 反向迭代器
for(auto rit = nums.rbegin(); rit != nums.rend(); ++rit) {
    std::cout << *rit << " ";  // 输出: 5 4 3 2 1
}
```

## shareptr共享所有权
多个指针可以共享同一对象，通过引用计数管理生命周期,当最后一个 shared_ptr 被销毁时，对象自动释放,允许拷贝和赋值。

需要多个指针共享同一对象时（如多线程、复杂所有权关系）。

1. 基本创建和使用
```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
std::shared_ptr<int> ptr2(new int(42)); // 不推荐
```

2. 共享所有权
```cpp
std::shared_ptr<int> ptr3 = ptr1; // 引用计数变为 2
auto ptr4 = ptr1;                 // 引用计数变为 3
```

3. 检查引用计数
```cpp
std::cout << ptr1.use_count(); // 输出当前引用计数
```
4. 重置和释放
```cpp
ptr1.reset();        // 引用计数减 1
ptr2 = nullptr;      // 引用计数减 1
```

5. weak_ptr 配合使用（避免循环引用）
```cpp
std::weak_ptr<int> weak = ptr3;
if (auto locked = weak.lock()) {
    // 安全使用对象
}
```

## unique独占所有权
独占对象所有权，不可拷贝，但可以通过 std::move 转移所有权。
更轻量级，性能优于 shared_ptr。

独占资源管理（如工厂模式、RAII 资源封装）。

1. 基本创建和使用
```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(42);
std::unique_ptr<int> ptr2(new int(42)); // 不推荐
```

2. 所有权转移
```cpp
std::unique_ptr<int> ptr3 = std::move(ptr); // ptr 变为 nullptr
```

3. 释放和重置
```cpp
ptr3.reset();           // 释放对象，指针变为 nullptr
ptr3.reset(new int(10)); // 释放旧对象，指向新对象
```

4. 获取原始指针
```cpp
int* raw = ptr3.get(); // 不转移所有权
```

5. 自定义删除器
```cpp
std::unique_ptr<FILE, decltype(&fclose)> file(fopen("test.txt", "r"), &fclose);
```
## auto
编译器根据初始化表达式自动推导变量类型。
简化代码，避免冗长的类型声明。

1. 简化复杂类型声明

```cpp
复制
// 传统写法
std::vector<std::string>::iterator it = vec.begin();
std::unordered_map<std::string, std::vector<int>>::const_iterator iter = map.cbegin();

// 使用 auto
auto it = vec.begin();
auto iter = map.cbegin();
```

2. 模板和泛型编程

```cpp
复制
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {  // C++11
    return t + u;
}

// C++14 更简洁
template<typename T, typename U>
auto add(T t, U u) {
    return t + u;
}
```

3. lambda 表达式

```cpp
复制
auto lambda = [](int x, int y) { return x + y; };
auto result = lambda(3, 4);

// 复杂 lambda
auto predicate = [](const std::string& s) { return s.length() > 5; };
```

4. 范围for循环

```cpp
复制
std::vector<std::string> vec = {"hello", "world"};

// 避免类型错误和冗长声明
for (const auto& str : vec) {
    std::cout << str << "\n";
}

// 修改元素
for (auto& str : vec) {
    str += "!";
}
```

5. 函数返回值

```cpp
复制
auto getVector() {
    return std::vector<int>{1, 2, 3, 4, 5};
}

auto map = std::make_unique<std::map<std::string, int>>();
```

## string
std::string 是 C++ 标准库提供的字符串类，封装了字符序列（char），支持动态内存管理。

底层存储类似 std::vector<char>，但额外优化了字符串操作（如短字符串优化 SSO）。

自动处理内存分配和释放，无需手动管理 \0 结尾。

1. 构造与初始化

```cpp
#include <string>
std::string s1;                // 空字符串
std::string s2 = "Hello";      // 从 C 字符串构造
std::string s3(5, 'a');        // 重复字符："aaaaa"
std::string s4(s2);            // 拷贝构造
std::string s5 = "World"s;     // C++14 字面量后缀 `s`（需 `using namespace std::string_literals`）
```

2. 输入输出

```cpp
std::string s;
std::cin >> s;                  // 读取单词（遇到空格停止）
std::getline(std::cin, s);      // 读取整行（包括空格）
std::cout << s << std::endl;    // 输出
```

3. 与 C 字符串互转

```cpp
// string → C 字符串
const char* cstr = s.c_str();   // 返回只读指针（生命周期随 s）

// C 字符串 → string
const char* cstr = "Hello";
std::string s(cstr);            // 拷贝构造
```
## transform
std::transform 是定义在 <algorithm> 头文件中的一个函数模板，它有两种重载形式：

一元操作版本：对单个范围内的元素进行转换

二元操作版本：对两个范围内的元素进行组合转换

一元操作版本
```cpp
OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);
```
first1, last1：输入范围的迭代器

d_first：输出范围的起始迭代器

unary_op：一元操作函数（接受一个参数）

二元操作版本
```cpp
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op);
```

first1, last1：第一个输入范围的迭代器

first2：第二个输入范围的起始迭代器

d_first：输出范围的起始迭代器

binary_op：二元操作函数（接受两个参数）

1. 一元操作（将vector中的元素加倍）
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v{1, 2, 3, 4, 5};
std::vector<int> result(v.size());

std::transform(v.begin(), v.end(), result.begin(),
    [](int x) { return x * 2; });
// result = {2, 4, 6, 8, 10}
```

2. 二元操作（两个vector相加）
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v1{1, 2, 3};
std::vector<int> v2{4, 5, 6};
std::vector<int> result(v1.size());

std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(),
    [](int a, int b) { return a + b; });
// result = {5, 7, 9}
```
3. 转换为字符串（如你的练习）
```cpp
#include <algorithm>
#include <vector>
#include <string>

std::vector<int> v{8, 13, 21, 34, 55};
std::vector<std::string> result(v.size());

std::transform(v.begin(), v.end(), result.begin(),
    [](int x) { return std::to_string(x * 2); });
// result = {"16", "26", "42", "68", "110"}
```

# STL标准库

# Utilities
## forward完美转发
完美转发指的是将参数以其原始的值类别（左值引用或右值引用）传递给其他函数。

```cpp
#include <iostream>
#include <utility>

void process(int& x) {
    std::cout << "处理左值引用: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "处理右值引用: " << x << std::endl;
}

// 不完美的转发
template<typename T>
void bad_forward(T&& arg) {
    // arg 在这里总是左值，因为它有名字
    process(arg);  // 总是调用 process(int&)
}

// 完美转发
template<typename T>
void perfect_forward(T&& arg) {
    // 使用 std::forward 保持原始值类别
    process(std::forward<T>(arg));
}

int main() {
    int x = 42;

    std::cout << "=== 不完美转发 ===" << std::endl;
    bad_forward(x);      // 左值
    bad_forward(100);    // 右值，但被当作左值处理

    std::cout << "\n=== 完美转发 ===" << std::endl;
    perfect_forward(x);      // 正确转发左值
    perfect_forward(100);    // 正确转发右值

    return 0;
}
```

std::forward的实现原理
```cpp
// std::forward 的简化实现
template<typename T>
constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept {
    return static_cast<T&&>(t);
}

template<typename T>
constexpr T&& forward(typename std::remove_reference<T>::type&& t) noexcept {
    static_assert(!std::is_lvalue_reference<T>::value,
                  "不能将右值转发为左值引用");
    return static_cast<T&&>(t);
}
```

## 引用折叠规则

```cpp
// T&  + &  -> T&   (左值引用 + 左值引用 = 左值引用)
// T&  + && -> T&   (左值引用 + 右值引用 = 左值引用)
// T&& + &  -> T&   (右值引用 + 左值引用 = 左值引用)
// T&& + && -> T&&  (右值引用 + 右值引用 = 右值引用)

template<typename T>
void demo_reference_collapsing(T&& arg) {
    // 当传入左值时：T 推导为 int&，T&& 折叠为 int&
    // 当传入右值时：T 推导为 int，T&& 保持为 int&&
}
```


