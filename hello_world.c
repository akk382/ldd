#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int __init hello_world_init(void) {
	printk(KERN_INFO "This is a hello world module.\n");
	printk(KERN_INFO "Successfully inserted module.\n");
	return 0;
}

static void __exit hello_world_exit(void) {
	printk("Successfully removed module.\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("akk382");
MODULE_DESCRIPTION("This is a hello world module");
MODULE_VERSION("1:1.0");

