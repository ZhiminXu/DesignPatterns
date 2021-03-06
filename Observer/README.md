# Observer
## 1 动机
通过建立依赖关系，一个对象状态变化，所有依赖的对象得到通知。如果依赖过于紧密，软件不能很好的抵御变化。
## 2 定义
定义对象一对多的依赖关系，当对象变化时，所有依赖它的对象的得到通知并自动更新。
## 3 特点
- Stragety使我们可以独立改变目标和观察者，从而使二者松耦合。
- 目标无需指定观察者，通知会自动传播
- 基于事件的UI框架非常常用的设计模式，也是MVC模式的重要组成部分。
## 4 代码举例
- 一个任务类，需要输出任务处理日志，支持控制台输出、文本输出；但后期可能需要支持其他输出方式。
- 定义一个目标基类类，内部包含一个观察者列表，支持添加删除观察者，提供状态（本例以Log日志作为状态）的Get、Set接口
- 定义一个观察者基类，提供Update更新接口，需要传入目标的指针。
- 目标基类实现Notify通知方法，循环调用观察者的Update更新方法，传入this指针。
- 目标基类派生任务类，任务run方法中，生成Log并调用SetLog；SetLog内部更新log字符串并Notify
- 观察者基类派生控制台日志类和文本日志类，在Upddate更新方法中，通过目标的指针获取目标的Log信息，控制台日志打印输出，文本日志类写入txt文件。
## 5 Tips
C++支持多继承，但是一般不推荐使用多继承，这会带来耦合性问题；推荐以一个主体类继承加多个抽象基类（接口）的方式实现。