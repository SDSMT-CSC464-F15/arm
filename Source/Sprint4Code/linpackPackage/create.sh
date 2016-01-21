#script to build a debian package
#from the contents of linpack_1.0.orig

#!/bin/bash

# Create tar.bz2 of the directory
rm linpack_1.0.orig.tar.bz2
tar -cvjSf linpack_1.0.orig.tar.bz2 linpack_1.0.orig

# Build the package
cd linpack_1.0.orig
debuild -us -uc
