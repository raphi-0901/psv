Command to execute klee with docker
```shell
docker run --rm -v .:/code -it klee/klee:3.0 /bin/bash
cd /code
```

now in the container, compile your files if not already done:
```shell
clang -c -emit-llvm gcd1.c -o gcd1.bc
clang -c -emit-llvm gcd2.c -o gcd2.bc
```

with the .bc file, we can run klee:
```shell
rm -rf klee_gcd1 ; klee --max-forks=4 --output-dir=klee_gcd1 gcd1.bc ; klee-stats klee_gcd1
rm -rf klee_gcd2 ; klee --max-forks=4 --output-dir=klee_gcd2 gcd2.bc ; klee-stats klee_gcd2
```

we can specify to rerun a test suite:
```shell
rm -rf klee_gcd2 ; klee --replay-ktest-dir=klee_gcd1 --output-dir=klee_gcd2 gcd2.bc ; klee-stats klee_gcd2
```

