% A = [1, 2, 3];
% B = [4, 5, 6];
% C = A + B;
% disp(C);
% 
% A = [1, 2, 3; 4, 5, 6];
% disp(sum(A));
% 
% A = [1, 2; 3, 4];
% B = [5, 6; 7, 8];
% C = [A, B];
% disp(C);


%Print even number 1 to N
% n = input('Enter the value of N: ');
% fprintf('Even Numbers are: ');
% for i = 2: 2 : n
%     fprintf('%d ', i);
% end

% n = input('Enter the value of N: ');
% fprintf('\nOdd Numbers are: ');
% for i = 1: 2: n
%     fprintf('%d ', i);
% end
% fprintf('\n');

% n = input('Enter the value of N: ');
%multiplication Table
% fprintf('Multiplication Table : \n');
% for i = 1: 10
%     result = n * i;
%     fprintf('%d * %d = %d\n', n, i, result);
% end

%Sum of Digit
% n = input('Enter the value of N: ');
% sum_digit = 0;
% while n > 0
%     temp = rem(n, 10);
%     sum_digit = sum_digit + temp;
%     n = floor(n / 10);
% end
% 
% fprintf('Sum of Digit is: %d\n', sum_digit);

% n = input('Enter the value of N: ');
%sum of first digit and last digit
% first = n;
% while first >= 10
%     first = floor(first / 10);
% end
% 
% last = n;
% last = rem(n, 10);
% 
% fprintf('Sum of first and last digit is: %d\n', first + last);

% n = input('Enter the value of N: ');
%print a number in reverse order
 % rev_n = 0;
 % while n > 0
 %     digit = rem(n, 10);
 %     rev_n = rev_n * 10 + digit;
 %     n = floor(n / 10);
 % end
 % 
 % fprintf('Reverse number is: %d\n', rev_n);


 %perfect number check
% n = input('Enter the value of N: ');
% sum_of_divisors = 0;
% for i = 1:n-1
%     if rem(n, i) == 0
%         sum_of_divisors = sum_of_divisors + i;
%     end
% end
% 
% if sum_of_divisors == n
%     disp('Perfect');
% else
%     disp('Not Perfect');
% end

% n = input('Enter how many numbers want: ');
% sum = 0;
% for i = 1: n
%     x = input('Enter your number: ');
%     sum = sum + x;
% end
% 
% fprintf("Mean value is: %f\n", sum / n);

%series value x^1 + x^2 + x^3 + x^n.
% n = input('Enter how many numbers want: ');
% x = input('Enter the value of x: ');
% sum = 0;
% for i = 1: n
%     sum = sum + (x ^ i);
% end
% fprintf('The equation value is: %f\n', sum);

%series value 1 / x + 1/x^2 + 1/x^3 + 1/x^n.
% n = input('Enter how many numbers want: ');
% x = input('Enter the value of x: ');
% sum = 0;
% for i = 1: n
%     sum = sum + (1 / x ^ i);
% end
% fprintf('The equation value is: %f\n', sum);

%factorial of a number
% n = input('Enter your number:  ');
% fact = 1;
% for i = 1: n
%     fact = fact * i;
% end
% fprintf("Factorial value is: %d\n", fact);

%Fibonacci----
% n = input('Enter the value: ');
% a(n) = 0;
% a(1) = 0;
% a(2) = 1;
% for i = 3: n
%     a(i) = a(i - 1) + a(i - 2);
% end
% 
% disp(a);

%prime number
% n = input('Enter the value: ');
% prime = 1;
% for i = 2: n - 1
%     if rem(n, i) == 0;
%         prime = 0;
%     end
% end
% 
% if prime == 1 disp('Prime');
% else disp('Not Prime');
% end




