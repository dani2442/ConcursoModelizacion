import numpy as np
import os
import PIL
import PIL.Image
import tensorflow as tf
import pathlib
import matplotlib.pyplot as plt

data_dir=pathlib.WindowsPath("Resource/data/train/")

image_count = len(list(data_dir.glob('*/*.png')))
print(image_count)

roses = list(data_dir.glob('angry/*'))
plt.imshow(PIL.Image.open(str(roses[0])))
plt.show()

batch_size=32
img_height=48
img_width=48


train_ds = tf.keras.preprocessing.image_dataset_from_directory(
  data_dir,
  validation_split=0.2,
  subset="training",
  seed=123,
  image_size=(img_height, img_width),
  batch_size=batch_size)