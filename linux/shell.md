# cmd
## xargs
* -I str
```
find . -name "*.py" | xargs -I {} mv {} {}.py3
```
