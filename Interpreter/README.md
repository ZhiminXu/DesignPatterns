# Interpreter
## 1 动机
某一领域问题比较复杂，类似结构不断重发发现，使用普通编程方式将面临频繁变化。将特定领域问题表达为某种规则语法下的句子，用解析器解析句子，从而解决问题。
## 2 定义
给定一个语言，定义他的文法的一种表示，并定义一种解析器，由解析器使用该表示来解析语言中的句子。
## 3 特点
- Interpreter应用场合是本模式应用中的难点，需满足业务规则频繁变化，类似结构不断重复且容易抽象为语法规则。
- Interpreter模式表示文法，可以用面向对象的方式扩展文法
- Interpreter适用于简单文法，复杂文法（可能大致比较大的类层次结构）需要用语法分析生成器这样的标准工具。
## 4 代码举例
- 实例代码展示的是通过解析器模式解决+-二则运算，map<char,int>记录运算式中的每一个字符对应的数值。
- Expression基类包含Interpreter接口，传入map，返回运算值int。
- Expression派生VarExpression构造函数传入char，实现Interpreter，返回map中key为char的value
- Expression派生SymbolExpression，包含left、right两个Express*指针，构造函数传入。
- SymbolExpression派生AddExpression，SubExpression，分别返回left与right解析结果的和与差。
- Analyzer类传入二则运算算式，通过栈操作解析算式，利用Expression解析算法，返回结果。

