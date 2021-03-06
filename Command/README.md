# Command
## 1 动机
- 行为请求者与行为实现者之间紧耦合，如对行为的记录、撤销、重做、事务处理等，这种不能抵御变化的紧耦合是不合适的。
## 2 定义
- 将请求（行为）封装为对象，使得可以用不同的请求对客户进行参数化，对请求排队或记录请求日志，支持可撤销的操作。
## 3 特点
- Command目的在于行为请求者和行为实现者解耦，将行为抽象为对象
- 实现Command的具体子类有时需要保存一些额外的状态信息（记录命令执行信息，以便支持日志或Redo、Undo）
- 可通过Composite模式将命令封装为复合命令
- Command与C++的函数对象类似。Command以面向对象中的接口实现来定位行为接口规范，更严格但是性能有损失；函数对象用函数签名来定义行为接口规范，更灵活，性能更高。
## 4 代码举例
- Image类包含SetScale方法，可以实现图片缩放比例。
- Command基类提供Redo、Undo、缩放图片Zooming三个接口。
- Command派生ImageProcessCommand（行为请求者），实现三个接口，包含Image指针（行为实现者）在构造函数中传入，包含一个历史缩放比例的数组，和当前操作游标（初始为0）
- Zooming执行时，通过Image指针执行SetScale方法，数组压入缩放参数，游标加一
- Undo时，获取缩放比例数组当前游标上一处的缩放比例，执行缩放的逆操作，游标减一；
- Redo时，获取当前游标处的缩放比例执行缩放，游标加一。
## 5 Tips
有一种观点认为，设计模式的就是为了弥补特定语言设计的不足而出现的，成熟的设计模式慢慢称为语言本身所支持的一种特性。