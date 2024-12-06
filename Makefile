obj-m += spdif_duplex.o
kernel ?=$(shell uname -r)

all:
	make -C /lib/modules/$(kernel)/build M=$(PWD) modules
	dtc -@ -H epapr -O dtb -o zynaudio8x.dtbo -Wno-unit_address_vs_reg zynaudio8x.dtbs

clean:
	make -C /lib/modules/$(kernel)/build M=$(PWD) clean

install:
	cp zynaudio8x.dtbo /boot/firmware/overlays/
	xz -f spdif_duplex.ko
	cp spdif_duplex.ko.xz /lib/modules/$(kernel)/kernel/sound/soc/codecs/snd-soc-spdif_duplex.ko.xz
	depmod -a
