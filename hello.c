#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/vermagic.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Frank Maker");
MODULE_DESCRIPTION("Simple test linux kernel module");
MODULE_VERSION("0.01");

char* input = "To load or not to load...";

module_param(input, charp, S_IRUGO);
void info(void){
	printk(KERN_ALERT "My process id is: %d",current->pid);
	printk(KERN_ALERT "My command name is: %s",current->comm);
	printk(KERN_ALERT "Kernel version is: %s",UTS_RELEASE);
	printk(KERN_ALERT "Module param 'input' is: %s",input);
}

static __init int hello_init(void)
{
	printk(KERN_ALERT "Hello world!\n");
	info();
	return 0;
}

static __exit void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

