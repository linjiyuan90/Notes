http://stackoverflow.com/a/561450
http://www.linuxhowtos.org/System/Linux%20Memory%20Management.htm

## Virtual memory
	The virtual size of a process, which is the sum of memory it's actually using, memory it has mapped into itself, files on disk that have been mapped into it (most notably shared libraries), and memory shared with other processes.
	Use `pmap pid` to see a process's virtual memory address.
	
## Resident Set size (RES)
	 `RES` stands for the resident size, which is an accurate representation of how much actual physical memory a process is consuming. 

	`SHR` indicates how much of the VIRT size is actually sharable memory or libraries). In the case of libraries, it does not necessarily mean that the entire library is resident. For example, if a program only uses a few functions in a library, the whole library is mapped and will be counted in VIRT and SHR, but only the parts of the library file containing the functions being used will actually be loaded in and be counted under RES.

## Swap
	If the physical memory is not enough, swap are used. Take care of this situation!
	
## Cache
	Most physcial mem are occupied by cache, to see the actual free memory, use `free`, the `-/+ buffers/cache` is the actual freed memory.
	
## Buffer
	Buffers are associated with a specific block device, and cover caching of filesystem metadata as well as tracking in-flight pages. The cache only contains parked file data. That is, the buffers remember what's in directories, what file permissions are, and keep track of what memory is being written from or read to for a particular block device. The cache only contains the contents of the files themselves.
	
		
# TODO
## what's memory map file and it's application?