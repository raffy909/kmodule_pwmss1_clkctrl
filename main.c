#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>

#define CTRL_MOD_PWMSS_CLKCTRL 	0x44E10664

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Raffaele DApuzzo");
MODULE_DESCRIPTION("pwmss_clkctrl hack");
MODULE_VERSION("0.01");

static int __init lkm_init(void) {
	volatile void* paddr;
	uint32_t dataWord;
	paddr = (volatile uint32_t*)ioremap(0x44E10664, 1);
	iowrite32(0x2, paddr);
	dataWord = readl(paddr);
	printk(KERN_INFO "CTRL_MOD_PWMSS_CLKCTRL : 0x%x\n", dataWord);
 	return 0;
}

static void __exit lkm_exit(void) {
	volatile void* paddr;
	uint32_t dataWord;
	paddr = (volatile uint32_t*)ioremap(0x44E10664, 1);
	iowrite32(0x0, paddr);
	dataWord = readl(paddr);
	printk(KERN_INFO "CTRL_MOD_PWMSS_CLKCTRL : 0x%x\n", dataWord);
 	return 0;
}

module_init(lkm_init);
module_exit(lkm_exit);
