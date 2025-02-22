# Flare

## Usage

```
    $ flare [files to reflect] --opts --out [out file] --header [path to flare.h]
```

This application requires a compile_flags.txt or a compiler_commands.json file to be present in the working directory.


## Ignoring declarations in headers

Declarations in specific headers can be ignored by marking them as 'system' headers in 'compile_flags.txt'.
