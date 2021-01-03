#include <linux/init.h>
#include <linux/module.h>
//#include <linux/types.h>
#include <hello1.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK-1 Lab6");
MODULE_AUTHOR("Kuzmich IV-82");

static uint count = 1;
module_param(count, uint, S_IRUGO);

static int hello_init(void)
{
    return print_hello(count);
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);