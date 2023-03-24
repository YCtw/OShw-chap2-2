# OShw-chap2-2
- Description:
In the module entry point, create a linked list containing five struct_birthday elements. Traverse the linked list and output its contents to the kernel log buffer. Invoke the dmesg command to ensure the list is properly constructed once the kernel module has been loaded.
In the module exit point, delete the elements from the linked list and return the free memory back to the kernel. Again, invoke the dmesg command to check that the list has been removed once the kernel module has been unloaded.

- Steps
1. Compile **ds_traversal.c** with ```make```
2. Loading module to Linux kernel and creating linkedlist with command line ```sudo insmod ds_traversal.ko```
3. Removing module from Linux kernel and deleting linkedlist with command line ```sudo rmmod ds_traversal```
4. Setting **kernel.dmesg_restrict** to 0 with command line ```sudo sysctl kernel.dmesg_restrict=0```(optional)
5. Invoke dmesg with command line ```dmesg```
![33333](https://user-images.githubusercontent.com/85775331/227574405-2dd2dbac-2e5b-4c9a-9fb6-0fd3481688f7.png)
![5](https://user-images.githubusercontent.com/85775331/227574433-54c4fdeb-6a02-4103-8f09-2c1f36b291dd.png)



