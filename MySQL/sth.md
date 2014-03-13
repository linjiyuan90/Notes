* change root password
	After installed, root has no password. To set it,
	```
	mysql > UPDATE mysql.user SET Password=PASSWORD('mypassword') WHERE User = 'root';
	mysql > FLUSH PRIVILEGES;
	```
* allow access from other host
	* By upate table
		```
		mysql > use mysql;
		mysql > update user set host = '%' where user = 'root' and host = 'localhost';
		mysql > select host, user from user;
		mysql > flush privileges;
		```
	* By granting (TODO)
		
		