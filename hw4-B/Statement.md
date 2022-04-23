## 题目描述
map类是stl库中经常用到的一类结构，它实现了构建两个任意类型变量的映射关系，但它的实现是基于比较的，每次查询可能需要多达十几次比较。

HashTable也实现了同样的功能——将任意类型变量A映射到任意类型变量B，但效率更高。

具体而言，储存数据时，它将A通过一个固定的算法函数——称为哈希算法（Hash），得到一个数值，称为哈希值，记作Hash(A)。接下来，我们会将B储存在HashTable的第Hash(A)个位置。其中，A被称为关键字（key），B被称为关键字值（value），构造的映射关系称为键值对。

查询时，我们给出关键字A，然后通过哈希算法得到Hash(A)，最后再访问HashTable的第Hash(A)，得到需要查询的关键字值B。

举个例子：

假设固定对string类型的哈希算法为：从下标0到length-1，将每个字符的ASCII码相加，最后对数组长度n取模，得到数组下标。  
当n=10时，字符串ABC的哈希值就是

(int('A')+int('B')+int('C'))mod10=(65+66+67)mod10=8(int('A')+int('B')+int('C'))mod10=(65+66+67)mod10=8

因此，构建ABC映射到XYZ的关系时，XYZ就被放在数组下标为8的位置。

从这个例子上我们可以发现两点：

长度为3的字符串的个数就已经远超过10个，而上述算法是对于任意长度的字符串都能使用，得到的结果均为0-9。因此，哈希算法是一种压缩算法，也就是，哈希值的空间通常远小于输入的空间。
不难看出，上述算法中ABC和CBA对应的哈希值相等，因此查询ABC和CBA会出现冲突，这就是哈希冲突，这是压缩算法无法避免的问题，但在本题中不需要考虑哈希冲突的问题。
如果想要深入了解map或hash table的原理，可以参考以下网址：

how does a hash table work
哈希表（散列表）原理详解
map和HashMap原理详解
我们需要同学在给出的模板函数类Hash的基础上，完善并实现模板类HashTable。

Hash.h
```
template <typename T>
class Hash
{
private:
    int n;

public:
    Hash(int _n) : n(_n) {}
    int operator()(const T &x);
};

template<>
int Hash<int>::operator()(const int &x)
{
    return x % n;
}

template<>
int Hash<std::string>::operator()(const std::string &x)
{
    int ret = 0;
    for (char c : x)
    {
        ret += static_cast<int>(c);
        ret %= n;
    }
    return ret;
}
```
HashTable.h
```
template <typename T1, typename T2>
class HashTable
{
// TODO: Add member variables
public:
    void addItem(const T1 &key, const T2 &value);
    void removeItem(const T1 &key);
    T2 *findByKey(const T1 &key);
};
```
同时main.cpp也已经给出，具体参考下载文件。

文件下载地址：下载链接,见problem_89.zip

提示：模板类的实现应该放在头文件中。Hash类的实现使用了模板的特化，可参考课程自学部分或网上资料

### 输入格式
第一行包含用空格分隔的四个正整数n1，n2，n3，n4，表示

* int映射到int的哈希表元素总个数不超过n1。
* int映射到string的哈希表元素总个数不超过n2。
* string映射到int的哈希表元素总个数不超过n3。
* string映射到string的哈希表元素总个数不超过n4。
接下来一行包含一个正整数p，表示之后有p个操作。     
对每个操作给出一行，包含一个正整数opr，和若干个参数，用空格分隔，opr表示操作类型，如下：

* opr为1时，参数为两个整数a和b，表示建立a到b的映射关系；
* opr为2时，参数为一个整数a和一个字符串b，表示建立a到b的映射关系；
* opr为3时，参数为一个字符串a和一个整数b，表示建立a到b的映射关系；
* opr为4时，参数为两个字符串a和b，表示建立a到b的映射关系；
* opr为-1时，参数为一个整数a，表示删除a到整数的映射关系；
* opr为-2时，参数为一个整数a，表示删除a到字符串的映射关系；
* opr为-3时，参数为一个字符串a，表示删除a到整数的映射关系；
* opr为-4时，参数为一个字符串a，表示删除a到字符串的映射关系；    
接下来一行包含一个正整数q，表示之后有q个查询。  
对每个操作给出一行，包含一个正整数opr，和另一个参数，用空格分隔，opr表示操作类型，如下：

* opr为1时，参数为整数a，表示输出a映射到的整数；
* opr为2时，参数为整数a，表示输出a映射到的字符串；
* opr为3时，参数为字符串a，表示输出a映射到的整数；
* opr为4时，参数为字符串a，表示输出a映射到的字符串；  
### 输出格式
对每个查询输出一行，包含查询到的整数或字符串，若查询的映射关系不存在，则输出NULL。

### 输入样例
```
10 1 1 10
2
1 8 10
4 aut bst
5
1 9
1 8
4 aut
3 tjh
4 gc
```
### 输出样例
```
NULL
10
bst
NULL
NULL
```
### 数据规模和约定
1≤n1,n2,n3,n4≤5000, 1≤p,q≤10000  
所有输入的字符串长度不大于100    
不需考虑哈希冲突相关问题，如果出现关键字哈希值相同，则之后出现的映射关系覆盖之前的映射。

时间限制：1s，空间限制：256MB

### 提交格式
根据提供的main.cpp、HashTable.h和Hash.h的内容，编写HashTable类的代码并完善HashTable.h与Hash.h。  
应该将文件打包成一个zip压缩包并上传。评测时，OJ会将提供的main.cpp和Makefile贴入目录下进行编译并执行。
