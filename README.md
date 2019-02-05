# Go style defer in C++

```
// examples
```

## TODO

* Whether RAII will execute when the exception was not captured is implementation-defined behavior. To ensure all defers were executed, Add `std::set_terminal` in constructor.