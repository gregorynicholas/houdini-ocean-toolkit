#
# build and deployment tools for the HOT
#
from __future__ import with_statement
import os,sys,platform
from paver.easy import *
from paver.setuputils import setup

srcfiles = 'SOP_Cleave.C SOP_Ocean.C VEX_Ocean.C'.split()

# work out what platform we're using
if 'linux' in sys.platform:
    if platform.machine()=='x86_64':
        build_type = 'linux_64'
    else:
        build_type = 'linux_32'
    soext = '.so'
    oext = '.o'
    includes='-I 3rdparty/linux/include -I 3rdparty/include'
    libs='-L 3rdparty/linux/lib -l blitz -l fftw3f'
elif sys.platform == 'darwin':
    build_type = 'osx_64'
    soext = '.dylib'
    oext = '.o'
    includes='-I 3rdparty/osx/include -I 3rdparty/include'
    libs='-L 3rdparty/osx/lib -l blitz -l fftw3f'
elif sys.platform == 'win32':
    # how do we tell Win32 from Win64 ?
    build_type = 'win64'
    soext = '.dll'
    oext = '.o'
    includes='-I 3rdparty/win64 -I 3rdparty/include'
    libs='-L 3rdparty/win64 -l blitz.lib -l libfftw3f-3.lib'
else:
    RuntimeError('paver script has not been implemented for this architecture (%s)' % sys.platform)

setup(
    name='The Houdini Ocean Toolkit',
    packages=[],
    version='1.0rc6',
    author='Drew Whitehouse',
    author_email='Drew.Whitehouse@anu.edu.au')

@task
def update_docs():
    """makes the html docs and pushes them to the web site"""
    with pushd(path('docs')):
        sh('make html')
    sh('scp -r docs/_build/* sf:public_html/houdini/ocean/docs')

@task
def clean():
    for f in srcfiles:
        path(soname(f)).remove()
        path(oname(f)).remove()

@task
def build():
    """builds the plugins inplace, ie doesn't install them"""
    call_task('clean')
    call_task('build_sop_cleave')
    call_task('build_sop_ocean')
    call_task('build_vex_ocean')

def install():
    """build and install the plugins"""
    sofiles = map(soname,srcfiles)
    
@task
def bdist():
    """makes a binary distribution of the plugins"""
    path('dist').rmtree()
    #call_task('build')
    path('dist').makedirs()

    with pushd('dist'):
        path('dso').makedirs()
        path('config').makedirs()
        path('config/Icons').makedirs()
        path('vex').makedirs()
        path('otls').makedirs()

    # copy the dso's
    for f in map(soname,srcfiles):
        path(f).copy(path('dist/dso')/f)

    # copy in the Icons
    for f in path('.').files('*.png'):
        f.copy(path('dist/config/Icons')/f)
    for f in path('.').files('*.icon'):
        f.copy(path('dist/config/Icons')/f)
        
    # write the VEXdso
    path('dist/vex/VEXdso').write_lines([soname('VEX_Ocean.C')])

    # copy the otl
    path('../examples_and_otl/otls/HOT.otl').copy(path('dist/otls'))

    # if we are on windows, we need manifests and the fftw dll
    if sys.platform == 'win32':
        for f in map(soname,srcfiles):
            path(f).copy(path('dist/dso')/(f+'.manifest'))
        path('dist/dlls').makedirs()
        path('dist/dlls').copy('3rdparty/win64/libfftw3f-3.dll')
    
def soname(srcfile):
    return srcfile[:-2]+soext

def oname(srcfile):
    return srcfile[:-2]+oext

def hcustom(srcfile):
    """run hcustom on the srcfile, don't install the result"""
    path(oname(srcfile)).remove()
    path(soname(srcfile)).remove()
    sh('hcustom  -e %s %s  -i . %s' % (includes,libs,srcfile))
    assert path(oname(srcfile)).exists()
    assert path(soname(srcfile)).exists()

@task
def build_sop_cleave():
    hcustom('SOP_Cleave.C')

@task
def build_sop_ocean():
    hcustom('SOP_Ocean.C')
    pass

@task
def build_vex_ocean():
    hcustom('VEX_Ocean.C')
    

