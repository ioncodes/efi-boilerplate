#!/bin/sh

find ./build -name 'efi-boilerplate.efi' -exec cp {} root/efi/boot/bootx64.efi \;
sudo qemu-system-x86_64 -drive if=pflash,format=raw,file=/usr/share/qemu/OVMF.fd -drive format=raw,file=fat:rw:root -net none