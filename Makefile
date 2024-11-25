obj-m += spdif_duplex.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	dtc -@ -H epapr -O dtb -o zyndacadclite.dtbo -Wno-unit_address_vs_reg zyndacadclite.dtbs

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	cp zyndacadclite.dtbo /boot/firmware/overlays/
	cp spdif_duplex.ko /lib/modules/$(shell uname -r)/kernel/drivers/
	depmod -a
