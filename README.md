


# 6inch e-Paper Display "Video" Player

## Description

This is an E-Ink display HAT for Raspberry Pi, 6inch, 800x600 resolution, with embedded controller IT8951, communicating via USB/SPI/I80/I2C interface.

Due to the advantages like ultra low power consumption, wide viewing angle, clear display without electricity, it is an ideal choice for applications such as shelf label, industrial instrument, and so on.

## Installation

```bash
git clone https://github.com/waveshare/IT8951.git
cd IT8951
make
```

## Usage
```bash
# Clear the screen
sudo ./IT8951 clear

# Direct render
# Show an image with a specified update mode
# Parameters: [x1] [y1] [update mode] [filepath]
sudo ./IT8951 direct 0 0 2 ./demo_seq/02.bmp

# Play sequence
# Render image sequences one after another, about 0.5-0.75fps with 750ms wait
# Parameters: [directory] [filename pattern] [start frame] [end frame] [update mode] [wait]
# Example 1 - Play demo sequence
sudo ./IT8951 sequence ./demo_seq/ *.bmp 10 18 2 750
# Example 2 - Play a sick short film
sudo ./IT8951 sequence ~/Pictures/le_ravissement_de_frank_n_stein/bmp/ VTS_03_*.bmp 1000 1897 3 50
```

## Website

CN: http://www.waveshare.net/shop/6inch-e-Paper-HAT.htm

EN: https://www.waveshare.com/6inch-e-paper-hat.htm

## Wiki

CN: http://www.waveshare.net/wiki/6inch_e-Paper_HAT

EN: https://www.waveshare.com/wiki/6inch_e-Paper_HAT

### Documentation on display update modes
http://www.waveshare.net/w/upload/c/c4/E-paper-mode-declaration.pdf