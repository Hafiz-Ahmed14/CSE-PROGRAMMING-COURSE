bits = [1 0 1 0];
bitrate = 1;
figure;

n = 200;
T = length(bits) / bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));

for i = 1: length(bits)
    if bits(i) == 1
        x((i - 1) * n + 1: i * n) = 1;
    end
end

plot(t, x, 'LineWidth', 3);
title(['Unipolar Rz: [' num2str(bits) ']']);