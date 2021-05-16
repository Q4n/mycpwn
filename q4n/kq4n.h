#ifndef KQ4n_H
#define KQ4n_H

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/proc_fs.h>
#include <asm/cacheflush.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>
#include <asm/unistd.h>
#include <linux/sched.h>
#include <linux/mutex.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/sysfs.h>
#include <linux/list.h>
#include <linux/fs.h>
#include <linux/cred.h>
#include <linux/rbtree.h>
#include <linux/uaccess.h>
#include <linux/limits.h>
#include <linux/skbuff.h>
#include <linux/in.h>
#include <linux/icmp.h>
#include <linux/ip.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <net/tcp.h>
#include <net/udp.h>
#include <linux/pci.h>
#include <asm/io.h>
#include <linux/dma-mapping.h>

#define log(fmt, ...)                                                   \
    do {                                                                       \
        pr_alert("%s:%d(): " fmt, __func__, __LINE__, ##__VA_ARGS__);   \
    } while (0)


#endif