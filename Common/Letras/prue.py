from scipy import ndimage, misc
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax1 = fig.add_subplot(121)  # left side
ax2 = fig.add_subplot(122)  # right side
ascent = np.array(misc.ascent())


result = ndimage.zoom(ascent, 3.0)
ax1.imshow(ascent)
ax2.imshow(result)
plt.show()