all:
	./make-package.sh

build:
	$(MAKE) -C pkginfo
	$(MAKE) -C src/kext

clean:
	$(MAKE) -C src/kext clean
	sudo rm -rf pkgroot
	sudo rm -rf *.pkg
	sudo rm -rf *.zip

source:
	./make-source.sh
