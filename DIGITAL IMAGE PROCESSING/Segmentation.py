import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive

drive.mount("/content/drive", force_remount=True)

arr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/fingerprint.png", cv2.IMREAD_GRAYSCALE)

T = int(255/ 2);
p_T = 0

while abs(T - p_T) > 0.01:
    p_T = T
    left_region = arr[arr < T]
    right_region = arr[arr >= T]
    mean_left = np.mean(left_region) if left_region.size > 0 else 0
    mean_right = np.mean(right_region) if right_region.size > 0 else 0
    T = int((mean_left + mean_right) / 2)

_, binary_image = cv2.threshold(arr, T, 255, cv2.THRESH_BINARY)


plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.title("Original Grayscale Image")
plt.imshow(arr, cmap="gray")
plt.subplot(1, 2, 2)
plt.title("Binary Image after Global Thresholding")
plt.imshow(binary_image, cmap="gray")
plt.show()

print("Final Threshold Value:", T)
