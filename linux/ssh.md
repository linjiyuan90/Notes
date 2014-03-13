* clone session
	```~/.ssh/config```
	
	```
	host *
	ControlMaster auto
	ControlPath ~/.ssh/master-%r@%h:%p
	```