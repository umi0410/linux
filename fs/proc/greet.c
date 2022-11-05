#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>

static int greeting_message_show(struct seq_file *m, void *v)
{
	seq_printf(m, "Hello, world from Jinsu!\n");
	return 0;
}

static int __init proc_greet_init(void)
{
	proc_create_single("greet", 0, NULL, greeting_message_show);
	return 0;
}
fs_initcall(proc_greet_init);
