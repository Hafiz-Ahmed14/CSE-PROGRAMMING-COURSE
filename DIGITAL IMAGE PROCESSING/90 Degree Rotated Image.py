import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
from google.colab import drive

drive.mount("/content/drive", force_remount=True)

def rotate_image_90(image):
    width, height = image.size
    new_image = Image.new("RGB", (height, width))
    for y in range(height):
        for x in range(width):
            new_image.putpixel((height - 1 - y, x), image.getpixel((x, y)))
    return new_image

image = Image.open("/content/drive/MyDrive/Lab 1 DIP/face grayscale.jpg")
img_copy = image.copy()
rotated_image = rotate_image_90(image)

plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.imshow(image, cmap='gray')
plt.title('Original Image')
plt.axis('off')

plt.subplot(1, 2, 2)
plt.imshow(rotated_image, cmap='gray')
plt.title('90 Degree Rotated Image')
plt.axis('off')

plt.show()
