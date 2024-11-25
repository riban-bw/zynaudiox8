obj-m += spdif_duplex.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	dtc -@ -H epapr -O dtb -o zynaudio8x.dtbo -Wno-unit_address_vs_reg zynaudio8x.dtbs

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	cp zynaudio8x.dtbo /boot/firmware/overlays/
	cp spdif_duplex.ko /lib/modules/$(shell uname -r)/kernel/drivers/
	depmod -a
