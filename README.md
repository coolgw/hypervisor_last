In this repo , collect all features in our OS.
And some try or new idea in development.



hypervisor_last
===============

upstream development the newest feature about HV.


* Require Packages
  * openSUSE TW/openSUSE Leap15.0
  * 32 bit libc dev package (zypper in glibc-devel-32bit)
  * qemu-kvm (zypper in qemu-kvm)

* Build

~~~~
  `make`
~~~~

* Run Hypervisor

~~~~
  `make run.x86`
~~~~

* Debug
~~~~
  Plesae take a look here, it will help you use `qemu` console to monior the registers of VM.
  so that help you debug some of crash issues.
  `https://en.wikibooks.org/wiki/QEMU/Monitor`
~~~~
