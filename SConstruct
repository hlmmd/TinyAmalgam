
import os
import sys
Env = Environment( )
Env.Append(CPPPATH = [os.getcwd()])
Env.Append(CCCFLAGS = ['-g','-O2','-Wall'])
Export('Env')
SConscript('common/SConscript')