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
        sh('scp -r docs/_build/html/* sf:public_html/houdini/ocean/docs')
except ImportError:
    pass


#
# this will probably end up going into it's own file to be 'installed' into the dist dir
#
@task
def install_hot(options):
    """Install the Houdini Ocean Tools binary distribution."""

    # do the following to force the use of hython instead of python ...
    
    # try:
    #     import hou
    # except ImportError:
    #     print "Error: you mustn't have houdini installed properly, are you running this under hython ?"
    #     sys.exit(1)

    if options.dry_run:

        print '\n\nThe install will do the following operations...\n'

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

    add_vex_entries(options,rootdir/'vex/VEXdso',vexdsos)
    
    # copy the icons
    for f in path('config/Icons').glob('*'):
        f.copy(rootdir/'config/Icons')
               
               
def add_vex_entries(options,vexdsofile,entries):

    if vexdsofile.exists():
        backup = vexdsofile + '.orig'
        print 'back up the VEXdso file to %s' % backup
        vexdsofile.copy(backup)

    # get the current entries
    try:
        lines = [l.strip() for l in vexdsofile.lines()]
    except IOError:
        lines = []

    for e in entries:
        if e.name in lines:
            for i in range(0,lines.count(e.name)-1):
                lines.remove(e.name)
        else:
            lines.append(e.name)

    if not options.dry_run:
        vexdsofile.write_lines(lines)

