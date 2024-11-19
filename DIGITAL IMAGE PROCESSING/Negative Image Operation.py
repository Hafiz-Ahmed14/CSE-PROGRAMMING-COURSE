import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive


drive.mount("/content/drive", force_remount=True)


arr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/face grayscale.jpg", cv2.IMREAD_GRAYSCALE)

array = np.array([[255, 0, 1, 100, 25, 101], [10, 200, 70, 80, 120, 150], [95, 30, 30, 81, 96, 77], [87, 89, 220, 250, 100, 10],[18, 7, 221, 21, 8, 15]])
temp = array.copy()
max_pixel = np.max(array)
max_pixel = (2**(np.ceil(np.log2(max_pixel))))-1
for i in range(0, 5):
    for j in range(0, 6):
        array[i][j] = max_pixel-array[i][j]


plt.figure(figsize=(5, 5))
plt.subplot(1, 2, 1)
plt.title('Original Image')
plt.imshow(temp, cmap='gray')
plt.subplot(1, 2, 2)
plt.imshow(array, cmap='gray')
plt.title('Negative Image')
