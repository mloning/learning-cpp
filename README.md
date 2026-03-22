# Learning C++

Code for the [Learn C++](https://www.learncpp.com/) tutorials.
For more resources, see my blog post on [Learning C++](https://www.mloning.com/posts/learning-cpp/).

## Initial setup

```bash
brew install llvm pre-commit
ln -s "$(brew --prefix)/opt/llvm/bin/clang-format" "/usr/local/bin/clang-format"
ln -s "$(brew --prefix)/opt/llvm/bin/clang-tidy" "/usr/local/bin/clang-tidy"
pre-commit install --install-hooks
```
