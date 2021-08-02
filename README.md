# TinyAmalgam
tiny amalgam

## INSTALL

```bash
sudo apt install libunwind-dev libgflags-dev libgtest-dev libgoogle-glog-dev

# for gtest
cd /usr/src/googletest/googletest/
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp lib/libgtest* /usr/local/lib
```

## 编译时内存炸了

开启swap

```bash
# 创建2048(2G)虚拟内存
sudo dd if=/dev/zero of=/swapfile count=2048 bs=1M

# 激活swap
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile

# 开机自启动swap
sudo vim /etc/fstab
# 在 fstab 文件最后一行添加下面的内容
/swapfile none swap sw 0 0

# 关闭swap
sudo swapoff /swapfile
sudo rm /swapfile
```

## submodule使用

```bash
# 子模块添加
git submodule add https://github.com/hlmmd/hlstl common/hlstl
# 子模块初始化
git submodule init
git submodule update
git submodule update --init --recursive
git submodule update --init common/hlstl
```
