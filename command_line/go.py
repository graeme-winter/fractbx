from __future__ import division, print_function

def go():
  from scitbx.array_family import flex
  from fractbx import make_flex
  image = make_flex(1001).as_numpy_array()
  import matplotlib
  matplotlib.use('Agg')
  from matplotlib import pyplot
  pyplot.imshow(image, cmap='hot')
  pyplot.savefig('mandel.png', dpi=1000)

if __name__ == '__main__':
  go()
