import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread("/content/drive/MyDrive/Lab 1 DIP/Images.png", cv2.IMREAD_GRAYSCALE)
_, binary_image = cv2.threshold(image, 127, 255, cv2.THRESH_BINARY)
kernel = np.ones((5, 5), np.uint8)

dilated_image = cv2.dilate(binary_image, kernel, iterations=1)
eroded_image = cv2.erode(binary_image, kernel, iterations=1)
opened_image = cv2.morphologyEx(binary_image, cv2.MORPH_OPEN, kernel)
closed_image = cv2.morphologyEx(binary_image, cv2.MORPH_CLOSE, kernel)

plt.figure(figsize=(12, 8))

plt.subplot(2, 3, 1)
plt.imshow(binary_image, cmap='gray')
plt.title('Original Binary Image')
plt.axis('off')

plt.subplot(2, 3, 2)
plt.imshow(dilated_image, cmap='gray')
plt.title('Dilated Image')
plt.axis('off')

plt.subplot(2, 3, 3)
plt.imshow(eroded_image, cmap='gray')
plt.title('Eroded Image')
plt.axis('off')

plt.subplot(2, 3, 4)
plt.imshow(opened_image, cmap='gray')
plt.title('Opened Image')
plt.axis('off')

plt.subplot(2, 3, 5)
plt.imshow(closed_image, cmap='gray')
plt.title('Closed Image')
plt.axis('off')

plt.show()
