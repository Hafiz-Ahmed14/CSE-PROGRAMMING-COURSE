clc;
clear all;
close all;

%basic arethmetic operation
a = 5;
b = 6;
ans = a + b;
disp(['Additional Value: ', num2str(ans)]);
ans = a - b;
disp(['Subtraction Value: ', num2str(ans)]);
ans = a * b;
disp(['Multiplication Value: ', num2str(ans)]);
ans = a / b;
disp(['Division Value: ', num2str(ans)]);
ans = a \ b;
disp(['Division Value: ', num2str(ans)]);

clear all;
close all;

%basic Trigonometry operation
disp(['Sin Radian Value: ', num2str(sin(pi))]);
disp(['Cos Radian Value: ', num2str(cos(pi/2))]);
disp(['Tan Radian Value: ', num2str(tan(pi))]);
disp(['Cot Radian Value: ', num2str(cot(pi/2))]);
disp(['Sec Radian Value: ', num2str(sec(pi))]);
disp(['Cosec Radian Value: ', num2str(csc(pi))]);


disp(['Sin Degree Value: ', num2str(sind(30))]);
disp(['Cos Degree Value: ', num2str(cosd(90))]);
disp(['Tan Degree Value: ', num2str(tand(60))]);
disp(['Cot Degree Value: ', num2str(cotd(90))]);
disp(['Sec Degree Value: ', num2str(secd(30))]);
disp(['Cosec Degree Value: ', num2str(cscd(45))]);

%same as inverse just add a in first 
%Example asin, asind;
%for hyperbolic just add h in last
%Example sinh, sindh, 
%for inverse hyperbolic similary
%Example asinh, asindh

%Some math Function
disp(['Exp Value: ', num2str(exp(2))]);
disp(['Natural log Value: ', num2str(log(5))]);
disp(['Log 10 base Value: ', num2str(log10(1000))]);
disp(['Exp Value: ', num2str(exp(2))]);
disp(['PI Value: ', num2str(pi)]);
disp(['Sqrt Value: ', num2str(sqrt(4))]);
disp(['Exp Value: ', num2str(exp(2))]);
disp(['Power Value: ', num2str(2 ^ 5)]);
disp(['Absulate Value: ', num2str(abs(-2))]);
disp(['Reminder Value: ', num2str(rem(10,5))]);
disp(['Sign Representation: ', num2str(sign(-2))]);
disp(['GCD Value: ', num2str(gcd(2,3))]);
disp(['Lcm Value: ', num2str(lcm(6,3))]);
disp(['Factorial Value: ', num2str(factorial(2))]);
disp(['Primes less then x Value: ', num2str(primes(10))]);
disp(['Round Value: ', num2str(round(10.7))]);
disp(['Factor of X Value: ', num2str(factor(6))]);

clear all;
close all;

%some practice problems
ans = (1 / (2 + (3 ^ 2))) + ((4 / 5) * (6 / 7));
disp(['This equation output is:', num2str(ans)]);

x = input('Enter a value for x: ');
ans = (x ^ 3 + 2 * x ^ 2 + 15) / x ^ 4;
disp(['This equation output is:', num2str(ans)]);

ans = (4 + asin(x)) / (log(tan(x)) + x ^ 5);
disp(['This equation output is:', num2str(ans)]);

ans = (3 - (4 / 9)) / (20 * x + 15 + x ^ 3);
disp(['This equation output is:', num2str(ans)]);

ans = (abs(x) + cosh(x ^ 2) - sqrt(4) + factorial(6));
disp(['This equation output is:', num2str(ans)]);

clear all;
close all;

