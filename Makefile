# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language
ifneq ($(KERNELRELEASE),)
	obj-m := hello.o

# Otherwise we were called directly from the command
# line; invoke the kernel build system
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
	
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	
endif

.PHONY: clean.
clean:
	rm -rf *.o *.~ *.ko *.mod.c *.order *.symvers
