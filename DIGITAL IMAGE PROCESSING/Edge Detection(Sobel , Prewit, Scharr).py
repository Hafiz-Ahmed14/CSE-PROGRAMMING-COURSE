import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive


drive.mount("/content/drive", force_remount=True)


arr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/Rubix Cube.png", cv2.IMREAD_GRAYSCALE)


newarr = np.zeros_like(arr)

kernel = np.array([[1, 1, 1], [1, 1, 1], [1, 1, 1]])

kernel_sum = np.sum(kernel)


for i in range(1, arr.shape[0] - 1):
    for j in range(1, arr.shape[1] - 1):
        region = arr[i - 1: i + 2, j - 1: j + 2]
        newarr[i, j] = np.sum(region * kernel) / kernel_sum


#new_kernel = np.array([[-1, 0, 1], [-2,0, 2], [-1, 0, 1]]);
#new_kernel = np.array([[-1, -2, -1], [0,0, 0], [1, 2, 1]]);
#new_kernel = np.array([[-3, 0, 3], [-10,0, 10], [-3, 0, 3]]);
#new_kernel = np.array([[-3, -10, -3], [0,0, 0], [3, 10, 3]]);
#new_kernel = np.array([[-1, 0, 1], [-1,0, 1], [-1, 0, 1]]);
new_kernel = np.array([[-1, -1, -1], [0,0, 0], [1, 1, 1]]);
another_newarr = np.zeros_like(newarr)
for i in range(1, newarr.shape[0] - 1):
    for j in range(1, newarr.shape[1] - 1):
        region = newarr[i - 1: i + 2, j - 1: j + 2]
        another_newarr[i, j] = np.sum(region * new_kernel)

plt.subplot(1, 3, 1)
plt.imshow(newarr, cmap='gray')
plt.title('Original Image')

plt.subplot(1, 3, 2)
plt.imshow(another_newarr, cmap='gray')
plt.title('Sobel Vertical')
