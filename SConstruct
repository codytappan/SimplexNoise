import os

env=DefaultEnvironment()

env.Append(CXXFLAGS='-std=c++0x -fPIC')

# The exports attribute allows you to pass variables to the subdir SConscripts
SConscript(dirs = ['src'], exports = ['env'],
    variant_dir = 'build' )