#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


int value, array_value[4];
char *name;
int cb_value=0;

module_param(value,int ,S_IRUSR | S_IWUSR);
module_param(name,charp,S_IRUSR | S_IWUSR);
module_param_array(array_value,int, NULL, S_IRUSR | S_IWUSR);


static int __init hello_world_init(void)
{
	int i;
	printk(KERN_INFO "This is the simple module\n");
	printk(KERN_INFO "Hello World module inserted sucessfully...\n");
	printk(KERN_INFO "Value=%d\n",value);
	printk(KERN_INFO "Name:%s\n",name);
	for(i=0; i < (sizeof array_value / sizeof (int)); i++)
	{
		printk(KERN_INFO "Array[%d]:%d\n",i,array_value[i]);
	}
	return 0;
}

static void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Hello World module removed sucesfully...\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Syed Zakwan");
MODULE_DESCRIPTION("Simple hello world driver and passing parameter");
MODULE_VERSION("2:1.0");
