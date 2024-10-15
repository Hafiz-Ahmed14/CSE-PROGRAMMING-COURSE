import numpy as np
import cv2
import matplotlib.pyplot as plt
from google.colab import drive
drive.mount("/content/drive", force_remount=True)
arr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/histrogram.png", cv2.IMREAD_GRAYSCALE)
finalarr = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/histrogram.png", cv2.IMREAD_GRAYSCALE)


#arr = np.array([[0,1,2,4], [0,0,3,5], [0,0,2,3],[1,7,1,1]])
#arr

mx = int(-1e9);

height, width = arr.shape[:2]
for i in range(height):
    for j in range(width):
        if mx < arr[i][j]:
            mx = arr[i][j]

print(mx)

newarr = [0] * (mx + 1)

for i in range(mx + 1):
    newarr[i] = 0

for i in range(height):
    for j in range(width):
        newarr[arr[i][j]] += 1

for i in range(mx + 1):
    print(newarr[i], end=" ")

print("\n");

pdf = [0] * (mx + 1)

length = height * width
for i in range(mx + 1):
    pdf[i] = newarr[i] / length

for i in range(mx + 1):
    print(pdf[i], end=" ")

print("\n");

cdf = [0] * (mx + 1)
cdf[0] = pdf[0]

for i in range(1, mx + 1):
    cdf[i] = cdf[i - 1] + pdf[i]

for i in range(mx + 1):
    print(cdf[i], end=" ")

print("\n");

len = mx
for i in range(len):
    x = cdf[i] * mx
    cdf[i] = round(x)

for i in range(mx + 1):
    print(cdf[i], end=" ")

print("\n");

#finalarr = np.zeros_like(arr)

for i in range(height):
    for j in range(width):
        finalarr[i][j] = cdf[arr[i][j]]



print(finalarr);

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
