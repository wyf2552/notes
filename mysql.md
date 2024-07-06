```sh
ps -ef | grep mysql #查看正在运行的程序
mysql -u root -p #以root用户身份登陆
sudo /usr/local/mysql/support-files/mysql.server start
sudo /usr/local/mysql/support-files/mysql.server stop
touch .zshrc #创建文件
ls /usr/local/mysql/data #查data目录下文件，-a查看全部，-l以list形式查看
cd path #进入到path路径
rm -r #删除一个文件，文件夹加-r
cat file #查看file文件的内容

DDL
create database name default character set utf8; #name数据库名，utf8指定编码
drop database name; #删除数据库
use name; #选择数据库
create table name; #表名（列名 类型，列名 类型···）创建数据表
drop table name; #删除数据表
alter table old_name rename new_name; #修改表名
alter table name change column oid_name new_name type; #修改表列名
alter table name modify name new_type; #修改列类型
alter table name add column new_name type; #添加新列
alter table name drop column name; #删除列名
alter table name add primary key(name); # 修改表添加主键约束
alter table name modify primary_key type auto_increment; # 将主键修改为自增
alter table name modify primary_key type; #去掉自动增长
alter table name drop primary key; #删除主键 若主键具备自动增长的能力，需要先去掉自动增长，然后在删除主键
alter table name add constraint name foreign key (column_name) references table_name(column_name); #修改表添加外键约束
alter table name drop foreign key name; #表名，约束名 删除外键约束
alter table name add constraint name unique(column_name); #表名， 约束名， 列名 添加唯一性约束
alter table name drop key name; #表名，约束名 删除唯一性约束
alter table name modify column_name type not NULL; #表名，列名，类型 修改表添加非空约束
alter table name modify column_name type null; #表名，列名，类型 删除非空约束
show keys from name; # 表名 创建表时添加约束信息

DML #操作数据的语言
insert into name(column_mane 1 , column_name 2...) values(value 1 ，value 2...); #选择插入 添加数据
insert into name values(value 1, value2...); #完全插入 添加数据 表名，值1， 值2，
create table name(column_name type default morenzhi ,...); #表名，列名，类型，默认值，...  默认值处理 创建表时指定列的默认值
alter table name add column name type default morenzhi; #表名，列名，类型，默认值  修改表添加新列并指定默认值
update name set column_name=value, column_name=value where condition; #表名，列名=值，列名=值，条件； 更新数据WHERE
delete from name where codition; #表名，条件； 删除数据DELETE
truncate table name; #表名； TRUNCATE清空表，删除表中的所有数据

select *|{[distinct] column|expression [alias],...} #select确定哪些列
from   table; #from确定哪张表

SELECT *
FROM departments; #查询中的列选择 选择所有列

select department_name  from departments; #选择指定列

select last_name,salary,salary + 300 from employees; #算术表达式，使用算术运算符

select last_name,job_id,salary,commission_pct from employees; #定义空值
SELECT name as name from name where condition; #列名，列别名，表名，条件； 使用列别名
select biaobieming.lieming from biaoming as biaobieming where condition; #表别名.列名 ，表名，表别名，条件； 使用表别名
select department_id from employees; #显示所有的行，包括相同的行
select distinct lieming from biaoming; #列名，表名   除去相同的行
select * | touyinglie from biaoming where xuanzetiaojian; #投影列，表名，选择条件； 查询中的行选择
select last_name,salary from employees where between lower_limit and upper_limit; #使用between条件显示上下限之间的行
select employee_id,last_name,salary,manger_id from employees where manger_id in (100,101,201); #使用in成员条件测试在列表中的值
select first_name from employees where first_name like 's%'; #使用like条件
select last_name,manger_id from employees where manger_id is null; #使用is null 操作测试空值
select last_name,job_id,department_id,hire_date from empliyees order by hire_id; #使用order by 语句排序
select employ_id,last_name,salary*12 annsal from employees order by annsal;  #用列别名排序
select last_name,department_id,salary from employees order by department_id, salary desc; #多列排序
```
整型类型(m是指显示长度)

1. tinyint(m) 1个字节
2. smallint(m) 2个字节
3. mediumint(m) 3个字节
4. int(m) 4个字节
5. bigint(m) 8个字节

浮点类型（m为总个数，d为小数位）

1. float (m, d) 单精度
2. double (m, d) 双精度

字符类型

1. char(n) n为总长度，不够在前用空格补齐
2. varchar(n) n为总长度，不够不用空格补齐
3. text 不用指定长度

日期类型

1. date 日期
2. time 时间
3. datetime 日期时间
4. timestamp 时间戳，考虑时区

二进制数据BLOB

1. BLOB和TEXT存储方式不同，TEXT以文本方式存储，英文区分大小写，而BLOB是以二进制方式存储，不分大小写
2. BLOB存储的数据只能整体读出
3. TEXT可以指定字符集，BLOB不用指定字符集

约束：数据库提供的一种数据校验方式

主键约束PK（唯一性）：

1. 不允许为空
2. 不允许有重复值出现
3. 保证数据唯一性

    主键自增长：
    1. 一个表中只能有一个列为自动增长
    2. 自动增长的列类型必须是整数类型
    3. 自动增长只能添加到具备主键约束与唯一性约束的列上
    4. 删除主键约束或唯一性约束，如果该列拥有自动增长能力，则需要先去掉自动增长然后在删除约束

外键约束FK：

1. 允许空值
2. 允许有重复
3. 值必须是参照表中所包含的值
4. 保证数据参照完整性

唯一约束性U：

1. 相同值只能出现一次
2. 允许为多个列添加唯一性约束
3. 保证数据唯一性

非空约束NN（不能为空）：

1. 列中不能有空值
2. 允许重复值
3. 允许为多个列添加非空约束
4. 保证数据没有空值

检查约束C：

1. 用户自己定义约条件
2. 保证数据满足自定义的约束条件
3. MySQL数据库目前不支持约束条件

SELECT语句功能
1. 列选择 ：能够使用SELECT语句的列选择功能选择表中的列，这些列是想要用查询返回的。当查询时，能够返回列中的数据。
2. 行选择：能够使用SELECT语句的行选择功能选择表中的行，这些行是想要用查询返回的。能够使用不同的标准限制看见的行。
3. 连接：能够使用SELECT语句的连接功能来集合数据，这些数据被存储在不同的表中，在他们之间可以创建连接，查询出我们所关心的数据。

SELECT语句：
|语句|含义|
|----|----|
|SELECT|是一个或者多字段的列表|
|*|选择所有的列|
|DISTINCT|禁止重复|
|column/expression|选择指定的字段或表达式|
|alias|给所选择的列不同的标题|
|FROM table|指定包含列的表|

NUL值处理：
1. null是一个未分配的、未知的，或者不适用的值
2. null不是0，也不是空格
3. 包含空值的算术表达式计算结果为空

用WHERE子句限制从查询返回的行。一WHERE子句包含一个必须满足的条件，WHERE子句紧跟着FROM子句。如果条件是true，返回满足条件的行。

在语法中：

where 限制查询满足条件的行

condition 由列名、表达式、常数和比较操作组成

比较条件
|运算|含义|
|----|----|
|=|等于|
|>|大于|
|>=|大于等于|
|<|小于|
|<=|小于等于|
|<>|不等于|

其他条件比较
|操作|含义|
|----|----|
|between...and...|在两个值之间（包含）|
|in(set)|匹配任意一个值列表|
|like|匹配一个字符模版|
|is null|是一个空值|

使用like 条件
1. 使用like条件执行有效搜索串值的通配符搜索
2. 搜索条件既可以包含文字也可以包含数字：
    1.%表示零个或多个字符
    2._表示一个字符

使用NULL条件

包括is null 条件和 is not null 条件

is null 条件用于空值测试。空值意思是难以获得的，未指定的，未知的或者不适用的。

运算条件
|运算|含义|
|----|----|
|and|如果两个组成部分的条件都为真，返回true|
|or|如果两个组成部分中的任一个条件为真，返回true|
|not|如果跟随的条件为假，返回true|

可以在where子句中用and和or运算符使用多个条件

优先规则
|求值顺序||
|----|----|
|1|算术运算|
|2|连字运算|
|3|比较运算|
|4|is [not] null,like,[not] in|
|5|[not] between|
|6|not 逻辑运算|
|7|and 逻辑运算|
|8|or 逻辑运算|

order by 子句
1. 用order by子句排序行
 1. ASC:升序排序，默认
 2. DESC:降序排序
2. order by 子句在select语句的最后

select 语句的执行顺序如下：
1. from
2. where
3. select
4. order by

