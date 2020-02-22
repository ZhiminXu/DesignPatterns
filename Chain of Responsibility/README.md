# Chain of responsibility
## 1 动机
一个请求被多个对象处理，每个请求在运行时只有一个接受者，如果显示指定，将给请求的发送者和接受者带来耦合。
## 2 定义
每个对象都有处理请求的机会，将这些对象连城一条链，沿着链条传递请求，知道有一个处理它为止。
## 3 特点
- 一个请求可能有多个接受者，但最后真正的接受者只有一个，这时请求者和接受者的耦合可能出现变化脆弱的症状。
- 运行时动态添/修改请求的处理职责；
- 责任链到末尾仍不处理请求时，应当有一个缺省的处理机制。
## 4 代码举例
- Request基类包含请求级别，请求描述。请求级别分为一二三级，一级最高。
- Handler基类包含一个后继者的Handler指针，在构造函数中传入，以及canHandleRequest、HandleRequest两个虚函数，分别传入Request对象指针，由子类实现。
- Handler基类包含Handle方法，传入Request对象指针，如果canHandleRequest判断自身可以处理请求，则调用HandleRequest完成处理，如果不能，交给后继者Handler的Handle函数处理。
- Handler基类派生Headman组长、Manager经理、Boss老板三个类、Manager作为Headman后继，Boss作为Manager后继，Boss无需后继。
- Headman可以处理三级请求如请假，Manager可以处理二级以下请求，如请求加薪，Boss可以处理所有请求，如请求升职。