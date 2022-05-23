## 题目描述
开发网站的时候，服务器处理用户传来的数据时需要有足够的鲁棒性，其中就包括对数据格式的检查。现在从网站前端传来了包含用户注册帐号时提交信息的字符串，请你完成后端检验代码，如果存在非法格式的数据，则输出报错信息；如果注册信息正确，则在屏蔽掉私密信息后输出注册信息。

### 格式要求

* 用户名username：长度4-15，由字母或数字或下划线_构成，且首字符必须为字母

* 密码password：长度8-20，为字母和数字的组合，且二者必须都有。

* 邮箱email： 类似`xiaoming@mails.tsinghua.edu.cn`。合法的邮箱满足：@字符前只能包括字母、数字或下划线，@字符后只包括字母、数字、下划线或者.字符，@前后至少各有一个字符。

### 输入数据
输入一行简单的json格式的字符串：字符串首尾为{、}，内部以 键 : 值 的格式记录信息。键和值中不会出现 " 和 : 。不同的键值对之间使用 , 进行分隔。需要注意双引号之外可能存在多余的空格。题目保证在输入数据在json格式上不会出错，所有json字符串都有且只有 username，password，email 三个键。

### 输出要求
* 数据合法时：
  用户名：保留开头三个字符，后续字符用*代替

  密码：所有字符用*代替

  邮箱：除了@与.外的其他字符用*代替。

* 数据不合法时：
  根据三个字段的非法情况输出Illegal [username],[password],[email]，顺序始终按照 username，password，email 的顺序。

  （由于后端只需要检验数据格式的合法性，因此不需要返回具体的错误原因）

### 样例输入
```
{"username":"wrongpass", "password":"abc", "email":"example@qq.com"}
```
```
{"username": "twoillegal?", "email": "test.thu.com", "password": "abc12345"}
```
```
{"password" : "abc12345", "username": "correct", "email": "a@b.c.com"}
```
### 样例输出
对应三个输出分别为
```
Illegal password
```
解释：密码长度过短
```
Illegal username,email
```
解释：用户名中包含除了字母和密码以外的特殊字符?，邮箱不符合题给正则表达式（不含@）
```
Successfully registered.
username: cor****
password: ********
email: *@*.*.***
```
解释：三个字段均合法，按照屏蔽规则输出屏蔽后的信息，注意第一行固定为“Successfully registered.”的提示信息。

### 提交要求
提交一个main.cpp，完成上述要求。

