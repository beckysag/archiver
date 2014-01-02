# Unix Archiver

The archiver program mimics the behavior of the UNIX ar (archive) utility by creating, modifying, and extracting from a standard UNIX archive library. The archive maintained uses exactly the standard format defined in ar.h.

The original files' contents, mode, timestamp, owner, and group are preserved in the archive, and are restored on extraction.

The available options, with the exception of -A, are compatible with the options having the same name in the UNIX ar command. -A is a new option not in the usual ar command and is defined below.


## Usage

```
make myar
./myar [-]{qxtvdAw} archive [member...]
```

Supported options:
```
-q	quickly append named files to the archive
-x	extract named members from the archive
-t  print a concise table listing the contents of the archive
-v	if specified with -t, print a verbose table of the contents of the archive
-d	delete named files from the archive
-A  quickly append all "regular" files in the current directory (except the archive itself)
```

### Example usage: 

To append the files ```class1.o```, ```class2.o```, and ```class3.o``` to an archive file:
```
myar -q lib.ar class1.o class2.o class3.o
```

To extract the files ```class1.o```, ```class2.o```, and ```class3.o``` from ```lib.ar```:
```
myar -x lib.ar class1.o class2.o class3.o
```

To display a concise table of contents of ```lib.ar```:
```
myar -t lib.ar
```

To display a verbose table of contents of ```lib.ar```:
```
myar -tv lib.ar
```

To delete the files ```class1.o```, ```class2.o```, and ```class3.o``` from ```lib.ar```:
```
myar -d lib.ar class1.o class2.o class3.o
```

To append all regular files (excluding ```lib.ar```) in the current directory to ```lib.ar```:
```
myar -A lib.ar
```


## TODO:
main.c: In function 'main':
main.c:18: warning: 'key' may be used uninitialized in this function
