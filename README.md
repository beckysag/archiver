# Unix Archiver

This program mimics the behavior of the UNIX ar (archive) utility and illustrates the use of file I/O on UNIX by maintaining a UNIX archive library. The archive file maintained uses exactly the standard format defined in /usr/inc1ude/ar.h.

The available options are compatible with the options having the same name in the ar command. -A is a new option not in the usual ar command.


## Usage

### From the Command Line

```
myar key archive-file [member [...]]
```
where archive-file is the name of the archive file to be used, and key is one of
the following options:
```
-q	quickly append named files to archive	  
-x	extract named files	  
-t  print a concise table of contents of the archive	  
-v	iff specified with -t, print a verbose table of contents of the archive	 
-d	delete named files from archive	 
-A  quickly append all "regular" files in the current directory (except the archive itself)
```

### Example usage: 
```
myar -q myarfile.ar
```
