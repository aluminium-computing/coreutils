all: clean ls echo fpr chpr chown chroot cp md 

ls:
	@clang ls-src/ls.c -o out/ls && echo ls
echo:
	@clang echo-src/echo.c -o out/echo && echo echo
fpr:
	@clang fpr-src/fpr.c -o out/fpr && echo fpr
chpr:
	@clang chpr-src/chpr.c -o out/chpr && echo chpr
chown:
	@clang chown-src/chown.c -o out/chown && echo chown
chroot:
	@clang chroot-src/chroot.c -o out/chroot && echo chroot
cp:
	@clang cp-src/cp.c -o out/cp && echo cp
md:
	@clang md-src/md.c -o out/md && echo md
#cut:
#	@clang cut-src/cut.c -o out/cut && echo cut
#WARNING: `cut’ unsupported

clean:
	@rm -rf out && mkdir -p out && echo Programs\ Removed.
install: ./install.sh