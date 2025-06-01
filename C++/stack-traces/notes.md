# Stack traces

## cpptrace

> [!WARNING]
>
> This library works only on Linux.

It is possible to generate more detailed stack trace using `cpptrace`.

To compile with g++ you need to link the library `cpptrace`:

```shell
g++ [...] -lcpptrace
```