import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive
#drive.mount('/content/drive')
drive.mount("/content/drive", force_remount=True)
img =  cv2.imread("/content/drive/MyDrive/Lab 1 DIP/face grayscale.jpg")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
height = img_gray.shape[0]
width = img_gray.shape[1]
img_mirrored = np.zeros((height, width))
for i in range(height):
    for j in range(width):
        img_mirrored[i][j] = img_gray[i][width-j-1]

plt.subplot(1, 2, 1)
plt.imshow(img_gray, cmap='gray')
plt.title('Original Image')
plt.subplot(1, 2, 2)
plt.imshow(img_mirrored, cmap='gray')
plt.title('Mirror Image')
plt.show()
