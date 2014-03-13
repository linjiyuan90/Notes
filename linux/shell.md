* zsh
	array index is started from 1 while 0 in bash?
* eval
* nc
	```shell
		nc -zv host port >/dev/null; echo $?
	```
* change user
  after changing user by using `su`, the environment will also consist of previous ones.
* split array
	```shell
	IN="bla@some.com;john@home.com"
	arrIN=(${IN//;/ })
	line="12 34"
	arrLine=($line)
	echo ${arrLine[1]]}
	```