MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem '../mruby-test-depfail'

  #conf.gem github: 'udzura/mruby-etcd', commit: 'd5562b66381f8c57d0e19c264ad905648c0fd254'

  #conf.enable_test
end
