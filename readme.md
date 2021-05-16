# mycpwn

写c利用的时候懒得包含头文件, 还有一些其他的通用的函数啥的了

## usage

### r3
```
#include <q4n/q4n.h>
```

log("this is log%d",1);

pause();

die("err here");

hexdump("title", buffer, length);

### r0

```
#include <q4n/kq4n.h>
```

log("this is log%d",1);


## install 

install to `/usr/local/include`

```
./install.sh
```

## remove

```
sudo rm -rf /usr/local/include/q4n
```