# AbstractFactroy
## 1 动机
一系列相互依赖的对象的创建工作；或由于需求变化，往往存在的更多系列对象的创建工作
## 2 定义
提供一个接口，让该接口负责一系列相关或相互依赖对象的创建工作，无需指定它们的具体类
## 3 特点
- 如果不应对多系列对象的创建，则无需使用抽象工厂，用工厂方法即可。
- 同一系列对象之间相互依赖或相互作用，不同系列对象之间不能相互依赖。
- AbstractFactory主要应对系列对象的需求变动，缺点在于难以应对新对象的需求变动。
## 4 代码举例
- DBFactory基类包含创建数据库连接DBConnection，和创建数据库命令DBCommand两个接口。
- DBConnection与DBCommand基类，分别各自派生SQL与Oracle类型的子类。
- Factory派生SQLSQLDBFactory和OracleSQLDBFactory子类，实现的两个创建接口，返回对应SQL或Oracle类型的连接与命令。
- DBCommand执行Excute接口需要传入DBConnection作为参数，不同系列的DBCommand与DBConnection不能兼容。