#coding=utf-8
import os
import sys
Env = Environment()

# Env.Append(CCFLAGS = ['-g'])

currentPath = os.path.abspath('.')

Env.Append(CPPPATH=[currentPath, currentPath + '/external/spdlog/include'])
Env.Append(LIBPATH =[currentPath + '/external/spdlog'])

# gtest 是个奇葩，apt install libgtest-dev 只是下载source code，没有编译好的库文件
Env.Append(CPPPATH=[currentPath + '/external/gtest/include'])
Env.Append(CPPPATH=[currentPath + '/external/gtest'])
Env.Append(LIBPATH =[currentPath + '/external/gtest'])

# 改用 apt 安装
# Env.Append(CPPPATH=[currentPath + '/external/gflags/include'])
# Env.Append(LIBPATH =[currentPath + '/external/gflags'])

# 检查是否安装 gflags
# try:
#     Env.ParseConfig("pkg-config gflags --cflags --libs")
# except:
#     print (Env['CPPPATH'])

# Env.Append(CPPPATH=[currentPath + '/external/glog/include'])
# Env.Append(LIBPATH =[currentPath + '/external/glog'])

# 检查是否安装 glog
# try:
#     Env.ParseConfig("pkg-config glog --cflags --libs")
# except:
#     os.system('cd external/glog && rm -rf build && mkdir build && cd build && cmake .. ')
#     os.system('cd external/glog/build && make -j && sudo make install')
#     os.system('cd '+ currentPath)
#     print (Env['CPPPATH'])

Env.Append(CCCFLAGS=['-g', '-O3', '-Wall'])

Env.Append(CPPPATH=[currentPath + '/algorithm'])
Env.Append(LIBPATH =[currentPath + '/algorithm'])

Export('Env')
SConscript('common/SConscript', exports=['Env'])
SConscript('external/SConscript', exports=['Env'])
SConscript('algorithm/SConscript', exports=['Env'])
