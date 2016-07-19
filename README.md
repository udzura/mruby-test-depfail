# mruby-test-depfail   [![Build Status](https://travis-ci.org/udzura/mruby-test-depfail.svg?branch=master)](https://travis-ci.org/udzura/mruby-test-depfail)
Failed class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/mruby-test-depfail'
end
```
## example
```ruby
p Failed.hi
#=> "hi!!"
t = Failed.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
