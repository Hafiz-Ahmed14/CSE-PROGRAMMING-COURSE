1. unrz


bits = [1 0 1 0];
bitrate = 1;
figure;

n = 200;
T = length(bits) / bitrate;
N = n * length(bits);

dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));

for i = 1:length(bits)
    if bits(i) == 1
        x((i-1)*n+1:i*n) = 1;
    end
end

plot(t, x, 'Linewidth', 3);



2. urz

bits = [1 0 1 0];
bitrate = 1;
figure;

n = 200;
T = length(bits) / bitrate;
N = n * length(bits);

dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));

for i = 0:length(bits)-1
  if bits(i+1) == 1
    x(i*n+1:(i+0.5)*n) = 1;
    x((i+0.5)*n+1:(i+1)*n) = 0;
  else
    x(i*n+1:(i+1)*n) = 0;
  end
end

plot(t, x, 'Linewidth', 3);


3. prz

bits = [1 0 1 0];
bitrate = 1;
figure;

n = 200;
T = length(bits) / bitrate;
N = n * length(bits);

dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));

for i = 0:length(bits)-1
  if bits(i+1) == 1
    x(i*n+1:(i+0.5)*n) = 1;
    x((i+0.5)*n+1:(i+1)*n) = 0;
  else
    x(i*n+1:(i+0.5)*n) = -1;
    x((i+0.5)*n+1:(i+1)*n) = 0;
  end
end

plot(t, x, 'Linewidth', 3);

4. pnrz

bits = [1 0 1 0];
bitrate = 1;
figure;

n = 200;
T = length(bits) / bitrate;
N = n * length(bits);

dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));

for i = 0:length(bits)-1
  if bits(i+1) == 1
    x(i*n+1:(i+0.5)*n) = 1;
    x((i+0.5)*n+1:(i+1)*n) = 0;
  else
    x(i*n+1:(i+0.5)*n) = -1;
    x((i+0.5)*n+1:(i+1)*n)=0;
  end
end

plot(t, x, 'Linewidth', 3);



Lab - 5

1. Line coding demo

clear all;
clc;
close all;

bits = [1 0 1 0 0 0 1 1 0];
bitrate = 1;

figure;
[t, x] = unrz(bits, bitrate);
plot(t, x, 'LineWidth', 3);

axis([0 t(end) -0.1 1.1])
grid on;

title(['Unipolar NRZ: [' num2str(bits) ']']);
xlabel('Time in sec', 'fontSize', 14, 'fontweight', 'bold');
ylabel('Amplitude in volts', 'fontSize', 14, 'fontweight', 'bold');


figure;
[t, x] = urz(bits, bitrate);
plot(t, x, 'LineWidth', 3);
axis([0, t(end) -0.1 1.1]);
grid on;
title(['Unipolar RZ: [' num2str(bits) ']']);
xlabel('Time in sec', 'fontSize', 14, 'fontweight', 'bold');
ylabel('Amplitude in volts', 'fontSize', 14, 'fontweight', 'bold');


figure;
[t, x] = prz(bits, bitrate);
plot(t, x, 'LineWidth', 3);
axis([0, t(end) -0.1 1.1]);
grid on;
title(['Unipolar RZ: [' num2str(bits) ']']);
xlabel('Time in sec', 'fontSize', 14, 'fontweight', 'bold');
ylabel('Amplitude in volts', 'fontSize', 14, 'fontweight', 'bold');


figure;
[t, x] = manchester(bits, bitrate);
plot(t, x, 'LineWidth', 3);
axis([0, t(end) -0.1 1.1]);
grid on;
title(['Unipolar RZ: [' num2str(bits) ']']);
xlabel('Time in sec', 'fontSize', 14, 'fontweight', 'bold');
ylabel('Amplitude in volts', 'fontSize', 14, 'fontweight', 'bold');



2. unrz

function [t, x] = unrz(bits, bitrate)
n = 200;
T = length(bits)/bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));
for i = 0:length(bits)-1
    if bits(i + 1) == 1
        x(i * n + 1 : (i + 1) * n) = 1;
    else 
        x(i * n + 1 : (i + 1) * n) = 0;
    end
end


3. urz

function [t, x] = urz(bits, bitrate)
n = 200;
T = length(bits)/bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));
for i = 0:length(bits)-1
    if bits(i + 1) == 1
        x(i*n+1 : (i + 0.5) * n) = 1;
        x((i + 0.5) * n + 1 : (i + 1) * n) = 0;
    else
        x(i * n + 1 : (i + 1) * n) = 0;
    end
end



4. prz

function [t, x] = prz(bits, bitrate)
n = 200;
T = length(bits)/bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));
for i = 0:length(bits)-1
    if bits(i + 1) == 1
        x(i*n+1 : (i + 0.5) * n) = 1;
        x((i + 0.5) * n + 1 : (i + 1) * n) = 0;
    else
        x(i * n + 1 : (i + 0.5) * n) = -1;
        x((i + 0.5) * n + 1 : (i + 1) * n) = 0;
    end
end


5. pnrz


T = length(bits)/bitrate; 
n = 200;
N = n*length(bits);
dt = T/N;
t = 0:dt:T;
x = zeros(1,length(t)); 
for i = 0:length(bits)-1
  if bits(i+1) == 1
    x(i*n+1:(i+0.5)*n) = 1;
    x((i+0.5)*n+1:(i+1)*n) = 0;
  else
    x(i*n+1:(i+0.5)*n) = -1;
    x((i+0.5)*n+1:(i+1)*n)=0;
  end
end
plot(t,x,'Linewidth',3);



6. manchester

function [t, x] = manchester(bits, bitrate)
n = 200;
T = length(bits)/bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;
x = zeros(1, length(t));
for i = 0:length(bits)-1
    if bits(i + 1) == 1
        x(i*n+1 : (i + 0.5) * n) = 1;
        x((i + 0.5) * n + 1 : (i + 1) * n) = -1;
    else
        x( i * n + 1 : (i + 0.5) * n) = -1;
        x((i + 0.5) * n + 1 : (i + 1) * n) = 1;
    end
end