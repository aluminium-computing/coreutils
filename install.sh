#!/bin/bash
echo "Compiling Wildebeest™"
echo "Installing Wildebeest™"
echo "Installing ls"
mv $(which ls) /bin/gnuls
mv out/ls /bin/ls
echo "installing echo"
mv $(which echo) /bin/gnuecho
mv out/echo /bin/echo
echo "installing fpr"
mv out/fpr /bin/fpr
echo "installing chpr"
mv out/chpr /bin/chpr
echo "installing chown"
mv $(which chown) /bin/gnuchown
mv out/chown /bin/chown
echo "installing chroot"
mv $(which chroot) /bin/gnuchroot
mv out/chroot /bin/chroot
echo "installing cp"
mv $(which cp) /bin/gnucp
mv out/cp /bin/cp
echo "Wildebeest™ should now be installed."

