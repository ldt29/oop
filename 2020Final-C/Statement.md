## 题目描述
动物园新接收了一批动物。由于接收过程比较匆忙，整个过程分为了两步：

* 园方依次接收所有的动物(Animal)，先暂存在一块区域（buffer）。
* 之后，园方再按照动物种类，包括狗(Dog)和鸟(Bird)，按照接收的顺序将动物移动到相应的区域。

整个过程由以下代码（main.cpp）描述。
```
int main()
{
    Animal* buffer[100];
    vector<Dog> dogzone;
    vector<Bird> birdzone;

    int n;
    cin >> n;

    // step 1: store all animals in buffer
    for(int i = 1; i <= n; i++){
        string type, name;
        cin >> type >> name;
        if(type == "dog")
            buffer[i] = new Dog(name);
        else if(type == "bird")
            buffer[i] = new Bird(name);
    }

    // step2: move animal to the corresponding zone
    for(int i = 1; i <= n; i++){
        action(buffer[i], dogzone, birdzone);
        delete buffer[i];
    }

    // output animals' name and type
    for(auto &dog : dogzone){
        cout << dog << endl;
    }
    for(auto &bird : birdzone){
        cout << bird << endl;
    }

    return 0;
}
```
其中你需要补充头文件action.h，在其中实现
```
void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone)
```
该函数将判断当前animal的类型，并将该动物移动到相应的区域中（利用dogzone.push_back或birdzone.push_back）。

Animal类、Dog类和Bird类都已经写好：
```
class Animal {
private:
    std::string name, type;
public:
    Animal(const std::string &_name, const std::string &_type): name(_name), type(_type) {}

    //Cannot copy animals
    Animal(const Animal &other) = delete;
    //Can move animals
    Animal(Animal &&other): name(other.name), type(other.type) {
        other.name = ""; other.type = "empty";
    }

    //Cannot copy animals
    Animal& operator=(const Animal &other) = delete;
    //Can move animals
    Animal& operator=(Animal &&other){
        if(type != "empty"){
            std::cout << "There has already been an animal here. Cannot move." << std::endl;
        }
        name = other.name; type = other.type;
        other.name = ""; other.type = "empty";
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Animal& animal){
        out << animal.type << " " << animal.name;
        return out;
    }

    //pure virtual destruction
    virtual ~Animal()=0;
};

inline Animal::~Animal()
{
    if(type != "empty"){
        std::cout << "An animal deleted." << std::endl;
    }
}

class Dog: public Animal {
public:
    Dog(const std::string &_name): Animal(_name, "dog") {};
};

class Bird: public Animal {
public:
    Bird(const std::string &_name): Animal(_name, "bird") {};
};
```
### 提示：

* Animal中type变量为private，无法从外部访问。
* dynamic_cast。
* 动物只能移动，不能复制。

文件下载地址：下载链接见problem_62.zip

### 输入说明
输入第一行是n（n≤100），代表接受的动物数量。

接下来nn行，每行两个字符串，分别是动物的种类和动物的名字。

### 输出说明
输出一共2n行。

前n行，每行两个字符串，分别经过分类后动物的种类和动物的名字。

后n行为Animal类的析构信息。

### 输入样例
```
4
bird Jack
dog DogKing
bird Jone
dog BigDog
```
### 输出样例
```
dog DogKing
dog BigDog
bird Jack
bird Jone
An animal deleted.
An animal deleted.
An animal deleted.
An animal deleted.
```
### 提交格式
你只能提交头文件action.h ，我们会将你提交的文件和我们预先设置好的main.cpp, animal.h一起编译运行。

### 评分标准
OJ评分占100%。
