
# Multi-thread safe & reentrant
## difference between Multi-thread safe & reentrant
* reentrancy
  The permanent part is the code, and the temporary part is the pointer back to
  the calling program and **local variables** used by that program.
## others
* when a method is not [MT-safe](http://stackoverflow.com/a/4031528/3117578), you shold look for same method with suffix_r meaning `reentranted`. For example `strtok_r` is an reentranted version of `strtok`.
