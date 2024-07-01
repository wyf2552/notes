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
create database name default character set utf8; #name数据库名，utf8指定编码
drop database name; #删除数据库
use name; #选择数据库

```