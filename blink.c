#define REG32(addr) *((unsigned long *)(addr))

#define RCC_GPIO_EN 0x40023800 + 0x30
#define GPIOD_BASE 0x40020C00
#define GPIO_MODER_OFFSET 0x00
#define GPIO_OTYPER_OFFSET 0x04
#define GPIO_OSPEEDR_OFFSET 0x08
#define GPIO_PUPDR_OFFSET 0x0C
#define GPIO_BSRR_OFFSET 0x18

asm(".word 0x20001000");
asm(".word yb");

int yb()
{
	unsigned int c = 0;
	REG32(RCC_GPIO_EN) = (1 << 3);
	REG32(GPIOD_BASE + GPIO_MODER_OFFSET) = 1 << 30;
	while (1)
	{
		REG32(GPIOD_BASE + GPIO_BSRR_OFFSET) = 1 << 31;
		for (c = 0; c < 100000; c++)
			;
		REG32(GPIOD_BASE + GPIO_BSRR_OFFSET) = 1 << 15;
		for (c = 0; c < 100000; c++)
			;
	}
}