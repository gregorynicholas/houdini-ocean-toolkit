#
# deployment tools for the HOT
#
from __future__ import with_statement
import os,sys,platform
from paver.easy import *
from paver.ssh import scp
from paver.setuputils import setup

setup(
    name="The Houdini Ocean Toolkit",
    packages=[],
    version="1.0rc6",
    author="Drew Whitehouse",
    author_email="Drew.Whitehouse@anu.edu.au")

@task
def update_docs():
    """makes the html docs and pushes them to the web site"""
    with pushd(path('docs')):
        sh('make html')
    sh('scp -r docs/_build/* sf:public_html/houdini/ocean/docs')
