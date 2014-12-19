Pixelgroup
==========

grouping pixels in a LED-strip. This Library is intended to be used together with a pixel-strip library like Adafruit_NeoPixel or Adafruit_WS2801. But can be used for any kind of backend. The PixelWriter class can be used to write into a uint8_t array. The PixelWriterInterface can be used to subclass existing pixelstrips writers or to build your own writer.


Pixelgroup comes in 4 flavours:

PixelgroupBase:
- basic pixelgroup. can set color

PixelgroupEaser:
- based on PixelgroupBase
- can do colorfades

PixelgroupStrobe:
- based on PixelgroupBase
- can strobe

Pixelgroup:
- based on PixelgroupBase
- can do colorfades
- can strobe
- can flicker
