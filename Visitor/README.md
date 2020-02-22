# Visitor
## 1 动机
由于需求的变化，在类层级结构中需要增加新的行为，如果直接在基类中修改，将带来沉重的变更负担，甚至破坏原有设计。不改变类层次结构的前提下，运行时根据需要透明地为类层次结构动态的添加新操作。
## 2 定义
定义一个作用于某对象结构的各个元素的操作，使得可以在不改变各元素的类的前提下，扩展作用于这些元素的新操作。
## 3 特点
- 通过双重分发来实现不改变Element类层次结构的前提下，在运行时动态添加新操作。
- 双重分发包含两个多态分发，一个为Accept多态，一个为VisitElement多态
- Visitor缺点在于廓镇Element类层次结构会导致Visitor类改变，因此Visitor适用于Element类层次结构稳定而操作经常改动的场景。
- Visitor的应用要求在类设计阶段具有一定的预见性。
## 4 代码举例
- Element基类包含接口Accept接口，传入Visitor指针；派生ElementA与ElementB两个子类
- Visitor基类包含visitElementA、VisitElmentB接口，分别传入ElementA与ElementB指针
- ElementA实现Accept接口，内部调用visitor的VisitiElementA方法，传入this指针，包含OperationA方法；ELementB类似。
- Visitor基类派生ConcreteVisitor子类，实现visitElementA，调用ElementA的OperationA方法，并增加新的功能；ELementB类似。