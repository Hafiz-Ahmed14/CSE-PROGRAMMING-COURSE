#Smoothing Filtering
import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive


drive.mount("/content/drive", force_remount=True)


arr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/face grayscale.jpg", cv2.IMREAD_GRAYSCALE)


newarr = np.zeros_like(arr)


kernel = np.array([[1, 1, 1], [1, 1, 1], [1, 1, 1]])
kernel_sum = np.sum(kernel)



for i in range(1, arr.shape[0] - 1):
    for j in range(1, arr.shape[1] - 1):
        region = arr[i - 1: i + 2, j - 1: j + 2]
        newarr[i, j] = np.sum(region * kernel) / kernel_sum

plt.subplot(1, 3, 1)
plt.imshow(arr, cmap='gray')
plt.title('Original Image')

plt.subplot(1, 3, 2)
plt.imshow(newarr, cmap='gray')
plt.title('Smooting Image')
