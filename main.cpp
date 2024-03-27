#include <iostream>
#include <string>

int main() {
    std::string first, second;
    std::cout << "First number:  >> ";
    std::cin >> first;
    std::cout << "Second number: >> ";
    std::cin >> second;

    // 더 자릿수가 낮은 수(문자열)의 앞에 0을 추가해 first와 second의 자릿수 맞춰주기
    int diff_size = first.size() - second.size();
    if(diff_size > 0) 
        for(int i = 0; i < diff_size; i++) 
            second = "0" + second;
    else 
        for(int i = 0; i < diff_size * -1; i++) 
            first = "0" + first;
    
    int size = first.size();


    // 덧셈 구하기
    std::string rest = "";
    int carry = 0;
    std::string sum_result[size + 1];

    for(int i = size; i >= 0; i--) {
        if(int(first[i] - '0') + int(second[i] - '0') + carry >= 10) {
            rest = std::to_string((((int(first[i] - '0') + int(second[i])) - '0') + carry) % 10);
            sum_result[i] = rest;
            carry = 1; 
            }
        else {
            rest = std::to_string(((int(first[i] - '0') + int(second[i])) - '0') + carry);
            sum_result[i] = rest;
            carry = 0;
        }
    }

    std::cout << "Sum            >> ";
    if(carry == 1)
        std::cout << "1";
    for(int i = 0; i < size; i++)
        std::cout << sum_result[i];

    std::cout << "\n";


    //뺄셈 구하기
    std::string big, small;

    bool stop = false;
    bool same = false;
    while(stop == false) {
        for(int i = 0; i < size; i++) {
            if(first[i] > second[i]) {
                big = first;
                small = second;
                stop = true;
                break;
            }
            else if(first[i] < second[i]) {
                big = second;
                small = first;
                stop = true;
                break;
            }
        }
        if(big == first || big == second)
            break;
        else {
            same = true;
            big = first;
            small = second;
            stop = true;
        }
    }

    std::string sub_result[size + 1];
    carry = 0;
    for(int i = size; i >= 0; i--) {
        if(int(big[i] - '0') + carry - int(small[i] - '0') >= 0) {
            rest = std::to_string(int(big[i] - '0') + carry - int(small[i] - '0'));
            sub_result[i] = rest;
            carry = 0;
        }
        else {
            rest = std::to_string(int(big[i] - '0') + carry + 10 - int(small[i] - '0'));
            sub_result[i] = rest;
            carry = -1;
        }
    }

    stop = false;
    std::cout << "Sub            >> ";

    int count = 0;

    if(same == true)
        std::cout << "0";   // 입력받은 두 수가 같으면 0 출력
    else { 
        if(big == second)    // 두 번째 수가 더 크면 - 출력
            std::cout << "-";

        while(sub_result[count] == "0")   // 결과값 앞의 0이 제외되어 출력되도록 설정
            count += 1;

        for(int i = count; i < size; i++)   // 결과값 앞의 0이 제외되어 출력
            std::cout << sub_result[i];
    }

    return 0;
}