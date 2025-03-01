#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>
#include <linux/random.h>

static int greeting_message_show(struct seq_file *m, void *v)
{
    unsigned int random_int = get_random_int() % 10;
    if ( 0 == (random_int % 2) ) {
        seq_printf(m, "\"Hello\" from Jinsu!\n");
    } else {
        seq_printf(m, "\"Bye\" from Jinsu!\n");
    }
    return 0;
}

static int __init proc_greet_init(void)
{
	proc_create_single("greet", 0, NULL, greeting_message_show);
	return 0;
}
fs_initcall(proc_greet_init);
