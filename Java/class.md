# static nested class and non-static nested class (inner class)
* if the nested class doesn't use any field of the outer class, mark it as `static`, then you can
```
new Outer.Inner()
// than
new Outer().new Inner()  // which is a non-static nested class
```
