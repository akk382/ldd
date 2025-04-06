#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int arr[] = {1, 2, 3, 4, 5};
static int num_of_params = 5;

// Syntax: module_param_array(param_name, type, number_of_elems, permissions);
module_param_array(arr, int, &num_of_params, S_IRUGO);
MODULE_PARM_DESC(arr, "Passing an array to module");

static int __init driver_init(void) {
	printk(KERN_INFO "Loaded module with values = {%d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3] ,arr[4]);
	return 0;
}

static void __exit driver_exit(void) {
	printk(KERN_INFO "Unloaded module\n");
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("akk382");
MODULE_DESCRIPTION("module_param example with string");
MODULE_VERSION("1:1.0");
