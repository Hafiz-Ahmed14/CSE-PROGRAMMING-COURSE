import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/histrogram.png")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

img_gray_20 = img_gray.copy()
img_gray_40 = img_gray.copy()
img_gray_60 = img_gray.copy()
img_gray_15 = img_gray.copy()
img_gray_25 = img_gray.copy()
img_gray_50 = img_gray.copy()

height, width = img_gray.shape
for i in range(0, height):
    for j in range(0, width):
        img_gray_20[i][j] = np.power(img_gray[i][j] / 255.0, 0.20) * 255
        img_gray_40[i][j] = np.power(img_gray[i][j] / 255.0, 0.40) * 255
        img_gray_60[i][j] = np.power(img_gray[i][j] / 255.0, 0.60) * 255
        img_gray_15[i][j] = np.power(img_gray[i][j] / 255.0, 1.5) * 255
        img_gray_25[i][j] = np.power(img_gray[i][j] / 255.0, 2.5) * 255
        img_gray_50[i][j] = np.power(img_gray[i][j] / 255.0, 5.0) * 255

plt.figure(figsize=(10, 10))

plt.subplot(3, 3, 1)
plt.imshow(img_gray_20, cmap='gray')
plt.title('Gamma = 0.20')
plt.axis('off')

plt.subplot(3, 3, 2)
plt.imshow(img_gray_40, cmap='gray')
plt.title('Gamma = 0.40')
plt.axis('off')

plt.subplot(3, 3, 3)
plt.imshow(img_gray_60, cmap='gray')
plt.title('Gamma = 0.60')
plt.axis('off')

plt.subplot(3, 3, 4)
plt.imshow(img_gray, cmap='gray')
plt.title('Original Image (Gamma = 1)')
plt.axis('off')

plt.subplot(3, 3, 5)
plt.imshow(img_gray_15, cmap='gray')
plt.title('Gamma = 1.5')
plt.axis('off')

plt.subplot(3, 3, 6)
plt.imshow(img_gray_25, cmap='gray')
plt.title('Gamma = 2.5')
plt.axis('off')

plt.subplot(3, 3, 7)
plt.imshow(img_gray_50, cmap='gray')
plt.title('Gamma = 5')
plt.axis('off')

plt.tight_layout()
plt.show()
