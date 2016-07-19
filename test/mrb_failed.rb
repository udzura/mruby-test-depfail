##
## Failed Test
##

assert("Failed#hello") do
  t = Failed.new "hello"
  assert_equal("hello", t.hello)
end

assert("Failed#bye") do
  t = Failed.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Failed.hi") do
  assert_equal("hi!!", Failed.hi)
end
