# curl
* -x proxy, -U user:proxy
```
$ curl -x proxy:port -U user:pass url
```
* -X, --data
```
$ curl --header "content-type: application/json" -X POST --data '{name:
"xxx"}' http://host:port/service/query
```
