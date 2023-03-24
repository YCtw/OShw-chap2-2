#include <linux/list.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

static LIST_HEAD(birthday_list); //head of linkedlist

struct birthday {
	int person_num;
	int day;
	struct list_head list; //list head use to store prev and next node
};

int birthday_list_load(void)
{
	struct birthday *person;
	int i;
	for(i = 0; i < 5 ;i++) {
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->person_num = i;
		person->day = 10+i;
		INIT_LIST_HEAD(&person->list); //int person list_head, point to itself
		list_add_tail(&person->list, &birthday_list); //insert new node to the list
	}

	printk(KERN_INFO "Loading Module\n");
	printk(KERN_INFO "Creating Linkedlist\n");
	
	list_for_each_entry(person, &birthday_list, list) {
		printk(KERN_INFO "Person %d's birthday is %d", person->person_num, person->day);
	}

	return 0;
}	

void birthday_list_remove(void)
{
	struct birthday *person, *next;
	list_for_each_entry_safe(person, next, &birthday_list, list) {
		printk(KERN_INFO "Freeing node for person %d", person->person_num);
		list_del(&person->list);
		kfree(person);
	}
	printk(KERN_INFO "Removing Module\n");
}

module_init(birthday_list_load);
module_exit(birthday_list_remove);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("John Chen");
MODULE_DESCRIPTION("for data structure traversal");


