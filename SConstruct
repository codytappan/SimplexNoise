import os

env=DefaultEnvironment()

env.Append(CXXFLAGS='-std=c++0x -fPIC')

subdirs = [
    'src/qt',
    'src'
]

# The exports attribute allows you to pass variables to the subdir SConscripts
for dir in subdirs:
    SConscript( os.path.join(dir, 'SConscript'), exports = ['env'],
    variant_dir = os.path.join('build', dir) )