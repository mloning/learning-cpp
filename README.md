# Learning C++

Code for the [learncpp] tutorial series.

[learncpp]: https://www.learncpp.com/

## Initial setup

```bash
brew install llvm pre-commit
pre-commit install
ln -s "$(brew --prefix)/opt/llvm/bin/clang-format" "/usr/local/bin/clang-format"
ln -s "$(brew --prefix)/opt/llvm/bin/clang-tidy" "/usr/local/bin/clang-tidy"
```
