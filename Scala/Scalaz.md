* Memorization
	```scala
	def expensive(foo: Foo): bar = ...
	val cache = collection.mutable.Map[Foo, Bar]()
	cache.getOrElseUpdate(f, expensive(f))
	// more triky way
	val cache: Foo => Bar = collection.mutable.Map[Foo, Bar]().withDefault(expensive _)
	cache(f)
	cache(f)
	// with scalaz
	val memo = immutableHashMapMemo {
		foo: Foo => expensive(foo)
	}
	memo(f)
	memo(f)
	```
	
* others
	```weakHashMap```