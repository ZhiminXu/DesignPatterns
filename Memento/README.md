# Memento
## 1 动机
某些对象在转换过程中，出于某种需要，要求能回溯到对象之前某个点时的状态，如果使用公有接口让其他对象的得到对象的状态，会暴露对象实现细节。
## 2 定义
不破坏封装性的前提下，捕获对象内部状态，并在该对象外部保存这个状态，以后可以将该对象回复之前的状态。
## 3 特点
- Memento存储Originator对象的内部状态，需要时恢复。
- Memento的核心是信息隐藏（内部的函数为Protected，不供外界调用，Originator为友元类，只给Originator使用），即Originator需要外界隐藏信息，保持封装性。
- 现代语言运行时都有序列化支持，效率高而且准确，往往用序列化的方案实现Memento。
## 4 代码举例
- Memento类包含GetState和SeState保护方法方法，生命Originator为友元类。
- Originator包含State属性，提供CreateMemento方法，创建Memento备份。
- 在必要时候调用SetMemento方法，传入Memento对象，调用对象GetState方法恢复状态。
