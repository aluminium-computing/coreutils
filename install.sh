#!/bin/bash
echo "Compiling Wildebeest™"
make
echo "Installing Wildebeest™"
echo "Installing ls"
mv $(which ls) /bin/gnuls
mv out/ls /bin/ls
echo "installing echo"
mv $(which echo) /bin/oldecho
mv out/echo /bin/echo
echo "installing fpr"
mv out/fpr /bin/fpr
echo "installing chpr"
mv out/chpr /bin/chpr
echo "installing chown"
mv $(which chown) /bin/oldchown
mv out/chown /bin/chown
echo "installing chroot"
mv $(which chroot) /bin/oldchroot
mv out/chroot /bin/chroot
echo "installing cp"
mv $(which cp) /bin/oldcp
mv out/cp /bin/cp
echo "fixing echo perms"
chmod 777 /bin/echo
echo "Wildebeest™ coreutils should now be installed."
echo "For best results, install wsh as well."

