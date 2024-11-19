import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/histrogram.png")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img_gray_CI = img_gray.copy()
temp = img_gray.copy()

max_pixel = np.max(img_gray)
L = 2**(np.ceil(np.log2(max_pixel)))
C = L / np.log(1 + L)

height, width = img_gray.shape
for i in range(height):
    for j in range(width):
        img_gray[i][j] = np.log(1 + img_gray[i][j])

img_gray_CI = C * img_gray_CI

plt.figure(figsize=(10, 10))
plt.subplot(1, 3, 1)
plt.imshow(temp, cmap='gray')
plt.title('Original Image')
plt.subplot(1, 3, 2)
plt.imshow(img_gray, cmap='gray')
plt.title('Logarithmic C=1')
plt.subplot(1, 3, 3)
plt.imshow(img_gray_CI, cmap='gray')
plt.title('Logarithmic C=L/log(1+L)')

plt.tight_layout()
plt.show()

r = np.unique(img_gray)
s1 = np.zeros(len(r))
s2 = np.zeros(len(r))

for i in range(len(r)):
    s1[i] = np.log(1 + r[i])
    s2[i] = C * s1[i]

plt.figure(figsize=(5, 5))
plt.subplot(1, 2, 1)
plt.plot(r, s1)
plt.title('Logarithmic C=1')
plt.subplot(1, 2, 2)
plt.plot(r, s2)
plt.title('Logarithmic C=L/log(1+L)')

plt.tight_layout()
plt.show()
