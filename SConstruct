import os
import sys
Env = Environment()

# Env.Append(CCFLAGS = ['-g'])

currentPath = os.path.abspath('.')

Env.Append(CPPPATH=[currentPath, currentPath + '/external/spdlog/include'])
Env.Append(LIBPATH =[currentPath + '/external/spdlog'])

Env.Append(CPPPATH=[currentPath + '/external/gtest/include'])
Env.Append(CPPPATH=[currentPath + '/external/gtest'])
Env.Append(LIBPATH =[currentPath + '/external/gtest'])

Env.Append(CPPPATH=[currentPath + '/external/gflags/include'])
Env.Append(LIBPATH =[currentPath + '/external/gflags'])

Env.Append(CPPPATH=[currentPath + '/external/glog/include'])
Env.Append(LIBPATH =[currentPath + '/external/glog'])

Env.Append(CCCFLAGS=['-g', '-O3', '-Wall'])

Export('Env')
SConscript('common/SConscript', exports=['Env'])
SConscript('external/SConscript', exports=['Env'])

