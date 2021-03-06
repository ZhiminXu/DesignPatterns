# Flyweight
## 1 动机
纯对象方案中，大量细粒度的对象充斥系统，从而带来运行代价（主要指内存）；如何避免大量细粒度对象的问题，使用户透明的运用面向对象的方法进行操作。
## 2 定义
运用共享技术有效支持大量细粒度的对象。
## 3 特点
- 解决了面向对象的代价问题，不触及面向对象的抽象问题。
- 通过对象共享降低对象的个数，从而降低内存压力。
- 具体实现方面要注意对象状态的处理。
- 对象数量大导致内存开销要根据实际情况评估，不能凭空臆断。
## 4 代码举例
- Tool工具类派生Hammer锤子类与Saw锯子类，工具有各自的名字Name和使用方法Use
- ToolFactory使用简单工厂模式，根据名字完成工具对象的创建。
- ToolBox类采用提供GetTool方法，通过工具名字返回工具对象。
- ToolsBox包含map容器，GetTool时，优先查找返回创建过的工具对象，没创建过才新建，同时存入map并返回。
