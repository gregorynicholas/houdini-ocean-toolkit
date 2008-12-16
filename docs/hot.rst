The Houdini Ocean Toolkit
=========================

Send any questions and feedback to - [[User:DrewWhitehouse]], or just post to the [[http://www.odforce.net/forum|odForum]].

Introduction
------------

The Houdini Ocean Toolkit (HOT) is a collection of dso's and an OTL
for rendering deep ocean waves using the algorithms of
[[http://www.finelightvisualtechnology.com/|Jerry Tessendorf]]
described in the
[[http://www.finelightvisualtechnology.com/pages/coursematerials.php|SIGGRAPH 2004 course notes]].

Version History
---------------

* 1.0rc2 - fixed a problem with the Makefiles that was the cause of the missing dll's from the 1.0rc1 builds.

* 1.0rc1 - fixed a bug in the VEX/VOP where the x and z displacement components weren't being zeroed in the case where chop was turned off (ie when only y displacement is taking place). Updated the makefiles to work in with the makefile includes shipped with the 9.0 HDK. Added a few new examples in the OTL directory that illustrate the VOP usage (9.0 only) to reduce tiling and generate particles for spray and foam effects. There hasn't been to much thought given to backwards compatability, but the code itself should still build properly for older releases (it may be easier to adapt the compile.sh scripts for these cases instead of using the makefiles which have more version dependencies).

* 0.9 - Changed the windows binary distribution back to using a dynamically loaded FFTW dll and moved to fftw-3.1.2 which has a bug fix to properly handle older CPUs (eg AMD ones that don't have SSE1/SSE2). Also SOP_Cleave has a fix for a bug that manifested for houdini >= 8.1, thanks to Stephen Marshall. I am only providing windows binaries from now on due to the profusion of linux distributions, besides all linux users have free access to compilers and know how to do some basic building, no ?

* 0.8 - Giant bump in the version and I'm dropping the alpha status now that others have used the HOT successfully. There is also a first try at building a HOT VOP in the included HOT.otl.

* 0.07 - For the sake of convenience SOP_Cleave is now included in the HOT distribution (with Stu's blessing).

* 0.06 - mostly a bugfix release, fixes a bug in the minimum eigenvalue computation. Also, you can now add N (non displaced only) and eigenvalue attributes with the SOP which is useful for fast previewing.

* 0.05 - alpha release, win32 + linux, lots of refactoring of the code for better memory usage and readability (it got shorter). Eigenvalues and vectors are now available from ocean_eval() (eigenvectors have yet to be used/tested). Ocean_eval() parameters have been reorganized, and the example displacement shader has been updated to reflect this (see above). See the pictures above for an example of using the minimal eigenvalue for locating cresting waves. Catmull rom interpolation is used instead of linear interpolation so geometry stays smooth when undersampling.

* 0.04 - alpha release, win32 + linux, separated the VEX and SOP dll's due to linking problems under linux when using standalone mantra.

* 0.03 - alpha release, win32 only, added an example displacement.hip that illustrates the displacement shader. Also the source has been released, it compiles under both linux and windows.

* 0.02 - alpha release, win32 only, simplified interfaces, lots of cleanup. Added some simple examples of the usage of the Ocean SOP and a VOP network that implements an ocean surface.

* 0.01 - alpha release, win32 only

Installation
------------

* In the following you need to modify the instructions such that you substitute the correct location of your home houdini folder, eg $HOME/houdini8.1 is you home folder if you are using houdini 8.1.*. Also whenever I say something like "blah.dll", linux users should read "blah.so", similarly "folder" means "directory". 
 
* Windows users need to put a copy of the included file "libfftw3f-3.dll" somewhere on their system's executable path. A reasonable place is in houdini's executable folder, usually something like c:\Program Files\Side Effects\Houdini 8.2.13\bin if you've installed into the default folder (I don't).

* Place SOP_Ocean.dll, SOP_Cleave.dll and VEX_Ocean.dll into the $HOME/houdini8.1/dso folder and restart houdini. You should now have "Ocean" and "Cleave" sops available (note: you need to create the "dso" directory if it doesn't exist).
 
* to complete the install of the vex functions add a line entry "VEX_Ocean.dll" (minus the quotes, see the included example) to the file $HOME/houdini8.1/vex/VEXdso file. You may need to create the "vex" folder if it doesn't already exist in which case you can just copy (win32 only) in the VEXdso file that's included in the distribution. 

* to get an icon to go with the SOPs copy the file SOP_Ocean.pic etc into $HOME/houdini8.1/config/Icon, again creating the folders if neccessary.

Download
--------

//Important: You must use the right version of houdini, particularly
 for the SOP (the VEX has a better chance of working across versions,
 but it's still not recommended).//

Latest Builds
~~~~~~~~~~~~~

1.0rc4
* source [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc4.tar.gz|HOT_src_1.0rc4.tar.gz]] : **NB: src only now, though it has now been compiled on linux, win32, win64 and OSX. There is a problem with mantra displacement shading, see [[http://forums.odforce.net/index.php?showtopic=8014|this thread]]**

1.0rc3
* source (from the [[http://forums.odforce.net/index.php?showtopic=6810&st=12&gopid=47389&#entry47389|forum]] thread) - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc3.zip|HOT_src_1.0rc3.zip]] : **NB: Linux only for now**


1.0rc2
* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_9_0_782_1.0rc2_win32.zip|HOT_9_0_782_1.0rc2_win32.zip]]
* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_9_0_768_1.0rc2_win32.zip|HOT_9_0_768_1.0rc2_win32.zip ]]
* source - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_1.0rc2.zip|HOT_src_1.0rc2.zip]]


Community builds
~~~~~~~~~~~~~~~~

If you've compiled a version of HOT for a different configuration, put it on the web somewhere and make a link to it here (and thanks!). 

* linux Ubuntu 6.06 Dapper H8 binary - [[http://personales.ya.com/lisux/HOT_8_1_704_0.8_Ubuntu606_Dapper.tar.gz|HOT_8_1_704_0.8_Ubuntu606_Dapper.tar.gz]]


Legacy
~~~~~~

* source code [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_v0.9.zip| HOT_src_v0.9.zip]]

* source code [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_v0.8.zip| HOT_src_v0.8.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_2_13_0.9_win32.zip|HOT_8.2.13_0.9_win32]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_704_0.9_win32.zip|HOT_8.1.704_0.9_win32]]
* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_704_0.8_win32.zip|HOT_8_1_704_0.8_win32]] (*)

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_666_0.8_win32.zip|HOT_8_1_666_0.8_win32]] (*)

* win32 binary - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_655_0.8_win32.zip|HOT_8_1_655_0.8_win32.zip]] (*)

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_534_0.8_win32.zip|HOT_7_0_534_0.8_win32.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_474_0.8_win32.zip|HOT_8_0_474_0.8_win32.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_410_0.8_win32.zip|HOT_8_0_410_0.8_win32.zip]]

* linux rhel4 H8 binary - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_704_0.8_rhel4.tar.gz|  HOT_8_1_704_0.8_rhel4.tar.gz]]  (*)

* linux rhel4 H8 binary - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_1_655_0.8_rhel4.tar.gz|  HOT_8_1_655_0.8_rhel4.tar.gz]]  (*)

* linux rhel4 H8 binary - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_474_0.8_rhel4.tar.gz|   HOT_8_0_474_0.8_rhel4.tar.gz]]
* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_534_0.07_win32.zip|HOT_7_0_534_0.07_win32.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_505_0.07_win32.zip|HOT_7_0_505_0.07_win32.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_383_0.07_win32.zip|HOT_8_0_383_0.07_win32.zip]]

* linux rhel4 H7 binary (houdini 7.0.515) - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_515_0.07_rhel4.tar.gz|   HOT_7_0_515_0.07_rhel4.tar.gz]]

* linux rhel4 H8 binary (houdini 8.0.383) - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_383_0.07_rhel4.tar.gz|   HOT_8_0_383_0.07_rhel4.tar.gz]]

* linux rhel4 H8 binary (houdini 8.0.335) - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_335_0.07_rhel4.tar.gz|   HOT_8_0_335_0.07_rhel4.tar.gz]]

* source code [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_src_alpha_v0.07.zip| HOT_src_alpha_v0.07.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_534_0.06_win32.zip|HOT_7_0_534_0.06_win32.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_505_0.06_win32.zip|HOT_7_0_505_0.06_win32.zip]]

* win32 binary  - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_353_0.06_win32.zip|HOT_8_0_353_0.06_win32.zip]]

* linux rhel4 H7 binary (houdini 7.0.515) - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_7_0_515_0.06_rhel4.tar.gz|   HOT_7_0_515_0.06_rhel4.tar.gz]]

* linux rhel4 H8 binary (houdini 8.0.335) - [[http://anusf.anu.edu.au/~drw900/houdini/ocean/HOT_8_0_335_0.06_rhel4.tar.gz|   HOT_8_0_335_0.06_rhel4.tar.gz]]

(*) - the cleave SOP has a mild problem in the 8.1 build

Examples
--------

{{HOT_sop_lg_nc.jpg}}\\
The simplest example (simple.hip) - the Ocean SOP with a lowres
geometry (50m x 50m and 64 rows and columns) and no chop. This
animates in near real time.

{{HOT_sop_hg_c.jpg}}\\
Using simple.hip crank up the grid to 200 rows and columns, toggle
chop and play around with the chop amount and wave height parameters
to get this surface. Things slow down a bit.

{{HOT_sop_hg_c_shader.jpg}}\\
Adding a surface shader that uses fresnel reflections and an environment map, things begin to look a bit more realistic.

{{HOT_vexdisp_500m.jpg}}\\
Here we render a 10km square composed of 4 polygons with a vex
displacement shader that calls ocean_eval(). The size of the ocean
tile is 500m, rendered with the ocean "res" setting = 10. (obvious
problem here with the reflections, it will be fixed when we get a
problem with re-uploading image files fixed.)

{{HOT_mineig.jpg}}\\

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

{{HOT_sop_parms.jpg}}\\
SOP parameters

Parameters
~~~~~~~~~~

For a deeper understaning of the parameters see the Tessendorf notes.

* Ocean Resolution - This is the resolution of the grid that the ocean will be simulated on. You can think of it in the same way as you would a texture image that you would tile the ocean surface with. The resolution of the image would be 2 to the power of res so e.g. res=10 would make a 1024x1024 image. Be warned, going to res=11 means you are going to use quite a bit of memory since the code uses more arrays of this size to store intermediate computations.

* Ocean Size - The grid mentiond above is computed for and applied to the input geometry in tiles of this size.

* Wind Speed - Affects the shape of the waves

* Wind Direction - Affects the direction the waves travel in.

* Shortest Wavelength - Waves below this lenght will be filterd out.

* Approximate Waveheight - This is used to set the so called "A" fiddle factor in the Tessendorf paper. The waves are scaled so that they will be roughly less than this height (strictly so for the t=0 timestep).
 
* Seed - Seeds the random number generator.

* Chop - Toggles the application of chop.

* Choppyness - The amount of chop displacenemnt that is applied to the input points.

* Damp reflections - In a "fully developed" ocean you will have waves travelling in both the forward and backwards directions. This parameter damps out the negative direcion waves.

* Wind Alignment - Controls how closely the waves travel in the direction of the wind.

* Ocean Depth - Affects the spectrum of waves generated. Visually in doesn't seem to have that great an influence.

* Time - The time that the surface will be evaluated at. You will usually just plug the expression **$T** in here.

VEX function ocean_eval()
~~~~~~~~~~~~~~~~~~~~~~~~~

The following VEX displacement shader illustrates how to use the ocean_eval() function included in the HOT. The functions arguments have exactly the same meaning as for the SOP. The ocean_eval() function is available in all contexts, so it can be used in vex sops, cops etc 

Getting the right combination of parameters for the displacement can be fiddly, balancing wave height, chop, wind velocity etc so I'd recommend that you start building an ocean using an Ocean SOP and a single "Ocean Size" sized XZ plane grid. This way you can visualize the the surface as geometry, then when you're happy with the look of the waves transfer the ocean sop's parameters to a displacement shader thats applied to a large ocean plane geometry.

{{{
#!c++
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

}}}


VEX function ocean_eval_ij()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mostly used for debugging. Can be used from the COP context to save out the various quantities as images. i and j simply index into the arrays that are interpolated in ocean_eval(). The image dimension is 2^gridres.

VOP shaders for basic ocean surfaces
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

See the OTL directory for examples of VOP usage.

Building from source
--------------------

Sorry that it couldn't be easier but I like to leverage existing toolkits when possible. Blitz++ is a very fast n-dimensional array library. FFTW is the "fastest fourier transform in the west". The Ocean.h file is where most of the math is done and is independant of the hdk, so it can be used outside of houdini.

Windows
~~~~~~~

I'm assuming you're using cygwin under windows. I'm also assuming you have VS.NET 2003 installed along with the hdk tools and are able to run "hcompile" from the cygwin command line.

*Unzip the HOT source ...

* We'll build the SOP first.

{{{
cd HOT/src/SOP_Ocean
}}}


*Take a look at the Makefile, I put the 3rd party lib distributions under a single root directory and make environment variables DRWLIBS and DRWLIBS_CYGWIN that point to it, I do this as a windows system environment variable so I can easily reference it in the user variables for putting dlls on executable paths, though this isn't neccessary here. I do this so I can easily change in and out different sets of dependencies with the change of a couple of environment vars.

{{{
DRWLIBS        -> H:\libs    # a windows style directory name
DRWLIBS_CYGWIN -> h:/libs    # cygwin style
}}}

*Go to http://www.fftw.org/install/windows.html, get the one built by Franz Franchetti including the intel compiler support libs, ie the first two links on the page http://www.ece.cmu.edu/~franzf/fftw.org/.

*Grab the latest blitz source from - http://sourceforge.net/project/showfiles.php?group_id=63961

*Untar them under DRWLIBS and remove the version numbers so they are simply named "fftw" and "blitz", eg

{{{
> ls $DRWLIBS
total 0
0 3rdParty/       0 Producer/             0 fftw3win32mingw/
0 OpenEXR/        0 OpenSceneGraph/       0 blitz/     0 fftw_dynamic/
0 OpenThreads/    0 fftw/
}}}

*Build blitz++ using VS.NET 2003, you unzip the included Blitz-VS.NET.zip back into the root blitz++ directory, open up the .sln file and build the "Release" version of the "blitz" project. This will put blitz.lib in blitz/lib.

*Now a "make" in the HOT/src/houdini dir should work producing a SOP_Ocean.dll. At this point you have the various bits and pieces to install according to the instructions for the binary release above. 
*You should now be able to load and run the  HOT/src/SOP_Ocean/examples/simple.hip file.

* go to the HOT/src/VEX_Ocean and make to get the VEX functions

Linux
~~~~~

The linux build is quite straight forward, building all the dependencies from source.

*Get the source distributions of both blitz++ and fftw3. Ubuntu users can install a suitable fftw3 and fftw3-dev via theSynaptic package manager, blitz++ has also been available in the past but is not currently.

*We will build them under $DRWLIBS as for windows, but this time we "make install" them there rather than just leaving the compiled blitz in place and using the pre-compiled fftw.

*So in the blitz source directory (assuming you have setup an environment variable DRWLIBS to point to a suitable directory).

{{{
> ./configure --prefix=$DRWLIBS
> make
> make install
}}}

*and for fftw we want to get the single precision version built ...

{{{
> ./configure --prefix=$DRWLIBS --enable-float
> make
> make install
}}}

*Then go to the directory HOT/src/SOP_Ocean and ...

{{{
> ./compile.sh
}}}

* do the same in ../VEX_Ocean

* Note - you can also use the included Makefile to build for both cygwin/windows and linux once the dependencies are built into the directories as described above.

HOT sightings
-------------

* Sam Loxton's [[http://samloxton.com/index.php?location=stormyOcean|Ocean Storm]]

* The time spent making the basic algorithm code independant of the HDK has obviously been useful to others - the [[http://mke3.net/weblog/another-update/|blender guys]] have ported the code to C and it looks like this [[http://www.kai-wolter.com/resources/xsi/ocean-in-xsi|XSI guy]] has also used the HOT as a base.

* Framestore used the HOT in the award winning [[http://www.framestore.com/#/Commercials%20London/Smirnoff,Sea|Smirnoff Sea commercial]] - cool!

* Ocean whirlpool WIP [[http://forums.odforce.net/index.php?showtopic=7340|on the forum]].

License
-------

The Toolkit is copyright under the [[http://creativecommons.org/licenses/GPL/2.0/|GNU GPL 2.0]] license.

Author
-----

[[User:DrewWhitehouse]]
