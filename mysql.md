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