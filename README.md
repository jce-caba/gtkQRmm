# gtkQRmm
## Create codes easily and efficiently

gtkQRmm is a library for the gtkmm GUI library for generating QR codes .

## Features
- versions for gtkmm 2 and 3 
- numeric, alphanumeric, byte and kanji mode 
- micro QR mode
- supports utf8 character set 
- supports different character sets  
- customizable colors 
- support for use without UI 

## Installation

gtkQRmm requires development files for gtkmm this is libgtkmm-3.0-dev or libgtkmm-2.4-dev for most cases.for version 3 use: 

```sh
make
sudo make install
make clean
```

for version 2 use: 
```sh
make VERSION=2
sudo make install
make clean
```

The build is prepared for libgtkmm-3.0-dev or libgtkmm-2.4-dev, if you have other development files use:

```sh
make VERSION_GTKMM=XX VERSION=3
or
make VERSION_GTKMM=XX VERSION=2
sudo make install
make clean
```
## Use

You only need compile your programs with `pkg-config gtkqrmm-3.0 --cflags  --libs` or `pkg-config gtkqrmm-2.0 --cflags --libs`.Without UI use `pkg-config qrmmutils --cflags --libs`
