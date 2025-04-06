#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static char *str_param = "This is a initial string";
module_param(str_param, charp, S_IRUGO);
MODULE_PARM_DESC(str_param, "A string parameter");

static int __init driver_init(void) {
	printk(KERN_INFO "Loaded module with %s\n", str_param);
	return 0;
}

static void __exit driver_exit(void) {
	printk(KERN_INFO "unloaded module, current str_param value = %s\n", str_param);
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("akk382");
MODULE_DESCRIPTION("module_param example with string");
MODULE_VERSION("1:1.0");
