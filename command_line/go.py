from __future__ import division, print_function

def go():
  from scitbx.array_family import flex
  from fractbx import make_flex
  fl = make_flex(5)
  print(fl.as_numpy_array())
  print(flex.min(fl), flex.max(fl))

if __name__ == '__main__':
  go()
