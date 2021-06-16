import os
import sys
Env = Environment()

currentPath = os.path.abspath('.')

Env.Append(CPPPATH=[currentPath, currentPath + '/external/spdlog/include'])
Env.Append(LIBPATH =[currentPath + '/external/spdlog'])

Env.Append(CPPPATH=[currentPath + '/external/gtest/include'])
Env.Append(CPPPATH=[currentPath + '/external/gtest'])
Env.Append(LIBPATH =[currentPath + '/external/gtest'])

Env.Append(CCCFLAGS=['-g', '-O3', '-Wall'])

Export('Env')
SConscript('common/SConscript', exports=['Env'])
SConscript('external/SConscript', exports=['Env'])

