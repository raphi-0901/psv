Command to execute klee with docker
```shell
docker run --rm -v .:/code -it diffblue/cbmc:5.56.0 /bin/bash
cd /code
```

now in the container, compile your files if not already done:
```shell
cbmc adder.c
cbmc adder.c -DERROR
```
