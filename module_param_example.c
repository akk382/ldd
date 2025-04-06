#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


static int my_param = 0;

// Syntax: module_param(parameter_name, parameter_type, permissions);
module_param(my_param, int, S_IRUGO);
MODULE_PARM_DESC(my_param, "An integer parameter");

static int __init driver_init(void) {
	printk(KERN_INFO "driver: loaded with my_param = %d\n", my_param);
	return 0;
}

static void __exit driver_exit(void) {
	printk(KERN_INFO "driver: unloaded\n");
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_AUTHOR("akk382");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module param example");
MODULE_VERSION("1:1.0");
