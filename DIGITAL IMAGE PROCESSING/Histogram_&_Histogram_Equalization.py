import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive
drive.mount("/content/drive", force_remount=True)
arr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/histrogram.png", cv2.IMREAD_GRAYSCALE)
finalarr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/histrogram.png", cv2.IMREAD_GRAYSCALE)


mx = np.max(arr)

newarr = [0] * (mx + 1)

for i in range(mx + 1):
    newarr[i] = 0

for i in range(height):
    for j in range(width):
        newarr[arr[i][j]] += 1


pdf = [0] * (mx + 1)

length = height * width
for i in range(mx + 1):
    pdf[i] = newarr[i] / length


cdf = [0] * (mx + 1)
cdf[0] = pdf[0]

for i in range(1, mx + 1):
    cdf[i] = cdf[i - 1] + pdf[i]



len = mx
for i in range(len):
    x = cdf[i] * mx
    cdf[i] = round(x)



for i in range(height):
    for j in range(width):
        finalarr[i][j] = cdf[arr[i][j]]




plt.figure(figsize=(10, 10))
plt.bar(np.arange(256), newarr)
plt.title('Original')
plt.show()

plt.bar(np.arange(256), cdf)
plt.title('CDF')

plt.show()

plt.figure(figsize=(10, 10))
plt.subplot(1, 2, 1)
plt.imshow(arr, cmap='gray')
plt.title('Original Image')
plt.subplot(1, 2, 2)
plt.imshow(finalarr, cmap='gray')
plt.title('Histrogram Image')



plt.show()
