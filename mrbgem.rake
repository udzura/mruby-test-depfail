MRuby::Gem::Specification.new('mruby-test-depfail') do |spec|
  spec.license = 'MIT'
  spec.authors = 'Uchio Kondo'

  spec.add_dependency 'mruby-etcd', github: 'udzura/mruby-etcd' #, branch: 'depfail-testing'
end
