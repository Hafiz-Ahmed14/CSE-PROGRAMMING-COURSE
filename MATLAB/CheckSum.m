clc;
clear all;
close all;

k = input('Enter value for k: ');
m = input('Enter value for m: '); 


a = cell(1, k);
%Input of array of string
% for i = 1:k
%     a{i} = input(['Enter binary string ', num2str(i), ': '], 's');
% end
%Initialize of a array
a = {'11011001', '11101010', '11101010', '11101010'};
s = "0";
for i = 1:k
    %disp(a{i});
    s = add(s, a{i}, m);
    %disp(s);
end
%disp('Ones complement: ');
s = ones_complement(s);

for i = 1:k
    s = add(s, a{i}, m);
   %disp(s);
end

s = ones_complement(s);
%disp('Ones complement: ');
%disp(s);

sum_zero = 0;
for i = 1:length(s)
    if s(i) == '0'
        sum_zero = sum_zero + 0;
    else
        sum_zero = sum_zero + 1;
    end
end

if sum_zero == 0
    disp('No error, So data is accepted');
else
    disp('Error, So data is not accepted');
end


%Function for add Binary Number
function result = add(a, b, m)
    result = '';
    carry = 0;
    i = length(a);
    j = length(b);

    while (i >= 1 || j >= 1 || carry)
        sum = carry;
        if (i >= 1)
            sum = sum + str2double(a(i));
            i = i - 1;
        end
        if (j >= 1)
            sum = sum + str2double(b(j));
            j = j - 1;
        end
        result = [num2str(mod(sum, 2)), result];
        carry = floor(sum / 2);
    end
    
    if(length(result) > m)
        t = result(1:length(result) - m);
        f = result(length(result) - m + 1:end);
        j = add(t, f, m);
        result = j;
    end
end


% Function for Ones Complements
function result = ones_complement(s)
    result = s;
    for i = 1:length(s)
        if s(i) == '0'
            result(i) = '1';
        else
            result(i) = '0';
        end
    end
end
