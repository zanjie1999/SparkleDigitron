# SparkleDigitron
这是一个7脚数码管驱动，这种数码管常用于插卡音箱

不管你见没见过这种奇葩，但他的脚是阴阳共用的

所以这7个脚处理普通数码管的高和低两种状态，还需要一种悬浮的状态

## 使用说明
库文件是 src 目录下的 SparkleDigitron.h 和 SparkleDigitron.cpp 如果使用Arduino官方IDE的话，只需要在 Arduino 的 libraries 目录下建一个文件夹把这两玩意放进去就能愉快玩耍了

main.cpp 则是例子

## 屏幕适配
其中 SparkleDigitron.h 中的 indexM 因为屏幕布局大概都不一样，所以可以在板子上跑一下 test 目录下的 test2.cpp 来把脚都扫描一边并记录下来，顺序是从顶部开始绕0顺时针转一圈，最后的是8字中间的-