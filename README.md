# TinyAmalgam
tiny amalgam

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