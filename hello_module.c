/* 
Usage:
# insmod hello_module.ko 

    NOTE: use "sudo" if 
insmod: ERROR: could not insert module hello_module.ko: Operation not permitted

# dmesg | tail -1
[13143.981999] Hello world!

# rmmod hello.ko

    NOTE: use "sudo" if 
rmmod: ERROR: ../libkmod/libkmod-module.c:793 kmod_module_remove_module() could not remove 'hello_module': Operation not permitted
rmmod: ERROR: could not remove module hello_module.ko: Operation not permitted

# dmesg | tail -1
[13289.702516] Cleaning up module
*/

#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk(KERN_ALERT "Hello world!\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Cleaning up module\n");
}

module_init(hello_init);
module_exit(hello_exit);
