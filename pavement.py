#
# Automate hot build and distribution.
#
from __future__ import with_statement
import os,sys,platform
from paver.easy import *
from paver.setuputils import setup


try:
    from paver.ssh import scp
    @task
    def update_docs():
        """makes the html docs and pushes them to the web site"""
        with pushd(path('docs')):
            sh('make html')
        sh('scp -r docs/_build/* sf:public_html/houdini/ocean/docs')
except ImportError:
    pass


#
# this will probably end up going into it's own file to be 'installed' into the dist dir
#
@task
def install_hot():
    """Install the Houdini Ocean Tools binary distribution."""

    
    try:
        import hou
    except ImportError:
        print "Error: you mustn't have houdini installed properly, are you running this under hython ?"
        sys.exit(1)

    # work out where things will go
    if 'linux' in sys.platform:
        hdir = "houdini%s.%s" % (os.getenv('HOUDINI_MAJOR_RELEASE'),os.getenv('HOUDINI_MINOR_RELEASE'))
        rootdir = path(os.getenv('HOME')) / hdir
    else:
        print 'not implemented yet *****',sys.platform
        pass
    #print 'rootdir',rootdir


    # copy the dso's, keep track of VEX extensions
    vexdsos = []
    for f in path('dso').glob('*'):
        f.copy(rootdir/'dso')
        if 'VEX_' in f:
            vexdsos.append(f)

    add_vex_entries(rootdir/'vex/VEXdso',vexdsos)
    
    # copy the icons
    for f in path('config/Icons').glob('*'):
        f.copy(rootdir/'config/Icons')
               
               
def add_vex_entries(vexdsofile,entries):

    if vexdsofile.exists():
        backup = vexdsofile + '.orig'
        #print 'Backing up your VEXdso file to %s' % backup
        vexdsofile.copy(backup)

    # get the current entries
    try:
        lines = [l.strip() for l in vexdsofile.lines()]
    except IOError:
        lines = []
        
    #print 'lines',lines
    for e in entries:
        #print 'Adding %s to %s' % (e.name,vexdsofile)
        if e.name not in lines:
            lines.append(e.name)
    #print 'now lines=',lines
    vexdsofile.write_lines(lines)

