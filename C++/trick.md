# sizeof
* returns size in bytes of the object representation of type.
* depending on the computer architecture, a *byte* may consist of 8 or more bits, **CHAR_BIT**
* sizeof(char), sizeof(signed cahr), sizeof(unsigend char) always return 1
* when applied to a class type, the result is the size of an object of that class plus any additional padding
* when applied to an empty class type, always returns 1


* sizeof(int) depends on compiler, not on machine WORD_BIT(Generally, compiler will consider WORD_BIT)
* sizeof(int *) depends on pointer size
* sizeof("ab")  returns the length of the const string + 1, that's 3 in this case
* sizeof(int[10]) returns 
