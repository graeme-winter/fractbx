from __future__ import division, print_function

def go():
  from scitbx.array_family import flex
  from fractbx import make_flex
  import numpy
  i0 = make_flex(4001)
  i1 = (255. / flex.max(i0)) * i0.as_double()
  image = (i1.iround()).as_numpy_array()
  from PIL import Image
  image = Image.fromarray(numpy.uint8(image))
  image.save('mandel.png')

if __name__ == '__main__':
  go()
