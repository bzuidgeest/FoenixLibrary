@echo off
cls

rem fatfs file
cd fatfs
wdc816cc -ML ata.c
wdc816cc -ML sd.c
wdc816cc -ML diskio.c
wdc816cc -ML ff.c
cd ../

rem other stuff
wdc816cc -ML vicky.c 
rem wdc816cc -ML FMX_printf.c -DPRINTF_INCLUDE_CONFIG_H

del fmx.lib

WDCLIB -A FMX.LIB vicky.obj ./fatfs/ata.obj ./fatfs/sd.obj ./fatfs/diskio.obj ./fatfs/ff.obj
