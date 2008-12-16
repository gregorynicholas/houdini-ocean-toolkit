.. Houdini Ocean Toolkit documentation master file, created by sphinx-quickstart on Tue Dec 16 15:52:07 2008.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

The Houdini Ocean Toolkit
=========================

.. toctree::
   :maxdepth: 2

Introduction
------------

The Houdini Ocean Toolkit (HOT) is a collection of dso's and an OTL
for rendering deep ocean waves using the algorithms of `Jerry
Tessendorf <http://www.finelightvisualtechnology.com/>`_ described in
the `SIGGRAPH 2004 course notes
<http://www.finelightvisualtechnology.com/pages/coursematerials.php/>`_. The
dso's implement a SOP for displacing geometry and VEX functions
functions for use in various Houdini contexts. The OTL contains a VOP
that wraps the vex function. For the sake of convenience SOP_Cleave is
also included in the HOT distribution (with Stuart Ramsden's blessing).

Download
--------

*Important note - when installing a pre-built binary package you must
use the matching version of houdini. The VEX dso has a better chance of
working across versions, but it's still not recommended.*

Latest Releases
~~~~~~~~~~~~~~~

1.0rc6

* `HOT_src_1.0rc6.tar.gz
  <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc6.tar.gz>`_,

  - Fixed up Houdini 9x multithreading problems.

  - The mantra displacement issue was fixed by rebuilding the example
    hip file using Houdini 9x, something was lost in
    translation. Thankyou to Side Effect support for help on this one.

  - Building should be straight forward for linux and osx,
    win32 may need some finetuning. 

  - The docs have been updated using the python sphinx package. They
    are now served via the web and are included in the doc
    subdirectory of the distribution.

  - All 3rd party dependencies are included in the distribution.

  - Linux and osx dependencies are now linked statically, meaning less
    installation hassles.

1.0rc4

* `HOT_src_1.0rc4.tar.gz
  <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc4.tar.gz>`_,
  src only now, though it has now been compiled on linux, win32
  and OSX. There is a problem with mantra displacement shading, see
  `this thread <http://forums.odforce.net/index.php?showtopic=8014>`_.

1.0rc3

* `HOT_src_1.0rc3.zip
  <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc3.zip>`_
  (from the `forum
  <http://forums.odforce.net/index.php?showtopic=6810&st=12&gopid=47389&#entry47389>`_
  thread, linux only).

1.0rc2

* win32 binary - `HOT_9_0_782_1.0rc2_win32.zip
  <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_9_0_782_1.0rc2_win32.zip>`_

* win32 binary - `HOT_9_0_768_1.0rc2_win32.zip
  <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_9_0_768_1.0rc2_win32.zip>`_

* source - `HOT_src_1.0rc2.zip
  <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc2.zip>`_


Latest source from Bitbucket
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Bitbucket is a `mercurial <http://www.selenic.com/mercurial/wiki/>`_
project hosting site. You will need to have mercurial installed on
your machine. Go to the `HOT page
<http://www.bitbucket.org/eloop/hot/>`_ on Bitbucket. To get a copy of
the distribution you simply ::

    hg clone http://bitbucket.org/eloop/hot/

Examples
--------

.. image:: ./HOT_sop_lg_nc.jpg
   :align: center

The simplest example (simple.hip) - the Ocean SOP with a lowres
geometry (50m x 50m and 64 rows and columns) and no chop. This
animates in near real time.

.. image:: HOT_sop_hg_c.jpg
   :align: center

Using simple.hip crank up the grid to 200 rows and columns, toggle
chop and play around with the chop amount and wave height parameters
to get this surface. Things slow down a bit.

.. image:: HOT_sop_hg_c_shader.jpg
   :align: center

Adding a surface shader that uses fresnel reflections and an environment map, things begin to look a bit more realistic.

.. image:: HOT_vexdisp_500m.jpg
   :align: center

Here we render a 10km square composed of 4 polygons with a vex
displacement shader that calls ocean_eval(). The size of the ocean
tile is 500m, rendered with the ocean "res" setting = 10. (obvious
problem here with the reflections, it will be fixed when we get a
problem with re-uploading image files fixed.)

.. image:: HOT_mineig.jpg
   :align: center

The crests of the choppy waves are being colored by choosing the areas
where the sign of the mininum eigenvalue (ME) is negative, and adding
some color made from the negated ME multiplied by some noise. More
sophisticated foam and spray can be driven with the minimal eigenvalue
and eigenvector.

Usage
-----

Ocean SOP
~~~~~~~~~
 
The Ocean SOP is a filter sop that displaces points in the up/y
direction . See the **simple.hip** example included in the
distribution and play with the parameters to get a feel for how the
SOP works. Note that the sop will calculate accurate normals if it is
fed a geometry that has a normal attribute on points.

.. image:: HOT_sop_parms.jpg
   :align: center

Parameters
~~~~~~~~~~

For a deeper understaning of the parameters see the Tessendorf notes.

* Ocean Resolution - This is the resolution of the grid that the ocean
  will be simulated on. You can think of it in the same way as you
  would a texture image that you would tile the ocean surface
  with. The resolution of the image would be 2 to the power of res so
  e.g. res=10 would make a 1024x1024 image. Be warned, going to res=11
  means you are going to use quite a bit of memory since the code uses
  more arrays of this size to store intermediate computations.

* Ocean Size - The grid mentiond above is computed for and applied to
  the input geometry in tiles of this size.

* Wind Speed - Affects the shape of the waves

* Wind Direction - Affects the direction the waves travel in.

* Shortest Wavelength - Waves below this lenght will be filterd out.

* Approximate Waveheight - This is used to set the so called "A"
  fiddle factor in the Tessendorf paper. The waves are scaled so that
  they will be roughly less than this height (strictly so for the t=0
  timestep).
 
* Seed - Seeds the random number generator.

* Chop - Toggles the application of chop.

* Choppyness - The amount of chop displacenemnt that is applied to the
  input points.

* Damp reflections - In a "fully developed" ocean you will have waves
  travelling in both the forward and backwards directions. This
  parameter damps out the negative direcion waves.

* Wind Alignment - Controls how closely the waves travel in the
  direction of the wind.

* Ocean Depth - Affects the spectrum of waves generated. Visually in
  doesn't seem to have that great an influence.

* Time - The time that the surface will be evaluated at. You will
  usually just plug the expression **$T** in here.

VEX function ocean_eval()
~~~~~~~~~~~~~~~~~~~~~~~~~

The following VEX displacement shader illustrates how to use the
ocean_eval() function included in the HOT. The functions arguments
have exactly the same meaning as for the SOP. The ocean_eval()
function is available in all contexts, so it can be used in vex sops,
cops etc

Getting the right combination of parameters for the displacement can
be fiddly, balancing wave height, chop, wind velocity etc so I'd
recommend that you start building an ocean using an Ocean SOP and a
single "Ocean Size" sized XZ plane grid. This way you can visualize
the the surface as geometry, then when you're happy with the look of
the waves transfer the ocean sop's parameters to a displacement shader
thats applied to a large ocean plane geometry.

.. highlight:: c++

::

    #pragma label    gridres "Ocean Resolution"
    #pragma range    gridres 3 11

    #pragma label    ocean_size "Ocean Size"
    #pragma range    ocean_size 1 2000

    #pragma label    height_scale "Wave Height (approx)"
    #pragma range    height_scale 0.01 100.0

    #pragma label    do_chop Chop
    #pragma hint     do_chop toggle

    #pragma label    chop_amount  "Chop Amount"
    #pragma range    chop_amount  0.1 10 

    #pragma label windspeed "Wind Speed"
    #pragma range windspeed 0.0 100.0

    #pragma label smallest_wave "Smallest Wave"
    #pragma range smallest_wave 0.01 100

    #pragma label   winddirection "Wind Direction"
    #pragma range   winddirection 0 360

    #pragma label align "Wind Alignment"
    #pragma range align 1 10

    #pragma label damp "Damp Reflections" 
    #pragma range damp  0 1

    #pragma label do_eigenvalues "Export Eigenvalues"
    #pragma hint  do_eigenvalues toggle

    #pragma hint jminus hidden
    #pragma hint jplus hidden
    #pragma hint eminus hidden
    #pragma hint eplus hidden

    displacement
    ocean_displace(float time=0.0;
                    int   gridres=7;
                    float ocean_size=50;
                    float height_scale=1.0;
                    float windspeed=30.0;
                    float smallest_wave=0.02;
                    float winddirection=0.0;
                    float damp = 0.5;
                    float align = 2.0;
                    float ocean_depth = 200.0;
                    int   seed = 0;
                    int   do_chop=0;
                    float chop_amount=1.0;
                    int   do_eigenvalues=0;
                    export float  jminus=0.0; 
                    export float  jplus=0.0; 
                    export vector eminus={0,0,0}; 
                    export vector eplus={0,0,0}; 
                    )
    {
        vector disp,norm;

        int do_norm = 1;

        vector Po = wo_space(P);

        ocean_eval(Po.x,Po.z,time,height_scale,
                   do_chop,chop_amount,disp,
                   do_norm,norm,
                   do_eigenvalues,jminus,jplus,eminus,eplus,
                   gridres,
                   ocean_size,
                   windspeed,
                   smallest_wave,
                   winddirection,
                   damp,
                   align,
                   ocean_depth,
                   seed);

        if (do_chop)
        {
            Po += disp;
            N = computenormal(P,ow_nspace(norm),Ng);
        }
        else
        {
            Po.y += disp.y;
            N = ow_nspace(norm);
        }

        P = ow_space(Po);

    }

VEX function ocean_eval_ij()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mostly used for debugging. Can be used from the COP context to save
out the various quantities as images. i and j simply index into the
arrays that are interpolated in ocean_eval(). The image dimension is
2^gridres.

VOP shaders for basic ocean surfaces
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

See the OTL directory for examples of VOP usage.

Building from source
--------------------

Before building the HOT from source you should be able to successfully
compile and install Houdini Development Kit (HDK)
code. ``$HT/toolkit/samples/SOP/SOP_Star.C`` is a good one to try
first. So before going any further try this - ::

  cd <a temporary directory somewhere>
  cp $HT/toolkit/samples/SOP/SOP_Star.C .
  hcustom SOP_Star.C

For more information about using the HDK see the `odforce wiki HDK page
<http://odforce.net/wiki/index.php/HDK>`_. 

.. highlight:: bash


Linux
~~~~~

The linux build is quite straight forward, building all the
dependencies from source (included). To build, do the following in a
terminal - ::

  cd <where you put the HOT source>/src/3rdparty
  ./build_linux.sh
  # now would be a good time for a cuppa ...
  cd ..
  ./compile_linux.sh

Alternatively instead of compile_linux.sh you can - ::

  make 
  make install

OSX
~~~

The OSX build is quite straight forward, building all the dependencies
from source (included). You must have Apple's Xcode development
package installed. To build, do the following in a terminal - ::

  cd <where you extracted the HOT source>/src/3rdparty
  ./build_osx.sh
  # now would be a good time for a latte ...
  cd ..
  ./compile_osx.sh

Win32
~~~~~

I'm assuming you're using cygwin and bash under windows. I'm also assuming you
have VisualStudio.NET to match your version of houdini. You should be setup to
run "hcompile" from the cygwin command line. ::

  cd <where you extracted the HOT source>/src/
  ./compile_win32.sh

Win64
~~~~~

I'm assuming you're using cygwin and bash under windows. I'm also assuming you
have install VisualStudio.NET to match your version of houdini. You should be setup to
run "hcompile" from the cygwin command line. ::

  cd <where you extracted the HOT source>/src/
  ./compile_win64.sh

*Warning: win64 currently not tested, probably not working*

HOT sightings
-------------

* Sam Loxton's `Ocean Storm
  <http://samloxton.com/index.php?location=stormyOcean>`_

* The time spent making the basic algorithm code independant of the
  HDK has obviously been useful to others - the `blender guys
  <http://mke3.net/weblog/another-update/>`_ have ported the code to C
  and it looks like this `XSI guy
  <http://www.kai-wolter.com/resources/xsi/ocean-in-xsi>`_ has also
  used the HOT as a base.

* Framestore used the HOT in the award winning `Smirnoff Sea
  commercial
  <http://www.framestore.com/#/Commercials%20London/Smirnoff,Sea>`_ -
  cool!

* Ocean whirlpool WIP `on the forum
  <http://forums.odforce.net/index.php?showtopic=7340>`_.

License
-------

The toolkit is open source and copyright under the `GNU GPL 2.0
<http://creativecommons.org/licenses/GPL/2.0/>`_ license.

Support and Community
---------------------

Send any questions and feedback to the `Houdini Ocean Toolkit
od[forum] <http://forums.odforce.net/index.php?showforum=57>`_. If
this doesn't bring enlightement, mail the author directly
(Drew.Whitehouse@anu.edu.au).

Version History
---------------

Community builds
~~~~~~~~~~~~~~~~

If you've compiled a version of HOT for a different configuration, put
it on the web somewhere and make a link to it on the `odWiki page
<http://odforce.net/wiki/index.php/HoudiniOceanToolkit>`_ (and
thanks!).

Legacy Builds
~~~~~~~~~~~~~

* source code `HOT_src_v0.9.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_v0.9.zip>`_
* source code `HOT_src_v0.8.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_v0.8.zip>`_
* win32 binary  - `HOT_8.2.13_0.9_win32 <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_2_13_0.9_win32.zip>`_
* win32 binary  - `HOT_8.1.704_0.9_win32 <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_704_0.9_win32.zip>`_
* win32 binary  - `HOT_8_1_704_0.8_win32 <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_704_0.8_win32.zip>`_ (*)
* win32 binary  - `HOT_8_1_666_0.8_win32 <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_666_0.8_win32.zip>`_ (*)
* win32 binary - `HOT_8_1_655_0.8_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_655_0.8_win32.zip>`_ (*)
* win32 binary  - `HOT_7_0_534_0.8_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_534_0.8_win32.zip>`_
* win32 binary  - `HOT_8_0_474_0.8_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_474_0.8_win32.zip>`_
* win32 binary  - `HOT_8_0_410_0.8_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_410_0.8_win32.zip>`_
* linux rhel4 H8 binary - `HOT_8_1_704_0.8_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_704_0.8_rhel4.tar.gz>`_  (*)
* linux rhel4 H8 binary - `HOT_8_1_655_0.8_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_655_0.8_rhel4.tar.gz>`_  (*)
* linux rhel4 H8 binary - `HOT_8_0_474_0.8_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_474_0.8_rhel4.tar.gz>`_
* win32 binary  - `HOT_7_0_534_0.07_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_534_0.07_win32.zip>`_
* win32 binary  - `HOT_7_0_505_0.07_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_505_0.07_win32.zip>`_
* win32 binary  - `HOT_8_0_383_0.07_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_383_0.07_win32.zip>`_
* linux rhel4 H7 binary (houdini 7.0.515) - `HOT_7_0_515_0.07_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_515_0.07_rhel4.tar.gz>`_
* linux rhel4 H8 binary (houdini 8.0.383) - `HOT_8_0_383_0.07_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_383_0.07_rhel4.tar.gz>`_
* linux rhel4 H8 binary (houdini 8.0.335) - `HOT_8_0_335_0.07_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_335_0.07_rhel4.tar.gz>`_
* source code `HOT_src_alpha_v0.07.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_alpha_v0.07.zip>`_
* win32 binary  - `HOT_7_0_534_0.06_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_534_0.06_win32.zip>`_
* win32 binary  - `HOT_7_0_505_0.06_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_505_0.06_win32.zip>`_
* win32 binary  - `HOT_8_0_353_0.06_win32.zip <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_353_0.06_win32.zip>`_
* linux rhel4 H7 binary (houdini 7.0.515) - `HOT_7_0_515_0.06_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_515_0.06_rhel4.tar.gz>`_
* linux rhel4 H8 binary (houdini 8.0.335) - `HOT_8_0_335_0.06_rhel4.tar.gz <http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_335_0.06_rhel4.tar.gz>`_

(*) - the cleave SOP has a mild problem in the 8.1 build

Legacy Release Notes
~~~~~~~~~~~~~~~~~~~~

* 1.0rc2 - fixed a problem with the Makefiles that was the cause of the missing dll's from the 1.0rc1 builds.

* 1.0rc1 - fixed a bug in the VEX/VOP where the x and z displacement
  components weren't being zeroed in the case where chop was turned
  off (ie when only y displacement is taking place). Updated the
  makefiles to work in with the makefile includes shipped with the 9.0
  HDK. Added a few new examples in the OTL directory that illustrate
  the VOP usage (9.0 only) to reduce tiling and generate particles for
  spray and foam effects. There hasn't been to much thought given to
  backwards compatability, but the code itself should still build
  properly for older releases (it may be easier to adapt the
  compile.sh scripts for these cases instead of using the makefiles
  which have more version dependencies).

* 0.9 - Changed the windows binary distribution back to using a
  dynamically loaded FFTW dll and moved to fftw-3.1.2 which has a bug
  fix to properly handle older CPUs (eg AMD ones that don't have
  SSE1/SSE2). Also SOP_Cleave has a fix for a bug that manifested for
  houdini >= 8.1, thanks to Stephen Marshall. I am only providing
  windows binaries from now on due to the profusion of linux
  distributions, besides all linux users have free access to compilers
  and know how to do some basic building, no ?

* 0.8 - Giant bump in the version and I'm dropping the alpha status
  now that others have used the HOT successfully. There is also a
  first try at building a HOT VOP in the included HOT.otl.

* 0.07 - For the sake of convenience SOP_Cleave is now included in the
  HOT distribution (with Stu's blessing).

* 0.06 - mostly a bugfix release, fixes a bug in the minimum
  eigenvalue computation. Also, you can now add N (non displaced only)
  and eigenvalue attributes with the SOP which is useful for fast
  previewing.

* 0.05 - alpha release, win32 + linux, lots of refactoring of the code
  for better memory usage and readability (it got
  shorter). Eigenvalues and vectors are now available from
  ocean_eval() (eigenvectors have yet to be used/tested). Ocean_eval()
  parameters have been reorganized, and the example displacement
  shader has been updated to reflect this (see above). See the
  pictures above for an example of using the minimal eigenvalue for
  locating cresting waves. Catmull rom interpolation is used instead
  of linear interpolation so geometry stays smooth when undersampling.

* 0.04 - alpha release, win32 + linux, separated the VEX and SOP dll's
  due to linking problems under linux when using standalone mantra.

* 0.03 - alpha release, win32 only, added an example displacement.hip
  that illustrates the displacement shader. Also the source has been
  released, it compiles under both linux and windows.

* 0.02 - alpha release, win32 only, simplified interfaces, lots of
  cleanup. Added some simple examples of the usage of the Ocean SOP
  and a VOP network that implements an ocean surface.

* 0.01 - alpha release, win32 only

Indices and tables
==================

* :ref:`genindex`
* :ref:`search`

